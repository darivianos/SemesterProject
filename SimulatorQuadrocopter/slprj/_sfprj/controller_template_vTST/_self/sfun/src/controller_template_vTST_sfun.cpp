/* Include files */

#include "controller_template_vTST_sfun.h"
#include "c1_controller_template_vTST.h"
#include "c2_controller_template_vTST.h"
#include "c3_controller_template_vTST.h"
#include "c4_controller_template_vTST.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _controller_template_vTSTMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void controller_template_vTST_initializer(void)
{
}

void controller_template_vTST_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_controller_template_vTST_method_dispatcher(SimStruct
  *simstructPtr, unsigned int chartFileNumber, const char* specsCksum, int_T
  method, void *data)
{
  if (chartFileNumber==1) {
    c1_controller_template_vTST_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_controller_template_vTST_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_controller_template_vTST_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_controller_template_vTST_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_controller_template_vTST_process_testpoint_info_call( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char machineName[128];
  if (nrhs < 3 || !mxIsChar(prhs[0]) || !mxIsChar(prhs[1]))
    return 0;

  /* Possible call to get testpoint info. */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_testpoint_info"))
    return 0;
  mxGetString(prhs[1], machineName, sizeof(machineName)/sizeof(char));
  machineName[(sizeof(machineName)/sizeof(char)-1)] = '\0';
  if (!strcmp(machineName, "controller_template_vTST")) {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
    switch (chartFileNumber) {
     case 1:
      {
        extern mxArray *sf_c1_controller_template_vTST_get_testpoint_info(void);
        plhs[0] = sf_c1_controller_template_vTST_get_testpoint_info();
        break;
      }

     case 2:
      {
        extern mxArray *sf_c2_controller_template_vTST_get_testpoint_info(void);
        plhs[0] = sf_c2_controller_template_vTST_get_testpoint_info();
        break;
      }

     case 3:
      {
        extern mxArray *sf_c3_controller_template_vTST_get_testpoint_info(void);
        plhs[0] = sf_c3_controller_template_vTST_get_testpoint_info();
        break;
      }

     case 4:
      {
        extern mxArray *sf_c4_controller_template_vTST_get_testpoint_info(void);
        plhs[0] = sf_c4_controller_template_vTST_get_testpoint_info();
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }

    return 1;
  }

  return 0;

#else

  return 0;

#endif

}

unsigned int sf_controller_template_vTST_process_check_sum_call( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
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
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2983376856U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2283231954U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3683165072U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(277298617U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(580306333U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2892394039U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(985415229U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3664947284U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_controller_template_vTST_get_check_sum(mxArray *
            plhs[]);
          sf_c1_controller_template_vTST_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_controller_template_vTST_get_check_sum(mxArray *
            plhs[]);
          sf_c2_controller_template_vTST_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_controller_template_vTST_get_check_sum(mxArray *
            plhs[]);
          sf_c3_controller_template_vTST_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_controller_template_vTST_get_check_sum(mxArray *
            plhs[]);
          sf_c4_controller_template_vTST_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(65012270U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(758126418U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4231394770U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2145385362U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(888886155U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3010842897U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1253923174U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1979913470U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_controller_template_vTST_autoinheritance_info( int nlhs, mxArray
  * plhs[], int nrhs, const mxArray * prhs[] )
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
        if (strcmp(aiChksum, "RSJfvnpAMS5JarRMVBpx0G") == 0) {
          extern mxArray
            *sf_c1_controller_template_vTST_get_autoinheritance_info(void);
          plhs[0] = sf_c1_controller_template_vTST_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "ucFBFGNn35UNj63VB48iTD") == 0) {
          extern mxArray
            *sf_c2_controller_template_vTST_get_autoinheritance_info(void);
          plhs[0] = sf_c2_controller_template_vTST_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "rWu1wKxvVv1DL03jC6pvJC") == 0) {
          extern mxArray
            *sf_c3_controller_template_vTST_get_autoinheritance_info(void);
          plhs[0] = sf_c3_controller_template_vTST_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "ekZxSgXMhkGSTeJX8mCnKF") == 0) {
          extern mxArray
            *sf_c4_controller_template_vTST_get_autoinheritance_info(void);
          plhs[0] = sf_c4_controller_template_vTST_get_autoinheritance_info();
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

unsigned int sf_controller_template_vTST_get_eml_resolved_functions_info( int
  nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
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
          *sf_c1_controller_template_vTST_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_controller_template_vTST_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray
          *sf_c2_controller_template_vTST_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_controller_template_vTST_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray
          *sf_c3_controller_template_vTST_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_controller_template_vTST_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray
          *sf_c4_controller_template_vTST_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_controller_template_vTST_get_eml_resolved_functions_info();
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

void controller_template_vTST_debug_initialize(void)
{
  _controller_template_vTSTMachineNumber_ = sf_debug_initialize_machine(
    "controller_template_vTST","sfun",0,4,0,0,0);
  sf_debug_set_machine_event_thresholds(_controller_template_vTSTMachineNumber_,
    0,0);
  sf_debug_set_machine_data_thresholds(_controller_template_vTSTMachineNumber_,0);
}

void controller_template_vTST_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_controller_template_vTST_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "controller_template_vTST", "controller_template_vTST");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_controller_template_vTST_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
