

#ifndef GROUP_AUGMENTATION_CONFIGURATION_H
#define GROUP_AUGMENTATION_CONFIGURATION_H




//Run parameters
const bool REACTION_NORM_HELP = 1;        //Apply reaction norm to age for level of help?
const bool REACTION_NORM_DISPERSAL = 1;    //Apply reaction norm to age for dispersal?

const int MAX_COLONIES = 1000;     // max number of groups or colonies --> breeding spots.
const int NUM_GENERATIONS = 200000;
const int MAX_NUM_REPLICATES = 20;
const int SKIP = 50;   // interval between print-outs

//Fix values
const double PREDATION = 0.1;
const double BIAS_FLOAT_BREEDER = 2;
const int INIT_NUM_HELPERS = 3;

// Modifiers
const double K0 = 1;    // min fecundity, fecundity when no help provided.
const double K1 = 1;    // benefit of cumhelp in the fecundity
const double Xsh = 3;    // cost of help in survival
const double Xsn = 1;    // benefit of group size in survival


//Genetic values

//For help
const double INIT_ALPHA = 0.0;            // bigger values higher level of help
const double INIT_ALPHA_AGE = 0.0;            //linear term for age, positive: higher help with age
const double INIT_ALPHA_AGE2 = 0.0;            //quadratic term for age, positive: higher help with age

const double MUTATION_ALPHA = 0.05;            // mutation rate in alpha for level of help
const double MUTATION_ALPHA_AGE = 0.05;
const double MUTATION_ALPHA_AGE2 = 0.05;
const double STEP_ALPHA = 0.01;            // mutation step size in alpha for level of help


//For dispersal
const double INIT_BETA = 1.0;            // bigger values higher dispersal
const double INIT_BETA_AGE = 0.0;            // 0: age has no effect, positive: dispersal decreases with age

const double MUTATION_BETA = 0.05;            // mutation rate for the propensity to disperse
const double MUTATION_BETA_AGE = 0.05;
const double STEP_BETA = 0.01;            // mutation step size for the propensity to disperse


//For relatedness
const double MUTATION_DRIFT = 0.05;            // mutation rate in the neutral selected value to track level of relatedness
const double STEP_DRIFT = 0.01;            // mutation step size in the neutral genetic value to track level of relatedness



const int NO_VALUE = -1;


#endif //GROUP_AUGMENTATION_CONFIGURATION_H
