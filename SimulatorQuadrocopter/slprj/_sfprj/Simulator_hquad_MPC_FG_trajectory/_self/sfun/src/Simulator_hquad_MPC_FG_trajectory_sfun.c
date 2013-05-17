/* Include files */

#include "Simulator_hquad_MPC_FG_trajectory_sfun.h"
#include "c1_Simulator_hquad_MPC_FG_trajectory.h"
#include "c2_Simulator_hquad_MPC_FG_trajectory.h"
#include "c4_Simulator_hquad_MPC_FG_trajectory.h"
#include "c6_Simulator_hquad_MPC_FG_trajectory.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _Simulator_hquad_MPC_FG_trajectoryMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void Simulator_hquad_MPC_FG_trajectory_initializer(void)
{
}

void Simulator_hquad_MPC_FG_trajectory_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_Simulator_hquad_MPC_FG_trajectory_method_dispatcher(SimStruct
  *simstructPtr, unsigned int chartFileNumber, const char* specsCksum, int_T
  method, void *data)
{
  if (chartFileNumber==1) {
    c1_Simulator_hquad_MPC_FG_trajectory_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_Simulator_hquad_MPC_FG_trajectory_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_Simulator_hquad_MPC_FG_trajectory_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==6) {
    c6_Simulator_hquad_MPC_FG_trajectory_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  return 0;
}

unsigned int sf_Simulator_hquad_MPC_FG_trajectory_process_check_sum_call( int
  nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2600598277U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1947932798U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2642305680U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3630965052U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3969904099U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2197372160U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1759958109U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2148149687U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_Simulator_hquad_MPC_FG_trajectory_get_check_sum
            (mxArray *plhs[]);
          sf_c1_Simulator_hquad_MPC_FG_trajectory_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_Simulator_hquad_MPC_FG_trajectory_get_check_sum
            (mxArray *plhs[]);
          sf_c2_Simulator_hquad_MPC_FG_trajectory_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_Simulator_hquad_MPC_FG_trajectory_get_check_sum
            (mxArray *plhs[]);
          sf_c4_Simulator_hquad_MPC_FG_trajectory_get_check_sum(plhs);
          break;
        }

       case 6:
        {
          extern void sf_c6_Simulator_hquad_MPC_FG_trajectory_get_check_sum
            (mxArray *plhs[]);
          sf_c6_Simulator_hquad_MPC_FG_trajectory_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1764838350U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3410240878U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(118138738U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(243351119U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3492068552U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3690367633U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4125417569U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2931750870U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_Simulator_hquad_MPC_FG_trajectory_autoinheritance_info( int nlhs,
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
        if (strcmp(aiChksum, "1NZmy9QUKO8Wfv2iXGmfmE") == 0) {
          extern mxArray
            *sf_c1_Simulator_hquad_MPC_FG_trajectory_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c1_Simulator_hquad_MPC_FG_trajectory_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "XyCL0xeYkImGQUKVG2ob4E") == 0) {
          extern mxArray
            *sf_c2_Simulator_hquad_MPC_FG_trajectory_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c2_Simulator_hquad_MPC_FG_trajectory_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "OHyhmGlgSOxrtod3vbHBvD") == 0) {
          extern mxArray
            *sf_c4_Simulator_hquad_MPC_FG_trajectory_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c4_Simulator_hquad_MPC_FG_trajectory_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 6:
      {
        if (strcmp(aiChksum, "8s4I6UXYzAm8D2Nb6kPXKC") == 0) {
          extern mxArray
            *sf_c6_Simulator_hquad_MPC_FG_trajectory_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c6_Simulator_hquad_MPC_FG_trajectory_get_autoinheritance_info();
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

unsigned int
  sf_Simulator_hquad_MPC_FG_trajectory_get_eml_resolved_functions_info( int nlhs,
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
          *sf_c1_Simulator_hquad_MPC_FG_trajectory_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_Simulator_hquad_MPC_FG_trajectory_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray
          *sf_c2_Simulator_hquad_MPC_FG_trajectory_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_Simulator_hquad_MPC_FG_trajectory_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray
          *sf_c4_Simulator_hquad_MPC_FG_trajectory_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_Simulator_hquad_MPC_FG_trajectory_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 6:
      {
        extern const mxArray
          *sf_c6_Simulator_hquad_MPC_FG_trajectory_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c6_Simulator_hquad_MPC_FG_trajectory_get_eml_resolved_functions_info
          ();
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

void Simulator_hquad_MPC_FG_trajectory_debug_initialize(void)
{
  _Simulator_hquad_MPC_FG_trajectoryMachineNumber_ = sf_debug_initialize_machine
    ("Simulator_hquad_MPC_FG_trajectory","sfun",0,4,0,0,0);
  sf_debug_set_machine_event_thresholds
    (_Simulator_hquad_MPC_FG_trajectoryMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds
    (_Simulator_hquad_MPC_FG_trajectoryMachineNumber_,0);
}

void Simulator_hquad_MPC_FG_trajectory_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_Simulator_hquad_MPC_FG_trajectory_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "Simulator_hquad_MPC_FG_trajectory", "Simulator_hquad_MPC_FG_trajectory");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_Simulator_hquad_MPC_FG_trajectory_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
