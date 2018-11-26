/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Clustering.cpp
 * Author: nikolaus
 * 
 * Created on November 14, 2018, 9:40 PM
 */

#include "Clustering.h"
#include "Randoms.h"
#include "Sinartiseis.h"
#include <map>
#include <set>
#include <iterator>

using namespace std;

Clustering::Clustering() {
}

Clustering::~Clustering() {
}

PinakasKentron * Clustering::random(PinakasDianismaton * pd, int plithos_clusters) {
    PinakasKentron * kentra = new PinakasKentron(plithos_clusters);

    for (int i = 0; i < plithos_clusters; i++) {
        kentra->setDianisma(i, pd->getDianisma(getRandomInt(0, pd->getN())));
    }

    return kentra;
}

PinakasKentron * Clustering::kmeanspp(PinakasDianismaton * pd, int plithos_clusters, AlgorithmosEktelesis ae) {
    PinakasKentron * kentra = new PinakasKentron(plithos_clusters);

    Sinartiseis sinartiseis;

    set<unsigned int> selectedOffsets;
    
    for (unsigned int i = 0; i < (unsigned) plithos_clusters; i++) {
        if (i == 0) {
            int roll = getRandomInt(0, pd->getN());
            kentra->setDianisma(i, pd->getDianisma(roll));
            selectedOffsets.insert(roll);
        } else {
            map<unsigned int, double> distanceMap;

            double max = 0;
            // build distance map
            for (unsigned int j = 0; j < pd->getN(); j++) {
                if (selectedOffsets.find(j) == selectedOffsets.end()) {
                    for (set<unsigned int>::iterator p = selectedOffsets.begin(); p != selectedOffsets.end(); p++) {
                        Dianisma * apo = pd->getDianisma(j);
                        Dianisma * mexri = pd->getDianisma(*p);
                        double temp = sinartiseis.ypologismosApostasis(apo, mexri, ae);

                        if (distanceMap.find(j) == distanceMap.end()) {
                            distanceMap[j] = temp;

                            if (temp > max) {
                                max = temp;
                            }
                        } else {
                            if (temp < distanceMap[j]) {
                                distanceMap[j] = temp;

                                if (temp > max) {
                                    max = temp;
                                }
                            }
                        }
                    }
                }
            }

            for (map<unsigned int, double>::iterator q = distanceMap.begin(); q != distanceMap.end(); ++q) {
                distanceMap[q->first] = distanceMap[q->first] / max;
                distanceMap[q->first] = distanceMap[q->first] * distanceMap[q->first];
            }

            double ** pr = new double*[2];

            pr[0] = new double[distanceMap.size()];
            pr[1] = new double[distanceMap.size()];

            int c = 0;
            max = 0;
            for (map<unsigned int, double>::iterator q = distanceMap.begin(); q != distanceMap.end(); ++q) {
                pr[0][c] = q->first;
                if (c - 1 >= 0) {
                    pr[1][c] = q->second + pr[1][c - 1];
                } else {
                    pr[1][c] = q->second;
                }
                if (pr[1][c] > max) {
                    max = pr[1][c];
                }
                c++;
            }

            double roll = getRandomReal(max);

            unsigned int nextneighbour = 0;
            for (unsigned int i = 0; i < distanceMap.size(); i++) {
                if (roll < pr[1][i]) {
                    nextneighbour = pr[0][i];
                    break;
                }
            }

            kentra->setDianisma(i, pd->getDianisma(nextneighbour));
            selectedOffsets.insert(nextneighbour);

            delete [] pr[0];
            delete [] pr[1];
            delete [] pr;

        }
    }

    return kentra;
}

PinakasAnathesewn * Clustering::lloyd(PinakasDianismaton * pd, PinakasKentron *) {
    return 0;
}

PinakasAnathesewn * Clustering::lsh(PinakasDianismaton * pd, PinakasKentron *, PinakaPinakon * pinakasPinakon, int K, int L) {
    return 0;
}

PinakasKentron * Clustering::pam(PinakasDianismaton * pd, PinakasKentron *, PinakasAnathesewn *) {
    return 0;
}

PinakasKentron * Clustering::kmeans(PinakasDianismaton * pd, PinakasKentron *, PinakasAnathesewn *) {
    return 0;
}

