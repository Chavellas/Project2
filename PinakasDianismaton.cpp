/*
Chavellas Christos
AM: 1115201300196
 */
#include <iostream>
#include <vector>
#include <iostream>
#include <cfloat>
#include <cstdlib>

#include "PinakasDianismaton.h"
#include "Sinartiseis.h"

using namespace std;

PinakasDianismaton::PinakasDianismaton(unsigned int n) : n(n) {
  //arxikopoiisi dedomenon gia kathe dianisma
    deiktis = new Dianisma[n];
    for (unsigned int i = 0; i < n; i++) {
        deiktis[i].setID(i);
    }
}

Dianisma * PinakasDianismaton::getDianisma(unsigned int i) {
    //epistrefei to dianisma api ti thesi i tou pinaka dianismaton
    return &deiktis[i];
}

Dianisma * PinakasDianismaton::getAndCheckDianisma(unsigned int i) {
    //epistrefei to dianisma elegxontas oti eimaste entos orion
    if (i < n) {
        return &deiktis[i];
    } else {
        return 0;
    }
}

unsigned int PinakasDianismaton::getN() {
    // epistrefei to plithos grammon
    return n;
}

PinakasDianismaton::~PinakasDianismaton() {
    delete [] deiktis;
}

unsigned int PinakasDianismaton::eisagogiDedomenon(ifstream & file) {
    // se auti ti sinartisi eisagontai oi sintetagmenes ton dianismaton apo to arxeio eisodou sto pinaka dianismaton
    string line;
    Sinartiseis sin;
    unsigned int d = 0;
    int temp = 0;

    for (unsigned int i = 1; i <= n + temp; i++) {
        getline(file, line);
        if (line[0] != '@') {
            //        cout << line << endl;
            vector<string> words = sin.split(line, ',');
            if (d == 0) {
                d = words.size() - 1;
            }
            deiktis[i - 1 - temp].SetTag(words[0]);
            for (unsigned int j = 1; j < words.size() - 1; j++) {
                TDD number = (TDD) atof(words[j].c_str());
                deiktis[i - 1 - temp].SetAndCheckDedomena(j - 1, number);
            }
        } else {
            temp = 1;
        }
    }
    return d;
}

unsigned int PinakasDianismaton::anazitisiDedomenon(PinakaPinakon * pinakasPinakon, ifstream & file, ostream & FileOutput, AlgorithmosEktelesis ae, double aktina) {
    // se  auti ti sinartisi ginetai anazitis dianismatos me vasi to dianisma anazitisis  apo to queryfile me vasi panta ton algorithmo ektelesis
    string line;
    Sinartiseis sin;

    double max_klasma_dlsh_dtrue = 0;
    double min_klasma_dlsh_dtrue = DBL_MAX;
    double mesi_timi_tlsh = 0;
    int qn = 0;
    while (true) {
        getline(file, line);
        //        cout << line << endl;
        vector<string> words = sin.split(line, ',');
        if (words.size() == 0) {
            break;
        }
        qn++;
        Dianisma * query = new Dianisma();
        query->SetTag(words[0]);
        for (unsigned int j = 1; j < words.size() - 1; j++) {
            TDD number = (TDD) atof(words[j].c_str());
            query->SetAndCheckDedomena(j - 1, number);
        }
        FileOutput << " .............................................. " << endl;
        FileOutput << "Query: " << query->GetTag() << endl;

        // anazitisi tou evresiPlisiesterouGeitona me nasi ton algorithmo LSH entis aktinas R
        if (aktina > 0) {
            Sinartiseis si;
            si.katharismosFlags(this);
            FileOutput << "R - nearest neighbours: " << endl;
            vector<string> * apotelesmata = evresiPlisiesterouGeitonaProseggistikaSeAktina(pinakasPinakon, query, ae, aktina);
            for (unsigned int i=0;i<apotelesmata->size();i++) {
                FileOutput << "\t" << apotelesmata->at(i) << endl;
            }
            delete apotelesmata;
        }

        // anazitisi tou evresiPlisiesterouGeitona me nasi ton algorithmo LSH
        vector<void*> * lshApotelesmata = evresiPlisiesterouGeitonaProseggistika(pinakasPinakon, query, ae);

        // anazitisi tou pragmatikou evresiPlisiesterouGeitona
        vector<void*> * trueApotelesmata = evresiPlisiesterouGeitona(query, ae);

        // ektiponntai ta apotelemsata me vasi to format pou dothike
        FileOutput << "True nearest neighbour: " << ((Dianisma*) trueApotelesmata->at(0))->GetTag() << " - " << ((Dianisma*) trueApotelesmata->at(0))->getID() << endl;

        if (lshApotelesmata->at(0) != NULL) {
            FileOutput << "LSH nearest neighbour: " << ((Dianisma*) lshApotelesmata->at(0))->GetTag() << endl;
        } else {
            FileOutput << "LSH nearest neighbour: " << "not found" << endl;
        }

        FileOutput << "dTrue nearest neighbour: " << *((double*) trueApotelesmata->at(1)) << endl;
        if (lshApotelesmata->at(0) != NULL) {
            FileOutput << "dLSH nearest neighbour: " << *((double*) lshApotelesmata->at(1)) << endl;
        }

        FileOutput << "tTrue nearest neighbour: " << *((double*) trueApotelesmata->at(2)) << " nanosec" << endl;
        FileOutput << "tLSH nearest neighbour: " << *((double*) lshApotelesmata->at(2)) << " nanosec" << endl;

        if (lshApotelesmata->at(0) != NULL) {
            double dlsh = *((double*) lshApotelesmata->at(1));
            double dtrue = *((double*) trueApotelesmata->at(1));
            double klasma = dlsh / dtrue;
            max_klasma_dlsh_dtrue = max(max_klasma_dlsh_dtrue, klasma);
            min_klasma_dlsh_dtrue = min(min_klasma_dlsh_dtrue, klasma);
        }

        double tlsh = *((double*) lshApotelesmata->at(2));
        mesi_timi_tlsh = mesi_timi_tlsh + tlsh;

        delete (double*) (trueApotelesmata->at(1));
        delete (double*) (trueApotelesmata->at(2));

        delete (double*) (lshApotelesmata->at(1));
        delete (double*) (lshApotelesmata->at(2));

        delete trueApotelesmata;
        delete query;
    }

    FileOutput << "################################################" << endl;

    mesi_timi_tlsh = mesi_timi_tlsh / qn;

    FileOutput << "max klasma_dlsh_dtrue: " << max_klasma_dlsh_dtrue << endl;
    FileOutput << "min klasma_dlsh_dtrue: " << min_klasma_dlsh_dtrue << endl;
    FileOutput << "mesi_timi_tlsh   : " << mesi_timi_tlsh << " nanosec" << endl;

    return 0;
}

vector<void*> * PinakasDianismaton::evresiPlisiesterouGeitona(Dianisma * erotima, AlgorithmosEktelesis ae) {
    Sinartiseis si;
    vector<void*> * apotelesmata = si.exantlitikiAnazitisi(this, erotima, ae);
    return apotelesmata;
}

vector<void*> * PinakasDianismaton::evresiPlisiesterouGeitonaProseggistika(PinakaPinakon * pp, Dianisma * erotima, AlgorithmosEktelesis ae) {
    Sinartiseis si;
    vector<void*> * apotelesmata = si.proseggistikiAnazitisi(pp, this, erotima, ae);
    return apotelesmata;
}

vector<string> * PinakasDianismaton::evresiPlisiesterouGeitonaProseggistikaSeAktina(PinakaPinakon * pp, Dianisma * erotima, AlgorithmosEktelesis ae, double aktina) {
    Sinartiseis si;
    return si.proseggistikiAnazitisiSeAktina(pp, this, erotima, ae, aktina);
}
