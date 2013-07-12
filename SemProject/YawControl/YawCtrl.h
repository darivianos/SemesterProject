#define mpt_getInput_h

#define MPT_NR 3
#define MPT_NX 1
#define MPT_NU 1
#define MPT_NY 1
#define MPT_NXT 1
#define MPT_NREF 0
#define MPT_TS 0.080000
#define MPT_DUMODE 0
#define MPT_TRACKING 0
#define MPT_ABSTOL 1.000000e-08

static float MPT_H[] = {
1.000000e+00,	-1.000000e+00,	-1.000000e+00,	1.000000e+00,	1.000000e+00,	
-1.000000e+00 };

static float MPT_K[] = {
2.740881e+00,	2.740881e+00,	-2.740881e+00,	3.141593e+00,	-2.740881e+00,	
3.141593e+00 };

static int MPT_NC[] = {
2,	2,	2 };

static float MPT_F[] = {
-1.146198e+00,	0.000000e+00,	0.000000e+00 };

static float MPT_G[] = {
-4.440892e-16,	-3.141593e+00,	3.141593e+00 };
