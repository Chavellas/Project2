/*
Chavellas Christos
AM: 1115201300196
 */

#include "PinakaPinakon.h"

PinakaPinakon::PinakaPinakon(unsigned int L, unsigned int T, unsigned int k, unsigned int d, AlgorithmosEktelesis ae) : L(L) {
    pinakes = new Pinakas*[L];
    for (unsigned int i = 0; i < L; i++) {
        pinakes[i] = new Pinakas(T, k, d, ae);
    }
}

PinakaPinakon::~PinakaPinakon() {
    for (unsigned int i = 0; i < L; i++) {
        delete pinakes[i];
    }
    delete [] pinakes;
}

void PinakaPinakon::eisagogi(Dianisma * x) {
	//eisagetai to dianisam sto pinaka
    for (unsigned int i = 0; i < L; i++) {
        pinakes[i]->eisagogi(x);
    }
}

unsigned int PinakaPinakon::getL() {
	//mas epistrefei to plithos ton pinakon katakermatismou
    return L;
}

vector<void*>* PinakaPinakon::anazitisi(PinakasDianismaton * pinakasDianysmaton, Dianisma * erotima, AlgorithmosEktelesis ae) {
	//anazitisi tou kontinoterou dianismatos erotimatos 
    vector<void*> * apotelesmata = new vector<void*>();

    Dianisma * geitonas = 0;
    double * apostasi = new double();

    for (unsigned int i = 0; i < L; i++) {
        vector<void*> * apotelesmataEnosPinaka = pinakes[i]->anazitisi(pinakasDianysmaton, erotima);
        if (apotelesmataEnosPinaka != NULL) {
            if (apotelesmataEnosPinaka->at(0) != 0) {
                double tempapostasi = *((double*) apotelesmataEnosPinaka->at(1));
                if (geitonas == 0 || tempapostasi < *apostasi) {
                    geitonas = (Dianisma*) apotelesmataEnosPinaka->at(0);
                    *apostasi = *((double*) apotelesmataEnosPinaka->at(1));
                }
                delete (double*) (apotelesmataEnosPinaka->at(1));
            }
            delete apotelesmataEnosPinaka;
        }
    }
    apotelesmata->push_back(geitonas);
    apotelesmata->push_back(apostasi);
    return apotelesmata;
}

vector<string> * PinakaPinakon::anazitisiSeAktina(PinakasDianismaton * pinakasDianysmaton, Dianisma * erotima, AlgorithmosEktelesis ae, double aktina) {
	//anazitisi tou dianismatos se aktina R
    vector<string> * apotelesmata = new vector<string>();
    for (unsigned int i = 0; i < L; i++) {
        pinakes[i]->anazitisiSeAktina(pinakasDianysmaton, erotima, aktina, apotelesmata);
    }
    return apotelesmata;
}
vector<int> * PinakaPinakon::anazitisiOffsetsSeAktina(PinakasDianismaton * pinakasDianysmaton, Dianisma * erotima, AlgorithmosEktelesis ae, double aktina) {
	//anazitisi tou dianismatos se aktina R
    vector<int> * apotelesmata = new vector<int>();
    for (unsigned int i = 0; i < L; i++) {
        pinakes[i]->anazitisiOffsetsSeAktina(pinakasDianysmaton, erotima, aktina, apotelesmata);
    }
    return apotelesmata;
}
