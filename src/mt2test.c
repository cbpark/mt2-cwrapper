#include "mt2calculator_c.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    double visA[4] = {423.,  410.0,   20.0, -20.0};
    double visB[4] = {398., -210.0, -300.0,  44.0};
    double ptmiss[2] = {-200.0, 280.0};
    double mchi = 100.0;

    mt2calc_result* result = (mt2calc_result*) malloc(sizeof(mt2calc_result));
    if (result == NULL) {
        puts("Memory allocation for mt2calc_result failed.");
        exit(1);
    }

    int status = run_mt2calculator(visA, visB, ptmiss, mchi, result);
    if (status == 0) {
        printf("MT2 = %f\n", result->mt2);
        printf("qx = %f, qy = %f at the minimum\n", result->qx, result->qy);
    } else {
        printf("The MT2 calculation failed!\n");
    }

    return 0;
}
