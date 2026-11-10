#include <gtest/gtest.h>
extern "C" {
#include "motor.h"
}
static MotorConfig_t m(){return {1.8,16,100,2000};}
TEST(Motor,ValidConfig){auto x=m();EXPECT_EQ(motor_validate_config(&x),STATUS_SUCCESS);}
TEST(Motor,NullConfig){EXPECT_EQ(motor_validate_config(nullptr),STATUS_INVALID_INPUT);}
TEST(Motor,ZeroMicrostep){auto x=m();x.microstepping=0;EXPECT_EQ(motor_validate_config(&x),STATUS_INVALID_CONFIG);}
TEST(Motor,StepsPerDegree){auto x=m();double s;EXPECT_EQ(motor_steps_per_degree(&x,&s),STATUS_SUCCESS);EXPECT_NEAR(s,888.8888889,1e-6);}
TEST(Motor,PositiveSteps){auto x=m();uint64_t n;Direction_t d;double a;EXPECT_EQ(motor_calculate_steps(&x,1,&n,&d,&a),STATUS_SUCCESS);EXPECT_EQ(n,889u);EXPECT_EQ(d,DIRECTION_POSITIVE);}
TEST(Motor,NegativeSteps){auto x=m();uint64_t n;Direction_t d;double a;EXPECT_EQ(motor_calculate_steps(&x,-1,&n,&d,&a),STATUS_SUCCESS);EXPECT_EQ(d,DIRECTION_NEGATIVE);}
TEST(Motor,ZeroSteps){auto x=m();uint64_t n;Direction_t d;double a;EXPECT_EQ(motor_calculate_steps(&x,0,&n,&d,&a),STATUS_SUCCESS);EXPECT_EQ(n,0u);EXPECT_EQ(d,DIRECTION_STOP);}
TEST(Motor,Duration){auto x=m();double t;EXPECT_EQ(motor_estimate_duration(&x,1000,&t),STATUS_SUCCESS);EXPECT_DOUBLE_EQ(t,.5);}
