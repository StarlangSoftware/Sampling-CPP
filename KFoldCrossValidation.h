//
// Created by Olcay Taner Yıldız on 28.09.2018.
//

#ifndef SAMPLING_KFOLDCROSSVALIDATION_H
#define SAMPLING_KFOLDCROSSVALIDATION_H
#include "CrossValidation.h"
using namespace std;

template <class T> class KFoldCrossValidation : public CrossValidation<T>{
private:
    unsigned long N;
    vector<T> instanceList;
public:
    KFoldCrossValidation(const vector<T>& instanceList, int K, unsigned int seed);
    vector<T> getTrainFold(int k);
    vector<T> getTestFold(int k);
};


#endif //SAMPLING_KFOLDCROSSVALIDATION_H
