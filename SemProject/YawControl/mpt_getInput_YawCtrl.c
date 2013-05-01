/* C implemented function to get input of X direction */
/* Main implementation was taken by function of MPT toolbox */
/* exportToC.m which can be found under tbxmanager/toolboxes/mpt/3.0.2/all/mpt3-3_0_2/functions/modules/ui/@EMPCController */
/* Modified by Darivianakis Georgios (gdarivia@student.ethz.ch) to include the following extra features */

/* 1) When no feasible control law then provide the input derived by the control law of the region */
/*    which violates the less constraints */
/* 2) Round the input at the third decimal in order to be closer to real applications */

#ifndef YawCtrl_h 
#include "YawCtrl.h" 
#endif
#include <math.h>

static float mpt_getInput_YawCtrl(float *X, float *U)
{
    int ix, iu, ic, nc, isinside;
    unsigned long ireg, abspos, minreg;
    float hx, region, tolerance, sumViol, temp;
    
    abspos = 0;
    region = 0;
    tolerance = 1;
    sumViol = 0;
    minreg = 0;

    /* initialize U to zero*/
    for (iu=0; iu<MPT_NU; iu++) {
        U[iu] = 0;
    }
    for (ix=0; ix<MPT_NX; ix++) {
        temp = X[ix];
        X[ix] = round(1000*temp)/1000;
    }
    
    for (ireg=0; ireg<MPT_NR; ireg++) {
        sumViol = 0;
        isinside = 1;
        nc = MPT_NC[ireg];
        for (ic=0; ic<nc; ic++) {
            hx = 0;
            for (ix=0; ix<MPT_NX; ix++) {
                hx = hx + MPT_H[abspos*MPT_NX+ic*MPT_NX+ix]*X[ix];
            }
            
            if ((hx - MPT_K[abspos+ic]) > MPT_ABSTOL) {
                /* constraint is violated, continue with next region */
                isinside = 0;
                sumViol = sumViol + (hx - MPT_K[abspos+ic]);
            }
            
        }
        if (sumViol < tolerance){
            tolerance = sumViol;
            minreg = ireg;
        }
        if (isinside==1) {
            /* state belongs to this region, extract control law and exit */
            region = ireg + 1;
            for (iu=0; iu<MPT_NU; iu++) {
                for (ix=0; ix<MPT_NX; ix++) {
                    U[iu] = U[iu] + MPT_F[ireg*MPT_NX*MPT_NU + iu*MPT_NX + ix]*X[ix];
                }
                U[iu] = U[iu] + MPT_G[ireg*MPT_NU + iu];
            }
            return region;
        }
        abspos = abspos + MPT_NC[ireg];
    }
    ireg = minreg;
    region = ireg + 1;
    for (iu=0; iu<MPT_NU; iu++) {
        for (ix=0; ix<MPT_NX; ix++) {
            U[iu] = U[iu] + MPT_F[ireg*MPT_NX*MPT_NU + iu*MPT_NX + ix]*X[ix];
        }
        U[iu] = U[iu] + MPT_G[ireg*MPT_NU + iu];
    }
    return region;
}
