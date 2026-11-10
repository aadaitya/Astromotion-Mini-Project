#include "motor.h"
#include <math.h>
#include <limits.h>
Status_t motor_validate_config(const MotorConfig_t *c) {
 if (!c) return STATUS_INVALID_INPUT;
 if (!isfinite(c->step_angle_deg)||!isfinite(c->gear_ratio)||!isfinite(c->pulse_frequency_hz)||c->step_angle_deg<=0||c->gear_ratio<=0||c->pulse_frequency_hz<=0||c->microstepping==0) return STATUS_INVALID_CONFIG;
 return STATUS_SUCCESS;
}
Status_t motor_steps_per_degree(const MotorConfig_t *c,double *out) {
 if (!out) return STATUS_INVALID_INPUT;
 Status_t s=motor_validate_config(c);
 if(s) return s;
 *out=((double)c->microstepping*c->gear_ratio)/c->step_angle_deg;
 return isfinite(*out)&&*out>0?STATUS_SUCCESS:STATUS_CALCULATION_ERROR;
}
Status_t motor_calculate_steps(const MotorConfig_t *c,double angle,uint64_t *steps,Direction_t *dir,double *actual) {
 if(!steps||!dir||!actual||!isfinite(angle)) return STATUS_INVALID_INPUT;
 double scale; Status_t s=motor_steps_per_degree(c,&scale); if(s) return s;
 double raw=fabs(angle)*scale; if(!isfinite(raw)||raw>(double)UINT64_MAX-0.5) return STATUS_CALCULATION_ERROR;
 *steps=(uint64_t)llround(raw); *dir=angle>0?DIRECTION_POSITIVE:angle<0?DIRECTION_NEGATIVE:DIRECTION_STOP;
 *actual=(double)*steps/scale; return STATUS_SUCCESS;
}
Status_t motor_estimate_duration(const MotorConfig_t *c,uint64_t steps,double *out) {
 if(!out) return STATUS_INVALID_INPUT;
 Status_t s=motor_validate_config(c);
 if(s) return s;
 *out=(double)steps/c->pulse_frequency_hz; return isfinite(*out)?STATUS_SUCCESS:STATUS_CALCULATION_ERROR;
}
