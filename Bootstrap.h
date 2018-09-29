#ifndef SAMPLING_BOOTSTRAP_H
#define SAMPLING_BOOTSTRAP_H

#include <vector>
using namespace std;

template <class T> class Bootstrap {
private:
    vector<T> instanceList;
public:
    Bootstrap(const vector<T> &instanceList, unsigned int seed);
    vector<T> getSample();
};

#endif //SAMPLING_BOOTSTRAP_H
