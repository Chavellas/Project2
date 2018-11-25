/*
Chavellas Christos
AM: 1115201300196
 */

#ifndef HASHFUNCTION_H
#define HASHFUNCTION_H

#include "Typoi.h"
#include "Dianisma.h"


class HashFunction {
public:
    HashFunction(AlgorithmosEktelesis ae, unsigned int k, unsigned int d);
    virtual ~HashFunction();
    unsigned int ypologismosThesis(Dianisma * x);

private:
    AlgorithmosEktelesis ae;
    // ae = euclidean or hypercube
    unsigned int k;
    Dianisma * v;
    float * t;
    float * r;
    // ae = cosine
    Dianisma * cr;
};

#endif
