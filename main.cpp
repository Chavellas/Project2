/*
Chavellas Christos
AM: 1115201300196
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <fstream>
#include <cmath>

#include "Typoi.h"
#include "PinakasDianismaton.h"
#include "PinakaPinakon.h"
#include "Dianisma.h"
#include "PinakasDianismaton.h"
#include "Clustering.h"
#include "Ektiposeis.h"
#include "cluster.h"

using namespace std;

int main(int argc, char** argv) {

    int m = argc; //plihos eisodou
    char* arxeio_eisodou;
    char* arxeio_exodou;
    char* arxeio_config;
    int h_functions; //k
    int pinakes_katakermatismou; //L
    AlgorithmosEktelesis algorithmos_ektelesis = Euclidean; //0:Euclidean 1:Cosine
    bool leptomeries = false;

    h_functions = 4;
    pinakes_katakermatismou = 5;

    srand(time(NULL));

    for (int i = 1; i < m; i++) {
        if (strcmp(argv[i], "-i") == 0) {
            arxeio_eisodou = argv[i + 1];
        } else if (strcmp(argv[i], "-c") == 0) {
            arxeio_config = argv[i + 1];
        } else if (strcmp(argv[i], "-o") == 0) {
            arxeio_exodou = argv[i + 1];
        } else if (strcmp(argv[i], "-a") == 0) {
            if (strcmp(argv[i + 1], "euclidean") == 0) {
                algorithmos_ektelesis = Euclidean;
            } else {
                algorithmos_ektelesis = Cosine;
            }
        } else if (strcmp(argv[i], "-complete") == 0) {
            leptomeries = true;
        }
    }
    
    return run_clustering(arxeio_eisodou, arxeio_exodou, arxeio_config, h_functions, pinakes_katakermatismou, leptomeries, algorithmos_ektelesis);
}
