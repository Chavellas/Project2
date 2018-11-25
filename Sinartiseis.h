/*
Chavellas Christos
AM: 1115201300196
 */

#ifndef SINARTISEIS_H
#define SINARTISEIS_H

#include <vector>
#include <string>

#include "Dianisma.h"
#include "PinakasDianismaton.h"

using namespace std;

class Sinartiseis {
public:
    Sinartiseis();
    virtual ~Sinartiseis();

    // ------------------------ boithitikes --------------------------

    std::vector<std::string> split(const std::string& s, char delimiter);
    double pollaplasiasmos(Dianisma * left, Dianisma * right);
    long int modulo(long int N, long int M);
    double ypologismosApostasis(Dianisma * apo, Dianisma * mexri, AlgorithmosEktelesis ae);
    double ypologismosApostasisEuclidean(Dianisma * apo, Dianisma * mexri);
    double ypologismosApostasisCosine(Dianisma * apo, Dianisma * mexri);

    // ------------------------ ypologismoi --------------------------

    void katharismosFlags(PinakasDianismaton * pinakasDianysmaton);
    vector<void*> * exantlitikiAnazitisi(PinakasDianismaton * pinakasDianysmaton,  Dianisma * erotima, AlgorithmosEktelesis ae );
    vector<void*> * proseggistikiAnazitisi(PinakaPinakon * pinakasPinakon, PinakasDianismaton * pinakasDianysmaton, Dianisma * erotima, AlgorithmosEktelesis ae );
    vector<string> * proseggistikiAnazitisiSeAktina(PinakaPinakon * pinakasPinakon, PinakasDianismaton * pinakasDianysmaton, Dianisma * erotima, AlgorithmosEktelesis ae, double aktina );

private:

};

#endif
