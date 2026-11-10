#ifndef REPORT_H
#define REPORT_H
#include "astro_types.h"
void report_print_plan(const MovementPlan_t *);
void report_print_state(const MountState_t *);
void report_print_calibration(const CalibrationSummary_t *);
Status_t report_sort_movements(MovementRecord_t *,size_t,SortCriteria_t);
#endif
