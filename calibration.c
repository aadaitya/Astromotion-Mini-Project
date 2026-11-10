#include "calibration.h"
#include <math.h>
#include <stdio.h>
Status_t calibration_create_record(Axis_t axis,double ref,double measured,const char *time,CalibrationRecord_t *r) {
 if(!r||!time||(axis!=AXIS_1&&axis!=AXIS_2)||!isfinite(ref)||!isfinite(measured))return STATUS_INVALID_INPUT;
 r->axis=axis;r->reference_position_deg=ref;r->measured_position_deg=measured;
 r->signed_error_deg=measured-ref;r->absolute_error_deg=fabs(r->signed_error_deg);
 (void)snprintf(r->timestamp,sizeof(r->timestamp),"%s",time);return STATUS_SUCCESS;
}
Status_t calibration_summarize(const CalibrationRecord_t *r,size_t n,CalibrationSummary_t *s) {
 if(!s||(!r&&n)) return STATUS_INVALID_INPUT;
 if(!n) return STATUS_NO_DATA;
 double sum=0,abs=0,max=0;
 for(size_t i=0;i<n;i++){if(!isfinite(r[i].signed_error_deg)||!isfinite(r[i].absolute_error_deg))return STATUS_INVALID_INPUT;sum+=r[i].signed_error_deg;abs+=r[i].absolute_error_deg;if(r[i].absolute_error_deg>max)max=r[i].absolute_error_deg;}
 s->measurement_count=n;s->mean_signed_error_deg=sum/n;s->mean_absolute_error_deg=abs/n;s->maximum_absolute_error_deg=max;return STATUS_SUCCESS;
}
