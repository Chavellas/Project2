
#include "Ektiposeis.h"
#include "PinakasDianismaton.h"
#include "PinakasAnathesewn.h"
#include "PinakasKentron.h"

#include <iostream>
#include <list>

using namespace std;

void Ektipotis::ektiposi(unsigned algorithmos_arxikopoiisis, unsigned algorithmos_anathesis, unsigned algorithmos_ananeosis, PinakasDianismaton * pd, PinakasKentron * kentra, PinakasAnathesewn * pinakasAnatheseon, AlgorithmosEktelesis ae, bool leptomereies) {

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

    list<unsigned int> * deiktis = new list<unsigned int>[kentra->getN()];


    for (unsigned int j = 0; j < pd->getN(); j++) {
        Dianisma * apo = pd->getDianisma(j);

        deiktis[pinakasAnatheseon->getAnathesi(j)].push_back(j);
    }

    for (unsigned int i = 0; i < kentra->getN(); i++) {
        cout << "Cluster-" << i << ":" << " { size: " << deiktis[i].size() << " " << kentra->getDianisma(i)->GetTag() << " } " << endl;
    }


    if (leptomereies) {
        for (unsigned int i = 0; i < kentra->getN(); i++) {
            cout << "*** Cluster-" << i << ":" << " { size: " << deiktis[i].size() << " " << kentra->getDianisma(i)->GetTag() << " } " << endl;

            int counter = 0;
            for (list<unsigned int>::iterator p = deiktis[i].begin(); p != deiktis[i].end(); p++) {
                cout << pd->getDianisma(*p)->getID() << "\t";
                counter++;
                if (counter == 5) {
                    counter = 0;
                    cout << endl;
                }
            }
            cout << endl;
        }
    }





    cout << endl;

    delete [] deiktis;
}
