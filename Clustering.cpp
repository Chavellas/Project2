/*
Chavellas Christos
AM: 1115201300196
 */

#include "Clustering.h"
#include "Randoms.h"
#include "Sinartiseis.h"
#include <map>
#include <set>
#include <iterator>
#include <list>
#include <cfloat>

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

PinakasAnathesewn * Clustering::lloyd(PinakasDianismaton * pd, PinakasKentron * kentra, AlgorithmosEktelesis ae) {
    PinakasAnathesewn * anatheseis = new PinakasAnathesewn(pd->getN());

    map<unsigned int, double> distanceMap;
    map<unsigned int, double> secondDistanceMap;

    Sinartiseis sinartiseis;


    for (unsigned int j = 0; j < pd->getN(); j++) {
        Dianisma * apo = pd->getDianisma(j);

        for (unsigned int i = 0; i < kentra->getN(); i++) {
            Dianisma * mexri = kentra->getDianisma(i);

            double temp = sinartiseis.ypologismosApostasis(apo, mexri, ae);

            if (distanceMap.find(j) == distanceMap.end()) {
                distanceMap[j] = temp;
                anatheseis->setAnathesi(j, i);
            } else {
                if (temp < distanceMap[j]) {
                    secondDistanceMap[j] = distanceMap[j];
                    anatheseis->setEfedrikiAnathesi(j, anatheseis->getAnathesi(j));

                    distanceMap[j] = temp;
                    anatheseis->setAnathesi(j, i);
                } else if (secondDistanceMap.find(j) == secondDistanceMap.end()) {
                    secondDistanceMap[j] = temp;
                    anatheseis->setEfedrikiAnathesi(j, i);
                } else if (temp < secondDistanceMap[j]) {
                    secondDistanceMap[j] = temp;
                    anatheseis->setEfedrikiAnathesi(j, i);
                }
            }
        }
    }

    return anatheseis;
}

PinakasAnathesewn * Clustering::lsh(PinakasDianismaton * pd, PinakasKentron * kentra, PinakaPinakon * pinakasPinakon, int K, int L, AlgorithmosEktelesis ae) {
    PinakasAnathesewn * anatheseis = new PinakasAnathesewn(pd->getN());

    double mindist = DBL_MAX;

    Sinartiseis sinartiseis;


    for (unsigned int i = 0; i < kentra->getN(); i++) { // gia kathe cluster. ..
        for (unsigned int j = i + 1; j < kentra->getN(); j++) { // gia kathe cluster. ..
            Dianisma * apo = kentra->getDianisma(i);
            Dianisma * mexri = kentra->getDianisma(j);

            if (i == j) {
                continue;
            }

            double temp = sinartiseis.ypologismosApostasis(apo, mexri, ae);

            if (temp < mindist) {
                mindist = temp;
            }
        }
    }

    mindist *= 0.5;
    double aktina = mindist;
    unsigned int total = 0;
    unsigned int countdown = 20;

    while (total < pd->getN() && --countdown > 0) {
        set<int> * trees = new set<int>[pd->getN()]();

        for (unsigned int i = 0; i < kentra->getN(); i++) { // gia kathe cluster. ..
            Dianisma * query = kentra->getDianisma(i);

            vector<int> * apotelesmata = sinartiseis.proseggistikiAnazitisiOffsetsSeAktina(pinakasPinakon, pd, query, ae, aktina);

            for (unsigned int i = 0; i < apotelesmata->size(); i++) {
                int offset = apotelesmata->at(i);
                trees[offset].insert(i);
            }

            delete apotelesmata;
        }

        for (unsigned int i = 0; i < pd->getN(); i++) {
            if (trees[i].size() == 0) {
                // do nothing
            } else if (trees[i].size() == 1) {
                if (anatheseis->getAnathesi(i) == -1) {
                    anatheseis->setAnathesi(i, *(trees[i].begin()));
                    total++;
                }
            } else {
                if (anatheseis->getAnathesi(i) == -1) {
                    PinakasKentron *prosorinakentra = new PinakasKentron(trees[i].size());

                    int j = 0;
                    for (set<int>::iterator p = trees[i].begin(); p != trees[i].end(); ++p) {
                        prosorinakentra->setDianisma(j++, kentra->getDianisma(*p));
                    }

                    lloydOnlyOne(i, pd, prosorinakentra, ae, anatheseis);
                    total++;

                    delete prosorinakentra;
                }
            }
        }

        delete [] trees;

        aktina = 2 * aktina;
    }


    for (int i = 0; i < anatheseis->getN(); i++) {
        if (anatheseis->getAnathesi(i) == -1 || anatheseis->getEfedrikiAnathesi(i) == -1) {
            lloydOnlyOne(i, pd, kentra, ae, anatheseis);
        }
    }

    return anatheseis;
}

PinakasKentron * Clustering::pam(PinakasDianismaton * pd, PinakasKentron * kentra, PinakasAnathesewn * pinakasAnatheseon, AlgorithmosEktelesis ae) {
    list<unsigned int> * deiktis = new list<unsigned int>[kentra->getN()];
    PinakasKentron * neakentra = new PinakasKentron(kentra->getN());

    Sinartiseis sinartiseis;

    // moirazw ta simeia se listes, mia gia kathe kentro
    for (unsigned int j = 0; j < pd->getN(); j++) {
        deiktis[pinakasAnatheseon->getAnathesi(j)].push_back(j);
    }

    double djtotal = 0;

    for (unsigned int c = 0; c < neakentra->getN(); c++) { // gia kathe cluster. ..
        if (deiktis[c].size() > 1) {
            // bres medoid:
            double mindistance = DBL_MAX;
            unsigned int medoid;

            for (list<unsigned int>::iterator p1 = deiktis[c].begin(); p1 != deiktis[c].end(); p1++) {
                double sumdist = 0;
                for (list<unsigned int>::iterator p2 = deiktis[c].begin(); p2 != deiktis[c].end(); p2++) {
                    if (*p1 != *p2) {
                        Dianisma * apo = pd->getDianisma(c);
                        Dianisma * mexri = pd->getDianisma(c);

                        double temp = sinartiseis.ypologismosApostasis(apo, mexri, ae);

                        sumdist = sumdist + temp;
                    }
                }

                sumdist = sumdist / (deiktis[c].size() - 1);

                if (sumdist < mindistance) {
                    mindistance = sumdist;
                    medoid = *p1;
                }
            }

            // calculate DJ
            double dj = 0;

            for (unsigned int j = 0; j < pd->getN(); j++) {
                if (pinakasAnatheseon->getAnathesi(j) == (int) c) { // internal
                    Dianisma * apo = pd->getDianisma(j);
                    Dianisma * mexri = pd->getDianisma(medoid);
                    double distance_i_t = sinartiseis.ypologismosApostasis(apo, mexri, ae);

                    mexri = kentra->getAndCheckDianisma(pinakasAnatheseon->getEfedrikiAnathesi(j));
                    double distance_i_cc = sinartiseis.ypologismosApostasis(apo, mexri, ae);

                    mexri = kentra->getAndCheckDianisma(c);
                    double distance_i_m = sinartiseis.ypologismosApostasis(apo, mexri, ae);

                    if (distance_i_t <= distance_i_cc) {
                        dj = dj + (distance_i_t - distance_i_m);
                    } else {
                        dj = dj + (distance_i_cc - distance_i_m);
                    }
                } else { // external
                    Dianisma * apo = pd->getDianisma(j);
                    Dianisma * mexri = pd->getDianisma(medoid);
                    double distance_i_t = sinartiseis.ypologismosApostasis(apo, mexri, ae);

                    mexri = kentra->getAndCheckDianisma(pinakasAnatheseon->getAnathesi(j));
                    double distance_i_c = sinartiseis.ypologismosApostasis(apo, mexri, ae);

                    if (distance_i_t >= distance_i_c) {
                        dj = dj + 0;
                    } else {
                        dj = dj + (distance_i_t - distance_i_c);
                    }
                }
            }

            if (dj < 0) {
                djtotal = djtotal + dj;
                neakentra->setDianisma(c, pd->getDianisma(medoid));
            }
        } else {
            neakentra->setDianisma(c, kentra->getDianisma(c));
        }
    }

    delete [] deiktis;


    if (djtotal < 0) {
        return neakentra;
    } else {
        return kentra;
    }
}

PinakasKentron * Clustering::kmeans(PinakasDianismaton * pd, PinakasKentron *kentra, PinakasAnathesewn * pinakasAnatheseon, AlgorithmosEktelesis ae) {
    list<unsigned int> * deiktis = new list<unsigned int>[kentra->getN()];
    int diastaseis = pd->getDianisma(0)->mikos();
    PinakasKentron * neakentra = new PinakasKentron(kentra->getN());

    // moirazw ta simeia se listes, mia gia kathe kentro
    for (unsigned int j = 0; j < pd->getN(); j++) {
        deiktis[pinakasAnatheseon->getAnathesi(j)].push_back(j);
    }


    for (unsigned int i = 0; i < neakentra->getN(); i++) { // gia kathe cluster. ..
        // ftiaxe ena neo kentro
        Dianisma * neokentro = new Dianisma();

        // kai gemise tis sintetagmenes me midenika
        for (int j = 0; j < diastaseis; j++) {
            neokentro->SetAndCheckDedomena(j, 0);
        }

        int counter = 0;

        // gia kathe simeio tou cluster
        for (list<unsigned int>::iterator p = deiktis[i].begin(); p != deiktis[i].end(); p++) {

            // gia kathe sintetagmeni
            for (int j = 0; j < diastaseis; j++) {
                // prosthese tin stin antistoixi sintetagmeni tou cluster
                neokentro->SetDedomena(j, (neokentro->GetDedomena(j) + pd->getDianisma(*p)->GetDedomena(j)));
            }

            counter++;
        }

        // bres to meso oro gia kathe sintetagmeni
        for (int j = 0; j < diastaseis; j++) {
            neokentro->SetDedomena(j, neokentro->GetDedomena(i) / counter);
        }

        neakentra->setDianisma(i, neokentro);
    }

    delete [] deiktis;


    return neakentra;
}

double Clustering::elegxosApostasisKentron(PinakasKentron * kentra, PinakasKentron * neakentra, AlgorithmosEktelesis ae) {
    double maxdistance = 0.0;

    Sinartiseis sinartiseis;

    for (unsigned int i = 0; i < neakentra->getN(); i++) { // gia kathe cluster. ..
        Dianisma * apo = kentra->getDianisma(i);
        Dianisma * mexri = neakentra->getDianisma(i);

        double temp = sinartiseis.ypologismosApostasis(apo, mexri, ae);

        if (temp > maxdistance) {
            maxdistance = temp;
        }
    }
    return maxdistance;
}

double * Clustering::silouette(PinakasDianismaton * pd, PinakasKentron *kentra, PinakasAnathesewn * pinakasAnatheseon, AlgorithmosEktelesis ae) {
    double * results = new double[kentra->getN() + 1];
    double stotal = 0;

    list<unsigned int> * deiktis = new list<unsigned int>[kentra->getN()];

    for (unsigned int j = 0; j < pd->getN(); j++) {
        deiktis[pinakasAnatheseon->getAnathesi(j)].push_back(j);
    }

    for (unsigned int cluster_inner = 0; cluster_inner < kentra->getN(); cluster_inner++) {
        double scluster = 0;

        for (list<unsigned int>::iterator p1 = deiktis[cluster_inner].begin(); p1 != deiktis[cluster_inner].end(); p1++) {
            int i = *p1;

            int cluster_outer = pinakasAnatheseon->getEfedrikiAnathesi(i);
            scluster = scluster + silouette(i, cluster_inner, cluster_outer, pd, kentra, pinakasAnatheseon, deiktis, ae);
        }
        scluster = scluster / deiktis[cluster_inner].size();

        stotal = stotal + scluster;

        results[cluster_inner] = scluster;
    }

    stotal = stotal / kentra->getN();


    delete [] deiktis;

    results[kentra->getN()] = stotal;

    return results;
}

double Clustering::silouette(int i, int cluster_inner, int cluster_outer, PinakasDianismaton * pd, PinakasKentron *kentra, PinakasAnathesewn * pinakasAnatheseon, list<unsigned int> * deiktis, AlgorithmosEktelesis ae) {
    double sil = 0;

    double average_inner = 0;
    double average_outer = 0;

    int counter = 0;

    Sinartiseis sinartiseis;

    Dianisma * apo = pd->getDianisma(i);

    // gia kathe simeio tou cluster
    for (list<unsigned int>::iterator p = deiktis[cluster_inner].begin(); p != deiktis[cluster_inner].end(); p++) {
        Dianisma * mexri = pd->getDianisma(*p);

        average_inner = average_inner + sinartiseis.ypologismosApostasis(apo, mexri, ae);

        counter++;
    }
    average_inner = average_inner / counter;

    counter = 0;

    for (list<unsigned int>::iterator p = deiktis[cluster_outer].begin(); p != deiktis[cluster_outer].end(); p++) {
        Dianisma * mexri = pd->getDianisma(*p);

        average_outer = average_outer + sinartiseis.ypologismosApostasis(apo, mexri, ae);

        counter++;
    }
    average_outer = average_outer / counter;

    sil = (average_outer - average_inner) / max(average_inner, average_outer);

    return sil;

}

void Clustering::lloydOnlyOne(int offset, PinakasDianismaton * pd, PinakasKentron *kentra, AlgorithmosEktelesis ae, PinakasAnathesewn * anatheseis) {
    map<unsigned int, double> distanceMap;
    map<unsigned int, double> secondDistanceMap;

    Sinartiseis sinartiseis;

    unsigned int j = offset;
    Dianisma * apo = pd->getDianisma(j);

    for (unsigned int i = 0; i < kentra->getN(); i++) {
        Dianisma * mexri = kentra->getDianisma(i);

        double temp = sinartiseis.ypologismosApostasis(apo, mexri, ae);

        if (distanceMap.find(j) == distanceMap.end()) {
            distanceMap[j] = temp;
            anatheseis->setAnathesi(j, i);
        } else {
            if (temp < distanceMap[j]) {
                secondDistanceMap[j] = distanceMap[j];
                anatheseis->setEfedrikiAnathesi(j, anatheseis->getAnathesi(j));

                distanceMap[j] = temp;
                anatheseis->setAnathesi(j, i);
            } else if (secondDistanceMap.find(j) == secondDistanceMap.end()) {
                secondDistanceMap[j] = temp;
                anatheseis->setEfedrikiAnathesi(j, i);
            } else if (temp < secondDistanceMap[j]) {
                secondDistanceMap[j] = temp;
                anatheseis->setEfedrikiAnathesi(j, i);
            }
        }
    }
}