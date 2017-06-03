/*
 *  Copyright (c) 2014-2015, 2017 Chan Beom Park <cbpark@gmail.com>
 *
 *  This file is part of mt2-cwrapper, which is released under the GNU General
 *  Public License. See file LICENSE in the top directory of this project or
 *  go to <http://www.gnu.org/licenses/> for full license details.
 */

#include "symm_mt2_minuit2_c.h"
#include "symm_mt2_minuit2.h"

extern "C" {
double mt2_value(MT2Calculator *m, double *vis_a, double *vis_b, double *ptmiss,
                 double mchi) {
    return m->mt2(vis_a, vis_b, ptmiss, mchi);
}

double *pinv_value(MT2Calculator *m) { return m->p_invisible; }

int run_symm_mt2_minuit2(double *vis_a, double *vis_b, double *ptmiss,
                         double mchi, mt2calc_result *result) {
    MT2Calculator *m = new MT2Calculator();
    if (m == NULL) {
        puts("Memory allocation for MT2Calculator failed.");
        return 1;
    }

    result->mt2 = mt2_value(m, vis_a, vis_b, ptmiss, mchi);
    result->qx = pinv_value(m)[0];
    result->qy = pinv_value(m)[1];

    delete m;

    return 0;
}
}
