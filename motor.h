#ifndef MOTOR_H
#define MOTOR_H
#include "astro_types.h"
Status_t motor_validate_config(const MotorConfig_t *);
Status_t motor_steps_per_degree(const MotorConfig_t *, double *);
Status_t motor_calculate_steps(const MotorConfig_t *, double, uint64_t *, Direction_t *, double *);
Status_t motor_estimate_duration(const MotorConfig_t *, uint64_t, double *);
#endif
