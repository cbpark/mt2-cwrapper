#include <stdio.h>
#include "lester_mt2_bisect_c.h"

int main() {
    double visA[3] = {100.0,  410.0,   20.0};
    double visB[4] = {150.0, -210.0, -300.0};
    double ptmiss[2] = {-200.0, 280.0};
    double mchi = 100.0;
    printf("MT2 = %f\n", asymm_mt2_bisect(visA[0], visA[1], visA[2],
                                          visB[0], visB[1], visB[2],
                                          ptmiss[0], ptmiss[1],
                                          mchi, mchi));
}
