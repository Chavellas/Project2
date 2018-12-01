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

    void setAnathesi(unsigned int i, unsigned cluster_id) ;
    int getAnathesi(unsigned int i) ;
    int getAndCheckAnathesi(unsigned int i);
    int getN();

     void setEfedrikiAnathesi(unsigned int i, unsigned cluster_id) ;
    int getEfedrikiAnathesi(unsigned int i) ;
    int getAndCheckEfedrikiAnathesi(unsigned int i);
    
private:
    int N;
    int * anatheseis;
    int * efedrikesanatheseis;
};

#endif /* PINAKASANATHESEWN_H */

