
#include "Individual.h"
#include "Configuration.h"



Individual::Individual(double alpha_, double alphaAge_, double alphaAge2_, double beta_, double betaAge_, double drift_,
                       Classes fishType_) {
    alpha = alpha_;
    alphaAge = alphaAge_;
    alphaAge2 = alphaAge2_;
    beta = beta_;
    betaAge = betaAge_;
    drift = drift_;
    Mutate();
    fishType = fishType_;
    age = 1;
    survival = NO_VALUE;
    help = 0;
    dispersal = 0;
}

Individual::Individual(const Individual &copy) {
    alpha = copy.alpha;
    alphaAge = copy.alphaAge;
    alphaAge2 = copy.alphaAge2;
    beta = copy.beta;
    betaAge = copy.betaAge;
    drift = copy.drift;
    fishType = copy.fishType;
    age = copy.age;
    survival = copy.survival;
    help = copy.help;
    dispersal = copy.dispersal;
}