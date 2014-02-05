//! A C wrapper for the MT2Calculator.
#ifndef _MT2CALCULATOR_C_H_
#define _MT2CALCULATOR_C_H_

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct MT2Calculator MT2Calculator;

    MT2Calculator* newMT2Calculator();

    void deleteMT2Calculator(MT2Calculator* m);

    double MT2Calculator_mt2(MT2Calculator* m,
                             double* visA,
                             double* visB,
                             double* ptmiss,
                             double  mInvisible);

    double* MT2Calculator_pInvisible(MT2Calculator* m);

    typedef struct MT2
    {
        double mt2;
        double qx;
        double qy;
    } MT2;

    MT2 MT2Calculator_run(double* visA,
                          double* visB,
                          double* ptmiss,
                          double  mInvisible);

#ifdef __cplusplus
}
#endif
#endif /* _MT2CALCULATOR_C_H_ */
