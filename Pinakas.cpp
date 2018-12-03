/*
Chavellas Christos
AM: 1115201300196
 */
#include <iterator>
#include <iostream>

#include "Pinakas.h"
#include "Sinartiseis.h"

using namespace std;

Pinakas::Pinakas(unsigned int T, unsigned int k, unsigned int d, AlgorithmosEktelesis ae) : T(T), ae(ae), hashfunction(ae, k, d) {
    deiktis = new list<unsigned int>[T];
}

Pinakas::~Pinakas() {
    delete [] deiktis;
}

void Pinakas::eisagogi(Dianisma * x) {
	//ipologizetai i thesi tou dianismatos me vasi ti hashfucntion kai ginetao eisagogi
    unsigned int thesi = hashfunction.ypologismosThesis(x) % T;
    deiktis[thesi].push_back(x->getID());
}

vector<void*> * Pinakas::anazitisi(PinakasDianismaton * pinakasDianysmaton, Dianisma * erotima) {
	//ginetai anazitisi tou kontinoteroy dianismastos stis listes
    Sinartiseis si;
    vector<void*> * apotelesmata = new vector<void*>();
    unsigned int thesi = hashfunction.ypologismosThesis(erotima) % T;
    list<unsigned int> & lista = deiktis[thesi];
    Dianisma * geitonas = 0;
    double * apostasi = new double();

    for (list<unsigned int>::iterator p = lista.begin(); p != lista.end();p++) {
        unsigned int index = *p;
        Dianisma * d = pinakasDianysmaton->getDianisma(index);

        double trexousa = si.ypologismosApostasis(d, erotima, ae);

        if (geitonas == 0 || trexousa < *apostasi) {
            *apostasi = trexousa;
            geitonas = d;
        }
    }
    apotelesmata->push_back(geitonas);
    apotelesmata->push_back(apostasi);
    return apotelesmata;
}

void Pinakas::anazitisiSeAktina(PinakasDianismaton * pinakasDianysmaton, Dianisma * erotima, double aktina, vector<string> * apotelesmata) {
	//ginetai anazitisi dianismaton entos aktinas R
    Sinartiseis si;
    unsigned int thesi = hashfunction.ypologismosThesis(erotima) % T;
    list<unsigned int> & lista = deiktis[thesi];
    for (list<unsigned int>::iterator p = lista.begin(); p != lista.end();p++) {
        unsigned int index = *p;
        Dianisma * d = pinakasDianysmaton->getDianisma(index);
        if (d->printed == false ){
            double trexousa = si.ypologismosApostasis(d, erotima, ae);
            if (trexousa <= aktina) {
                d->printed = true;
                apotelesmata->push_back(d->GetTag());
            }
        }
    }
}

void Pinakas::anazitisiOffsetsSeAktina(PinakasDianismaton * pinakasDianysmaton, Dianisma * erotima, double aktina, vector<int> * apotelesmata) {
	//ginetai anazitisi dianismaton entos aktinas R
    Sinartiseis si;
    unsigned int thesi = hashfunction.ypologismosThesis(erotima) % T;
    list<unsigned int> & lista = deiktis[thesi];
    for (list<unsigned int>::iterator p = lista.begin(); p != lista.end();p++) {
        unsigned int index = *p;
        Dianisma * d = pinakasDianysmaton->getDianisma(index);
        if (d->printed == false ){
            double trexousa = si.ypologismosApostasis(d, erotima, ae);
            if (trexousa <= aktina) {
                d->printed = true;
                apotelesmata->push_back(index);
            }
        }
    }
}
