/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Clustering.h
 * Author: nikolaus
 *
 * Created on November 14, 2018, 9:40 PM
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
    
    PinakasKentron * pam(PinakasDianismaton * pd, PinakasKentron *, PinakasAnathesewn *  );
    PinakasKentron * kmeans(PinakasDianismaton * pd, PinakasKentron *kentra, PinakasAnathesewn * anatheseis, AlgorithmosEktelesis ae);
    
    double elegxosApostasisKentron(PinakasKentron *,PinakasKentron *, AlgorithmosEktelesis ae);
    
    double silouette(PinakasDianismaton * pd, PinakasKentron *kentra, PinakasAnathesewn * anatheseis, AlgorithmosEktelesis ae);
private:
    double silouette(int i,int cluster_inner,int cluster_outerm, PinakasDianismaton * pd, PinakasKentron *kentra, PinakasAnathesewn * pinakasAnatheseon, list<unsigned int> * deiktis,AlgorithmosEktelesis ae);
};

#endif /* CLUSTERING_H */

