/* Include files */

#include "Hquad_control_LIB_LQR_sfun.h"
#include "c1_Hquad_control_LIB_LQR.h"
#include "c2_Hquad_control_LIB_LQR.h"
#include "c4_Hquad_control_LIB_LQR.h"
#include "c22_Hquad_control_LIB_LQR.h"
#include "c23_Hquad_control_LIB_LQR.h"
#include "c24_Hquad_control_LIB_LQR.h"
#include "c26_Hquad_control_LIB_LQR.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _Hquad_control_LIB_LQRMachineNumber_;

/* Function Declarations */

/* Function Definitions */
void Hquad_control_LIB_LQR_initializer(void)
{
}

void Hquad_control_LIB_LQR_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_Hquad_control_LIB_LQR_method_dispatcher(SimStruct *simstructPtr,
  unsigned int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_Hquad_control_LIB_LQR_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_Hquad_control_LIB_LQR_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_Hquad_control_LIB_LQR_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==22) {
    c22_Hquad_control_LIB_LQR_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==23) {
    c23_Hquad_control_LIB_LQR_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==24) {
    c24_Hquad_control_LIB_LQR_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==26) {
    c26_Hquad_control_LIB_LQR_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_Hquad_control_LIB_LQR_process_check_sum_call( int nlhs, mxArray *
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
      if (!strcmp(machineName,"Hquad_control_LIB_LQR")) {
        if (nrhs==3) {
          ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3053099771U);
          ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2738357012U);
          ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3458877313U);
          ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4119453075U);
        } else if (nrhs==4) {
          unsigned int chartFileNumber;
          chartFileNumber = (unsigned int)mxGetScalar(prhs[3]);
          switch (chartFileNumber) {
           case 1:
            {
              extern void sf_c1_Hquad_control_LIB_LQR_get_check_sum(mxArray
                *plhs[]);
              sf_c1_Hquad_control_LIB_LQR_get_check_sum(plhs);
              break;
            }

           case 2:
            {
              extern void sf_c2_Hquad_control_LIB_LQR_get_check_sum(mxArray
                *plhs[]);
              sf_c2_Hquad_control_LIB_LQR_get_check_sum(plhs);
              break;
            }

           case 4:
            {
              extern void sf_c4_Hquad_control_LIB_LQR_get_check_sum(mxArray
                *plhs[]);
              sf_c4_Hquad_control_LIB_LQR_get_check_sum(plhs);
              break;
            }

           case 22:
            {
              extern void sf_c22_Hquad_control_LIB_LQR_get_check_sum(mxArray
                *plhs[]);
              sf_c22_Hquad_control_LIB_LQR_get_check_sum(plhs);
              break;
            }

           case 23:
            {
              extern void sf_c23_Hquad_control_LIB_LQR_get_check_sum(mxArray
                *plhs[]);
              sf_c23_Hquad_control_LIB_LQR_get_check_sum(plhs);
              break;
            }

           case 24:
            {
              extern void sf_c24_Hquad_control_LIB_LQR_get_check_sum(mxArray
                *plhs[]);
              sf_c24_Hquad_control_LIB_LQR_get_check_sum(plhs);
              break;
            }

           case 26:
            {
              extern void sf_c26_Hquad_control_LIB_LQR_get_check_sum(mxArray
                *plhs[]);
              sf_c26_Hquad_control_LIB_LQR_get_check_sum(plhs);
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

unsigned int sf_Hquad_control_LIB_LQR_autoinheritance_info( int nlhs, mxArray *
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
        if (strcmp(aiChksum, "45Fuswg00zONVTG7JwL4nH") == 0) {
          extern mxArray *sf_c1_Hquad_control_LIB_LQR_get_autoinheritance_info
            (void);
          plhs[0] = sf_c1_Hquad_control_LIB_LQR_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "WucNmsTdfL32cCRVCQfYVE") == 0) {
          extern mxArray *sf_c2_Hquad_control_LIB_LQR_get_autoinheritance_info
            (void);
          plhs[0] = sf_c2_Hquad_control_LIB_LQR_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "uqhzgzx0XKWhD3wpRouPj") == 0) {
          extern mxArray *sf_c4_Hquad_control_LIB_LQR_get_autoinheritance_info
            (void);
          plhs[0] = sf_c4_Hquad_control_LIB_LQR_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 22:
      {
        if (strcmp(aiChksum, "hmYcdyDXXhoJJTD0zJ3zpG") == 0) {
          extern mxArray *sf_c22_Hquad_control_LIB_LQR_get_autoinheritance_info
            (void);
          plhs[0] = sf_c22_Hquad_control_LIB_LQR_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 23:
      {
        if (strcmp(aiChksum, "DbIzIE8fJOe5fgoGGbEQjC") == 0) {
          extern mxArray *sf_c23_Hquad_control_LIB_LQR_get_autoinheritance_info
            (void);
          plhs[0] = sf_c23_Hquad_control_LIB_LQR_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 24:
      {
        if (strcmp(aiChksum, "0EnR6ROROtAZ3s4d6x8WbF") == 0) {
          extern mxArray *sf_c24_Hquad_control_LIB_LQR_get_autoinheritance_info
            (void);
          plhs[0] = sf_c24_Hquad_control_LIB_LQR_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 26:
      {
        if (strcmp(aiChksum, "7RzKZXjuoXTy7F5GxUZfPG") == 0) {
          extern mxArray *sf_c26_Hquad_control_LIB_LQR_get_autoinheritance_info
            (void);
          plhs[0] = sf_c26_Hquad_control_LIB_LQR_get_autoinheritance_info();
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

unsigned int sf_Hquad_control_LIB_LQR_get_eml_resolved_functions_info( int nlhs,
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
          *sf_c1_Hquad_control_LIB_LQR_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_Hquad_control_LIB_LQR_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray
          *sf_c2_Hquad_control_LIB_LQR_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_Hquad_control_LIB_LQR_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray
          *sf_c4_Hquad_control_LIB_LQR_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_Hquad_control_LIB_LQR_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 22:
      {
        extern const mxArray
          *sf_c22_Hquad_control_LIB_LQR_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c22_Hquad_control_LIB_LQR_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 23:
      {
        extern const mxArray
          *sf_c23_Hquad_control_LIB_LQR_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c23_Hquad_control_LIB_LQR_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 24:
      {
        extern const mxArray
          *sf_c24_Hquad_control_LIB_LQR_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c24_Hquad_control_LIB_LQR_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 26:
      {
        extern const mxArray
          *sf_c26_Hquad_control_LIB_LQR_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c26_Hquad_control_LIB_LQR_get_eml_resolved_functions_info();
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

void Hquad_control_LIB_LQR_debug_initialize(void)
{
  _Hquad_control_LIB_LQRMachineNumber_ = sf_debug_initialize_machine(
    "Hquad_control_LIB_LQR","sfun",1,7,0,0,0);
  sf_debug_set_machine_event_thresholds(_Hquad_control_LIB_LQRMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(_Hquad_control_LIB_LQRMachineNumber_,0);
}

void Hquad_control_LIB_LQR_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_Hquad_control_LIB_LQR_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "Hquad_control_LIB_LQR", "Simulator_hquad_LQR_trajectory");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_Hquad_control_LIB_LQR_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
