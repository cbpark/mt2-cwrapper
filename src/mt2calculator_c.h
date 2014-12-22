#ifndef SRC_MT2CALCULATOR_C_H_
#define SRC_MT2CALCULATOR_C_H_

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct mt2calc_result {
        double mt2;
        double qx;
        double qy;
    } mt2calc_result;

    int run_mt2calculator(double *visA, double *visB,
                          double *ptmiss, double mInvisible,
                          mt2calc_result* result);

#ifdef __cplusplus
}
#endif
#endif  // SRC_MT2CALCULATOR_C_H_
