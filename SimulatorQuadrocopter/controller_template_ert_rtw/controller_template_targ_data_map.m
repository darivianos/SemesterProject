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
      section.nData     = 357;
      section.data(357)  = dumData; %prealloc
      
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
	
	  ;% controller_template_P.Saturation3_UpperSat
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 48;
	
	  ;% controller_template_P.Saturation3_LowerSat
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 49;
	
	  ;% controller_template_P.Saturation3_UpperSat_j
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 50;
	
	  ;% controller_template_P.Saturation3_LowerSat_l
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 51;
	
	  ;% controller_template_P.A_Value
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 52;
	
	  ;% controller_template_P.B_Value
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 61;
	
	  ;% controller_template_P.C_Value
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 64;
	
	  ;% controller_template_P.D_Value
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 70;
	
	  ;% controller_template_P.Q_Value
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 72;
	
	  ;% controller_template_P.R_Value
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 81;
	
	  ;% controller_template_P.IntegerDelay3_InitialCondition
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 85;
	
	  ;% controller_template_P.UnitDelay1_X0
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 86;
	
	  ;% controller_template_P.FixPtUnitDelay1_X0
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 95;
	
	  ;% controller_template_P.Saturation_UpperSat
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 96;
	
	  ;% controller_template_P.Saturation_LowerSat
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 97;
	
	  ;% controller_template_P.Gain2_Gain
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 98;
	
	  ;% controller_template_P.gravity_Value
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 99;
	
	  ;% controller_template_P.Constant1_Value_m
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 100;
	
	  ;% controller_template_P.SliderGain_Gain
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 101;
	
	  ;% controller_template_P.Gain1_Gain
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 102;
	
	  ;% controller_template_P.Saturation_UpperSat_i
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 103;
	
	  ;% controller_template_P.Saturation_LowerSat_j
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 104;
	
	  ;% controller_template_P.Saturation1_UpperSat
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 105;
	
	  ;% controller_template_P.Saturation1_LowerSat
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 106;
	
	  ;% controller_template_P.Constant_Value_c
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 107;
	
	  ;% controller_template_P.SliderGain_Gain_o
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 108;
	
	  ;% controller_template_P.Constant1_Value_f
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 109;
	
	  ;% controller_template_P.SliderGain_Gain_b
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 110;
	
	  ;% controller_template_P.Saturation2_UpperSat
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 111;
	
	  ;% controller_template_P.Saturation2_LowerSat
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 112;
	
	  ;% controller_template_P.UnitDelay2_X0
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 113;
	
	  ;% controller_template_P.Saturation_UpperSat_p
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 114;
	
	  ;% controller_template_P.Saturation_LowerSat_c
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 115;
	
	  ;% controller_template_P.Saturation1_UpperSat_o
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 116;
	
	  ;% controller_template_P.Saturation1_LowerSat_d
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 117;
	
	  ;% controller_template_P.Saturation3_UpperSat_c
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 118;
	
	  ;% controller_template_P.Saturation3_LowerSat_k
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 119;
	
	  ;% controller_template_P.Saturation2_UpperSat_a
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 120;
	
	  ;% controller_template_P.Saturation2_LowerSat_h
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 121;
	
	  ;% controller_template_P.Constant_Value_l
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 122;
	
	  ;% controller_template_P.Constant1_Value_fy
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 9598;
	
	  ;% controller_template_P.Constant2_Value_m
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 11967;
	
	  ;% controller_template_P.Constat3_Value
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 13075;
	
	  ;% controller_template_P.Constant4_Value
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 13352;
	
	  ;% controller_template_P.Constant_Value_m
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 13629;
	
	  ;% controller_template_P.Constant1_Value_a
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 13645;
	
	  ;% controller_template_P.UnitDelay2_X0_b
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 13653;
	
	  ;% controller_template_P.Saturation_UpperSat_k
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 13654;
	
	  ;% controller_template_P.Saturation_LowerSat_e
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 13655;
	
	  ;% controller_template_P.Saturation1_UpperSat_p
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 13656;
	
	  ;% controller_template_P.Saturation1_LowerSat_l
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 13657;
	
	  ;% controller_template_P.Saturation3_UpperSat_l
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 13658;
	
	  ;% controller_template_P.Saturation3_LowerSat_lj
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 13659;
	
	  ;% controller_template_P.Saturation2_UpperSat_k
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 13660;
	
	  ;% controller_template_P.Saturation2_LowerSat_c
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 13661;
	
	  ;% controller_template_P.Constant5_Value
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 13662;
	
	  ;% controller_template_P.Constant6_Value
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 18126;
	
	  ;% controller_template_P.Constant7_Value
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 19242;
	
	  ;% controller_template_P.Constant8_Value
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 19778;
	
	  ;% controller_template_P.Constant9_Value
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 19912;
	
	  ;% controller_template_P.Saturation4_UpperSat
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 20046;
	
	  ;% controller_template_P.Saturation4_LowerSat
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 20047;
	
	  ;% controller_template_P.UnitDelay2_X0_m
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 20048;
	
	  ;% controller_template_P.UnitDelay_X0
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 20049;
	
	  ;% controller_template_P.Gain_Gain
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 20050;
	
	  ;% controller_template_P.Constant_Value_f
	  section.data(70).logicalSrcIdx = 69;
	  section.data(70).dtTransOffset = 20051;
	
	  ;% controller_template_P.SliderGain_Gain_g
	  section.data(71).logicalSrcIdx = 70;
	  section.data(71).dtTransOffset = 20052;
	
	  ;% controller_template_P.SliderGain_Gain_ba
	  section.data(72).logicalSrcIdx = 71;
	  section.data(72).dtTransOffset = 20053;
	
	  ;% controller_template_P.Gain_Gain_j
	  section.data(73).logicalSrcIdx = 72;
	  section.data(73).dtTransOffset = 20054;
	
	  ;% controller_template_P.Constant1_Value_d
	  section.data(74).logicalSrcIdx = 73;
	  section.data(74).dtTransOffset = 20055;
	
	  ;% controller_template_P.SliderGain_Gain_j
	  section.data(75).logicalSrcIdx = 74;
	  section.data(75).dtTransOffset = 20056;
	
	  ;% controller_template_P.Gain_Gain_f
	  section.data(76).logicalSrcIdx = 75;
	  section.data(76).dtTransOffset = 20057;
	
	  ;% controller_template_P.Saturation_UpperSat_h
	  section.data(77).logicalSrcIdx = 76;
	  section.data(77).dtTransOffset = 20058;
	
	  ;% controller_template_P.Saturation_LowerSat_d
	  section.data(78).logicalSrcIdx = 77;
	  section.data(78).dtTransOffset = 20059;
	
	  ;% controller_template_P.Saturation1_UpperSat_ou
	  section.data(79).logicalSrcIdx = 78;
	  section.data(79).dtTransOffset = 20060;
	
	  ;% controller_template_P.Saturation1_LowerSat_c
	  section.data(80).logicalSrcIdx = 79;
	  section.data(80).dtTransOffset = 20061;
	
	  ;% controller_template_P.SliderGain_Gain_gm
	  section.data(81).logicalSrcIdx = 80;
	  section.data(81).dtTransOffset = 20062;
	
	  ;% controller_template_P.Constant_Value_g
	  section.data(82).logicalSrcIdx = 81;
	  section.data(82).dtTransOffset = 20063;
	
	  ;% controller_template_P.SliderGain_Gain_be
	  section.data(83).logicalSrcIdx = 82;
	  section.data(83).dtTransOffset = 20064;
	
	  ;% controller_template_P.Saturation3_UpperSat_n
	  section.data(84).logicalSrcIdx = 83;
	  section.data(84).dtTransOffset = 20065;
	
	  ;% controller_template_P.Saturation3_LowerSat_c
	  section.data(85).logicalSrcIdx = 84;
	  section.data(85).dtTransOffset = 20066;
	
	  ;% controller_template_P.Saturation2_UpperSat_b
	  section.data(86).logicalSrcIdx = 85;
	  section.data(86).dtTransOffset = 20067;
	
	  ;% controller_template_P.Saturation2_LowerSat_hu
	  section.data(87).logicalSrcIdx = 86;
	  section.data(87).dtTransOffset = 20068;
	
	  ;% controller_template_P.Constant_Value_k
	  section.data(88).logicalSrcIdx = 87;
	  section.data(88).dtTransOffset = 20069;
	
	  ;% controller_template_P.SliderGain_Gain_p
	  section.data(89).logicalSrcIdx = 88;
	  section.data(89).dtTransOffset = 20070;
	
	  ;% controller_template_P.Constant1_Value_dx
	  section.data(90).logicalSrcIdx = 89;
	  section.data(90).dtTransOffset = 20071;
	
	  ;% controller_template_P.SliderGain_Gain_g3
	  section.data(91).logicalSrcIdx = 90;
	  section.data(91).dtTransOffset = 20072;
	
	  ;% controller_template_P.Saturation3_UpperSat_lg
	  section.data(92).logicalSrcIdx = 91;
	  section.data(92).dtTransOffset = 20073;
	
	  ;% controller_template_P.Saturation3_LowerSat_b
	  section.data(93).logicalSrcIdx = 92;
	  section.data(93).dtTransOffset = 20074;
	
	  ;% controller_template_P.Constant_Value_co
	  section.data(94).logicalSrcIdx = 93;
	  section.data(94).dtTransOffset = 20075;
	
	  ;% controller_template_P.Constant1_Value_g
	  section.data(95).logicalSrcIdx = 94;
	  section.data(95).dtTransOffset = 20100;
	
	  ;% controller_template_P.UnitDelay2_X0_d
	  section.data(96).logicalSrcIdx = 95;
	  section.data(96).dtTransOffset = 20110;
	
	  ;% controller_template_P.Constant_Value_ln
	  section.data(97).logicalSrcIdx = 96;
	  section.data(97).dtTransOffset = 20111;
	
	  ;% controller_template_P.Constant1_Value_j
	  section.data(98).logicalSrcIdx = 97;
	  section.data(98).dtTransOffset = 36756;
	
	  ;% controller_template_P.Constant2_Value_j
	  section.data(99).logicalSrcIdx = 98;
	  section.data(99).dtTransOffset = 40085;
	
	  ;% controller_template_P.Constant3_Value_o
	  section.data(100).logicalSrcIdx = 99;
	  section.data(100).dtTransOffset = 41660;
	
	  ;% controller_template_P.Constant4_Value_g
	  section.data(101).logicalSrcIdx = 100;
	  section.data(101).dtTransOffset = 41975;
	
	  ;% controller_template_P.Constant_Value_o
	  section.data(102).logicalSrcIdx = 101;
	  section.data(102).dtTransOffset = 42290;
	
	  ;% controller_template_P.SliderGain_Gain_m
	  section.data(103).logicalSrcIdx = 102;
	  section.data(103).dtTransOffset = 42291;
	
	  ;% controller_template_P.Saturation4_UpperSat_i
	  section.data(104).logicalSrcIdx = 103;
	  section.data(104).dtTransOffset = 42292;
	
	  ;% controller_template_P.Saturation4_LowerSat_h
	  section.data(105).logicalSrcIdx = 104;
	  section.data(105).dtTransOffset = 42293;
	
	  ;% controller_template_P.UnitDelay2_X0_n
	  section.data(106).logicalSrcIdx = 105;
	  section.data(106).dtTransOffset = 42294;
	
	  ;% controller_template_P.UnitDelay_X0_f
	  section.data(107).logicalSrcIdx = 106;
	  section.data(107).dtTransOffset = 42295;
	
	  ;% controller_template_P.Gain_Gain_fn
	  section.data(108).logicalSrcIdx = 107;
	  section.data(108).dtTransOffset = 42296;
	
	  ;% controller_template_P.Saturation1_UpperSat_d
	  section.data(109).logicalSrcIdx = 108;
	  section.data(109).dtTransOffset = 42297;
	
	  ;% controller_template_P.Saturation1_LowerSat_n
	  section.data(110).logicalSrcIdx = 109;
	  section.data(110).dtTransOffset = 42298;
	
	  ;% controller_template_P.Saturation_UpperSat_d
	  section.data(111).logicalSrcIdx = 110;
	  section.data(111).dtTransOffset = 42299;
	
	  ;% controller_template_P.Saturation_LowerSat_b
	  section.data(112).logicalSrcIdx = 111;
	  section.data(112).dtTransOffset = 42300;
	
	  ;% controller_template_P.Constant_Value_fz
	  section.data(113).logicalSrcIdx = 112;
	  section.data(113).dtTransOffset = 42301;
	
	  ;% controller_template_P.SliderGain_Gain_d
	  section.data(114).logicalSrcIdx = 113;
	  section.data(114).dtTransOffset = 42302;
	
	  ;% controller_template_P.Constant1_Value_l
	  section.data(115).logicalSrcIdx = 114;
	  section.data(115).dtTransOffset = 42303;
	
	  ;% controller_template_P.SliderGain_Gain_ds
	  section.data(116).logicalSrcIdx = 115;
	  section.data(116).dtTransOffset = 42304;
	
	  ;% controller_template_P.Saturation3_UpperSat_nh
	  section.data(117).logicalSrcIdx = 116;
	  section.data(117).dtTransOffset = 42305;
	
	  ;% controller_template_P.Saturation3_LowerSat_e
	  section.data(118).logicalSrcIdx = 117;
	  section.data(118).dtTransOffset = 42306;
	
	  ;% controller_template_P.Constant_Value_b
	  section.data(119).logicalSrcIdx = 118;
	  section.data(119).dtTransOffset = 42307;
	
	  ;% controller_template_P.Constant1_Value_li
	  section.data(120).logicalSrcIdx = 119;
	  section.data(120).dtTransOffset = 42931;
	
	  ;% controller_template_P.Constant2_Value_g
	  section.data(121).logicalSrcIdx = 120;
	  section.data(121).dtTransOffset = 43139;
	
	  ;% controller_template_P.Constant3_Value_m
	  section.data(122).logicalSrcIdx = 121;
	  section.data(122).dtTransOffset = 43229;
	
	  ;% controller_template_P.Constant4_Value_a
	  section.data(123).logicalSrcIdx = 122;
	  section.data(123).dtTransOffset = 43259;
	
	  ;% controller_template_P.Constant_Value_n
	  section.data(124).logicalSrcIdx = 123;
	  section.data(124).dtTransOffset = 43289;
	
	  ;% controller_template_P.SliderGain_Gain_mb
	  section.data(125).logicalSrcIdx = 124;
	  section.data(125).dtTransOffset = 43290;
	
	  ;% controller_template_P.SliderGain_Gain_c
	  section.data(126).logicalSrcIdx = 125;
	  section.data(126).dtTransOffset = 43291;
	
	  ;% controller_template_P.Saturation2_UpperSat_kw
	  section.data(127).logicalSrcIdx = 126;
	  section.data(127).dtTransOffset = 43292;
	
	  ;% controller_template_P.Saturation2_LowerSat_j
	  section.data(128).logicalSrcIdx = 127;
	  section.data(128).dtTransOffset = 43293;
	
	  ;% controller_template_P.UnitDelay2_X0_o
	  section.data(129).logicalSrcIdx = 128;
	  section.data(129).dtTransOffset = 43294;
	
	  ;% controller_template_P.UnitDelay_X0_i
	  section.data(130).logicalSrcIdx = 129;
	  section.data(130).dtTransOffset = 43295;
	
	  ;% controller_template_P.Gain_Gain_p
	  section.data(131).logicalSrcIdx = 130;
	  section.data(131).dtTransOffset = 43296;
	
	  ;% controller_template_P.UnitDelay_X0_m
	  section.data(132).logicalSrcIdx = 131;
	  section.data(132).dtTransOffset = 43297;
	
	  ;% controller_template_P.Constant1_Value_k
	  section.data(133).logicalSrcIdx = 132;
	  section.data(133).dtTransOffset = 43298;
	
	  ;% controller_template_P.SliderGain_Gain_a
	  section.data(134).logicalSrcIdx = 133;
	  section.data(134).dtTransOffset = 43299;
	
	  ;% controller_template_P.Constant2_Value_l
	  section.data(135).logicalSrcIdx = 134;
	  section.data(135).dtTransOffset = 43300;
	
	  ;% controller_template_P.SliderGain_Gain_pq
	  section.data(136).logicalSrcIdx = 135;
	  section.data(136).dtTransOffset = 43301;
	
	  ;% controller_template_P.SliderGain_Gain_ai
	  section.data(137).logicalSrcIdx = 136;
	  section.data(137).dtTransOffset = 43302;
	
	  ;% controller_template_P.Constant_Value_fv
	  section.data(138).logicalSrcIdx = 137;
	  section.data(138).dtTransOffset = 43303;
	
	  ;% controller_template_P.SliderGain_Gain_jt
	  section.data(139).logicalSrcIdx = 138;
	  section.data(139).dtTransOffset = 43304;
	
	  ;% controller_template_P.Saturation_UpperSat_o
	  section.data(140).logicalSrcIdx = 139;
	  section.data(140).dtTransOffset = 43305;
	
	  ;% controller_template_P.Saturation_LowerSat_p
	  section.data(141).logicalSrcIdx = 140;
	  section.data(141).dtTransOffset = 43306;
	
	  ;% controller_template_P.Constant_Value_h
	  section.data(142).logicalSrcIdx = 141;
	  section.data(142).dtTransOffset = 43307;
	
	  ;% controller_template_P.Constant1_Value_m3
	  section.data(143).logicalSrcIdx = 142;
	  section.data(143).dtTransOffset = 43308;
	
	  ;% controller_template_P.UnitDelay2_X0_ng
	  section.data(144).logicalSrcIdx = 143;
	  section.data(144).dtTransOffset = 43309;
	
	  ;% controller_template_P.Constant_Value_a
	  section.data(145).logicalSrcIdx = 144;
	  section.data(145).dtTransOffset = 43310;
	
	  ;% controller_template_P.Constant1_Value_gs
	  section.data(146).logicalSrcIdx = 145;
	  section.data(146).dtTransOffset = 43316;
	
	  ;% controller_template_P.Constant2_Value_jq
	  section.data(147).logicalSrcIdx = 146;
	  section.data(147).dtTransOffset = 43322;
	
	  ;% controller_template_P.Constant3_Value_b
	  section.data(148).logicalSrcIdx = 147;
	  section.data(148).dtTransOffset = 43325;
	
	  ;% controller_template_P.Constant4_Value_gb
	  section.data(149).logicalSrcIdx = 148;
	  section.data(149).dtTransOffset = 43328;
	
	  ;% controller_template_P.Saturation1_UpperSat_g
	  section.data(150).logicalSrcIdx = 149;
	  section.data(150).dtTransOffset = 43331;
	
	  ;% controller_template_P.Saturation1_LowerSat_b
	  section.data(151).logicalSrcIdx = 150;
	  section.data(151).dtTransOffset = 43332;
	
	  ;% controller_template_P.UnitDelay2_X0_i
	  section.data(152).logicalSrcIdx = 151;
	  section.data(152).dtTransOffset = 43333;
	
	  ;% controller_template_P.UnitDelay_X0_c
	  section.data(153).logicalSrcIdx = 152;
	  section.data(153).dtTransOffset = 43334;
	
	  ;% controller_template_P.Gain_Gain_p0
	  section.data(154).logicalSrcIdx = 153;
	  section.data(154).dtTransOffset = 43335;
	
	  ;% controller_template_P.UnitDelay1_X0_i
	  section.data(155).logicalSrcIdx = 154;
	  section.data(155).dtTransOffset = 43336;
	
	  ;% controller_template_P.UnitDelay1_X0_d
	  section.data(156).logicalSrcIdx = 155;
	  section.data(156).dtTransOffset = 43337;
	
	  ;% controller_template_P.Gain_Gain_b
	  section.data(157).logicalSrcIdx = 156;
	  section.data(157).dtTransOffset = 43338;
	
	  ;% controller_template_P.UnitDelay1_X0_j
	  section.data(158).logicalSrcIdx = 157;
	  section.data(158).dtTransOffset = 43339;
	
	  ;% controller_template_P.Gain1_Gain_e
	  section.data(159).logicalSrcIdx = 158;
	  section.data(159).dtTransOffset = 43340;
	
	  ;% controller_template_P.Gain_Gain_e
	  section.data(160).logicalSrcIdx = 159;
	  section.data(160).dtTransOffset = 43341;
	
	  ;% controller_template_P.UnitDelay1_X0_f
	  section.data(161).logicalSrcIdx = 160;
	  section.data(161).dtTransOffset = 43342;
	
	  ;% controller_template_P.g_Value
	  section.data(162).logicalSrcIdx = 161;
	  section.data(162).dtTransOffset = 43343;
	
	  ;% controller_template_P.Constant_Value_ks
	  section.data(163).logicalSrcIdx = 162;
	  section.data(163).dtTransOffset = 43344;
	
	  ;% controller_template_P.SliderGain_Gain_n
	  section.data(164).logicalSrcIdx = 163;
	  section.data(164).dtTransOffset = 43345;
	
	  ;% controller_template_P.Constant1_Value_i
	  section.data(165).logicalSrcIdx = 164;
	  section.data(165).dtTransOffset = 43346;
	
	  ;% controller_template_P.SliderGain_Gain_i
	  section.data(166).logicalSrcIdx = 165;
	  section.data(166).dtTransOffset = 43347;
	
	  ;% controller_template_P.Saturation3_UpperSat_p
	  section.data(167).logicalSrcIdx = 166;
	  section.data(167).dtTransOffset = 43348;
	
	  ;% controller_template_P.Saturation3_LowerSat_es
	  section.data(168).logicalSrcIdx = 167;
	  section.data(168).dtTransOffset = 43349;
	
	  ;% controller_template_P.X_ref_x_Value
	  section.data(169).logicalSrcIdx = 168;
	  section.data(169).dtTransOffset = 43350;
	
	  ;% controller_template_P.Constant_Value_i
	  section.data(170).logicalSrcIdx = 169;
	  section.data(170).dtTransOffset = 44682;
	
	  ;% controller_template_P.SliderGain_Gain_e
	  section.data(171).logicalSrcIdx = 170;
	  section.data(171).dtTransOffset = 44683;
	
	  ;% controller_template_P.Constant1_Value_e
	  section.data(172).logicalSrcIdx = 171;
	  section.data(172).dtTransOffset = 44684;
	
	  ;% controller_template_P.SliderGain_Gain_jr
	  section.data(173).logicalSrcIdx = 172;
	  section.data(173).dtTransOffset = 44685;
	
	  ;% controller_template_P.Saturation3_UpperSat_f
	  section.data(174).logicalSrcIdx = 173;
	  section.data(174).dtTransOffset = 44686;
	
	  ;% controller_template_P.Saturation3_LowerSat_lw
	  section.data(175).logicalSrcIdx = 174;
	  section.data(175).dtTransOffset = 44687;
	
	  ;% controller_template_P.UnitDelay_2_X0
	  section.data(176).logicalSrcIdx = 175;
	  section.data(176).dtTransOffset = 44688;
	
	  ;% controller_template_P.UnitDelay_3_X0
	  section.data(177).logicalSrcIdx = 176;
	  section.data(177).dtTransOffset = 44689;
	
	  ;% controller_template_P.Constant1_Value_j2
	  section.data(178).logicalSrcIdx = 177;
	  section.data(178).dtTransOffset = 44690;
	
	  ;% controller_template_P.SliderGain_Gain_db
	  section.data(179).logicalSrcIdx = 178;
	  section.data(179).dtTransOffset = 44691;
	
	  ;% controller_template_P.Constant_Value_le
	  section.data(180).logicalSrcIdx = 179;
	  section.data(180).dtTransOffset = 44692;
	
	  ;% controller_template_P.SliderGain_Gain_ne
	  section.data(181).logicalSrcIdx = 180;
	  section.data(181).dtTransOffset = 44693;
	
	  ;% controller_template_P.Constant_Value_kb
	  section.data(182).logicalSrcIdx = 181;
	  section.data(182).dtTransOffset = 44694;
	
	  ;% controller_template_P.SliderGain_Gain_dsh
	  section.data(183).logicalSrcIdx = 182;
	  section.data(183).dtTransOffset = 44695;
	
	  ;% controller_template_P.SliderGain_Gain_cx
	  section.data(184).logicalSrcIdx = 183;
	  section.data(184).dtTransOffset = 44696;
	
	  ;% controller_template_P.Constant1_Value_kj
	  section.data(185).logicalSrcIdx = 184;
	  section.data(185).dtTransOffset = 44697;
	
	  ;% controller_template_P.SliderGain_Gain_mi
	  section.data(186).logicalSrcIdx = 185;
	  section.data(186).dtTransOffset = 44698;
	
	  ;% controller_template_P.Constant2_Value_c
	  section.data(187).logicalSrcIdx = 186;
	  section.data(187).dtTransOffset = 44699;
	
	  ;% controller_template_P.SliderGain_Gain_nu
	  section.data(188).logicalSrcIdx = 187;
	  section.data(188).dtTransOffset = 44700;
	
	  ;% controller_template_P.Constant3_Value_f
	  section.data(189).logicalSrcIdx = 188;
	  section.data(189).dtTransOffset = 44701;
	
	  ;% controller_template_P.SliderGain_Gain_k
	  section.data(190).logicalSrcIdx = 189;
	  section.data(190).dtTransOffset = 44702;
	
	  ;% controller_template_P.Switch1_Threshold
	  section.data(191).logicalSrcIdx = 190;
	  section.data(191).dtTransOffset = 44703;
	
	  ;% controller_template_P.Switch_Threshold
	  section.data(192).logicalSrcIdx = 191;
	  section.data(192).dtTransOffset = 44704;
	
	  ;% controller_template_P.SliderGain_Gain_h
	  section.data(193).logicalSrcIdx = 192;
	  section.data(193).dtTransOffset = 44705;
	
	  ;% controller_template_P.TotalSamples_Value
	  section.data(194).logicalSrcIdx = 193;
	  section.data(194).dtTransOffset = 44706;
	
	  ;% controller_template_P.UnitDelay1_X0_ie
	  section.data(195).logicalSrcIdx = 194;
	  section.data(195).dtTransOffset = 44707;
	
	  ;% controller_template_P.UnitDelay_X0_o
	  section.data(196).logicalSrcIdx = 195;
	  section.data(196).dtTransOffset = 44708;
	
	  ;% controller_template_P.total_samples_Value
	  section.data(197).logicalSrcIdx = 196;
	  section.data(197).dtTransOffset = 44709;
	
	  ;% controller_template_P.Constant1_Value_mu
	  section.data(198).logicalSrcIdx = 197;
	  section.data(198).dtTransOffset = 44710;
	
	  ;% controller_template_P.X_ref_x_Value_k
	  section.data(199).logicalSrcIdx = 198;
	  section.data(199).dtTransOffset = 44711;
	
	  ;% controller_template_P.Constant_Value_kh
	  section.data(200).logicalSrcIdx = 199;
	  section.data(200).dtTransOffset = 46043;
	
	  ;% controller_template_P.UnitDelay_X0_b
	  section.data(201).logicalSrcIdx = 200;
	  section.data(201).dtTransOffset = 46044;
	
	  ;% controller_template_P.total_samples_Value_k
	  section.data(202).logicalSrcIdx = 201;
	  section.data(202).dtTransOffset = 46045;
	
	  ;% controller_template_P.Constant1_Value_h
	  section.data(203).logicalSrcIdx = 202;
	  section.data(203).dtTransOffset = 46046;
	
	  ;% controller_template_P.X_ref_y_Value
	  section.data(204).logicalSrcIdx = 203;
	  section.data(204).dtTransOffset = 46047;
	
	  ;% controller_template_P.X_ref_y_Value_e
	  section.data(205).logicalSrcIdx = 204;
	  section.data(205).dtTransOffset = 47379;
	
	  ;% controller_template_P.X_ref_z_Value
	  section.data(206).logicalSrcIdx = 205;
	  section.data(206).dtTransOffset = 48711;
	
	  ;% controller_template_P.X_ref_z_Value_a
	  section.data(207).logicalSrcIdx = 206;
	  section.data(207).dtTransOffset = 49599;
	
	  ;% controller_template_P.X_ref_yaw_Value
	  section.data(208).logicalSrcIdx = 207;
	  section.data(208).dtTransOffset = 50487;
	
	  ;% controller_template_P.X_ref_yaw_Value_f
	  section.data(209).logicalSrcIdx = 208;
	  section.data(209).dtTransOffset = 51375;
	
	  ;% controller_template_P.Gain_Gain_a
	  section.data(210).logicalSrcIdx = 209;
	  section.data(210).dtTransOffset = 52263;
	
	  ;% controller_template_P.raddeg2_Gain
	  section.data(211).logicalSrcIdx = 210;
	  section.data(211).dtTransOffset = 52264;
	
	  ;% controller_template_P.raddeg1_Gain
	  section.data(212).logicalSrcIdx = 211;
	  section.data(212).dtTransOffset = 52265;
	
	  ;% controller_template_P.raddeg3_Gain
	  section.data(213).logicalSrcIdx = 212;
	  section.data(213).dtTransOffset = 52266;
	
	  ;% controller_template_P.raddeg_Gain
	  section.data(214).logicalSrcIdx = 213;
	  section.data(214).dtTransOffset = 52267;
	
	  ;% controller_template_P.Gain_Gain_d
	  section.data(215).logicalSrcIdx = 214;
	  section.data(215).dtTransOffset = 52268;
	
	  ;% controller_template_P.UnitDelay_X0_l
	  section.data(216).logicalSrcIdx = 215;
	  section.data(216).dtTransOffset = 52269;
	
	  ;% controller_template_P.UnitDelay1_X0_js
	  section.data(217).logicalSrcIdx = 216;
	  section.data(217).dtTransOffset = 52270;
	
	  ;% controller_template_P.yaw_rate_bias_Value
	  section.data(218).logicalSrcIdx = 217;
	  section.data(218).dtTransOffset = 52271;
	
	  ;% controller_template_P.thrust_bias_Value
	  section.data(219).logicalSrcIdx = 218;
	  section.data(219).dtTransOffset = 52272;
	
	  ;% controller_template_P.roll_bias_Value
	  section.data(220).logicalSrcIdx = 219;
	  section.data(220).dtTransOffset = 52273;
	
	  ;% controller_template_P.pitch_bias_Value
	  section.data(221).logicalSrcIdx = 220;
	  section.data(221).dtTransOffset = 52274;
	
	  ;% controller_template_P.yaw_Value
	  section.data(222).logicalSrcIdx = 221;
	  section.data(222).dtTransOffset = 52275;
	
	  ;% controller_template_P.gravity_Value_c
	  section.data(223).logicalSrcIdx = 222;
	  section.data(223).dtTransOffset = 52276;
	
	  ;% controller_template_P.roll_Value
	  section.data(224).logicalSrcIdx = 223;
	  section.data(224).dtTransOffset = 52277;
	
	  ;% controller_template_P.pitch_Value
	  section.data(225).logicalSrcIdx = 224;
	  section.data(225).dtTransOffset = 52278;
	
	  ;% controller_template_P.yaw_rate_Value
	  section.data(226).logicalSrcIdx = 225;
	  section.data(226).dtTransOffset = 52279;
	
	  ;% controller_template_P.yaw_cmd2yaw_Gain
	  section.data(227).logicalSrcIdx = 226;
	  section.data(227).dtTransOffset = 52280;
	
	  ;% controller_template_P.IntegerDelay_InitialCondition
	  section.data(228).logicalSrcIdx = 227;
	  section.data(228).dtTransOffset = 52281;
	
	  ;% controller_template_P.IntegerDelay1_InitialCondition
	  section.data(229).logicalSrcIdx = 228;
	  section.data(229).dtTransOffset = 52282;
	
	  ;% controller_template_P.IntegerDelay2_InitialCondition
	  section.data(230).logicalSrcIdx = 229;
	  section.data(230).dtTransOffset = 52283;
	
	  ;% controller_template_P.IntegerDelay3_InitialConditio_c
	  section.data(231).logicalSrcIdx = 230;
	  section.data(231).dtTransOffset = 52284;
	
	  ;% controller_template_P.gravity_Value_j
	  section.data(232).logicalSrcIdx = 231;
	  section.data(232).dtTransOffset = 52285;
	
	  ;% controller_template_P.TT_PP_Value
	  section.data(233).logicalSrcIdx = 232;
	  section.data(233).dtTransOffset = 52286;
	
	  ;% controller_template_P.LL_PP_Value
	  section.data(234).logicalSrcIdx = 233;
	  section.data(234).dtTransOffset = 53186;
	
	  ;% controller_template_P.LL_ref_PP_Value
	  section.data(235).logicalSrcIdx = 234;
	  section.data(235).dtTransOffset = 53276;
	
	  ;% controller_template_P.LL_U_ref_PP_Value
	  section.data(236).logicalSrcIdx = 235;
	  section.data(236).dtTransOffset = 56066;
	
	  ;% controller_template_P.MM_Value
	  section.data(237).logicalSrcIdx = 236;
	  section.data(237).dtTransOffset = 56966;
	
	  ;% controller_template_P.PP_Value
	  section.data(238).logicalSrcIdx = 237;
	  section.data(238).dtTransOffset = 56975;
	
	  ;% controller_template_P.AA_delay_Value
	  section.data(239).logicalSrcIdx = 238;
	  section.data(239).dtTransOffset = 57875;
	
	  ;% controller_template_P.BB_delay_Value
	  section.data(240).logicalSrcIdx = 239;
	  section.data(240).dtTransOffset = 57884;
	
	  ;% controller_template_P.A_Value_h
	  section.data(241).logicalSrcIdx = 240;
	  section.data(241).dtTransOffset = 57893;
	
	  ;% controller_template_P.B_Value_i
	  section.data(242).logicalSrcIdx = 241;
	  section.data(242).dtTransOffset = 57909;
	
	  ;% controller_template_P.C_Value_c
	  section.data(243).logicalSrcIdx = 242;
	  section.data(243).dtTransOffset = 57913;
	
	  ;% controller_template_P.D_Value_l
	  section.data(244).logicalSrcIdx = 243;
	  section.data(244).dtTransOffset = 57925;
	
	  ;% controller_template_P.Q_Value_a
	  section.data(245).logicalSrcIdx = 244;
	  section.data(245).dtTransOffset = 57928;
	
	  ;% controller_template_P.R_Value_c
	  section.data(246).logicalSrcIdx = 245;
	  section.data(246).dtTransOffset = 57944;
	
	  ;% controller_template_P.UnitDelay1_X0_c
	  section.data(247).logicalSrcIdx = 246;
	  section.data(247).dtTransOffset = 57953;
	
	  ;% controller_template_P.FixPtUnitDelay1_X0_f
	  section.data(248).logicalSrcIdx = 247;
	  section.data(248).dtTransOffset = 57969;
	
	  ;% controller_template_P.V_max_Value
	  section.data(249).logicalSrcIdx = 248;
	  section.data(249).dtTransOffset = 57970;
	
	  ;% controller_template_P.i_min_Value
	  section.data(250).logicalSrcIdx = 249;
	  section.data(250).dtTransOffset = 58000;
	
	  ;% controller_template_P.betas_Value
	  section.data(251).logicalSrcIdx = 250;
	  section.data(251).dtTransOffset = 58001;
	
	  ;% controller_template_P.L_Value
	  section.data(252).logicalSrcIdx = 251;
	  section.data(252).dtTransOffset = 58008;
	
	  ;% controller_template_P.UnitDelay_X0_fc
	  section.data(253).logicalSrcIdx = 252;
	  section.data(253).dtTransOffset = 58009;
	
	  ;% controller_template_P.UnitDelay1_X0_k
	  section.data(254).logicalSrcIdx = 253;
	  section.data(254).dtTransOffset = 58012;
	
	  ;% controller_template_P.Saturation_UpperSat_ia
	  section.data(255).logicalSrcIdx = 254;
	  section.data(255).dtTransOffset = 58042;
	
	  ;% controller_template_P.Saturation_LowerSat_o
	  section.data(256).logicalSrcIdx = 255;
	  section.data(256).dtTransOffset = 58043;
	
	  ;% controller_template_P.TT_PP_Value_m
	  section.data(257).logicalSrcIdx = 256;
	  section.data(257).dtTransOffset = 58044;
	
	  ;% controller_template_P.LL_PP_Value_e
	  section.data(258).logicalSrcIdx = 257;
	  section.data(258).dtTransOffset = 58944;
	
	  ;% controller_template_P.LL_ref_PP_Value_l
	  section.data(259).logicalSrcIdx = 258;
	  section.data(259).dtTransOffset = 59034;
	
	  ;% controller_template_P.LL_U_ref_PP_Value_m
	  section.data(260).logicalSrcIdx = 259;
	  section.data(260).dtTransOffset = 61824;
	
	  ;% controller_template_P.MM_Value_c
	  section.data(261).logicalSrcIdx = 260;
	  section.data(261).dtTransOffset = 62724;
	
	  ;% controller_template_P.PP_Value_m
	  section.data(262).logicalSrcIdx = 261;
	  section.data(262).dtTransOffset = 62733;
	
	  ;% controller_template_P.AA_delay_Value_h
	  section.data(263).logicalSrcIdx = 262;
	  section.data(263).dtTransOffset = 63633;
	
	  ;% controller_template_P.BB_delay_Value_o
	  section.data(264).logicalSrcIdx = 263;
	  section.data(264).dtTransOffset = 63642;
	
	  ;% controller_template_P.A_Value_n
	  section.data(265).logicalSrcIdx = 264;
	  section.data(265).dtTransOffset = 63651;
	
	  ;% controller_template_P.B_Value_h
	  section.data(266).logicalSrcIdx = 265;
	  section.data(266).dtTransOffset = 63667;
	
	  ;% controller_template_P.C_Value_p
	  section.data(267).logicalSrcIdx = 266;
	  section.data(267).dtTransOffset = 63671;
	
	  ;% controller_template_P.D_Value_m
	  section.data(268).logicalSrcIdx = 267;
	  section.data(268).dtTransOffset = 63683;
	
	  ;% controller_template_P.Q_Value_h
	  section.data(269).logicalSrcIdx = 268;
	  section.data(269).dtTransOffset = 63686;
	
	  ;% controller_template_P.R_Value_l
	  section.data(270).logicalSrcIdx = 269;
	  section.data(270).dtTransOffset = 63702;
	
	  ;% controller_template_P.UnitDelay1_X0_fk
	  section.data(271).logicalSrcIdx = 270;
	  section.data(271).dtTransOffset = 63711;
	
	  ;% controller_template_P.FixPtUnitDelay1_X0_n
	  section.data(272).logicalSrcIdx = 271;
	  section.data(272).dtTransOffset = 63727;
	
	  ;% controller_template_P.V_max_Value_o
	  section.data(273).logicalSrcIdx = 272;
	  section.data(273).dtTransOffset = 63728;
	
	  ;% controller_template_P.i_min_Value_j
	  section.data(274).logicalSrcIdx = 273;
	  section.data(274).dtTransOffset = 63758;
	
	  ;% controller_template_P.betas_Value_l
	  section.data(275).logicalSrcIdx = 274;
	  section.data(275).dtTransOffset = 63759;
	
	  ;% controller_template_P.L_Value_n
	  section.data(276).logicalSrcIdx = 275;
	  section.data(276).dtTransOffset = 63766;
	
	  ;% controller_template_P.UnitDelay_X0_ik
	  section.data(277).logicalSrcIdx = 276;
	  section.data(277).dtTransOffset = 63767;
	
	  ;% controller_template_P.UnitDelay1_X0_jc
	  section.data(278).logicalSrcIdx = 277;
	  section.data(278).dtTransOffset = 63770;
	
	  ;% controller_template_P.Saturation_UpperSat_f
	  section.data(279).logicalSrcIdx = 278;
	  section.data(279).dtTransOffset = 63800;
	
	  ;% controller_template_P.Saturation_LowerSat_k
	  section.data(280).logicalSrcIdx = 279;
	  section.data(280).dtTransOffset = 63801;
	
	  ;% controller_template_P.TT_PP_Value_b
	  section.data(281).logicalSrcIdx = 280;
	  section.data(281).dtTransOffset = 63802;
	
	  ;% controller_template_P.LL_PP_Value_j
	  section.data(282).logicalSrcIdx = 281;
	  section.data(282).dtTransOffset = 64702;
	
	  ;% controller_template_P.LL_ref_PP_Value_h
	  section.data(283).logicalSrcIdx = 282;
	  section.data(283).dtTransOffset = 64762;
	
	  ;% controller_template_P.LL_U_ref_PP_Value_o
	  section.data(284).logicalSrcIdx = 283;
	  section.data(284).dtTransOffset = 66622;
	
	  ;% controller_template_P.MM_Value_l
	  section.data(285).logicalSrcIdx = 284;
	  section.data(285).dtTransOffset = 67522;
	
	  ;% controller_template_P.PP_Value_o
	  section.data(286).logicalSrcIdx = 285;
	  section.data(286).dtTransOffset = 67526;
	
	  ;% controller_template_P.AA_delay_Value_l
	  section.data(287).logicalSrcIdx = 286;
	  section.data(287).dtTransOffset = 68426;
	
	  ;% controller_template_P.BB_delay_Value_b
	  section.data(288).logicalSrcIdx = 287;
	  section.data(288).dtTransOffset = 68430;
	
	  ;% controller_template_P.A_Value_f
	  section.data(289).logicalSrcIdx = 288;
	  section.data(289).dtTransOffset = 68434;
	
	  ;% controller_template_P.B_Value_n
	  section.data(290).logicalSrcIdx = 289;
	  section.data(290).dtTransOffset = 68443;
	
	  ;% controller_template_P.C_Value_o
	  section.data(291).logicalSrcIdx = 290;
	  section.data(291).dtTransOffset = 68446;
	
	  ;% controller_template_P.D_Value_j
	  section.data(292).logicalSrcIdx = 291;
	  section.data(292).dtTransOffset = 68452;
	
	  ;% controller_template_P.Q_Value_j
	  section.data(293).logicalSrcIdx = 292;
	  section.data(293).dtTransOffset = 68454;
	
	  ;% controller_template_P.R_Value_ca
	  section.data(294).logicalSrcIdx = 293;
	  section.data(294).dtTransOffset = 68463;
	
	  ;% controller_template_P.UnitDelay1_X0_cw
	  section.data(295).logicalSrcIdx = 294;
	  section.data(295).dtTransOffset = 68467;
	
	  ;% controller_template_P.FixPtUnitDelay1_X0_c
	  section.data(296).logicalSrcIdx = 295;
	  section.data(296).dtTransOffset = 68476;
	
	  ;% controller_template_P.V_max_Value_i
	  section.data(297).logicalSrcIdx = 296;
	  section.data(297).dtTransOffset = 68477;
	
	  ;% controller_template_P.i_min_Value_o
	  section.data(298).logicalSrcIdx = 297;
	  section.data(298).dtTransOffset = 68507;
	
	  ;% controller_template_P.betas_Value_g
	  section.data(299).logicalSrcIdx = 298;
	  section.data(299).dtTransOffset = 68508;
	
	  ;% controller_template_P.L_Value_m
	  section.data(300).logicalSrcIdx = 299;
	  section.data(300).dtTransOffset = 68516;
	
	  ;% controller_template_P.UnitDelay_X0_a
	  section.data(301).logicalSrcIdx = 300;
	  section.data(301).dtTransOffset = 68517;
	
	  ;% controller_template_P.UnitDelay1_X0_b
	  section.data(302).logicalSrcIdx = 301;
	  section.data(302).dtTransOffset = 68519;
	
	  ;% controller_template_P.Saturation_UpperSat_l
	  section.data(303).logicalSrcIdx = 302;
	  section.data(303).dtTransOffset = 68549;
	
	  ;% controller_template_P.Saturation_LowerSat_cp
	  section.data(304).logicalSrcIdx = 303;
	  section.data(304).dtTransOffset = 68550;
	
	  ;% controller_template_P.TT_PP_Value_o
	  section.data(305).logicalSrcIdx = 304;
	  section.data(305).dtTransOffset = 68551;
	
	  ;% controller_template_P.LL_PP_Value_j5
	  section.data(306).logicalSrcIdx = 305;
	  section.data(306).dtTransOffset = 69451;
	
	  ;% controller_template_P.LL_ref_PP_Value_e
	  section.data(307).logicalSrcIdx = 306;
	  section.data(307).dtTransOffset = 69511;
	
	  ;% controller_template_P.LL_U_ref_PP_Value_b
	  section.data(308).logicalSrcIdx = 307;
	  section.data(308).dtTransOffset = 71371;
	
	  ;% controller_template_P.MM_Value_g
	  section.data(309).logicalSrcIdx = 308;
	  section.data(309).dtTransOffset = 72271;
	
	  ;% controller_template_P.PP_Value_p
	  section.data(310).logicalSrcIdx = 309;
	  section.data(310).dtTransOffset = 72275;
	
	  ;% controller_template_P.AA_delay_Value_o
	  section.data(311).logicalSrcIdx = 310;
	  section.data(311).dtTransOffset = 73175;
	
	  ;% controller_template_P.BB_delay_Value_d
	  section.data(312).logicalSrcIdx = 311;
	  section.data(312).dtTransOffset = 73179;
	
	  ;% controller_template_P.A_Value_k
	  section.data(313).logicalSrcIdx = 312;
	  section.data(313).dtTransOffset = 73191;
	
	  ;% controller_template_P.B_Value_f
	  section.data(314).logicalSrcIdx = 313;
	  section.data(314).dtTransOffset = 73200;
	
	  ;% controller_template_P.C_Value_b
	  section.data(315).logicalSrcIdx = 314;
	  section.data(315).dtTransOffset = 73203;
	
	  ;% controller_template_P.D_Value_c
	  section.data(316).logicalSrcIdx = 315;
	  section.data(316).dtTransOffset = 73209;
	
	  ;% controller_template_P.Q_Value_g
	  section.data(317).logicalSrcIdx = 316;
	  section.data(317).dtTransOffset = 73211;
	
	  ;% controller_template_P.R_Value_o
	  section.data(318).logicalSrcIdx = 317;
	  section.data(318).dtTransOffset = 73220;
	
	  ;% controller_template_P.UnitDelay1_X0_n
	  section.data(319).logicalSrcIdx = 318;
	  section.data(319).dtTransOffset = 73224;
	
	  ;% controller_template_P.FixPtUnitDelay1_X0_e
	  section.data(320).logicalSrcIdx = 319;
	  section.data(320).dtTransOffset = 73233;
	
	  ;% controller_template_P.V_max_Value_f
	  section.data(321).logicalSrcIdx = 320;
	  section.data(321).dtTransOffset = 73234;
	
	  ;% controller_template_P.i_min_Value_n
	  section.data(322).logicalSrcIdx = 321;
	  section.data(322).dtTransOffset = 73264;
	
	  ;% controller_template_P.betas_Value_j
	  section.data(323).logicalSrcIdx = 322;
	  section.data(323).dtTransOffset = 73265;
	
	  ;% controller_template_P.L_Value_g
	  section.data(324).logicalSrcIdx = 323;
	  section.data(324).dtTransOffset = 73270;
	
	  ;% controller_template_P.UnitDelay_X0_fj
	  section.data(325).logicalSrcIdx = 324;
	  section.data(325).dtTransOffset = 73271;
	
	  ;% controller_template_P.UnitDelay1_X0_o
	  section.data(326).logicalSrcIdx = 325;
	  section.data(326).dtTransOffset = 73277;
	
	  ;% controller_template_P.Saturation_UpperSat_o3
	  section.data(327).logicalSrcIdx = 326;
	  section.data(327).dtTransOffset = 73307;
	
	  ;% controller_template_P.Saturation_LowerSat_kn
	  section.data(328).logicalSrcIdx = 327;
	  section.data(328).dtTransOffset = 73308;
	
	  ;% controller_template_P.g_Value_m
	  section.data(329).logicalSrcIdx = 328;
	  section.data(329).dtTransOffset = 73309;
	
	  ;% controller_template_P.Gain_Gain_o
	  section.data(330).logicalSrcIdx = 329;
	  section.data(330).dtTransOffset = 73310;
	
	  ;% controller_template_P.raddeg2_Gain_p
	  section.data(331).logicalSrcIdx = 330;
	  section.data(331).dtTransOffset = 73311;
	
	  ;% controller_template_P.raddeg1_Gain_a
	  section.data(332).logicalSrcIdx = 331;
	  section.data(332).dtTransOffset = 73312;
	
	  ;% controller_template_P.raddeg3_Gain_k
	  section.data(333).logicalSrcIdx = 332;
	  section.data(333).dtTransOffset = 73313;
	
	  ;% controller_template_P.raddeg_Gain_k
	  section.data(334).logicalSrcIdx = 333;
	  section.data(334).dtTransOffset = 73314;
	
	  ;% controller_template_P.pitch_offset_Value
	  section.data(335).logicalSrcIdx = 334;
	  section.data(335).dtTransOffset = 73315;
	
	  ;% controller_template_P.InitialCondition_Value
	  section.data(336).logicalSrcIdx = 335;
	  section.data(336).dtTransOffset = 73316;
	
	  ;% controller_template_P.Constant1_Value_mr
	  section.data(337).logicalSrcIdx = 336;
	  section.data(337).dtTransOffset = 73317;
	
	  ;% controller_template_P.Constant2_Value_a
	  section.data(338).logicalSrcIdx = 337;
	  section.data(338).dtTransOffset = 73318;
	
	  ;% controller_template_P.FixPtUnitDelay1_X0_h
	  section.data(339).logicalSrcIdx = 338;
	  section.data(339).dtTransOffset = 73319;
	
	  ;% controller_template_P.Constant_Value_p
	  section.data(340).logicalSrcIdx = 339;
	  section.data(340).dtTransOffset = 73320;
	
	  ;% controller_template_P.pitch_cmd2pitch_Gain
	  section.data(341).logicalSrcIdx = 340;
	  section.data(341).dtTransOffset = 73321;
	
	  ;% controller_template_P.Gain1_Gain_eg
	  section.data(342).logicalSrcIdx = 341;
	  section.data(342).dtTransOffset = 73322;
	
	  ;% controller_template_P.roll_offset_Value
	  section.data(343).logicalSrcIdx = 342;
	  section.data(343).dtTransOffset = 73323;
	
	  ;% controller_template_P.roll_cmd2roll_Gain
	  section.data(344).logicalSrcIdx = 343;
	  section.data(344).dtTransOffset = 73324;
	
	  ;% controller_template_P.Gain2_Gain_a
	  section.data(345).logicalSrcIdx = 344;
	  section.data(345).dtTransOffset = 73325;
	
	  ;% controller_template_P.gravity_Value_ch
	  section.data(346).logicalSrcIdx = 345;
	  section.data(346).dtTransOffset = 73326;
	
	  ;% controller_template_P.Constant_Value_lf
	  section.data(347).logicalSrcIdx = 346;
	  section.data(347).dtTransOffset = 73327;
	
	  ;% controller_template_P.SliderGain_Gain_px
	  section.data(348).logicalSrcIdx = 347;
	  section.data(348).dtTransOffset = 73328;
	
	  ;% controller_template_P.Gain5_Gain
	  section.data(349).logicalSrcIdx = 348;
	  section.data(349).dtTransOffset = 73329;
	
	  ;% controller_template_P.Constant1_Value_ih
	  section.data(350).logicalSrcIdx = 349;
	  section.data(350).dtTransOffset = 73330;
	
	  ;% controller_template_P.Saturation_UpperSat_pb
	  section.data(351).logicalSrcIdx = 350;
	  section.data(351).dtTransOffset = 73331;
	
	  ;% controller_template_P.Saturation_LowerSat_h
	  section.data(352).logicalSrcIdx = 351;
	  section.data(352).dtTransOffset = 73332;
	
	  ;% controller_template_P.SliderGain_Gain_o4
	  section.data(353).logicalSrcIdx = 352;
	  section.data(353).dtTransOffset = 73333;
	
	  ;% controller_template_P.trhust_cmd2thrust_Gain
	  section.data(354).logicalSrcIdx = 353;
	  section.data(354).dtTransOffset = 73334;
	
	  ;% controller_template_P.Gain_Gain_k
	  section.data(355).logicalSrcIdx = 354;
	  section.data(355).dtTransOffset = 73335;
	
	  ;% controller_template_P.Gain3_Gain
	  section.data(356).logicalSrcIdx = 355;
	  section.data(356).dtTransOffset = 73336;
	
	  ;% controller_template_P.Gain4_Gain
	  section.data(357).logicalSrcIdx = 356;
	  section.data(357).dtTransOffset = 73337;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% controller_template_P.IntegerDelay3_DelayLength
	  section.data(1).logicalSrcIdx = 357;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_P.IntegerDelay_DelayLength
	  section.data(2).logicalSrcIdx = 358;
	  section.data(2).dtTransOffset = 1;
	
	  ;% controller_template_P.IntegerDelay1_DelayLength
	  section.data(3).logicalSrcIdx = 359;
	  section.data(3).dtTransOffset = 2;
	
	  ;% controller_template_P.IntegerDelay2_DelayLength
	  section.data(4).logicalSrcIdx = 360;
	  section.data(4).dtTransOffset = 3;
	
	  ;% controller_template_P.IntegerDelay3_DelayLength_o
	  section.data(5).logicalSrcIdx = 361;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 31;
      section.data(31)  = dumData; %prealloc
      
	  ;% controller_template_P.FixPtUnitDelay2_X0
	  section.data(1).logicalSrcIdx = 362;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_P.Constant_Value_lw
	  section.data(2).logicalSrcIdx = 363;
	  section.data(2).dtTransOffset = 1;
	
	  ;% controller_template_P.SwitchControl_Threshold
	  section.data(3).logicalSrcIdx = 364;
	  section.data(3).dtTransOffset = 2;
	
	  ;% controller_template_P.Constant_Value_j
	  section.data(4).logicalSrcIdx = 365;
	  section.data(4).dtTransOffset = 3;
	
	  ;% controller_template_P.SwitchControl_Threshold_a
	  section.data(5).logicalSrcIdx = 366;
	  section.data(5).dtTransOffset = 4;
	
	  ;% controller_template_P.FixPtConstant_Value
	  section.data(6).logicalSrcIdx = 367;
	  section.data(6).dtTransOffset = 5;
	
	  ;% controller_template_P.Constant_Value_ph
	  section.data(7).logicalSrcIdx = 368;
	  section.data(7).dtTransOffset = 6;
	
	  ;% controller_template_P.SwitchControl_1_Threshold
	  section.data(8).logicalSrcIdx = 369;
	  section.data(8).dtTransOffset = 7;
	
	  ;% controller_template_P.SwitchControl_2_Threshold
	  section.data(9).logicalSrcIdx = 370;
	  section.data(9).dtTransOffset = 8;
	
	  ;% controller_template_P.SwitchControl_3_Threshold
	  section.data(10).logicalSrcIdx = 371;
	  section.data(10).dtTransOffset = 9;
	
	  ;% controller_template_P.SwitchControl_4_Threshold
	  section.data(11).logicalSrcIdx = 372;
	  section.data(11).dtTransOffset = 10;
	
	  ;% controller_template_P.SwitchControl_5_Threshold
	  section.data(12).logicalSrcIdx = 373;
	  section.data(12).dtTransOffset = 11;
	
	  ;% controller_template_P.SwitchControl_6_Threshold
	  section.data(13).logicalSrcIdx = 374;
	  section.data(13).dtTransOffset = 12;
	
	  ;% controller_template_P.SwitchControl_8_Threshold
	  section.data(14).logicalSrcIdx = 375;
	  section.data(14).dtTransOffset = 13;
	
	  ;% controller_template_P.SwitchControl_7_Threshold
	  section.data(15).logicalSrcIdx = 376;
	  section.data(15).dtTransOffset = 14;
	
	  ;% controller_template_P.FixPtUnitDelay2_X0_d
	  section.data(16).logicalSrcIdx = 377;
	  section.data(16).dtTransOffset = 15;
	
	  ;% controller_template_P.FixPtUnitDelay2_X0_n
	  section.data(17).logicalSrcIdx = 378;
	  section.data(17).dtTransOffset = 16;
	
	  ;% controller_template_P.FixPtUnitDelay2_X0_do
	  section.data(18).logicalSrcIdx = 379;
	  section.data(18).dtTransOffset = 17;
	
	  ;% controller_template_P.FixPtUnitDelay2_X0_i
	  section.data(19).logicalSrcIdx = 380;
	  section.data(19).dtTransOffset = 18;
	
	  ;% controller_template_P.FixPtConstant_Value_h
	  section.data(20).logicalSrcIdx = 381;
	  section.data(20).dtTransOffset = 19;
	
	  ;% controller_template_P.FixPtConstant_Value_o
	  section.data(21).logicalSrcIdx = 382;
	  section.data(21).dtTransOffset = 20;
	
	  ;% controller_template_P.FixPtConstant_Value_n
	  section.data(22).logicalSrcIdx = 383;
	  section.data(22).dtTransOffset = 21;
	
	  ;% controller_template_P.FixPtConstant_Value_p
	  section.data(23).logicalSrcIdx = 384;
	  section.data(23).dtTransOffset = 22;
	
	  ;% controller_template_P.FixPtUnitDelay2_X0_g
	  section.data(24).logicalSrcIdx = 385;
	  section.data(24).dtTransOffset = 23;
	
	  ;% controller_template_P.Constant_Value_he
	  section.data(25).logicalSrcIdx = 386;
	  section.data(25).dtTransOffset = 24;
	
	  ;% controller_template_P.SwitchControl_Threshold_e
	  section.data(26).logicalSrcIdx = 387;
	  section.data(26).dtTransOffset = 25;
	
	  ;% controller_template_P.Constant_Value_nk
	  section.data(27).logicalSrcIdx = 388;
	  section.data(27).dtTransOffset = 26;
	
	  ;% controller_template_P.SwitchControl_Threshold_b
	  section.data(28).logicalSrcIdx = 389;
	  section.data(28).dtTransOffset = 27;
	
	  ;% controller_template_P.Constant_Value_a3
	  section.data(29).logicalSrcIdx = 390;
	  section.data(29).dtTransOffset = 28;
	
	  ;% controller_template_P.SwitchControl_Threshold_ef
	  section.data(30).logicalSrcIdx = 391;
	  section.data(30).dtTransOffset = 29;
	
	  ;% controller_template_P.FixPtConstant_Value_i
	  section.data(31).logicalSrcIdx = 392;
	  section.data(31).dtTransOffset = 30;
	
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
    nTotSects     = 23;
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
      section.nData     = 112;
      section.data(112)  = dumData; %prealloc
      
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
	
	  ;% controller_template_B.SliderGain
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 343;
	
	  ;% controller_template_B.thrust_cmd
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 344;
	
	  ;% controller_template_B.yaw_rate_cmd
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 345;
	
	  ;% controller_template_B.pitch_bias
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 346;
	
	  ;% controller_template_B.roll_bias
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 347;
	
	  ;% controller_template_B.thrust_bias
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 348;
	
	  ;% controller_template_B.yaw_rate_bias
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 349;
	
	  ;% controller_template_B.Gain
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 350;
	
	  ;% controller_template_B.raddeg2
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 354;
	
	  ;% controller_template_B.raddeg1
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 357;
	
	  ;% controller_template_B.raddeg3
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 360;
	
	  ;% controller_template_B.raddeg
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 363;
	
	  ;% controller_template_B.bias_W
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 367;
	
	  ;% controller_template_B.cmd_W
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 371;
	
	  ;% controller_template_B.pitch_rot
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 375;
	
	  ;% controller_template_B.roll_rot
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 376;
	
	  ;% controller_template_B.pitch_bias_rot
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 377;
	
	  ;% controller_template_B.roll_bias_rot
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 378;
	
	  ;% controller_template_B.pitch_cmd_comp
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 379;
	
	  ;% controller_template_B.roll_cmd_comp
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 380;
	
	  ;% controller_template_B.thrust_comp
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 381;
	
	  ;% controller_template_B.thrust_cmd_e
	  section.data(30).logicalSrcIdx = 33;
	  section.data(30).dtTransOffset = 382;
	
	  ;% controller_template_B.u_opt
	  section.data(31).logicalSrcIdx = 34;
	  section.data(31).dtTransOffset = 383;
	
	  ;% controller_template_B.J_star
	  section.data(32).logicalSrcIdx = 35;
	  section.data(32).dtTransOffset = 384;
	
	  ;% controller_template_B.u_buff_out
	  section.data(33).logicalSrcIdx = 36;
	  section.data(33).dtTransOffset = 385;
	
	  ;% controller_template_B.V_init_out
	  section.data(34).logicalSrcIdx = 37;
	  section.data(34).dtTransOffset = 387;
	
	  ;% controller_template_B.u_opt_l
	  section.data(35).logicalSrcIdx = 38;
	  section.data(35).dtTransOffset = 417;
	
	  ;% controller_template_B.J_star_h
	  section.data(36).logicalSrcIdx = 39;
	  section.data(36).dtTransOffset = 418;
	
	  ;% controller_template_B.u_buff_out_i
	  section.data(37).logicalSrcIdx = 40;
	  section.data(37).dtTransOffset = 419;
	
	  ;% controller_template_B.V_init_out_n
	  section.data(38).logicalSrcIdx = 41;
	  section.data(38).dtTransOffset = 425;
	
	  ;% controller_template_B.Switch1
	  section.data(39).logicalSrcIdx = 42;
	  section.data(39).dtTransOffset = 455;
	
	  ;% controller_template_B.Switch
	  section.data(40).logicalSrcIdx = 43;
	  section.data(40).dtTransOffset = 456;
	
	  ;% controller_template_B.UnitDelay1
	  section.data(41).logicalSrcIdx = 44;
	  section.data(41).dtTransOffset = 457;
	
	  ;% controller_template_B.x_ref
	  section.data(42).logicalSrcIdx = 45;
	  section.data(42).dtTransOffset = 458;
	
	  ;% controller_template_B.y_ref
	  section.data(43).logicalSrcIdx = 46;
	  section.data(43).dtTransOffset = 459;
	
	  ;% controller_template_B.z_ref
	  section.data(44).logicalSrcIdx = 47;
	  section.data(44).dtTransOffset = 460;
	
	  ;% controller_template_B.Gain_p
	  section.data(45).logicalSrcIdx = 48;
	  section.data(45).dtTransOffset = 461;
	
	  ;% controller_template_B.raddeg2_p
	  section.data(46).logicalSrcIdx = 49;
	  section.data(46).dtTransOffset = 479;
	
	  ;% controller_template_B.raddeg1_e
	  section.data(47).logicalSrcIdx = 50;
	  section.data(47).dtTransOffset = 482;
	
	  ;% controller_template_B.x_dot_ref
	  section.data(48).logicalSrcIdx = 51;
	  section.data(48).dtTransOffset = 484;
	
	  ;% controller_template_B.y_dot_ref
	  section.data(49).logicalSrcIdx = 52;
	  section.data(49).dtTransOffset = 485;
	
	  ;% controller_template_B.raddeg3_a
	  section.data(50).logicalSrcIdx = 53;
	  section.data(50).dtTransOffset = 486;
	
	  ;% controller_template_B.raddeg_j
	  section.data(51).logicalSrcIdx = 54;
	  section.data(51).dtTransOffset = 489;
	
	  ;% controller_template_B.z_dot_ref
	  section.data(52).logicalSrcIdx = 55;
	  section.data(52).dtTransOffset = 493;
	
	  ;% controller_template_B.Sum
	  section.data(53).logicalSrcIdx = 56;
	  section.data(53).dtTransOffset = 494;
	
	  ;% controller_template_B.Gain_k
	  section.data(54).logicalSrcIdx = 57;
	  section.data(54).dtTransOffset = 496;
	
	  ;% controller_template_B.bias_W_b
	  section.data(55).logicalSrcIdx = 58;
	  section.data(55).dtTransOffset = 498;
	
	  ;% controller_template_B.cmd_W_h
	  section.data(56).logicalSrcIdx = 59;
	  section.data(56).dtTransOffset = 502;
	
	  ;% controller_template_B.pitch_rot_n
	  section.data(57).logicalSrcIdx = 60;
	  section.data(57).dtTransOffset = 506;
	
	  ;% controller_template_B.roll_rot_e
	  section.data(58).logicalSrcIdx = 61;
	  section.data(58).dtTransOffset = 507;
	
	  ;% controller_template_B.pitch_bias_rot_i
	  section.data(59).logicalSrcIdx = 62;
	  section.data(59).dtTransOffset = 508;
	
	  ;% controller_template_B.roll_bias_rot_d
	  section.data(60).logicalSrcIdx = 63;
	  section.data(60).dtTransOffset = 509;
	
	  ;% controller_template_B.pitch_cmd_comp_n
	  section.data(61).logicalSrcIdx = 64;
	  section.data(61).dtTransOffset = 510;
	
	  ;% controller_template_B.roll_cmd_comp_j
	  section.data(62).logicalSrcIdx = 65;
	  section.data(62).dtTransOffset = 511;
	
	  ;% controller_template_B.thrust_comp_k
	  section.data(63).logicalSrcIdx = 66;
	  section.data(63).dtTransOffset = 512;
	
	  ;% controller_template_B.nominal_window_z_out
	  section.data(64).logicalSrcIdx = 67;
	  section.data(64).dtTransOffset = 513;
	
	  ;% controller_template_B.nominal_window_y_out
	  section.data(65).logicalSrcIdx = 68;
	  section.data(65).dtTransOffset = 514;
	
	  ;% controller_template_B.count_out
	  section.data(66).logicalSrcIdx = 69;
	  section.data(66).dtTransOffset = 515;
	
	  ;% controller_template_B.en
	  section.data(67).logicalSrcIdx = 70;
	  section.data(67).dtTransOffset = 516;
	
	  ;% controller_template_B.Gain2
	  section.data(68).logicalSrcIdx = 71;
	  section.data(68).dtTransOffset = 517;
	
	  ;% controller_template_B.SwitchControl
	  section.data(69).logicalSrcIdx = 72;
	  section.data(69).dtTransOffset = 518;
	
	  ;% controller_template_B.RateTransition
	  section.data(70).logicalSrcIdx = 73;
	  section.data(70).dtTransOffset = 519;
	
	  ;% controller_template_B.UnitDelay2
	  section.data(71).logicalSrcIdx = 74;
	  section.data(71).dtTransOffset = 523;
	
	  ;% controller_template_B.RateTransition_l
	  section.data(72).logicalSrcIdx = 75;
	  section.data(72).dtTransOffset = 524;
	
	  ;% controller_template_B.UnitDelay2_p
	  section.data(73).logicalSrcIdx = 76;
	  section.data(73).dtTransOffset = 528;
	
	  ;% controller_template_B.Gain_pk
	  section.data(74).logicalSrcIdx = 77;
	  section.data(74).dtTransOffset = 529;
	
	  ;% controller_template_B.Sum_e
	  section.data(75).logicalSrcIdx = 78;
	  section.data(75).dtTransOffset = 530;
	
	  ;% controller_template_B.Saturation3
	  section.data(76).logicalSrcIdx = 79;
	  section.data(76).dtTransOffset = 531;
	
	  ;% controller_template_B.RateTransition_i
	  section.data(77).logicalSrcIdx = 80;
	  section.data(77).dtTransOffset = 532;
	
	  ;% controller_template_B.UnitDelay2_o
	  section.data(78).logicalSrcIdx = 81;
	  section.data(78).dtTransOffset = 537;
	
	  ;% controller_template_B.Gain_f
	  section.data(79).logicalSrcIdx = 82;
	  section.data(79).dtTransOffset = 538;
	
	  ;% controller_template_B.Saturation1
	  section.data(80).logicalSrcIdx = 83;
	  section.data(80).dtTransOffset = 539;
	
	  ;% controller_template_B.RateTransition_j
	  section.data(81).logicalSrcIdx = 84;
	  section.data(81).dtTransOffset = 540;
	
	  ;% controller_template_B.Gain_i
	  section.data(82).logicalSrcIdx = 85;
	  section.data(82).dtTransOffset = 543;
	
	  ;% controller_template_B.Sum_b
	  section.data(83).logicalSrcIdx = 86;
	  section.data(83).dtTransOffset = 544;
	
	  ;% controller_template_B.Gain_n
	  section.data(84).logicalSrcIdx = 87;
	  section.data(84).dtTransOffset = 545;
	
	  ;% controller_template_B.thrust_cmd_a
	  section.data(85).logicalSrcIdx = 89;
	  section.data(85).dtTransOffset = 546;
	
	  ;% controller_template_B.RateTransition1
	  section.data(86).logicalSrcIdx = 90;
	  section.data(86).dtTransOffset = 547;
	
	  ;% controller_template_B.RateTransition1_l
	  section.data(87).logicalSrcIdx = 91;
	  section.data(87).dtTransOffset = 548;
	
	  ;% controller_template_B.RateTransition1_lq
	  section.data(88).logicalSrcIdx = 92;
	  section.data(88).dtTransOffset = 549;
	
	  ;% controller_template_B.Gain_g
	  section.data(89).logicalSrcIdx = 93;
	  section.data(89).dtTransOffset = 550;
	
	  ;% controller_template_B.Gain1
	  section.data(90).logicalSrcIdx = 94;
	  section.data(90).dtTransOffset = 551;
	
	  ;% controller_template_B.Gain_d
	  section.data(91).logicalSrcIdx = 95;
	  section.data(91).dtTransOffset = 552;
	
	  ;% controller_template_B.u_thrust_out
	  section.data(92).logicalSrcIdx = 96;
	  section.data(92).dtTransOffset = 553;
	
	  ;% controller_template_B.U
	  section.data(93).logicalSrcIdx = 97;
	  section.data(93).dtTransOffset = 554;
	
	  ;% controller_template_B.flag_oob
	  section.data(94).logicalSrcIdx = 98;
	  section.data(94).dtTransOffset = 555;
	
	  ;% controller_template_B.psi_prime
	  section.data(95).logicalSrcIdx = 99;
	  section.data(95).dtTransOffset = 556;
	
	  ;% controller_template_B.psi_out
	  section.data(96).logicalSrcIdx = 100;
	  section.data(96).dtTransOffset = 557;
	
	  ;% controller_template_B.delta_x
	  section.data(97).logicalSrcIdx = 101;
	  section.data(97).dtTransOffset = 558;
	
	  ;% controller_template_B.psi_prime_l
	  section.data(98).logicalSrcIdx = 102;
	  section.data(98).dtTransOffset = 559;
	
	  ;% controller_template_B.y
	  section.data(99).logicalSrcIdx = 103;
	  section.data(99).dtTransOffset = 560;
	
	  ;% controller_template_B.U_g
	  section.data(100).logicalSrcIdx = 104;
	  section.data(100).dtTransOffset = 561;
	
	  ;% controller_template_B.flag_oob_l
	  section.data(101).logicalSrcIdx = 105;
	  section.data(101).dtTransOffset = 562;
	
	  ;% controller_template_B.input_out
	  section.data(102).logicalSrcIdx = 106;
	  section.data(102).dtTransOffset = 563;
	
	  ;% controller_template_B.y_a
	  section.data(103).logicalSrcIdx = 107;
	  section.data(103).dtTransOffset = 564;
	
	  ;% controller_template_B.U_p
	  section.data(104).logicalSrcIdx = 108;
	  section.data(104).dtTransOffset = 569;
	
	  ;% controller_template_B.flag_oob_o
	  section.data(105).logicalSrcIdx = 109;
	  section.data(105).dtTransOffset = 570;
	
	  ;% controller_template_B.y_i
	  section.data(106).logicalSrcIdx = 110;
	  section.data(106).dtTransOffset = 571;
	
	  ;% controller_template_B.U_gb
	  section.data(107).logicalSrcIdx = 111;
	  section.data(107).dtTransOffset = 575;
	
	  ;% controller_template_B.flag_oob_ow
	  section.data(108).logicalSrcIdx = 112;
	  section.data(108).dtTransOffset = 576;
	
	  ;% controller_template_B.y_o
	  section.data(109).logicalSrcIdx = 113;
	  section.data(109).dtTransOffset = 577;
	
	  ;% controller_template_B.U_a
	  section.data(110).logicalSrcIdx = 114;
	  section.data(110).dtTransOffset = 581;
	
	  ;% controller_template_B.flag_oob_l1
	  section.data(111).logicalSrcIdx = 115;
	  section.data(111).dtTransOffset = 582;
	
	  ;% controller_template_B.pitch_cmd_out
	  section.data(112).logicalSrcIdx = 116;
	  section.data(112).dtTransOffset = 583;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% controller_template_B.sf_EmbeddedMATLABFunction_o.roll_rot
	  section.data(1).logicalSrcIdx = 117;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_B.sf_EmbeddedMATLABFunction_o.pitch_rot
	  section.data(2).logicalSrcIdx = 118;
	  section.data(2).dtTransOffset = 1;
	
	  ;% controller_template_B.sf_EmbeddedMATLABFunction_o.pitch_bias_rot
	  section.data(3).logicalSrcIdx = 119;
	  section.data(3).dtTransOffset = 2;
	
	  ;% controller_template_B.sf_EmbeddedMATLABFunction_o.roll_bias_rot
	  section.data(4).logicalSrcIdx = 120;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_B.sf_discretekalmanfilter_k.state_est
	  section.data(1).logicalSrcIdx = 121;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_B.sf_discretekalmanfilter_k.P_est
	  section.data(2).logicalSrcIdx = 122;
	  section.data(2).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_B.sf_discretekalmanfilter_n.state_est
	  section.data(1).logicalSrcIdx = 123;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_B.sf_discretekalmanfilter_n.P_est
	  section.data(2).logicalSrcIdx = 124;
	  section.data(2).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_B.sf_discretekalmanfilter_m.state_est
	  section.data(1).logicalSrcIdx = 125;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_B.sf_discretekalmanfilter_m.P_est
	  section.data(2).logicalSrcIdx = 126;
	  section.data(2).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(5) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% controller_template_B.sf_runFastGradient_d.u_opt
	  section.data(1).logicalSrcIdx = 127;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_B.sf_runFastGradient_d.J_star
	  section.data(2).logicalSrcIdx = 128;
	  section.data(2).dtTransOffset = 1;
	
	  ;% controller_template_B.sf_runFastGradient_d.u_buff_out
	  section.data(3).logicalSrcIdx = 129;
	  section.data(3).dtTransOffset = 2;
	
	  ;% controller_template_B.sf_runFastGradient_d.V_init_out
	  section.data(4).logicalSrcIdx = 130;
	  section.data(4).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(6) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_B.sf_discretekalmanfilter_b.state_est
	  section.data(1).logicalSrcIdx = 131;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_B.sf_discretekalmanfilter_b.P_est
	  section.data(2).logicalSrcIdx = 132;
	  section.data(2).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(7) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% controller_template_B.sf_runFastGradient.u_opt
	  section.data(1).logicalSrcIdx = 133;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_B.sf_runFastGradient.J_star
	  section.data(2).logicalSrcIdx = 134;
	  section.data(2).dtTransOffset = 1;
	
	  ;% controller_template_B.sf_runFastGradient.u_buff_out
	  section.data(3).logicalSrcIdx = 135;
	  section.data(3).dtTransOffset = 2;
	
	  ;% controller_template_B.sf_runFastGradient.V_init_out
	  section.data(4).logicalSrcIdx = 136;
	  section.data(4).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(8) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% controller_template_B.sf_EmbeddedMATLABFunction.roll_rot
	  section.data(1).logicalSrcIdx = 137;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_B.sf_EmbeddedMATLABFunction.pitch_rot
	  section.data(2).logicalSrcIdx = 138;
	  section.data(2).dtTransOffset = 1;
	
	  ;% controller_template_B.sf_EmbeddedMATLABFunction.pitch_bias_rot
	  section.data(3).logicalSrcIdx = 139;
	  section.data(3).dtTransOffset = 2;
	
	  ;% controller_template_B.sf_EmbeddedMATLABFunction.roll_bias_rot
	  section.data(4).logicalSrcIdx = 140;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(9) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_B.sf_MATLABFunction_p.y
	  section.data(1).logicalSrcIdx = 141;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(10) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_B.sf_generate_X_ref_z.X_ref_z
	  section.data(1).logicalSrcIdx = 142;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(11) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_B.sf_generate_X_ref_yaw.X_ref_yaw
	  section.data(1).logicalSrcIdx = 143;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(12) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_B.sf_generate_X_ref_y.X_ref_y
	  section.data(1).logicalSrcIdx = 144;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(13) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_B.sf_generate_X_ref_x.X_ref_x
	  section.data(1).logicalSrcIdx = 145;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(14) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_B.sf_MATLABFunction.y
	  section.data(1).logicalSrcIdx = 146;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(15) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_B.sf_MATLABFunction_c.y
	  section.data(1).logicalSrcIdx = 147;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(16) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_B.sf_discretekalmanfilter.state_est
	  section.data(1).logicalSrcIdx = 148;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_B.sf_discretekalmanfilter.P_est
	  section.data(2).logicalSrcIdx = 149;
	  section.data(2).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(17) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_B.sf_MATLABFunction_l5.y
	  section.data(1).logicalSrcIdx = 150;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(18) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_B.sf_MATLABFunction_e.y
	  section.data(1).logicalSrcIdx = 151;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(19) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_B.sf_generate_X_ref_z_l.X_ref_z
	  section.data(1).logicalSrcIdx = 152;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(20) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_B.sf_generate_X_ref_yaw_g.X_ref_yaw
	  section.data(1).logicalSrcIdx = 153;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(21) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_B.sf_generate_X_ref_y_a.X_ref_y
	  section.data(1).logicalSrcIdx = 154;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(22) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_B.sf_generate_X_ref_x_k.X_ref_x
	  section.data(1).logicalSrcIdx = 155;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(23) = section;
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
    nTotSects     = 74;
    sectIdxOffset = 23;
    
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
      section.nData     = 48;
      section.data(48)  = dumData; %prealloc
      
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
	
	  ;% controller_template_DWork.UnitDelay_2_DSTATE
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 202;
	
	  ;% controller_template_DWork.UnitDelay_3_DSTATE
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 203;
	
	  ;% controller_template_DWork.UnitDelay1_DSTATE_i
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 204;
	
	  ;% controller_template_DWork.UnitDelay_DSTATE_g
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 205;
	
	  ;% controller_template_DWork.UnitDelay_DSTATE_e
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 206;
	
	  ;% controller_template_DWork.UnitDelay_DSTATE_es
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 207;
	
	  ;% controller_template_DWork.UnitDelay1_DSTATE_o
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 208;
	
	  ;% controller_template_DWork.IntegerDelay3_DSTATE_k
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 209;
	
	  ;% controller_template_DWork.UnitDelay1_DSTATE_bg
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 210;
	
	  ;% controller_template_DWork.FixPtUnitDelay1_DSTATE_i1
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 219;
	
	  ;% controller_template_DWork.UnitDelay2_DSTATE
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 221;
	
	  ;% controller_template_DWork.UnitDelay2_DSTATE_m
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 222;
	
	  ;% controller_template_DWork.UnitDelay2_DSTATE_d
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 223;
	
	  ;% controller_template_DWork.UnitDelay_DSTATE_jv
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 224;
	
	  ;% controller_template_DWork.UnitDelay2_DSTATE_l
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 225;
	
	  ;% controller_template_DWork.UnitDelay2_DSTATE_k
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 226;
	
	  ;% controller_template_DWork.UnitDelay_DSTATE_f
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 227;
	
	  ;% controller_template_DWork.UnitDelay2_DSTATE_b
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 228;
	
	  ;% controller_template_DWork.UnitDelay_DSTATE_fw
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 229;
	
	  ;% controller_template_DWork.UnitDelay_DSTATE_lg
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 230;
	
	  ;% controller_template_DWork.UnitDelay2_DSTATE_g
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 231;
	
	  ;% controller_template_DWork.UnitDelay2_DSTATE_ga
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 232;
	
	  ;% controller_template_DWork.UnitDelay_DSTATE_p
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 233;
	
	  ;% controller_template_DWork.UnitDelay1_DSTATE_a
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 234;
	
	  ;% controller_template_DWork.UnitDelay1_DSTATE_ji
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 235;
	
	  ;% controller_template_DWork.UnitDelay1_DSTATE_c3
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 236;
	
	  ;% controller_template_DWork.UnitDelay1_DSTATE_m
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 237;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 36;
      section.data(36)  = dumData; %prealloc
      
	  ;% controller_template_DWork.bias_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 48;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.cmd_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 49;
	  section.data(2).dtTransOffset = 1;
	
	  ;% controller_template_DWork.cmd1_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 50;
	  section.data(3).dtTransOffset = 2;
	
	  ;% controller_template_DWork.mode_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 51;
	  section.data(4).dtTransOffset = 3;
	
	  ;% controller_template_DWork.mode2_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 52;
	  section.data(5).dtTransOffset = 4;
	
	  ;% controller_template_DWork.mode1_PWORK.LoggedData
	  section.data(6).logicalSrcIdx = 53;
	  section.data(6).dtTransOffset = 5;
	
	  ;% controller_template_DWork.mode1_PWORK_h.LoggedData
	  section.data(7).logicalSrcIdx = 54;
	  section.data(7).dtTransOffset = 6;
	
	  ;% controller_template_DWork.ToFile_PWORK.FilePtr
	  section.data(8).logicalSrcIdx = 55;
	  section.data(8).dtTransOffset = 7;
	
	  ;% controller_template_DWork.ToFile1_PWORK.FilePtr
	  section.data(9).logicalSrcIdx = 56;
	  section.data(9).dtTransOffset = 8;
	
	  ;% controller_template_DWork.ToWorkspace_PWORK.LoggedData
	  section.data(10).logicalSrcIdx = 57;
	  section.data(10).dtTransOffset = 9;
	
	  ;% controller_template_DWork.pitchcmd_PWORK.LoggedData
	  section.data(11).logicalSrcIdx = 58;
	  section.data(11).dtTransOffset = 10;
	
	  ;% controller_template_DWork.rollcmd_PWORK.LoggedData
	  section.data(12).logicalSrcIdx = 59;
	  section.data(12).dtTransOffset = 11;
	
	  ;% controller_template_DWork.thrustcmd_PWORK.LoggedData
	  section.data(13).logicalSrcIdx = 60;
	  section.data(13).dtTransOffset = 12;
	
	  ;% controller_template_DWork.x_ref_PWORK.LoggedData
	  section.data(14).logicalSrcIdx = 61;
	  section.data(14).dtTransOffset = 13;
	
	  ;% controller_template_DWork.y_ref_PWORK.LoggedData
	  section.data(15).logicalSrcIdx = 62;
	  section.data(15).dtTransOffset = 14;
	
	  ;% controller_template_DWork.yawcmd_PWORK.LoggedData
	  section.data(16).logicalSrcIdx = 63;
	  section.data(16).dtTransOffset = 15;
	
	  ;% controller_template_DWork.yaw_ref_PWORK.LoggedData
	  section.data(17).logicalSrcIdx = 64;
	  section.data(17).dtTransOffset = 16;
	
	  ;% controller_template_DWork.z_ref_PWORK.LoggedData
	  section.data(18).logicalSrcIdx = 65;
	  section.data(18).dtTransOffset = 17;
	
	  ;% controller_template_DWork.ToFile_PWORK_p.FilePtr
	  section.data(19).logicalSrcIdx = 66;
	  section.data(19).dtTransOffset = 18;
	
	  ;% controller_template_DWork.ToFile1_PWORK_i.FilePtr
	  section.data(20).logicalSrcIdx = 67;
	  section.data(20).dtTransOffset = 19;
	
	  ;% controller_template_DWork.ToWorkspace_PWORK_h.LoggedData
	  section.data(21).logicalSrcIdx = 68;
	  section.data(21).dtTransOffset = 20;
	
	  ;% controller_template_DWork.pitchcmd_PWORK_p.LoggedData
	  section.data(22).logicalSrcIdx = 69;
	  section.data(22).dtTransOffset = 21;
	
	  ;% controller_template_DWork.rollcmd_PWORK_i.LoggedData
	  section.data(23).logicalSrcIdx = 70;
	  section.data(23).dtTransOffset = 22;
	
	  ;% controller_template_DWork.thrustcmd_PWORK_g.LoggedData
	  section.data(24).logicalSrcIdx = 71;
	  section.data(24).dtTransOffset = 23;
	
	  ;% controller_template_DWork.x_ref_PWORK_a.LoggedData
	  section.data(25).logicalSrcIdx = 72;
	  section.data(25).dtTransOffset = 24;
	
	  ;% controller_template_DWork.y_ref_PWORK_j.LoggedData
	  section.data(26).logicalSrcIdx = 73;
	  section.data(26).dtTransOffset = 25;
	
	  ;% controller_template_DWork.yawcmd_PWORK_p.LoggedData
	  section.data(27).logicalSrcIdx = 74;
	  section.data(27).dtTransOffset = 26;
	
	  ;% controller_template_DWork.yaw_ref_PWORK_n.LoggedData
	  section.data(28).logicalSrcIdx = 75;
	  section.data(28).dtTransOffset = 27;
	
	  ;% controller_template_DWork.z_ref_PWORK_e.LoggedData
	  section.data(29).logicalSrcIdx = 76;
	  section.data(29).dtTransOffset = 28;
	
	  ;% controller_template_DWork.Scope_PWORK.LoggedData
	  section.data(30).logicalSrcIdx = 77;
	  section.data(30).dtTransOffset = 29;
	
	  ;% controller_template_DWork.Scope_PWORK_p.LoggedData
	  section.data(31).logicalSrcIdx = 78;
	  section.data(31).dtTransOffset = 30;
	
	  ;% controller_template_DWork.Scope_PWORK_i.LoggedData
	  section.data(32).logicalSrcIdx = 79;
	  section.data(32).dtTransOffset = 31;
	
	  ;% controller_template_DWork.Scope_PWORK_f.LoggedData
	  section.data(33).logicalSrcIdx = 80;
	  section.data(33).dtTransOffset = 32;
	
	  ;% controller_template_DWork.Scope_PWORK_j.LoggedData
	  section.data(34).logicalSrcIdx = 81;
	  section.data(34).dtTransOffset = 33;
	
	  ;% controller_template_DWork.Scope1_PWORK.LoggedData
	  section.data(35).logicalSrcIdx = 82;
	  section.data(35).dtTransOffset = 34;
	
	  ;% controller_template_DWork.Scope_PWORK_e.LoggedData
	  section.data(36).logicalSrcIdx = 83;
	  section.data(36).dtTransOffset = 35;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 24;
      section.data(24)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sfEvent
	  section.data(1).logicalSrcIdx = 84;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.sfEvent_f
	  section.data(2).logicalSrcIdx = 85;
	  section.data(2).dtTransOffset = 1;
	
	  ;% controller_template_DWork.sfEvent_k
	  section.data(3).logicalSrcIdx = 86;
	  section.data(3).dtTransOffset = 2;
	
	  ;% controller_template_DWork.sfEvent_n
	  section.data(4).logicalSrcIdx = 87;
	  section.data(4).dtTransOffset = 3;
	
	  ;% controller_template_DWork.sfEvent_j
	  section.data(5).logicalSrcIdx = 88;
	  section.data(5).dtTransOffset = 4;
	
	  ;% controller_template_DWork.sfEvent_c
	  section.data(6).logicalSrcIdx = 89;
	  section.data(6).dtTransOffset = 5;
	
	  ;% controller_template_DWork.sfEvent_a
	  section.data(7).logicalSrcIdx = 90;
	  section.data(7).dtTransOffset = 6;
	
	  ;% controller_template_DWork.sfEvent_jg
	  section.data(8).logicalSrcIdx = 91;
	  section.data(8).dtTransOffset = 7;
	
	  ;% controller_template_DWork.sfEvent_p
	  section.data(9).logicalSrcIdx = 92;
	  section.data(9).dtTransOffset = 8;
	
	  ;% controller_template_DWork.sfEvent_jj
	  section.data(10).logicalSrcIdx = 93;
	  section.data(10).dtTransOffset = 9;
	
	  ;% controller_template_DWork.sfEvent_k0
	  section.data(11).logicalSrcIdx = 94;
	  section.data(11).dtTransOffset = 10;
	
	  ;% controller_template_DWork.sfEvent_ks
	  section.data(12).logicalSrcIdx = 95;
	  section.data(12).dtTransOffset = 11;
	
	  ;% controller_template_DWork.sfEvent_d
	  section.data(13).logicalSrcIdx = 96;
	  section.data(13).dtTransOffset = 12;
	
	  ;% controller_template_DWork.sfEvent_g
	  section.data(14).logicalSrcIdx = 97;
	  section.data(14).dtTransOffset = 13;
	
	  ;% controller_template_DWork.sfEvent_l
	  section.data(15).logicalSrcIdx = 98;
	  section.data(15).dtTransOffset = 14;
	
	  ;% controller_template_DWork.sfEvent_jv
	  section.data(16).logicalSrcIdx = 99;
	  section.data(16).dtTransOffset = 15;
	
	  ;% controller_template_DWork.sfEvent_ab
	  section.data(17).logicalSrcIdx = 100;
	  section.data(17).dtTransOffset = 16;
	
	  ;% controller_template_DWork.sfEvent_i
	  section.data(18).logicalSrcIdx = 101;
	  section.data(18).dtTransOffset = 17;
	
	  ;% controller_template_DWork.sfEvent_cd
	  section.data(19).logicalSrcIdx = 102;
	  section.data(19).dtTransOffset = 18;
	
	  ;% controller_template_DWork.sfEvent_ac
	  section.data(20).logicalSrcIdx = 103;
	  section.data(20).dtTransOffset = 19;
	
	  ;% controller_template_DWork.sfEvent_cm
	  section.data(21).logicalSrcIdx = 104;
	  section.data(21).dtTransOffset = 20;
	
	  ;% controller_template_DWork.sfEvent_kd
	  section.data(22).logicalSrcIdx = 105;
	  section.data(22).dtTransOffset = 21;
	
	  ;% controller_template_DWork.sfEvent_cr
	  section.data(23).logicalSrcIdx = 106;
	  section.data(23).dtTransOffset = 22;
	
	  ;% controller_template_DWork.sfEvent_fp
	  section.data(24).logicalSrcIdx = 107;
	  section.data(24).dtTransOffset = 23;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% controller_template_DWork.ToFile_IWORK.Count
	  section.data(1).logicalSrcIdx = 108;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.ToFile1_IWORK.Count
	  section.data(2).logicalSrcIdx = 109;
	  section.data(2).dtTransOffset = 1;
	
	  ;% controller_template_DWork.ToFile_IWORK_g.Count
	  section.data(3).logicalSrcIdx = 110;
	  section.data(3).dtTransOffset = 2;
	
	  ;% controller_template_DWork.ToFile1_IWORK_p.Count
	  section.data(4).logicalSrcIdx = 111;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% controller_template_DWork.FixPtUnitDelay2_DSTATE
	  section.data(1).logicalSrcIdx = 112;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.FixPtUnitDelay2_DSTATE_l
	  section.data(2).logicalSrcIdx = 113;
	  section.data(2).dtTransOffset = 1;
	
	  ;% controller_template_DWork.FixPtUnitDelay2_DSTATE_b
	  section.data(3).logicalSrcIdx = 114;
	  section.data(3).dtTransOffset = 2;
	
	  ;% controller_template_DWork.FixPtUnitDelay2_DSTATE_c
	  section.data(4).logicalSrcIdx = 115;
	  section.data(4).dtTransOffset = 3;
	
	  ;% controller_template_DWork.FixPtUnitDelay2_DSTATE_a
	  section.data(5).logicalSrcIdx = 116;
	  section.data(5).dtTransOffset = 4;
	
	  ;% controller_template_DWork.FixPtUnitDelay2_DSTATE_g
	  section.data(6).logicalSrcIdx = 117;
	  section.data(6).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_DWork.FreeFlightPosCtrl_SubsysRanBC
	  section.data(1).logicalSrcIdx = 118;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.poscontroller_SubsysRanBC
	  section.data(2).logicalSrcIdx = 119;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 24;
      section.data(24)  = dumData; %prealloc
      
	  ;% controller_template_DWork.is_active_c4_Hquad_control_LIB_
	  section.data(1).logicalSrcIdx = 120;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.is_active_c1_Hquad_control_LIB_
	  section.data(2).logicalSrcIdx = 121;
	  section.data(2).dtTransOffset = 1;
	
	  ;% controller_template_DWork.is_active_c8_Hquad_control_LIB_
	  section.data(3).logicalSrcIdx = 122;
	  section.data(3).dtTransOffset = 2;
	
	  ;% controller_template_DWork.is_active_c9_Hquad_control_LIB_
	  section.data(4).logicalSrcIdx = 123;
	  section.data(4).dtTransOffset = 3;
	
	  ;% controller_template_DWork.is_active_c10_controller_templa
	  section.data(5).logicalSrcIdx = 124;
	  section.data(5).dtTransOffset = 4;
	
	  ;% controller_template_DWork.is_active_c9_controller_templat
	  section.data(6).logicalSrcIdx = 125;
	  section.data(6).dtTransOffset = 5;
	
	  ;% controller_template_DWork.is_active_c18_controller_templa
	  section.data(7).logicalSrcIdx = 126;
	  section.data(7).dtTransOffset = 6;
	
	  ;% controller_template_DWork.is_active_c11_controller_templa
	  section.data(8).logicalSrcIdx = 127;
	  section.data(8).dtTransOffset = 7;
	
	  ;% controller_template_DWork.is_active_c35_controller_templa
	  section.data(9).logicalSrcIdx = 128;
	  section.data(9).dtTransOffset = 8;
	
	  ;% controller_template_DWork.is_active_c16_controller_templa
	  section.data(10).logicalSrcIdx = 129;
	  section.data(10).dtTransOffset = 9;
	
	  ;% controller_template_DWork.is_active_c3_controller_templat
	  section.data(11).logicalSrcIdx = 130;
	  section.data(11).dtTransOffset = 10;
	
	  ;% controller_template_DWork.is_active_c28_controller_templa
	  section.data(12).logicalSrcIdx = 131;
	  section.data(12).dtTransOffset = 11;
	
	  ;% controller_template_DWork.is_active_c30_controller_templa
	  section.data(13).logicalSrcIdx = 132;
	  section.data(13).dtTransOffset = 12;
	
	  ;% controller_template_DWork.is_active_c25_controller_templa
	  section.data(14).logicalSrcIdx = 133;
	  section.data(14).dtTransOffset = 13;
	
	  ;% controller_template_DWork.is_active_c6_controller_templat
	  section.data(15).logicalSrcIdx = 134;
	  section.data(15).dtTransOffset = 14;
	
	  ;% controller_template_DWork.is_active_c4_controller_templat
	  section.data(16).logicalSrcIdx = 135;
	  section.data(16).dtTransOffset = 15;
	
	  ;% controller_template_DWork.is_active_c17_controller_templa
	  section.data(17).logicalSrcIdx = 136;
	  section.data(17).dtTransOffset = 16;
	
	  ;% controller_template_DWork.is_active_c5_controller_templat
	  section.data(18).logicalSrcIdx = 137;
	  section.data(18).dtTransOffset = 17;
	
	  ;% controller_template_DWork.is_active_c2_controller_templat
	  section.data(19).logicalSrcIdx = 138;
	  section.data(19).dtTransOffset = 18;
	
	  ;% controller_template_DWork.is_active_c7_controller_templat
	  section.data(20).logicalSrcIdx = 139;
	  section.data(20).dtTransOffset = 19;
	
	  ;% controller_template_DWork.is_active_c1_controller_templat
	  section.data(21).logicalSrcIdx = 140;
	  section.data(21).dtTransOffset = 20;
	
	  ;% controller_template_DWork.is_active_c26_controller_templa
	  section.data(22).logicalSrcIdx = 141;
	  section.data(22).dtTransOffset = 21;
	
	  ;% controller_template_DWork.is_active_c24_controller_templa
	  section.data(23).logicalSrcIdx = 142;
	  section.data(23).dtTransOffset = 22;
	
	  ;% controller_template_DWork.is_active_c12_controller_templa
	  section.data(24).logicalSrcIdx = 143;
	  section.data(24).dtTransOffset = 23;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 50;
      section.data(50)  = dumData; %prealloc
      
	  ;% controller_template_DWork.isStable
	  section.data(1).logicalSrcIdx = 144;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 145;
	  section.data(2).dtTransOffset = 1;
	
	  ;% controller_template_DWork.isStable_m
	  section.data(3).logicalSrcIdx = 146;
	  section.data(3).dtTransOffset = 2;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_e
	  section.data(4).logicalSrcIdx = 147;
	  section.data(4).dtTransOffset = 3;
	
	  ;% controller_template_DWork.isStable_i
	  section.data(5).logicalSrcIdx = 148;
	  section.data(5).dtTransOffset = 4;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_h
	  section.data(6).logicalSrcIdx = 149;
	  section.data(6).dtTransOffset = 5;
	
	  ;% controller_template_DWork.isStable_h
	  section.data(7).logicalSrcIdx = 150;
	  section.data(7).dtTransOffset = 6;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_o
	  section.data(8).logicalSrcIdx = 151;
	  section.data(8).dtTransOffset = 7;
	
	  ;% controller_template_DWork.isStable_o
	  section.data(9).logicalSrcIdx = 152;
	  section.data(9).dtTransOffset = 8;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_c
	  section.data(10).logicalSrcIdx = 153;
	  section.data(10).dtTransOffset = 9;
	
	  ;% controller_template_DWork.isStable_mf
	  section.data(11).logicalSrcIdx = 154;
	  section.data(11).dtTransOffset = 10;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_a
	  section.data(12).logicalSrcIdx = 155;
	  section.data(12).dtTransOffset = 11;
	
	  ;% controller_template_DWork.isStable_g
	  section.data(13).logicalSrcIdx = 156;
	  section.data(13).dtTransOffset = 12;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_ek
	  section.data(14).logicalSrcIdx = 157;
	  section.data(14).dtTransOffset = 13;
	
	  ;% controller_template_DWork.isStable_j
	  section.data(15).logicalSrcIdx = 158;
	  section.data(15).dtTransOffset = 14;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_p
	  section.data(16).logicalSrcIdx = 159;
	  section.data(16).dtTransOffset = 15;
	
	  ;% controller_template_DWork.isStable_od
	  section.data(17).logicalSrcIdx = 160;
	  section.data(17).dtTransOffset = 16;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_em
	  section.data(18).logicalSrcIdx = 161;
	  section.data(18).dtTransOffset = 17;
	
	  ;% controller_template_DWork.isStable_g4
	  section.data(19).logicalSrcIdx = 162;
	  section.data(19).dtTransOffset = 18;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_n
	  section.data(20).logicalSrcIdx = 163;
	  section.data(20).dtTransOffset = 19;
	
	  ;% controller_template_DWork.isStable_c
	  section.data(21).logicalSrcIdx = 164;
	  section.data(21).dtTransOffset = 20;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_ha
	  section.data(22).logicalSrcIdx = 165;
	  section.data(22).dtTransOffset = 21;
	
	  ;% controller_template_DWork.isStable_hz
	  section.data(23).logicalSrcIdx = 166;
	  section.data(23).dtTransOffset = 22;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_l
	  section.data(24).logicalSrcIdx = 167;
	  section.data(24).dtTransOffset = 23;
	
	  ;% controller_template_DWork.isStable_f
	  section.data(25).logicalSrcIdx = 168;
	  section.data(25).dtTransOffset = 24;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_g
	  section.data(26).logicalSrcIdx = 169;
	  section.data(26).dtTransOffset = 25;
	
	  ;% controller_template_DWork.isStable_a
	  section.data(27).logicalSrcIdx = 170;
	  section.data(27).dtTransOffset = 26;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_ga
	  section.data(28).logicalSrcIdx = 171;
	  section.data(28).dtTransOffset = 27;
	
	  ;% controller_template_DWork.isStable_oc
	  section.data(29).logicalSrcIdx = 172;
	  section.data(29).dtTransOffset = 28;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_m
	  section.data(30).logicalSrcIdx = 173;
	  section.data(30).dtTransOffset = 29;
	
	  ;% controller_template_DWork.isStable_hg
	  section.data(31).logicalSrcIdx = 174;
	  section.data(31).dtTransOffset = 30;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_pw
	  section.data(32).logicalSrcIdx = 175;
	  section.data(32).dtTransOffset = 31;
	
	  ;% controller_template_DWork.isStable_oj
	  section.data(33).logicalSrcIdx = 176;
	  section.data(33).dtTransOffset = 32;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_cz
	  section.data(34).logicalSrcIdx = 177;
	  section.data(34).dtTransOffset = 33;
	
	  ;% controller_template_DWork.isStable_n
	  section.data(35).logicalSrcIdx = 178;
	  section.data(35).dtTransOffset = 34;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_b
	  section.data(36).logicalSrcIdx = 179;
	  section.data(36).dtTransOffset = 35;
	
	  ;% controller_template_DWork.isStable_k
	  section.data(37).logicalSrcIdx = 180;
	  section.data(37).dtTransOffset = 36;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_d
	  section.data(38).logicalSrcIdx = 181;
	  section.data(38).dtTransOffset = 37;
	
	  ;% controller_template_DWork.isStable_b
	  section.data(39).logicalSrcIdx = 182;
	  section.data(39).dtTransOffset = 38;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_nz
	  section.data(40).logicalSrcIdx = 183;
	  section.data(40).dtTransOffset = 39;
	
	  ;% controller_template_DWork.isStable_hy
	  section.data(41).logicalSrcIdx = 184;
	  section.data(41).dtTransOffset = 40;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_f
	  section.data(42).logicalSrcIdx = 185;
	  section.data(42).dtTransOffset = 41;
	
	  ;% controller_template_DWork.isStable_l
	  section.data(43).logicalSrcIdx = 186;
	  section.data(43).dtTransOffset = 42;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_lo
	  section.data(44).logicalSrcIdx = 187;
	  section.data(44).dtTransOffset = 43;
	
	  ;% controller_template_DWork.isStable_ng
	  section.data(45).logicalSrcIdx = 188;
	  section.data(45).dtTransOffset = 44;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_dn
	  section.data(46).logicalSrcIdx = 189;
	  section.data(46).dtTransOffset = 45;
	
	  ;% controller_template_DWork.isStable_d
	  section.data(47).logicalSrcIdx = 190;
	  section.data(47).dtTransOffset = 46;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_hm
	  section.data(48).logicalSrcIdx = 191;
	  section.data(48).dtTransOffset = 47;
	
	  ;% controller_template_DWork.FreeFlightPosCtrl_MODE
	  section.data(49).logicalSrcIdx = 192;
	  section.data(49).dtTransOffset = 48;
	
	  ;% controller_template_DWork.poscontroller_MODE
	  section.data(50).logicalSrcIdx = 193;
	  section.data(50).dtTransOffset = 49;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_EmbeddedMATLABFunction_o.sfEvent
	  section.data(1).logicalSrcIdx = 194;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_EmbeddedMATLABFunction_o.is_active_c26_Hquad_control_LIB
	  section.data(1).logicalSrcIdx = 195;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(10) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_EmbeddedMATLABFunction_o.isStable
	  section.data(1).logicalSrcIdx = 196;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.sf_EmbeddedMATLABFunction_o.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 197;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(11) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_discretekalmanfilter_k.sfEvent
	  section.data(1).logicalSrcIdx = 198;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(12) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_discretekalmanfilter_k.is_active_c27_controller_templa
	  section.data(1).logicalSrcIdx = 199;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(13) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_discretekalmanfilter_k.isStable
	  section.data(1).logicalSrcIdx = 200;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.sf_discretekalmanfilter_k.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 201;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(14) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_discretekalmanfilter_n.sfEvent
	  section.data(1).logicalSrcIdx = 202;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(15) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_discretekalmanfilter_n.is_active_c27_controller_templa
	  section.data(1).logicalSrcIdx = 203;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(16) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_discretekalmanfilter_n.isStable
	  section.data(1).logicalSrcIdx = 204;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.sf_discretekalmanfilter_n.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 205;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(17) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_discretekalmanfilter_m.sfEvent
	  section.data(1).logicalSrcIdx = 206;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(18) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_discretekalmanfilter_m.is_active_c11_Hquad_control_LIB
	  section.data(1).logicalSrcIdx = 207;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(19) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_discretekalmanfilter_m.isStable
	  section.data(1).logicalSrcIdx = 208;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.sf_discretekalmanfilter_m.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 209;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(20) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_runFastGradient_d.sfEvent
	  section.data(1).logicalSrcIdx = 210;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(21) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_runFastGradient_d.is_active_c6_Hquad_control_LIB_
	  section.data(1).logicalSrcIdx = 211;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(22) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_runFastGradient_d.isStable
	  section.data(1).logicalSrcIdx = 212;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.sf_runFastGradient_d.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 213;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(23) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_discretekalmanfilter_b.sfEvent
	  section.data(1).logicalSrcIdx = 214;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(24) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_discretekalmanfilter_b.is_active_c11_Hquad_control_LIB
	  section.data(1).logicalSrcIdx = 215;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(25) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_discretekalmanfilter_b.isStable
	  section.data(1).logicalSrcIdx = 216;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.sf_discretekalmanfilter_b.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 217;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(26) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_runFastGradient.sfEvent
	  section.data(1).logicalSrcIdx = 218;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(27) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_runFastGradient.is_active_c6_Hquad_control_LIB_
	  section.data(1).logicalSrcIdx = 219;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(28) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_runFastGradient.isStable
	  section.data(1).logicalSrcIdx = 220;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.sf_runFastGradient.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 221;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(29) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_EmbeddedMATLABFunction.sfEvent
	  section.data(1).logicalSrcIdx = 222;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(30) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_EmbeddedMATLABFunction.is_active_c26_Hquad_control_LIB
	  section.data(1).logicalSrcIdx = 223;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(31) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_EmbeddedMATLABFunction.isStable
	  section.data(1).logicalSrcIdx = 224;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.sf_EmbeddedMATLABFunction.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 225;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(32) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_MATLABFunction_p.sfEvent
	  section.data(1).logicalSrcIdx = 226;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(33) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_MATLABFunction_p.is_active_c15_controller_templa
	  section.data(1).logicalSrcIdx = 227;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(34) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_MATLABFunction_p.isStable
	  section.data(1).logicalSrcIdx = 228;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.sf_MATLABFunction_p.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 229;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(35) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_generate_X_ref_z.sfEvent
	  section.data(1).logicalSrcIdx = 230;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(36) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_generate_X_ref_z.is_active_c22_controller_templa
	  section.data(1).logicalSrcIdx = 231;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(37) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_generate_X_ref_z.isStable
	  section.data(1).logicalSrcIdx = 232;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.sf_generate_X_ref_z.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 233;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(38) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_generate_X_ref_yaw.sfEvent
	  section.data(1).logicalSrcIdx = 234;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(39) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_generate_X_ref_yaw.is_active_c21_controller_templa
	  section.data(1).logicalSrcIdx = 235;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(40) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_generate_X_ref_yaw.isStable
	  section.data(1).logicalSrcIdx = 236;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.sf_generate_X_ref_yaw.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 237;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(41) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_generate_X_ref_y.sfEvent
	  section.data(1).logicalSrcIdx = 238;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(42) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_generate_X_ref_y.is_active_c20_controller_templa
	  section.data(1).logicalSrcIdx = 239;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(43) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_generate_X_ref_y.isStable
	  section.data(1).logicalSrcIdx = 240;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.sf_generate_X_ref_y.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 241;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(44) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_generate_X_ref_x.sfEvent
	  section.data(1).logicalSrcIdx = 242;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(45) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_generate_X_ref_x.is_active_c19_controller_templa
	  section.data(1).logicalSrcIdx = 243;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(46) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_generate_X_ref_x.isStable
	  section.data(1).logicalSrcIdx = 244;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.sf_generate_X_ref_x.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 245;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(47) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_MATLABFunction.sfEvent
	  section.data(1).logicalSrcIdx = 246;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(48) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_MATLABFunction.is_active_c15_controller_templa
	  section.data(1).logicalSrcIdx = 247;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(49) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_MATLABFunction.isStable
	  section.data(1).logicalSrcIdx = 248;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.sf_MATLABFunction.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 249;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(50) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_MATLABFunction_c.sfEvent
	  section.data(1).logicalSrcIdx = 250;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(51) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_MATLABFunction_c.is_active_c13_controller_templa
	  section.data(1).logicalSrcIdx = 251;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(52) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_MATLABFunction_c.isStable
	  section.data(1).logicalSrcIdx = 252;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.sf_MATLABFunction_c.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 253;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(53) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_discretekalmanfilter.sfEvent
	  section.data(1).logicalSrcIdx = 254;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(54) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_discretekalmanfilter.is_active_c27_controller_templa
	  section.data(1).logicalSrcIdx = 255;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(55) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_discretekalmanfilter.isStable
	  section.data(1).logicalSrcIdx = 256;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.sf_discretekalmanfilter.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 257;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(56) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_MATLABFunction_l5.sfEvent
	  section.data(1).logicalSrcIdx = 258;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(57) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_MATLABFunction_l5.is_active_c13_controller_templa
	  section.data(1).logicalSrcIdx = 259;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(58) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_MATLABFunction_l5.isStable
	  section.data(1).logicalSrcIdx = 260;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.sf_MATLABFunction_l5.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 261;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(59) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_MATLABFunction_e.sfEvent
	  section.data(1).logicalSrcIdx = 262;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(60) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_MATLABFunction_e.is_active_c15_controller_templa
	  section.data(1).logicalSrcIdx = 263;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(61) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_MATLABFunction_e.isStable
	  section.data(1).logicalSrcIdx = 264;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.sf_MATLABFunction_e.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 265;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(62) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_generate_X_ref_z_l.sfEvent
	  section.data(1).logicalSrcIdx = 266;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(63) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_generate_X_ref_z_l.is_active_c22_controller_templa
	  section.data(1).logicalSrcIdx = 267;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(64) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_generate_X_ref_z_l.isStable
	  section.data(1).logicalSrcIdx = 268;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.sf_generate_X_ref_z_l.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 269;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(65) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_generate_X_ref_yaw_g.sfEvent
	  section.data(1).logicalSrcIdx = 270;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(66) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_generate_X_ref_yaw_g.is_active_c21_controller_templa
	  section.data(1).logicalSrcIdx = 271;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(67) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_generate_X_ref_yaw_g.isStable
	  section.data(1).logicalSrcIdx = 272;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.sf_generate_X_ref_yaw_g.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 273;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(68) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_generate_X_ref_y_a.sfEvent
	  section.data(1).logicalSrcIdx = 274;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(69) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_generate_X_ref_y_a.is_active_c20_controller_templa
	  section.data(1).logicalSrcIdx = 275;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(70) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_generate_X_ref_y_a.isStable
	  section.data(1).logicalSrcIdx = 276;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.sf_generate_X_ref_y_a.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 277;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(71) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_generate_X_ref_x_k.sfEvent
	  section.data(1).logicalSrcIdx = 278;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(72) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_generate_X_ref_x_k.is_active_c19_controller_templa
	  section.data(1).logicalSrcIdx = 279;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(73) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_generate_X_ref_x_k.isStable
	  section.data(1).logicalSrcIdx = 280;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.sf_generate_X_ref_x_k.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 281;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(74) = section;
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


  targMap.checksum0 = 2797423045;
  targMap.checksum1 = 3798148326;
  targMap.checksum2 = 3623658429;
  targMap.checksum3 = 139371640;

