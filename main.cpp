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

using namespace std;

int main(int argc, char** argv) {

    int m = argc; //plihos eisodou
    char* arxeio_eisodou;
    char* arxeio_exodou;
    char* arxeio_config;
    int h_functions; //k
    int pinakes_katakermatismou; //L
    int megethos_pinakes_katakermatismou;
    int plithos_systades;
    unsigned int d;
    unsigned int n = 0; //grammes arxeiou eisodou
    AlgorithmosEktelesis algorithmos_ektelesis = Euclidean; //0:Euclidean 1:Cosine
    PinakasDianismaton * pinakasDianismatwn = NULL;

    string line;
    string line2;

    h_functions = 4;
    pinakes_katakermatismou = 5;

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
        }
    }

    // read config file
    ifstream cFile(arxeio_config);
    if (cFile.is_open() == true) {
        while (getline(cFile, line2)) {
            size_t pos = line2.find(":");
            string firstword = line2.substr(0, pos);
            string secondword = line2.substr(pos + 2);
            if (firstword == "number_of_hash_functions") {
                h_functions = atoi(secondword.c_str());
            }
            if (firstword == "number_of_hash_tables") {
                pinakes_katakermatismou = atoi(secondword.c_str());
            }
            if (firstword == "number_of_clusters") {
                plithos_systades = atoi(secondword.c_str());
            }
        }
    }

    //dedoemna arxeio_eisodou
    cout << "To programma tha ektelestei gia: " << endl;
    cout << "i=" << arxeio_eisodou << " " << endl;
    cout << "c=" << arxeio_config << " " << endl;
    cout << "k=" << h_functions << " " << endl;
    cout << "L=" << pinakes_katakermatismou << " " << endl;
    cout << "K=" << plithos_systades << " " << endl;

    srand(time(NULL));

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
        if (algorithmos_ektelesis == Euclidean) {
            megethos_pinakes_katakermatismou = n / 4;
        } else {
            megethos_pinakes_katakermatismou = (int) pow(2, h_functions);
        }
        pinakasDianismatwn = new PinakasDianismaton(n);
        d = pinakasDianismatwn->eisagogiDedomenon(File);
    } else {
        cout << "To arxeio den anoixtoike!" << endl;
        return 0;
    }

    cout << "N = " << n << endl;
    cout << "dim N = " << pinakasDianismatwn->getDianisma(0)->mikos() << endl;

    PinakaPinakon * pinakasPinakon = new PinakaPinakon(pinakes_katakermatismou, megethos_pinakes_katakermatismou, h_functions, d, algorithmos_ektelesis);

    //eisagogi dianismaton stis listes
    for (unsigned int i = 0; i < n; i++) {
        Dianisma * p = pinakasDianismatwn->getDianisma(i);
        pinakasPinakon->eisagogi(p);
    }

    ofstream FileOutput(arxeio_exodou);
    // ----------------------- clustering --------------------------

    Clustering clustering;
    Ektipotis ektipotis;

    for (unsigned algorithmos_arxikopoiisis = Random; algorithmos_arxikopoiisis <= KmeansPP; ++algorithmos_arxikopoiisis) {
        for (unsigned algorithmos_anathesis = LLOYD; algorithmos_anathesis <= LSH; ++algorithmos_anathesis) {
            for (unsigned algorithmos_ananeosis = PAM; algorithmos_ananeosis <= Kmeans; ++algorithmos_ananeosis) {
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
                        break;
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

                while (true) {
                    PinakasAnathesewn * anatheseis;

                    switch (algorithmos_anathesis) {
                        case LLOYD:
                            anatheseis = clustering.lloyd(pinakasDianismatwn, kentra, algorithmos_ektelesis);
                            break;
                        case LSH:
                            //                            anatheseis = clustering.lloyd(pinakasDianismatwn, kentra);
                            break;
                    }

                    ektipotis.ektiposi(algorithmos_arxikopoiisis, algorithmos_anathesis, algorithmos_ananeosis, pinakasDianismatwn, kentra, anatheseis, algorithmos_ektelesis, false);



                    switch (algorithmos_ananeosis) {
                        case PAM:
                            cout << "Update      : PAM " << endl;
                            break;
                        case Kmeans: {
                            cout << "Update      : Kmeans " << endl;
                            PinakasKentron * neakentra =  clustering.kmeans(pinakasDianismatwn, kentra, anatheseis, algorithmos_ektelesis);
                            // ###
                            break;
                        }
                    }
                    break;
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
