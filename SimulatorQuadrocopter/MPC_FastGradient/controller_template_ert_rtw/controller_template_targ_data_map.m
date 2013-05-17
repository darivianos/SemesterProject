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
      section.nData     = 252;
      section.data(252)  = dumData; %prealloc
      
	  ;% controller_template_P.Constant3_Value
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_P.Constant1_Value
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 8;
	
	  ;% controller_template_P.Constant2_Value
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 16;
	
	  ;% controller_template_P.Constant_Value
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 32;
	
	  ;% controller_template_P.IntegerDelay3_InitialCondition
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 48;
	
	  ;% controller_template_P.gravity_Value
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 49;
	
	  ;% controller_template_P.Saturation_UpperSat
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 50;
	
	  ;% controller_template_P.Saturation_LowerSat
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 51;
	
	  ;% controller_template_P.Saturation1_UpperSat
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 52;
	
	  ;% controller_template_P.Saturation1_LowerSat
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 53;
	
	  ;% controller_template_P.SliderGain_Gain
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 54;
	
	  ;% controller_template_P.Constant_Value_f
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 55;
	
	  ;% controller_template_P.SliderGain_Gain_e
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 56;
	
	  ;% controller_template_P.Constant1_Value_g
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 57;
	
	  ;% controller_template_P.SliderGain_Gain_f
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 58;
	
	  ;% controller_template_P.Saturation3_UpperSat
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 59;
	
	  ;% controller_template_P.Saturation3_LowerSat
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 60;
	
	  ;% controller_template_P.Saturation2_UpperSat
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 61;
	
	  ;% controller_template_P.Saturation2_LowerSat
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 62;
	
	  ;% controller_template_P.UnitDelay2_X0
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 63;
	
	  ;% controller_template_P.Saturation_UpperSat_a
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 64;
	
	  ;% controller_template_P.Saturation_LowerSat_e
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 65;
	
	  ;% controller_template_P.Saturation1_UpperSat_n
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 66;
	
	  ;% controller_template_P.Saturation1_LowerSat_c
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 67;
	
	  ;% controller_template_P.Saturation3_UpperSat_i
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 68;
	
	  ;% controller_template_P.Saturation3_LowerSat_k
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 69;
	
	  ;% controller_template_P.Saturation2_UpperSat_g
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 70;
	
	  ;% controller_template_P.Saturation2_LowerSat_o
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 71;
	
	  ;% controller_template_P.Constant_Value_o
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 72;
	
	  ;% controller_template_P.Constant1_Value_d
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 12344;
	
	  ;% controller_template_P.Constant2_Value_i
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 15412;
	
	  ;% controller_template_P.Constant3_Value_o
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 16796;
	
	  ;% controller_template_P.Constant4_Value
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 17142;
	
	  ;% controller_template_P.Saturation4_UpperSat
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 17488;
	
	  ;% controller_template_P.Saturation4_LowerSat
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 17489;
	
	  ;% controller_template_P.UnitDelay2_X0_m
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 17490;
	
	  ;% controller_template_P.UnitDelay_X0
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 17491;
	
	  ;% controller_template_P.Gain_Gain
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 17492;
	
	  ;% controller_template_P.Saturation_UpperSat_h
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 17493;
	
	  ;% controller_template_P.Saturation_LowerSat_d
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 17494;
	
	  ;% controller_template_P.Saturation1_UpperSat_o
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 17495;
	
	  ;% controller_template_P.Saturation1_LowerSat_cl
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 17496;
	
	  ;% controller_template_P.SliderGain_Gain_g
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 17497;
	
	  ;% controller_template_P.Constant_Value_g
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 17498;
	
	  ;% controller_template_P.SliderGain_Gain_b
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 17499;
	
	  ;% controller_template_P.Saturation3_UpperSat_n
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 17500;
	
	  ;% controller_template_P.Saturation3_LowerSat_c
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 17501;
	
	  ;% controller_template_P.Saturation2_UpperSat_b
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 17502;
	
	  ;% controller_template_P.Saturation2_LowerSat_h
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 17503;
	
	  ;% controller_template_P.Constant_Value_c
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 17504;
	
	  ;% controller_template_P.Constant1_Value_gy
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 17520;
	
	  ;% controller_template_P.UnitDelay2_X0_d
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 17528;
	
	  ;% controller_template_P.Constant_Value_l
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 17529;
	
	  ;% controller_template_P.Constant1_Value_j
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 22061;
	
	  ;% controller_template_P.Constant2_Value_j
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 23194;
	
	  ;% controller_template_P.Constant3_Value_ok
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 23730;
	
	  ;% controller_template_P.Constant4_Value_g
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 23864;
	
	  ;% controller_template_P.Saturation4_UpperSat_i
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 23998;
	
	  ;% controller_template_P.Saturation4_LowerSat_h
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 23999;
	
	  ;% controller_template_P.UnitDelay2_X0_n
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 24000;
	
	  ;% controller_template_P.UnitDelay_X0_f
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 24001;
	
	  ;% controller_template_P.Gain_Gain_f
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 24002;
	
	  ;% controller_template_P.Saturation1_UpperSat_d
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 24003;
	
	  ;% controller_template_P.Saturation1_LowerSat_n
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 24004;
	
	  ;% controller_template_P.Saturation_UpperSat_d
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 24005;
	
	  ;% controller_template_P.Saturation_LowerSat_b
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 24006;
	
	  ;% controller_template_P.Constant_Value_b
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 24007;
	
	  ;% controller_template_P.Constant1_Value_l
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 24231;
	
	  ;% controller_template_P.Constant2_Value_g
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 24343;
	
	  ;% controller_template_P.Constant3_Value_m
	  section.data(70).logicalSrcIdx = 69;
	  section.data(70).dtTransOffset = 24397;
	
	  ;% controller_template_P.Constant4_Value_a
	  section.data(71).logicalSrcIdx = 70;
	  section.data(71).dtTransOffset = 24424;
	
	  ;% controller_template_P.Saturation2_UpperSat_k
	  section.data(72).logicalSrcIdx = 71;
	  section.data(72).dtTransOffset = 24451;
	
	  ;% controller_template_P.Saturation2_LowerSat_j
	  section.data(73).logicalSrcIdx = 72;
	  section.data(73).dtTransOffset = 24452;
	
	  ;% controller_template_P.UnitDelay2_X0_o
	  section.data(74).logicalSrcIdx = 73;
	  section.data(74).dtTransOffset = 24453;
	
	  ;% controller_template_P.UnitDelay_X0_i
	  section.data(75).logicalSrcIdx = 74;
	  section.data(75).dtTransOffset = 24454;
	
	  ;% controller_template_P.Gain_Gain_p
	  section.data(76).logicalSrcIdx = 75;
	  section.data(76).dtTransOffset = 24455;
	
	  ;% controller_template_P.A_Value
	  section.data(77).logicalSrcIdx = 76;
	  section.data(77).dtTransOffset = 24456;
	
	  ;% controller_template_P.B_Value
	  section.data(78).logicalSrcIdx = 77;
	  section.data(78).dtTransOffset = 24465;
	
	  ;% controller_template_P.C_Value
	  section.data(79).logicalSrcIdx = 78;
	  section.data(79).dtTransOffset = 24468;
	
	  ;% controller_template_P.D_Value
	  section.data(80).logicalSrcIdx = 79;
	  section.data(80).dtTransOffset = 24474;
	
	  ;% controller_template_P.Q_Value
	  section.data(81).logicalSrcIdx = 80;
	  section.data(81).dtTransOffset = 24476;
	
	  ;% controller_template_P.R_Value
	  section.data(82).logicalSrcIdx = 81;
	  section.data(82).dtTransOffset = 24485;
	
	  ;% controller_template_P.UnitDelay1_X0
	  section.data(83).logicalSrcIdx = 82;
	  section.data(83).dtTransOffset = 24489;
	
	  ;% controller_template_P.FixPtUnitDelay1_X0
	  section.data(84).logicalSrcIdx = 83;
	  section.data(84).dtTransOffset = 24498;
	
	  ;% controller_template_P.SliderGain_Gain_a
	  section.data(85).logicalSrcIdx = 84;
	  section.data(85).dtTransOffset = 24499;
	
	  ;% controller_template_P.Constant_Value_fv
	  section.data(86).logicalSrcIdx = 85;
	  section.data(86).dtTransOffset = 24500;
	
	  ;% controller_template_P.SliderGain_Gain_j
	  section.data(87).logicalSrcIdx = 86;
	  section.data(87).dtTransOffset = 24501;
	
	  ;% controller_template_P.Saturation_UpperSat_o
	  section.data(88).logicalSrcIdx = 87;
	  section.data(88).dtTransOffset = 24502;
	
	  ;% controller_template_P.Saturation_LowerSat_p
	  section.data(89).logicalSrcIdx = 88;
	  section.data(89).dtTransOffset = 24503;
	
	  ;% controller_template_P.Constant_Value_h
	  section.data(90).logicalSrcIdx = 89;
	  section.data(90).dtTransOffset = 24504;
	
	  ;% controller_template_P.Constant1_Value_m
	  section.data(91).logicalSrcIdx = 90;
	  section.data(91).dtTransOffset = 24505;
	
	  ;% controller_template_P.UnitDelay2_X0_ng
	  section.data(92).logicalSrcIdx = 91;
	  section.data(92).dtTransOffset = 24506;
	
	  ;% controller_template_P.Constant_Value_a
	  section.data(93).logicalSrcIdx = 92;
	  section.data(93).dtTransOffset = 24507;
	
	  ;% controller_template_P.Constant1_Value_gs
	  section.data(94).logicalSrcIdx = 93;
	  section.data(94).dtTransOffset = 24509;
	
	  ;% controller_template_P.Constant2_Value_jq
	  section.data(95).logicalSrcIdx = 94;
	  section.data(95).dtTransOffset = 24511;
	
	  ;% controller_template_P.Constant3_Value_b
	  section.data(96).logicalSrcIdx = 95;
	  section.data(96).dtTransOffset = 24512;
	
	  ;% controller_template_P.Constant4_Value_gb
	  section.data(97).logicalSrcIdx = 96;
	  section.data(97).dtTransOffset = 24513;
	
	  ;% controller_template_P.SliderGain_Gain_a3
	  section.data(98).logicalSrcIdx = 97;
	  section.data(98).dtTransOffset = 24514;
	
	  ;% controller_template_P.Saturation1_UpperSat_g
	  section.data(99).logicalSrcIdx = 98;
	  section.data(99).dtTransOffset = 24515;
	
	  ;% controller_template_P.Saturation1_LowerSat_b
	  section.data(100).logicalSrcIdx = 99;
	  section.data(100).dtTransOffset = 24516;
	
	  ;% controller_template_P.UnitDelay2_X0_i
	  section.data(101).logicalSrcIdx = 100;
	  section.data(101).dtTransOffset = 24517;
	
	  ;% controller_template_P.UnitDelay_X0_c
	  section.data(102).logicalSrcIdx = 101;
	  section.data(102).dtTransOffset = 24518;
	
	  ;% controller_template_P.Gain_Gain_p0
	  section.data(103).logicalSrcIdx = 102;
	  section.data(103).dtTransOffset = 24519;
	
	  ;% controller_template_P.Saturation_UpperSat_c
	  section.data(104).logicalSrcIdx = 103;
	  section.data(104).dtTransOffset = 24520;
	
	  ;% controller_template_P.Saturation_LowerSat_j
	  section.data(105).logicalSrcIdx = 104;
	  section.data(105).dtTransOffset = 24521;
	
	  ;% controller_template_P.UnitDelay1_X0_i
	  section.data(106).logicalSrcIdx = 105;
	  section.data(106).dtTransOffset = 24522;
	
	  ;% controller_template_P.UnitDelay1_X0_d
	  section.data(107).logicalSrcIdx = 106;
	  section.data(107).dtTransOffset = 24523;
	
	  ;% controller_template_P.Gain_Gain_b
	  section.data(108).logicalSrcIdx = 107;
	  section.data(108).dtTransOffset = 24524;
	
	  ;% controller_template_P.UnitDelay1_X0_j
	  section.data(109).logicalSrcIdx = 108;
	  section.data(109).dtTransOffset = 24525;
	
	  ;% controller_template_P.UnitDelay1_X0_f
	  section.data(110).logicalSrcIdx = 109;
	  section.data(110).dtTransOffset = 24526;
	
	  ;% controller_template_P.g_Value
	  section.data(111).logicalSrcIdx = 110;
	  section.data(111).dtTransOffset = 24527;
	
	  ;% controller_template_P.Constant_Value_br
	  section.data(112).logicalSrcIdx = 111;
	  section.data(112).dtTransOffset = 24528;
	
	  ;% controller_template_P.Constant1_Value_e
	  section.data(113).logicalSrcIdx = 112;
	  section.data(113).dtTransOffset = 24529;
	
	  ;% controller_template_P.InitialCondition_Value
	  section.data(114).logicalSrcIdx = 113;
	  section.data(114).dtTransOffset = 24530;
	
	  ;% controller_template_P.FixPtUnitDelay1_X0_c
	  section.data(115).logicalSrcIdx = 114;
	  section.data(115).dtTransOffset = 24531;
	
	  ;% controller_template_P.total_samples_Value
	  section.data(116).logicalSrcIdx = 115;
	  section.data(116).dtTransOffset = 24532;
	
	  ;% controller_template_P.X_ref_x_Value
	  section.data(117).logicalSrcIdx = 116;
	  section.data(117).dtTransOffset = 24533;
	
	  ;% controller_template_P.X_ref_y_Value
	  section.data(118).logicalSrcIdx = 117;
	  section.data(118).dtTransOffset = 27329;
	
	  ;% controller_template_P.X_ref_yaw_Value
	  section.data(119).logicalSrcIdx = 118;
	  section.data(119).dtTransOffset = 30125;
	
	  ;% controller_template_P.X_ref_z_Value
	  section.data(120).logicalSrcIdx = 119;
	  section.data(120).dtTransOffset = 31989;
	
	  ;% controller_template_P.yaw_rate_bias_Value
	  section.data(121).logicalSrcIdx = 120;
	  section.data(121).dtTransOffset = 33853;
	
	  ;% controller_template_P.thrust_bias_Value
	  section.data(122).logicalSrcIdx = 121;
	  section.data(122).dtTransOffset = 33854;
	
	  ;% controller_template_P.roll_bias_Value
	  section.data(123).logicalSrcIdx = 122;
	  section.data(123).dtTransOffset = 33855;
	
	  ;% controller_template_P.pitch_bias_Value
	  section.data(124).logicalSrcIdx = 123;
	  section.data(124).dtTransOffset = 33856;
	
	  ;% controller_template_P.yaw_Value
	  section.data(125).logicalSrcIdx = 124;
	  section.data(125).dtTransOffset = 33857;
	
	  ;% controller_template_P.gravity_Value_c
	  section.data(126).logicalSrcIdx = 125;
	  section.data(126).dtTransOffset = 33858;
	
	  ;% controller_template_P.roll_Value
	  section.data(127).logicalSrcIdx = 126;
	  section.data(127).dtTransOffset = 33859;
	
	  ;% controller_template_P.pitch_Value
	  section.data(128).logicalSrcIdx = 127;
	  section.data(128).dtTransOffset = 33860;
	
	  ;% controller_template_P.yaw_rate_Value
	  section.data(129).logicalSrcIdx = 128;
	  section.data(129).dtTransOffset = 33861;
	
	  ;% controller_template_P.yaw_cmd2yaw_Gain
	  section.data(130).logicalSrcIdx = 129;
	  section.data(130).dtTransOffset = 33862;
	
	  ;% controller_template_P.IntegerDelay_InitialCondition
	  section.data(131).logicalSrcIdx = 130;
	  section.data(131).dtTransOffset = 33863;
	
	  ;% controller_template_P.IntegerDelay1_InitialCondition
	  section.data(132).logicalSrcIdx = 131;
	  section.data(132).dtTransOffset = 33864;
	
	  ;% controller_template_P.IntegerDelay2_InitialCondition
	  section.data(133).logicalSrcIdx = 132;
	  section.data(133).dtTransOffset = 33865;
	
	  ;% controller_template_P.IntegerDelay3_InitialConditio_c
	  section.data(134).logicalSrcIdx = 133;
	  section.data(134).dtTransOffset = 33866;
	
	  ;% controller_template_P.gravity_Value_j
	  section.data(135).logicalSrcIdx = 134;
	  section.data(135).dtTransOffset = 33867;
	
	  ;% controller_template_P.TT_PP_Value
	  section.data(136).logicalSrcIdx = 135;
	  section.data(136).dtTransOffset = 33868;
	
	  ;% controller_template_P.LL_PP_Value
	  section.data(137).logicalSrcIdx = 136;
	  section.data(137).dtTransOffset = 34768;
	
	  ;% controller_template_P.LL_ref_PP_Value
	  section.data(138).logicalSrcIdx = 137;
	  section.data(138).dtTransOffset = 34858;
	
	  ;% controller_template_P.LL_U_ref_PP_Value
	  section.data(139).logicalSrcIdx = 138;
	  section.data(139).dtTransOffset = 37648;
	
	  ;% controller_template_P.MM_Value
	  section.data(140).logicalSrcIdx = 139;
	  section.data(140).dtTransOffset = 38548;
	
	  ;% controller_template_P.PP_Value
	  section.data(141).logicalSrcIdx = 140;
	  section.data(141).dtTransOffset = 38557;
	
	  ;% controller_template_P.AA_delay_Value
	  section.data(142).logicalSrcIdx = 141;
	  section.data(142).dtTransOffset = 39457;
	
	  ;% controller_template_P.BB_delay_Value
	  section.data(143).logicalSrcIdx = 142;
	  section.data(143).dtTransOffset = 39466;
	
	  ;% controller_template_P.A_Value_h
	  section.data(144).logicalSrcIdx = 143;
	  section.data(144).dtTransOffset = 39475;
	
	  ;% controller_template_P.B_Value_i
	  section.data(145).logicalSrcIdx = 144;
	  section.data(145).dtTransOffset = 39491;
	
	  ;% controller_template_P.C_Value_c
	  section.data(146).logicalSrcIdx = 145;
	  section.data(146).dtTransOffset = 39495;
	
	  ;% controller_template_P.D_Value_l
	  section.data(147).logicalSrcIdx = 146;
	  section.data(147).dtTransOffset = 39507;
	
	  ;% controller_template_P.Q_Value_a
	  section.data(148).logicalSrcIdx = 147;
	  section.data(148).dtTransOffset = 39510;
	
	  ;% controller_template_P.R_Value_c
	  section.data(149).logicalSrcIdx = 148;
	  section.data(149).dtTransOffset = 39526;
	
	  ;% controller_template_P.UnitDelay1_X0_c
	  section.data(150).logicalSrcIdx = 149;
	  section.data(150).dtTransOffset = 39535;
	
	  ;% controller_template_P.FixPtUnitDelay1_X0_f
	  section.data(151).logicalSrcIdx = 150;
	  section.data(151).dtTransOffset = 39551;
	
	  ;% controller_template_P.V_max_Value
	  section.data(152).logicalSrcIdx = 151;
	  section.data(152).dtTransOffset = 39552;
	
	  ;% controller_template_P.i_min_Value
	  section.data(153).logicalSrcIdx = 152;
	  section.data(153).dtTransOffset = 39582;
	
	  ;% controller_template_P.betas_Value
	  section.data(154).logicalSrcIdx = 153;
	  section.data(154).dtTransOffset = 39583;
	
	  ;% controller_template_P.L_Value
	  section.data(155).logicalSrcIdx = 154;
	  section.data(155).dtTransOffset = 39590;
	
	  ;% controller_template_P.UnitDelay_X0_fc
	  section.data(156).logicalSrcIdx = 155;
	  section.data(156).dtTransOffset = 39591;
	
	  ;% controller_template_P.UnitDelay1_X0_k
	  section.data(157).logicalSrcIdx = 156;
	  section.data(157).dtTransOffset = 39594;
	
	  ;% controller_template_P.Saturation_UpperSat_i
	  section.data(158).logicalSrcIdx = 157;
	  section.data(158).dtTransOffset = 39624;
	
	  ;% controller_template_P.Saturation_LowerSat_o
	  section.data(159).logicalSrcIdx = 158;
	  section.data(159).dtTransOffset = 39625;
	
	  ;% controller_template_P.TT_PP_Value_m
	  section.data(160).logicalSrcIdx = 159;
	  section.data(160).dtTransOffset = 39626;
	
	  ;% controller_template_P.LL_PP_Value_e
	  section.data(161).logicalSrcIdx = 160;
	  section.data(161).dtTransOffset = 40526;
	
	  ;% controller_template_P.LL_ref_PP_Value_l
	  section.data(162).logicalSrcIdx = 161;
	  section.data(162).dtTransOffset = 40616;
	
	  ;% controller_template_P.LL_U_ref_PP_Value_m
	  section.data(163).logicalSrcIdx = 162;
	  section.data(163).dtTransOffset = 43406;
	
	  ;% controller_template_P.MM_Value_c
	  section.data(164).logicalSrcIdx = 163;
	  section.data(164).dtTransOffset = 44306;
	
	  ;% controller_template_P.PP_Value_m
	  section.data(165).logicalSrcIdx = 164;
	  section.data(165).dtTransOffset = 44315;
	
	  ;% controller_template_P.AA_delay_Value_h
	  section.data(166).logicalSrcIdx = 165;
	  section.data(166).dtTransOffset = 45215;
	
	  ;% controller_template_P.BB_delay_Value_o
	  section.data(167).logicalSrcIdx = 166;
	  section.data(167).dtTransOffset = 45224;
	
	  ;% controller_template_P.A_Value_n
	  section.data(168).logicalSrcIdx = 167;
	  section.data(168).dtTransOffset = 45233;
	
	  ;% controller_template_P.B_Value_h
	  section.data(169).logicalSrcIdx = 168;
	  section.data(169).dtTransOffset = 45249;
	
	  ;% controller_template_P.C_Value_p
	  section.data(170).logicalSrcIdx = 169;
	  section.data(170).dtTransOffset = 45253;
	
	  ;% controller_template_P.D_Value_m
	  section.data(171).logicalSrcIdx = 170;
	  section.data(171).dtTransOffset = 45265;
	
	  ;% controller_template_P.Q_Value_h
	  section.data(172).logicalSrcIdx = 171;
	  section.data(172).dtTransOffset = 45268;
	
	  ;% controller_template_P.R_Value_l
	  section.data(173).logicalSrcIdx = 172;
	  section.data(173).dtTransOffset = 45284;
	
	  ;% controller_template_P.UnitDelay1_X0_fk
	  section.data(174).logicalSrcIdx = 173;
	  section.data(174).dtTransOffset = 45293;
	
	  ;% controller_template_P.FixPtUnitDelay1_X0_n
	  section.data(175).logicalSrcIdx = 174;
	  section.data(175).dtTransOffset = 45309;
	
	  ;% controller_template_P.V_max_Value_o
	  section.data(176).logicalSrcIdx = 175;
	  section.data(176).dtTransOffset = 45310;
	
	  ;% controller_template_P.i_min_Value_j
	  section.data(177).logicalSrcIdx = 176;
	  section.data(177).dtTransOffset = 45340;
	
	  ;% controller_template_P.betas_Value_l
	  section.data(178).logicalSrcIdx = 177;
	  section.data(178).dtTransOffset = 45341;
	
	  ;% controller_template_P.L_Value_n
	  section.data(179).logicalSrcIdx = 178;
	  section.data(179).dtTransOffset = 45348;
	
	  ;% controller_template_P.UnitDelay_X0_ik
	  section.data(180).logicalSrcIdx = 179;
	  section.data(180).dtTransOffset = 45349;
	
	  ;% controller_template_P.UnitDelay1_X0_jc
	  section.data(181).logicalSrcIdx = 180;
	  section.data(181).dtTransOffset = 45352;
	
	  ;% controller_template_P.Saturation_UpperSat_f
	  section.data(182).logicalSrcIdx = 181;
	  section.data(182).dtTransOffset = 45382;
	
	  ;% controller_template_P.Saturation_LowerSat_k
	  section.data(183).logicalSrcIdx = 182;
	  section.data(183).dtTransOffset = 45383;
	
	  ;% controller_template_P.TT_PP_Value_b
	  section.data(184).logicalSrcIdx = 183;
	  section.data(184).dtTransOffset = 45384;
	
	  ;% controller_template_P.LL_PP_Value_j
	  section.data(185).logicalSrcIdx = 184;
	  section.data(185).dtTransOffset = 46284;
	
	  ;% controller_template_P.LL_ref_PP_Value_h
	  section.data(186).logicalSrcIdx = 185;
	  section.data(186).dtTransOffset = 46344;
	
	  ;% controller_template_P.LL_U_ref_PP_Value_o
	  section.data(187).logicalSrcIdx = 186;
	  section.data(187).dtTransOffset = 48204;
	
	  ;% controller_template_P.MM_Value_l
	  section.data(188).logicalSrcIdx = 187;
	  section.data(188).dtTransOffset = 49104;
	
	  ;% controller_template_P.PP_Value_o
	  section.data(189).logicalSrcIdx = 188;
	  section.data(189).dtTransOffset = 49108;
	
	  ;% controller_template_P.AA_delay_Value_l
	  section.data(190).logicalSrcIdx = 189;
	  section.data(190).dtTransOffset = 50008;
	
	  ;% controller_template_P.BB_delay_Value_b
	  section.data(191).logicalSrcIdx = 190;
	  section.data(191).dtTransOffset = 50012;
	
	  ;% controller_template_P.A_Value_f
	  section.data(192).logicalSrcIdx = 191;
	  section.data(192).dtTransOffset = 50016;
	
	  ;% controller_template_P.B_Value_n
	  section.data(193).logicalSrcIdx = 192;
	  section.data(193).dtTransOffset = 50025;
	
	  ;% controller_template_P.C_Value_o
	  section.data(194).logicalSrcIdx = 193;
	  section.data(194).dtTransOffset = 50028;
	
	  ;% controller_template_P.D_Value_j
	  section.data(195).logicalSrcIdx = 194;
	  section.data(195).dtTransOffset = 50034;
	
	  ;% controller_template_P.Q_Value_j
	  section.data(196).logicalSrcIdx = 195;
	  section.data(196).dtTransOffset = 50036;
	
	  ;% controller_template_P.R_Value_ca
	  section.data(197).logicalSrcIdx = 196;
	  section.data(197).dtTransOffset = 50045;
	
	  ;% controller_template_P.UnitDelay1_X0_cw
	  section.data(198).logicalSrcIdx = 197;
	  section.data(198).dtTransOffset = 50049;
	
	  ;% controller_template_P.FixPtUnitDelay1_X0_cl
	  section.data(199).logicalSrcIdx = 198;
	  section.data(199).dtTransOffset = 50058;
	
	  ;% controller_template_P.V_max_Value_i
	  section.data(200).logicalSrcIdx = 199;
	  section.data(200).dtTransOffset = 50059;
	
	  ;% controller_template_P.i_min_Value_o
	  section.data(201).logicalSrcIdx = 200;
	  section.data(201).dtTransOffset = 50089;
	
	  ;% controller_template_P.betas_Value_g
	  section.data(202).logicalSrcIdx = 201;
	  section.data(202).dtTransOffset = 50090;
	
	  ;% controller_template_P.L_Value_m
	  section.data(203).logicalSrcIdx = 202;
	  section.data(203).dtTransOffset = 50098;
	
	  ;% controller_template_P.UnitDelay_X0_a
	  section.data(204).logicalSrcIdx = 203;
	  section.data(204).dtTransOffset = 50099;
	
	  ;% controller_template_P.UnitDelay1_X0_b
	  section.data(205).logicalSrcIdx = 204;
	  section.data(205).dtTransOffset = 50101;
	
	  ;% controller_template_P.Saturation_UpperSat_l
	  section.data(206).logicalSrcIdx = 205;
	  section.data(206).dtTransOffset = 50131;
	
	  ;% controller_template_P.Saturation_LowerSat_c
	  section.data(207).logicalSrcIdx = 206;
	  section.data(207).dtTransOffset = 50132;
	
	  ;% controller_template_P.TT_PP_Value_o
	  section.data(208).logicalSrcIdx = 207;
	  section.data(208).dtTransOffset = 50133;
	
	  ;% controller_template_P.LL_PP_Value_j5
	  section.data(209).logicalSrcIdx = 208;
	  section.data(209).dtTransOffset = 51033;
	
	  ;% controller_template_P.LL_ref_PP_Value_e
	  section.data(210).logicalSrcIdx = 209;
	  section.data(210).dtTransOffset = 51093;
	
	  ;% controller_template_P.LL_U_ref_PP_Value_b
	  section.data(211).logicalSrcIdx = 210;
	  section.data(211).dtTransOffset = 52953;
	
	  ;% controller_template_P.MM_Value_g
	  section.data(212).logicalSrcIdx = 211;
	  section.data(212).dtTransOffset = 53853;
	
	  ;% controller_template_P.PP_Value_p
	  section.data(213).logicalSrcIdx = 212;
	  section.data(213).dtTransOffset = 53857;
	
	  ;% controller_template_P.AA_delay_Value_o
	  section.data(214).logicalSrcIdx = 213;
	  section.data(214).dtTransOffset = 54757;
	
	  ;% controller_template_P.BB_delay_Value_d
	  section.data(215).logicalSrcIdx = 214;
	  section.data(215).dtTransOffset = 54761;
	
	  ;% controller_template_P.A_Value_k
	  section.data(216).logicalSrcIdx = 215;
	  section.data(216).dtTransOffset = 54773;
	
	  ;% controller_template_P.B_Value_f
	  section.data(217).logicalSrcIdx = 216;
	  section.data(217).dtTransOffset = 54782;
	
	  ;% controller_template_P.C_Value_b
	  section.data(218).logicalSrcIdx = 217;
	  section.data(218).dtTransOffset = 54785;
	
	  ;% controller_template_P.D_Value_c
	  section.data(219).logicalSrcIdx = 218;
	  section.data(219).dtTransOffset = 54791;
	
	  ;% controller_template_P.Q_Value_g
	  section.data(220).logicalSrcIdx = 219;
	  section.data(220).dtTransOffset = 54793;
	
	  ;% controller_template_P.R_Value_o
	  section.data(221).logicalSrcIdx = 220;
	  section.data(221).dtTransOffset = 54802;
	
	  ;% controller_template_P.UnitDelay1_X0_n
	  section.data(222).logicalSrcIdx = 221;
	  section.data(222).dtTransOffset = 54806;
	
	  ;% controller_template_P.FixPtUnitDelay1_X0_e
	  section.data(223).logicalSrcIdx = 222;
	  section.data(223).dtTransOffset = 54815;
	
	  ;% controller_template_P.V_max_Value_f
	  section.data(224).logicalSrcIdx = 223;
	  section.data(224).dtTransOffset = 54816;
	
	  ;% controller_template_P.i_min_Value_n
	  section.data(225).logicalSrcIdx = 224;
	  section.data(225).dtTransOffset = 54846;
	
	  ;% controller_template_P.betas_Value_j
	  section.data(226).logicalSrcIdx = 225;
	  section.data(226).dtTransOffset = 54847;
	
	  ;% controller_template_P.L_Value_g
	  section.data(227).logicalSrcIdx = 226;
	  section.data(227).dtTransOffset = 54852;
	
	  ;% controller_template_P.UnitDelay_X0_fj
	  section.data(228).logicalSrcIdx = 227;
	  section.data(228).dtTransOffset = 54853;
	
	  ;% controller_template_P.UnitDelay1_X0_o
	  section.data(229).logicalSrcIdx = 228;
	  section.data(229).dtTransOffset = 54859;
	
	  ;% controller_template_P.Saturation_UpperSat_o3
	  section.data(230).logicalSrcIdx = 229;
	  section.data(230).dtTransOffset = 54889;
	
	  ;% controller_template_P.Saturation_LowerSat_kn
	  section.data(231).logicalSrcIdx = 230;
	  section.data(231).dtTransOffset = 54890;
	
	  ;% controller_template_P.g_Value_m
	  section.data(232).logicalSrcIdx = 231;
	  section.data(232).dtTransOffset = 54891;
	
	  ;% controller_template_P.raddeg2_Gain
	  section.data(233).logicalSrcIdx = 232;
	  section.data(233).dtTransOffset = 54892;
	
	  ;% controller_template_P.raddeg1_Gain
	  section.data(234).logicalSrcIdx = 233;
	  section.data(234).dtTransOffset = 54893;
	
	  ;% controller_template_P.raddeg3_Gain
	  section.data(235).logicalSrcIdx = 234;
	  section.data(235).dtTransOffset = 54894;
	
	  ;% controller_template_P.raddeg_Gain
	  section.data(236).logicalSrcIdx = 235;
	  section.data(236).dtTransOffset = 54895;
	
	  ;% controller_template_P.pitch_offset_Value
	  section.data(237).logicalSrcIdx = 236;
	  section.data(237).dtTransOffset = 54896;
	
	  ;% controller_template_P.InitialCondition_Value_b
	  section.data(238).logicalSrcIdx = 237;
	  section.data(238).dtTransOffset = 54897;
	
	  ;% controller_template_P.Constant1_Value_mr
	  section.data(239).logicalSrcIdx = 238;
	  section.data(239).dtTransOffset = 54898;
	
	  ;% controller_template_P.Constant2_Value_a
	  section.data(240).logicalSrcIdx = 239;
	  section.data(240).dtTransOffset = 54899;
	
	  ;% controller_template_P.FixPtUnitDelay1_X0_h
	  section.data(241).logicalSrcIdx = 240;
	  section.data(241).dtTransOffset = 54900;
	
	  ;% controller_template_P.Constant_Value_p
	  section.data(242).logicalSrcIdx = 241;
	  section.data(242).dtTransOffset = 54901;
	
	  ;% controller_template_P.pitch_cmd2pitch_Gain
	  section.data(243).logicalSrcIdx = 242;
	  section.data(243).dtTransOffset = 54902;
	
	  ;% controller_template_P.Gain1_Gain
	  section.data(244).logicalSrcIdx = 243;
	  section.data(244).dtTransOffset = 54903;
	
	  ;% controller_template_P.roll_offset_Value
	  section.data(245).logicalSrcIdx = 244;
	  section.data(245).dtTransOffset = 54904;
	
	  ;% controller_template_P.roll_cmd2roll_Gain
	  section.data(246).logicalSrcIdx = 245;
	  section.data(246).dtTransOffset = 54905;
	
	  ;% controller_template_P.Gain2_Gain
	  section.data(247).logicalSrcIdx = 246;
	  section.data(247).dtTransOffset = 54906;
	
	  ;% controller_template_P.gravity_Value_ch
	  section.data(248).logicalSrcIdx = 247;
	  section.data(248).dtTransOffset = 54907;
	
	  ;% controller_template_P.trhust_cmd2thrust_Gain
	  section.data(249).logicalSrcIdx = 248;
	  section.data(249).dtTransOffset = 54908;
	
	  ;% controller_template_P.Gain_Gain_k
	  section.data(250).logicalSrcIdx = 249;
	  section.data(250).dtTransOffset = 54909;
	
	  ;% controller_template_P.Gain3_Gain
	  section.data(251).logicalSrcIdx = 250;
	  section.data(251).dtTransOffset = 54910;
	
	  ;% controller_template_P.Gain4_Gain
	  section.data(252).logicalSrcIdx = 251;
	  section.data(252).dtTransOffset = 54911;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% controller_template_P.IntegerDelay3_DelayLength
	  section.data(1).logicalSrcIdx = 252;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_P.IntegerDelay_DelayLength
	  section.data(2).logicalSrcIdx = 253;
	  section.data(2).dtTransOffset = 1;
	
	  ;% controller_template_P.IntegerDelay1_DelayLength
	  section.data(3).logicalSrcIdx = 254;
	  section.data(3).dtTransOffset = 2;
	
	  ;% controller_template_P.IntegerDelay2_DelayLength
	  section.data(4).logicalSrcIdx = 255;
	  section.data(4).dtTransOffset = 3;
	
	  ;% controller_template_P.IntegerDelay3_DelayLength_o
	  section.data(5).logicalSrcIdx = 256;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 20;
      section.data(20)  = dumData; %prealloc
      
	  ;% controller_template_P.FixPtUnitDelay2_X0
	  section.data(1).logicalSrcIdx = 257;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_P.FixPtConstant_Value
	  section.data(2).logicalSrcIdx = 258;
	  section.data(2).dtTransOffset = 1;
	
	  ;% controller_template_P.FixPtUnitDelay2_X0_j
	  section.data(3).logicalSrcIdx = 259;
	  section.data(3).dtTransOffset = 2;
	
	  ;% controller_template_P.FixPtConstant_Value_g
	  section.data(4).logicalSrcIdx = 260;
	  section.data(4).dtTransOffset = 3;
	
	  ;% controller_template_P.FixPtUnitDelay2_X0_d
	  section.data(5).logicalSrcIdx = 261;
	  section.data(5).dtTransOffset = 4;
	
	  ;% controller_template_P.FixPtUnitDelay2_X0_n
	  section.data(6).logicalSrcIdx = 262;
	  section.data(6).dtTransOffset = 5;
	
	  ;% controller_template_P.FixPtUnitDelay2_X0_do
	  section.data(7).logicalSrcIdx = 263;
	  section.data(7).dtTransOffset = 6;
	
	  ;% controller_template_P.FixPtUnitDelay2_X0_i
	  section.data(8).logicalSrcIdx = 264;
	  section.data(8).dtTransOffset = 7;
	
	  ;% controller_template_P.FixPtConstant_Value_h
	  section.data(9).logicalSrcIdx = 265;
	  section.data(9).dtTransOffset = 8;
	
	  ;% controller_template_P.FixPtConstant_Value_o
	  section.data(10).logicalSrcIdx = 266;
	  section.data(10).dtTransOffset = 9;
	
	  ;% controller_template_P.FixPtConstant_Value_n
	  section.data(11).logicalSrcIdx = 267;
	  section.data(11).dtTransOffset = 10;
	
	  ;% controller_template_P.FixPtConstant_Value_p
	  section.data(12).logicalSrcIdx = 268;
	  section.data(12).dtTransOffset = 11;
	
	  ;% controller_template_P.FixPtUnitDelay2_X0_g
	  section.data(13).logicalSrcIdx = 269;
	  section.data(13).dtTransOffset = 12;
	
	  ;% controller_template_P.Constant_Value_he
	  section.data(14).logicalSrcIdx = 270;
	  section.data(14).dtTransOffset = 13;
	
	  ;% controller_template_P.SwitchControl_Threshold
	  section.data(15).logicalSrcIdx = 271;
	  section.data(15).dtTransOffset = 14;
	
	  ;% controller_template_P.Constant_Value_n
	  section.data(16).logicalSrcIdx = 272;
	  section.data(16).dtTransOffset = 15;
	
	  ;% controller_template_P.SwitchControl_Threshold_b
	  section.data(17).logicalSrcIdx = 273;
	  section.data(17).dtTransOffset = 16;
	
	  ;% controller_template_P.Constant_Value_a3
	  section.data(18).logicalSrcIdx = 274;
	  section.data(18).dtTransOffset = 17;
	
	  ;% controller_template_P.SwitchControl_Threshold_e
	  section.data(19).logicalSrcIdx = 275;
	  section.data(19).dtTransOffset = 18;
	
	  ;% controller_template_P.FixPtConstant_Value_i
	  section.data(20).logicalSrcIdx = 276;
	  section.data(20).dtTransOffset = 19;
	
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
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (controller_template_B)
    ;%
      section.nData     = 89;
      section.data(89)  = dumData; %prealloc
      
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
	
	  ;% controller_template_B.roll_rot
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 362;
	
	  ;% controller_template_B.pitch_rot
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 363;
	
	  ;% controller_template_B.pitch_bias_rot
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 364;
	
	  ;% controller_template_B.roll_bias_rot
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 365;
	
	  ;% controller_template_B.bias_W
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 366;
	
	  ;% controller_template_B.cmd_W
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 370;
	
	  ;% controller_template_B.pitch_rot_k
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 374;
	
	  ;% controller_template_B.roll_rot_a
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 375;
	
	  ;% controller_template_B.pitch_bias_rot_e
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 376;
	
	  ;% controller_template_B.roll_bias_rot_b
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 377;
	
	  ;% controller_template_B.pitch_cmd_comp
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 378;
	
	  ;% controller_template_B.roll_cmd_comp
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 379;
	
	  ;% controller_template_B.thrust_comp
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 380;
	
	  ;% controller_template_B.thrust_cmd_e
	  section.data(32).logicalSrcIdx = 35;
	  section.data(32).dtTransOffset = 381;
	
	  ;% controller_template_B.u_opt
	  section.data(33).logicalSrcIdx = 36;
	  section.data(33).dtTransOffset = 382;
	
	  ;% controller_template_B.J_star
	  section.data(34).logicalSrcIdx = 37;
	  section.data(34).dtTransOffset = 383;
	
	  ;% controller_template_B.u_buff_out
	  section.data(35).logicalSrcIdx = 38;
	  section.data(35).dtTransOffset = 384;
	
	  ;% controller_template_B.V_init_out
	  section.data(36).logicalSrcIdx = 39;
	  section.data(36).dtTransOffset = 386;
	
	  ;% controller_template_B.u_opt_l
	  section.data(37).logicalSrcIdx = 40;
	  section.data(37).dtTransOffset = 416;
	
	  ;% controller_template_B.J_star_h
	  section.data(38).logicalSrcIdx = 41;
	  section.data(38).dtTransOffset = 417;
	
	  ;% controller_template_B.u_buff_out_i
	  section.data(39).logicalSrcIdx = 42;
	  section.data(39).dtTransOffset = 418;
	
	  ;% controller_template_B.V_init_out_n
	  section.data(40).logicalSrcIdx = 43;
	  section.data(40).dtTransOffset = 424;
	
	  ;% controller_template_B.roll_rot_f
	  section.data(41).logicalSrcIdx = 44;
	  section.data(41).dtTransOffset = 454;
	
	  ;% controller_template_B.pitch_rot_i
	  section.data(42).logicalSrcIdx = 45;
	  section.data(42).dtTransOffset = 455;
	
	  ;% controller_template_B.pitch_bias_rot_p
	  section.data(43).logicalSrcIdx = 46;
	  section.data(43).dtTransOffset = 456;
	
	  ;% controller_template_B.roll_bias_rot_n
	  section.data(44).logicalSrcIdx = 47;
	  section.data(44).dtTransOffset = 457;
	
	  ;% controller_template_B.bias_W_b
	  section.data(45).logicalSrcIdx = 48;
	  section.data(45).dtTransOffset = 458;
	
	  ;% controller_template_B.cmd_W_h
	  section.data(46).logicalSrcIdx = 49;
	  section.data(46).dtTransOffset = 462;
	
	  ;% controller_template_B.pitch_rot_n
	  section.data(47).logicalSrcIdx = 50;
	  section.data(47).dtTransOffset = 466;
	
	  ;% controller_template_B.roll_rot_e
	  section.data(48).logicalSrcIdx = 51;
	  section.data(48).dtTransOffset = 467;
	
	  ;% controller_template_B.pitch_bias_rot_i
	  section.data(49).logicalSrcIdx = 52;
	  section.data(49).dtTransOffset = 468;
	
	  ;% controller_template_B.roll_bias_rot_d
	  section.data(50).logicalSrcIdx = 53;
	  section.data(50).dtTransOffset = 469;
	
	  ;% controller_template_B.pitch_cmd_comp_n
	  section.data(51).logicalSrcIdx = 54;
	  section.data(51).dtTransOffset = 470;
	
	  ;% controller_template_B.roll_cmd_comp_j
	  section.data(52).logicalSrcIdx = 55;
	  section.data(52).dtTransOffset = 471;
	
	  ;% controller_template_B.thrust_comp_k
	  section.data(53).logicalSrcIdx = 56;
	  section.data(53).dtTransOffset = 472;
	
	  ;% controller_template_B.X_ref_z_b
	  section.data(54).logicalSrcIdx = 57;
	  section.data(54).dtTransOffset = 473;
	
	  ;% controller_template_B.X_ref_yaw_a
	  section.data(55).logicalSrcIdx = 58;
	  section.data(55).dtTransOffset = 535;
	
	  ;% controller_template_B.X_ref_y_j
	  section.data(56).logicalSrcIdx = 59;
	  section.data(56).dtTransOffset = 597;
	
	  ;% controller_template_B.X_ref_x_l
	  section.data(57).logicalSrcIdx = 60;
	  section.data(57).dtTransOffset = 690;
	
	  ;% controller_template_B.Saturation3
	  section.data(58).logicalSrcIdx = 61;
	  section.data(58).dtTransOffset = 783;
	
	  ;% controller_template_B.RateTransition
	  section.data(59).logicalSrcIdx = 62;
	  section.data(59).dtTransOffset = 784;
	
	  ;% controller_template_B.UnitDelay2
	  section.data(60).logicalSrcIdx = 63;
	  section.data(60).dtTransOffset = 788;
	
	  ;% controller_template_B.Gain
	  section.data(61).logicalSrcIdx = 64;
	  section.data(61).dtTransOffset = 789;
	
	  ;% controller_template_B.pitch_cmd_bq
	  section.data(62).logicalSrcIdx = 65;
	  section.data(62).dtTransOffset = 790;
	
	  ;% controller_template_B.Saturation3_e
	  section.data(63).logicalSrcIdx = 66;
	  section.data(63).dtTransOffset = 791;
	
	  ;% controller_template_B.RateTransition_i
	  section.data(64).logicalSrcIdx = 67;
	  section.data(64).dtTransOffset = 792;
	
	  ;% controller_template_B.UnitDelay2_o
	  section.data(65).logicalSrcIdx = 68;
	  section.data(65).dtTransOffset = 796;
	
	  ;% controller_template_B.Gain_f
	  section.data(66).logicalSrcIdx = 69;
	  section.data(66).dtTransOffset = 797;
	
	  ;% controller_template_B.roll_cmd_c
	  section.data(67).logicalSrcIdx = 70;
	  section.data(67).dtTransOffset = 798;
	
	  ;% controller_template_B.Saturation1
	  section.data(68).logicalSrcIdx = 71;
	  section.data(68).dtTransOffset = 799;
	
	  ;% controller_template_B.RateTransition_j
	  section.data(69).logicalSrcIdx = 72;
	  section.data(69).dtTransOffset = 800;
	
	  ;% controller_template_B.Gain_i
	  section.data(70).logicalSrcIdx = 73;
	  section.data(70).dtTransOffset = 802;
	
	  ;% controller_template_B.Sum
	  section.data(71).logicalSrcIdx = 74;
	  section.data(71).dtTransOffset = 803;
	
	  ;% controller_template_B.Gain_n
	  section.data(72).logicalSrcIdx = 75;
	  section.data(72).dtTransOffset = 804;
	
	  ;% controller_template_B.yaw_rate_cmd_g
	  section.data(73).logicalSrcIdx = 76;
	  section.data(73).dtTransOffset = 805;
	
	  ;% controller_template_B.thrust_cmd_a
	  section.data(74).logicalSrcIdx = 77;
	  section.data(74).dtTransOffset = 806;
	
	  ;% controller_template_B.RateTransition1
	  section.data(75).logicalSrcIdx = 78;
	  section.data(75).dtTransOffset = 807;
	
	  ;% controller_template_B.RateTransition1_l
	  section.data(76).logicalSrcIdx = 79;
	  section.data(76).dtTransOffset = 808;
	
	  ;% controller_template_B.Gain_g
	  section.data(77).logicalSrcIdx = 80;
	  section.data(77).dtTransOffset = 809;
	
	  ;% controller_template_B.U
	  section.data(78).logicalSrcIdx = 81;
	  section.data(78).dtTransOffset = 810;
	
	  ;% controller_template_B.flag_oob
	  section.data(79).logicalSrcIdx = 82;
	  section.data(79).dtTransOffset = 811;
	
	  ;% controller_template_B.y
	  section.data(80).logicalSrcIdx = 83;
	  section.data(80).dtTransOffset = 812;
	
	  ;% controller_template_B.U_g
	  section.data(81).logicalSrcIdx = 84;
	  section.data(81).dtTransOffset = 813;
	
	  ;% controller_template_B.flag_oob_l
	  section.data(82).logicalSrcIdx = 85;
	  section.data(82).dtTransOffset = 814;
	
	  ;% controller_template_B.y_a
	  section.data(83).logicalSrcIdx = 86;
	  section.data(83).dtTransOffset = 815;
	
	  ;% controller_template_B.U_p
	  section.data(84).logicalSrcIdx = 87;
	  section.data(84).dtTransOffset = 819;
	
	  ;% controller_template_B.flag_oob_o
	  section.data(85).logicalSrcIdx = 88;
	  section.data(85).dtTransOffset = 820;
	
	  ;% controller_template_B.y_n
	  section.data(86).logicalSrcIdx = 89;
	  section.data(86).dtTransOffset = 821;
	
	  ;% controller_template_B.y_d
	  section.data(87).logicalSrcIdx = 90;
	  section.data(87).dtTransOffset = 822;
	
	  ;% controller_template_B.U_i
	  section.data(88).logicalSrcIdx = 91;
	  section.data(88).dtTransOffset = 826;
	
	  ;% controller_template_B.flag_oob_b
	  section.data(89).logicalSrcIdx = 92;
	  section.data(89).dtTransOffset = 827;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_B.sf_discretekalmanfilter_k.state_est
	  section.data(1).logicalSrcIdx = 93;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_B.sf_discretekalmanfilter_k.P_est
	  section.data(2).logicalSrcIdx = 94;
	  section.data(2).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_B.sf_discretekalmanfilter_n.state_est
	  section.data(1).logicalSrcIdx = 95;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_B.sf_discretekalmanfilter_n.P_est
	  section.data(2).logicalSrcIdx = 96;
	  section.data(2).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_B.sf_discretekalmanfilter_m.state_est
	  section.data(1).logicalSrcIdx = 97;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_B.sf_discretekalmanfilter_m.P_est
	  section.data(2).logicalSrcIdx = 98;
	  section.data(2).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% controller_template_B.sf_runFastGradient_d.u_opt
	  section.data(1).logicalSrcIdx = 99;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_B.sf_runFastGradient_d.J_star
	  section.data(2).logicalSrcIdx = 100;
	  section.data(2).dtTransOffset = 1;
	
	  ;% controller_template_B.sf_runFastGradient_d.u_buff_out
	  section.data(3).logicalSrcIdx = 101;
	  section.data(3).dtTransOffset = 2;
	
	  ;% controller_template_B.sf_runFastGradient_d.V_init_out
	  section.data(4).logicalSrcIdx = 102;
	  section.data(4).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(5) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_B.sf_discretekalmanfilter_b.state_est
	  section.data(1).logicalSrcIdx = 103;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_B.sf_discretekalmanfilter_b.P_est
	  section.data(2).logicalSrcIdx = 104;
	  section.data(2).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(6) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% controller_template_B.sf_runFastGradient.u_opt
	  section.data(1).logicalSrcIdx = 105;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_B.sf_runFastGradient.J_star
	  section.data(2).logicalSrcIdx = 106;
	  section.data(2).dtTransOffset = 1;
	
	  ;% controller_template_B.sf_runFastGradient.u_buff_out
	  section.data(3).logicalSrcIdx = 107;
	  section.data(3).dtTransOffset = 2;
	
	  ;% controller_template_B.sf_runFastGradient.V_init_out
	  section.data(4).logicalSrcIdx = 108;
	  section.data(4).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(7) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_B.sf_discretekalmanfilter.state_est
	  section.data(1).logicalSrcIdx = 109;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_B.sf_discretekalmanfilter.P_est
	  section.data(2).logicalSrcIdx = 110;
	  section.data(2).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(8) = section;
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
    nTotSects     = 29;
    sectIdxOffset = 8;
    
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
      section.nData     = 40;
      section.data(40)  = dumData; %prealloc
      
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
	
	  ;% controller_template_DWork.FixPtUnitDelay1_DSTATE_k
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 202;
	
	  ;% controller_template_DWork.IntegerDelay3_DSTATE_k
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 203;
	
	  ;% controller_template_DWork.UnitDelay2_DSTATE
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 204;
	
	  ;% controller_template_DWork.UnitDelay2_DSTATE_d
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 205;
	
	  ;% controller_template_DWork.UnitDelay_DSTATE_jv
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 206;
	
	  ;% controller_template_DWork.UnitDelay2_DSTATE_l
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 207;
	
	  ;% controller_template_DWork.UnitDelay2_DSTATE_k
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 208;
	
	  ;% controller_template_DWork.UnitDelay_DSTATE_f
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 209;
	
	  ;% controller_template_DWork.UnitDelay2_DSTATE_b
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 210;
	
	  ;% controller_template_DWork.UnitDelay_DSTATE_fw
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 211;
	
	  ;% controller_template_DWork.UnitDelay1_DSTATE_bg
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 212;
	
	  ;% controller_template_DWork.FixPtUnitDelay1_DSTATE_i1
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 221;
	
	  ;% controller_template_DWork.UnitDelay2_DSTATE_g
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 223;
	
	  ;% controller_template_DWork.UnitDelay2_DSTATE_ga
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 224;
	
	  ;% controller_template_DWork.UnitDelay_DSTATE_p
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 225;
	
	  ;% controller_template_DWork.UnitDelay1_DSTATE_a
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 226;
	
	  ;% controller_template_DWork.UnitDelay1_DSTATE_ji
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 227;
	
	  ;% controller_template_DWork.UnitDelay1_DSTATE_c3
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 228;
	
	  ;% controller_template_DWork.UnitDelay1_DSTATE_m
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 229;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 25;
      section.data(25)  = dumData; %prealloc
      
	  ;% controller_template_DWork.bias_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 40;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.cmd_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 41;
	  section.data(2).dtTransOffset = 1;
	
	  ;% controller_template_DWork.cmd1_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 42;
	  section.data(3).dtTransOffset = 2;
	
	  ;% controller_template_DWork.mode_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 43;
	  section.data(4).dtTransOffset = 3;
	
	  ;% controller_template_DWork.mode2_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 44;
	  section.data(5).dtTransOffset = 4;
	
	  ;% controller_template_DWork.mode1_PWORK.LoggedData
	  section.data(6).logicalSrcIdx = 45;
	  section.data(6).dtTransOffset = 5;
	
	  ;% controller_template_DWork.mode1_PWORK_h.LoggedData
	  section.data(7).logicalSrcIdx = 46;
	  section.data(7).dtTransOffset = 6;
	
	  ;% controller_template_DWork.ToFile_PWORK.FilePtr
	  section.data(8).logicalSrcIdx = 47;
	  section.data(8).dtTransOffset = 7;
	
	  ;% controller_template_DWork.ToFile1_PWORK.FilePtr
	  section.data(9).logicalSrcIdx = 48;
	  section.data(9).dtTransOffset = 8;
	
	  ;% controller_template_DWork.pitchcmd_PWORK.LoggedData
	  section.data(10).logicalSrcIdx = 49;
	  section.data(10).dtTransOffset = 9;
	
	  ;% controller_template_DWork.rollcmd_PWORK.LoggedData
	  section.data(11).logicalSrcIdx = 50;
	  section.data(11).dtTransOffset = 10;
	
	  ;% controller_template_DWork.thrustcmd_PWORK.LoggedData
	  section.data(12).logicalSrcIdx = 51;
	  section.data(12).dtTransOffset = 11;
	
	  ;% controller_template_DWork.x_ref_PWORK.LoggedData
	  section.data(13).logicalSrcIdx = 52;
	  section.data(13).dtTransOffset = 12;
	
	  ;% controller_template_DWork.y_ref_PWORK.LoggedData
	  section.data(14).logicalSrcIdx = 53;
	  section.data(14).dtTransOffset = 13;
	
	  ;% controller_template_DWork.yawcmd_PWORK.LoggedData
	  section.data(15).logicalSrcIdx = 54;
	  section.data(15).dtTransOffset = 14;
	
	  ;% controller_template_DWork.yaw_ref_PWORK.LoggedData
	  section.data(16).logicalSrcIdx = 55;
	  section.data(16).dtTransOffset = 15;
	
	  ;% controller_template_DWork.z_ref_PWORK.LoggedData
	  section.data(17).logicalSrcIdx = 56;
	  section.data(17).dtTransOffset = 16;
	
	  ;% controller_template_DWork.ToFile_PWORK_p.FilePtr
	  section.data(18).logicalSrcIdx = 57;
	  section.data(18).dtTransOffset = 17;
	
	  ;% controller_template_DWork.pitch_PWORK.LoggedData
	  section.data(19).logicalSrcIdx = 58;
	  section.data(19).dtTransOffset = 18;
	
	  ;% controller_template_DWork.roll_PWORK.LoggedData
	  section.data(20).logicalSrcIdx = 59;
	  section.data(20).dtTransOffset = 19;
	
	  ;% controller_template_DWork.thrust_PWORK.LoggedData
	  section.data(21).logicalSrcIdx = 60;
	  section.data(21).dtTransOffset = 20;
	
	  ;% controller_template_DWork.xaxis_PWORK.LoggedData
	  section.data(22).logicalSrcIdx = 61;
	  section.data(22).dtTransOffset = 21;
	
	  ;% controller_template_DWork.yaxis_PWORK.LoggedData
	  section.data(23).logicalSrcIdx = 62;
	  section.data(23).dtTransOffset = 22;
	
	  ;% controller_template_DWork.yaw_PWORK.LoggedData
	  section.data(24).logicalSrcIdx = 63;
	  section.data(24).dtTransOffset = 23;
	
	  ;% controller_template_DWork.zaxis_PWORK.LoggedData
	  section.data(25).logicalSrcIdx = 64;
	  section.data(25).dtTransOffset = 24;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 20;
      section.data(20)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sfEvent
	  section.data(1).logicalSrcIdx = 65;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.sfEvent_b
	  section.data(2).logicalSrcIdx = 66;
	  section.data(2).dtTransOffset = 1;
	
	  ;% controller_template_DWork.sfEvent_f
	  section.data(3).logicalSrcIdx = 67;
	  section.data(3).dtTransOffset = 2;
	
	  ;% controller_template_DWork.sfEvent_k
	  section.data(4).logicalSrcIdx = 68;
	  section.data(4).dtTransOffset = 3;
	
	  ;% controller_template_DWork.sfEvent_n
	  section.data(5).logicalSrcIdx = 69;
	  section.data(5).dtTransOffset = 4;
	
	  ;% controller_template_DWork.sfEvent_bq
	  section.data(6).logicalSrcIdx = 70;
	  section.data(6).dtTransOffset = 5;
	
	  ;% controller_template_DWork.sfEvent_j
	  section.data(7).logicalSrcIdx = 71;
	  section.data(7).dtTransOffset = 6;
	
	  ;% controller_template_DWork.sfEvent_c
	  section.data(8).logicalSrcIdx = 72;
	  section.data(8).dtTransOffset = 7;
	
	  ;% controller_template_DWork.sfEvent_d
	  section.data(9).logicalSrcIdx = 73;
	  section.data(9).dtTransOffset = 8;
	
	  ;% controller_template_DWork.sfEvent_h
	  section.data(10).logicalSrcIdx = 74;
	  section.data(10).dtTransOffset = 9;
	
	  ;% controller_template_DWork.sfEvent_dw
	  section.data(11).logicalSrcIdx = 75;
	  section.data(11).dtTransOffset = 10;
	
	  ;% controller_template_DWork.sfEvent_m
	  section.data(12).logicalSrcIdx = 76;
	  section.data(12).dtTransOffset = 11;
	
	  ;% controller_template_DWork.sfEvent_k0
	  section.data(13).logicalSrcIdx = 77;
	  section.data(13).dtTransOffset = 12;
	
	  ;% controller_template_DWork.sfEvent_l
	  section.data(14).logicalSrcIdx = 78;
	  section.data(14).dtTransOffset = 13;
	
	  ;% controller_template_DWork.sfEvent_jv
	  section.data(15).logicalSrcIdx = 79;
	  section.data(15).dtTransOffset = 14;
	
	  ;% controller_template_DWork.sfEvent_i
	  section.data(16).logicalSrcIdx = 80;
	  section.data(16).dtTransOffset = 15;
	
	  ;% controller_template_DWork.sfEvent_cd
	  section.data(17).logicalSrcIdx = 81;
	  section.data(17).dtTransOffset = 16;
	
	  ;% controller_template_DWork.sfEvent_fk
	  section.data(18).logicalSrcIdx = 82;
	  section.data(18).dtTransOffset = 17;
	
	  ;% controller_template_DWork.sfEvent_cm
	  section.data(19).logicalSrcIdx = 83;
	  section.data(19).dtTransOffset = 18;
	
	  ;% controller_template_DWork.sfEvent_kl
	  section.data(20).logicalSrcIdx = 84;
	  section.data(20).dtTransOffset = 19;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% controller_template_DWork.ToFile_IWORK.Count
	  section.data(1).logicalSrcIdx = 85;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.ToFile1_IWORK.Count
	  section.data(2).logicalSrcIdx = 86;
	  section.data(2).dtTransOffset = 1;
	
	  ;% controller_template_DWork.ToFile_IWORK_g.Count
	  section.data(3).logicalSrcIdx = 87;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% controller_template_DWork.FixPtUnitDelay2_DSTATE
	  section.data(1).logicalSrcIdx = 88;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.FixPtUnitDelay2_DSTATE_l
	  section.data(2).logicalSrcIdx = 89;
	  section.data(2).dtTransOffset = 1;
	
	  ;% controller_template_DWork.FixPtUnitDelay2_DSTATE_b
	  section.data(3).logicalSrcIdx = 90;
	  section.data(3).dtTransOffset = 2;
	
	  ;% controller_template_DWork.FixPtUnitDelay2_DSTATE_c
	  section.data(4).logicalSrcIdx = 91;
	  section.data(4).dtTransOffset = 3;
	
	  ;% controller_template_DWork.FixPtUnitDelay2_DSTATE_a
	  section.data(5).logicalSrcIdx = 92;
	  section.data(5).dtTransOffset = 4;
	
	  ;% controller_template_DWork.FixPtUnitDelay2_DSTATE_e
	  section.data(6).logicalSrcIdx = 93;
	  section.data(6).dtTransOffset = 5;
	
	  ;% controller_template_DWork.FixPtUnitDelay2_DSTATE_g
	  section.data(7).logicalSrcIdx = 94;
	  section.data(7).dtTransOffset = 6;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_DWork.FreeFlightPosCtrl_SubsysRanBC
	  section.data(1).logicalSrcIdx = 95;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.poscontroller_SubsysRanBC
	  section.data(2).logicalSrcIdx = 96;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 20;
      section.data(20)  = dumData; %prealloc
      
	  ;% controller_template_DWork.is_active_c26_Hquad_control_LIB
	  section.data(1).logicalSrcIdx = 97;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.is_active_c4_Hquad_control_LIB_
	  section.data(2).logicalSrcIdx = 98;
	  section.data(2).dtTransOffset = 1;
	
	  ;% controller_template_DWork.is_active_c1_Hquad_control_LIB_
	  section.data(3).logicalSrcIdx = 99;
	  section.data(3).dtTransOffset = 2;
	
	  ;% controller_template_DWork.is_active_c8_Hquad_control_LIB_
	  section.data(4).logicalSrcIdx = 100;
	  section.data(4).dtTransOffset = 3;
	
	  ;% controller_template_DWork.is_active_c9_Hquad_control_LIB_
	  section.data(5).logicalSrcIdx = 101;
	  section.data(5).dtTransOffset = 4;
	
	  ;% controller_template_DWork.is_active_c26_Hquad_control_L_f
	  section.data(6).logicalSrcIdx = 102;
	  section.data(6).dtTransOffset = 5;
	
	  ;% controller_template_DWork.is_active_c4_Hquad_control_LI_d
	  section.data(7).logicalSrcIdx = 103;
	  section.data(7).dtTransOffset = 6;
	
	  ;% controller_template_DWork.is_active_c1_Hquad_control_LI_l
	  section.data(8).logicalSrcIdx = 104;
	  section.data(8).dtTransOffset = 7;
	
	  ;% controller_template_DWork.is_active_c24_Hquad_control_LIB
	  section.data(9).logicalSrcIdx = 105;
	  section.data(9).dtTransOffset = 8;
	
	  ;% controller_template_DWork.is_active_c23_Hquad_control_LIB
	  section.data(10).logicalSrcIdx = 106;
	  section.data(10).dtTransOffset = 9;
	
	  ;% controller_template_DWork.is_active_c22_Hquad_control_LIB
	  section.data(11).logicalSrcIdx = 107;
	  section.data(11).dtTransOffset = 10;
	
	  ;% controller_template_DWork.is_active_c2_Hquad_control_LIB_
	  section.data(12).logicalSrcIdx = 108;
	  section.data(12).dtTransOffset = 11;
	
	  ;% controller_template_DWork.is_active_c3_controller_templat
	  section.data(13).logicalSrcIdx = 109;
	  section.data(13).dtTransOffset = 12;
	
	  ;% controller_template_DWork.is_active_c6_controller_templat
	  section.data(14).logicalSrcIdx = 110;
	  section.data(14).dtTransOffset = 13;
	
	  ;% controller_template_DWork.is_active_c4_controller_templat
	  section.data(15).logicalSrcIdx = 111;
	  section.data(15).dtTransOffset = 14;
	
	  ;% controller_template_DWork.is_active_c5_controller_templat
	  section.data(16).logicalSrcIdx = 112;
	  section.data(16).dtTransOffset = 15;
	
	  ;% controller_template_DWork.is_active_c2_controller_templat
	  section.data(17).logicalSrcIdx = 113;
	  section.data(17).dtTransOffset = 16;
	
	  ;% controller_template_DWork.is_active_c8_controller_templat
	  section.data(18).logicalSrcIdx = 114;
	  section.data(18).dtTransOffset = 17;
	
	  ;% controller_template_DWork.is_active_c7_controller_templat
	  section.data(19).logicalSrcIdx = 115;
	  section.data(19).dtTransOffset = 18;
	
	  ;% controller_template_DWork.is_active_c1_controller_templat
	  section.data(20).logicalSrcIdx = 116;
	  section.data(20).dtTransOffset = 19;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 42;
      section.data(42)  = dumData; %prealloc
      
	  ;% controller_template_DWork.isStable
	  section.data(1).logicalSrcIdx = 117;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 118;
	  section.data(2).dtTransOffset = 1;
	
	  ;% controller_template_DWork.isStable_n
	  section.data(3).logicalSrcIdx = 119;
	  section.data(3).dtTransOffset = 2;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_m
	  section.data(4).logicalSrcIdx = 120;
	  section.data(4).dtTransOffset = 3;
	
	  ;% controller_template_DWork.isStable_m
	  section.data(5).logicalSrcIdx = 121;
	  section.data(5).dtTransOffset = 4;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_e
	  section.data(6).logicalSrcIdx = 122;
	  section.data(6).dtTransOffset = 5;
	
	  ;% controller_template_DWork.isStable_i
	  section.data(7).logicalSrcIdx = 123;
	  section.data(7).dtTransOffset = 6;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_h
	  section.data(8).logicalSrcIdx = 124;
	  section.data(8).dtTransOffset = 7;
	
	  ;% controller_template_DWork.isStable_h
	  section.data(9).logicalSrcIdx = 125;
	  section.data(9).dtTransOffset = 8;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_o
	  section.data(10).logicalSrcIdx = 126;
	  section.data(10).dtTransOffset = 9;
	
	  ;% controller_template_DWork.isStable_k
	  section.data(11).logicalSrcIdx = 127;
	  section.data(11).dtTransOffset = 10;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_og
	  section.data(12).logicalSrcIdx = 128;
	  section.data(12).dtTransOffset = 11;
	
	  ;% controller_template_DWork.isStable_o
	  section.data(13).logicalSrcIdx = 129;
	  section.data(13).dtTransOffset = 12;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_c
	  section.data(14).logicalSrcIdx = 130;
	  section.data(14).dtTransOffset = 13;
	
	  ;% controller_template_DWork.isStable_mf
	  section.data(15).logicalSrcIdx = 131;
	  section.data(15).dtTransOffset = 14;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_a
	  section.data(16).logicalSrcIdx = 132;
	  section.data(16).dtTransOffset = 15;
	
	  ;% controller_template_DWork.isStable_f
	  section.data(17).logicalSrcIdx = 133;
	  section.data(17).dtTransOffset = 16;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_l
	  section.data(18).logicalSrcIdx = 134;
	  section.data(18).dtTransOffset = 17;
	
	  ;% controller_template_DWork.isStable_mv
	  section.data(19).logicalSrcIdx = 135;
	  section.data(19).dtTransOffset = 18;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_ov
	  section.data(20).logicalSrcIdx = 136;
	  section.data(20).dtTransOffset = 19;
	
	  ;% controller_template_DWork.isStable_b
	  section.data(21).logicalSrcIdx = 137;
	  section.data(21).dtTransOffset = 20;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_n
	  section.data(22).logicalSrcIdx = 138;
	  section.data(22).dtTransOffset = 21;
	
	  ;% controller_template_DWork.isStable_bj
	  section.data(23).logicalSrcIdx = 139;
	  section.data(23).dtTransOffset = 22;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_f
	  section.data(24).logicalSrcIdx = 140;
	  section.data(24).dtTransOffset = 23;
	
	  ;% controller_template_DWork.isStable_c
	  section.data(25).logicalSrcIdx = 141;
	  section.data(25).dtTransOffset = 24;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_ha
	  section.data(26).logicalSrcIdx = 142;
	  section.data(26).dtTransOffset = 25;
	
	  ;% controller_template_DWork.isStable_oc
	  section.data(27).logicalSrcIdx = 143;
	  section.data(27).dtTransOffset = 26;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_me
	  section.data(28).logicalSrcIdx = 144;
	  section.data(28).dtTransOffset = 27;
	
	  ;% controller_template_DWork.isStable_hg
	  section.data(29).logicalSrcIdx = 145;
	  section.data(29).dtTransOffset = 28;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_p
	  section.data(30).logicalSrcIdx = 146;
	  section.data(30).dtTransOffset = 29;
	
	  ;% controller_template_DWork.isStable_nx
	  section.data(31).logicalSrcIdx = 147;
	  section.data(31).dtTransOffset = 30;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_b
	  section.data(32).logicalSrcIdx = 148;
	  section.data(32).dtTransOffset = 31;
	
	  ;% controller_template_DWork.isStable_ke
	  section.data(33).logicalSrcIdx = 149;
	  section.data(33).dtTransOffset = 32;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_d
	  section.data(34).logicalSrcIdx = 150;
	  section.data(34).dtTransOffset = 33;
	
	  ;% controller_template_DWork.isStable_a
	  section.data(35).logicalSrcIdx = 151;
	  section.data(35).dtTransOffset = 34;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_h2
	  section.data(36).logicalSrcIdx = 152;
	  section.data(36).dtTransOffset = 35;
	
	  ;% controller_template_DWork.isStable_fw
	  section.data(37).logicalSrcIdx = 153;
	  section.data(37).dtTransOffset = 36;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_j
	  section.data(38).logicalSrcIdx = 154;
	  section.data(38).dtTransOffset = 37;
	
	  ;% controller_template_DWork.isStable_fv
	  section.data(39).logicalSrcIdx = 155;
	  section.data(39).dtTransOffset = 38;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_g
	  section.data(40).logicalSrcIdx = 156;
	  section.data(40).dtTransOffset = 39;
	
	  ;% controller_template_DWork.FreeFlightPosCtrl_MODE
	  section.data(41).logicalSrcIdx = 157;
	  section.data(41).dtTransOffset = 40;
	
	  ;% controller_template_DWork.poscontroller_MODE
	  section.data(42).logicalSrcIdx = 158;
	  section.data(42).dtTransOffset = 41;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_discretekalmanfilter_k.sfEvent
	  section.data(1).logicalSrcIdx = 159;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_discretekalmanfilter_k.is_active_c5_Hquad_control_LIB_
	  section.data(1).logicalSrcIdx = 160;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(10) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_discretekalmanfilter_k.isStable
	  section.data(1).logicalSrcIdx = 161;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.sf_discretekalmanfilter_k.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 162;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(11) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_discretekalmanfilter_n.sfEvent
	  section.data(1).logicalSrcIdx = 163;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(12) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_discretekalmanfilter_n.is_active_c5_Hquad_control_LIB_
	  section.data(1).logicalSrcIdx = 164;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(13) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_discretekalmanfilter_n.isStable
	  section.data(1).logicalSrcIdx = 165;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.sf_discretekalmanfilter_n.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 166;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(14) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_discretekalmanfilter_m.sfEvent
	  section.data(1).logicalSrcIdx = 167;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(15) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_discretekalmanfilter_m.is_active_c11_Hquad_control_LIB
	  section.data(1).logicalSrcIdx = 168;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(16) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_discretekalmanfilter_m.isStable
	  section.data(1).logicalSrcIdx = 169;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.sf_discretekalmanfilter_m.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 170;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(17) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_runFastGradient_d.sfEvent
	  section.data(1).logicalSrcIdx = 171;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(18) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_runFastGradient_d.is_active_c6_Hquad_control_LIB_
	  section.data(1).logicalSrcIdx = 172;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(19) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_runFastGradient_d.isStable
	  section.data(1).logicalSrcIdx = 173;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.sf_runFastGradient_d.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 174;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(20) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_discretekalmanfilter_b.sfEvent
	  section.data(1).logicalSrcIdx = 175;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(21) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_discretekalmanfilter_b.is_active_c11_Hquad_control_LIB
	  section.data(1).logicalSrcIdx = 176;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(22) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_discretekalmanfilter_b.isStable
	  section.data(1).logicalSrcIdx = 177;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.sf_discretekalmanfilter_b.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 178;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(23) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_runFastGradient.sfEvent
	  section.data(1).logicalSrcIdx = 179;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(24) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_runFastGradient.is_active_c6_Hquad_control_LIB_
	  section.data(1).logicalSrcIdx = 180;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(25) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_runFastGradient.isStable
	  section.data(1).logicalSrcIdx = 181;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.sf_runFastGradient.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 182;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(26) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_discretekalmanfilter.sfEvent
	  section.data(1).logicalSrcIdx = 183;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(27) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_discretekalmanfilter.is_active_c5_Hquad_control_LIB_
	  section.data(1).logicalSrcIdx = 184;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(28) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_discretekalmanfilter.isStable
	  section.data(1).logicalSrcIdx = 185;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.sf_discretekalmanfilter.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 186;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(29) = section;
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


  targMap.checksum0 = 2294414305;
  targMap.checksum1 = 797197336;
  targMap.checksum2 = 1111424642;
  targMap.checksum3 = 2160926172;

