
#ifndef PINAKASKENTRON_H
#define PINAKASKENTRON_H

#include "Dianisma.h"


class PinakasKentron {
public:
    PinakasKentron(int n);
    virtual ~PinakasKentron();
    
    Dianisma * getDianisma(unsigned int i);
    Dianisma * getAndCheckDianisma(unsigned int i);
    unsigned int getN();
private:
    Dianisma ** deiktis;
    unsigned int n;
};

#endif /* PINAKASKENTRON_H */

