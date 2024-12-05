//
// Created by rodio on 01.12.2024.
//

#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "fraction.h"

int number[6][2]{5, 2, 2, 5, 0, 1, -1, 1, 7, 2, 9, 1};
std::vector<std::string> tResForSum{"29/10", "-1/1", "25/2"};
std::vector<std::string> tResForSub{"21/10", "1/1", "-11/2"};
std::vector<std::string> tResForDiv{"25/4", "0/1", "7/18"};
std::vector<std::string> tResForMul{"1/1", "0/1", "63/2"};

TEST(testfraction, testinit) {
    RationalNumber<int> mynumber(5,2);
    std::string tRes = "5/2";
    ASSERT_EQ(mynumber.toString(), tRes);

    mynumber = RationalNumber<int>(2,5);
    tRes = "2/5";
    ASSERT_EQ(mynumber.toString(), tRes);
}


TEST(testfraction, testinitwithnorm) {
    RationalNumber<int> mynumber(4,2);
    std::string tRes = "2/1";
    ASSERT_EQ(mynumber.toString(), tRes);

    mynumber = RationalNumber<int>(1, -1);
    tRes = "-1/1";
    ASSERT_EQ(mynumber.toString(), tRes);
}


TEST(testfraction, testdefaultinit) {
    RationalNumber<int> mynumber;
    std::string tRes = "0/1";
    EXPECT_EQ(mynumber.toString(), tRes);
}


TEST(testfraction, testsum) {
    int cnt = 0;
    for (int i = 0; i < 6; i+=2) {
        RationalNumber<int> left{number[i][0], number[i][1]};
        RationalNumber<int> right{number[i+1][0], number[i+1][1]};
        RationalNumber<int> sum = left.sum(right);
        EXPECT_EQ(sum.toString(), tResForSum[cnt++]) << "Number of Test " << cnt;
    }
}

TEST(testfraction, testsub) {
    int cnt = 0;
    for (int i = 0; i < 6; i+=2) {
        RationalNumber<int> left{number[i][0], number[i][1]};
        RationalNumber<int> right{number[i+1][0], number[i+1][1]};
        RationalNumber<int> sum = left.sub(right);
        EXPECT_EQ(sum.toString(), tResForSub[cnt++]) << "Number of Test" << cnt;
    }
}

TEST(testfraction, testdiv) {
    int cnt = 0;
    for (int i = 0; i < 6; i+=2) {
        RationalNumber<int> left{number[i][0], number[i][1]};
        RationalNumber<int> right{number[i+1][0], number[i+1][1]};
        RationalNumber<int> sum = left.div(right);
        ASSERT_EQ(sum.toString(), tResForDiv[cnt++]) << "Number of Test " << cnt;
    }
}

TEST(testfraction, testmultiply) {
    int cnt = 0;
    for (int i = 0; i < 6; i+=2) {
        RationalNumber<int> left{number[i][0], number[i][1]};
        RationalNumber<int> right{number[i+1][0], number[i+1][1]};
        RationalNumber<int> sum = left.multiply(right);
        EXPECT_EQ(sum.toString(), tResForMul[cnt++]) << "Number of Test " << cnt;
    }
}

TEST(testfraction, testunarplus) {
    RationalNumber<int> num{4,5};
    +num;
    EXPECT_EQ(num.toString(), "4/5");
}

TEST(testfraction, testsumoperator) {
    int cnt = 0;
    for (int i = 0; i < 6; i+=2) {
        RationalNumber<int> left{number[i][0], number[i][1]};
        RationalNumber<int> right{number[i+1][0], number[i+1][1]};
        RationalNumber<int> sum = left + right;
        EXPECT_EQ(sum.toString(), tResForSum[cnt++]) << "Number of Test " << cnt;
    }
}



TEST(testfraction, testminusoperator) {
    int cnt = 0;
    for (int i = 0; i < 6; i+=2) {
        RationalNumber<int> left{number[i][0], number[i][1]};
        RationalNumber<int> right{number[i+1][0], number[i+1][1]};
        RationalNumber<int> sum = left - right;
        EXPECT_EQ(sum.toString(), tResForSub[cnt++]) << "Number of Test " << cnt;
    }
}

TEST(testfraction, testoperatormulty) {
    int cnt = 0;
    for (int i = 0; i < 6; i+=2) {
        RationalNumber<int> left{number[i][0], number[i][1]};
        RationalNumber<int> right{number[i+1][0], number[i+1][1]};
        RationalNumber<int> sum = left * right;
        EXPECT_EQ(sum.toString(), tResForMul[cnt++]) << "Number of Test " << cnt;
    }
}

TEST(testfraction, testdivoperator) {
    int cnt = 0;
    for (int i = 0; i < 6; i+=2) {
        RationalNumber<int> left{number[i][0], number[i][1]};
        RationalNumber<int> right{number[i+1][0], number[i+1][1]};
        RationalNumber<int> sum = left / right;
        EXPECT_EQ(sum.toString(), tResForDiv[cnt++]) << "Number of Test " << cnt;
    }
}

TEST(testfraction, testpluschange) {
    RationalNumber<int> left{1,1};
    RationalNumber<int> right{1,1};
    left += right += right;
    EXPECT_EQ(left.toString(), "3/1");
}

TEST(testfraction, testpostfixincrement) {
    RationalNumber<int> left{1,1};
    RationalNumber<int> right{1,1};
    right += left++;
    EXPECT_EQ(left.toString(), "2/1");
    EXPECT_EQ(right.toString(), "2/1");
}


TEST(testfraction, testorefixincrement) {
    RationalNumber<int> left{1,1};
    RationalNumber<int> right{1,1};
    right += ++left;
    EXPECT_EQ(left.toString(), "2/1");
    EXPECT_EQ(right.toString(), "3/1");
}

TEST(testfraction, testEqual) {
    RationalNumber<int> left{1,1};
    RationalNumber<int> right{1,1};
    EXPECT_TRUE(left == right);
    ++right;
    EXPECT_FALSE(right == left);
}