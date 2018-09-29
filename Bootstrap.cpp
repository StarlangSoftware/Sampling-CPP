//
// Created by Olcay Taner Yıldız on 27.09.2018.
//

#include "Bootstrap.h"
using namespace std;

template<class T> Bootstrap<T>::Bootstrap(const vector<T> &instanceList, unsigned int seed) {
    unsigned long N;
    srand(seed);
    N = instanceList.capacity();
    for (int i = 0; i < N; i++){
        this->instanceList.push_back(instanceList.at(random() % N));
    }
}

template<class T> vector<T> Bootstrap<T>::getSample(){
    return instanceList;
}
