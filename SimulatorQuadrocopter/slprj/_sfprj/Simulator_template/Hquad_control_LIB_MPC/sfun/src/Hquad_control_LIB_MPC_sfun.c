/* Include files */

#include "Hquad_control_LIB_MPC_sfun.h"
#include "Hquad_control_LIB_MPC_sfun_debug_macros.h"
#include "c1_Hquad_control_LIB_MPC.h"
#include "c3_Hquad_control_LIB_MPC.h"
#include "c4_Hquad_control_LIB_MPC.h"
#include "c5_Hquad_control_LIB_MPC.h"
#include "c6_Hquad_control_LIB_MPC.h"
#include "c7_Hquad_control_LIB_MPC.h"
#include "c8_Hquad_control_LIB_MPC.h"
#include "c9_Hquad_control_LIB_MPC.h"
#include "c11_Hquad_control_LIB_MPC.h"
#include "c16_Hquad_control_LIB_MPC.h"
#include "c18_Hquad_control_LIB_MPC.h"
#include "c19_Hquad_control_LIB_MPC.h"
#include "c20_Hquad_control_LIB_MPC.h"
#include "c21_Hquad_control_LIB_MPC.h"
#include "c26_Hquad_control_LIB_MPC.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _Hquad_control_LIB_MPCMachineNumber_;

/* Function Declarations */

/* Function Definitions */
void Hquad_control_LIB_MPC_initializer(void)
{
}

void Hquad_control_LIB_MPC_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_Hquad_control_LIB_MPC_method_dispatcher(SimStruct *simstructPtr,
  unsigned int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_Hquad_control_LIB_MPC_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_Hquad_control_LIB_MPC_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_Hquad_control_LIB_MPC_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_Hquad_control_LIB_MPC_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==6) {
    c6_Hquad_control_LIB_MPC_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==7) {
    c7_Hquad_control_LIB_MPC_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==8) {
    c8_Hquad_control_LIB_MPC_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==9) {
    c9_Hquad_control_LIB_MPC_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==11) {
    c11_Hquad_control_LIB_MPC_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==16) {
    c16_Hquad_control_LIB_MPC_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==18) {
    c18_Hquad_control_LIB_MPC_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==19) {
    c19_Hquad_control_LIB_MPC_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==20) {
    c20_Hquad_control_LIB_MPC_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==21) {
    c21_Hquad_control_LIB_MPC_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==26) {
    c26_Hquad_control_LIB_MPC_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_Hquad_control_LIB_MPC_process_check_sum_call( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>2 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"library")) {
      char machineName[100];
      mxGetString(prhs[2], machineName,sizeof(machineName)/sizeof(char));
      machineName[(sizeof(machineName)/sizeof(char)-1)] = '\0';
      if (!strcmp(machineName,"Hquad_control_LIB_MPC")) {
        if (nrhs==3) {
          ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3459641639U);
          ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2135523680U);
          ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3850912850U);
          ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(216405979U);
        } else if (nrhs==4) {
          unsigned int chartFileNumber;
          chartFileNumber = (unsigned int)mxGetScalar(prhs[3]);
          switch (chartFileNumber) {
           case 1:
            {
              extern void sf_c1_Hquad_control_LIB_MPC_get_check_sum(mxArray
                *plhs[]);
              sf_c1_Hquad_control_LIB_MPC_get_check_sum(plhs);
              break;
            }

           case 3:
            {
              extern void sf_c3_Hquad_control_LIB_MPC_get_check_sum(mxArray
                *plhs[]);
              sf_c3_Hquad_control_LIB_MPC_get_check_sum(plhs);
              break;
            }

           case 4:
            {
              extern void sf_c4_Hquad_control_LIB_MPC_get_check_sum(mxArray
                *plhs[]);
              sf_c4_Hquad_control_LIB_MPC_get_check_sum(plhs);
              break;
            }

           case 5:
            {
              extern void sf_c5_Hquad_control_LIB_MPC_get_check_sum(mxArray
                *plhs[]);
              sf_c5_Hquad_control_LIB_MPC_get_check_sum(plhs);
              break;
            }

           case 6:
            {
              extern void sf_c6_Hquad_control_LIB_MPC_get_check_sum(mxArray
                *plhs[]);
              sf_c6_Hquad_control_LIB_MPC_get_check_sum(plhs);
              break;
            }

           case 7:
            {
              extern void sf_c7_Hquad_control_LIB_MPC_get_check_sum(mxArray
                *plhs[]);
              sf_c7_Hquad_control_LIB_MPC_get_check_sum(plhs);
              break;
            }

           case 8:
            {
              extern void sf_c8_Hquad_control_LIB_MPC_get_check_sum(mxArray
                *plhs[]);
              sf_c8_Hquad_control_LIB_MPC_get_check_sum(plhs);
              break;
            }

           case 9:
            {
              extern void sf_c9_Hquad_control_LIB_MPC_get_check_sum(mxArray
                *plhs[]);
              sf_c9_Hquad_control_LIB_MPC_get_check_sum(plhs);
              break;
            }

           case 11:
            {
              extern void sf_c11_Hquad_control_LIB_MPC_get_check_sum(mxArray
                *plhs[]);
              sf_c11_Hquad_control_LIB_MPC_get_check_sum(plhs);
              break;
            }

           case 16:
            {
              extern void sf_c16_Hquad_control_LIB_MPC_get_check_sum(mxArray
                *plhs[]);
              sf_c16_Hquad_control_LIB_MPC_get_check_sum(plhs);
              break;
            }

           case 18:
            {
              extern void sf_c18_Hquad_control_LIB_MPC_get_check_sum(mxArray
                *plhs[]);
              sf_c18_Hquad_control_LIB_MPC_get_check_sum(plhs);
              break;
            }

           case 19:
            {
              extern void sf_c19_Hquad_control_LIB_MPC_get_check_sum(mxArray
                *plhs[]);
              sf_c19_Hquad_control_LIB_MPC_get_check_sum(plhs);
              break;
            }

           case 20:
            {
              extern void sf_c20_Hquad_control_LIB_MPC_get_check_sum(mxArray
                *plhs[]);
              sf_c20_Hquad_control_LIB_MPC_get_check_sum(plhs);
              break;
            }

           case 21:
            {
              extern void sf_c21_Hquad_control_LIB_MPC_get_check_sum(mxArray
                *plhs[]);
              sf_c21_Hquad_control_LIB_MPC_get_check_sum(plhs);
              break;
            }

           case 26:
            {
              extern void sf_c26_Hquad_control_LIB_MPC_get_check_sum(mxArray
                *plhs[]);
              sf_c26_Hquad_control_LIB_MPC_get_check_sum(plhs);
              break;
            }

           default:
            ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
            ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
            ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
            ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
          }
        } else {
          return 0;
        }
      } else {
        return 0;
      }
    } else {
      return 0;
    }
  } else {
    return 0;
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_Hquad_control_LIB_MPC_autoinheritance_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char aiChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;
  mxGetString(prhs[2], aiChksum,sizeof(aiChksum)/sizeof(char));
  aiChksum[(sizeof(aiChksum)/sizeof(char)-1)] = '\0';

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(aiChksum, "nh76AtsuL8I9FR93xyClmE") == 0) {
          extern mxArray *sf_c1_Hquad_control_LIB_MPC_get_autoinheritance_info
            (void);
          plhs[0] = sf_c1_Hquad_control_LIB_MPC_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "oMZbdsvy8OZAzoPlGchP1C") == 0) {
          extern mxArray *sf_c3_Hquad_control_LIB_MPC_get_autoinheritance_info
            (void);
          plhs[0] = sf_c3_Hquad_control_LIB_MPC_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "PddICc7weq3w2oiZsWbCfH") == 0) {
          extern mxArray *sf_c4_Hquad_control_LIB_MPC_get_autoinheritance_info
            (void);
          plhs[0] = sf_c4_Hquad_control_LIB_MPC_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "Js21s845HMRYEwG9sWQp3F") == 0) {
          extern mxArray *sf_c5_Hquad_control_LIB_MPC_get_autoinheritance_info
            (void);
          plhs[0] = sf_c5_Hquad_control_LIB_MPC_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 6:
      {
        if (strcmp(aiChksum, "pK85XlVC8cHIfd0QscFQBG") == 0) {
          extern mxArray *sf_c6_Hquad_control_LIB_MPC_get_autoinheritance_info
            (void);
          plhs[0] = sf_c6_Hquad_control_LIB_MPC_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 7:
      {
        if (strcmp(aiChksum, "pK85XlVC8cHIfd0QscFQBG") == 0) {
          extern mxArray *sf_c7_Hquad_control_LIB_MPC_get_autoinheritance_info
            (void);
          plhs[0] = sf_c7_Hquad_control_LIB_MPC_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 8:
      {
        if (strcmp(aiChksum, "p9NXNLYRd7QjiiMwQAefsC") == 0) {
          extern mxArray *sf_c8_Hquad_control_LIB_MPC_get_autoinheritance_info
            (void);
          plhs[0] = sf_c8_Hquad_control_LIB_MPC_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 9:
      {
        if (strcmp(aiChksum, "qoRejmPF0PKXidDQmdXyoD") == 0) {
          extern mxArray *sf_c9_Hquad_control_LIB_MPC_get_autoinheritance_info
            (void);
          plhs[0] = sf_c9_Hquad_control_LIB_MPC_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 11:
      {
        if (strcmp(aiChksum, "oMZbdsvy8OZAzoPlGchP1C") == 0) {
          extern mxArray *sf_c11_Hquad_control_LIB_MPC_get_autoinheritance_info
            (void);
          plhs[0] = sf_c11_Hquad_control_LIB_MPC_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 16:
      {
        if (strcmp(aiChksum, "Js21s845HMRYEwG9sWQp3F") == 0) {
          extern mxArray *sf_c16_Hquad_control_LIB_MPC_get_autoinheritance_info
            (void);
          plhs[0] = sf_c16_Hquad_control_LIB_MPC_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 18:
      {
        if (strcmp(aiChksum, "brbGJAEZFBJoXWBIT8cagG") == 0) {
          extern mxArray *sf_c18_Hquad_control_LIB_MPC_get_autoinheritance_info
            (void);
          plhs[0] = sf_c18_Hquad_control_LIB_MPC_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 19:
      {
        if (strcmp(aiChksum, "brbGJAEZFBJoXWBIT8cagG") == 0) {
          extern mxArray *sf_c19_Hquad_control_LIB_MPC_get_autoinheritance_info
            (void);
          plhs[0] = sf_c19_Hquad_control_LIB_MPC_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 20:
      {
        if (strcmp(aiChksum, "tNYoVAWCxd8JSGzubW0QQE") == 0) {
          extern mxArray *sf_c20_Hquad_control_LIB_MPC_get_autoinheritance_info
            (void);
          plhs[0] = sf_c20_Hquad_control_LIB_MPC_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 21:
      {
        if (strcmp(aiChksum, "tNYoVAWCxd8JSGzubW0QQE") == 0) {
          extern mxArray *sf_c21_Hquad_control_LIB_MPC_get_autoinheritance_info
            (void);
          plhs[0] = sf_c21_Hquad_control_LIB_MPC_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 26:
      {
        if (strcmp(aiChksum, "idNwsgva3FBfH7PGX67okD") == 0) {
          extern mxArray *sf_c26_Hquad_control_LIB_MPC_get_autoinheritance_info
            (void);
          plhs[0] = sf_c26_Hquad_control_LIB_MPC_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_Hquad_control_LIB_MPC_get_eml_resolved_functions_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        extern const mxArray
          *sf_c1_Hquad_control_LIB_MPC_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_Hquad_control_LIB_MPC_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray
          *sf_c3_Hquad_control_LIB_MPC_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_Hquad_control_LIB_MPC_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray
          *sf_c4_Hquad_control_LIB_MPC_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_Hquad_control_LIB_MPC_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray
          *sf_c5_Hquad_control_LIB_MPC_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_Hquad_control_LIB_MPC_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 6:
      {
        extern const mxArray
          *sf_c6_Hquad_control_LIB_MPC_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c6_Hquad_control_LIB_MPC_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 7:
      {
        extern const mxArray
          *sf_c7_Hquad_control_LIB_MPC_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c7_Hquad_control_LIB_MPC_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 8:
      {
        extern const mxArray
          *sf_c8_Hquad_control_LIB_MPC_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c8_Hquad_control_LIB_MPC_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 9:
      {
        extern const mxArray
          *sf_c9_Hquad_control_LIB_MPC_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c9_Hquad_control_LIB_MPC_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 11:
      {
        extern const mxArray
          *sf_c11_Hquad_control_LIB_MPC_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c11_Hquad_control_LIB_MPC_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 16:
      {
        extern const mxArray
          *sf_c16_Hquad_control_LIB_MPC_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c16_Hquad_control_LIB_MPC_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 18:
      {
        extern const mxArray
          *sf_c18_Hquad_control_LIB_MPC_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c18_Hquad_control_LIB_MPC_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 19:
      {
        extern const mxArray
          *sf_c19_Hquad_control_LIB_MPC_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c19_Hquad_control_LIB_MPC_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 20:
      {
        extern const mxArray
          *sf_c20_Hquad_control_LIB_MPC_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c20_Hquad_control_LIB_MPC_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 21:
      {
        extern const mxArray
          *sf_c21_Hquad_control_LIB_MPC_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c21_Hquad_control_LIB_MPC_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 26:
      {
        extern const mxArray
          *sf_c26_Hquad_control_LIB_MPC_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c26_Hquad_control_LIB_MPC_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_Hquad_control_LIB_MPC_third_party_uses_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the third_party_uses_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_third_party_uses_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "CW9TPeP3D3jzTSXz9TP0aB") == 0) {
          extern mxArray *sf_c1_Hquad_control_LIB_MPC_third_party_uses_info(void);
          plhs[0] = sf_c1_Hquad_control_LIB_MPC_third_party_uses_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "tQvBlIbv8Q76uvlyfAPTMB") == 0) {
          extern mxArray *sf_c3_Hquad_control_LIB_MPC_third_party_uses_info(void);
          plhs[0] = sf_c3_Hquad_control_LIB_MPC_third_party_uses_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "9ukmRYrRYXn7rvf6dwyjIG") == 0) {
          extern mxArray *sf_c4_Hquad_control_LIB_MPC_third_party_uses_info(void);
          plhs[0] = sf_c4_Hquad_control_LIB_MPC_third_party_uses_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "po9Jq8Fj6QNIBJjFRUW5KC") == 0) {
          extern mxArray *sf_c5_Hquad_control_LIB_MPC_third_party_uses_info(void);
          plhs[0] = sf_c5_Hquad_control_LIB_MPC_third_party_uses_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "9cCVXedYes0RQHo9xw8Yq") == 0) {
          extern mxArray *sf_c6_Hquad_control_LIB_MPC_third_party_uses_info(void);
          plhs[0] = sf_c6_Hquad_control_LIB_MPC_third_party_uses_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "9cCVXedYes0RQHo9xw8Yq") == 0) {
          extern mxArray *sf_c7_Hquad_control_LIB_MPC_third_party_uses_info(void);
          plhs[0] = sf_c7_Hquad_control_LIB_MPC_third_party_uses_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "z1TIkCO6Q4kMPs8uruIiAH") == 0) {
          extern mxArray *sf_c8_Hquad_control_LIB_MPC_third_party_uses_info(void);
          plhs[0] = sf_c8_Hquad_control_LIB_MPC_third_party_uses_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "J9cVuQmr51fLwATPeVNOZG") == 0) {
          extern mxArray *sf_c9_Hquad_control_LIB_MPC_third_party_uses_info(void);
          plhs[0] = sf_c9_Hquad_control_LIB_MPC_third_party_uses_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "tQvBlIbv8Q76uvlyfAPTMB") == 0) {
          extern mxArray *sf_c11_Hquad_control_LIB_MPC_third_party_uses_info
            (void);
          plhs[0] = sf_c11_Hquad_control_LIB_MPC_third_party_uses_info();
          break;
        }
      }

     case 16:
      {
        if (strcmp(tpChksum, "po9Jq8Fj6QNIBJjFRUW5KC") == 0) {
          extern mxArray *sf_c16_Hquad_control_LIB_MPC_third_party_uses_info
            (void);
          plhs[0] = sf_c16_Hquad_control_LIB_MPC_third_party_uses_info();
          break;
        }
      }

     case 18:
      {
        if (strcmp(tpChksum, "eoWaOP4lGzOWPQP2Vo6Lo") == 0) {
          extern mxArray *sf_c18_Hquad_control_LIB_MPC_third_party_uses_info
            (void);
          plhs[0] = sf_c18_Hquad_control_LIB_MPC_third_party_uses_info();
          break;
        }
      }

     case 19:
      {
        if (strcmp(tpChksum, "eoWaOP4lGzOWPQP2Vo6Lo") == 0) {
          extern mxArray *sf_c19_Hquad_control_LIB_MPC_third_party_uses_info
            (void);
          plhs[0] = sf_c19_Hquad_control_LIB_MPC_third_party_uses_info();
          break;
        }
      }

     case 20:
      {
        if (strcmp(tpChksum, "qJGrMMHT6fLmo5l53rPatH") == 0) {
          extern mxArray *sf_c20_Hquad_control_LIB_MPC_third_party_uses_info
            (void);
          plhs[0] = sf_c20_Hquad_control_LIB_MPC_third_party_uses_info();
          break;
        }
      }

     case 21:
      {
        if (strcmp(tpChksum, "qJGrMMHT6fLmo5l53rPatH") == 0) {
          extern mxArray *sf_c21_Hquad_control_LIB_MPC_third_party_uses_info
            (void);
          plhs[0] = sf_c21_Hquad_control_LIB_MPC_third_party_uses_info();
          break;
        }
      }

     case 26:
      {
        if (strcmp(tpChksum, "O4fQlh57OhxC4AD55kVAqG") == 0) {
          extern mxArray *sf_c26_Hquad_control_LIB_MPC_third_party_uses_info
            (void);
          plhs[0] = sf_c26_Hquad_control_LIB_MPC_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void Hquad_control_LIB_MPC_debug_initialize(struct SfDebugInstanceStruct*
  debugInstance)
{
  _Hquad_control_LIB_MPCMachineNumber_ = sf_debug_initialize_machine
    (debugInstance,"Hquad_control_LIB_MPC","sfun",1,15,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _Hquad_control_LIB_MPCMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,
    _Hquad_control_LIB_MPCMachineNumber_,0);
}

void Hquad_control_LIB_MPC_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_Hquad_control_LIB_MPC_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "Hquad_control_LIB_MPC", "Simulator_template");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_Hquad_control_LIB_MPC_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
