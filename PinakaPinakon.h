/*
Chavellas Christos
AM: 1115201300196
 */

#ifndef PINAKAPINAKON_H
#define PINAKAPINAKON_H

#include "Pinakas.h"
#include "Typoi.h"

class PinakaPinakon {
public:
    PinakaPinakon(unsigned int L, unsigned int T, unsigned int k, unsigned int d, AlgorithmosEktelesis ae);
    virtual ~PinakaPinakon();
    void eisagogi(Dianisma * x);
    vector<void*>* anazitisi(PinakasDianismaton * pinakasDianysmaton, Dianisma * x, AlgorithmosEktelesis ae);
    vector<string> * anazitisiSeAktina(PinakasDianismaton * pinakasDianysmaton, Dianisma * x, AlgorithmosEktelesis ae, double aktina);
    unsigned int getL();
private:
    Pinakas ** pinakes;
    unsigned int L;
};

#endif
