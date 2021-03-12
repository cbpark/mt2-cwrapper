/*
 *  Copyright (c) 2014-2015, 2017 Chan Beom Park <cbpark@gmail.com>
 *
 *  This file is part of mt2-cwrapper, which is released under the GNU General
 *  Public License. See file LICENSE in the top directory of this project or
 *  go to <http://www.gnu.org/licenses/> for full license details.
 */

#include <stdio.h>
#include "lester_mt2_bisect_c.h"

int main(void) {
    double visA[3] = {100.0, 410.0, 20.0};
    double visB[3] = {150.0, -210.0, -300.0};
    double ptmiss[2] = {-200.0, 280.0};
    double mchi = 100.0;
    double mT2 =
        asymm_mt2_lester_bisect(visA[0], visA[1], visA[2], visB[0], visB[1],
                                visB[2], ptmiss[0], ptmiss[1], mchi, mchi);
    printf("MT2 = %f\n", mT2);
    Solutions s = sols(mT2, visA[1], visA[2], visA[0], mchi, visB[1], visB[2],
                       ptmiss[0], ptmiss[1], visB[0], mchi);
    printf("sols = (%f, %f)\n", s.qx, s.qy);
}
