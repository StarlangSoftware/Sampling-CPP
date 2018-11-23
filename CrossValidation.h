//
// Created by Olcay Taner Yıldız on 27.09.2018.
//

#ifndef SAMPLING_CROSSVALIDATION_H
#define SAMPLING_CROSSVALIDATION_H
using namespace std;

#include <vector>

template <class T> class CrossValidation {
protected:
    int K;
public:
    virtual vector<T> getTrainFold(int k) = 0;
    virtual vector<T> getTestFold(int k) = 0;
};

#endif //SAMPLING_CROSSVALIDATION_H
