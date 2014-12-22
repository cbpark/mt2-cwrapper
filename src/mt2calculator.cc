#include "mt2calculator.h"

#include <algorithm>
#include <cmath>
#include "Minuit2/MnUserParameterState.h"
#include "Minuit2/MnSimplex.h"
#include "Minuit2/FunctionMinimum.h"

class MT2Fcn : public ROOT::Minuit2::FCNBase {
private:
    double exmiss_, eymiss_;
    double mchi_;
    TLorentzVector via_a_, vis_b_;
    double error_def_;
public:
    MT2Fcn(const double& exmiss, const double& eymiss, const double& mchi,
           const TLorentzVector& vis_a, const TLorentzVector& vis_b) :
        exmiss_(exmiss), eymiss_(eymiss), mchi_(mchi),
        via_a_(vis_a), vis_b_(vis_b), error_def_(1.0) { }
    virtual double Up() const {
        return error_def_;
    }
    virtual double operator()(const std::vector<double>&) const;
};

double MT2Fcn::operator()(const std::vector<double>& par) const {
    double pchi[2][2] = {{par[0], par[1]},
                         {exmiss_ - par[0], eymiss_ - par[1]}};
    double echi[2] = {mchi_ * mchi_, mchi_ * mchi_};
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            echi[i] += pchi[i][j] * pchi[i][j];
        }
        echi[i] = std::sqrt(echi[i]);
    }

    double mvis_sq[2] = {via_a_.M2(), vis_b_.M2()};
    double pvis[2][2] = {{via_a_.Px(), via_a_.Py()},
                         {vis_b_.Px(), vis_b_.Py()}};
    double evis[2] = {via_a_.Perp2(), vis_b_.Perp2()};
    for (int i = 0; i < 2; ++i) {
        evis[i] += mvis_sq[i];
        evis[i]  = std::sqrt(evis[i]);
    }

    double mtrans_sq[2] = {mchi_ * mchi_ + mvis_sq[0],
                           mchi_ * mchi_ + mvis_sq[1]};
    for (int i = 0; i < 2; ++i) {
        mtrans_sq[i] += 2.0 * echi[i] * evis[i];
        for (int j = 0; j < 2; ++j) {
            mtrans_sq[i] -= 2.0 * pchi[i][j] * pvis[i][j];
        }
    }

    return std::max(mtrans_sq[0], mtrans_sq[1]);
}

double MT2Calculator::mt2sq(const TLorentzVector& vis_a,
                            const TLorentzVector& vis_b,
                            const TVector2& ptmiss, const double& mchi) {
    MT2Fcn fcn(ptmiss.Px(), ptmiss.Py(), mchi, vis_a, vis_b);

    const double mass_scale = (ptmiss.Mod() + mchi
                               + vis_a.Pt() + vis_a.M()
                               + vis_b.Pt() + vis_b.M()) / 6.0;

    double guessx = 0.5 * ptmiss.Px();
    double guessy = 0.5 * ptmiss.Py();

    ROOT::Minuit2::MnUserParameters upar;
    upar.Add("etx", guessx, 0.02*mass_scale);
    upar.Add("ety", guessy, 0.02*mass_scale);

    const int high_quality = 2;
    ROOT::Minuit2::MnSimplex simplex(fcn, upar, high_quality);
    ROOT::Minuit2::FunctionMinimum min_s = simplex(0, mass_scale*0.000001);
    p_invisible[0] = min_s.UserState().Value("etx");
    p_invisible[1] = min_s.UserState().Value("ety");

    return min_s.Fval();
}
