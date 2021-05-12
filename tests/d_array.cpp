#include <gtest/gtest.h>

#include "d_array.hpp"
#include <vector>

TEST(Vectortest, VectorElement) {
    DArray<int> dArr {1, 2, 3};

    ASSERT_EQ(dArr.size(), 3);
    ASSERT_EQ(dArr[0], 1);
    ASSERT_EQ(dArr[1], 2);
    ASSERT_EQ(dArr[2], 3);
}

