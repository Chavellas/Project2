/*
Chavellas Christos
AM: 1115201300196
 */

#include "Dianisma.h"

Dianisma::Dianisma() {
    //arxikopoiisi dedomenon
    id = 0;
    printed = false;
}

Dianisma::~Dianisma() {
}

unsigned int Dianisma::getID() {
    //epistrefei to id toy dianismatos
    return id;
}

void Dianisma::setID(unsigned int id) {
    //ekxorei timi sto id tou dianismatos
    this->id = id;
}

TDD Dianisma::GetDedomena(unsigned int i) const {
    //epistrefonati ta dedoemna tou dianismatos ousiastika oi sintetagmenes tou
    return dedomena[i];
}

void Dianisma::SetDedomena(unsigned int i, TDD value) {
    //ekxorei sto dianisma oi sintetagmenes
    dedomena[i] = value;
}

void Dianisma::SetAndCheckDedomena(unsigned int i, TDD value) {
    //elegxei an eimaste enots orion tou pinaka gia na ginei resize tou pinaka kai na ekxorithoun sinettagmenes
    if (i >= dedomena.size()) {
        dedomena.resize(i + 1);
    }
    SetDedomena(i, value);
}

unsigned int Dianisma::mikos() {
  //epistrefei to mikos dou dianismatos
    return dedomena.size();
}

string Dianisma::GetTag() {
    //epistrefei to id tou dianismatos query_id#
    return tag;
}

void Dianisma::SetTag(string tag) {
    //kataxorei query_id#
    this->tag = tag;
}
