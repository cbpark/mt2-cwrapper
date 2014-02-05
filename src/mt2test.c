#include "MT2Calculator_c.h"
#include <stdio.h>

int main(void)
{
    double visA[4]    = { 423.,  410.,   20., -20. };
    double visB[4]    = { 398., -210., -300,   44. };
    double ptmiss[2]  = { -200., 280. };
    double mInvisible = 100.;

    MT2 result = MT2Calculator_run(visA, visB, ptmiss, mInvisible);

    printf("MT2 = %f\n", result.mt2);
    printf("qx = %f, qy = %f at the minimum\n", result.qx, result.qy);

    return 0;
}
