#ifndef MOUNT_H
#define MOUNT_H
#include "astro_types.h"
Status_t mount_initialize(MountState_t *,const double [AXIS_COUNT],const MountConfig_t *);
Status_t mount_apply_movement(MountState_t *,const MountConfig_t *,const MovementPlan_t *);
#endif
