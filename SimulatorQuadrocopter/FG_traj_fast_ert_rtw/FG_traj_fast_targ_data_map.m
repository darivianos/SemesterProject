  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 8;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (FG_traj_fast_P)
    ;%
      section.nData     = 35;
      section.data(35)  = dumData; %prealloc
      
	  ;% FG_traj_fast_P.yaw_rate_bias_Value
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% FG_traj_fast_P.thrust_bias_Value
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% FG_traj_fast_P.roll_bias_Value
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% FG_traj_fast_P.pitch_bias_Value
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% FG_traj_fast_P.yaw_Value
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% FG_traj_fast_P.gravity_Value
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% FG_traj_fast_P.roll_Value
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% FG_traj_fast_P.pitch_Value
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% FG_traj_fast_P.g_Value
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% FG_traj_fast_P.raddeg2_Gain
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% FG_traj_fast_P.raddeg1_Gain
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% FG_traj_fast_P.raddeg3_Gain
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% FG_traj_fast_P.raddeg_Gain
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% FG_traj_fast_P.g_Value_c
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% FG_traj_fast_P.raddeg2_Gain_p
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% FG_traj_fast_P.raddeg1_Gain_a
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% FG_traj_fast_P.raddeg3_Gain_m
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 16;
	
	  ;% FG_traj_fast_P.raddeg_Gain_b
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 17;
	
	  ;% FG_traj_fast_P.pitch_offset_Value
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 18;
	
	  ;% FG_traj_fast_P.InitialCondition_Value
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 19;
	
	  ;% FG_traj_fast_P.Constant1_Value
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 20;
	
	  ;% FG_traj_fast_P.Constant2_Value
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 21;
	
	  ;% FG_traj_fast_P.FixPtUnitDelay1_InitialConditio
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 22;
	
	  ;% FG_traj_fast_P.pitch_cmd2pitch_Gain
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 23;
	
	  ;% FG_traj_fast_P.Gain1_Gain
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 24;
	
	  ;% FG_traj_fast_P.roll_offset_Value
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 25;
	
	  ;% FG_traj_fast_P.roll_cmd2roll_Gain
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 26;
	
	  ;% FG_traj_fast_P.Gain2_Gain
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 27;
	
	  ;% FG_traj_fast_P.gravity_Value_b
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 28;
	
	  ;% FG_traj_fast_P.trhust_cmd2thrust_Gain
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 29;
	
	  ;% FG_traj_fast_P.Gain_Gain
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 30;
	
	  ;% FG_traj_fast_P.Gain3_Gain
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 31;
	
	  ;% FG_traj_fast_P.yaw_cmd2yaw_Gain
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 32;
	
	  ;% FG_traj_fast_P.yaw_rate_Value
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 33;
	
	  ;% FG_traj_fast_P.Gain4_Gain
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 34;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% FG_traj_fast_P.FixPtUnitDelay2_InitialConditio
	  section.data(1).logicalSrcIdx = 35;
	  section.data(1).dtTransOffset = 0;
	
	  ;% FG_traj_fast_P.ManualSwitch_CurrentSetting
	  section.data(2).logicalSrcIdx = 36;
	  section.data(2).dtTransOffset = 1;
	
	  ;% FG_traj_fast_P.FixPtConstant_Value
	  section.data(3).logicalSrcIdx = 37;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 101;
      section.data(101)  = dumData; %prealloc
      
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.IntegerDelay_InitialCondition
	  section.data(1).logicalSrcIdx = 38;
	  section.data(1).dtTransOffset = 0;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.IntegerDelay1_InitialCondition
	  section.data(2).logicalSrcIdx = 39;
	  section.data(2).dtTransOffset = 1;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.IntegerDelay2_InitialCondition
	  section.data(3).logicalSrcIdx = 40;
	  section.data(3).dtTransOffset = 2;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.IntegerDelay3_InitialCondition
	  section.data(4).logicalSrcIdx = 41;
	  section.data(4).dtTransOffset = 3;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.gravity_Value
	  section.data(5).logicalSrcIdx = 42;
	  section.data(5).dtTransOffset = 4;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.TT_PP_Value
	  section.data(6).logicalSrcIdx = 43;
	  section.data(6).dtTransOffset = 5;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.LL_PP_Value
	  section.data(7).logicalSrcIdx = 44;
	  section.data(7).dtTransOffset = 905;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.LL_ref_PP_Value
	  section.data(8).logicalSrcIdx = 45;
	  section.data(8).dtTransOffset = 995;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.LL_U_ref_PP_Value
	  section.data(9).logicalSrcIdx = 46;
	  section.data(9).dtTransOffset = 3785;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.MM_Value
	  section.data(10).logicalSrcIdx = 47;
	  section.data(10).dtTransOffset = 4685;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.PP_Value
	  section.data(11).logicalSrcIdx = 48;
	  section.data(11).dtTransOffset = 4694;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.AA_delay_Value
	  section.data(12).logicalSrcIdx = 49;
	  section.data(12).dtTransOffset = 5594;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.BB_delay_Value
	  section.data(13).logicalSrcIdx = 50;
	  section.data(13).dtTransOffset = 5603;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.A_Value
	  section.data(14).logicalSrcIdx = 51;
	  section.data(14).dtTransOffset = 5612;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.B_Value
	  section.data(15).logicalSrcIdx = 52;
	  section.data(15).dtTransOffset = 5628;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.C_Value
	  section.data(16).logicalSrcIdx = 53;
	  section.data(16).dtTransOffset = 5632;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.D_Value
	  section.data(17).logicalSrcIdx = 54;
	  section.data(17).dtTransOffset = 5644;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.Q_Value
	  section.data(18).logicalSrcIdx = 55;
	  section.data(18).dtTransOffset = 5647;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.R_Value
	  section.data(19).logicalSrcIdx = 56;
	  section.data(19).dtTransOffset = 5663;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.UnitDelay1_InitialCondition
	  section.data(20).logicalSrcIdx = 57;
	  section.data(20).dtTransOffset = 5672;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.FixPtUnitDelay1_InitialConditio
	  section.data(21).logicalSrcIdx = 58;
	  section.data(21).dtTransOffset = 5688;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.V_max_Value
	  section.data(22).logicalSrcIdx = 59;
	  section.data(22).dtTransOffset = 5689;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.i_min_Value
	  section.data(23).logicalSrcIdx = 60;
	  section.data(23).dtTransOffset = 5719;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.betas_Value
	  section.data(24).logicalSrcIdx = 61;
	  section.data(24).dtTransOffset = 5720;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.L_Value
	  section.data(25).logicalSrcIdx = 62;
	  section.data(25).dtTransOffset = 5727;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.UnitDelay_InitialCondition
	  section.data(26).logicalSrcIdx = 63;
	  section.data(26).dtTransOffset = 5728;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.UnitDelay1_InitialCondition_h
	  section.data(27).logicalSrcIdx = 64;
	  section.data(27).dtTransOffset = 5731;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.Saturation_UpperSat
	  section.data(28).logicalSrcIdx = 65;
	  section.data(28).dtTransOffset = 5761;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.Saturation_LowerSat
	  section.data(29).logicalSrcIdx = 66;
	  section.data(29).dtTransOffset = 5762;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.TT_PP_Value_n
	  section.data(30).logicalSrcIdx = 67;
	  section.data(30).dtTransOffset = 5763;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.LL_PP_Value_h
	  section.data(31).logicalSrcIdx = 68;
	  section.data(31).dtTransOffset = 6663;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.LL_ref_PP_Value_l
	  section.data(32).logicalSrcIdx = 69;
	  section.data(32).dtTransOffset = 6753;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.LL_U_ref_PP_Value_h
	  section.data(33).logicalSrcIdx = 70;
	  section.data(33).dtTransOffset = 9543;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.MM_Value_n
	  section.data(34).logicalSrcIdx = 71;
	  section.data(34).dtTransOffset = 10443;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.PP_Value_a
	  section.data(35).logicalSrcIdx = 72;
	  section.data(35).dtTransOffset = 10452;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.AA_delay_Value_j
	  section.data(36).logicalSrcIdx = 73;
	  section.data(36).dtTransOffset = 11352;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.BB_delay_Value_c
	  section.data(37).logicalSrcIdx = 74;
	  section.data(37).dtTransOffset = 11361;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.A_Value_g
	  section.data(38).logicalSrcIdx = 75;
	  section.data(38).dtTransOffset = 11370;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.B_Value_f
	  section.data(39).logicalSrcIdx = 76;
	  section.data(39).dtTransOffset = 11386;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.C_Value_m
	  section.data(40).logicalSrcIdx = 77;
	  section.data(40).dtTransOffset = 11390;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.D_Value_f
	  section.data(41).logicalSrcIdx = 78;
	  section.data(41).dtTransOffset = 11402;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.Q_Value_h
	  section.data(42).logicalSrcIdx = 79;
	  section.data(42).dtTransOffset = 11405;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.R_Value_e
	  section.data(43).logicalSrcIdx = 80;
	  section.data(43).dtTransOffset = 11421;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.UnitDelay1_InitialCondition_b
	  section.data(44).logicalSrcIdx = 81;
	  section.data(44).dtTransOffset = 11430;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.FixPtUnitDelay1_InitialCondit_m
	  section.data(45).logicalSrcIdx = 82;
	  section.data(45).dtTransOffset = 11446;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.V_max_Value_g
	  section.data(46).logicalSrcIdx = 83;
	  section.data(46).dtTransOffset = 11447;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.i_min_Value_l
	  section.data(47).logicalSrcIdx = 84;
	  section.data(47).dtTransOffset = 11477;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.betas_Value_m
	  section.data(48).logicalSrcIdx = 85;
	  section.data(48).dtTransOffset = 11478;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.L_Value_g
	  section.data(49).logicalSrcIdx = 86;
	  section.data(49).dtTransOffset = 11485;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.UnitDelay_InitialCondition_n
	  section.data(50).logicalSrcIdx = 87;
	  section.data(50).dtTransOffset = 11486;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.UnitDelay1_InitialCondition_o
	  section.data(51).logicalSrcIdx = 88;
	  section.data(51).dtTransOffset = 11489;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.Saturation_UpperSat_f
	  section.data(52).logicalSrcIdx = 89;
	  section.data(52).dtTransOffset = 11519;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.Saturation_LowerSat_c
	  section.data(53).logicalSrcIdx = 90;
	  section.data(53).dtTransOffset = 11520;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.TT_PP_Value_e
	  section.data(54).logicalSrcIdx = 91;
	  section.data(54).dtTransOffset = 11521;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.LL_PP_Value_l
	  section.data(55).logicalSrcIdx = 92;
	  section.data(55).dtTransOffset = 12421;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.LL_ref_PP_Value_d
	  section.data(56).logicalSrcIdx = 93;
	  section.data(56).dtTransOffset = 12481;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.LL_U_ref_PP_Value_k
	  section.data(57).logicalSrcIdx = 94;
	  section.data(57).dtTransOffset = 14341;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.MM_Value_i
	  section.data(58).logicalSrcIdx = 95;
	  section.data(58).dtTransOffset = 15241;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.PP_Value_m
	  section.data(59).logicalSrcIdx = 96;
	  section.data(59).dtTransOffset = 15245;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.AA_delay_Value_f
	  section.data(60).logicalSrcIdx = 97;
	  section.data(60).dtTransOffset = 16145;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.BB_delay_Value_n
	  section.data(61).logicalSrcIdx = 98;
	  section.data(61).dtTransOffset = 16149;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.A_Value_e
	  section.data(62).logicalSrcIdx = 99;
	  section.data(62).dtTransOffset = 16153;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.B_Value_k
	  section.data(63).logicalSrcIdx = 100;
	  section.data(63).dtTransOffset = 16162;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.C_Value_p
	  section.data(64).logicalSrcIdx = 101;
	  section.data(64).dtTransOffset = 16165;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.D_Value_k
	  section.data(65).logicalSrcIdx = 102;
	  section.data(65).dtTransOffset = 16171;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.Q_Value_g
	  section.data(66).logicalSrcIdx = 103;
	  section.data(66).dtTransOffset = 16173;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.R_Value_c
	  section.data(67).logicalSrcIdx = 104;
	  section.data(67).dtTransOffset = 16182;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.UnitDelay1_InitialCondition_ou
	  section.data(68).logicalSrcIdx = 105;
	  section.data(68).dtTransOffset = 16186;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.FixPtUnitDelay1_InitialCondit_p
	  section.data(69).logicalSrcIdx = 106;
	  section.data(69).dtTransOffset = 16195;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.V_max_Value_a
	  section.data(70).logicalSrcIdx = 107;
	  section.data(70).dtTransOffset = 16196;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.i_min_Value_p
	  section.data(71).logicalSrcIdx = 108;
	  section.data(71).dtTransOffset = 16226;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.betas_Value_o
	  section.data(72).logicalSrcIdx = 109;
	  section.data(72).dtTransOffset = 16227;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.L_Value_j
	  section.data(73).logicalSrcIdx = 110;
	  section.data(73).dtTransOffset = 16235;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.UnitDelay_InitialCondition_f
	  section.data(74).logicalSrcIdx = 111;
	  section.data(74).dtTransOffset = 16236;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.UnitDelay1_InitialCondition_m
	  section.data(75).logicalSrcIdx = 112;
	  section.data(75).dtTransOffset = 16238;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.Saturation_UpperSat_j
	  section.data(76).logicalSrcIdx = 113;
	  section.data(76).dtTransOffset = 16268;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.Saturation_LowerSat_cp
	  section.data(77).logicalSrcIdx = 114;
	  section.data(77).dtTransOffset = 16269;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.TT_PP_Value_ew
	  section.data(78).logicalSrcIdx = 115;
	  section.data(78).dtTransOffset = 16270;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.LL_PP_Value_o
	  section.data(79).logicalSrcIdx = 116;
	  section.data(79).dtTransOffset = 17170;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.LL_ref_PP_Value_b
	  section.data(80).logicalSrcIdx = 117;
	  section.data(80).dtTransOffset = 17230;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.LL_U_ref_PP_Value_g
	  section.data(81).logicalSrcIdx = 118;
	  section.data(81).dtTransOffset = 19090;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.MM_Value_m
	  section.data(82).logicalSrcIdx = 119;
	  section.data(82).dtTransOffset = 19990;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.PP_Value_i
	  section.data(83).logicalSrcIdx = 120;
	  section.data(83).dtTransOffset = 19994;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.AA_delay_Value_e
	  section.data(84).logicalSrcIdx = 121;
	  section.data(84).dtTransOffset = 20894;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.BB_delay_Value_j
	  section.data(85).logicalSrcIdx = 122;
	  section.data(85).dtTransOffset = 20898;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.A_Value_gk
	  section.data(86).logicalSrcIdx = 123;
	  section.data(86).dtTransOffset = 20910;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.B_Value_ke
	  section.data(87).logicalSrcIdx = 124;
	  section.data(87).dtTransOffset = 20919;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.C_Value_c
	  section.data(88).logicalSrcIdx = 125;
	  section.data(88).dtTransOffset = 20922;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.D_Value_h
	  section.data(89).logicalSrcIdx = 126;
	  section.data(89).dtTransOffset = 20928;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.Q_Value_n
	  section.data(90).logicalSrcIdx = 127;
	  section.data(90).dtTransOffset = 20930;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.R_Value_k
	  section.data(91).logicalSrcIdx = 128;
	  section.data(91).dtTransOffset = 20939;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.UnitDelay1_InitialCondition_oo
	  section.data(92).logicalSrcIdx = 129;
	  section.data(92).dtTransOffset = 20943;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.FixPtUnitDelay1_InitialCondit_k
	  section.data(93).logicalSrcIdx = 130;
	  section.data(93).dtTransOffset = 20952;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.V_max_Value_h
	  section.data(94).logicalSrcIdx = 131;
	  section.data(94).dtTransOffset = 20953;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.i_min_Value_a
	  section.data(95).logicalSrcIdx = 132;
	  section.data(95).dtTransOffset = 20983;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.betas_Value_o5
	  section.data(96).logicalSrcIdx = 133;
	  section.data(96).dtTransOffset = 20984;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.L_Value_jd
	  section.data(97).logicalSrcIdx = 134;
	  section.data(97).dtTransOffset = 20989;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.UnitDelay_InitialCondition_k
	  section.data(98).logicalSrcIdx = 135;
	  section.data(98).dtTransOffset = 20990;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.UnitDelay1_InitialCondition_g
	  section.data(99).logicalSrcIdx = 136;
	  section.data(99).dtTransOffset = 20996;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.Saturation_UpperSat_o
	  section.data(100).logicalSrcIdx = 137;
	  section.data(100).dtTransOffset = 21026;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.Saturation_LowerSat_k
	  section.data(101).logicalSrcIdx = 138;
	  section.data(101).dtTransOffset = 21027;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.IntegerDelay_DelayLength
	  section.data(1).logicalSrcIdx = 139;
	  section.data(1).dtTransOffset = 0;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.IntegerDelay1_DelayLength
	  section.data(2).logicalSrcIdx = 140;
	  section.data(2).dtTransOffset = 1;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.IntegerDelay2_DelayLength
	  section.data(3).logicalSrcIdx = 141;
	  section.data(3).dtTransOffset = 2;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.IntegerDelay3_DelayLength
	  section.data(4).logicalSrcIdx = 142;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.FixPtUnitDelay2_InitialConditio
	  section.data(1).logicalSrcIdx = 143;
	  section.data(1).dtTransOffset = 0;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.FixPtUnitDelay2_InitialCondit_d
	  section.data(2).logicalSrcIdx = 144;
	  section.data(2).dtTransOffset = 1;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.FixPtUnitDelay2_InitialCondit_b
	  section.data(3).logicalSrcIdx = 145;
	  section.data(3).dtTransOffset = 2;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.FixPtUnitDelay2_InitialCondit_i
	  section.data(4).logicalSrcIdx = 146;
	  section.data(4).dtTransOffset = 3;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.FixPtConstant_Value
	  section.data(5).logicalSrcIdx = 147;
	  section.data(5).dtTransOffset = 4;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.FixPtConstant_Value_p
	  section.data(6).logicalSrcIdx = 148;
	  section.data(6).dtTransOffset = 5;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.FixPtConstant_Value_p5
	  section.data(7).logicalSrcIdx = 149;
	  section.data(7).dtTransOffset = 6;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1_c.FixPtConstant_Value_j
	  section.data(8).logicalSrcIdx = 150;
	  section.data(8).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 101;
      section.data(101)  = dumData; %prealloc
      
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.IntegerDelay_InitialCondition
	  section.data(1).logicalSrcIdx = 151;
	  section.data(1).dtTransOffset = 0;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.IntegerDelay1_InitialCondition
	  section.data(2).logicalSrcIdx = 152;
	  section.data(2).dtTransOffset = 1;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.IntegerDelay2_InitialCondition
	  section.data(3).logicalSrcIdx = 153;
	  section.data(3).dtTransOffset = 2;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.IntegerDelay3_InitialCondition
	  section.data(4).logicalSrcIdx = 154;
	  section.data(4).dtTransOffset = 3;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.gravity_Value
	  section.data(5).logicalSrcIdx = 155;
	  section.data(5).dtTransOffset = 4;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.TT_PP_Value
	  section.data(6).logicalSrcIdx = 156;
	  section.data(6).dtTransOffset = 5;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.LL_PP_Value
	  section.data(7).logicalSrcIdx = 157;
	  section.data(7).dtTransOffset = 905;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.LL_ref_PP_Value
	  section.data(8).logicalSrcIdx = 158;
	  section.data(8).dtTransOffset = 995;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.LL_U_ref_PP_Value
	  section.data(9).logicalSrcIdx = 159;
	  section.data(9).dtTransOffset = 3785;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.MM_Value
	  section.data(10).logicalSrcIdx = 160;
	  section.data(10).dtTransOffset = 4685;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.PP_Value
	  section.data(11).logicalSrcIdx = 161;
	  section.data(11).dtTransOffset = 4694;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.AA_delay_Value
	  section.data(12).logicalSrcIdx = 162;
	  section.data(12).dtTransOffset = 5594;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.BB_delay_Value
	  section.data(13).logicalSrcIdx = 163;
	  section.data(13).dtTransOffset = 5603;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.A_Value
	  section.data(14).logicalSrcIdx = 164;
	  section.data(14).dtTransOffset = 5612;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.B_Value
	  section.data(15).logicalSrcIdx = 165;
	  section.data(15).dtTransOffset = 5628;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.C_Value
	  section.data(16).logicalSrcIdx = 166;
	  section.data(16).dtTransOffset = 5632;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.D_Value
	  section.data(17).logicalSrcIdx = 167;
	  section.data(17).dtTransOffset = 5644;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.Q_Value
	  section.data(18).logicalSrcIdx = 168;
	  section.data(18).dtTransOffset = 5647;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.R_Value
	  section.data(19).logicalSrcIdx = 169;
	  section.data(19).dtTransOffset = 5663;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.UnitDelay1_InitialCondition
	  section.data(20).logicalSrcIdx = 170;
	  section.data(20).dtTransOffset = 5672;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.FixPtUnitDelay1_InitialConditio
	  section.data(21).logicalSrcIdx = 171;
	  section.data(21).dtTransOffset = 5688;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.V_max_Value
	  section.data(22).logicalSrcIdx = 172;
	  section.data(22).dtTransOffset = 5689;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.i_min_Value
	  section.data(23).logicalSrcIdx = 173;
	  section.data(23).dtTransOffset = 5719;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.betas_Value
	  section.data(24).logicalSrcIdx = 174;
	  section.data(24).dtTransOffset = 5720;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.L_Value
	  section.data(25).logicalSrcIdx = 175;
	  section.data(25).dtTransOffset = 5727;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.UnitDelay_InitialCondition
	  section.data(26).logicalSrcIdx = 176;
	  section.data(26).dtTransOffset = 5728;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.UnitDelay1_InitialCondition_h
	  section.data(27).logicalSrcIdx = 177;
	  section.data(27).dtTransOffset = 5731;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.Saturation_UpperSat
	  section.data(28).logicalSrcIdx = 178;
	  section.data(28).dtTransOffset = 5761;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.Saturation_LowerSat
	  section.data(29).logicalSrcIdx = 179;
	  section.data(29).dtTransOffset = 5762;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.TT_PP_Value_n
	  section.data(30).logicalSrcIdx = 180;
	  section.data(30).dtTransOffset = 5763;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.LL_PP_Value_h
	  section.data(31).logicalSrcIdx = 181;
	  section.data(31).dtTransOffset = 6663;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.LL_ref_PP_Value_l
	  section.data(32).logicalSrcIdx = 182;
	  section.data(32).dtTransOffset = 6753;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.LL_U_ref_PP_Value_h
	  section.data(33).logicalSrcIdx = 183;
	  section.data(33).dtTransOffset = 9543;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.MM_Value_n
	  section.data(34).logicalSrcIdx = 184;
	  section.data(34).dtTransOffset = 10443;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.PP_Value_a
	  section.data(35).logicalSrcIdx = 185;
	  section.data(35).dtTransOffset = 10452;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.AA_delay_Value_j
	  section.data(36).logicalSrcIdx = 186;
	  section.data(36).dtTransOffset = 11352;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.BB_delay_Value_c
	  section.data(37).logicalSrcIdx = 187;
	  section.data(37).dtTransOffset = 11361;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.A_Value_g
	  section.data(38).logicalSrcIdx = 188;
	  section.data(38).dtTransOffset = 11370;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.B_Value_f
	  section.data(39).logicalSrcIdx = 189;
	  section.data(39).dtTransOffset = 11386;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.C_Value_m
	  section.data(40).logicalSrcIdx = 190;
	  section.data(40).dtTransOffset = 11390;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.D_Value_f
	  section.data(41).logicalSrcIdx = 191;
	  section.data(41).dtTransOffset = 11402;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.Q_Value_h
	  section.data(42).logicalSrcIdx = 192;
	  section.data(42).dtTransOffset = 11405;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.R_Value_e
	  section.data(43).logicalSrcIdx = 193;
	  section.data(43).dtTransOffset = 11421;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.UnitDelay1_InitialCondition_b
	  section.data(44).logicalSrcIdx = 194;
	  section.data(44).dtTransOffset = 11430;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.FixPtUnitDelay1_InitialCondit_m
	  section.data(45).logicalSrcIdx = 195;
	  section.data(45).dtTransOffset = 11446;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.V_max_Value_g
	  section.data(46).logicalSrcIdx = 196;
	  section.data(46).dtTransOffset = 11447;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.i_min_Value_l
	  section.data(47).logicalSrcIdx = 197;
	  section.data(47).dtTransOffset = 11477;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.betas_Value_m
	  section.data(48).logicalSrcIdx = 198;
	  section.data(48).dtTransOffset = 11478;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.L_Value_g
	  section.data(49).logicalSrcIdx = 199;
	  section.data(49).dtTransOffset = 11485;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.UnitDelay_InitialCondition_n
	  section.data(50).logicalSrcIdx = 200;
	  section.data(50).dtTransOffset = 11486;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.UnitDelay1_InitialCondition_o
	  section.data(51).logicalSrcIdx = 201;
	  section.data(51).dtTransOffset = 11489;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.Saturation_UpperSat_f
	  section.data(52).logicalSrcIdx = 202;
	  section.data(52).dtTransOffset = 11519;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.Saturation_LowerSat_c
	  section.data(53).logicalSrcIdx = 203;
	  section.data(53).dtTransOffset = 11520;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.TT_PP_Value_e
	  section.data(54).logicalSrcIdx = 204;
	  section.data(54).dtTransOffset = 11521;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.LL_PP_Value_l
	  section.data(55).logicalSrcIdx = 205;
	  section.data(55).dtTransOffset = 12421;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.LL_ref_PP_Value_d
	  section.data(56).logicalSrcIdx = 206;
	  section.data(56).dtTransOffset = 12481;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.LL_U_ref_PP_Value_k
	  section.data(57).logicalSrcIdx = 207;
	  section.data(57).dtTransOffset = 14341;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.MM_Value_i
	  section.data(58).logicalSrcIdx = 208;
	  section.data(58).dtTransOffset = 15241;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.PP_Value_m
	  section.data(59).logicalSrcIdx = 209;
	  section.data(59).dtTransOffset = 15245;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.AA_delay_Value_f
	  section.data(60).logicalSrcIdx = 210;
	  section.data(60).dtTransOffset = 16145;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.BB_delay_Value_n
	  section.data(61).logicalSrcIdx = 211;
	  section.data(61).dtTransOffset = 16149;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.A_Value_e
	  section.data(62).logicalSrcIdx = 212;
	  section.data(62).dtTransOffset = 16153;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.B_Value_k
	  section.data(63).logicalSrcIdx = 213;
	  section.data(63).dtTransOffset = 16162;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.C_Value_p
	  section.data(64).logicalSrcIdx = 214;
	  section.data(64).dtTransOffset = 16165;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.D_Value_k
	  section.data(65).logicalSrcIdx = 215;
	  section.data(65).dtTransOffset = 16171;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.Q_Value_g
	  section.data(66).logicalSrcIdx = 216;
	  section.data(66).dtTransOffset = 16173;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.R_Value_c
	  section.data(67).logicalSrcIdx = 217;
	  section.data(67).dtTransOffset = 16182;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.UnitDelay1_InitialCondition_ou
	  section.data(68).logicalSrcIdx = 218;
	  section.data(68).dtTransOffset = 16186;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.FixPtUnitDelay1_InitialCondit_p
	  section.data(69).logicalSrcIdx = 219;
	  section.data(69).dtTransOffset = 16195;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.V_max_Value_a
	  section.data(70).logicalSrcIdx = 220;
	  section.data(70).dtTransOffset = 16196;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.i_min_Value_p
	  section.data(71).logicalSrcIdx = 221;
	  section.data(71).dtTransOffset = 16226;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.betas_Value_o
	  section.data(72).logicalSrcIdx = 222;
	  section.data(72).dtTransOffset = 16227;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.L_Value_j
	  section.data(73).logicalSrcIdx = 223;
	  section.data(73).dtTransOffset = 16235;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.UnitDelay_InitialCondition_f
	  section.data(74).logicalSrcIdx = 224;
	  section.data(74).dtTransOffset = 16236;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.UnitDelay1_InitialCondition_m
	  section.data(75).logicalSrcIdx = 225;
	  section.data(75).dtTransOffset = 16238;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.Saturation_UpperSat_j
	  section.data(76).logicalSrcIdx = 226;
	  section.data(76).dtTransOffset = 16268;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.Saturation_LowerSat_cp
	  section.data(77).logicalSrcIdx = 227;
	  section.data(77).dtTransOffset = 16269;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.TT_PP_Value_ew
	  section.data(78).logicalSrcIdx = 228;
	  section.data(78).dtTransOffset = 16270;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.LL_PP_Value_o
	  section.data(79).logicalSrcIdx = 229;
	  section.data(79).dtTransOffset = 17170;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.LL_ref_PP_Value_b
	  section.data(80).logicalSrcIdx = 230;
	  section.data(80).dtTransOffset = 17230;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.LL_U_ref_PP_Value_g
	  section.data(81).logicalSrcIdx = 231;
	  section.data(81).dtTransOffset = 19090;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.MM_Value_m
	  section.data(82).logicalSrcIdx = 232;
	  section.data(82).dtTransOffset = 19990;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.PP_Value_i
	  section.data(83).logicalSrcIdx = 233;
	  section.data(83).dtTransOffset = 19994;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.AA_delay_Value_e
	  section.data(84).logicalSrcIdx = 234;
	  section.data(84).dtTransOffset = 20894;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.BB_delay_Value_j
	  section.data(85).logicalSrcIdx = 235;
	  section.data(85).dtTransOffset = 20898;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.A_Value_gk
	  section.data(86).logicalSrcIdx = 236;
	  section.data(86).dtTransOffset = 20910;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.B_Value_ke
	  section.data(87).logicalSrcIdx = 237;
	  section.data(87).dtTransOffset = 20919;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.C_Value_c
	  section.data(88).logicalSrcIdx = 238;
	  section.data(88).dtTransOffset = 20922;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.D_Value_h
	  section.data(89).logicalSrcIdx = 239;
	  section.data(89).dtTransOffset = 20928;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.Q_Value_n
	  section.data(90).logicalSrcIdx = 240;
	  section.data(90).dtTransOffset = 20930;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.R_Value_k
	  section.data(91).logicalSrcIdx = 241;
	  section.data(91).dtTransOffset = 20939;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.UnitDelay1_InitialCondition_oo
	  section.data(92).logicalSrcIdx = 242;
	  section.data(92).dtTransOffset = 20943;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.FixPtUnitDelay1_InitialCondit_k
	  section.data(93).logicalSrcIdx = 243;
	  section.data(93).dtTransOffset = 20952;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.V_max_Value_h
	  section.data(94).logicalSrcIdx = 244;
	  section.data(94).dtTransOffset = 20953;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.i_min_Value_a
	  section.data(95).logicalSrcIdx = 245;
	  section.data(95).dtTransOffset = 20983;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.betas_Value_o5
	  section.data(96).logicalSrcIdx = 246;
	  section.data(96).dtTransOffset = 20984;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.L_Value_jd
	  section.data(97).logicalSrcIdx = 247;
	  section.data(97).dtTransOffset = 20989;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.UnitDelay_InitialCondition_k
	  section.data(98).logicalSrcIdx = 248;
	  section.data(98).dtTransOffset = 20990;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.UnitDelay1_InitialCondition_g
	  section.data(99).logicalSrcIdx = 249;
	  section.data(99).dtTransOffset = 20996;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.Saturation_UpperSat_o
	  section.data(100).logicalSrcIdx = 250;
	  section.data(100).dtTransOffset = 21026;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.Saturation_LowerSat_k
	  section.data(101).logicalSrcIdx = 251;
	  section.data(101).dtTransOffset = 21027;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.IntegerDelay_DelayLength
	  section.data(1).logicalSrcIdx = 252;
	  section.data(1).dtTransOffset = 0;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.IntegerDelay1_DelayLength
	  section.data(2).logicalSrcIdx = 253;
	  section.data(2).dtTransOffset = 1;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.IntegerDelay2_DelayLength
	  section.data(3).logicalSrcIdx = 254;
	  section.data(3).dtTransOffset = 2;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.IntegerDelay3_DelayLength
	  section.data(4).logicalSrcIdx = 255;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(7) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.FixPtUnitDelay2_InitialConditio
	  section.data(1).logicalSrcIdx = 256;
	  section.data(1).dtTransOffset = 0;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.FixPtUnitDelay2_InitialCondit_d
	  section.data(2).logicalSrcIdx = 257;
	  section.data(2).dtTransOffset = 1;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.FixPtUnitDelay2_InitialCondit_b
	  section.data(3).logicalSrcIdx = 258;
	  section.data(3).dtTransOffset = 2;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.FixPtUnitDelay2_InitialCondit_i
	  section.data(4).logicalSrcIdx = 259;
	  section.data(4).dtTransOffset = 3;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.FixPtConstant_Value
	  section.data(5).logicalSrcIdx = 260;
	  section.data(5).dtTransOffset = 4;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.FixPtConstant_Value_p
	  section.data(6).logicalSrcIdx = 261;
	  section.data(6).dtTransOffset = 5;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.FixPtConstant_Value_p5
	  section.data(7).logicalSrcIdx = 262;
	  section.data(7).dtTransOffset = 6;
	
	  ;% FG_traj_fast_P.MAINCONTROLLOOP1.FixPtConstant_Value_j
	  section.data(8).logicalSrcIdx = 263;
	  section.data(8).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(8) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 17;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (FG_traj_fast_B)
    ;%
      section.nData     = 36;
      section.data(36)  = dumData; %prealloc
      
	  ;% FG_traj_fast_B.DataTypeConversion
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% FG_traj_fast_B.X_ref_x
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 30;
	
	  ;% FG_traj_fast_B.X_ref_y
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 123;
	
	  ;% FG_traj_fast_B.X_ref_z
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 216;
	
	  ;% FG_traj_fast_B.X_ref_yaw
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 278;
	
	  ;% FG_traj_fast_B.MultiportSwitch
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 340;
	
	  ;% FG_traj_fast_B.pitch_cmd
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 341;
	
	  ;% FG_traj_fast_B.roll_cmd
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 342;
	
	  ;% FG_traj_fast_B.thrust_cmd
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 343;
	
	  ;% FG_traj_fast_B.yaw_rate_cmd
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 344;
	
	  ;% FG_traj_fast_B.pitch_bias
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 345;
	
	  ;% FG_traj_fast_B.roll_bias
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 346;
	
	  ;% FG_traj_fast_B.thrust_bias
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 347;
	
	  ;% FG_traj_fast_B.yaw_rate_bias
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 348;
	
	  ;% FG_traj_fast_B.raddeg2
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 349;
	
	  ;% FG_traj_fast_B.raddeg1
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 352;
	
	  ;% FG_traj_fast_B.raddeg3
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 355;
	
	  ;% FG_traj_fast_B.raddeg
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 358;
	
	  ;% FG_traj_fast_B.bias_W
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 362;
	
	  ;% FG_traj_fast_B.cmd_W
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 366;
	
	  ;% FG_traj_fast_B.pitch_rot
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 370;
	
	  ;% FG_traj_fast_B.roll_rot
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 371;
	
	  ;% FG_traj_fast_B.pitch_bias_rot
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 372;
	
	  ;% FG_traj_fast_B.roll_bias_rot
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 373;
	
	  ;% FG_traj_fast_B.thrust_comp
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 374;
	
	  ;% FG_traj_fast_B.raddeg2_g
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 375;
	
	  ;% FG_traj_fast_B.raddeg1_i
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 378;
	
	  ;% FG_traj_fast_B.raddeg3_g
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 381;
	
	  ;% FG_traj_fast_B.raddeg_e
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 384;
	
	  ;% FG_traj_fast_B.bias_W_k
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 388;
	
	  ;% FG_traj_fast_B.cmd_W_c
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 392;
	
	  ;% FG_traj_fast_B.pitch_rot_f
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 396;
	
	  ;% FG_traj_fast_B.roll_rot_c
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 397;
	
	  ;% FG_traj_fast_B.pitch_bias_rot_j
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 398;
	
	  ;% FG_traj_fast_B.roll_bias_rot_g
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 399;
	
	  ;% FG_traj_fast_B.thrust_comp_c
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 400;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% FG_traj_fast_B.sf_EmbeddedMATLABFunction_j.roll_rot
	  section.data(1).logicalSrcIdx = 36;
	  section.data(1).dtTransOffset = 0;
	
	  ;% FG_traj_fast_B.sf_EmbeddedMATLABFunction_j.pitch_rot
	  section.data(2).logicalSrcIdx = 37;
	  section.data(2).dtTransOffset = 1;
	
	  ;% FG_traj_fast_B.sf_EmbeddedMATLABFunction_j.pitch_bias_rot
	  section.data(3).logicalSrcIdx = 38;
	  section.data(3).dtTransOffset = 2;
	
	  ;% FG_traj_fast_B.sf_EmbeddedMATLABFunction_j.roll_bias_rot
	  section.data(4).logicalSrcIdx = 39;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% FG_traj_fast_B.MAINCONTROLLOOP1_c.Saturation
	  section.data(1).logicalSrcIdx = 40;
	  section.data(1).dtTransOffset = 0;
	
	  ;% FG_traj_fast_B.MAINCONTROLLOOP1_c.pitch_cmd
	  section.data(2).logicalSrcIdx = 41;
	  section.data(2).dtTransOffset = 1;
	
	  ;% FG_traj_fast_B.MAINCONTROLLOOP1_c.Saturation_l
	  section.data(3).logicalSrcIdx = 42;
	  section.data(3).dtTransOffset = 2;
	
	  ;% FG_traj_fast_B.MAINCONTROLLOOP1_c.roll_cmd
	  section.data(4).logicalSrcIdx = 43;
	  section.data(4).dtTransOffset = 3;
	
	  ;% FG_traj_fast_B.MAINCONTROLLOOP1_c.Saturation_p
	  section.data(5).logicalSrcIdx = 44;
	  section.data(5).dtTransOffset = 4;
	
	  ;% FG_traj_fast_B.MAINCONTROLLOOP1_c.Saturation_c
	  section.data(6).logicalSrcIdx = 45;
	  section.data(6).dtTransOffset = 5;
	
	  ;% FG_traj_fast_B.MAINCONTROLLOOP1_c.yaw_rate_cmd
	  section.data(7).logicalSrcIdx = 46;
	  section.data(7).dtTransOffset = 6;
	
	  ;% FG_traj_fast_B.MAINCONTROLLOOP1_c.thrust_cmd
	  section.data(8).logicalSrcIdx = 47;
	  section.data(8).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% FG_traj_fast_B.MAINCONTROLLOOP1_c.sf_discretekalmanfilter_d.state_est
	  section.data(1).logicalSrcIdx = 48;
	  section.data(1).dtTransOffset = 0;
	
	  ;% FG_traj_fast_B.MAINCONTROLLOOP1_c.sf_discretekalmanfilter_d.P_est
	  section.data(2).logicalSrcIdx = 49;
	  section.data(2).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% FG_traj_fast_B.MAINCONTROLLOOP1_c.sf_discretekalmanfilter_j.state_est
	  section.data(1).logicalSrcIdx = 50;
	  section.data(1).dtTransOffset = 0;
	
	  ;% FG_traj_fast_B.MAINCONTROLLOOP1_c.sf_discretekalmanfilter_j.P_est
	  section.data(2).logicalSrcIdx = 51;
	  section.data(2).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(5) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% FG_traj_fast_B.MAINCONTROLLOOP1_c.sf_discretekalmanfilter_n.state_est
	  section.data(1).logicalSrcIdx = 52;
	  section.data(1).dtTransOffset = 0;
	
	  ;% FG_traj_fast_B.MAINCONTROLLOOP1_c.sf_discretekalmanfilter_n.P_est
	  section.data(2).logicalSrcIdx = 53;
	  section.data(2).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(6) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% FG_traj_fast_B.MAINCONTROLLOOP1_c.sf_runFastGradient_a.u_opt
	  section.data(1).logicalSrcIdx = 54;
	  section.data(1).dtTransOffset = 0;
	
	  ;% FG_traj_fast_B.MAINCONTROLLOOP1_c.sf_runFastGradient_a.u_buff_out
	  section.data(2).logicalSrcIdx = 55;
	  section.data(2).dtTransOffset = 1;
	
	  ;% FG_traj_fast_B.MAINCONTROLLOOP1_c.sf_runFastGradient_a.V_init_out
	  section.data(3).logicalSrcIdx = 56;
	  section.data(3).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(7) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% FG_traj_fast_B.MAINCONTROLLOOP1_c.sf_discretekalmanfilter.state_est
	  section.data(1).logicalSrcIdx = 57;
	  section.data(1).dtTransOffset = 0;
	
	  ;% FG_traj_fast_B.MAINCONTROLLOOP1_c.sf_discretekalmanfilter.P_est
	  section.data(2).logicalSrcIdx = 58;
	  section.data(2).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(8) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% FG_traj_fast_B.MAINCONTROLLOOP1_c.sf_runFastGradient.u_opt
	  section.data(1).logicalSrcIdx = 59;
	  section.data(1).dtTransOffset = 0;
	
	  ;% FG_traj_fast_B.MAINCONTROLLOOP1_c.sf_runFastGradient.u_buff_out
	  section.data(2).logicalSrcIdx = 60;
	  section.data(2).dtTransOffset = 1;
	
	  ;% FG_traj_fast_B.MAINCONTROLLOOP1_c.sf_runFastGradient.V_init_out
	  section.data(3).logicalSrcIdx = 61;
	  section.data(3).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(9) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% FG_traj_fast_B.sf_EmbeddedMATLABFunction.roll_rot
	  section.data(1).logicalSrcIdx = 62;
	  section.data(1).dtTransOffset = 0;
	
	  ;% FG_traj_fast_B.sf_EmbeddedMATLABFunction.pitch_rot
	  section.data(2).logicalSrcIdx = 63;
	  section.data(2).dtTransOffset = 1;
	
	  ;% FG_traj_fast_B.sf_EmbeddedMATLABFunction.pitch_bias_rot
	  section.data(3).logicalSrcIdx = 64;
	  section.data(3).dtTransOffset = 2;
	
	  ;% FG_traj_fast_B.sf_EmbeddedMATLABFunction.roll_bias_rot
	  section.data(4).logicalSrcIdx = 65;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(10) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% FG_traj_fast_B.MAINCONTROLLOOP1.Saturation
	  section.data(1).logicalSrcIdx = 66;
	  section.data(1).dtTransOffset = 0;
	
	  ;% FG_traj_fast_B.MAINCONTROLLOOP1.pitch_cmd
	  section.data(2).logicalSrcIdx = 67;
	  section.data(2).dtTransOffset = 1;
	
	  ;% FG_traj_fast_B.MAINCONTROLLOOP1.Saturation_l
	  section.data(3).logicalSrcIdx = 68;
	  section.data(3).dtTransOffset = 2;
	
	  ;% FG_traj_fast_B.MAINCONTROLLOOP1.roll_cmd
	  section.data(4).logicalSrcIdx = 69;
	  section.data(4).dtTransOffset = 3;
	
	  ;% FG_traj_fast_B.MAINCONTROLLOOP1.Saturation_p
	  section.data(5).logicalSrcIdx = 70;
	  section.data(5).dtTransOffset = 4;
	
	  ;% FG_traj_fast_B.MAINCONTROLLOOP1.Saturation_c
	  section.data(6).logicalSrcIdx = 71;
	  section.data(6).dtTransOffset = 5;
	
	  ;% FG_traj_fast_B.MAINCONTROLLOOP1.yaw_rate_cmd
	  section.data(7).logicalSrcIdx = 72;
	  section.data(7).dtTransOffset = 6;
	
	  ;% FG_traj_fast_B.MAINCONTROLLOOP1.thrust_cmd
	  section.data(8).logicalSrcIdx = 73;
	  section.data(8).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(11) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% FG_traj_fast_B.MAINCONTROLLOOP1.sf_discretekalmanfilter_d.state_est
	  section.data(1).logicalSrcIdx = 74;
	  section.data(1).dtTransOffset = 0;
	
	  ;% FG_traj_fast_B.MAINCONTROLLOOP1.sf_discretekalmanfilter_d.P_est
	  section.data(2).logicalSrcIdx = 75;
	  section.data(2).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(12) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% FG_traj_fast_B.MAINCONTROLLOOP1.sf_discretekalmanfilter_j.state_est
	  section.data(1).logicalSrcIdx = 76;
	  section.data(1).dtTransOffset = 0;
	
	  ;% FG_traj_fast_B.MAINCONTROLLOOP1.sf_discretekalmanfilter_j.P_est
	  section.data(2).logicalSrcIdx = 77;
	  section.data(2).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(13) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% FG_traj_fast_B.MAINCONTROLLOOP1.sf_discretekalmanfilter_n.state_est
	  section.data(1).logicalSrcIdx = 78;
	  section.data(1).dtTransOffset = 0;
	
	  ;% FG_traj_fast_B.MAINCONTROLLOOP1.sf_discretekalmanfilter_n.P_est
	  section.data(2).logicalSrcIdx = 79;
	  section.data(2).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(14) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% FG_traj_fast_B.MAINCONTROLLOOP1.sf_runFastGradient_a.u_opt
	  section.data(1).logicalSrcIdx = 80;
	  section.data(1).dtTransOffset = 0;
	
	  ;% FG_traj_fast_B.MAINCONTROLLOOP1.sf_runFastGradient_a.u_buff_out
	  section.data(2).logicalSrcIdx = 81;
	  section.data(2).dtTransOffset = 1;
	
	  ;% FG_traj_fast_B.MAINCONTROLLOOP1.sf_runFastGradient_a.V_init_out
	  section.data(3).logicalSrcIdx = 82;
	  section.data(3).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(15) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% FG_traj_fast_B.MAINCONTROLLOOP1.sf_discretekalmanfilter.state_est
	  section.data(1).logicalSrcIdx = 83;
	  section.data(1).dtTransOffset = 0;
	
	  ;% FG_traj_fast_B.MAINCONTROLLOOP1.sf_discretekalmanfilter.P_est
	  section.data(2).logicalSrcIdx = 84;
	  section.data(2).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(16) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% FG_traj_fast_B.MAINCONTROLLOOP1.sf_runFastGradient.u_opt
	  section.data(1).logicalSrcIdx = 85;
	  section.data(1).dtTransOffset = 0;
	
	  ;% FG_traj_fast_B.MAINCONTROLLOOP1.sf_runFastGradient.u_buff_out
	  section.data(2).logicalSrcIdx = 86;
	  section.data(2).dtTransOffset = 1;
	
	  ;% FG_traj_fast_B.MAINCONTROLLOOP1.sf_runFastGradient.V_init_out
	  section.data(3).logicalSrcIdx = 87;
	  section.data(3).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(17) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 10;
    sectIdxOffset = 17;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (FG_traj_fast_DWork)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% FG_traj_fast_DWork.FixPtUnitDelay1_DSTATE
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 28;
      section.data(28)  = dumData; %prealloc
      
	  ;% FG_traj_fast_DWork.bias_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
	  ;% FG_traj_fast_DWork.cmd_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 2;
	  section.data(2).dtTransOffset = 1;
	
	  ;% FG_traj_fast_DWork.cmd1_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 3;
	  section.data(3).dtTransOffset = 2;
	
	  ;% FG_traj_fast_DWork.mode_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 4;
	  section.data(4).dtTransOffset = 3;
	
	  ;% FG_traj_fast_DWork.mode2_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 5;
	  section.data(5).dtTransOffset = 4;
	
	  ;% FG_traj_fast_DWork.mode1_PWORK.LoggedData
	  section.data(6).logicalSrcIdx = 6;
	  section.data(6).dtTransOffset = 5;
	
	  ;% FG_traj_fast_DWork.mode1_PWORK_k.LoggedData
	  section.data(7).logicalSrcIdx = 7;
	  section.data(7).dtTransOffset = 6;
	
	  ;% FG_traj_fast_DWork.ToFile_PWORK.FilePtr
	  section.data(8).logicalSrcIdx = 8;
	  section.data(8).dtTransOffset = 7;
	
	  ;% FG_traj_fast_DWork.ToFile1_PWORK.FilePtr
	  section.data(9).logicalSrcIdx = 9;
	  section.data(9).dtTransOffset = 8;
	
	  ;% FG_traj_fast_DWork.pitchcmd_PWORK.LoggedData
	  section.data(10).logicalSrcIdx = 10;
	  section.data(10).dtTransOffset = 9;
	
	  ;% FG_traj_fast_DWork.rollcmd_PWORK.LoggedData
	  section.data(11).logicalSrcIdx = 11;
	  section.data(11).dtTransOffset = 10;
	
	  ;% FG_traj_fast_DWork.thrustcmd_PWORK.LoggedData
	  section.data(12).logicalSrcIdx = 12;
	  section.data(12).dtTransOffset = 11;
	
	  ;% FG_traj_fast_DWork.x_ref_PWORK.LoggedData
	  section.data(13).logicalSrcIdx = 13;
	  section.data(13).dtTransOffset = 12;
	
	  ;% FG_traj_fast_DWork.y_ref_PWORK.LoggedData
	  section.data(14).logicalSrcIdx = 14;
	  section.data(14).dtTransOffset = 13;
	
	  ;% FG_traj_fast_DWork.yawcmd_PWORK.LoggedData
	  section.data(15).logicalSrcIdx = 15;
	  section.data(15).dtTransOffset = 14;
	
	  ;% FG_traj_fast_DWork.yaw_ref_PWORK.LoggedData
	  section.data(16).logicalSrcIdx = 16;
	  section.data(16).dtTransOffset = 15;
	
	  ;% FG_traj_fast_DWork.z_ref_PWORK.LoggedData
	  section.data(17).logicalSrcIdx = 17;
	  section.data(17).dtTransOffset = 16;
	
	  ;% FG_traj_fast_DWork.mode1_PWORK_n.LoggedData
	  section.data(18).logicalSrcIdx = 18;
	  section.data(18).dtTransOffset = 17;
	
	  ;% FG_traj_fast_DWork.ToFile_PWORK_d.FilePtr
	  section.data(19).logicalSrcIdx = 19;
	  section.data(19).dtTransOffset = 18;
	
	  ;% FG_traj_fast_DWork.ToFile1_PWORK_c.FilePtr
	  section.data(20).logicalSrcIdx = 20;
	  section.data(20).dtTransOffset = 19;
	
	  ;% FG_traj_fast_DWork.pitchcmd_PWORK_f.LoggedData
	  section.data(21).logicalSrcIdx = 21;
	  section.data(21).dtTransOffset = 20;
	
	  ;% FG_traj_fast_DWork.rollcmd_PWORK_m.LoggedData
	  section.data(22).logicalSrcIdx = 22;
	  section.data(22).dtTransOffset = 21;
	
	  ;% FG_traj_fast_DWork.thrustcmd_PWORK_i.LoggedData
	  section.data(23).logicalSrcIdx = 23;
	  section.data(23).dtTransOffset = 22;
	
	  ;% FG_traj_fast_DWork.x_ref_PWORK_n.LoggedData
	  section.data(24).logicalSrcIdx = 24;
	  section.data(24).dtTransOffset = 23;
	
	  ;% FG_traj_fast_DWork.y_ref_PWORK_f.LoggedData
	  section.data(25).logicalSrcIdx = 25;
	  section.data(25).dtTransOffset = 24;
	
	  ;% FG_traj_fast_DWork.yawcmd_PWORK_p.LoggedData
	  section.data(26).logicalSrcIdx = 26;
	  section.data(26).dtTransOffset = 25;
	
	  ;% FG_traj_fast_DWork.yaw_ref_PWORK_g.LoggedData
	  section.data(27).logicalSrcIdx = 27;
	  section.data(27).dtTransOffset = 26;
	
	  ;% FG_traj_fast_DWork.z_ref_PWORK_m.LoggedData
	  section.data(28).logicalSrcIdx = 28;
	  section.data(28).dtTransOffset = 27;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% FG_traj_fast_DWork.ToFile_IWORK.Count
	  section.data(1).logicalSrcIdx = 29;
	  section.data(1).dtTransOffset = 0;
	
	  ;% FG_traj_fast_DWork.ToFile1_IWORK.Count
	  section.data(2).logicalSrcIdx = 30;
	  section.data(2).dtTransOffset = 1;
	
	  ;% FG_traj_fast_DWork.ToFile_IWORK_n.Count
	  section.data(3).logicalSrcIdx = 31;
	  section.data(3).dtTransOffset = 2;
	
	  ;% FG_traj_fast_DWork.ToFile1_IWORK_d.Count
	  section.data(4).logicalSrcIdx = 32;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% FG_traj_fast_DWork.FixPtUnitDelay2_DSTATE
	  section.data(1).logicalSrcIdx = 33;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% FG_traj_fast_DWork.poscontroller1_SubsysRanBC
	  section.data(1).logicalSrcIdx = 34;
	  section.data(1).dtTransOffset = 0;
	
	  ;% FG_traj_fast_DWork.poscontroller_SubsysRanBC
	  section.data(2).logicalSrcIdx = 35;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% FG_traj_fast_DWork.poscontroller1_MODE
	  section.data(1).logicalSrcIdx = 36;
	  section.data(1).dtTransOffset = 0;
	
	  ;% FG_traj_fast_DWork.poscontroller_MODE
	  section.data(2).logicalSrcIdx = 37;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 20;
      section.data(20)  = dumData; %prealloc
      
	  ;% FG_traj_fast_DWork.MAINCONTROLLOOP1_c.IntegerDelay_DSTATE
	  section.data(1).logicalSrcIdx = 38;
	  section.data(1).dtTransOffset = 0;
	
	  ;% FG_traj_fast_DWork.MAINCONTROLLOOP1_c.IntegerDelay1_DSTATE
	  section.data(2).logicalSrcIdx = 39;
	  section.data(2).dtTransOffset = 1;
	
	  ;% FG_traj_fast_DWork.MAINCONTROLLOOP1_c.IntegerDelay2_DSTATE
	  section.data(3).logicalSrcIdx = 40;
	  section.data(3).dtTransOffset = 2;
	
	  ;% FG_traj_fast_DWork.MAINCONTROLLOOP1_c.IntegerDelay3_DSTATE
	  section.data(4).logicalSrcIdx = 41;
	  section.data(4).dtTransOffset = 3;
	
	  ;% FG_traj_fast_DWork.MAINCONTROLLOOP1_c.UnitDelay1_DSTATE
	  section.data(5).logicalSrcIdx = 42;
	  section.data(5).dtTransOffset = 4;
	
	  ;% FG_traj_fast_DWork.MAINCONTROLLOOP1_c.FixPtUnitDelay1_DSTATE
	  section.data(6).logicalSrcIdx = 43;
	  section.data(6).dtTransOffset = 20;
	
	  ;% FG_traj_fast_DWork.MAINCONTROLLOOP1_c.UnitDelay_DSTATE
	  section.data(7).logicalSrcIdx = 44;
	  section.data(7).dtTransOffset = 23;
	
	  ;% FG_traj_fast_DWork.MAINCONTROLLOOP1_c.UnitDelay1_DSTATE_f
	  section.data(8).logicalSrcIdx = 45;
	  section.data(8).dtTransOffset = 26;
	
	  ;% FG_traj_fast_DWork.MAINCONTROLLOOP1_c.UnitDelay1_DSTATE_m
	  section.data(9).logicalSrcIdx = 46;
	  section.data(9).dtTransOffset = 56;
	
	  ;% FG_traj_fast_DWork.MAINCONTROLLOOP1_c.FixPtUnitDelay1_DSTATE_g
	  section.data(10).logicalSrcIdx = 47;
	  section.data(10).dtTransOffset = 72;
	
	  ;% FG_traj_fast_DWork.MAINCONTROLLOOP1_c.UnitDelay_DSTATE_p
	  section.data(11).logicalSrcIdx = 48;
	  section.data(11).dtTransOffset = 75;
	
	  ;% FG_traj_fast_DWork.MAINCONTROLLOOP1_c.UnitDelay1_DSTATE_mi
	  section.data(12).logicalSrcIdx = 49;
	  section.data(12).dtTransOffset = 78;
	
	  ;% FG_traj_fast_DWork.MAINCONTROLLOOP1_c.UnitDelay1_DSTATE_c
	  section.data(13).logicalSrcIdx = 50;
	  section.data(13).dtTransOffset = 108;
	
	  ;% FG_traj_fast_DWork.MAINCONTROLLOOP1_c.FixPtUnitDelay1_DSTATE_j
	  section.data(14).logicalSrcIdx = 51;
	  section.data(14).dtTransOffset = 117;
	
	  ;% FG_traj_fast_DWork.MAINCONTROLLOOP1_c.UnitDelay_DSTATE_d
	  section.data(15).logicalSrcIdx = 52;
	  section.data(15).dtTransOffset = 119;
	
	  ;% FG_traj_fast_DWork.MAINCONTROLLOOP1_c.UnitDelay1_DSTATE_j
	  section.data(16).logicalSrcIdx = 53;
	  section.data(16).dtTransOffset = 121;
	
	  ;% FG_traj_fast_DWork.MAINCONTROLLOOP1_c.UnitDelay1_DSTATE_h
	  section.data(17).logicalSrcIdx = 54;
	  section.data(17).dtTransOffset = 151;
	
	  ;% FG_traj_fast_DWork.MAINCONTROLLOOP1_c.FixPtUnitDelay1_DSTATE_p
	  section.data(18).logicalSrcIdx = 55;
	  section.data(18).dtTransOffset = 160;
	
	  ;% FG_traj_fast_DWork.MAINCONTROLLOOP1_c.UnitDelay_DSTATE_j
	  section.data(19).logicalSrcIdx = 56;
	  section.data(19).dtTransOffset = 162;
	
	  ;% FG_traj_fast_DWork.MAINCONTROLLOOP1_c.UnitDelay1_DSTATE_p
	  section.data(20).logicalSrcIdx = 57;
	  section.data(20).dtTransOffset = 168;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% FG_traj_fast_DWork.MAINCONTROLLOOP1_c.FixPtUnitDelay2_DSTATE
	  section.data(1).logicalSrcIdx = 58;
	  section.data(1).dtTransOffset = 0;
	
	  ;% FG_traj_fast_DWork.MAINCONTROLLOOP1_c.FixPtUnitDelay2_DSTATE_f
	  section.data(2).logicalSrcIdx = 59;
	  section.data(2).dtTransOffset = 1;
	
	  ;% FG_traj_fast_DWork.MAINCONTROLLOOP1_c.FixPtUnitDelay2_DSTATE_h
	  section.data(3).logicalSrcIdx = 60;
	  section.data(3).dtTransOffset = 2;
	
	  ;% FG_traj_fast_DWork.MAINCONTROLLOOP1_c.FixPtUnitDelay2_DSTATE_g
	  section.data(4).logicalSrcIdx = 61;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 20;
      section.data(20)  = dumData; %prealloc
      
	  ;% FG_traj_fast_DWork.MAINCONTROLLOOP1.IntegerDelay_DSTATE
	  section.data(1).logicalSrcIdx = 62;
	  section.data(1).dtTransOffset = 0;
	
	  ;% FG_traj_fast_DWork.MAINCONTROLLOOP1.IntegerDelay1_DSTATE
	  section.data(2).logicalSrcIdx = 63;
	  section.data(2).dtTransOffset = 1;
	
	  ;% FG_traj_fast_DWork.MAINCONTROLLOOP1.IntegerDelay2_DSTATE
	  section.data(3).logicalSrcIdx = 64;
	  section.data(3).dtTransOffset = 2;
	
	  ;% FG_traj_fast_DWork.MAINCONTROLLOOP1.IntegerDelay3_DSTATE
	  section.data(4).logicalSrcIdx = 65;
	  section.data(4).dtTransOffset = 3;
	
	  ;% FG_traj_fast_DWork.MAINCONTROLLOOP1.UnitDelay1_DSTATE
	  section.data(5).logicalSrcIdx = 66;
	  section.data(5).dtTransOffset = 4;
	
	  ;% FG_traj_fast_DWork.MAINCONTROLLOOP1.FixPtUnitDelay1_DSTATE
	  section.data(6).logicalSrcIdx = 67;
	  section.data(6).dtTransOffset = 20;
	
	  ;% FG_traj_fast_DWork.MAINCONTROLLOOP1.UnitDelay_DSTATE
	  section.data(7).logicalSrcIdx = 68;
	  section.data(7).dtTransOffset = 23;
	
	  ;% FG_traj_fast_DWork.MAINCONTROLLOOP1.UnitDelay1_DSTATE_f
	  section.data(8).logicalSrcIdx = 69;
	  section.data(8).dtTransOffset = 26;
	
	  ;% FG_traj_fast_DWork.MAINCONTROLLOOP1.UnitDelay1_DSTATE_m
	  section.data(9).logicalSrcIdx = 70;
	  section.data(9).dtTransOffset = 56;
	
	  ;% FG_traj_fast_DWork.MAINCONTROLLOOP1.FixPtUnitDelay1_DSTATE_g
	  section.data(10).logicalSrcIdx = 71;
	  section.data(10).dtTransOffset = 72;
	
	  ;% FG_traj_fast_DWork.MAINCONTROLLOOP1.UnitDelay_DSTATE_p
	  section.data(11).logicalSrcIdx = 72;
	  section.data(11).dtTransOffset = 75;
	
	  ;% FG_traj_fast_DWork.MAINCONTROLLOOP1.UnitDelay1_DSTATE_mi
	  section.data(12).logicalSrcIdx = 73;
	  section.data(12).dtTransOffset = 78;
	
	  ;% FG_traj_fast_DWork.MAINCONTROLLOOP1.UnitDelay1_DSTATE_c
	  section.data(13).logicalSrcIdx = 74;
	  section.data(13).dtTransOffset = 108;
	
	  ;% FG_traj_fast_DWork.MAINCONTROLLOOP1.FixPtUnitDelay1_DSTATE_j
	  section.data(14).logicalSrcIdx = 75;
	  section.data(14).dtTransOffset = 117;
	
	  ;% FG_traj_fast_DWork.MAINCONTROLLOOP1.UnitDelay_DSTATE_d
	  section.data(15).logicalSrcIdx = 76;
	  section.data(15).dtTransOffset = 119;
	
	  ;% FG_traj_fast_DWork.MAINCONTROLLOOP1.UnitDelay1_DSTATE_j
	  section.data(16).logicalSrcIdx = 77;
	  section.data(16).dtTransOffset = 121;
	
	  ;% FG_traj_fast_DWork.MAINCONTROLLOOP1.UnitDelay1_DSTATE_h
	  section.data(17).logicalSrcIdx = 78;
	  section.data(17).dtTransOffset = 151;
	
	  ;% FG_traj_fast_DWork.MAINCONTROLLOOP1.FixPtUnitDelay1_DSTATE_p
	  section.data(18).logicalSrcIdx = 79;
	  section.data(18).dtTransOffset = 160;
	
	  ;% FG_traj_fast_DWork.MAINCONTROLLOOP1.UnitDelay_DSTATE_j
	  section.data(19).logicalSrcIdx = 80;
	  section.data(19).dtTransOffset = 162;
	
	  ;% FG_traj_fast_DWork.MAINCONTROLLOOP1.UnitDelay1_DSTATE_p
	  section.data(20).logicalSrcIdx = 81;
	  section.data(20).dtTransOffset = 168;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% FG_traj_fast_DWork.MAINCONTROLLOOP1.FixPtUnitDelay2_DSTATE
	  section.data(1).logicalSrcIdx = 82;
	  section.data(1).dtTransOffset = 0;
	
	  ;% FG_traj_fast_DWork.MAINCONTROLLOOP1.FixPtUnitDelay2_DSTATE_f
	  section.data(2).logicalSrcIdx = 83;
	  section.data(2).dtTransOffset = 1;
	
	  ;% FG_traj_fast_DWork.MAINCONTROLLOOP1.FixPtUnitDelay2_DSTATE_h
	  section.data(3).logicalSrcIdx = 84;
	  section.data(3).dtTransOffset = 2;
	
	  ;% FG_traj_fast_DWork.MAINCONTROLLOOP1.FixPtUnitDelay2_DSTATE_g
	  section.data(4).logicalSrcIdx = 85;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(10) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 484232947;
  targMap.checksum1 = 3809245171;
  targMap.checksum2 = 649542148;
  targMap.checksum3 = 1283454371;

