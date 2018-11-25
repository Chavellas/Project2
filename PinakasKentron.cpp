/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PinakasKentron.cpp
 * Author: nikolaus
 * 
 * Created on November 14, 2018, 9:37 PM
 */

#include "PinakasKentron.h"

PinakasKentron::PinakasKentron(int n) : n(n) {
     deiktis = new Dianisma*[n];
}

PinakasKentron::~PinakasKentron() {
    delete [] deiktis;
}


Dianisma * PinakasKentron::getDianisma(unsigned int i) {
    //epistrefei to dianisma api ti thesi i tou pinaka dianismaton
    return deiktis[i];
}

Dianisma * PinakasKentron::getAndCheckDianisma(unsigned int i) {
    //epistrefei to dianisma elegxontas oti eimaste entos orion
    if (i < n) {
        return deiktis[i];
    } else {
        return 0;
    }
}

unsigned int PinakasKentron::getN() {
    // epistrefei to plithos grammon
    return n;
}
