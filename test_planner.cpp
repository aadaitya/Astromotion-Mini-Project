#include <gtest/gtest.h>
extern "C" {
#include "planner.h"
}
static MountConfig_t c(){MountConfig_t x{};for(int i=0;i<2;i++)x.axes[i]={{1.8,16,100,2000},-90,90};return x;}
TEST(Planner,TwoAxisPlan){auto x=c();MountState_t s{{0,0}};MovementRequest_t r{{1,-2}};MovementPlan_t p{};EXPECT_EQ(planner_create_plan(&x,&s,&r,&p),STATUS_SUCCESS);EXPECT_EQ(p.axis_plans[0].steps,889u);EXPECT_EQ(p.axis_plans[1].direction,DIRECTION_NEGATIVE);}
TEST(Planner,LimitRejected){auto x=c();MountState_t s{{89.5,0}};MovementRequest_t r{{1,0}};MovementPlan_t p{};EXPECT_EQ(planner_create_plan(&x,&s,&r,&p),STATUS_LIMIT_EXCEEDED);}
TEST(Planner,DurationMaximum){auto x=c();MountState_t s{{0,0}};MovementRequest_t r{{1,2}};MovementPlan_t p{};ASSERT_EQ(planner_create_plan(&x,&s,&r,&p),STATUS_SUCCESS);EXPECT_DOUBLE_EQ(p.total_duration_sec,p.axis_plans[1].duration_sec);}
