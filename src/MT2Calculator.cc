#include "MT2Calculator.h"
#include "Minuit2/MnUserParameterState.h"
#include "Minuit2/MnSimplex.h"
#include "Minuit2/MnScan.h"
#include "Minuit2/FunctionMinimum.h"
#include <algorithm>

using ROOT::Minuit2::MnUserParameters;
using ROOT::Minuit2::MnSimplex;
using ROOT::Minuit2::MnScan;
using ROOT::Minuit2::FunctionMinimum;

double MT2Calculator::mt2(double* visA,
                          double* visB,
                          double* ptmiss,
                          double  mEachInvisible) {
    TLorentzVector vA(visA  [1],   visA[2],   visA[3],   visA[0]);
    TLorentzVector vB(visB  [1],   visB[2],   visB[3],   visB[0]);
    TVector2       pX(ptmiss[0], ptmiss[1]);

    double mSq = mt2Sq(vA, vB, pX, mEachInvisible);

    if (mSq >= 0)
        return sqrt(mSq);
    else
        return sqrt(fabs(mSq));
}

double MT2Calculator::mt2Sq(const TLorentzVector& visA,
                            const TLorentzVector& visB,
                            const TVector2& ptmiss,
                            const double& mEachInvisible) {

    mT2Fcn theFCN(ptmiss.Px(),
                  ptmiss.Py(),
                  mEachInvisible,
                  visA,
                  visB);

    const double massScale = (ptmiss.Mod() +
                              mEachInvisible +
                              visA.Pt()  +
                              visA.M() +
                              visB.Pt() +
                              visB.M()) / 6.0;

    double guessx = 0.5*(ptmiss.Px());
    double guessy = 0.5*(ptmiss.Py());

    MnUserParameters upar;
    upar.Add("etx", guessx, 0.02*massScale);
    upar.Add("ety", guessy, 0.02*massScale);
    const int highQuality=2;

    MnSimplex simplex(theFCN, upar, highQuality);
    FunctionMinimum minS = simplex(0, massScale*0.000001);
    pInvisible[0] = minS.UserState().Value("etx");
    pInvisible[1] = minS.UserState().Value("ety");

    return minS.Fval();
}

double MT2Calculator::mT2Fcn::operator()(const std::vector<double>& par) const
{
    double qT[2][2] = {             {par[0],             par[1]},
                        {theExmiss - par[0], theEymiss - par[1]} };

    double ETchi[2] = { theMchi * theMchi, theMchi * theMchi };
    for (int i=0; i<2; ++i) {
        for (int j=0; j<2; ++j)
            ETchi[i] += qT[i][j] * qT[i][j];

        ETchi[i] = sqrt( ETchi[i] );
    }

    double mVisSq[2] = { theVisA.M2(), theVisB.M2() };

    double pT[2][2] = { {theVisA.Px(), theVisA.Py()},
                        {theVisB.Px(), theVisB.Py()} };

    double ETvis[2] = { theVisA.Perp2(), theVisB.Perp2() };
    for (int i=0; i<2; ++i) {
        ETvis[i]  += mVisSq[i];
        ETvis[i]   = sqrt( ETvis[i] );
    }

    double mTsq[2] = { theMchi * theMchi + mVisSq[0],
                       theMchi * theMchi + mVisSq[1] };
    for (int i=0; i<2; ++i) {
        mTsq[i] += 2.0 * ETchi[i] * ETvis[i];
        for (int j=0; j<2; ++j)
            mTsq[i] -= 2.0 * qT[i][j] * pT[i][j];
    }

    return std::max(mTsq[0], mTsq[1]);
}
