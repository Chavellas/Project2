/*
Chavellas Christos
AM: 1115201300196
 */

#include "Ektiposeis.h"
#include "PinakasDianismaton.h"
#include "PinakasAnathesewn.h"
#include "PinakasKentron.h"

#include <iostream>
#include <fstream>
#include <list>

using namespace std;

void Ektipotis::ektiposi(ostream & out, unsigned algorithmos_arxikopoiisis, unsigned algorithmos_anathesis, unsigned algorithmos_ananeosis, PinakasDianismaton * pd, PinakasKentron * kentra, PinakasAnathesewn * pinakasAnatheseon, AlgorithmosEktelesis ae, double * sil, bool leptomereies) {

    switch (algorithmos_arxikopoiisis) {
        case Random:
            out << "Arxikopoiisi: Random " << endl;
            break;
        case KmeansPP:
            out << "Arxikopoiisi: Kmeans++ " << endl;
            break;
    }

    switch (algorithmos_anathesis) {
        case LLOYD:
            out << "Anathesi    : LLOYD " << endl;
            break;
        case LSH:
            out << "Anathesi    : LSH " << endl;
            break;
    }

    switch (algorithmos_ananeosis) {
        case PAM:
            out << "Update      : PAM " << endl;
            break;
        case Kmeans:
            out << "Update      : Kmeans " << endl;
            break;
    }

    list<unsigned int> * deiktis = new list<unsigned int>[kentra->getN()];

    for (unsigned int j = 0; j < pd->getN(); j++) {
        //        Dianisma * apo = pd->getDianisma(j);
        deiktis[pinakasAnatheseon->getAnathesi(j)].push_back(j);
    }

    for (unsigned int i = 0; i < kentra->getN(); i++) {
        out << "Cluster-" << i << ":" << " { size: " << deiktis[i].size() << " " << kentra->getDianisma(i)->GetTag() << " } " << endl;
    }


    if (leptomereies) {
        for (unsigned int i = 0; i < kentra->getN(); i++) {
            out << "*** Cluster-" << i << ":" << " { size: " << deiktis[i].size() << " " << kentra->getDianisma(i)->GetTag() << " } " << endl;

            int counter = 0;
            for (list<unsigned int>::iterator p = deiktis[i].begin(); p != deiktis[i].end(); p++) {
                out << pd->getDianisma(*p)->getID() << "\t";
                counter++;
                if (counter == 5) {
                    counter = 0;
                    out << endl;
                }
            }
            out << endl;
        }
    }


    if (sil) {
        for (unsigned int i = 0; i < kentra->getN(); i++) {
            out << "Silhouette for cluster " << i << ":" << sil[i] << endl;
        }
        out << "Silhouette total: " << sil[kentra->getN()] << endl;
    }


    out << endl;

    delete [] deiktis;
}

void Ektipotis::ektiposi_ekfonisis(ostream & out, unsigned algorithmos_arxikopoiisis, unsigned algorithmos_anathesis, unsigned algorithmos_ananeosis, PinakasDianismaton * pd, PinakasKentron * kentra, PinakasAnathesewn * pinakasAnatheseon, AlgorithmosEktelesis ae, double * sil, bool leptomereies, double diff) {
    out << "I" << algorithmos_arxikopoiisis << "A" << algorithmos_anathesis << "U" << algorithmos_ananeosis << endl;

    if (ae == Euclidean) {
        out << "Metric: euclidean " << endl;
    } else {
        out << "Metric: cosine " << endl;
    }

    list<unsigned int> * deiktis = new list<unsigned int>[kentra->getN()];

    for (unsigned int j = 0; j < pd->getN(); j++) {
        deiktis[pinakasAnatheseon->getAnathesi(j)].push_back(j);
    }

    for (unsigned int i = 0; i < kentra->getN(); i++) {
        out << "Cluster-" << i << ":" << " { size: " << deiktis[i].size() << ", " << kentra->getDianisma(i)->GetTag() << " } " << endl;
    }

    if (sil) {
        out << "Silhouette: { ";

        for (unsigned int i = 0; i < kentra->getN(); i++) {
            out << sil[i] << "  ";
        }
        out << sil[kentra->getN()] << "}" << endl;
    }

    out << "Clustering time: " << diff << endl;

    if (leptomereies) {
        for (unsigned int i = 0; i < kentra->getN(); i++) {
            out << "*** Cluster-" << i << ":" << " { ";

            int counter = 0;
            for (list<unsigned int>::iterator p = deiktis[i].begin(); p != deiktis[i].end(); p++) {
                out << pd->getDianisma(*p)->getID() << "\t";
                counter++;
                if (counter == 5) {
                    counter = 0;
                    out << endl;
                }
            }
            out << "}" << endl;
        }
    }
}