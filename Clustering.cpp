/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Clustering.cpp
 * Author: nikolaus
 * 
 * Created on November 14, 2018, 9:40 PM
 */

#include "Clustering.h"

Clustering::Clustering() {
}

Clustering::~Clustering() {
}

PinakasKentron * Clustering::random(PinakasDianismaton * pd, int plithos_clusters) {
    return 0;
}

PinakasKentron * Clustering::kmeanspp(PinakasDianismaton * pd, int plithos_clusters) {
    return 0;
}

PinakasAnathesewn * Clustering::lloyd(PinakasDianismaton * pd, PinakasKentron *) {
    return 0;   
}

PinakasAnathesewn * Clustering::lsh(PinakasDianismaton * pd, PinakasKentron *, PinakaPinakon * pinakasPinakon, int K, int L) {
    return 0;
}

PinakasKentron * Clustering::pam(PinakasDianismaton * pd, PinakasKentron *, PinakasAnathesewn *) {
    return 0;
}

PinakasKentron * Clustering::kmeans(PinakasDianismaton * pd, PinakasKentron *, PinakasAnathesewn *) {
    return 0;
}
