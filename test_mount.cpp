#include <gtest/gtest.h>
extern "C" {
#include "mount.h"
}
TEST(Mount,Initialize){MountConfig_t c{};for(int i=0;i<2;i++)c.axes[i]={{1.8,16,100,2000},-90,90};MountState_t s{};double p[2]={10,-10};EXPECT_EQ(mount_initialize(&s,p,&c),STATUS_SUCCESS);EXPECT_DOUBLE_EQ(s.position_deg[0],10);}
TEST(Mount,RejectInitialLimit){MountConfig_t c{};for(int i=0;i<2;i++)c.axes[i]={{1.8,16,100,2000},-90,90};MountState_t s{};double p[2]={91,0};EXPECT_EQ(mount_initialize(&s,p,&c),STATUS_LIMIT_EXCEEDED);}
