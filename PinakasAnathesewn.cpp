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
    efedrikesanatheseis = new int[N];

    for (int i = 0; i < N; i++) {
        anatheseis[i] = -1;
        efedrikesanatheseis[i] = -1;
    }
}

PinakasAnathesewn::~PinakasAnathesewn() {
    delete [] anatheseis;
    delete [] efedrikesanatheseis;
}

int PinakasAnathesewn::getAnathesi(unsigned int i) {
    return anatheseis[i];
}

void PinakasAnathesewn::setAnathesi(unsigned int i, unsigned cluster_id)  {
    anatheseis[i] = cluster_id;
}

int PinakasAnathesewn::getAndCheckAnathesi(unsigned int i) {
    if ((int) i < N) {
        return anatheseis[i];
    } else {
        return 0;
    }
}

int PinakasAnathesewn::getEfedrikiAnathesi(unsigned int i) {
    return efedrikesanatheseis[i];
}

void PinakasAnathesewn::setEfedrikiAnathesi(unsigned int i, unsigned cluster_id)  {
    efedrikesanatheseis[i] = cluster_id;
}

int PinakasAnathesewn::getAndCheckEfedrikiAnathesi(unsigned int i) {
    if ((int) i < N) {
        return efedrikesanatheseis[i];
    } else {
        return 0;
    }
}

int PinakasAnathesewn::getN() {
    return N;
}

