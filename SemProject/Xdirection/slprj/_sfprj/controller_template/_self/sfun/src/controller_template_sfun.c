/* Include files */

#include "controller_template_sfun.h"
#include "controller_template_sfun_debug_macros.h"
#include "c1_controller_template.h"
#include "c2_controller_template.h"
#include "c3_controller_template.h"
#include "c4_controller_template.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _controller_templateMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void controller_template_initializer(void)
{
}

void controller_template_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_controller_template_method_dispatcher(SimStruct *simstructPtr,
  unsigned int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_controller_template_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_controller_template_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_controller_template_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_controller_template_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_controller_template_process_check_sum_call( int nlhs, mxArray *
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
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4096661829U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3046912530U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1497739396U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(416021690U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3852296550U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2425392420U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2931271816U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(620759294U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_controller_template_get_check_sum(mxArray *plhs[]);
          sf_c1_controller_template_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_controller_template_get_check_sum(mxArray *plhs[]);
          sf_c2_controller_template_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_controller_template_get_check_sum(mxArray *plhs[]);
          sf_c3_controller_template_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_controller_template_get_check_sum(mxArray *plhs[]);
          sf_c4_controller_template_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1621985301U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(345948149U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(705882661U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3218542080U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1013010614U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1255134792U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4221625494U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4258900578U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_controller_template_autoinheritance_info( int nlhs, mxArray *
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
        if (strcmp(aiChksum, "aFFIXtccfeWJJRVht6VAG") == 0) {
          extern mxArray *sf_c1_controller_template_get_autoinheritance_info
            (void);
          plhs[0] = sf_c1_controller_template_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "A6yq4iHghpdvB9qFVpwCsF") == 0) {
          extern mxArray *sf_c2_controller_template_get_autoinheritance_info
            (void);
          plhs[0] = sf_c2_controller_template_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "22mODf3Ury59sWjdqfxtkG") == 0) {
          extern mxArray *sf_c3_controller_template_get_autoinheritance_info
            (void);
          plhs[0] = sf_c3_controller_template_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "O3FFu5OgiY7cvGVa9ySrnF") == 0) {
          extern mxArray *sf_c4_controller_template_get_autoinheritance_info
            (void);
          plhs[0] = sf_c4_controller_template_get_autoinheritance_info();
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

unsigned int sf_controller_template_get_eml_resolved_functions_info( int nlhs,
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
          *sf_c1_controller_template_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_controller_template_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray
          *sf_c2_controller_template_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_controller_template_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray
          *sf_c3_controller_template_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_controller_template_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray
          *sf_c4_controller_template_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_controller_template_get_eml_resolved_functions_info();
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

unsigned int sf_controller_template_third_party_uses_info( int nlhs, mxArray *
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
        if (strcmp(tpChksum, "GRygl40jww5gijbmVnJ5iC") == 0) {
          extern mxArray *sf_c1_controller_template_third_party_uses_info(void);
          plhs[0] = sf_c1_controller_template_third_party_uses_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "27WViBFcOSJseAr0m5yoaE") == 0) {
          extern mxArray *sf_c2_controller_template_third_party_uses_info(void);
          plhs[0] = sf_c2_controller_template_third_party_uses_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "Lgkvb8MvfQZQSa7AyqgRwB") == 0) {
          extern mxArray *sf_c3_controller_template_third_party_uses_info(void);
          plhs[0] = sf_c3_controller_template_third_party_uses_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "2pQFYuCwdw8qxJwvUufZpE") == 0) {
          extern mxArray *sf_c4_controller_template_third_party_uses_info(void);
          plhs[0] = sf_c4_controller_template_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void controller_template_debug_initialize(struct SfDebugInstanceStruct*
  debugInstance)
{
  _controller_templateMachineNumber_ = sf_debug_initialize_machine(debugInstance,
    "controller_template","sfun",0,4,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _controller_templateMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,
    _controller_templateMachineNumber_,0);
}

void controller_template_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_controller_template_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "controller_template", "controller_template");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_controller_template_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
