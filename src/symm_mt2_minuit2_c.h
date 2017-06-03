/*
 *  Copyright (c) 2014-2015, 2017 Chan Beom Park <cbpark@gmail.com>
 *
 *  This file is part of mt2-cwrapper, which is released under the GNU General
 *  Public License. See file LICENSE in the top directory of this project or
 *  go to <http://www.gnu.org/licenses/> for full license details.
 */

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

int run_symm_mt2_minuit2(double *vis_a, double *vis_b, double *ptmiss,
                         double mchi, mt2calc_result *result);

#ifdef __cplusplus
}
#endif
#endif  // SRC_SYMM_MT2_MINUIT2_C_H_
