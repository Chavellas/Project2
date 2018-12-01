/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ektiposeis.h
 * Author: nikolaus
 *
 * Created on November 21, 2018, 9:12 PM
 */

#ifndef EKTIPOSEIS_H
#define EKTIPOSEIS_H

#include "PinakasDianismaton.h"
#include "PinakasKentron.h"
#include "PinakasAnathesewn.h"


class Ektipotis {
public:
    void ektiposi(unsigned algorithmos_arxikopoiisis, unsigned algorithmos_anathesis, unsigned algorithmos_ananeosis,PinakasDianismaton * pd, PinakasKentron * kentra, PinakasAnathesewn * anatheseon, AlgorithmosEktelesis ae, bool leptomereies);
};

#endif /* EKTIPOSEIS_H */

