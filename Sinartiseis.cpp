/*
Chavellas Christos
AM: 1115201300196
 */

#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>

#include "Sinartiseis.h"
#include "Dianisma.h"
#include "PinakaPinakon.h"

using namespace std;

double ** Sinartiseis::distanceMatrix;
unsigned int  Sinartiseis::distanceMatrixDimension;

Sinartiseis::Sinartiseis() {
}

Sinartiseis::~Sinartiseis() {
}

std::vector<std::string> Sinartiseis::split(const std::string& s, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

double Sinartiseis::pollaplasiasmos(Dianisma * left, Dianisma * right) {
    double v = 0;
    for (unsigned int i = 0; i < left->mikos(); i++) {
        v = v + left->GetDedomena(i) * right->GetDedomena(i);
    }
    return v;
}

long int Sinartiseis::modulo(long int N, long int M) {
    if (N > 0) {
        return N % M;
    } else {
        return N * (M - 1) % M;
    }
}

double Sinartiseis::ypologismosApostasisEuclidean(Dianisma * apo, Dianisma * mexri) {
    double apostasi = 0.0;

    for (unsigned i = 0; i < apo->mikos(); i++) {
        apostasi = apostasi + (apo->GetDedomena(i) - mexri->GetDedomena(i))*(apo->GetDedomena(i) - mexri->GetDedomena(i));
    }
    return sqrt(apostasi);
}

double Sinartiseis::ypologismosApostasisCosine(Dianisma * apo, Dianisma * mexri) {
    double esgin = 0.0;
    double m1 = 0.0, m2 = 0.0;
    for (unsigned i = 0; i < apo->mikos(); i++) {
        m1 = m1 + (apo->GetDedomena(i) * apo->GetDedomena(i));
        m2 = m2 + (mexri->GetDedomena(i) * mexri->GetDedomena(i));
        esgin = esgin + (apo->GetDedomena(i) * mexri->GetDedomena(i));
    }
    m1 = sqrt(m1);
    m2 = sqrt(m2);

    return 1 - esgin / (m1 * m2);
}

double Sinartiseis::ypologismosApostasis(Dianisma * apo, Dianisma * mexri, AlgorithmosEktelesis ae) {
    return ypologismosRizasApostasis(apo, mexri, ae);
    //    switch (ae) {
    //        case Euclidean:
    //        case HyperCubeEuclidean:
    //            return ypologismosApostasisEuclidean(apo, mexri);
    //        case HyperCubeCosine:
    //        case Cosine:
    //            return ypologismosApostasisCosine(apo, mexri);
    //        default:
    //            return ypologismosApostasisEuclidean(apo, mexri);
    //    }
}

double Sinartiseis::ypologismosRizasApostasisEuclidean(Dianisma * apo, Dianisma * mexri) {
    double apostasi = 0.0;

    for (unsigned i = 0; i < apo->mikos(); i++) {
        apostasi = apostasi + (apo->GetDedomena(i) - mexri->GetDedomena(i))*(apo->GetDedomena(i) - mexri->GetDedomena(i));
    }
    return apostasi;
}

double Sinartiseis::ypologismosRizasApostasisCosine(Dianisma * apo, Dianisma * mexri) {
    double esgin = 0.0;
    double m1 = 0.0, m2 = 0.0;
    for (unsigned i = 0; i < apo->mikos(); i++) {
        m1 = m1 + (apo->GetDedomena(i) * apo->GetDedomena(i));
        m2 = m2 + (mexri->GetDedomena(i) * mexri->GetDedomena(i));
        esgin = esgin + (apo->GetDedomena(i) * mexri->GetDedomena(i));
    }
    return 1 - esgin / (m1 * m2);
}

double Sinartiseis::ypologismosRizasApostasis(Dianisma * apo, Dianisma * mexri, AlgorithmosEktelesis ae) {
    if (apo->getID() == UINT32_MAX || mexri->getID() == UINT32_MAX) {
        switch (ae) {
            case Euclidean:
            case HyperCubeEuclidean:
                return ypologismosRizasApostasisEuclidean(apo, mexri);
            case HyperCubeCosine:
            case Cosine:
                return ypologismosRizasApostasisCosine(apo, mexri);
            default:
                return ypologismosRizasApostasisEuclidean(apo, mexri);
        }
    } else {
        return distanceMatrix[apo->getID()][mexri->getID()];
    }
}

double Sinartiseis::ypologismosRizasApostasisAnalytika(Dianisma * apo, Dianisma * mexri, AlgorithmosEktelesis ae) {
    switch (ae) {
        case Euclidean:
        case HyperCubeEuclidean:
            return ypologismosRizasApostasisEuclidean(apo, mexri);
        case HyperCubeCosine:
        case Cosine:
            return ypologismosRizasApostasisCosine(apo, mexri);
        default:
            return ypologismosRizasApostasisEuclidean(apo, mexri);
    }
}

vector<void*> * Sinartiseis::exantlitikiAnazitisi(PinakasDianismaton * pinakasDianysmaton, Dianisma * erotima, AlgorithmosEktelesis ae) {
    Dianisma * geitonas = 0;
    double * apostasi = new double();
    double * xrono = new double();

    vector<void*> * apotelesmata = new vector<void*>();

    timespec ts1, ts2;

    clock_gettime(CLOCK_REALTIME, &ts1);

    for (unsigned i = 0; i < pinakasDianysmaton->getN(); i++) {
        double trexousa = ypologismosApostasis(pinakasDianysmaton->getDianisma(i), erotima, ae);

        if (geitonas == 0 || trexousa < *apostasi) {
            *apostasi = trexousa;
            geitonas = pinakasDianysmaton->getDianisma(i);
        }
    }

    clock_gettime(CLOCK_REALTIME, &ts2);

    double dif = double( ts2.tv_nsec - ts1.tv_nsec); // nano
    *xrono = dif;
    apotelesmata->push_back(geitonas);
    apotelesmata->push_back(apostasi);
    apotelesmata->push_back(xrono);

    return apotelesmata;

}

vector<void*> * Sinartiseis::proseggistikiAnazitisi(PinakaPinakon * pinakasPinakon, PinakasDianismaton * pinakasDianysmaton, Dianisma * erotima, AlgorithmosEktelesis ae) {
    double * xrono = new double();
    timespec ts1, ts2;
    clock_gettime(CLOCK_REALTIME, &ts1);
    vector<void*> * apotelesmata = pinakasPinakon->anazitisi(pinakasDianysmaton, erotima, ae);
    clock_gettime(CLOCK_REALTIME, &ts2);
    double dif = double( ts2.tv_nsec - ts1.tv_nsec); // nano
    *xrono = dif;
    apotelesmata->push_back(xrono);

    return apotelesmata;
}

vector<string> * Sinartiseis::proseggistikiAnazitisiSeAktina(PinakaPinakon * pinakasPinakon, PinakasDianismaton * pinakasDianysmaton, Dianisma * erotima, AlgorithmosEktelesis ae, double aktina) {
    return pinakasPinakon->anazitisiSeAktina(pinakasDianysmaton, erotima, ae, aktina);
}

vector<int> * Sinartiseis::proseggistikiAnazitisiOffsetsSeAktina(PinakaPinakon * pinakasPinakon, PinakasDianismaton * pinakasDianysmaton, Dianisma * erotima, AlgorithmosEktelesis ae, double aktina) {
    return pinakasPinakon->anazitisiOffsetsSeAktina(pinakasDianysmaton, erotima, ae, aktina);
}

void Sinartiseis::katharismosFlags(PinakasDianismaton * pinakasDianysmaton) {
    for (unsigned i = 0; i < pinakasDianysmaton->getN(); i++) {
        pinakasDianysmaton->getDianisma(i)->printed = false;
    }
}

void Sinartiseis::calculateDistanceMatrix(PinakasDianismaton * pd, AlgorithmosEktelesis ae) {
    Sinartiseis s;

    cout << "Building distance matrix ... \n";
    Sinartiseis::distanceMatrixDimension = pd->getN();
    
    distanceMatrix = new double*[pd->getN()];
    for (unsigned int i = 0; i < pd->getN(); i++) {
        distanceMatrix[i] = new double[pd->getN()];
    }
    
    for (unsigned int i = 0; i < pd->getN(); i++) {
        for (unsigned int j = i; j < pd->getN(); j++) {
            if (i == j) {
                distanceMatrix[i][j] = 0;
            } else {
                double dist = s.ypologismosRizasApostasisAnalytika(pd->getDianisma(i), pd->getDianisma(j), ae);
                distanceMatrix[i][j] = dist;
                distanceMatrix[j][i] = dist;
            }
        }
    }
}

void Sinartiseis::cleanupDistanceMatrix() {
    cout << "destroying distance matrix ... \n";
    
    for (unsigned int i = 0; i < Sinartiseis::distanceMatrixDimension; i++) {
        delete [] distanceMatrix[i];
    }
    delete [] distanceMatrix;
}