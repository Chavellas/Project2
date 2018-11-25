/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PinakasAnathesewn.cpp
 * Author: nikolaus
 * 
 * Created on November 14, 2018, 9:43 PM
 */

#include "PinakasAnathesewn.h"

PinakasAnathesewn::PinakasAnathesewn(int N) : N(N) {
    anatheseis = new int[N];

    for (int i = 0; i < N; i++) {
        anatheseis[i] = -1;
    }
}

PinakasAnathesewn::~PinakasAnathesewn() {
    delete [] anatheseis;
}

int PinakasAnathesewn::getAnathesi(unsigned int i) {
    return anatheseis[i];
}

int PinakasAnathesewn::getAndCheckAnathesi(unsigned int i) {
    if ((int) i < N) {
        return anatheseis[i];
    } else {
        return 0;
    }
}

int PinakasAnathesewn::getN() {
    return N;
}
