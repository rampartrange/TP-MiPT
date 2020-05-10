//
// Created by akhtyamovpavel on 5/1/20.
//

#include "AddTestCase.h"
#include "Functions.h"

TEST_F(AddTestCase, Test1) {
    ASSERT_EQ(Add(-1, 1), 0);
}
