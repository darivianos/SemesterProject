/* C implemented function to get input of X direction */
/* Main implementation was taken by function of MPT toolbox */
/* exportToC.m which can be found under tbxmanager/toolboxes/mpt/3.0.2/all/mpt3-3_0_2/functions/modules/ui/@EMPCController */
/* Modified by Darivianakis Georgios (gdarivia@student.ethz.ch) to include the following extra features */

/* 1) When no feasible control law then provide the input derived by the control law of the region */
/*    which violates the less constraints */
/* 2) Round the input at the third decimal in order to be closer to real applications */

#ifndef XdirectionCtrl_h 
#include "XdirectionCtrl.h" 
#endif
#include <math.h>

static float mpt_getInput_Xdirection(float *X, float *U)
{
    int ix, iu, ic, nc, isinside;
    unsigned long ireg, abspos;
    float hx, region;
    int minReg, minViol, regionViol;
    
    for (ix=0; ix<MPT_NX; ix++) {
        X[ix] = round(1000*X[ix])/1000;
    }
    
    abspos = 0;
    region = 0;
    
    minReg = -1;
    minViol = 1000;
    
    /* initialize U to zero*/
    for (iu=0; iu<MPT_NU; iu++) {
        U[iu] = 0;
    }

    for (ireg=0; ireg<MPT_NR; ireg++) {
        regionViol = 0;
        isinside = 1;
        nc = MPT_NC[ireg];
        for (ic=0; ic<nc; ic++) {
            hx = 0;
            for (ix=0; ix<MPT_NX; ix++) {
                hx = hx + MPT_H[abspos*MPT_NX+ic*MPT_NX+ix]*X[ix];
            }
            if ((hx - MPT_K[abspos+ic]) > MPT_ABSTOL) {
                /* constraint is violated, continue with next region */
                regionViol = regionViol + 1;
                isinside = 0;
                break;
            } 
        }
        if (isinside==1) {
            /* state belongs to this region, extract control law and exit */
            region = ireg + 1;
            for (iu=0; iu<MPT_NU; iu++) {
                for (ix=0; ix<MPT_NX; ix++) {
                    U[iu] = U[iu] + MPT_F[ireg*MPT_NX*MPT_NU + iu*MPT_NX + ix]*X[ix];
                }
                U[iu] = U[iu] + MPT_G[ireg*MPT_NU + iu];
                /* round up at the third decimal */
                U[iu] = round(U[iu]*1000)/1000;
            }
            return region;
        }
        abspos = abspos + MPT_NC[ireg];
        
        /* Check which region has the least number of constraints violation */
        if(regionViol < minViol){
            minViol = regionViol;
            minReg = ireg;
        }
    }
       /* case in which not a feasible control law found */
    region = minReg + 1;
    for (iu=0; iu<MPT_NU; iu++) {
        for (ix=0; ix<MPT_NX; ix++) {
            U[iu] = U[iu] + MPT_F[minReg*MPT_NX*MPT_NU + iu*MPT_NX + ix]*X[ix];
        }
        U[iu] = U[iu] + MPT_G[minReg*MPT_NU + iu];
        /* round up at the third decimal */
        U[iu] = round(U[iu]*1000)/1000;
    }
    return region;
   
}
