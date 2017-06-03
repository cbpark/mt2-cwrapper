/*
 *  Copyright (c) 2015, 2017 Chan Beom Park <cbpark@gmail.com>
 *
 *  This file is part of mt2-cwrapper, which is released under the GNU General
 *  Public License. See file LICENSE in the top directory of this project or
 *  go to <http://www.gnu.org/licenses/> for full license details.
 */

#ifndef SRC_SYMM_MT2_MINUIT2_H_
#define SRC_SYMM_MT2_MINUIT2_H_

#include <cmath>
#include <vector>
#include "Minuit2/FCNBase.h"
#include "TLorentzVector.h"
#include "TVector2.h"

/**
 * MT2Calculator class.
 *
 * This class is basically the same as Basic_Mt2_332 algorithm in
 * <a href="http://www.hep.phy.cam.ac.uk/~lester/mt2/">MT2 / Stransverse Mass /
 * Oxbridge Kinetics Library</a>.
 * The modifications are:
 * - using TLorentzVector and TVector2 defined in ROOT,
 * - removing the namespace and some redundant codes,
 * - returning the invisible momenta after the minimization,
 * - simplifications in order to make C wrapper handily.
 */
class MT2Calculator {
private:
    double mt2sq(const TLorentzVector &vis_a, const TLorentzVector &vis_b,
                 const TVector2 &ptmiss, const double mchi);

public:
    double mt2(double *vis_a, double *vis_b, double *ptmiss, double mchi);
    double p_invisible[2];
    MT2Calculator() {}
};

inline double MT2Calculator::mt2(double *vis_a, double *vis_b, double *ptmiss,
                                 double mchi) {
    TLorentzVector va{vis_a[1], vis_a[2], vis_a[3], vis_a[0]};
    TLorentzVector vb{vis_b[1], vis_b[2], vis_b[3], vis_b[0]};
    TVector2 pchi{ptmiss[0], ptmiss[1]};
    double m_sq = mt2sq(va, vb, pchi, mchi);
    return m_sq < 0 ? -std::sqrt(-m_sq) : std::sqrt(m_sq);
}

#endif  // SRC_SYMM_MT2_MINUIT2_H_
