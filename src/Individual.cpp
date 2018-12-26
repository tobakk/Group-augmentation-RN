#include <iostream>
#include <cmath>
#include <random>

#include "Individual.h"
#include "Configuration.h"


using namespace std;


Individual::Individual(double alpha_,
                       double alphaAge_,
                       double alphaAge2_,
                       double beta_,
                       double betaAge_,
                       double drift_,
                       default_random_engine randomNumberGenerator,
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
    this->randomNumberGenerator = randomNumberGenerator;
}

//Individual::Individual(const Individual &copy, default_random_engine randomNumberGenerator) {
//    alpha = copy.alpha;
//    alphaAge = copy.alphaAge;
//    alphaAge2 = copy.alphaAge2;
//    beta = copy.beta;
//    betaAge = copy.betaAge;
//    drift = copy.drift;
//    fishType = copy.fishType;
//    age = copy.age;
//    survival = copy.survival;
//    help = copy.help;
//    dispersal = copy.dispersal;
//    this->randomNumberGenerator = randomNumberGenerator;
//}

/*DISPLAY LEVEL OF HELP*/
double Individual::calcHelp() {
    if (!REACTION_NORM_HELP) {
        help = alpha;
    } else {
        help = alpha + alphaAge * age + alphaAge2 * age * age;
        if (help < 0) { help = 0; }
    }

    return help;
}


/* BECOME FLOATER (STAY VS DISPERSE) */

double Individual::calcDispersal() {
    if (!REACTION_NORM_DISPERSAL) {

        dispersal = beta; // Range from 0 to 1 to compare to a Uniform distribution

        if (dispersal < 0 || dispersal > 1) {
            cout << "error in dispersal: " << dispersal << endl;
        }

    } else {
        dispersal = 1 / (1 + exp(betaAge * age - beta));
    }

    return dispersal;
}

/*SURVIVAL*/

double Individual::calcSurvival(int totalHelpers) {
    survival = (1 - PREDATION) /
               (1 + exp(Xsh * help - Xsn * (totalHelpers + 1))); // +1 to know group size (1 breeder + helpers)

    return survival;
}

void Individual::Mutate() // mutate genome of offspring
{
    normal_distribution<double> NormalA(0,
                                        STEP_ALPHA); ///could be simplified if I decide to have all the steps size with the same magnitude
    normal_distribution<double> NormalB(0, STEP_BETA);
    normal_distribution<double> normalDistribution(0, STEP_DRIFT);

    if (uniformDistribution(randomNumberGenerator) < MUTATION_ALPHA) {
        alpha += NormalA(randomNumberGenerator);
        if (!REACTION_NORM_HELP) {
            if (alpha < 0) { alpha = 0; }
        }
    }
    if (REACTION_NORM_HELP) {
        if (uniformDistribution(randomNumberGenerator) < MUTATION_ALPHA_AGE) {
            alphaAge += NormalA(randomNumberGenerator);
        }

        if (uniformDistribution(randomNumberGenerator) < MUTATION_ALPHA_AGE2) {
            alphaAge2 += NormalA(randomNumberGenerator);
        }
    }

    if (uniformDistribution(randomNumberGenerator) < MUTATION_BETA) {
        beta += NormalB(randomNumberGenerator);
        if (!REACTION_NORM_DISPERSAL) {
            if (beta < 0) { beta = 0; }
            if (beta > 1) { beta = 1; }
        }
    }
    if (REACTION_NORM_DISPERSAL) {
        if (uniformDistribution(randomNumberGenerator) < MUTATION_BETA_AGE) {
            betaAge += normalDistribution(randomNumberGenerator);
        }
    }

    if (uniformDistribution(randomNumberGenerator) < MUTATION_DRIFT) {
        drift += normalDistribution(randomNumberGenerator);
    }
}

