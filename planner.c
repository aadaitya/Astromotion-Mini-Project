#include "planner.h"
#include "motor.h"
#include "validation.h"
#include <string.h>
Status_t planner_create_plan(const MountConfig_t *c,const MountState_t *state,const MovementRequest_t *r,MovementPlan_t *p) {
 if(!c||!state||!r||!p)return STATUS_INVALID_INPUT;
 memset(p,0,sizeof(*p)); p->status=STATUS_SUCCESS;
 Status_t s=validation_check_request(r); if(s){p->status=s;return s;}
 for(size_t i=0;i<AXIS_COUNT;i++){
  MovementAxisPlan_t *a=&p->axis_plans[i]; const AxisConfig_t *cfg=&c->axes[i];
  s=validation_check_position(cfg,state->position_deg[i]);if(s)goto fail;
  a->start_position_deg=state->position_deg[i];a->requested_displacement_deg=r->displacement_deg[i];
  s=motor_calculate_steps(&cfg->motor,r->displacement_deg[i],&a->steps,&a->direction,&a->actual_displacement_deg);if(s)goto fail;
  a->final_position_deg=a->start_position_deg+(double)a->direction*a->actual_displacement_deg;
  s=validation_check_position(cfg,a->final_position_deg);if(s)goto fail;
  s=motor_estimate_duration(&cfg->motor,a->steps,&a->duration_sec);if(s)goto fail;
  if(a->duration_sec>p->total_duration_sec)p->total_duration_sec=a->duration_sec;
 }
 return STATUS_SUCCESS;
 fail: p->status=s;return s;
}
