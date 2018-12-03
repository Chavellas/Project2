/*
Chavellas Christos
AM: 1115201300196
 */

#ifndef CLUSTERING_H
#define CLUSTERING_H

#include "PinakasDianismaton.h"
#include "PinakasKentron.h"
#include "PinakasAnathesewn.h"

#include <list>

using namespace std;

class Clustering {
public:
    Clustering();
    virtual ~Clustering();
    
    PinakasKentron * random(PinakasDianismaton * pd, int plithos_clusters);
    PinakasKentron * kmeanspp(PinakasDianismaton * pd, int plithos_clusters, AlgorithmosEktelesis ae);
    
    PinakasAnathesewn * lloyd(PinakasDianismaton * pd,  PinakasKentron *, AlgorithmosEktelesis ae);
    PinakasAnathesewn * lsh(PinakasDianismaton * pd,  PinakasKentron *, PinakaPinakon * pinakasPinakon, int K, int L, AlgorithmosEktelesis ae);
    
    PinakasKentron * pam(PinakasDianismaton * pd, PinakasKentron *, PinakasAnathesewn *  , AlgorithmosEktelesis ae);
    PinakasKentron * kmeans(PinakasDianismaton * pd, PinakasKentron *kentra, PinakasAnathesewn * anatheseis, AlgorithmosEktelesis ae);
    
    double elegxosApostasisKentron(PinakasKentron *,PinakasKentron *, AlgorithmosEktelesis ae);
    
    double * silouette(PinakasDianismaton * pd, PinakasKentron *kentra, PinakasAnathesewn * anatheseis, AlgorithmosEktelesis ae);
private:
    double silouette(int i,int cluster_inner,int cluster_outerm, PinakasDianismaton * pd, PinakasKentron *kentra, PinakasAnathesewn * pinakasAnatheseon, list<unsigned int> * deiktis,AlgorithmosEktelesis ae);
    
    void lloydOnlyOne(int offset, PinakasDianismaton * pd,  PinakasKentron *, AlgorithmosEktelesis ae, PinakasAnathesewn * anatheseis);
};

#endif /* CLUSTERING_H */

