  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 3;
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
    ;% Auto data (controller_template_P)
    ;%
      section.nData     = 217;
      section.data(217)  = dumData; %prealloc
      
	  ;% controller_template_P.gravity_Value
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_P.Saturation_UpperSat
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% controller_template_P.Saturation_LowerSat
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% controller_template_P.Saturation1_UpperSat
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% controller_template_P.Saturation1_LowerSat
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% controller_template_P.SliderGain_Gain
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% controller_template_P.Constant_Value
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% controller_template_P.SliderGain_Gain_e
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% controller_template_P.Constant1_Value
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% controller_template_P.SliderGain_Gain_f
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% controller_template_P.Saturation3_UpperSat
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% controller_template_P.Saturation3_LowerSat
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% controller_template_P.Saturation2_UpperSat
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% controller_template_P.Saturation2_LowerSat
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% controller_template_P.Constant_Value_d
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% controller_template_P.Constant1_Value_k
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 30;
	
	  ;% controller_template_P.UnitDelay2_X0
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 38;
	
	  ;% controller_template_P.Constant_Value_o
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 39;
	
	  ;% controller_template_P.Constant1_Value_d
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 13011;
	
	  ;% controller_template_P.Constant2_Value
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 16254;
	
	  ;% controller_template_P.Constant3_Value
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 17726;
	
	  ;% controller_template_P.Constant4_Value
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 18094;
	
	  ;% controller_template_P.Saturation4_UpperSat
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 18462;
	
	  ;% controller_template_P.Saturation4_LowerSat
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 18463;
	
	  ;% controller_template_P.UnitDelay2_X0_m
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 18464;
	
	  ;% controller_template_P.UnitDelay_X0
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 18465;
	
	  ;% controller_template_P.Gain_Gain
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 18466;
	
	  ;% controller_template_P.Saturation_UpperSat_h
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 18467;
	
	  ;% controller_template_P.Saturation_LowerSat_d
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 18468;
	
	  ;% controller_template_P.Saturation1_UpperSat_o
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 18469;
	
	  ;% controller_template_P.Saturation1_LowerSat_c
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 18470;
	
	  ;% controller_template_P.Saturation3_UpperSat_n
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 18471;
	
	  ;% controller_template_P.Saturation3_LowerSat_c
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 18472;
	
	  ;% controller_template_P.Saturation2_UpperSat_b
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 18473;
	
	  ;% controller_template_P.Saturation2_LowerSat_h
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 18474;
	
	  ;% controller_template_P.Constant_Value_c
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 18475;
	
	  ;% controller_template_P.Constant1_Value_g
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 18491;
	
	  ;% controller_template_P.UnitDelay2_X0_d
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 18499;
	
	  ;% controller_template_P.Constant_Value_l
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 18500;
	
	  ;% controller_template_P.Constant1_Value_j
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 23032;
	
	  ;% controller_template_P.Constant2_Value_j
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 24165;
	
	  ;% controller_template_P.Constant3_Value_o
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 24701;
	
	  ;% controller_template_P.Constant4_Value_g
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 24835;
	
	  ;% controller_template_P.Saturation4_UpperSat_i
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 24969;
	
	  ;% controller_template_P.Saturation4_LowerSat_h
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 24970;
	
	  ;% controller_template_P.UnitDelay2_X0_n
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 24971;
	
	  ;% controller_template_P.UnitDelay_X0_f
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 24972;
	
	  ;% controller_template_P.Gain_Gain_f
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 24973;
	
	  ;% controller_template_P.Saturation1_UpperSat_d
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 24974;
	
	  ;% controller_template_P.Saturation1_LowerSat_n
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 24975;
	
	  ;% controller_template_P.Saturation_UpperSat_d
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 24976;
	
	  ;% controller_template_P.Saturation_LowerSat_b
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 24977;
	
	  ;% controller_template_P.Constant_Value_b
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 24978;
	
	  ;% controller_template_P.Constant1_Value_l
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 25202;
	
	  ;% controller_template_P.Constant2_Value_g
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 25314;
	
	  ;% controller_template_P.Constant3_Value_m
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 25368;
	
	  ;% controller_template_P.Constant4_Value_a
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 25395;
	
	  ;% controller_template_P.Saturation2_UpperSat_k
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 25422;
	
	  ;% controller_template_P.Saturation2_LowerSat_j
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 25423;
	
	  ;% controller_template_P.UnitDelay2_X0_o
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 25424;
	
	  ;% controller_template_P.UnitDelay_X0_i
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 25425;
	
	  ;% controller_template_P.Gain_Gain_p
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 25426;
	
	  ;% controller_template_P.Saturation_UpperSat_o
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 25427;
	
	  ;% controller_template_P.Saturation_LowerSat_p
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 25428;
	
	  ;% controller_template_P.Constant_Value_h
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 25429;
	
	  ;% controller_template_P.Constant1_Value_m
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 25430;
	
	  ;% controller_template_P.UnitDelay2_X0_ng
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 25431;
	
	  ;% controller_template_P.Constant_Value_a
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 25432;
	
	  ;% controller_template_P.Constant1_Value_gs
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 25438;
	
	  ;% controller_template_P.Constant2_Value_jq
	  section.data(70).logicalSrcIdx = 69;
	  section.data(70).dtTransOffset = 25444;
	
	  ;% controller_template_P.Constant3_Value_b
	  section.data(71).logicalSrcIdx = 70;
	  section.data(71).dtTransOffset = 25447;
	
	  ;% controller_template_P.Constant4_Value_gb
	  section.data(72).logicalSrcIdx = 71;
	  section.data(72).dtTransOffset = 25450;
	
	  ;% controller_template_P.Saturation1_UpperSat_g
	  section.data(73).logicalSrcIdx = 72;
	  section.data(73).dtTransOffset = 25453;
	
	  ;% controller_template_P.Saturation1_LowerSat_b
	  section.data(74).logicalSrcIdx = 73;
	  section.data(74).dtTransOffset = 25454;
	
	  ;% controller_template_P.UnitDelay2_X0_i
	  section.data(75).logicalSrcIdx = 74;
	  section.data(75).dtTransOffset = 25455;
	
	  ;% controller_template_P.UnitDelay_X0_c
	  section.data(76).logicalSrcIdx = 75;
	  section.data(76).dtTransOffset = 25456;
	
	  ;% controller_template_P.Gain_Gain_p0
	  section.data(77).logicalSrcIdx = 76;
	  section.data(77).dtTransOffset = 25457;
	
	  ;% controller_template_P.UnitDelay1_X0
	  section.data(78).logicalSrcIdx = 77;
	  section.data(78).dtTransOffset = 25458;
	
	  ;% controller_template_P.UnitDelay1_X0_d
	  section.data(79).logicalSrcIdx = 78;
	  section.data(79).dtTransOffset = 25459;
	
	  ;% controller_template_P.UnitDelay1_X0_j
	  section.data(80).logicalSrcIdx = 79;
	  section.data(80).dtTransOffset = 25460;
	
	  ;% controller_template_P.UnitDelay1_X0_f
	  section.data(81).logicalSrcIdx = 80;
	  section.data(81).dtTransOffset = 25461;
	
	  ;% controller_template_P.g_Value
	  section.data(82).logicalSrcIdx = 81;
	  section.data(82).dtTransOffset = 25462;
	
	  ;% controller_template_P.raddeg2_Gain
	  section.data(83).logicalSrcIdx = 82;
	  section.data(83).dtTransOffset = 25463;
	
	  ;% controller_template_P.raddeg1_Gain
	  section.data(84).logicalSrcIdx = 83;
	  section.data(84).dtTransOffset = 25464;
	
	  ;% controller_template_P.raddeg3_Gain
	  section.data(85).logicalSrcIdx = 84;
	  section.data(85).dtTransOffset = 25465;
	
	  ;% controller_template_P.raddeg_Gain
	  section.data(86).logicalSrcIdx = 85;
	  section.data(86).dtTransOffset = 25466;
	
	  ;% controller_template_P.yaw_rate_bias_Value
	  section.data(87).logicalSrcIdx = 86;
	  section.data(87).dtTransOffset = 25467;
	
	  ;% controller_template_P.thrust_bias_Value
	  section.data(88).logicalSrcIdx = 87;
	  section.data(88).dtTransOffset = 25468;
	
	  ;% controller_template_P.roll_bias_Value
	  section.data(89).logicalSrcIdx = 88;
	  section.data(89).dtTransOffset = 25469;
	
	  ;% controller_template_P.pitch_bias_Value
	  section.data(90).logicalSrcIdx = 89;
	  section.data(90).dtTransOffset = 25470;
	
	  ;% controller_template_P.yaw_Value
	  section.data(91).logicalSrcIdx = 90;
	  section.data(91).dtTransOffset = 25471;
	
	  ;% controller_template_P.gravity_Value_c
	  section.data(92).logicalSrcIdx = 91;
	  section.data(92).dtTransOffset = 25472;
	
	  ;% controller_template_P.roll_Value
	  section.data(93).logicalSrcIdx = 92;
	  section.data(93).dtTransOffset = 25473;
	
	  ;% controller_template_P.pitch_Value
	  section.data(94).logicalSrcIdx = 93;
	  section.data(94).dtTransOffset = 25474;
	
	  ;% controller_template_P.yaw_rate_Value
	  section.data(95).logicalSrcIdx = 94;
	  section.data(95).dtTransOffset = 25475;
	
	  ;% controller_template_P.yaw_cmd2yaw_Gain
	  section.data(96).logicalSrcIdx = 95;
	  section.data(96).dtTransOffset = 25476;
	
	  ;% controller_template_P.IntegerDelay_InitialCondition
	  section.data(97).logicalSrcIdx = 96;
	  section.data(97).dtTransOffset = 25477;
	
	  ;% controller_template_P.IntegerDelay1_InitialCondition
	  section.data(98).logicalSrcIdx = 97;
	  section.data(98).dtTransOffset = 25478;
	
	  ;% controller_template_P.IntegerDelay2_InitialCondition
	  section.data(99).logicalSrcIdx = 98;
	  section.data(99).dtTransOffset = 25479;
	
	  ;% controller_template_P.IntegerDelay3_InitialCondition
	  section.data(100).logicalSrcIdx = 99;
	  section.data(100).dtTransOffset = 25480;
	
	  ;% controller_template_P.gravity_Value_j
	  section.data(101).logicalSrcIdx = 100;
	  section.data(101).dtTransOffset = 25481;
	
	  ;% controller_template_P.TT_PP_Value
	  section.data(102).logicalSrcIdx = 101;
	  section.data(102).dtTransOffset = 25482;
	
	  ;% controller_template_P.LL_PP_Value
	  section.data(103).logicalSrcIdx = 102;
	  section.data(103).dtTransOffset = 26382;
	
	  ;% controller_template_P.LL_ref_PP_Value
	  section.data(104).logicalSrcIdx = 103;
	  section.data(104).dtTransOffset = 26472;
	
	  ;% controller_template_P.LL_U_ref_PP_Value
	  section.data(105).logicalSrcIdx = 104;
	  section.data(105).dtTransOffset = 29262;
	
	  ;% controller_template_P.MM_Value
	  section.data(106).logicalSrcIdx = 105;
	  section.data(106).dtTransOffset = 30162;
	
	  ;% controller_template_P.PP_Value
	  section.data(107).logicalSrcIdx = 106;
	  section.data(107).dtTransOffset = 30171;
	
	  ;% controller_template_P.AA_delay_Value
	  section.data(108).logicalSrcIdx = 107;
	  section.data(108).dtTransOffset = 31071;
	
	  ;% controller_template_P.BB_delay_Value
	  section.data(109).logicalSrcIdx = 108;
	  section.data(109).dtTransOffset = 31080;
	
	  ;% controller_template_P.A_Value
	  section.data(110).logicalSrcIdx = 109;
	  section.data(110).dtTransOffset = 31089;
	
	  ;% controller_template_P.B_Value
	  section.data(111).logicalSrcIdx = 110;
	  section.data(111).dtTransOffset = 31105;
	
	  ;% controller_template_P.C_Value
	  section.data(112).logicalSrcIdx = 111;
	  section.data(112).dtTransOffset = 31109;
	
	  ;% controller_template_P.D_Value
	  section.data(113).logicalSrcIdx = 112;
	  section.data(113).dtTransOffset = 31121;
	
	  ;% controller_template_P.Q_Value
	  section.data(114).logicalSrcIdx = 113;
	  section.data(114).dtTransOffset = 31124;
	
	  ;% controller_template_P.R_Value
	  section.data(115).logicalSrcIdx = 114;
	  section.data(115).dtTransOffset = 31140;
	
	  ;% controller_template_P.UnitDelay1_X0_c
	  section.data(116).logicalSrcIdx = 115;
	  section.data(116).dtTransOffset = 31149;
	
	  ;% controller_template_P.FixPtUnitDelay1_X0
	  section.data(117).logicalSrcIdx = 116;
	  section.data(117).dtTransOffset = 31165;
	
	  ;% controller_template_P.V_max_Value
	  section.data(118).logicalSrcIdx = 117;
	  section.data(118).dtTransOffset = 31166;
	
	  ;% controller_template_P.i_min_Value
	  section.data(119).logicalSrcIdx = 118;
	  section.data(119).dtTransOffset = 31196;
	
	  ;% controller_template_P.betas_Value
	  section.data(120).logicalSrcIdx = 119;
	  section.data(120).dtTransOffset = 31197;
	
	  ;% controller_template_P.L_Value
	  section.data(121).logicalSrcIdx = 120;
	  section.data(121).dtTransOffset = 31204;
	
	  ;% controller_template_P.UnitDelay_X0_fc
	  section.data(122).logicalSrcIdx = 121;
	  section.data(122).dtTransOffset = 31205;
	
	  ;% controller_template_P.UnitDelay1_X0_k
	  section.data(123).logicalSrcIdx = 122;
	  section.data(123).dtTransOffset = 31208;
	
	  ;% controller_template_P.Saturation_UpperSat_i
	  section.data(124).logicalSrcIdx = 123;
	  section.data(124).dtTransOffset = 31238;
	
	  ;% controller_template_P.Saturation_LowerSat_o
	  section.data(125).logicalSrcIdx = 124;
	  section.data(125).dtTransOffset = 31239;
	
	  ;% controller_template_P.TT_PP_Value_m
	  section.data(126).logicalSrcIdx = 125;
	  section.data(126).dtTransOffset = 31240;
	
	  ;% controller_template_P.LL_PP_Value_e
	  section.data(127).logicalSrcIdx = 126;
	  section.data(127).dtTransOffset = 32140;
	
	  ;% controller_template_P.LL_ref_PP_Value_l
	  section.data(128).logicalSrcIdx = 127;
	  section.data(128).dtTransOffset = 32230;
	
	  ;% controller_template_P.LL_U_ref_PP_Value_m
	  section.data(129).logicalSrcIdx = 128;
	  section.data(129).dtTransOffset = 35020;
	
	  ;% controller_template_P.MM_Value_c
	  section.data(130).logicalSrcIdx = 129;
	  section.data(130).dtTransOffset = 35920;
	
	  ;% controller_template_P.PP_Value_m
	  section.data(131).logicalSrcIdx = 130;
	  section.data(131).dtTransOffset = 35929;
	
	  ;% controller_template_P.AA_delay_Value_h
	  section.data(132).logicalSrcIdx = 131;
	  section.data(132).dtTransOffset = 36829;
	
	  ;% controller_template_P.BB_delay_Value_o
	  section.data(133).logicalSrcIdx = 132;
	  section.data(133).dtTransOffset = 36838;
	
	  ;% controller_template_P.A_Value_n
	  section.data(134).logicalSrcIdx = 133;
	  section.data(134).dtTransOffset = 36847;
	
	  ;% controller_template_P.B_Value_h
	  section.data(135).logicalSrcIdx = 134;
	  section.data(135).dtTransOffset = 36863;
	
	  ;% controller_template_P.C_Value_p
	  section.data(136).logicalSrcIdx = 135;
	  section.data(136).dtTransOffset = 36867;
	
	  ;% controller_template_P.D_Value_m
	  section.data(137).logicalSrcIdx = 136;
	  section.data(137).dtTransOffset = 36879;
	
	  ;% controller_template_P.Q_Value_h
	  section.data(138).logicalSrcIdx = 137;
	  section.data(138).dtTransOffset = 36882;
	
	  ;% controller_template_P.R_Value_l
	  section.data(139).logicalSrcIdx = 138;
	  section.data(139).dtTransOffset = 36898;
	
	  ;% controller_template_P.UnitDelay1_X0_fk
	  section.data(140).logicalSrcIdx = 139;
	  section.data(140).dtTransOffset = 36907;
	
	  ;% controller_template_P.FixPtUnitDelay1_X0_n
	  section.data(141).logicalSrcIdx = 140;
	  section.data(141).dtTransOffset = 36923;
	
	  ;% controller_template_P.V_max_Value_o
	  section.data(142).logicalSrcIdx = 141;
	  section.data(142).dtTransOffset = 36924;
	
	  ;% controller_template_P.i_min_Value_j
	  section.data(143).logicalSrcIdx = 142;
	  section.data(143).dtTransOffset = 36954;
	
	  ;% controller_template_P.betas_Value_l
	  section.data(144).logicalSrcIdx = 143;
	  section.data(144).dtTransOffset = 36955;
	
	  ;% controller_template_P.L_Value_n
	  section.data(145).logicalSrcIdx = 144;
	  section.data(145).dtTransOffset = 36962;
	
	  ;% controller_template_P.UnitDelay_X0_ik
	  section.data(146).logicalSrcIdx = 145;
	  section.data(146).dtTransOffset = 36963;
	
	  ;% controller_template_P.UnitDelay1_X0_jc
	  section.data(147).logicalSrcIdx = 146;
	  section.data(147).dtTransOffset = 36966;
	
	  ;% controller_template_P.Saturation_UpperSat_f
	  section.data(148).logicalSrcIdx = 147;
	  section.data(148).dtTransOffset = 36996;
	
	  ;% controller_template_P.Saturation_LowerSat_k
	  section.data(149).logicalSrcIdx = 148;
	  section.data(149).dtTransOffset = 36997;
	
	  ;% controller_template_P.TT_PP_Value_b
	  section.data(150).logicalSrcIdx = 149;
	  section.data(150).dtTransOffset = 36998;
	
	  ;% controller_template_P.LL_PP_Value_j
	  section.data(151).logicalSrcIdx = 150;
	  section.data(151).dtTransOffset = 37898;
	
	  ;% controller_template_P.LL_ref_PP_Value_h
	  section.data(152).logicalSrcIdx = 151;
	  section.data(152).dtTransOffset = 37958;
	
	  ;% controller_template_P.LL_U_ref_PP_Value_o
	  section.data(153).logicalSrcIdx = 152;
	  section.data(153).dtTransOffset = 39818;
	
	  ;% controller_template_P.MM_Value_l
	  section.data(154).logicalSrcIdx = 153;
	  section.data(154).dtTransOffset = 40718;
	
	  ;% controller_template_P.PP_Value_o
	  section.data(155).logicalSrcIdx = 154;
	  section.data(155).dtTransOffset = 40722;
	
	  ;% controller_template_P.AA_delay_Value_l
	  section.data(156).logicalSrcIdx = 155;
	  section.data(156).dtTransOffset = 41622;
	
	  ;% controller_template_P.BB_delay_Value_b
	  section.data(157).logicalSrcIdx = 156;
	  section.data(157).dtTransOffset = 41626;
	
	  ;% controller_template_P.A_Value_f
	  section.data(158).logicalSrcIdx = 157;
	  section.data(158).dtTransOffset = 41630;
	
	  ;% controller_template_P.B_Value_n
	  section.data(159).logicalSrcIdx = 158;
	  section.data(159).dtTransOffset = 41639;
	
	  ;% controller_template_P.C_Value_o
	  section.data(160).logicalSrcIdx = 159;
	  section.data(160).dtTransOffset = 41642;
	
	  ;% controller_template_P.D_Value_j
	  section.data(161).logicalSrcIdx = 160;
	  section.data(161).dtTransOffset = 41648;
	
	  ;% controller_template_P.Q_Value_j
	  section.data(162).logicalSrcIdx = 161;
	  section.data(162).dtTransOffset = 41650;
	
	  ;% controller_template_P.R_Value_c
	  section.data(163).logicalSrcIdx = 162;
	  section.data(163).dtTransOffset = 41659;
	
	  ;% controller_template_P.UnitDelay1_X0_cw
	  section.data(164).logicalSrcIdx = 163;
	  section.data(164).dtTransOffset = 41663;
	
	  ;% controller_template_P.FixPtUnitDelay1_X0_c
	  section.data(165).logicalSrcIdx = 164;
	  section.data(165).dtTransOffset = 41672;
	
	  ;% controller_template_P.V_max_Value_i
	  section.data(166).logicalSrcIdx = 165;
	  section.data(166).dtTransOffset = 41673;
	
	  ;% controller_template_P.i_min_Value_o
	  section.data(167).logicalSrcIdx = 166;
	  section.data(167).dtTransOffset = 41703;
	
	  ;% controller_template_P.betas_Value_g
	  section.data(168).logicalSrcIdx = 167;
	  section.data(168).dtTransOffset = 41704;
	
	  ;% controller_template_P.L_Value_m
	  section.data(169).logicalSrcIdx = 168;
	  section.data(169).dtTransOffset = 41712;
	
	  ;% controller_template_P.UnitDelay_X0_a
	  section.data(170).logicalSrcIdx = 169;
	  section.data(170).dtTransOffset = 41713;
	
	  ;% controller_template_P.UnitDelay1_X0_b
	  section.data(171).logicalSrcIdx = 170;
	  section.data(171).dtTransOffset = 41715;
	
	  ;% controller_template_P.Saturation_UpperSat_l
	  section.data(172).logicalSrcIdx = 171;
	  section.data(172).dtTransOffset = 41745;
	
	  ;% controller_template_P.Saturation_LowerSat_c
	  section.data(173).logicalSrcIdx = 172;
	  section.data(173).dtTransOffset = 41746;
	
	  ;% controller_template_P.TT_PP_Value_o
	  section.data(174).logicalSrcIdx = 173;
	  section.data(174).dtTransOffset = 41747;
	
	  ;% controller_template_P.LL_PP_Value_j5
	  section.data(175).logicalSrcIdx = 174;
	  section.data(175).dtTransOffset = 42647;
	
	  ;% controller_template_P.LL_ref_PP_Value_e
	  section.data(176).logicalSrcIdx = 175;
	  section.data(176).dtTransOffset = 42707;
	
	  ;% controller_template_P.LL_U_ref_PP_Value_b
	  section.data(177).logicalSrcIdx = 176;
	  section.data(177).dtTransOffset = 44567;
	
	  ;% controller_template_P.MM_Value_g
	  section.data(178).logicalSrcIdx = 177;
	  section.data(178).dtTransOffset = 45467;
	
	  ;% controller_template_P.PP_Value_p
	  section.data(179).logicalSrcIdx = 178;
	  section.data(179).dtTransOffset = 45471;
	
	  ;% controller_template_P.AA_delay_Value_o
	  section.data(180).logicalSrcIdx = 179;
	  section.data(180).dtTransOffset = 46371;
	
	  ;% controller_template_P.BB_delay_Value_d
	  section.data(181).logicalSrcIdx = 180;
	  section.data(181).dtTransOffset = 46375;
	
	  ;% controller_template_P.A_Value_k
	  section.data(182).logicalSrcIdx = 181;
	  section.data(182).dtTransOffset = 46387;
	
	  ;% controller_template_P.B_Value_f
	  section.data(183).logicalSrcIdx = 182;
	  section.data(183).dtTransOffset = 46396;
	
	  ;% controller_template_P.C_Value_b
	  section.data(184).logicalSrcIdx = 183;
	  section.data(184).dtTransOffset = 46399;
	
	  ;% controller_template_P.D_Value_c
	  section.data(185).logicalSrcIdx = 184;
	  section.data(185).dtTransOffset = 46405;
	
	  ;% controller_template_P.Q_Value_g
	  section.data(186).logicalSrcIdx = 185;
	  section.data(186).dtTransOffset = 46407;
	
	  ;% controller_template_P.R_Value_o
	  section.data(187).logicalSrcIdx = 186;
	  section.data(187).dtTransOffset = 46416;
	
	  ;% controller_template_P.UnitDelay1_X0_n
	  section.data(188).logicalSrcIdx = 187;
	  section.data(188).dtTransOffset = 46420;
	
	  ;% controller_template_P.FixPtUnitDelay1_X0_e
	  section.data(189).logicalSrcIdx = 188;
	  section.data(189).dtTransOffset = 46429;
	
	  ;% controller_template_P.V_max_Value_f
	  section.data(190).logicalSrcIdx = 189;
	  section.data(190).dtTransOffset = 46430;
	
	  ;% controller_template_P.i_min_Value_n
	  section.data(191).logicalSrcIdx = 190;
	  section.data(191).dtTransOffset = 46460;
	
	  ;% controller_template_P.betas_Value_j
	  section.data(192).logicalSrcIdx = 191;
	  section.data(192).dtTransOffset = 46461;
	
	  ;% controller_template_P.L_Value_g
	  section.data(193).logicalSrcIdx = 192;
	  section.data(193).dtTransOffset = 46466;
	
	  ;% controller_template_P.UnitDelay_X0_fj
	  section.data(194).logicalSrcIdx = 193;
	  section.data(194).dtTransOffset = 46467;
	
	  ;% controller_template_P.UnitDelay1_X0_o
	  section.data(195).logicalSrcIdx = 194;
	  section.data(195).dtTransOffset = 46473;
	
	  ;% controller_template_P.Saturation_UpperSat_o3
	  section.data(196).logicalSrcIdx = 195;
	  section.data(196).dtTransOffset = 46503;
	
	  ;% controller_template_P.Saturation_LowerSat_kn
	  section.data(197).logicalSrcIdx = 196;
	  section.data(197).dtTransOffset = 46504;
	
	  ;% controller_template_P.g_Value_m
	  section.data(198).logicalSrcIdx = 197;
	  section.data(198).dtTransOffset = 46505;
	
	  ;% controller_template_P.raddeg2_Gain_p
	  section.data(199).logicalSrcIdx = 198;
	  section.data(199).dtTransOffset = 46506;
	
	  ;% controller_template_P.raddeg1_Gain_a
	  section.data(200).logicalSrcIdx = 199;
	  section.data(200).dtTransOffset = 46507;
	
	  ;% controller_template_P.raddeg3_Gain_k
	  section.data(201).logicalSrcIdx = 200;
	  section.data(201).dtTransOffset = 46508;
	
	  ;% controller_template_P.raddeg_Gain_k
	  section.data(202).logicalSrcIdx = 201;
	  section.data(202).dtTransOffset = 46509;
	
	  ;% controller_template_P.pitch_offset_Value
	  section.data(203).logicalSrcIdx = 202;
	  section.data(203).dtTransOffset = 46510;
	
	  ;% controller_template_P.InitialCondition_Value
	  section.data(204).logicalSrcIdx = 203;
	  section.data(204).dtTransOffset = 46511;
	
	  ;% controller_template_P.Constant1_Value_mr
	  section.data(205).logicalSrcIdx = 204;
	  section.data(205).dtTransOffset = 46512;
	
	  ;% controller_template_P.Constant2_Value_a
	  section.data(206).logicalSrcIdx = 205;
	  section.data(206).dtTransOffset = 46513;
	
	  ;% controller_template_P.FixPtUnitDelay1_X0_h
	  section.data(207).logicalSrcIdx = 206;
	  section.data(207).dtTransOffset = 46514;
	
	  ;% controller_template_P.pitch_cmd2pitch_Gain
	  section.data(208).logicalSrcIdx = 207;
	  section.data(208).dtTransOffset = 46515;
	
	  ;% controller_template_P.Gain1_Gain
	  section.data(209).logicalSrcIdx = 208;
	  section.data(209).dtTransOffset = 46516;
	
	  ;% controller_template_P.roll_offset_Value
	  section.data(210).logicalSrcIdx = 209;
	  section.data(210).dtTransOffset = 46517;
	
	  ;% controller_template_P.roll_cmd2roll_Gain
	  section.data(211).logicalSrcIdx = 210;
	  section.data(211).dtTransOffset = 46518;
	
	  ;% controller_template_P.Gain2_Gain
	  section.data(212).logicalSrcIdx = 211;
	  section.data(212).dtTransOffset = 46519;
	
	  ;% controller_template_P.gravity_Value_ch
	  section.data(213).logicalSrcIdx = 212;
	  section.data(213).dtTransOffset = 46520;
	
	  ;% controller_template_P.trhust_cmd2thrust_Gain
	  section.data(214).logicalSrcIdx = 213;
	  section.data(214).dtTransOffset = 46521;
	
	  ;% controller_template_P.Gain_Gain_k
	  section.data(215).logicalSrcIdx = 214;
	  section.data(215).dtTransOffset = 46522;
	
	  ;% controller_template_P.Gain3_Gain
	  section.data(216).logicalSrcIdx = 215;
	  section.data(216).dtTransOffset = 46523;
	
	  ;% controller_template_P.Gain4_Gain
	  section.data(217).logicalSrcIdx = 216;
	  section.data(217).dtTransOffset = 46524;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% controller_template_P.IntegerDelay_DelayLength
	  section.data(1).logicalSrcIdx = 217;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_P.IntegerDelay1_DelayLength
	  section.data(2).logicalSrcIdx = 218;
	  section.data(2).dtTransOffset = 1;
	
	  ;% controller_template_P.IntegerDelay2_DelayLength
	  section.data(3).logicalSrcIdx = 219;
	  section.data(3).dtTransOffset = 2;
	
	  ;% controller_template_P.IntegerDelay3_DelayLength
	  section.data(4).logicalSrcIdx = 220;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 12;
      section.data(12)  = dumData; %prealloc
      
	  ;% controller_template_P.FixPtUnitDelay2_X0
	  section.data(1).logicalSrcIdx = 221;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_P.FixPtUnitDelay2_X0_n
	  section.data(2).logicalSrcIdx = 222;
	  section.data(2).dtTransOffset = 1;
	
	  ;% controller_template_P.FixPtUnitDelay2_X0_d
	  section.data(3).logicalSrcIdx = 223;
	  section.data(3).dtTransOffset = 2;
	
	  ;% controller_template_P.FixPtUnitDelay2_X0_i
	  section.data(4).logicalSrcIdx = 224;
	  section.data(4).dtTransOffset = 3;
	
	  ;% controller_template_P.FixPtConstant_Value
	  section.data(5).logicalSrcIdx = 225;
	  section.data(5).dtTransOffset = 4;
	
	  ;% controller_template_P.FixPtConstant_Value_o
	  section.data(6).logicalSrcIdx = 226;
	  section.data(6).dtTransOffset = 5;
	
	  ;% controller_template_P.FixPtConstant_Value_n
	  section.data(7).logicalSrcIdx = 227;
	  section.data(7).dtTransOffset = 6;
	
	  ;% controller_template_P.FixPtConstant_Value_p
	  section.data(8).logicalSrcIdx = 228;
	  section.data(8).dtTransOffset = 7;
	
	  ;% controller_template_P.FixPtUnitDelay2_X0_g
	  section.data(9).logicalSrcIdx = 229;
	  section.data(9).dtTransOffset = 8;
	
	  ;% controller_template_P.Constant_Value_a3
	  section.data(10).logicalSrcIdx = 230;
	  section.data(10).dtTransOffset = 9;
	
	  ;% controller_template_P.SwitchControl_Threshold
	  section.data(11).logicalSrcIdx = 231;
	  section.data(11).dtTransOffset = 10;
	
	  ;% controller_template_P.FixPtConstant_Value_i
	  section.data(12).logicalSrcIdx = 232;
	  section.data(12).dtTransOffset = 11;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
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
    nTotSects     = 11;
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
    ;% Auto data (controller_template_B)
    ;%
      section.nData     = 73;
      section.data(73)  = dumData; %prealloc
      
	  ;% controller_template_B.DataTypeConversion
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_B.X_ref_x
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 30;
	
	  ;% controller_template_B.X_ref_y
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 123;
	
	  ;% controller_template_B.X_ref_z
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 216;
	
	  ;% controller_template_B.X_ref_yaw
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 278;
	
	  ;% controller_template_B.MultiportSwitch
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 340;
	
	  ;% controller_template_B.pitch_cmd
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 341;
	
	  ;% controller_template_B.roll_cmd
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 342;
	
	  ;% controller_template_B.thrust_cmd
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 343;
	
	  ;% controller_template_B.yaw_rate_cmd
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 344;
	
	  ;% controller_template_B.pitch_bias
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 345;
	
	  ;% controller_template_B.roll_bias
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 346;
	
	  ;% controller_template_B.thrust_bias
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 347;
	
	  ;% controller_template_B.yaw_rate_bias
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 348;
	
	  ;% controller_template_B.raddeg2
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 349;
	
	  ;% controller_template_B.raddeg1
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 352;
	
	  ;% controller_template_B.raddeg3
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 355;
	
	  ;% controller_template_B.raddeg
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 358;
	
	  ;% controller_template_B.bias_W
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 362;
	
	  ;% controller_template_B.cmd_W
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 366;
	
	  ;% controller_template_B.pitch_rot
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 370;
	
	  ;% controller_template_B.roll_rot
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 371;
	
	  ;% controller_template_B.pitch_bias_rot
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 372;
	
	  ;% controller_template_B.roll_bias_rot
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 373;
	
	  ;% controller_template_B.pitch_cmd_comp
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 374;
	
	  ;% controller_template_B.roll_cmd_comp
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 375;
	
	  ;% controller_template_B.thrust_comp
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 376;
	
	  ;% controller_template_B.thrust_cmd_e
	  section.data(28).logicalSrcIdx = 31;
	  section.data(28).dtTransOffset = 377;
	
	  ;% controller_template_B.u_opt
	  section.data(29).logicalSrcIdx = 32;
	  section.data(29).dtTransOffset = 378;
	
	  ;% controller_template_B.J_star
	  section.data(30).logicalSrcIdx = 33;
	  section.data(30).dtTransOffset = 379;
	
	  ;% controller_template_B.u_buff_out
	  section.data(31).logicalSrcIdx = 34;
	  section.data(31).dtTransOffset = 380;
	
	  ;% controller_template_B.V_init_out
	  section.data(32).logicalSrcIdx = 35;
	  section.data(32).dtTransOffset = 382;
	
	  ;% controller_template_B.u_opt_l
	  section.data(33).logicalSrcIdx = 36;
	  section.data(33).dtTransOffset = 412;
	
	  ;% controller_template_B.J_star_h
	  section.data(34).logicalSrcIdx = 37;
	  section.data(34).dtTransOffset = 413;
	
	  ;% controller_template_B.u_buff_out_i
	  section.data(35).logicalSrcIdx = 38;
	  section.data(35).dtTransOffset = 414;
	
	  ;% controller_template_B.V_init_out_n
	  section.data(36).logicalSrcIdx = 39;
	  section.data(36).dtTransOffset = 420;
	
	  ;% controller_template_B.raddeg2_p
	  section.data(37).logicalSrcIdx = 40;
	  section.data(37).dtTransOffset = 450;
	
	  ;% controller_template_B.raddeg1_e
	  section.data(38).logicalSrcIdx = 41;
	  section.data(38).dtTransOffset = 453;
	
	  ;% controller_template_B.raddeg3_a
	  section.data(39).logicalSrcIdx = 42;
	  section.data(39).dtTransOffset = 456;
	
	  ;% controller_template_B.raddeg_j
	  section.data(40).logicalSrcIdx = 43;
	  section.data(40).dtTransOffset = 459;
	
	  ;% controller_template_B.bias_W_b
	  section.data(41).logicalSrcIdx = 44;
	  section.data(41).dtTransOffset = 463;
	
	  ;% controller_template_B.cmd_W_h
	  section.data(42).logicalSrcIdx = 45;
	  section.data(42).dtTransOffset = 467;
	
	  ;% controller_template_B.pitch_rot_n
	  section.data(43).logicalSrcIdx = 46;
	  section.data(43).dtTransOffset = 471;
	
	  ;% controller_template_B.roll_rot_e
	  section.data(44).logicalSrcIdx = 47;
	  section.data(44).dtTransOffset = 472;
	
	  ;% controller_template_B.pitch_bias_rot_i
	  section.data(45).logicalSrcIdx = 48;
	  section.data(45).dtTransOffset = 473;
	
	  ;% controller_template_B.roll_bias_rot_d
	  section.data(46).logicalSrcIdx = 49;
	  section.data(46).dtTransOffset = 474;
	
	  ;% controller_template_B.pitch_cmd_comp_n
	  section.data(47).logicalSrcIdx = 50;
	  section.data(47).dtTransOffset = 475;
	
	  ;% controller_template_B.roll_cmd_comp_j
	  section.data(48).logicalSrcIdx = 51;
	  section.data(48).dtTransOffset = 476;
	
	  ;% controller_template_B.thrust_comp_k
	  section.data(49).logicalSrcIdx = 52;
	  section.data(49).dtTransOffset = 477;
	
	  ;% controller_template_B.Saturation3
	  section.data(50).logicalSrcIdx = 53;
	  section.data(50).dtTransOffset = 478;
	
	  ;% controller_template_B.RateTransition
	  section.data(51).logicalSrcIdx = 54;
	  section.data(51).dtTransOffset = 479;
	
	  ;% controller_template_B.UnitDelay2
	  section.data(52).logicalSrcIdx = 55;
	  section.data(52).dtTransOffset = 483;
	
	  ;% controller_template_B.RateTransition_i
	  section.data(53).logicalSrcIdx = 56;
	  section.data(53).dtTransOffset = 484;
	
	  ;% controller_template_B.UnitDelay2_o
	  section.data(54).logicalSrcIdx = 57;
	  section.data(54).dtTransOffset = 488;
	
	  ;% controller_template_B.Saturation1
	  section.data(55).logicalSrcIdx = 58;
	  section.data(55).dtTransOffset = 489;
	
	  ;% controller_template_B.Saturation
	  section.data(56).logicalSrcIdx = 59;
	  section.data(56).dtTransOffset = 490;
	
	  ;% controller_template_B.RateTransition_j
	  section.data(57).logicalSrcIdx = 60;
	  section.data(57).dtTransOffset = 491;
	
	  ;% controller_template_B.RateTransition_jf
	  section.data(58).logicalSrcIdx = 61;
	  section.data(58).dtTransOffset = 493;
	
	  ;% controller_template_B.UnitDelay2_e
	  section.data(59).logicalSrcIdx = 62;
	  section.data(59).dtTransOffset = 494;
	
	  ;% controller_template_B.thrust_cmd_a
	  section.data(60).logicalSrcIdx = 63;
	  section.data(60).dtTransOffset = 495;
	
	  ;% controller_template_B.RateTransition1
	  section.data(61).logicalSrcIdx = 64;
	  section.data(61).dtTransOffset = 496;
	
	  ;% controller_template_B.RateTransition1_l
	  section.data(62).logicalSrcIdx = 65;
	  section.data(62).dtTransOffset = 497;
	
	  ;% controller_template_B.RateTransition1_h
	  section.data(63).logicalSrcIdx = 66;
	  section.data(63).dtTransOffset = 498;
	
	  ;% controller_template_B.U
	  section.data(64).logicalSrcIdx = 67;
	  section.data(64).dtTransOffset = 499;
	
	  ;% controller_template_B.flag_oob
	  section.data(65).logicalSrcIdx = 68;
	  section.data(65).dtTransOffset = 500;
	
	  ;% controller_template_B.y
	  section.data(66).logicalSrcIdx = 69;
	  section.data(66).dtTransOffset = 501;
	
	  ;% controller_template_B.U_g
	  section.data(67).logicalSrcIdx = 70;
	  section.data(67).dtTransOffset = 502;
	
	  ;% controller_template_B.flag_oob_l
	  section.data(68).logicalSrcIdx = 71;
	  section.data(68).dtTransOffset = 503;
	
	  ;% controller_template_B.U_p
	  section.data(69).logicalSrcIdx = 72;
	  section.data(69).dtTransOffset = 504;
	
	  ;% controller_template_B.flag_oob_o
	  section.data(70).logicalSrcIdx = 73;
	  section.data(70).dtTransOffset = 505;
	
	  ;% controller_template_B.y_n
	  section.data(71).logicalSrcIdx = 74;
	  section.data(71).dtTransOffset = 506;
	
	  ;% controller_template_B.U_i
	  section.data(72).logicalSrcIdx = 75;
	  section.data(72).dtTransOffset = 507;
	
	  ;% controller_template_B.flag_oob_b
	  section.data(73).logicalSrcIdx = 76;
	  section.data(73).dtTransOffset = 508;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% controller_template_B.sf_EmbeddedMATLABFunction_o.roll_rot
	  section.data(1).logicalSrcIdx = 77;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_B.sf_EmbeddedMATLABFunction_o.pitch_rot
	  section.data(2).logicalSrcIdx = 78;
	  section.data(2).dtTransOffset = 1;
	
	  ;% controller_template_B.sf_EmbeddedMATLABFunction_o.pitch_bias_rot
	  section.data(3).logicalSrcIdx = 79;
	  section.data(3).dtTransOffset = 2;
	
	  ;% controller_template_B.sf_EmbeddedMATLABFunction_o.roll_bias_rot
	  section.data(4).logicalSrcIdx = 80;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_B.sf_discretekalmanfilter_k.state_est
	  section.data(1).logicalSrcIdx = 81;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_B.sf_discretekalmanfilter_k.P_est
	  section.data(2).logicalSrcIdx = 82;
	  section.data(2).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_B.sf_discretekalmanfilter_n.state_est
	  section.data(1).logicalSrcIdx = 83;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_B.sf_discretekalmanfilter_n.P_est
	  section.data(2).logicalSrcIdx = 84;
	  section.data(2).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_B.sf_discretekalmanfilter_m.state_est
	  section.data(1).logicalSrcIdx = 85;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_B.sf_discretekalmanfilter_m.P_est
	  section.data(2).logicalSrcIdx = 86;
	  section.data(2).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(5) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% controller_template_B.sf_runFastGradient_d.u_opt
	  section.data(1).logicalSrcIdx = 87;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_B.sf_runFastGradient_d.J_star
	  section.data(2).logicalSrcIdx = 88;
	  section.data(2).dtTransOffset = 1;
	
	  ;% controller_template_B.sf_runFastGradient_d.u_buff_out
	  section.data(3).logicalSrcIdx = 89;
	  section.data(3).dtTransOffset = 2;
	
	  ;% controller_template_B.sf_runFastGradient_d.V_init_out
	  section.data(4).logicalSrcIdx = 90;
	  section.data(4).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(6) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_B.sf_discretekalmanfilter.state_est
	  section.data(1).logicalSrcIdx = 91;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_B.sf_discretekalmanfilter.P_est
	  section.data(2).logicalSrcIdx = 92;
	  section.data(2).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(7) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% controller_template_B.sf_runFastGradient.u_opt
	  section.data(1).logicalSrcIdx = 93;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_B.sf_runFastGradient.J_star
	  section.data(2).logicalSrcIdx = 94;
	  section.data(2).dtTransOffset = 1;
	
	  ;% controller_template_B.sf_runFastGradient.u_buff_out
	  section.data(3).logicalSrcIdx = 95;
	  section.data(3).dtTransOffset = 2;
	
	  ;% controller_template_B.sf_runFastGradient.V_init_out
	  section.data(4).logicalSrcIdx = 96;
	  section.data(4).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(8) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% controller_template_B.sf_EmbeddedMATLABFunction.roll_rot
	  section.data(1).logicalSrcIdx = 97;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_B.sf_EmbeddedMATLABFunction.pitch_rot
	  section.data(2).logicalSrcIdx = 98;
	  section.data(2).dtTransOffset = 1;
	
	  ;% controller_template_B.sf_EmbeddedMATLABFunction.pitch_bias_rot
	  section.data(3).logicalSrcIdx = 99;
	  section.data(3).dtTransOffset = 2;
	
	  ;% controller_template_B.sf_EmbeddedMATLABFunction.roll_bias_rot
	  section.data(4).logicalSrcIdx = 100;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(9) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_B.sf_MATLABFunction_k.y
	  section.data(1).logicalSrcIdx = 101;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(10) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_B.sf_MATLABFunction_f.y
	  section.data(1).logicalSrcIdx = 102;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(11) = section;
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
    nTotSects     = 38;
    sectIdxOffset = 11;
    
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
    ;% Auto data (controller_template_DWork)
    ;%
      section.nData     = 36;
      section.data(36)  = dumData; %prealloc
      
	  ;% controller_template_DWork.FixPtUnitDelay1_DSTATE
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.IntegerDelay_DSTATE
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 4;
	
	  ;% controller_template_DWork.IntegerDelay1_DSTATE
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 5;
	
	  ;% controller_template_DWork.IntegerDelay2_DSTATE
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 6;
	
	  ;% controller_template_DWork.IntegerDelay3_DSTATE
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 7;
	
	  ;% controller_template_DWork.UnitDelay1_DSTATE
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 8;
	
	  ;% controller_template_DWork.FixPtUnitDelay1_DSTATE_i
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 24;
	
	  ;% controller_template_DWork.UnitDelay_DSTATE
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 27;
	
	  ;% controller_template_DWork.UnitDelay1_DSTATE_c
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 30;
	
	  ;% controller_template_DWork.UnitDelay1_DSTATE_b
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 60;
	
	  ;% controller_template_DWork.FixPtUnitDelay1_DSTATE_g
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 76;
	
	  ;% controller_template_DWork.UnitDelay_DSTATE_j
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 79;
	
	  ;% controller_template_DWork.UnitDelay1_DSTATE_l
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 82;
	
	  ;% controller_template_DWork.UnitDelay1_DSTATE_j
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 112;
	
	  ;% controller_template_DWork.FixPtUnitDelay1_DSTATE_d
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 121;
	
	  ;% controller_template_DWork.UnitDelay_DSTATE_l
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 123;
	
	  ;% controller_template_DWork.UnitDelay1_DSTATE_g
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 125;
	
	  ;% controller_template_DWork.UnitDelay1_DSTATE_lx
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 155;
	
	  ;% controller_template_DWork.FixPtUnitDelay1_DSTATE_e
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 164;
	
	  ;% controller_template_DWork.UnitDelay_DSTATE_jz
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 166;
	
	  ;% controller_template_DWork.UnitDelay1_DSTATE_js
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 172;
	
	  ;% controller_template_DWork.UnitDelay2_DSTATE
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 202;
	
	  ;% controller_template_DWork.UnitDelay2_DSTATE_d
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 203;
	
	  ;% controller_template_DWork.UnitDelay_DSTATE_jv
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 204;
	
	  ;% controller_template_DWork.UnitDelay2_DSTATE_l
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 205;
	
	  ;% controller_template_DWork.UnitDelay2_DSTATE_k
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 206;
	
	  ;% controller_template_DWork.UnitDelay_DSTATE_f
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 207;
	
	  ;% controller_template_DWork.UnitDelay2_DSTATE_b
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 208;
	
	  ;% controller_template_DWork.UnitDelay_DSTATE_fw
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 209;
	
	  ;% controller_template_DWork.UnitDelay2_DSTATE_g
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 210;
	
	  ;% controller_template_DWork.UnitDelay2_DSTATE_ga
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 211;
	
	  ;% controller_template_DWork.UnitDelay_DSTATE_p
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 212;
	
	  ;% controller_template_DWork.UnitDelay1_DSTATE_a
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 213;
	
	  ;% controller_template_DWork.UnitDelay1_DSTATE_ji
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 214;
	
	  ;% controller_template_DWork.UnitDelay1_DSTATE_c3
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 215;
	
	  ;% controller_template_DWork.UnitDelay1_DSTATE_m
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 216;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 29;
      section.data(29)  = dumData; %prealloc
      
	  ;% controller_template_DWork.bias_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 36;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.cmd_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 37;
	  section.data(2).dtTransOffset = 1;
	
	  ;% controller_template_DWork.cmd1_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 38;
	  section.data(3).dtTransOffset = 2;
	
	  ;% controller_template_DWork.mode_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 39;
	  section.data(4).dtTransOffset = 3;
	
	  ;% controller_template_DWork.mode2_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 40;
	  section.data(5).dtTransOffset = 4;
	
	  ;% controller_template_DWork.mode1_PWORK.LoggedData
	  section.data(6).logicalSrcIdx = 41;
	  section.data(6).dtTransOffset = 5;
	
	  ;% controller_template_DWork.mode1_PWORK_h.LoggedData
	  section.data(7).logicalSrcIdx = 42;
	  section.data(7).dtTransOffset = 6;
	
	  ;% controller_template_DWork.ToFile_PWORK.FilePtr
	  section.data(8).logicalSrcIdx = 43;
	  section.data(8).dtTransOffset = 7;
	
	  ;% controller_template_DWork.ToFile1_PWORK.FilePtr
	  section.data(9).logicalSrcIdx = 44;
	  section.data(9).dtTransOffset = 8;
	
	  ;% controller_template_DWork.pitchcmd_PWORK.LoggedData
	  section.data(10).logicalSrcIdx = 45;
	  section.data(10).dtTransOffset = 9;
	
	  ;% controller_template_DWork.rollcmd_PWORK.LoggedData
	  section.data(11).logicalSrcIdx = 46;
	  section.data(11).dtTransOffset = 10;
	
	  ;% controller_template_DWork.thrustcmd_PWORK.LoggedData
	  section.data(12).logicalSrcIdx = 47;
	  section.data(12).dtTransOffset = 11;
	
	  ;% controller_template_DWork.x_ref_PWORK.LoggedData
	  section.data(13).logicalSrcIdx = 48;
	  section.data(13).dtTransOffset = 12;
	
	  ;% controller_template_DWork.y_ref_PWORK.LoggedData
	  section.data(14).logicalSrcIdx = 49;
	  section.data(14).dtTransOffset = 13;
	
	  ;% controller_template_DWork.yawcmd_PWORK.LoggedData
	  section.data(15).logicalSrcIdx = 50;
	  section.data(15).dtTransOffset = 14;
	
	  ;% controller_template_DWork.yaw_ref_PWORK.LoggedData
	  section.data(16).logicalSrcIdx = 51;
	  section.data(16).dtTransOffset = 15;
	
	  ;% controller_template_DWork.z_ref_PWORK.LoggedData
	  section.data(17).logicalSrcIdx = 52;
	  section.data(17).dtTransOffset = 16;
	
	  ;% controller_template_DWork.ToFile_PWORK_p.FilePtr
	  section.data(18).logicalSrcIdx = 53;
	  section.data(18).dtTransOffset = 17;
	
	  ;% controller_template_DWork.ToFile1_PWORK_i.FilePtr
	  section.data(19).logicalSrcIdx = 54;
	  section.data(19).dtTransOffset = 18;
	
	  ;% controller_template_DWork.pitchcmd_PWORK_p.LoggedData
	  section.data(20).logicalSrcIdx = 55;
	  section.data(20).dtTransOffset = 19;
	
	  ;% controller_template_DWork.rollcmd_PWORK_i.LoggedData
	  section.data(21).logicalSrcIdx = 56;
	  section.data(21).dtTransOffset = 20;
	
	  ;% controller_template_DWork.thrustcmd_PWORK_g.LoggedData
	  section.data(22).logicalSrcIdx = 57;
	  section.data(22).dtTransOffset = 21;
	
	  ;% controller_template_DWork.x_ref_PWORK_a.LoggedData
	  section.data(23).logicalSrcIdx = 58;
	  section.data(23).dtTransOffset = 22;
	
	  ;% controller_template_DWork.y_ref_PWORK_j.LoggedData
	  section.data(24).logicalSrcIdx = 59;
	  section.data(24).dtTransOffset = 23;
	
	  ;% controller_template_DWork.yawcmd_PWORK_p.LoggedData
	  section.data(25).logicalSrcIdx = 60;
	  section.data(25).dtTransOffset = 24;
	
	  ;% controller_template_DWork.yaw_ref_PWORK_n.LoggedData
	  section.data(26).logicalSrcIdx = 61;
	  section.data(26).dtTransOffset = 25;
	
	  ;% controller_template_DWork.z_ref_PWORK_e.LoggedData
	  section.data(27).logicalSrcIdx = 62;
	  section.data(27).dtTransOffset = 26;
	
	  ;% controller_template_DWork.Scope_PWORK.LoggedData
	  section.data(28).logicalSrcIdx = 63;
	  section.data(28).dtTransOffset = 27;
	
	  ;% controller_template_DWork.Scope_PWORK_f.LoggedData
	  section.data(29).logicalSrcIdx = 64;
	  section.data(29).dtTransOffset = 28;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 12;
      section.data(12)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sfEvent
	  section.data(1).logicalSrcIdx = 65;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.sfEvent_f
	  section.data(2).logicalSrcIdx = 66;
	  section.data(2).dtTransOffset = 1;
	
	  ;% controller_template_DWork.sfEvent_k
	  section.data(3).logicalSrcIdx = 67;
	  section.data(3).dtTransOffset = 2;
	
	  ;% controller_template_DWork.sfEvent_n
	  section.data(4).logicalSrcIdx = 68;
	  section.data(4).dtTransOffset = 3;
	
	  ;% controller_template_DWork.sfEvent_j
	  section.data(5).logicalSrcIdx = 69;
	  section.data(5).dtTransOffset = 4;
	
	  ;% controller_template_DWork.sfEvent_c
	  section.data(6).logicalSrcIdx = 70;
	  section.data(6).dtTransOffset = 5;
	
	  ;% controller_template_DWork.sfEvent_k0
	  section.data(7).logicalSrcIdx = 71;
	  section.data(7).dtTransOffset = 6;
	
	  ;% controller_template_DWork.sfEvent_l
	  section.data(8).logicalSrcIdx = 72;
	  section.data(8).dtTransOffset = 7;
	
	  ;% controller_template_DWork.sfEvent_jv
	  section.data(9).logicalSrcIdx = 73;
	  section.data(9).dtTransOffset = 8;
	
	  ;% controller_template_DWork.sfEvent_cd
	  section.data(10).logicalSrcIdx = 74;
	  section.data(10).dtTransOffset = 9;
	
	  ;% controller_template_DWork.sfEvent_fk
	  section.data(11).logicalSrcIdx = 75;
	  section.data(11).dtTransOffset = 10;
	
	  ;% controller_template_DWork.sfEvent_kl
	  section.data(12).logicalSrcIdx = 76;
	  section.data(12).dtTransOffset = 11;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% controller_template_DWork.ToFile_IWORK.Count
	  section.data(1).logicalSrcIdx = 77;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.ToFile1_IWORK.Count
	  section.data(2).logicalSrcIdx = 78;
	  section.data(2).dtTransOffset = 1;
	
	  ;% controller_template_DWork.ToFile_IWORK_g.Count
	  section.data(3).logicalSrcIdx = 79;
	  section.data(3).dtTransOffset = 2;
	
	  ;% controller_template_DWork.ToFile1_IWORK_p.Count
	  section.data(4).logicalSrcIdx = 80;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% controller_template_DWork.FixPtUnitDelay2_DSTATE
	  section.data(1).logicalSrcIdx = 81;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.FixPtUnitDelay2_DSTATE_l
	  section.data(2).logicalSrcIdx = 82;
	  section.data(2).dtTransOffset = 1;
	
	  ;% controller_template_DWork.FixPtUnitDelay2_DSTATE_b
	  section.data(3).logicalSrcIdx = 83;
	  section.data(3).dtTransOffset = 2;
	
	  ;% controller_template_DWork.FixPtUnitDelay2_DSTATE_c
	  section.data(4).logicalSrcIdx = 84;
	  section.data(4).dtTransOffset = 3;
	
	  ;% controller_template_DWork.FixPtUnitDelay2_DSTATE_a
	  section.data(5).logicalSrcIdx = 85;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_DWork.FreeFlightPosCtrl_SubsysRanBC
	  section.data(1).logicalSrcIdx = 86;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.poscontroller_SubsysRanBC
	  section.data(2).logicalSrcIdx = 87;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 12;
      section.data(12)  = dumData; %prealloc
      
	  ;% controller_template_DWork.is_active_c4_Hquad_control_LIB_
	  section.data(1).logicalSrcIdx = 88;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.is_active_c1_Hquad_control_LIB_
	  section.data(2).logicalSrcIdx = 89;
	  section.data(2).dtTransOffset = 1;
	
	  ;% controller_template_DWork.is_active_c8_Hquad_control_LIB_
	  section.data(3).logicalSrcIdx = 90;
	  section.data(3).dtTransOffset = 2;
	
	  ;% controller_template_DWork.is_active_c9_Hquad_control_LIB_
	  section.data(4).logicalSrcIdx = 91;
	  section.data(4).dtTransOffset = 3;
	
	  ;% controller_template_DWork.is_active_c4_Hquad_control_LI_d
	  section.data(5).logicalSrcIdx = 92;
	  section.data(5).dtTransOffset = 4;
	
	  ;% controller_template_DWork.is_active_c1_Hquad_control_LI_l
	  section.data(6).logicalSrcIdx = 93;
	  section.data(6).dtTransOffset = 5;
	
	  ;% controller_template_DWork.is_active_c3_controller_templat
	  section.data(7).logicalSrcIdx = 94;
	  section.data(7).dtTransOffset = 6;
	
	  ;% controller_template_DWork.is_active_c6_controller_templat
	  section.data(8).logicalSrcIdx = 95;
	  section.data(8).dtTransOffset = 7;
	
	  ;% controller_template_DWork.is_active_c4_controller_templat
	  section.data(9).logicalSrcIdx = 96;
	  section.data(9).dtTransOffset = 8;
	
	  ;% controller_template_DWork.is_active_c2_controller_templat
	  section.data(10).logicalSrcIdx = 97;
	  section.data(10).dtTransOffset = 9;
	
	  ;% controller_template_DWork.is_active_c8_controller_templat
	  section.data(11).logicalSrcIdx = 98;
	  section.data(11).dtTransOffset = 10;
	
	  ;% controller_template_DWork.is_active_c1_controller_templat
	  section.data(12).logicalSrcIdx = 99;
	  section.data(12).dtTransOffset = 11;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 26;
      section.data(26)  = dumData; %prealloc
      
	  ;% controller_template_DWork.isStable
	  section.data(1).logicalSrcIdx = 100;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 101;
	  section.data(2).dtTransOffset = 1;
	
	  ;% controller_template_DWork.isStable_m
	  section.data(3).logicalSrcIdx = 102;
	  section.data(3).dtTransOffset = 2;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_e
	  section.data(4).logicalSrcIdx = 103;
	  section.data(4).dtTransOffset = 3;
	
	  ;% controller_template_DWork.isStable_i
	  section.data(5).logicalSrcIdx = 104;
	  section.data(5).dtTransOffset = 4;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_h
	  section.data(6).logicalSrcIdx = 105;
	  section.data(6).dtTransOffset = 5;
	
	  ;% controller_template_DWork.isStable_h
	  section.data(7).logicalSrcIdx = 106;
	  section.data(7).dtTransOffset = 6;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_o
	  section.data(8).logicalSrcIdx = 107;
	  section.data(8).dtTransOffset = 7;
	
	  ;% controller_template_DWork.isStable_o
	  section.data(9).logicalSrcIdx = 108;
	  section.data(9).dtTransOffset = 8;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_c
	  section.data(10).logicalSrcIdx = 109;
	  section.data(10).dtTransOffset = 9;
	
	  ;% controller_template_DWork.isStable_mf
	  section.data(11).logicalSrcIdx = 110;
	  section.data(11).dtTransOffset = 10;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_a
	  section.data(12).logicalSrcIdx = 111;
	  section.data(12).dtTransOffset = 11;
	
	  ;% controller_template_DWork.isStable_c
	  section.data(13).logicalSrcIdx = 112;
	  section.data(13).dtTransOffset = 12;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_ha
	  section.data(14).logicalSrcIdx = 113;
	  section.data(14).dtTransOffset = 13;
	
	  ;% controller_template_DWork.isStable_oc
	  section.data(15).logicalSrcIdx = 114;
	  section.data(15).dtTransOffset = 14;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_m
	  section.data(16).logicalSrcIdx = 115;
	  section.data(16).dtTransOffset = 15;
	
	  ;% controller_template_DWork.isStable_hg
	  section.data(17).logicalSrcIdx = 116;
	  section.data(17).dtTransOffset = 16;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_p
	  section.data(18).logicalSrcIdx = 117;
	  section.data(18).dtTransOffset = 17;
	
	  ;% controller_template_DWork.isStable_k
	  section.data(19).logicalSrcIdx = 118;
	  section.data(19).dtTransOffset = 18;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_d
	  section.data(20).logicalSrcIdx = 119;
	  section.data(20).dtTransOffset = 19;
	
	  ;% controller_template_DWork.isStable_a
	  section.data(21).logicalSrcIdx = 120;
	  section.data(21).dtTransOffset = 20;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_h2
	  section.data(22).logicalSrcIdx = 121;
	  section.data(22).dtTransOffset = 21;
	
	  ;% controller_template_DWork.isStable_f
	  section.data(23).logicalSrcIdx = 122;
	  section.data(23).dtTransOffset = 22;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_g
	  section.data(24).logicalSrcIdx = 123;
	  section.data(24).dtTransOffset = 23;
	
	  ;% controller_template_DWork.FreeFlightPosCtrl_MODE
	  section.data(25).logicalSrcIdx = 124;
	  section.data(25).dtTransOffset = 24;
	
	  ;% controller_template_DWork.poscontroller_MODE
	  section.data(26).logicalSrcIdx = 125;
	  section.data(26).dtTransOffset = 25;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_EmbeddedMATLABFunction_o.sfEvent
	  section.data(1).logicalSrcIdx = 126;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_EmbeddedMATLABFunction_o.is_active_c26_Hquad_control_LIB
	  section.data(1).logicalSrcIdx = 127;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(10) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_EmbeddedMATLABFunction_o.isStable
	  section.data(1).logicalSrcIdx = 128;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.sf_EmbeddedMATLABFunction_o.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 129;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(11) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_discretekalmanfilter_k.sfEvent
	  section.data(1).logicalSrcIdx = 130;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(12) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_discretekalmanfilter_k.is_active_c5_Hquad_control_LIB_
	  section.data(1).logicalSrcIdx = 131;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(13) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_discretekalmanfilter_k.isStable
	  section.data(1).logicalSrcIdx = 132;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.sf_discretekalmanfilter_k.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 133;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(14) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_discretekalmanfilter_n.sfEvent
	  section.data(1).logicalSrcIdx = 134;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(15) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_discretekalmanfilter_n.is_active_c5_Hquad_control_LIB_
	  section.data(1).logicalSrcIdx = 135;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(16) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_discretekalmanfilter_n.isStable
	  section.data(1).logicalSrcIdx = 136;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.sf_discretekalmanfilter_n.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 137;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(17) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_discretekalmanfilter_m.sfEvent
	  section.data(1).logicalSrcIdx = 138;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(18) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_discretekalmanfilter_m.is_active_c11_Hquad_control_LIB
	  section.data(1).logicalSrcIdx = 139;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(19) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_discretekalmanfilter_m.isStable
	  section.data(1).logicalSrcIdx = 140;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.sf_discretekalmanfilter_m.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 141;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(20) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_runFastGradient_d.sfEvent
	  section.data(1).logicalSrcIdx = 142;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(21) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_runFastGradient_d.is_active_c6_Hquad_control_LIB_
	  section.data(1).logicalSrcIdx = 143;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(22) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_runFastGradient_d.isStable
	  section.data(1).logicalSrcIdx = 144;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.sf_runFastGradient_d.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 145;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(23) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_discretekalmanfilter.sfEvent
	  section.data(1).logicalSrcIdx = 146;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(24) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_discretekalmanfilter.is_active_c11_Hquad_control_LIB
	  section.data(1).logicalSrcIdx = 147;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(25) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_discretekalmanfilter.isStable
	  section.data(1).logicalSrcIdx = 148;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.sf_discretekalmanfilter.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 149;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(26) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_runFastGradient.sfEvent
	  section.data(1).logicalSrcIdx = 150;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(27) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_runFastGradient.is_active_c6_Hquad_control_LIB_
	  section.data(1).logicalSrcIdx = 151;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(28) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_runFastGradient.isStable
	  section.data(1).logicalSrcIdx = 152;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.sf_runFastGradient.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 153;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(29) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_EmbeddedMATLABFunction.sfEvent
	  section.data(1).logicalSrcIdx = 154;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(30) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_EmbeddedMATLABFunction.is_active_c26_Hquad_control_LIB
	  section.data(1).logicalSrcIdx = 155;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(31) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_EmbeddedMATLABFunction.isStable
	  section.data(1).logicalSrcIdx = 156;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.sf_EmbeddedMATLABFunction.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 157;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(32) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_MATLABFunction_k.sfEvent
	  section.data(1).logicalSrcIdx = 158;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(33) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_MATLABFunction_k.is_active_c7_controller_templat
	  section.data(1).logicalSrcIdx = 159;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(34) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_MATLABFunction_k.isStable
	  section.data(1).logicalSrcIdx = 160;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.sf_MATLABFunction_k.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 161;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(35) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_MATLABFunction_f.sfEvent
	  section.data(1).logicalSrcIdx = 162;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(36) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_MATLABFunction_f.is_active_c7_controller_templat
	  section.data(1).logicalSrcIdx = 163;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(37) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_MATLABFunction_f.isStable
	  section.data(1).logicalSrcIdx = 164;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.sf_MATLABFunction_f.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 165;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(38) = section;
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


  targMap.checksum0 = 808419355;
  targMap.checksum1 = 149421341;
  targMap.checksum2 = 4087441434;
  targMap.checksum3 = 3271846147;

