#ifndef SRC_SYMM_MT2_MINUIT2_C_H_
#define SRC_SYMM_MT2_MINUIT2_C_H_

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct mt2calc_result {
        double mt2;
        double qx;
        double qy;
    } mt2calc_result;

    int run_symm_mt2_minuit2(double *vis_a, double *vis_b,
                             double *ptmiss, double mchi,
                             mt2calc_result* result);

#ifdef __cplusplus
}
#endif
#endif  // SRC_SYMM_MT2_MINUIT2_C_H_
