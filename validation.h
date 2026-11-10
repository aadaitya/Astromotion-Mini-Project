#ifndef VALIDATION_H
#define VALIDATION_H
#include "astro_types.h"
Status_t validation_check_axis_config(const AxisConfig_t *);
Status_t validation_check_position(const AxisConfig_t *,double);
Status_t validation_check_request(const MovementRequest_t *);
#endif
