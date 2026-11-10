#include "report.h"
#include <stdio.h>
#include <string.h>
static int cmp(const MovementRecord_t *a,const MovementRecord_t *b,SortCriteria_t c) {
 if(c==SORT_BY_DURATION)return (a->plan.total_duration_sec>b->plan.total_duration_sec)-(a->plan.total_duration_sec<b->plan.total_duration_sec);
 if(c==SORT_BY_STEPS){uint64_t x=a->plan.axis_plans[0].steps+a->plan.axis_plans[1].steps,y=b->plan.axis_plans[0].steps+b->plan.axis_plans[1].steps;return (x>y)-(x<y);}
 return strcmp(a->timestamp,b->timestamp);
}
void report_print_plan(const MovementPlan_t *p) {
 if(!p) return;
 if(p->status){printf("Movement rejected (status %d)\n",p->status);return;}
 for(size_t i=0;i<AXIS_COUNT;i++){const MovementAxisPlan_t *a=&p->axis_plans[i];printf("Axis %zu: %llu steps, direction %d, actual %.4f deg, %.4f s\n",i+1,(unsigned long long)a->steps,a->direction,a->actual_displacement_deg,a->duration_sec);}
 printf("Total estimated duration: %.4f s\n",p->total_duration_sec);
}
void report_print_state(const MountState_t *s){if(s)printf("Axis 1: %.4f deg\nAxis 2: %.4f deg\n",s->position_deg[0],s->position_deg[1]);}
void report_print_calibration(const CalibrationSummary_t *s){if(s)printf("Count: %zu | Mean signed error: %.5f | Mean absolute error: %.5f | Maximum error: %.5f deg\n",s->measurement_count,s->mean_signed_error_deg,s->mean_absolute_error_deg,s->maximum_absolute_error_deg);}
Status_t report_sort_movements(MovementRecord_t *r,size_t n,SortCriteria_t c) {
 if((!r&&n)||c<SORT_BY_DURATION||c>SORT_BY_TIMESTAMP)return STATUS_INVALID_INPUT;
 for(size_t i=1;i<n;i++){MovementRecord_t key=r[i];size_t j=i;while(j&&cmp(&r[j-1],&key,c)>0){r[j]=r[j-1];j--;}r[j]=key;}return STATUS_SUCCESS;
}
