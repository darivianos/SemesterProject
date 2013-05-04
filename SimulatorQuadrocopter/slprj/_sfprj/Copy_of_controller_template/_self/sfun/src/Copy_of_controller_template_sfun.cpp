/* Include files */

#include "Copy_of_controller_template_sfun.h"
#include "c1_Copy_of_controller_template.h"
#include "c2_Copy_of_controller_template.h"
#include "c3_Copy_of_controller_template.h"
#include "c4_Copy_of_controller_template.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _Copy_of_controller_templateMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void Copy_of_controller_template_initializer(void)
{
}

void Copy_of_controller_template_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_Copy_of_controller_template_method_dispatcher(SimStruct
  *simstructPtr, unsigned int chartFileNumber, const char* specsCksum, int_T
  method, void *data)
{
  if (chartFileNumber==1) {
    c1_Copy_of_controller_template_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_Copy_of_controller_template_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_Copy_of_controller_template_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_Copy_of_controller_template_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_Copy_of_controller_template_process_testpoint_info_call( int
  nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
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
  if (!strcmp(machineName, "Copy_of_controller_template")) {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
    switch (chartFileNumber) {
     case 1:
      {
        extern mxArray *sf_c1_Copy_of_controller_template_get_testpoint_info
          (void);
        plhs[0] = sf_c1_Copy_of_controller_template_get_testpoint_info();
        break;
      }

     case 2:
      {
        extern mxArray *sf_c2_Copy_of_controller_template_get_testpoint_info
          (void);
        plhs[0] = sf_c2_Copy_of_controller_template_get_testpoint_info();
        break;
      }

     case 3:
      {
        extern mxArray *sf_c3_Copy_of_controller_template_get_testpoint_info
          (void);
        plhs[0] = sf_c3_Copy_of_controller_template_get_testpoint_info();
        break;
      }

     case 4:
      {
        extern mxArray *sf_c4_Copy_of_controller_template_get_testpoint_info
          (void);
        plhs[0] = sf_c4_Copy_of_controller_template_get_testpoint_info();
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

unsigned int sf_Copy_of_controller_template_process_check_sum_call( int nlhs,
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2485104754U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3111899582U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4277172120U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(618358296U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2762026960U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2332019169U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2421387892U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1518196088U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_Copy_of_controller_template_get_check_sum(mxArray
            *plhs[]);
          sf_c1_Copy_of_controller_template_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_Copy_of_controller_template_get_check_sum(mxArray
            *plhs[]);
          sf_c2_Copy_of_controller_template_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_Copy_of_controller_template_get_check_sum(mxArray
            *plhs[]);
          sf_c3_Copy_of_controller_template_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_Copy_of_controller_template_get_check_sum(mxArray
            *plhs[]);
          sf_c4_Copy_of_controller_template_get_check_sum(plhs);
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
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3812277949U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(576730291U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2697755078U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(249308539U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_Copy_of_controller_template_autoinheritance_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
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
        if (strcmp(aiChksum, "LGZ4iMGM5zWQjS1DCBXhSE") == 0) {
          extern mxArray
            *sf_c1_Copy_of_controller_template_get_autoinheritance_info(void);
          plhs[0] = sf_c1_Copy_of_controller_template_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "qI4P3iLE8e7I3QzRPdy5fE") == 0) {
          extern mxArray
            *sf_c2_Copy_of_controller_template_get_autoinheritance_info(void);
          plhs[0] = sf_c2_Copy_of_controller_template_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "YnogJaQXI8p5UuphmhhyDB") == 0) {
          extern mxArray
            *sf_c3_Copy_of_controller_template_get_autoinheritance_info(void);
          plhs[0] = sf_c3_Copy_of_controller_template_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "ekZxSgXMhkGSTeJX8mCnKF") == 0) {
          extern mxArray
            *sf_c4_Copy_of_controller_template_get_autoinheritance_info(void);
          plhs[0] = sf_c4_Copy_of_controller_template_get_autoinheritance_info();
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

unsigned int sf_Copy_of_controller_template_get_eml_resolved_functions_info( int
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
          *sf_c1_Copy_of_controller_template_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_Copy_of_controller_template_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray
          *sf_c2_Copy_of_controller_template_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_Copy_of_controller_template_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray
          *sf_c3_Copy_of_controller_template_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_Copy_of_controller_template_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray
          *sf_c4_Copy_of_controller_template_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_Copy_of_controller_template_get_eml_resolved_functions_info();
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

void Copy_of_controller_template_debug_initialize(void)
{
  _Copy_of_controller_templateMachineNumber_ = sf_debug_initialize_machine(
    "Copy_of_controller_template","sfun",0,4,0,0,0);
  sf_debug_set_machine_event_thresholds
    (_Copy_of_controller_templateMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds
    (_Copy_of_controller_templateMachineNumber_,0);
}

void Copy_of_controller_template_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_Copy_of_controller_template_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "Copy_of_controller_template", "Copy_of_controller_template");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_Copy_of_controller_template_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
