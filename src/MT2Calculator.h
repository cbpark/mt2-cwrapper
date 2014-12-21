//! MT2Calculator class.
/*!
  This class is basically the same as Basic_Mt2_332 algorithm in
  <a href="http://www.hep.phy.cam.ac.uk/~lester/mt2/">MT2 / Stransverse Mass / Oxbridge Kinetics Library</a>.
  The modifications are:
  - using TLorentzVector and TVector2 defined in ROOT,
  - removing the namespace and some redundant codes,
  - returning the invisible momenta after the minimization,
  - simplifications in order to make C wrapper handily.
*/
#ifndef _MT2CALCULATOR_H_
#define _MT2CALCULATOR_H_

#include "Minuit2/FCNBase.h"
#include "TLorentzVector.h"
#include "TVector2.h"
#include <vector>

class MT2Calculator {
public:

    //! Calculate the MT2 variable.
    /*!
      The input momenta should be like visibleA[4], visibleB[4], ptmiss[2], and mInvisible.
    */
    double mt2(double* visibleA,
               double* visibleB,
               double* ptmiss,
               double  mInvisible);

    //! The transverse momenta of the invisible particle after the minimization.
    double pInvisible[2];

    //! MT2Calculator constructor.
    MT2Calculator() {
        for (int i = 0; i < 2; ++i) {
            pInvisible[i] = 0;
        }
    }

    //! MT2Calculator destructor.
    ~MT2Calculator() { }

private:

    double mt2Sq(const TLorentzVector& visibleA,
                 const TLorentzVector& visibleB,
                 const TVector2& ptmiss,
                 const double& mInvisible);
};

#endif /* _MT2CALCULATOR_H_ */
