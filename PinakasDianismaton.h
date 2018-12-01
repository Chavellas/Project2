/*
Chavellas Christos
AM: 1115201300196
 */

#ifndef PINAKASDIANISMATON_H
#define PINAKASDIANISMATON_H

#include <fstream>

#include "Dianisma.h"

using namespace std;

class PinakaPinakon;

class PinakasDianismaton {
public:
    PinakasDianismaton(unsigned int n);
    virtual ~PinakasDianismaton();
    unsigned int eisagogiDedomenon(ifstream & file);
    unsigned int anazitisiDedomenon(PinakaPinakon * pinakasPinakon, ifstream & file, ostream & FileOutput, AlgorithmosEktelesis ae, double aktina);
    Dianisma * getDianisma(unsigned int i);
    Dianisma * getAndCheckDianisma(unsigned int i);
    unsigned int getN();
    
    
private:
    vector<string> * evresiPlisiesterouGeitonaProseggistikaSeAktina(PinakaPinakon * pp, Dianisma * dianysma, AlgorithmosEktelesis ae, double aktina);
    vector<void*> *  evresiPlisiesterouGeitona(Dianisma * dianysma, AlgorithmosEktelesis ae);
    vector<void*> *  evresiPlisiesterouGeitonaProseggistika(PinakaPinakon * pp, Dianisma * dianysma, AlgorithmosEktelesis ae);
    Dianisma * deiktis;
    unsigned int n;
};

#endif
