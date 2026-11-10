#include "astro_types.h"
#include "mount.h"
#include "planner.h"
#include "report.h"
#include "storage.h"
#include "calibration.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define CONFIG_FILE "data/config.txt"
#define MOVEMENTS_FILE "data/movements.txt"
#define CALIBRATIONS_FILE "data/calibrations.txt"
static void defaults(MountConfig_t *c){for(size_t i=0;i<2;i++)c->axes[i]=(AxisConfig_t){{1.8,16,100.0,2000.0},-180.0,180.0};}
static void now_string(char *s){time_t t=time(NULL);struct tm *p=localtime(&t);if(!p||!strftime(s,TIMESTAMP_LENGTH,"%Y-%m-%d_%H:%M:%S",p))snprintf(s,TIMESTAMP_LENGTH,"unknown");}
static int get_double(const char *prompt,double *v){char b[128],extra;printf("%s",prompt);return fgets(b,sizeof b,stdin)&&sscanf(b," %lf %c",v,&extra)==1;}
int main(void){
 MountConfig_t c;if(storage_load_config(CONFIG_FILE,&c)!=STATUS_SUCCESS){defaults(&c);(void)storage_save_config(CONFIG_FILE,&c);}
 MountState_t state;const double initial[2]={0,0};if(mount_initialize(&state,initial,&c)!=STATUS_SUCCESS){puts("Invalid configuration.");return EXIT_FAILURE;}
 uint64_t id=1;char line[128];int running=1;
 while(running){int choice;puts("\n=== AstroMotion ===\n1. View position\n2. Plan/simulate movement\n3. Add calibration measurement\n4. Exit");printf("Choice: ");
  if(!fgets(line,sizeof line,stdin)||sscanf(line,"%d",&choice)!=1){puts("Invalid choice.");continue;}
  if(choice==1)report_print_state(&state);
  else if(choice==2){MovementRequest_t r;if(!get_double("Axis 1 displacement (deg): ",&r.displacement_deg[0])||!get_double("Axis 2 displacement (deg): ",&r.displacement_deg[1])){puts("Invalid input.");continue;}
   MovementPlan_t p;Status_t s=planner_create_plan(&c,&state,&r,&p);report_print_plan(&p);if(s==STATUS_SUCCESS){printf("Apply simulated movement? (1=yes, 0=no): ");if(fgets(line,sizeof line,stdin)){int yes=0;sscanf(line,"%d",&yes);if(yes==1&&mount_apply_movement(&state,&c,&p)==STATUS_SUCCESS){MovementRecord_t rec={0};rec.record_id=id++;now_string(rec.timestamp);rec.plan=p;if(storage_append_movement(MOVEMENTS_FILE,&rec)!=STATUS_SUCCESS)puts("Warning: history save failed.");report_print_state(&state);}}}
  } else if(choice==3){int a;double ref,meas;printf("Axis (1 or 2): ");if(!fgets(line,sizeof line,stdin)||sscanf(line,"%d",&a)!=1||(a!=1&&a!=2)||!get_double("Reference position: ",&ref)||!get_double("Measured position: ",&meas)){puts("Invalid input.");continue;}
   CalibrationRecord_t r;char ts[TIMESTAMP_LENGTH];now_string(ts);if(calibration_create_record((Axis_t)(a-1),ref,meas,ts,&r)==STATUS_SUCCESS&&storage_append_calibration(CALIBRATIONS_FILE,&r)==STATUS_SUCCESS)printf("Saved. Signed error: %.4f deg\n",r.signed_error_deg);else puts("Calibration save failed.");
  } else if(choice==4)running=0;else puts("Unknown option.");
 }
 puts("Exiting AstroMotion.");return EXIT_SUCCESS;
}
