/*
Chavellas Christos
AM: 1115201300196
 */

#ifndef PINAKASKENTRON_H
#define PINAKASKENTRON_H

#include "Dianisma.h"


class PinakasKentron {
public:
    PinakasKentron(int n);
    virtual ~PinakasKentron();
    
    void setDianisma(unsigned int i, Dianisma * );
    Dianisma * getDianisma(unsigned int i);
    Dianisma * getAndCheckDianisma(unsigned int i);
    unsigned int getN();
    
    void print(ostream & os);
private:
    Dianisma ** deiktis;
    unsigned int n;
};

#endif /* PINAKASKENTRON_H */

