#include "MT2Calculator.h"
#include "MT2Calculator_c.h"

extern "C" {
    MT2Calculator* newMT2Calculator() {
        return new MT2Calculator();
    }

    void deleteMT2Calculator(MT2Calculator* m) {
        delete m;
    }

    double MT2Calculator_mt2(MT2Calculator* m,
                             double* visA,
                             double* visB,
                             double* ptmiss,
                             double  mInvisible) {
        return m->mt2(visA, visB, ptmiss, mInvisible);
    }

    double* MT2Calculator_pInvisible(MT2Calculator* m) {
        return m->pInvisible;
    }

    MT2 MT2Calculator_run(double* visA,
                          double* visB,
                          double* ptmiss,
                          double  mInvisible) {
        struct MT2Calculator* m = newMT2Calculator();

        MT2 result;

        result.mt2 = MT2Calculator_mt2(m, visA, visB, ptmiss, mInvisible);
        result.qx  = MT2Calculator_pInvisible(m)[0];
        result.qy  = MT2Calculator_pInvisible(m)[1];

        deleteMT2Calculator(m);

        return result;
    }
}
