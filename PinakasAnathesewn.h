/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PinakasAnathesewn.h
 * Author: nikolaus
 *
 * Created on November 14, 2018, 9:43 PM
 */

#ifndef PINAKASANATHESEWN_H
#define PINAKASANATHESEWN_H

class PinakasAnathesewn {
public:
    PinakasAnathesewn(int N);
    virtual ~PinakasAnathesewn();

    int getAnathesi(unsigned int i) ;
    int getAndCheckAnathesi(unsigned int i);
    int getN();

private:
    int N;
    int * anatheseis;
};

#endif /* PINAKASANATHESEWN_H */

