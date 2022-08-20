//
// Created by Olcay Taner YILDIZ on 20.12.2020.
//

#include "catch.hpp"
#include "../src/StratifiedKFoldCrossValidation.h"

using namespace std;

TEST_CASE("StratifiedKFoldCrossValidation-testSmallSample10Fold") {
    vector<string> inputClass1 = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10"};
    vector<string> inputClass2 = {"11", "12", "13", "14", "15", "16", "17", "18", "19", "20",
                                   "21", "22", "23", "24", "25", "26", "27", "28", "29", "30"};
    auto* smallSample = new vector<string>[2];
    smallSample[0] = inputClass1;
    smallSample[1] = inputClass2;
    StratifiedKFoldCrossValidation<string> stratifiedKFoldCrossValidation = StratifiedKFoldCrossValidation<string>(smallSample, 2, 10, 1);
    vector<string> testSample = stratifiedKFoldCrossValidation.getTestFold(0);
    REQUIRE(testSample[0] == "2");
    REQUIRE(testSample[1] == "25");
    REQUIRE(testSample[2] == "13");
}

TEST_CASE("StratifiedKFoldCrossValidation-testSmallSample5Fold") {
    vector<string> inputClass1 = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10"};
    vector<string> inputClass2 = {"11", "12", "13", "14", "15", "16", "17", "18", "19", "20",
                                  "21", "22", "23", "24", "25", "26", "27", "28", "29", "30"};
    auto* smallSample = new vector<string>[2];
    smallSample[0] = inputClass1;
    smallSample[1] = inputClass2;
    StratifiedKFoldCrossValidation<string> stratifiedKFoldCrossValidation = StratifiedKFoldCrossValidation<string>(smallSample, 2, 5, 1);
    vector<string> testSample = stratifiedKFoldCrossValidation.getTestFold(0);
    REQUIRE(testSample[0] == "2");
    REQUIRE(testSample[1] == "7");
    REQUIRE(testSample[2] == "25");
    REQUIRE(testSample[3] == "13");
    REQUIRE(testSample[4] == "18");
    REQUIRE(testSample[5] == "30");
}

TEST_CASE("StratifiedKFoldCrossValidation-testSmallSample2Fold") {
    vector<string> inputClass1 = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10"};
    vector<string> inputClass2 = {"11", "12", "13", "14", "15", "16", "17", "18", "19", "20",
                                  "21", "22", "23", "24", "25", "26", "27", "28", "29", "30"};
    auto* smallSample = new vector<string>[2];
    smallSample[0] = inputClass1;
    smallSample[1] = inputClass2;
    StratifiedKFoldCrossValidation<string> stratifiedKFoldCrossValidation = StratifiedKFoldCrossValidation<string>(smallSample, 2, 2, 1);
    vector<string> testSample = stratifiedKFoldCrossValidation.getTestFold(0);
    REQUIRE(testSample[0] == "2");
    REQUIRE(testSample[1] == "7");
    REQUIRE(testSample[2] == "1");
    REQUIRE(testSample[3] == "4");
    REQUIRE(testSample[4] == "3");
    REQUIRE(testSample[5] == "25");
    REQUIRE(testSample[6] == "13");
    REQUIRE(testSample[7] == "18");
    REQUIRE(testSample[8] == "30");
    REQUIRE(testSample[9] == "17");
    REQUIRE(testSample[10] == "16");
    REQUIRE(testSample[11] == "11");
    REQUIRE(testSample[12] == "20");
    REQUIRE(testSample[13] == "21");
    REQUIRE(testSample[14] == "14");
}

TEST_CASE("StratifiedKFoldCrossValidation-testLargeSample10Fold") {
    vector<int> class1, class2, class3;
    auto* largeSample = new vector<int>[3];
    for (int i = 0; i < 1000; i++){
        class1.emplace_back(i);
    }
    for (int i = 0; i < 3000; i++){
        class2.emplace_back(1000 + i);
    }
    for (int i = 0; i < 5000; i++){
        class3.emplace_back(4000 + i);
    }
    largeSample[0] = class1;
    largeSample[1] = class2;
    largeSample[2] = class3;
    StratifiedKFoldCrossValidation<int> stratifiedKFoldCrossValidation = StratifiedKFoldCrossValidation<int>(largeSample, 3, 10, 1);
    for (int i = 0; i < 10; i++){
        vector<int> trainFold = stratifiedKFoldCrossValidation.getTrainFold(i);
        vector<int> testFold = stratifiedKFoldCrossValidation.getTestFold(i);
        REQUIRE(900 == testFold.size());
        REQUIRE(8100 == trainFold.size());
        int trainCounts[3] = {0, 0, 0};
        for (int integer : trainFold){
            if (integer < 1000) {
                trainCounts[0]++;
            } else {
                if (integer < 4000) {
                    trainCounts[1]++;
                } else {
                    trainCounts[2]++;
                }
            }
        }
        REQUIRE(900 == trainCounts[0]);
        REQUIRE(2700 == trainCounts[1]);
        REQUIRE(4500 == trainCounts[2]);
        int testCounts[3] = {0, 0, 0};
        for (int integer : testFold){
            if (integer < 1000) {
                testCounts[0]++;
            } else {
                if (integer < 4000) {
                    testCounts[1]++;
                } else {
                    testCounts[2]++;
                }
            }
        }
        REQUIRE(100 == testCounts[0]);
        REQUIRE(300 == testCounts[1]);
        REQUIRE(500 == testCounts[2]);
    }
}

TEST_CASE("StratifiedKFoldCrossValidation-testLargeSample5Fold") {
    vector<int> class1, class2, class3;
    auto* largeSample = new vector<int>[3];
    for (int i = 0; i < 1000; i++){
        class1.emplace_back(i);
    }
    for (int i = 0; i < 3000; i++){
        class2.emplace_back(1000 + i);
    }
    for (int i = 0; i < 5000; i++){
        class3.emplace_back(4000 + i);
    }
    largeSample[0] = class1;
    largeSample[1] = class2;
    largeSample[2] = class3;
    StratifiedKFoldCrossValidation<int> stratifiedKFoldCrossValidation = StratifiedKFoldCrossValidation<int>(largeSample, 3, 5, 1);
    for (int i = 0; i < 5; i++){
        vector<int> trainFold = stratifiedKFoldCrossValidation.getTrainFold(i);
        vector<int> testFold = stratifiedKFoldCrossValidation.getTestFold(i);
        REQUIRE(1800 == testFold.size());
        REQUIRE(7200 == trainFold.size());
        int trainCounts[3] = {0, 0, 0};
        for (int integer : trainFold){
            if (integer < 1000) {
                trainCounts[0]++;
            } else {
                if (integer < 4000) {
                    trainCounts[1]++;
                } else {
                    trainCounts[2]++;
                }
            }
        }
        REQUIRE(800 == trainCounts[0]);
        REQUIRE(2400 == trainCounts[1]);
        REQUIRE(4000 == trainCounts[2]);
        int testCounts[3] = {0, 0, 0};
        for (int integer : testFold){
            if (integer < 1000) {
                testCounts[0]++;
            } else {
                if (integer < 4000) {
                    testCounts[1]++;
                } else {
                    testCounts[2]++;
                }
            }
        }
        REQUIRE(200 == testCounts[0]);
        REQUIRE(600 == testCounts[1]);
        REQUIRE(1000 == testCounts[2]);
    }
}

TEST_CASE("StratifiedKFoldCrossValidation-testLargeSample2Fold") {
    vector<int> class1, class2, class3;
    auto* largeSample = new vector<int>[3];
    for (int i = 0; i < 1000; i++){
        class1.emplace_back(i);
    }
    for (int i = 0; i < 3000; i++){
        class2.emplace_back(1000 + i);
    }
    for (int i = 0; i < 5000; i++){
        class3.emplace_back(4000 + i);
    }
    largeSample[0] = class1;
    largeSample[1] = class2;
    largeSample[2] = class3;
    StratifiedKFoldCrossValidation<int> stratifiedKFoldCrossValidation = StratifiedKFoldCrossValidation<int>(largeSample, 3, 2, 1);
    for (int i = 0; i < 2; i++){
        vector<int> trainFold = stratifiedKFoldCrossValidation.getTrainFold(i);
        vector<int> testFold = stratifiedKFoldCrossValidation.getTestFold(i);
        REQUIRE(4500 == testFold.size());
        REQUIRE(4500 == trainFold.size());
        int trainCounts[3] = {0, 0, 0};
        for (int integer : trainFold){
            if (integer < 1000) {
                trainCounts[0]++;
            } else {
                if (integer < 4000) {
                    trainCounts[1]++;
                } else {
                    trainCounts[2]++;
                }
            }
        }
        REQUIRE(500 == trainCounts[0]);
        REQUIRE(1500 == trainCounts[1]);
        REQUIRE(2500 == trainCounts[2]);
        int testCounts[3] = {0, 0, 0};
        for (int integer : testFold){
            if (integer < 1000) {
                testCounts[0]++;
            } else {
                if (integer < 4000) {
                    testCounts[1]++;
                } else {
                    testCounts[2]++;
                }
            }
        }
        REQUIRE(500 == testCounts[0]);
        REQUIRE(1500 == testCounts[1]);
        REQUIRE(2500 == testCounts[2]);
    }
}
