#ifndef STORAGE_H
#define STORAGE_H
#include "astro_types.h"
Status_t storage_save_config(const char *,const MountConfig_t *);
Status_t storage_load_config(const char *,MountConfig_t *);
Status_t storage_append_movement(const char *,const MovementRecord_t *);
Status_t storage_load_movements(const char *,MovementRecord_t *,size_t,size_t *);
Status_t storage_append_calibration(const char *,const CalibrationRecord_t *);
#endif
