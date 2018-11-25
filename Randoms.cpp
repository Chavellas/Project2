/*
Chavellas Christos
AM: 1115201300196
 */

#include <cstdlib>
#include <random>

#include "Randoms.h"

using namespace std;

std::default_random_engine generator;

unsigned int getRandomInt(int M, int N) {
    int r = M + (rand() / (RAND_MAX + 1.0))*(N - M + 1);
    return r;
}

unsigned int getRandomInt() {
    return getRandomInt(0, 100000);
}

double getRandomReal(int max) {
    int r = max * (rand() / (RAND_MAX + 1.0));
    return r;
}

double getRandomNormalValue() {
    normal_distribution<double> distribution(0, 1);
    return  distribution(generator);
}
