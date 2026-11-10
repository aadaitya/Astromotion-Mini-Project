#ifndef CALIBRATION_H
#define CALIBRATION_H
#include "astro_types.h"
Status_t calibration_create_record(Axis_t,double,double,const char *,CalibrationRecord_t *);
Status_t calibration_summarize(const CalibrationRecord_t *,size_t,CalibrationSummary_t *);
#endif
