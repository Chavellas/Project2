/*
Chavellas Christos
AM: 1115201300196
 */

#ifndef EKTIPOSEIS_H
#define EKTIPOSEIS_H

#include "PinakasDianismaton.h"
#include "PinakasKentron.h"
#include "PinakasAnathesewn.h"


class Ektipotis {
public:
    void ektiposi(ostream & out, unsigned algorithmos_arxikopoiisis, unsigned algorithmos_anathesis, unsigned algorithmos_ananeosis,PinakasDianismaton * pd, PinakasKentron * kentra, PinakasAnathesewn * anatheseon, AlgorithmosEktelesis ae, double * sil, bool leptomereies);
    void ektiposi_ekfonisis(ostream & out, unsigned algorithmos_arxikopoiisis, unsigned algorithmos_anathesis, unsigned algorithmos_ananeosis,PinakasDianismaton * pd, PinakasKentron * kentra, PinakasAnathesewn * anatheseon, AlgorithmosEktelesis ae, double * sil, bool leptomereies, double diff);
};

#endif /* EKTIPOSEIS_H */

