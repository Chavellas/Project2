/*
Chavellas Christos
AM: 1115201300196
 */

#ifndef SINARTISEIS_H
#define SINARTISEIS_H

#include <vector>
#include <string>
#include <unordered_map>

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
    
    double ypologismosRizasApostasis(Dianisma * apo, Dianisma * mexri, AlgorithmosEktelesis ae);
    double ypologismosRizasApostasisAnalytika(Dianisma * apo, Dianisma * mexri, AlgorithmosEktelesis ae);
    double ypologismosRizasApostasisEuclidean(Dianisma * apo, Dianisma * mexri);
    double ypologismosRizasApostasisCosine(Dianisma * apo, Dianisma * mexri);

    // ------------------------ ypologismoi --------------------------

    static void calculateDistanceMatrix(PinakasDianismaton * pinakasDianysmaton, AlgorithmosEktelesis ae);
    static void cleanupDistanceMatrix();
    
    
    void katharismosFlags(PinakasDianismaton * pinakasDianysmaton);
    vector<void*> * exantlitikiAnazitisi(PinakasDianismaton * pinakasDianysmaton,  Dianisma * erotima, AlgorithmosEktelesis ae );
    vector<void*> * proseggistikiAnazitisi(PinakaPinakon * pinakasPinakon, PinakasDianismaton * pinakasDianysmaton, Dianisma * erotima, AlgorithmosEktelesis ae );
    vector<string> * proseggistikiAnazitisiSeAktina(PinakaPinakon * pinakasPinakon, PinakasDianismaton * pinakasDianysmaton, Dianisma * erotima, AlgorithmosEktelesis ae, double aktina );
    
    vector<int> * proseggistikiAnazitisiOffsetsSeAktina(PinakaPinakon * pinakasPinakon, PinakasDianismaton * pinakasDianysmaton, Dianisma * erotima, AlgorithmosEktelesis ae, double aktina );

private:
    static double ** distanceMatrix;
    static unsigned int distanceMatrixDimension;
};

#endif
