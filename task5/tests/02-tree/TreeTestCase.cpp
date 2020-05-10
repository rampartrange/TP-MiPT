//
// Created by akhtyamovpavel on 5/1/20.
//


#include "TreeTestCase.h"
#include "Tree.h"
#include "boost/filesystem/operations.hpp"
#include <fstream>

using boost::filesystem::current_path;
using boost::filesystem::create_directory;
using boost::filesystem::remove_all;

void TreeTestCase::SetUp() {
    test_path = current_path().string() + "/test";
    create_directory(test_path);

    std::ofstream fout(test_path + "/file_for_test.txt");
    fout << "Writing tests sucks!!!\n";

    fout.close();
    create_directory(test_path + "/another_test");
}

void TreeTestCase::TearDown() {
    remove_all(test_path);
}

TEST_F(TreeTestCase, Test1) {
    ASSERT_THROW(GetTree(test_path + "/xXx", false), std::invalid_argument);
}

TEST_F(TreeTestCase, Test2) {
    ASSERT_THROW(GetTree(test_path + "/file_for_test.txt", false), std::invalid_argument);
}

TEST_F(TreeTestCase, Test3) {
    ASSERT_NO_THROW(GetTree(test_path, false));
}

TEST_F(TreeTestCase, Test4) {
    ASSERT_NO_THROW(GetTree(test_path, true));
}

TEST_F(TreeTestCase, Test5) {
    ASSERT_TRUE(GetTree(test_path, true) == GetTree(test_path, true));
}