#include "MT2Calculator_c.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    double visA[4]    = { 423.,  410.,   20., -20. };
    double visB[4]    = { 398., -210., -300,   44. };
    double ptmiss[2]  = { -200., 280. };
    double mInvisible = 100.;

    mt2calc_result* result = (mt2calc_result*) malloc(sizeof(mt2calc_result));
    if (result == NULL) {
        puts("Memory allocation for mt2calc_result failed.");
        exit(1);
    }

    int status = MT2Calculator_run(visA, visB, ptmiss, mInvisible, result);

    if (status == 0) {
        printf("MT2 = %f\n", result->mt2);
        printf("qx = %f, qy = %f at the minimum\n", result->qx, result->qy);
    }
    else {
        printf("The MT2 calculation failed!\n");
    }

    return 0;
}
