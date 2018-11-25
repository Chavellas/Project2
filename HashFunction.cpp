/*
Chavellas Christos
AM: 1115201300196
 */

#include <cstdlib>
#include <iostream>
#include <cmath>

#include "HashFunction.h"
#include "Sinartiseis.h"
#include "Randoms.h"

using namespace std;

HashFunction::HashFunction(AlgorithmosEktelesis ae, unsigned int k, unsigned int d) : ae(ae), k(k) {
    if (ae == Euclidean) {
        v = new Dianisma[k]; // k dianysmata me diastasi d
        t = new float[k];
        r = new float[k];

        for (unsigned int i = 0; i < k; i++) {
            r[i] = getRandomInt(); // random int (uniform distribution)
            t[i] = getRandomReal(4); // random real (uniform distrubution in [0,W)

            for (unsigned int j = 0; j < d; j++) {
                float q = getRandomNormalValue();
                v[i].SetAndCheckDedomena(j, q);
            }
        }
    }
    if (ae == Cosine) {
        cr = new Dianisma[k]; // k dianysmata me diastasi d

        for (unsigned int i = 0; i < k; i++) {
            for (unsigned int j = 0; j < d; j++) {
                float q = getRandomNormalValue();
                cr[i].SetAndCheckDedomena(j, q);
            }
        }
    }
}

HashFunction::~HashFunction() {
    if (ae == Euclidean) {
        delete [] v;
        delete [] t;
        delete [] r;
    }

    if (ae == Cosine) {
        delete [] cr;
    }
}

unsigned int HashFunction::ypologismosThesis(Dianisma * x) {
    Sinartiseis sin;
    unsigned long int M = (unsigned long int) (pow(2, 32) - 5);

    if (ae == Euclidean) {
        unsigned long int thesi = 0;

        for (unsigned int i = 0; i < k; i++) {
            thesi = thesi + ((long int) (sin.modulo((long int) ((r[i] * sin.pollaplasiasmos(x, &v[i]) + t[i]) / 4), M)));
        }

        thesi = sin.modulo(thesi, M);

        return (unsigned int) thesi;
    }

    if (ae == Cosine || ae == HyperCubeEuclidean || ae == HyperCubeCosine) {
        unsigned int thesi = 0;

        for (unsigned int i = 0; i < k; i++) {
            double hi = (sin.pollaplasiasmos(x, &cr[i]));
            if (hi >= 0) {
                hi = 1;
            } else {
                hi = 0;
            }

            thesi = thesi + (unsigned int) (hi * pow(2, i));
        }

        return thesi;
    }

    cout << "ae corrupted :( \n";
    exit(0);
}
