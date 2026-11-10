#include <gtest/gtest.h>
extern "C" {
#include "validation.h"
}
static AxisConfig_t a(){return {{1.8,16,100,2000},-90,90};}
TEST(Validation,ValidAxis){auto x=a();EXPECT_EQ(validation_check_axis_config(&x),STATUS_SUCCESS);}
TEST(Validation,InvalidLimits){auto x=a();x.max_angle_deg=-90;EXPECT_EQ(validation_check_axis_config(&x),STATUS_INVALID_CONFIG);}
TEST(Validation,LowerBoundary){auto x=a();EXPECT_EQ(validation_check_position(&x,-90),STATUS_SUCCESS);}
TEST(Validation,UpperBoundary){auto x=a();EXPECT_EQ(validation_check_position(&x,90),STATUS_SUCCESS);}
TEST(Validation,OutsideLimit){auto x=a();EXPECT_EQ(validation_check_position(&x,91),STATUS_LIMIT_EXCEEDED);}
TEST(Validation,NullRequest){EXPECT_EQ(validation_check_request(nullptr),STATUS_INVALID_INPUT);}
