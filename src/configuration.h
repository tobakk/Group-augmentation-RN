#ifndef GROUP_AUGMENTATION_CONFIGURATION_H
#define GROUP_AUGMENTATION_CONFIGURATION_H

#include <iostream>
#include <random>
#include <fstream>

using namespace std;




// Output file
ofstream fout("group_augmentation_init.txt");
ofstream fout2("group_augmentation_last_generation_init.txt");


/*CONSTANTS AND STRUCTURES*/

// Random numbers
//mt19937 mt(time(0)); // random number generator
//unsigned seed = std::chrono::system_clock::now().time_since_epoch().count(); // if we don't want to obtain the same simulation under the same parameters
unsigned seed = 0; //in the same run takes different random values, but different runs same values unless we change the seed
default_random_engine generator(seed);
uniform_real_distribution<double> DriftUniform(0, 100);
uniform_real_distribution<double> Uniform(0, 1);



//Run parameters
const bool REACTION_NORM_HELP = 1;		//Apply reaction norm to age for level of help?
const bool REACTION_NORM_DISPERSAL = 1;	//Apply reaction norm to age for dispersal?

const int MAX_COLONIES	  = 1000;     // max number of groups or colonies --> breeding spots.
const int NUM_GENERATIONS = 200000;
const int MAX_NUM_REPLICATES  = 20;
const int SKIP = 50;   // interval between print-outs

//Fix values
const double PREDATION = 0.1;
const double BIAS_FLOAT_BREEDER = 2;
const int    INIT_NUM_HELPERS = 3;

// Modifiers
const double K0     = 1;	// min fecundity, fecundity when no help provided.
const double K1     = 1;	// benefit of cumhelp in the fecundity
const double Xsh    = 3;	// cost of help in survival
const double Xsn    = 1;	// benefit of group size in survival


//Genetic values

//For help
const double INIT_ALPHA			= 0.0;			// bigger values higher level of help
const double INIT_ALPHA_AGE		= 0.0;			//linear term for age, positive: higher help with age
const double INIT_ALPHA_AGE2	= 0.0;			//quadratic term for age, positive: higher help with age

const double MUTATION_ALPHA		= 0.05;			// mutation rate in alpha for level of help
const double MUTATION_ALPHA_AGE = 0.05;
const double MUTATION_ALPHA_AGE2= 0.05;
const double STEP_ALPHA			= 0.01;			// mutation step size in alpha for level of help


//For dispersal
const double INIT_BETA			= 1.0;			// bigger values higher dispersal
const double INIT_BETA_AGE		= 0.0;			// 0: age has no effect, positive: dispersal decreases with age

const double MUTATION_BETA		= 0.05;			// mutation rate for the propensity to disperse
const double MUTATION_BETA_AGE	= 0.05;
const double STEP_BETA			= 0.01;			// mutation step size for the propensity to disperse


//For relatedness
const double MUTATION_DRIFT		= 0.05;			// mutation rate in the neutral selected value to track level of relatedness
const double STEP_DRIFT			= 0.01;			// mutation step size in the neutral genetic value to track level of relatedness


const int NO_VALUE = -1;

//Population parameters and Statistics
int replica, gen, population, populationBeforeSurv, deaths, floatersgenerated, driftGroupSize, maxGroupSize, populationHelpers;
double relatedness;
double  meanGroupsize, stdevGroupSize,  sumGroupSize, sumsqGroupSize, varGroupSize,
        meanAge, stdevAge, sumAge, sumsqAge, varAge,
        meanAlpha, stdevAlpha, sumAlpha, sumsqAlpha, varAlpha,
        meanAlphaAge, stdevAlphaAge, sumAlphaAge, sumsqAlphaAge, varAlphaAge,
        meanAlphaAge2, stdevAlphaAge2, sumAlphaAge2, sumsqAlphaAge2, varAlphaAge2,
        meanBeta, stdevBeta, sumBeta, sumsqBeta, varBeta,
        meanBetaAge, stdevBetaAge, sumBetaAge, sumsqBetaAge, varBetaAge,
        meanHelp, stdevHelp, sumHelp, sumsqHelp, varHelp,
        meanDispersal, stdevDispersal, sumDispersal, sumsqDispersal, varDispersal,
        meanDriftB, sumDriftB, meanDriftH, sumDriftH,											//relatedness
        meanDriftBH, meanDriftBB, sumDriftBH, sumDriftBB,
        corr_HelpDispersal, sumprodHelpDispersal;





#endif //GROUP_AUGMENTATION_CONFIGURATION_H
