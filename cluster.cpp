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
#include "Sinartiseis.h"

using namespace std;

void loadconfiguration(char* arxeio_config, int& h_functions, int &pinakes_katakermatismou, int &plithos_systades) {
    string line2;
    ifstream cFile(arxeio_config);
    if (cFile.is_open() == true) {
        while (getline(cFile, line2)) {
            size_t pos = line2.find(":");
            string firstword = line2.substr(0, pos);
            string secondword = line2.substr(pos + 2);
            if (firstword == "number_of_hash_functions") {
                h_functions = atoi(secondword.c_str());
                //cout << h_functions << endl;
            }
            if (firstword == "number_of_hash_tables") {
                pinakes_katakermatismou = atoi(secondword.c_str());
                //cout << pinakes_katakermatismou << endl;
            }
            if (firstword == "number_of_clusters") {
                plithos_systades = atoi(secondword.c_str());
                //cout << plithos_systades << endl;
            }
        }
    }
}

int loadfile(char* arxeio_eisodou, AlgorithmosEktelesis & algorithmos_ektelesis, PinakasDianismaton * & pinakasDianismatwn, unsigned int & d) {
    string line, line2;
    int n = 0;

    ifstream File(arxeio_eisodou);

    //anazitisi tou algorithmou ekteleseis anazitisis
    if (File.is_open() == true) {
        getline(File, line);
        if (line.substr(0, 1) == "@") {
            cout << line.substr(9, 9) << endl;
            if (line.substr(8, 9) == "euclidean") {
                algorithmos_ektelesis = Euclidean;
                //cout << "euc" << endl;
            } else if (line.substr(8, 6) == "cosine") {
                algorithmos_ektelesis = Cosine;
                //cout << "cos" << endl;
            }
        } else {
            n++;
        }
        //metrisi plithous gramon arxeiou
        while (getline(File, line2)) {
            n++;
        }
        cout << "n = " << n << endl;
        File.close();

        File.open(arxeio_eisodou);

        //ipologismos megethous pinaka katakermatismou

        pinakasDianismatwn = new PinakasDianismaton(n);
        d = pinakasDianismatwn->eisagogiDedomenon(File);

        return n;
    } else {
        cout << "To arxeio den anoixtoike!" << endl;
        return -1;
    }

}


int run_clustering(char* arxeio_eisodou, char* arxeio_exodou, char* arxeio_config, int h_functions, int pinakes_katakermatismou, bool leptomeries, AlgorithmosEktelesis algorithmos_ektelesis) {
    int megethos_pinakes_katakermatismou, plithos_systades;
    unsigned int d;
    unsigned int n = 0; //grammes arxeiou eisodou
    PinakasDianismaton * pinakasDianismatwn = NULL;

    loadconfiguration(arxeio_config, h_functions, pinakes_katakermatismou, plithos_systades);
    
    //plithos_systades=4;
    cout << "To programma tha ektelestei gia: " << endl;
    cout << "i=" << arxeio_eisodou << " " << endl;
    cout << "c=" << arxeio_config << " " << endl;
    cout << "k=" << h_functions << " " << endl;
    cout << "L=" << pinakes_katakermatismou << " " << endl;
    cout << "K=" << plithos_systades << " " << endl;

    n = loadfile(arxeio_eisodou, algorithmos_ektelesis, pinakasDianismatwn, d);

    if (algorithmos_ektelesis == Euclidean) {
        megethos_pinakes_katakermatismou = n / 4;
    } else {
        megethos_pinakes_katakermatismou = (int) pow(2, h_functions);
    }

    cout << "N = " << n << endl;
    cout << "dim N = " << pinakasDianismatwn->getDianisma(0)->mikos() << endl;

    PinakaPinakon * pinakasPinakon = new PinakaPinakon(pinakes_katakermatismou, megethos_pinakes_katakermatismou, h_functions, d, algorithmos_ektelesis);

    //eisagogi dianismaton stis listes
    for (unsigned int i = 0; i < n; i++) {
        Dianisma * p = pinakasDianismatwn->getDianisma(i);
        pinakasPinakon->eisagogi(p);
    }
    
    Sinartiseis::calculateDistanceMatrix(pinakasDianismatwn, algorithmos_ektelesis);

    ofstream FileOutput(arxeio_exodou);
    // ----------------------- clustering --------------------------

    Clustering clustering;
    Ektipotis ektipotis;

    for (unsigned algorithmos_arxikopoiisis = Random; algorithmos_arxikopoiisis <= KmeansPP; ++algorithmos_arxikopoiisis) {
        for (unsigned algorithmos_anathesis = LLOYD; algorithmos_anathesis <= LSH; ++algorithmos_anathesis) {
            for (unsigned algorithmos_ananeosis = PAM; algorithmos_ananeosis <= Kmeans; ++algorithmos_ananeosis) {
                timespec ts1, ts2;

                clock_gettime(CLOCK_REALTIME, &ts1);

                cout << "===========================================" << endl;

                switch (algorithmos_arxikopoiisis) {
                    case Random:
                        cout << "Arxikopoiisi: Random " << endl;
                        break;
                    case KmeansPP:
                        cout << "Arxikopoiisi: Kmeans++ " << endl;
                        break;
                }

                switch (algorithmos_anathesis) {
                    case LLOYD:
                        cout << "Anathesi    : LLOYD " << endl;
                        break;
                    case LSH:
                        cout << "Anathesi    : LSH " << endl;
                        break;
                }

                switch (algorithmos_ananeosis) {
                    case PAM:
                        cout << "Update      : PAM " << endl;
                        continue;
                    case Kmeans:
                        cout << "Update      : Kmeans " << endl;
                        break;
                }
                cout << endl;

                // --------------------------- impl ------------------

                PinakasKentron * kentra;

                switch (algorithmos_arxikopoiisis) {
                    case Random:
                        kentra = clustering.random(pinakasDianismatwn, plithos_systades);
                        break;
                    case KmeansPP:
                        kentra = clustering.kmeanspp(pinakasDianismatwn, plithos_systades, algorithmos_ektelesis);
                        break;
                }

                kentra->print(cout);

                // ...

                bool stop = false;
                int steps = 1;
                PinakasAnathesewn * anatheseis = 0;

                while (!stop) {
                    steps++;

                    switch (algorithmos_anathesis) {
                        case LLOYD:
                            anatheseis = clustering.lloyd(pinakasDianismatwn, kentra, algorithmos_ektelesis);
                            break;
                        case LSH:
                            anatheseis = clustering.lsh(pinakasDianismatwn, kentra, pinakasPinakon, h_functions, pinakes_katakermatismou, algorithmos_ektelesis);
                            break;
                    }

                    if (anatheseis) {
                        ektipotis.ektiposi(cout, algorithmos_arxikopoiisis, algorithmos_anathesis, algorithmos_ananeosis, pinakasDianismatwn, kentra, anatheseis, algorithmos_ektelesis, 0, false);

                        switch (algorithmos_ananeosis) {
                            case PAM:
                            {
                                cout << "-------------------------------- Update      : PAM " << endl;
                                PinakasKentron * neakentra = clustering.pam(pinakasDianismatwn, kentra, anatheseis, algorithmos_ektelesis);

                                if (clustering.elegxosApostasisKentron(kentra, neakentra, algorithmos_ektelesis) < 0.0000001) {
                                    stop = true;
                                } else {
                                    kentra = neakentra;
                                }
                                break;
                            }
                            case Kmeans:
                            {
                                cout << "-------------------------------- Update      : Kmeans " << steps << endl;
                                PinakasKentron * neakentra = clustering.kmeans(pinakasDianismatwn, kentra, anatheseis, algorithmos_ektelesis);

                                if (clustering.elegxosApostasisKentron(kentra, neakentra, algorithmos_ektelesis) < 0.0000001) {
                                    stop = true;
                                } else {
                                    kentra = neakentra;
                                }
                                break;
                            }
                        }
                    }

                    if (steps == 40) {
                        stop = true;
                    }

                    if (!stop && anatheseis != NULL) {
                        delete anatheseis;
                    }
                }

                clock_gettime(CLOCK_REALTIME, &ts2);

                double dif = double( ts2.tv_nsec - ts1.tv_nsec); // nano

                if (anatheseis != NULL) {
                    cout << "Calculating Silhouette..." << endl;
                    double * sil = clustering.silouette(pinakasDianismatwn, kentra, anatheseis, algorithmos_ektelesis);

                    ektipotis.ektiposi_ekfonisis(FileOutput, algorithmos_arxikopoiisis, algorithmos_anathesis, algorithmos_ananeosis, pinakasDianismatwn, kentra, anatheseis, algorithmos_ektelesis, sil, leptomeries, dif);

                    delete [] sil;
                }
            }
        }
    }

    // -------------------------------------------------------------

    FileOutput.close();

    if (pinakasPinakon != NULL) {
        delete pinakasPinakon;
    }
    if (pinakasDianismatwn != NULL) {
        delete pinakasDianismatwn;
    }

    return 0;
}