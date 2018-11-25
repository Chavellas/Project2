/*
Chavellas Christos
AM: 1115201300196
 */

#ifndef DIANISMA_H
#define DIANISMA_H

#include <vector>
#include <string>

#include "Typoi.h"

using namespace std;

class Dianisma {
public:
    Dianisma();
    virtual ~Dianisma();

    TDD GetDedomena(unsigned int i) const;
    void SetAndCheckDedomena(unsigned int i, TDD value );
    void SetDedomena(unsigned int i, TDD value );
    unsigned int getID();
    void setID(unsigned int id);
    string GetTag();
    void SetTag(string tag);
    unsigned int mikos();
    bool printed;
private:
    unsigned int id;
    string tag;
    vector<TDD> dedomena;
};

#endif
