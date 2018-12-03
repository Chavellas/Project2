/*
Chavellas Christos
AM: 1115201300196
 */

#ifndef PINAKASPINAKON_H
#define PINAKASPINAKON_H

#include "Pinakas.h"
#include "Typoi.h"

#include <vector>

using namespace std;

class PinakaPinakon {
public:
    PinakaPinakon(unsigned int L, unsigned int T, unsigned int k, unsigned int d, AlgorithmosEktelesis ae);
    virtual ~PinakaPinakon();
    void eisagogi(Dianisma * x);
    vector<void*>* anazitisi(PinakasDianismaton * pinakasDianysmaton, Dianisma * x, AlgorithmosEktelesis ae);
    vector<string> * anazitisiSeAktina(PinakasDianismaton * pinakasDianysmaton, Dianisma * x, AlgorithmosEktelesis ae, double aktina);
    vector<int> * anazitisiOffsetsSeAktina(PinakasDianismaton * pinakasDianysmaton, Dianisma * x, AlgorithmosEktelesis ae, double aktina);
    unsigned int getL();
private:
    Pinakas ** pinakes;
    unsigned int L;
};

#endif
