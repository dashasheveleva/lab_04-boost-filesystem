// Copyright 2021 Daria <photodoshfy@gmail.com>

#include <stdexcept>
#include <gtest/gtest.h>
#include <broker.hpp>

TEST(ViewDirectory, CorrectPrintFilesAndAccountsEmptyPath) {
    Broker vd("");
    std::stringstream ss1 = vd.PrintFiles();
    std::stringstream ss2 = vd.PrintAccounts();
    EXPECT_EQ(ss1.str(), "");
    EXPECT_EQ(ss2.str(), "");
}

