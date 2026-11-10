#include <gtest/gtest.h>
extern "C" {
#include "calibration.h"
}
TEST(Calibration,Error){CalibrationRecord_t r{};EXPECT_EQ(calibration_create_record(AXIS_1,10,10.5,"t",&r),STATUS_SUCCESS);EXPECT_DOUBLE_EQ(r.signed_error_deg,.5);EXPECT_DOUBLE_EQ(r.absolute_error_deg,.5);}
TEST(Calibration,Summary){CalibrationRecord_t r[2]{};ASSERT_EQ(calibration_create_record(AXIS_1,0,1,"t",&r[0]),STATUS_SUCCESS);ASSERT_EQ(calibration_create_record(AXIS_2,0,-2,"t",&r[1]),STATUS_SUCCESS);CalibrationSummary_t s{};EXPECT_EQ(calibration_summarize(r,2,&s),STATUS_SUCCESS);EXPECT_DOUBLE_EQ(s.mean_absolute_error_deg,1.5);EXPECT_DOUBLE_EQ(s.maximum_absolute_error_deg,2);}
TEST(Calibration,Empty){CalibrationSummary_t s{};EXPECT_EQ(calibration_summarize(nullptr,0,&s),STATUS_NO_DATA);}
