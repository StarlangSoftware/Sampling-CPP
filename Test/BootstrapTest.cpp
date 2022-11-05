//
// Created by Olcay Taner YILDIZ on 20.12.2020.
//

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "../src/Bootstrap.h"
#include <unordered_set>

using namespace std;

TEST_CASE("Bootstrap-testSmallSample") {
    vector<string> smallSample = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10"};
    Bootstrap<string> bootstrap = Bootstrap<string>(smallSample, 1);
    vector<string> bootstrapSample = bootstrap.getSample();
    REQUIRE(bootstrapSample[0] == "10");
    REQUIRE(bootstrapSample[1] == "4");
    REQUIRE(bootstrapSample[2] == "5");
    REQUIRE(bootstrapSample[3] == "6");
    REQUIRE(bootstrapSample[4] == "4");
    REQUIRE(bootstrapSample[5] == "6");
    REQUIRE(bootstrapSample[6] == "7");
    REQUIRE(bootstrapSample[7] == "3");
    REQUIRE(bootstrapSample[8] == "10");
    REQUIRE(bootstrapSample[9] == "2");
}

TEST_CASE("Bootstrap-testLargeSample") {
    vector<int> largeSample;
    for (int i = 0; i < 1000000; i++){
        largeSample.emplace_back(i);
    }
    Bootstrap<int> bootstrap = Bootstrap<int>(largeSample, 1);
    vector<int> bootstrapSample = bootstrap.getSample();
    unordered_set<int> set(bootstrapSample.begin(), bootstrapSample.end());
    REQUIRE_THAT(set.size() / 1000000.0, Catch::Matchers::WithinAbs(0.632, 0.001));
}
