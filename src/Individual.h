
#include "Classes.cpp"

struct Individual // define individual traits
{
    Individual(double alpha_ = 0, double alphaAge_ = 0, double alphaAge2_ = 0, double beta_ = 0, double betaAge_ = 0,
               double drift_ = 0, Classes own_ = HELPER);

    Individual(const Individual &mother);

    double alpha, alphaAge, alphaAge2, beta, betaAge, drift,        // genetic values
            dispersal, help, survival;                                    // phenotypic values
    Classes fishType;                                                // possible classes: breeder, helper, floater
    int age;

    //Functions inside Individual
    double calcDispersal();

    double calcHelp();

    double calcSurvival(int totalHelpers);

    void Mutate();
};
