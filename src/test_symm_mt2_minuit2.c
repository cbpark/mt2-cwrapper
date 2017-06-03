/*
 *  Copyright (c) 2014-2015, 2017 Chan Beom Park <cbpark@gmail.com>
 *
 *  This file is part of mt2-cwrapper, which is released under the GNU General
 *  Public License. See file LICENSE in the top directory of this project or
 *  go to <http://www.gnu.org/licenses/> for full license details.
 */

#include <stdio.h>
#include <stdlib.h>
#include "symm_mt2_minuit2_c.h"

int main(void) {
    double visA[4] = {423.0, 410.0, 20.0, -20.0};
    double visB[4] = {398.0, -210.0, -300.0, 44.0};
    double ptmiss[2] = {-200.0, 280.0};
    double mchi = 100.0;

    mt2calc_result *result = (mt2calc_result *)malloc(sizeof(mt2calc_result));
    if (result == NULL) {
        puts("Memory allocation for mt2calc_result failed.");
        exit(1);
    }

    int status = run_symm_mt2_minuit2(visA, visB, ptmiss, mchi, result);
    if (status == 0) {
        printf("MT2 = %f\n", result->mt2);
        printf("qx = %f, qy = %f at the minimum\n", result->qx, result->qy);
    } else {
        printf("The MT2 calculation failed!\n");
    }
}
