#include "main_test.h"

TEST(CHECK, FirstFunction) {
    ASSERT_EQ(1, FirstFunction());
}

TEST(CHECK, SecondFunction) {
    ASSERT_EQ(2, SecondFunction());
}


int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
