#ifndef PLANNER_H
#define PLANNER_H
#include "astro_types.h"
Status_t planner_create_plan(const MountConfig_t *,const MountState_t *,const MovementRequest_t *,MovementPlan_t *);
#endif
