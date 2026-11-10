#include "validation.h"
#include "motor.h"
#include <math.h>
Status_t validation_check_axis_config(const AxisConfig_t *a) {
 if(!a) return STATUS_INVALID_INPUT;
 if(!isfinite(a->min_angle_deg)||!isfinite(a->max_angle_deg)||a->min_angle_deg>=a->max_angle_deg) return STATUS_INVALID_CONFIG;
 return motor_validate_config(&a->motor);
}
Status_t validation_check_position(const AxisConfig_t *a,double p) {
 Status_t s=validation_check_axis_config(a); if(s) return s;
 if(!isfinite(p)) return STATUS_INVALID_INPUT;
 return p<a->min_angle_deg||p>a->max_angle_deg?STATUS_LIMIT_EXCEEDED:STATUS_SUCCESS;
}
Status_t validation_check_request(const MovementRequest_t *r) {
 if(!r) return STATUS_INVALID_INPUT;
 for(size_t i=0;i<AXIS_COUNT;i++) if(!isfinite(r->displacement_deg[i])) return STATUS_INVALID_INPUT;
 return STATUS_SUCCESS;
}
