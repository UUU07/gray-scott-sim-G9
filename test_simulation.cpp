#include <gtest/gtest.h>
#include "gs.cpp"
TEST(SimulationTests, CheckModelParameterTypes) {
    EXPECT_TRUE(std::is_same<decltype(F), decltype(u[0])>::value);
    EXPECT_TRUE(std::is_same<decltype(k), decltype(u[0])>::value);
}

TEST(SimulationTests, CheckUVSize) {
    ASSERT_EQ(u.size(), v.size());
}

TEST(SimulationTests, CheckSimulationWithZeroUV) {
    const double epsilon = 1e-10;
    u.assign(u.size(), 0.0);
    v.assign(v.size(), 0.0);
    simulate(u, v, F, k, dt, dx);

    for (size_t i = 0; i < u.size(); ++i) {
        EXPECT_NEAR(u[i], 0.0, epsilon);
        EXPECT_NEAR(v[i], 0.0, epsilon);
    }
}
