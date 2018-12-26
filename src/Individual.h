
#ifndef GROUP_AUGMENTATION_INDIVIDUAL_H
#define GROUP_AUGMENTATION_INDIVIDUAL_H


#include "classes.h"

using namespace std;

struct Individual // define individual traits
{
    Individual(double alpha_,
               double alphaAge_,
               double alphaAge2_,
               double beta_,
               double betaAge_,
               double drift_,
               default_random_engine randomNumberGenerator,
               Classes own_ = HELPER);

//    Individual(const Individual &mother, default_random_engine randomNumberGenerator);


    double alpha, alphaAge, alphaAge2, beta, betaAge, drift,        // genetic values
            dispersal, help, survival;                               // phenotypic values
    Classes fishType;                                                // possible classes: breeder, helper, floater
    int age;

    default_random_engine randomNumberGenerator;

    //Functions inside Individual
    double calcDispersal();

    double calcHelp();

    double calcSurvival(int totalHelpers);

    void Mutate();
};

#endif //GROUP_AUGMENTATION_INDIVIDUAL_H