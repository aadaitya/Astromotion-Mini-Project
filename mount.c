#include "mount.h"
#include "validation.h"
Status_t mount_initialize(MountState_t *s,const double p[AXIS_COUNT],const MountConfig_t *c) {
 if(!s||!p||!c) return STATUS_INVALID_INPUT;
 for(size_t i=0;i<AXIS_COUNT;i++){Status_t x=validation_check_position(&c->axes[i],p[i]);if(x)return x;}
 for(size_t i=0;i<AXIS_COUNT;i++) s->position_deg[i]=p[i];
 return STATUS_SUCCESS;
}
Status_t mount_apply_movement(MountState_t *s,const MountConfig_t *c,const MovementPlan_t *p) {
 if(!s||!c||!p) return STATUS_INVALID_INPUT;
 if(p->status!=STATUS_SUCCESS) return p->status;
 double next[AXIS_COUNT];
 for(size_t i=0;i<AXIS_COUNT;i++){next[i]=p->axis_plans[i].final_position_deg;Status_t x=validation_check_position(&c->axes[i],next[i]);if(x)return x;}
 for(size_t i=0;i<AXIS_COUNT;i++) s->position_deg[i]=next[i];
 return STATUS_SUCCESS;
}
