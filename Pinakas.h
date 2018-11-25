/*
Chavellas Christos
AM: 1115201300196
 */

#ifndef PINAKAS_H
#define PINAKAS_H

#include <list>
#include <vector>

#include "Typoi.h"
#include "HashFunction.h"
#include "PinakasDianismaton.h"

using namespace std;

class Pinakas {
public:
    Pinakas(unsigned int T, unsigned int k, unsigned int d, AlgorithmosEktelesis ae);
    virtual ~Pinakas();
    void eisagogi(Dianisma * x);
    vector<void*> * anazitisi(PinakasDianismaton * pinakasDianysmaton, Dianisma * x);
    void anazitisiSeAktina(PinakasDianismaton * pinakasDianysmaton, Dianisma * x, double aktina, vector<string> * apotelesmata);
private:
    list<unsigned int> * deiktis;
    unsigned int T;
    AlgorithmosEktelesis ae;
    HashFunction hashfunction;
};

#endif
