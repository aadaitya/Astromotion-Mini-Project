#ifndef ASTRO_TYPES_H
#define ASTRO_TYPES_H
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#define AXIS_COUNT 2
#define TIMESTAMP_LENGTH 32
typedef enum { AXIS_1=0, AXIS_2=1 } Axis_t;
typedef enum { DIRECTION_NEGATIVE=-1, DIRECTION_STOP=0, DIRECTION_POSITIVE=1 } Direction_t;
typedef enum { STATUS_SUCCESS=0, STATUS_INVALID_INPUT, STATUS_INVALID_CONFIG, STATUS_LIMIT_EXCEEDED, STATUS_FILE_ERROR, STATUS_NO_DATA, STATUS_CALCULATION_ERROR } Status_t;
typedef enum { SORT_BY_DURATION=0, SORT_BY_STEPS, SORT_BY_TIMESTAMP } SortCriteria_t;
typedef struct { double step_angle_deg; unsigned int microstepping; double gear_ratio; double pulse_frequency_hz; } MotorConfig_t;
typedef struct { MotorConfig_t motor; double min_angle_deg, max_angle_deg; } AxisConfig_t;
typedef struct { AxisConfig_t axes[AXIS_COUNT]; } MountConfig_t;
typedef struct { double position_deg[AXIS_COUNT]; } MountState_t;
typedef struct { double displacement_deg[AXIS_COUNT]; } MovementRequest_t;
typedef struct { Direction_t direction; uint64_t steps; double requested_displacement_deg, actual_displacement_deg, start_position_deg, final_position_deg, duration_sec; } MovementAxisPlan_t;
typedef struct { MovementAxisPlan_t axis_plans[AXIS_COUNT]; double total_duration_sec; Status_t status; } MovementPlan_t;
typedef struct { uint64_t record_id; char timestamp[TIMESTAMP_LENGTH]; MovementPlan_t plan; } MovementRecord_t;
typedef struct { Axis_t axis; double reference_position_deg, measured_position_deg, signed_error_deg, absolute_error_deg; char timestamp[TIMESTAMP_LENGTH]; } CalibrationRecord_t;
typedef struct { size_t measurement_count; double mean_signed_error_deg, mean_absolute_error_deg, maximum_absolute_error_deg; } CalibrationSummary_t;
#endif
