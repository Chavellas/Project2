/*
Chavellas Christos
AM: 1115201300196
 */

#include "PinakasKentron.h"

#include <ostream>
#include <iostream>

using namespace std;
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

void PinakasKentron::setDianisma(unsigned int i, Dianisma * d) {
    deiktis[i] = d;
}

void PinakasKentron::print(ostream & os) {
    for (unsigned int i=0;i<n;i++) {
        os << "Cluster " << i << " " << getDianisma(i)->GetTag() << endl;
    }
}
