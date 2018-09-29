//
// Created by Olcay Taner Yıldız on 29.09.2018.
//

#ifndef SAMPLING_STRATIFIEDKFOLDCROSSVALIDATION_H
#define SAMPLING_STRATIFIEDKFOLDCROSSVALIDATION_H

#include <vector>
#include "CrossValidation.h"

template <class T> class StratifiedKFoldCrossValidation : public CrossValidation<T> {
private:
    unsigned long* N;
    vector<T>* instanceLists;
    int size;
public:
    StratifiedKFoldCrossValidation(const vector<T>* instanceLists, int size, int K, unsigned int seed);
    virtual ~StratifiedKFoldCrossValidation();
    vector<T> getTrainFold(int k);
    vector<T> getTestFold(int k);
};


#endif //SAMPLING_STRATIFIEDKFOLDCROSSVALIDATION_H
