//
// Created by akhtyamovpavel on 5/1/20.
//

#include "LeapTestCase.h"

#include <Functions.h>


TEST_F(LeapTestCase, Test1) {
    ASSERT_THROW(IsLeap(-1), std::invalid_argument);
}

TEST_F(LeapTestCase, Test2) {
    ASSERT_FALSE(IsLeap(100));
}

TEST_F(LeapTestCase, Test3) {
    ASSERT_TRUE(IsLeap(16));
}

TEST_F(LeapTestCase, Test4) {
    ASSERT_FALSE(IsLeap(15));
}

TEST_F(LeapTestCase, Test5) {
    ASSERT_TRUE(IsLeap(400));
}