//
// Created by Olcay Taner YILDIZ on 20.12.2020.
//

#include "catch.hpp"
#include "../src/KFoldCrossValidation.h"

using namespace std;

TEST_CASE("KFoldCrossValidation-testSmallSample10Fold") {
    vector<string> smallSample = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10"};
    KFoldCrossValidation<string> kFoldCrossValidation = KFoldCrossValidation<string>(smallSample, 10, 1);
    vector<string> testSample = kFoldCrossValidation.getTestFold(0);
    REQUIRE(testSample[0] == "2");
}

TEST_CASE("KFoldCrossValidation-testSmallSample5Fold") {
    vector<string> smallSample = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10"};
    KFoldCrossValidation<string> kFoldCrossValidation = KFoldCrossValidation<string>(smallSample, 5, 1);
    vector<string> testSample = kFoldCrossValidation.getTestFold(0);
    REQUIRE(testSample[0] == "2");
    REQUIRE(testSample[1] == "7");
}

TEST_CASE("KFoldCrossValidation-testSmallSample2Fold") {
    vector<string> smallSample = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10"};
    KFoldCrossValidation<string> kFoldCrossValidation = KFoldCrossValidation<string>(smallSample, 2, 1);
    vector<string> testSample = kFoldCrossValidation.getTestFold(0);
    REQUIRE(testSample[0] == "2");
    REQUIRE(testSample[1] == "7");
    REQUIRE(testSample[2] == "1");
    REQUIRE(testSample[3] == "4");
    REQUIRE(testSample[4] == "3");
}

TEST_CASE("KFoldCrossValidation-testLargeSample10Fold") {
    vector<int> largeSample;
    for (int i = 0; i < 1000; i++){
        largeSample.emplace_back(i);
    }
    KFoldCrossValidation<int> kFoldCrossValidation = KFoldCrossValidation<int>(largeSample, 10, 1);
    for (int i = 0; i < 10; i++){
        REQUIRE(100 == kFoldCrossValidation.getTestFold(i).size());
        REQUIRE(900 == kFoldCrossValidation.getTrainFold(i).size());
    }
}

TEST_CASE("KFoldCrossValidation-testLargeSample5Fold") {
    vector<int> largeSample;
    for (int i = 0; i < 1000; i++){
        largeSample.emplace_back(i);
    }
    KFoldCrossValidation<int> kFoldCrossValidation = KFoldCrossValidation<int>(largeSample, 5, 1);
    for (int i = 0; i < 5; i++){
        REQUIRE(200 == kFoldCrossValidation.getTestFold(i).size());
        REQUIRE(800 == kFoldCrossValidation.getTrainFold(i).size());
    }
}

TEST_CASE("KFoldCrossValidation-testLargeSample2Fold") {
    vector<int> largeSample;
    for (int i = 0; i < 1000; i++){
        largeSample.emplace_back(i);
    }
    KFoldCrossValidation<int> kFoldCrossValidation = KFoldCrossValidation<int>(largeSample, 2, 1);
    for (int i = 0; i < 2; i++){
        REQUIRE(500 == kFoldCrossValidation.getTestFold(i).size());
        REQUIRE(500 == kFoldCrossValidation.getTrainFold(i).size());
    }
}
