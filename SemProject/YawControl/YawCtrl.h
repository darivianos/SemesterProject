#define mpt_getInput_h

#define MPT_NR 1
#define MPT_NX 1
#define MPT_NU 1
#define MPT_NY 1
#define MPT_NXT 1
#define MPT_NREF 0
#define MPT_TS 0.080000
#define MPT_DUMODE 0
#define MPT_TRACKING 0
#define MPT_ABSTOL 1.000000e-03

static float MPT_H[] = {
1.000000e+00,	-1.000000e+00 };

static float MPT_K[] = {
8.730000e-02,	8.730000e-02 };

static int MPT_NC[] = {
2 };

static float MPT_F[] = {
-2.847540e-01 };

static float MPT_G[] = {
4.440892e-16 };
