#include "storage.h"
#include "validation.h"
#include <stdio.h>
#include <string.h>
Status_t storage_save_config(const char *path,const MountConfig_t *c) {
 if(!path||!c) return STATUS_INVALID_INPUT;
 FILE *f=fopen(path,"w");
 if(!f) return STATUS_FILE_ERROR;
 for(size_t i=0;i<AXIS_COUNT;i++){const AxisConfig_t *a=&c->axes[i];if(validation_check_axis_config(a)){fclose(f);return STATUS_INVALID_CONFIG;}
  if(fprintf(f,"%.10f %u %.10f %.10f %.10f %.10f\n",a->motor.step_angle_deg,a->motor.microstepping,a->motor.gear_ratio,a->motor.pulse_frequency_hz,a->min_angle_deg,a->max_angle_deg)<0){fclose(f);return STATUS_FILE_ERROR;}}
 return fclose(f)==0?STATUS_SUCCESS:STATUS_FILE_ERROR;
}
Status_t storage_load_config(const char *path,MountConfig_t *c) {
 if(!path||!c) return STATUS_INVALID_INPUT;
 FILE *f=fopen(path,"r");
 if(!f) return STATUS_FILE_ERROR;
 MountConfig_t t={0};
 for(size_t i=0;i<AXIS_COUNT;i++){AxisConfig_t *a=&t.axes[i];
  if(fscanf(f,"%lf %u %lf %lf %lf %lf",&a->motor.step_angle_deg,&a->motor.microstepping,&a->motor.gear_ratio,&a->motor.pulse_frequency_hz,&a->min_angle_deg,&a->max_angle_deg)!=6||validation_check_axis_config(a)){fclose(f);return STATUS_INVALID_CONFIG;}}
 fclose(f);*c=t;return STATUS_SUCCESS;
}
Status_t storage_append_movement(const char *path,const MovementRecord_t *r) {
 if(!path||!r) return STATUS_INVALID_INPUT;
 FILE *f=fopen(path,"a");
 if(!f) return STATUS_FILE_ERROR;
 int n=fprintf(f,"%llu,%s,%.10f,%.10f,%llu,%llu,%.10f\n",(unsigned long long)r->record_id,r->timestamp,r->plan.axis_plans[0].final_position_deg,r->plan.axis_plans[1].final_position_deg,(unsigned long long)r->plan.axis_plans[0].steps,(unsigned long long)r->plan.axis_plans[1].steps,r->plan.total_duration_sec);
 int e=fclose(f);return n<0||e?STATUS_FILE_ERROR:STATUS_SUCCESS;
}
Status_t storage_load_movements(const char *path,MovementRecord_t *r,size_t cap,size_t *count) {
 if(!path||!r||!count) return STATUS_INVALID_INPUT;
 *count=0;
 FILE *f=fopen(path,"r");
 if(!f) return STATUS_FILE_ERROR;
 char line[256];
 while(fgets(line,sizeof(line),f)){if(*count>=cap){fclose(f);return STATUS_INVALID_INPUT;}unsigned long long id,s1,s2;double p1,p2,d;char ts[TIMESTAMP_LENGTH];
  if(sscanf(line,"%llu,%31[^,],%lf,%lf,%llu,%llu,%lf",&id,ts,&p1,&p2,&s1,&s2,&d)!=7){fclose(f);return STATUS_INVALID_CONFIG;}
  MovementRecord_t *x=&r[(*count)++];memset(x,0,sizeof(*x));x->record_id=id;snprintf(x->timestamp,sizeof(x->timestamp),"%s",ts);x->plan.axis_plans[0].final_position_deg=p1;x->plan.axis_plans[1].final_position_deg=p2;x->plan.axis_plans[0].steps=s1;x->plan.axis_plans[1].steps=s2;x->plan.total_duration_sec=d;x->plan.status=STATUS_SUCCESS;
 }
 return fclose(f)==0?STATUS_SUCCESS:STATUS_FILE_ERROR;
}
Status_t storage_append_calibration(const char *path,const CalibrationRecord_t *r) {
 if(!path||!r) return STATUS_INVALID_INPUT;
 FILE *f=fopen(path,"a");
 if(!f) return STATUS_FILE_ERROR;
 int n=fprintf(f,"%d,%.10f,%.10f,%.10f,%.10f,%s\n",(int)r->axis,r->reference_position_deg,r->measured_position_deg,r->signed_error_deg,r->absolute_error_deg,r->timestamp);
 int e=fclose(f);return n<0||e?STATUS_FILE_ERROR:STATUS_SUCCESS;
}
