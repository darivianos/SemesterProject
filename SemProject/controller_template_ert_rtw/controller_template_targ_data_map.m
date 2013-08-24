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
      section.nData     = 383;
      section.data(383)  = dumData; %prealloc
      
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
	
	  ;% controller_template_P.A_Value
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 50;
	
	  ;% controller_template_P.B_Value
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 59;
	
	  ;% controller_template_P.C_Value
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 62;
	
	  ;% controller_template_P.D_Value
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 68;
	
	  ;% controller_template_P.Q_Value
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 70;
	
	  ;% controller_template_P.R_Value
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 79;
	
	  ;% controller_template_P.IntegerDelay3_InitialCondition
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 83;
	
	  ;% controller_template_P.UnitDelay1_X0
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 84;
	
	  ;% controller_template_P.FixPtUnitDelay1_X0
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 93;
	
	  ;% controller_template_P.Saturation_UpperSat
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 94;
	
	  ;% controller_template_P.Saturation_LowerSat
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 95;
	
	  ;% controller_template_P.Gain2_Gain
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 96;
	
	  ;% controller_template_P.UnitDelay1_X0_d
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 97;
	
	  ;% controller_template_P.UnitDelay2_X0
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 101;
	
	  ;% controller_template_P.Switch_Threshold
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 102;
	
	  ;% controller_template_P.Saturation_UpperSat_i
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 103;
	
	  ;% controller_template_P.Saturation_LowerSat_j
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 104;
	
	  ;% controller_template_P.Saturation1_UpperSat
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 105;
	
	  ;% controller_template_P.Saturation1_LowerSat
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 106;
	
	  ;% controller_template_P.Constant_Value_c
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 107;
	
	  ;% controller_template_P.SliderGain_Gain
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 108;
	
	  ;% controller_template_P.Constant1_Value_f
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 109;
	
	  ;% controller_template_P.SliderGain_Gain_b
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 110;
	
	  ;% controller_template_P.Saturation3_UpperSat_j
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 111;
	
	  ;% controller_template_P.Saturation3_LowerSat_l
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 112;
	
	  ;% controller_template_P.Saturation2_UpperSat
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 113;
	
	  ;% controller_template_P.Saturation2_LowerSat
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 114;
	
	  ;% controller_template_P.UnitDelay2_X0_g
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 115;
	
	  ;% controller_template_P.Saturation_UpperSat_p
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 116;
	
	  ;% controller_template_P.Saturation_LowerSat_c
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 117;
	
	  ;% controller_template_P.Saturation1_UpperSat_o
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 118;
	
	  ;% controller_template_P.Saturation1_LowerSat_d
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 119;
	
	  ;% controller_template_P.Saturation3_UpperSat_c
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 120;
	
	  ;% controller_template_P.Saturation3_LowerSat_k
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 121;
	
	  ;% controller_template_P.Saturation2_UpperSat_a
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 122;
	
	  ;% controller_template_P.Saturation2_LowerSat_h
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 123;
	
	  ;% controller_template_P.Constant_Value_l
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 124;
	
	  ;% controller_template_P.Constant1_Value_fy
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 9600;
	
	  ;% controller_template_P.Constant2_Value_m
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 11969;
	
	  ;% controller_template_P.Constat3_Value
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 13077;
	
	  ;% controller_template_P.Constant4_Value
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 13354;
	
	  ;% controller_template_P.Constant_Value_m
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 13631;
	
	  ;% controller_template_P.Constant1_Value_a
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 13647;
	
	  ;% controller_template_P.UnitDelay2_X0_b
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 13655;
	
	  ;% controller_template_P.Saturation_UpperSat_k
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 13656;
	
	  ;% controller_template_P.Saturation_LowerSat_e
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 13657;
	
	  ;% controller_template_P.Saturation1_UpperSat_p
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 13658;
	
	  ;% controller_template_P.Saturation1_LowerSat_l
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 13659;
	
	  ;% controller_template_P.Saturation3_UpperSat_l
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 13660;
	
	  ;% controller_template_P.Saturation3_LowerSat_lj
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 13661;
	
	  ;% controller_template_P.Saturation2_UpperSat_k
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 13662;
	
	  ;% controller_template_P.Saturation2_LowerSat_c
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 13663;
	
	  ;% controller_template_P.Constant5_Value
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 13664;
	
	  ;% controller_template_P.Constant6_Value
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 19324;
	
	  ;% controller_template_P.Constant7_Value
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 20739;
	
	  ;% controller_template_P.Constant8_Value
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 21395;
	
	  ;% controller_template_P.Constant9_Value
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 21559;
	
	  ;% controller_template_P.Saturation4_UpperSat
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 21723;
	
	  ;% controller_template_P.Saturation4_LowerSat
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 21724;
	
	  ;% controller_template_P.UnitDelay2_X0_m
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 21725;
	
	  ;% controller_template_P.UnitDelay_X0
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 21726;
	
	  ;% controller_template_P.Gain_Gain
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 21727;
	
	  ;% controller_template_P.Constant_Value_f
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 21728;
	
	  ;% controller_template_P.SliderGain_Gain_g
	  section.data(70).logicalSrcIdx = 69;
	  section.data(70).dtTransOffset = 21729;
	
	  ;% controller_template_P.SliderGain_Gain_ba
	  section.data(71).logicalSrcIdx = 70;
	  section.data(71).dtTransOffset = 21730;
	
	  ;% controller_template_P.Gain_Gain_j
	  section.data(72).logicalSrcIdx = 71;
	  section.data(72).dtTransOffset = 21731;
	
	  ;% controller_template_P.Constant1_Value_m
	  section.data(73).logicalSrcIdx = 72;
	  section.data(73).dtTransOffset = 21732;
	
	  ;% controller_template_P.SliderGain_Gain_k
	  section.data(74).logicalSrcIdx = 73;
	  section.data(74).dtTransOffset = 21733;
	
	  ;% controller_template_P.Gain1_Gain
	  section.data(75).logicalSrcIdx = 74;
	  section.data(75).dtTransOffset = 21734;
	
	  ;% controller_template_P.Constant2_Value_h
	  section.data(76).logicalSrcIdx = 75;
	  section.data(76).dtTransOffset = 21735;
	
	  ;% controller_template_P.SliderGain_Gain_f
	  section.data(77).logicalSrcIdx = 76;
	  section.data(77).dtTransOffset = 21736;
	
	  ;% controller_template_P.gravity_Value
	  section.data(78).logicalSrcIdx = 77;
	  section.data(78).dtTransOffset = 21737;
	
	  ;% controller_template_P.Constant1_Value_d
	  section.data(79).logicalSrcIdx = 78;
	  section.data(79).dtTransOffset = 21738;
	
	  ;% controller_template_P.SliderGain_Gain_j
	  section.data(80).logicalSrcIdx = 79;
	  section.data(80).dtTransOffset = 21739;
	
	  ;% controller_template_P.Gain_Gain_f
	  section.data(81).logicalSrcIdx = 80;
	  section.data(81).dtTransOffset = 21740;
	
	  ;% controller_template_P.Saturation_UpperSat_h
	  section.data(82).logicalSrcIdx = 81;
	  section.data(82).dtTransOffset = 21741;
	
	  ;% controller_template_P.Saturation_LowerSat_d
	  section.data(83).logicalSrcIdx = 82;
	  section.data(83).dtTransOffset = 21742;
	
	  ;% controller_template_P.Saturation1_UpperSat_ou
	  section.data(84).logicalSrcIdx = 83;
	  section.data(84).dtTransOffset = 21743;
	
	  ;% controller_template_P.Saturation1_LowerSat_c
	  section.data(85).logicalSrcIdx = 84;
	  section.data(85).dtTransOffset = 21744;
	
	  ;% controller_template_P.SliderGain_Gain_gm
	  section.data(86).logicalSrcIdx = 85;
	  section.data(86).dtTransOffset = 21745;
	
	  ;% controller_template_P.Constant_Value_g
	  section.data(87).logicalSrcIdx = 86;
	  section.data(87).dtTransOffset = 21746;
	
	  ;% controller_template_P.SliderGain_Gain_be
	  section.data(88).logicalSrcIdx = 87;
	  section.data(88).dtTransOffset = 21747;
	
	  ;% controller_template_P.Saturation3_UpperSat_n
	  section.data(89).logicalSrcIdx = 88;
	  section.data(89).dtTransOffset = 21748;
	
	  ;% controller_template_P.Saturation3_LowerSat_c
	  section.data(90).logicalSrcIdx = 89;
	  section.data(90).dtTransOffset = 21749;
	
	  ;% controller_template_P.Saturation2_UpperSat_b
	  section.data(91).logicalSrcIdx = 90;
	  section.data(91).dtTransOffset = 21750;
	
	  ;% controller_template_P.Saturation2_LowerSat_hu
	  section.data(92).logicalSrcIdx = 91;
	  section.data(92).dtTransOffset = 21751;
	
	  ;% controller_template_P.Constant_Value_k
	  section.data(93).logicalSrcIdx = 92;
	  section.data(93).dtTransOffset = 21752;
	
	  ;% controller_template_P.SliderGain_Gain_p
	  section.data(94).logicalSrcIdx = 93;
	  section.data(94).dtTransOffset = 21753;
	
	  ;% controller_template_P.Constant1_Value_dx
	  section.data(95).logicalSrcIdx = 94;
	  section.data(95).dtTransOffset = 21754;
	
	  ;% controller_template_P.SliderGain_Gain_g3
	  section.data(96).logicalSrcIdx = 95;
	  section.data(96).dtTransOffset = 21755;
	
	  ;% controller_template_P.Saturation3_UpperSat_lg
	  section.data(97).logicalSrcIdx = 96;
	  section.data(97).dtTransOffset = 21756;
	
	  ;% controller_template_P.Saturation3_LowerSat_b
	  section.data(98).logicalSrcIdx = 97;
	  section.data(98).dtTransOffset = 21757;
	
	  ;% controller_template_P.Constant_Value_co
	  section.data(99).logicalSrcIdx = 98;
	  section.data(99).dtTransOffset = 21758;
	
	  ;% controller_template_P.Constant1_Value_g
	  section.data(100).logicalSrcIdx = 99;
	  section.data(100).dtTransOffset = 21783;
	
	  ;% controller_template_P.UnitDelay2_X0_d
	  section.data(101).logicalSrcIdx = 100;
	  section.data(101).dtTransOffset = 21793;
	
	  ;% controller_template_P.Constant_Value_ln
	  section.data(102).logicalSrcIdx = 101;
	  section.data(102).dtTransOffset = 21794;
	
	  ;% controller_template_P.Constant1_Value_j
	  section.data(103).logicalSrcIdx = 102;
	  section.data(103).dtTransOffset = 38599;
	
	  ;% controller_template_P.Constant2_Value_j
	  section.data(104).logicalSrcIdx = 103;
	  section.data(104).dtTransOffset = 41960;
	
	  ;% controller_template_P.Constant3_Value_o
	  section.data(105).logicalSrcIdx = 104;
	  section.data(105).dtTransOffset = 43550;
	
	  ;% controller_template_P.Constant4_Value_g
	  section.data(106).logicalSrcIdx = 105;
	  section.data(106).dtTransOffset = 43868;
	
	  ;% controller_template_P.Constant_Value_o
	  section.data(107).logicalSrcIdx = 106;
	  section.data(107).dtTransOffset = 44186;
	
	  ;% controller_template_P.SliderGain_Gain_m
	  section.data(108).logicalSrcIdx = 107;
	  section.data(108).dtTransOffset = 44187;
	
	  ;% controller_template_P.Saturation4_UpperSat_i
	  section.data(109).logicalSrcIdx = 108;
	  section.data(109).dtTransOffset = 44188;
	
	  ;% controller_template_P.Saturation4_LowerSat_h
	  section.data(110).logicalSrcIdx = 109;
	  section.data(110).dtTransOffset = 44189;
	
	  ;% controller_template_P.UnitDelay2_X0_n
	  section.data(111).logicalSrcIdx = 110;
	  section.data(111).dtTransOffset = 44190;
	
	  ;% controller_template_P.UnitDelay_X0_f
	  section.data(112).logicalSrcIdx = 111;
	  section.data(112).dtTransOffset = 44191;
	
	  ;% controller_template_P.Gain_Gain_fn
	  section.data(113).logicalSrcIdx = 112;
	  section.data(113).dtTransOffset = 44192;
	
	  ;% controller_template_P.Saturation1_UpperSat_d
	  section.data(114).logicalSrcIdx = 113;
	  section.data(114).dtTransOffset = 44193;
	
	  ;% controller_template_P.Saturation1_LowerSat_n
	  section.data(115).logicalSrcIdx = 114;
	  section.data(115).dtTransOffset = 44194;
	
	  ;% controller_template_P.Saturation_UpperSat_d
	  section.data(116).logicalSrcIdx = 115;
	  section.data(116).dtTransOffset = 44195;
	
	  ;% controller_template_P.Saturation_LowerSat_b
	  section.data(117).logicalSrcIdx = 116;
	  section.data(117).dtTransOffset = 44196;
	
	  ;% controller_template_P.Constant_Value_fz
	  section.data(118).logicalSrcIdx = 117;
	  section.data(118).dtTransOffset = 44197;
	
	  ;% controller_template_P.SliderGain_Gain_d
	  section.data(119).logicalSrcIdx = 118;
	  section.data(119).dtTransOffset = 44198;
	
	  ;% controller_template_P.Constant1_Value_l
	  section.data(120).logicalSrcIdx = 119;
	  section.data(120).dtTransOffset = 44199;
	
	  ;% controller_template_P.SliderGain_Gain_ds
	  section.data(121).logicalSrcIdx = 120;
	  section.data(121).dtTransOffset = 44200;
	
	  ;% controller_template_P.Saturation3_UpperSat_nh
	  section.data(122).logicalSrcIdx = 121;
	  section.data(122).dtTransOffset = 44201;
	
	  ;% controller_template_P.Saturation3_LowerSat_e
	  section.data(123).logicalSrcIdx = 122;
	  section.data(123).dtTransOffset = 44202;
	
	  ;% controller_template_P.Constant_Value_b
	  section.data(124).logicalSrcIdx = 123;
	  section.data(124).dtTransOffset = 44203;
	
	  ;% controller_template_P.Constant1_Value_li
	  section.data(125).logicalSrcIdx = 124;
	  section.data(125).dtTransOffset = 44827;
	
	  ;% controller_template_P.Constant2_Value_g
	  section.data(126).logicalSrcIdx = 125;
	  section.data(126).dtTransOffset = 45035;
	
	  ;% controller_template_P.Constant3_Value_m
	  section.data(127).logicalSrcIdx = 126;
	  section.data(127).dtTransOffset = 45125;
	
	  ;% controller_template_P.Constant4_Value_a
	  section.data(128).logicalSrcIdx = 127;
	  section.data(128).dtTransOffset = 45155;
	
	  ;% controller_template_P.Constant_Value_n
	  section.data(129).logicalSrcIdx = 128;
	  section.data(129).dtTransOffset = 45185;
	
	  ;% controller_template_P.SliderGain_Gain_mb
	  section.data(130).logicalSrcIdx = 129;
	  section.data(130).dtTransOffset = 45186;
	
	  ;% controller_template_P.SliderGain_Gain_c
	  section.data(131).logicalSrcIdx = 130;
	  section.data(131).dtTransOffset = 45187;
	
	  ;% controller_template_P.Saturation2_UpperSat_kw
	  section.data(132).logicalSrcIdx = 131;
	  section.data(132).dtTransOffset = 45188;
	
	  ;% controller_template_P.Saturation2_LowerSat_j
	  section.data(133).logicalSrcIdx = 132;
	  section.data(133).dtTransOffset = 45189;
	
	  ;% controller_template_P.UnitDelay2_X0_o
	  section.data(134).logicalSrcIdx = 133;
	  section.data(134).dtTransOffset = 45190;
	
	  ;% controller_template_P.UnitDelay_X0_i
	  section.data(135).logicalSrcIdx = 134;
	  section.data(135).dtTransOffset = 45191;
	
	  ;% controller_template_P.Gain_Gain_p
	  section.data(136).logicalSrcIdx = 135;
	  section.data(136).dtTransOffset = 45192;
	
	  ;% controller_template_P.UnitDelay_X0_m
	  section.data(137).logicalSrcIdx = 136;
	  section.data(137).dtTransOffset = 45193;
	
	  ;% controller_template_P.Constant1_Value_k
	  section.data(138).logicalSrcIdx = 137;
	  section.data(138).dtTransOffset = 45194;
	
	  ;% controller_template_P.SliderGain_Gain_a
	  section.data(139).logicalSrcIdx = 138;
	  section.data(139).dtTransOffset = 45195;
	
	  ;% controller_template_P.Constant2_Value_l
	  section.data(140).logicalSrcIdx = 139;
	  section.data(140).dtTransOffset = 45196;
	
	  ;% controller_template_P.SliderGain_Gain_pq
	  section.data(141).logicalSrcIdx = 140;
	  section.data(141).dtTransOffset = 45197;
	
	  ;% controller_template_P.SliderGain_Gain_ai
	  section.data(142).logicalSrcIdx = 141;
	  section.data(142).dtTransOffset = 45198;
	
	  ;% controller_template_P.Constant_Value_fv
	  section.data(143).logicalSrcIdx = 142;
	  section.data(143).dtTransOffset = 45199;
	
	  ;% controller_template_P.SliderGain_Gain_jt
	  section.data(144).logicalSrcIdx = 143;
	  section.data(144).dtTransOffset = 45200;
	
	  ;% controller_template_P.Saturation_UpperSat_o
	  section.data(145).logicalSrcIdx = 144;
	  section.data(145).dtTransOffset = 45201;
	
	  ;% controller_template_P.Saturation_LowerSat_p
	  section.data(146).logicalSrcIdx = 145;
	  section.data(146).dtTransOffset = 45202;
	
	  ;% controller_template_P.Constant_Value_h
	  section.data(147).logicalSrcIdx = 146;
	  section.data(147).dtTransOffset = 45203;
	
	  ;% controller_template_P.Constant1_Value_m3
	  section.data(148).logicalSrcIdx = 147;
	  section.data(148).dtTransOffset = 45204;
	
	  ;% controller_template_P.UnitDelay2_X0_ng
	  section.data(149).logicalSrcIdx = 148;
	  section.data(149).dtTransOffset = 45205;
	
	  ;% controller_template_P.Constant_Value_a
	  section.data(150).logicalSrcIdx = 149;
	  section.data(150).dtTransOffset = 45206;
	
	  ;% controller_template_P.Constant1_Value_gs
	  section.data(151).logicalSrcIdx = 150;
	  section.data(151).dtTransOffset = 45212;
	
	  ;% controller_template_P.Constant2_Value_jq
	  section.data(152).logicalSrcIdx = 151;
	  section.data(152).dtTransOffset = 45218;
	
	  ;% controller_template_P.Constant3_Value_b
	  section.data(153).logicalSrcIdx = 152;
	  section.data(153).dtTransOffset = 45221;
	
	  ;% controller_template_P.Constant4_Value_gb
	  section.data(154).logicalSrcIdx = 153;
	  section.data(154).dtTransOffset = 45224;
	
	  ;% controller_template_P.Saturation1_UpperSat_g
	  section.data(155).logicalSrcIdx = 154;
	  section.data(155).dtTransOffset = 45227;
	
	  ;% controller_template_P.Saturation1_LowerSat_b
	  section.data(156).logicalSrcIdx = 155;
	  section.data(156).dtTransOffset = 45228;
	
	  ;% controller_template_P.UnitDelay2_X0_i
	  section.data(157).logicalSrcIdx = 156;
	  section.data(157).dtTransOffset = 45229;
	
	  ;% controller_template_P.UnitDelay_X0_c
	  section.data(158).logicalSrcIdx = 157;
	  section.data(158).dtTransOffset = 45230;
	
	  ;% controller_template_P.Gain_Gain_p0
	  section.data(159).logicalSrcIdx = 158;
	  section.data(159).dtTransOffset = 45231;
	
	  ;% controller_template_P.UnitDelay1_X0_i
	  section.data(160).logicalSrcIdx = 159;
	  section.data(160).dtTransOffset = 45232;
	
	  ;% controller_template_P.UnitDelay_X0_d
	  section.data(161).logicalSrcIdx = 160;
	  section.data(161).dtTransOffset = 45233;
	
	  ;% controller_template_P.Constant_Value_d
	  section.data(162).logicalSrcIdx = 161;
	  section.data(162).dtTransOffset = 45234;
	
	  ;% controller_template_P.SliderGain_Gain_mg
	  section.data(163).logicalSrcIdx = 162;
	  section.data(163).dtTransOffset = 45235;
	
	  ;% controller_template_P.Constant_Value_p
	  section.data(164).logicalSrcIdx = 163;
	  section.data(164).dtTransOffset = 45236;
	
	  ;% controller_template_P.Constant1_Value_l0
	  section.data(165).logicalSrcIdx = 164;
	  section.data(165).dtTransOffset = 45252;
	
	  ;% controller_template_P.Constant2_Value_gl
	  section.data(166).logicalSrcIdx = 165;
	  section.data(166).dtTransOffset = 45256;
	
	  ;% controller_template_P.UnitDelay_X0_a
	  section.data(167).logicalSrcIdx = 166;
	  section.data(167).dtTransOffset = 45272;
	
	  ;% controller_template_P.UnitDelay1_X0_ic
	  section.data(168).logicalSrcIdx = 167;
	  section.data(168).dtTransOffset = 45276;
	
	  ;% controller_template_P.Constant3_Value_h
	  section.data(169).logicalSrcIdx = 168;
	  section.data(169).dtTransOffset = 45292;
	
	  ;% controller_template_P.Constant4_Value_n
	  section.data(170).logicalSrcIdx = 169;
	  section.data(170).dtTransOffset = 45308;
	
	  ;% controller_template_P.UnitDelay_X0_if
	  section.data(171).logicalSrcIdx = 170;
	  section.data(171).dtTransOffset = 45324;
	
	  ;% controller_template_P.UnitDelay1_X0_dy
	  section.data(172).logicalSrcIdx = 171;
	  section.data(172).dtTransOffset = 45325;
	
	  ;% controller_template_P.Gain_Gain_b
	  section.data(173).logicalSrcIdx = 172;
	  section.data(173).dtTransOffset = 45326;
	
	  ;% controller_template_P.UnitDelay1_X0_j
	  section.data(174).logicalSrcIdx = 173;
	  section.data(174).dtTransOffset = 45327;
	
	  ;% controller_template_P.Gain1_Gain_e
	  section.data(175).logicalSrcIdx = 174;
	  section.data(175).dtTransOffset = 45328;
	
	  ;% controller_template_P.Gain_Gain_e
	  section.data(176).logicalSrcIdx = 175;
	  section.data(176).dtTransOffset = 45329;
	
	  ;% controller_template_P.UnitDelay1_X0_f
	  section.data(177).logicalSrcIdx = 176;
	  section.data(177).dtTransOffset = 45330;
	
	  ;% controller_template_P.g_Value
	  section.data(178).logicalSrcIdx = 177;
	  section.data(178).dtTransOffset = 45331;
	
	  ;% controller_template_P.Constant_Value_ks
	  section.data(179).logicalSrcIdx = 178;
	  section.data(179).dtTransOffset = 45332;
	
	  ;% controller_template_P.SliderGain_Gain_n
	  section.data(180).logicalSrcIdx = 179;
	  section.data(180).dtTransOffset = 45333;
	
	  ;% controller_template_P.Constant1_Value_i
	  section.data(181).logicalSrcIdx = 180;
	  section.data(181).dtTransOffset = 45334;
	
	  ;% controller_template_P.SliderGain_Gain_i
	  section.data(182).logicalSrcIdx = 181;
	  section.data(182).dtTransOffset = 45335;
	
	  ;% controller_template_P.Saturation3_UpperSat_p
	  section.data(183).logicalSrcIdx = 182;
	  section.data(183).dtTransOffset = 45336;
	
	  ;% controller_template_P.Saturation3_LowerSat_es
	  section.data(184).logicalSrcIdx = 183;
	  section.data(184).dtTransOffset = 45337;
	
	  ;% controller_template_P.X_ref_x_Value
	  section.data(185).logicalSrcIdx = 184;
	  section.data(185).dtTransOffset = 45338;
	
	  ;% controller_template_P.Constant_Value_i
	  section.data(186).logicalSrcIdx = 185;
	  section.data(186).dtTransOffset = 46247;
	
	  ;% controller_template_P.SliderGain_Gain_e
	  section.data(187).logicalSrcIdx = 186;
	  section.data(187).dtTransOffset = 46248;
	
	  ;% controller_template_P.Constant1_Value_e
	  section.data(188).logicalSrcIdx = 187;
	  section.data(188).dtTransOffset = 46249;
	
	  ;% controller_template_P.SliderGain_Gain_jr
	  section.data(189).logicalSrcIdx = 188;
	  section.data(189).dtTransOffset = 46250;
	
	  ;% controller_template_P.Saturation3_UpperSat_f
	  section.data(190).logicalSrcIdx = 189;
	  section.data(190).dtTransOffset = 46251;
	
	  ;% controller_template_P.Saturation3_LowerSat_lw
	  section.data(191).logicalSrcIdx = 190;
	  section.data(191).dtTransOffset = 46252;
	
	  ;% controller_template_P.UnitDelay_2_X0
	  section.data(192).logicalSrcIdx = 191;
	  section.data(192).dtTransOffset = 46253;
	
	  ;% controller_template_P.UnitDelay_3_X0
	  section.data(193).logicalSrcIdx = 192;
	  section.data(193).dtTransOffset = 46254;
	
	  ;% controller_template_P.Constant1_Value_j2
	  section.data(194).logicalSrcIdx = 193;
	  section.data(194).dtTransOffset = 46255;
	
	  ;% controller_template_P.SliderGain_Gain_db
	  section.data(195).logicalSrcIdx = 194;
	  section.data(195).dtTransOffset = 46256;
	
	  ;% controller_template_P.Constant_Value_le
	  section.data(196).logicalSrcIdx = 195;
	  section.data(196).dtTransOffset = 46257;
	
	  ;% controller_template_P.SliderGain_Gain_ne
	  section.data(197).logicalSrcIdx = 196;
	  section.data(197).dtTransOffset = 46258;
	
	  ;% controller_template_P.Constant_Value_kb
	  section.data(198).logicalSrcIdx = 197;
	  section.data(198).dtTransOffset = 46259;
	
	  ;% controller_template_P.SliderGain_Gain_dsh
	  section.data(199).logicalSrcIdx = 198;
	  section.data(199).dtTransOffset = 46260;
	
	  ;% controller_template_P.SliderGain_Gain_cx
	  section.data(200).logicalSrcIdx = 199;
	  section.data(200).dtTransOffset = 46261;
	
	  ;% controller_template_P.Constant1_Value_kj
	  section.data(201).logicalSrcIdx = 200;
	  section.data(201).dtTransOffset = 46262;
	
	  ;% controller_template_P.SliderGain_Gain_mi
	  section.data(202).logicalSrcIdx = 201;
	  section.data(202).dtTransOffset = 46263;
	
	  ;% controller_template_P.Constant2_Value_c
	  section.data(203).logicalSrcIdx = 202;
	  section.data(203).dtTransOffset = 46264;
	
	  ;% controller_template_P.SliderGain_Gain_nu
	  section.data(204).logicalSrcIdx = 203;
	  section.data(204).dtTransOffset = 46265;
	
	  ;% controller_template_P.Constant3_Value_f
	  section.data(205).logicalSrcIdx = 204;
	  section.data(205).dtTransOffset = 46266;
	
	  ;% controller_template_P.SliderGain_Gain_ka
	  section.data(206).logicalSrcIdx = 205;
	  section.data(206).dtTransOffset = 46267;
	
	  ;% controller_template_P.Switch1_Threshold
	  section.data(207).logicalSrcIdx = 206;
	  section.data(207).dtTransOffset = 46268;
	
	  ;% controller_template_P.Switch_Threshold_f
	  section.data(208).logicalSrcIdx = 207;
	  section.data(208).dtTransOffset = 46269;
	
	  ;% controller_template_P.SliderGain_Gain_h
	  section.data(209).logicalSrcIdx = 208;
	  section.data(209).dtTransOffset = 46270;
	
	  ;% controller_template_P.TotalSamples_Value
	  section.data(210).logicalSrcIdx = 209;
	  section.data(210).dtTransOffset = 46271;
	
	  ;% controller_template_P.UnitDelay1_X0_ie
	  section.data(211).logicalSrcIdx = 210;
	  section.data(211).dtTransOffset = 46272;
	
	  ;% controller_template_P.UnitDelay_X0_o
	  section.data(212).logicalSrcIdx = 211;
	  section.data(212).dtTransOffset = 46273;
	
	  ;% controller_template_P.total_samples_Value
	  section.data(213).logicalSrcIdx = 212;
	  section.data(213).dtTransOffset = 46274;
	
	  ;% controller_template_P.Constant1_Value_mu
	  section.data(214).logicalSrcIdx = 213;
	  section.data(214).dtTransOffset = 46275;
	
	  ;% controller_template_P.X_ref_x_Value_n
	  section.data(215).logicalSrcIdx = 214;
	  section.data(215).dtTransOffset = 46276;
	
	  ;% controller_template_P.Constant_Value_lw
	  section.data(216).logicalSrcIdx = 215;
	  section.data(216).dtTransOffset = 47185;
	
	  ;% controller_template_P.UnitDelay_X0_e
	  section.data(217).logicalSrcIdx = 216;
	  section.data(217).dtTransOffset = 47186;
	
	  ;% controller_template_P.total_samples_Value_h
	  section.data(218).logicalSrcIdx = 217;
	  section.data(218).dtTransOffset = 47187;
	
	  ;% controller_template_P.Constant1_Value_o
	  section.data(219).logicalSrcIdx = 218;
	  section.data(219).dtTransOffset = 47188;
	
	  ;% controller_template_P.X_ref_y_Value
	  section.data(220).logicalSrcIdx = 219;
	  section.data(220).dtTransOffset = 47189;
	
	  ;% controller_template_P.X_ref_y_Value_f
	  section.data(221).logicalSrcIdx = 220;
	  section.data(221).dtTransOffset = 48098;
	
	  ;% controller_template_P.X_ref_z_Value
	  section.data(222).logicalSrcIdx = 221;
	  section.data(222).dtTransOffset = 49007;
	
	  ;% controller_template_P.X_ref_z_Value_p
	  section.data(223).logicalSrcIdx = 222;
	  section.data(223).dtTransOffset = 49613;
	
	  ;% controller_template_P.X_ref_yaw_Value
	  section.data(224).logicalSrcIdx = 223;
	  section.data(224).dtTransOffset = 50219;
	
	  ;% controller_template_P.X_ref_yaw_Value_i
	  section.data(225).logicalSrcIdx = 224;
	  section.data(225).dtTransOffset = 50825;
	
	  ;% controller_template_P.Gain_Gain_m
	  section.data(226).logicalSrcIdx = 225;
	  section.data(226).dtTransOffset = 51431;
	
	  ;% controller_template_P.Gain_Gain_a
	  section.data(227).logicalSrcIdx = 226;
	  section.data(227).dtTransOffset = 51432;
	
	  ;% controller_template_P.raddeg2_Gain
	  section.data(228).logicalSrcIdx = 227;
	  section.data(228).dtTransOffset = 51433;
	
	  ;% controller_template_P.raddeg1_Gain
	  section.data(229).logicalSrcIdx = 228;
	  section.data(229).dtTransOffset = 51434;
	
	  ;% controller_template_P.raddeg3_Gain
	  section.data(230).logicalSrcIdx = 229;
	  section.data(230).dtTransOffset = 51435;
	
	  ;% controller_template_P.raddeg_Gain
	  section.data(231).logicalSrcIdx = 230;
	  section.data(231).dtTransOffset = 51436;
	
	  ;% controller_template_P.Constant_Value_kh
	  section.data(232).logicalSrcIdx = 231;
	  section.data(232).dtTransOffset = 51437;
	
	  ;% controller_template_P.Constant1_Value_h
	  section.data(233).logicalSrcIdx = 232;
	  section.data(233).dtTransOffset = 51438;
	
	  ;% controller_template_P.UnitDelay_X0_b
	  section.data(234).logicalSrcIdx = 233;
	  section.data(234).dtTransOffset = 51439;
	
	  ;% controller_template_P.total_samples_Value_k
	  section.data(235).logicalSrcIdx = 234;
	  section.data(235).dtTransOffset = 51440;
	
	  ;% controller_template_P.X_ref_x_Value_k
	  section.data(236).logicalSrcIdx = 235;
	  section.data(236).dtTransOffset = 51441;
	
	  ;% controller_template_P.X_ref_y_Value_e
	  section.data(237).logicalSrcIdx = 236;
	  section.data(237).dtTransOffset = 52350;
	
	  ;% controller_template_P.X_ref_yaw_Value_f
	  section.data(238).logicalSrcIdx = 237;
	  section.data(238).dtTransOffset = 53259;
	
	  ;% controller_template_P.X_ref_z_Value_a
	  section.data(239).logicalSrcIdx = 238;
	  section.data(239).dtTransOffset = 53865;
	
	  ;% controller_template_P.Gain_Gain_d
	  section.data(240).logicalSrcIdx = 239;
	  section.data(240).dtTransOffset = 54471;
	
	  ;% controller_template_P.UnitDelay_X0_l
	  section.data(241).logicalSrcIdx = 240;
	  section.data(241).dtTransOffset = 54472;
	
	  ;% controller_template_P.UnitDelay1_X0_js
	  section.data(242).logicalSrcIdx = 241;
	  section.data(242).dtTransOffset = 54473;
	
	  ;% controller_template_P.yaw_rate_bias_Value
	  section.data(243).logicalSrcIdx = 242;
	  section.data(243).dtTransOffset = 54474;
	
	  ;% controller_template_P.thrust_bias_Value
	  section.data(244).logicalSrcIdx = 243;
	  section.data(244).dtTransOffset = 54475;
	
	  ;% controller_template_P.roll_bias_Value
	  section.data(245).logicalSrcIdx = 244;
	  section.data(245).dtTransOffset = 54476;
	
	  ;% controller_template_P.pitch_bias_Value
	  section.data(246).logicalSrcIdx = 245;
	  section.data(246).dtTransOffset = 54477;
	
	  ;% controller_template_P.yaw_Value
	  section.data(247).logicalSrcIdx = 246;
	  section.data(247).dtTransOffset = 54478;
	
	  ;% controller_template_P.gravity_Value_c
	  section.data(248).logicalSrcIdx = 247;
	  section.data(248).dtTransOffset = 54479;
	
	  ;% controller_template_P.roll_Value
	  section.data(249).logicalSrcIdx = 248;
	  section.data(249).dtTransOffset = 54480;
	
	  ;% controller_template_P.pitch_Value
	  section.data(250).logicalSrcIdx = 249;
	  section.data(250).dtTransOffset = 54481;
	
	  ;% controller_template_P.yaw_rate_Value
	  section.data(251).logicalSrcIdx = 250;
	  section.data(251).dtTransOffset = 54482;
	
	  ;% controller_template_P.yaw_cmd2yaw_Gain
	  section.data(252).logicalSrcIdx = 251;
	  section.data(252).dtTransOffset = 54483;
	
	  ;% controller_template_P.IntegerDelay_InitialCondition
	  section.data(253).logicalSrcIdx = 252;
	  section.data(253).dtTransOffset = 54484;
	
	  ;% controller_template_P.IntegerDelay1_InitialCondition
	  section.data(254).logicalSrcIdx = 253;
	  section.data(254).dtTransOffset = 54485;
	
	  ;% controller_template_P.IntegerDelay2_InitialCondition
	  section.data(255).logicalSrcIdx = 254;
	  section.data(255).dtTransOffset = 54486;
	
	  ;% controller_template_P.IntegerDelay3_InitialConditio_c
	  section.data(256).logicalSrcIdx = 255;
	  section.data(256).dtTransOffset = 54487;
	
	  ;% controller_template_P.gravity_Value_j
	  section.data(257).logicalSrcIdx = 256;
	  section.data(257).dtTransOffset = 54488;
	
	  ;% controller_template_P.TT_PP_Value
	  section.data(258).logicalSrcIdx = 257;
	  section.data(258).dtTransOffset = 54489;
	
	  ;% controller_template_P.LL_PP_Value
	  section.data(259).logicalSrcIdx = 258;
	  section.data(259).dtTransOffset = 55389;
	
	  ;% controller_template_P.LL_ref_PP_Value
	  section.data(260).logicalSrcIdx = 259;
	  section.data(260).dtTransOffset = 55479;
	
	  ;% controller_template_P.LL_U_ref_PP_Value
	  section.data(261).logicalSrcIdx = 260;
	  section.data(261).dtTransOffset = 58269;
	
	  ;% controller_template_P.MM_Value
	  section.data(262).logicalSrcIdx = 261;
	  section.data(262).dtTransOffset = 59169;
	
	  ;% controller_template_P.PP_Value
	  section.data(263).logicalSrcIdx = 262;
	  section.data(263).dtTransOffset = 59178;
	
	  ;% controller_template_P.AA_delay_Value
	  section.data(264).logicalSrcIdx = 263;
	  section.data(264).dtTransOffset = 60078;
	
	  ;% controller_template_P.BB_delay_Value
	  section.data(265).logicalSrcIdx = 264;
	  section.data(265).dtTransOffset = 60087;
	
	  ;% controller_template_P.A_Value_h
	  section.data(266).logicalSrcIdx = 265;
	  section.data(266).dtTransOffset = 60096;
	
	  ;% controller_template_P.B_Value_i
	  section.data(267).logicalSrcIdx = 266;
	  section.data(267).dtTransOffset = 60112;
	
	  ;% controller_template_P.C_Value_c
	  section.data(268).logicalSrcIdx = 267;
	  section.data(268).dtTransOffset = 60116;
	
	  ;% controller_template_P.D_Value_l
	  section.data(269).logicalSrcIdx = 268;
	  section.data(269).dtTransOffset = 60128;
	
	  ;% controller_template_P.Q_Value_a
	  section.data(270).logicalSrcIdx = 269;
	  section.data(270).dtTransOffset = 60131;
	
	  ;% controller_template_P.R_Value_c
	  section.data(271).logicalSrcIdx = 270;
	  section.data(271).dtTransOffset = 60147;
	
	  ;% controller_template_P.UnitDelay1_X0_c
	  section.data(272).logicalSrcIdx = 271;
	  section.data(272).dtTransOffset = 60156;
	
	  ;% controller_template_P.FixPtUnitDelay1_X0_f
	  section.data(273).logicalSrcIdx = 272;
	  section.data(273).dtTransOffset = 60172;
	
	  ;% controller_template_P.V_max_Value
	  section.data(274).logicalSrcIdx = 273;
	  section.data(274).dtTransOffset = 60173;
	
	  ;% controller_template_P.i_min_Value
	  section.data(275).logicalSrcIdx = 274;
	  section.data(275).dtTransOffset = 60203;
	
	  ;% controller_template_P.betas_Value
	  section.data(276).logicalSrcIdx = 275;
	  section.data(276).dtTransOffset = 60204;
	
	  ;% controller_template_P.L_Value
	  section.data(277).logicalSrcIdx = 276;
	  section.data(277).dtTransOffset = 60211;
	
	  ;% controller_template_P.UnitDelay_X0_fc
	  section.data(278).logicalSrcIdx = 277;
	  section.data(278).dtTransOffset = 60212;
	
	  ;% controller_template_P.UnitDelay1_X0_k
	  section.data(279).logicalSrcIdx = 278;
	  section.data(279).dtTransOffset = 60215;
	
	  ;% controller_template_P.Saturation_UpperSat_ia
	  section.data(280).logicalSrcIdx = 279;
	  section.data(280).dtTransOffset = 60245;
	
	  ;% controller_template_P.Saturation_LowerSat_o
	  section.data(281).logicalSrcIdx = 280;
	  section.data(281).dtTransOffset = 60246;
	
	  ;% controller_template_P.TT_PP_Value_m
	  section.data(282).logicalSrcIdx = 281;
	  section.data(282).dtTransOffset = 60247;
	
	  ;% controller_template_P.LL_PP_Value_e
	  section.data(283).logicalSrcIdx = 282;
	  section.data(283).dtTransOffset = 61147;
	
	  ;% controller_template_P.LL_ref_PP_Value_l
	  section.data(284).logicalSrcIdx = 283;
	  section.data(284).dtTransOffset = 61237;
	
	  ;% controller_template_P.LL_U_ref_PP_Value_m
	  section.data(285).logicalSrcIdx = 284;
	  section.data(285).dtTransOffset = 64027;
	
	  ;% controller_template_P.MM_Value_c
	  section.data(286).logicalSrcIdx = 285;
	  section.data(286).dtTransOffset = 64927;
	
	  ;% controller_template_P.PP_Value_m
	  section.data(287).logicalSrcIdx = 286;
	  section.data(287).dtTransOffset = 64936;
	
	  ;% controller_template_P.AA_delay_Value_h
	  section.data(288).logicalSrcIdx = 287;
	  section.data(288).dtTransOffset = 65836;
	
	  ;% controller_template_P.BB_delay_Value_o
	  section.data(289).logicalSrcIdx = 288;
	  section.data(289).dtTransOffset = 65845;
	
	  ;% controller_template_P.A_Value_n
	  section.data(290).logicalSrcIdx = 289;
	  section.data(290).dtTransOffset = 65854;
	
	  ;% controller_template_P.B_Value_h
	  section.data(291).logicalSrcIdx = 290;
	  section.data(291).dtTransOffset = 65870;
	
	  ;% controller_template_P.C_Value_p
	  section.data(292).logicalSrcIdx = 291;
	  section.data(292).dtTransOffset = 65874;
	
	  ;% controller_template_P.D_Value_m
	  section.data(293).logicalSrcIdx = 292;
	  section.data(293).dtTransOffset = 65886;
	
	  ;% controller_template_P.Q_Value_h
	  section.data(294).logicalSrcIdx = 293;
	  section.data(294).dtTransOffset = 65889;
	
	  ;% controller_template_P.R_Value_l
	  section.data(295).logicalSrcIdx = 294;
	  section.data(295).dtTransOffset = 65905;
	
	  ;% controller_template_P.UnitDelay1_X0_fk
	  section.data(296).logicalSrcIdx = 295;
	  section.data(296).dtTransOffset = 65914;
	
	  ;% controller_template_P.FixPtUnitDelay1_X0_n
	  section.data(297).logicalSrcIdx = 296;
	  section.data(297).dtTransOffset = 65930;
	
	  ;% controller_template_P.V_max_Value_o
	  section.data(298).logicalSrcIdx = 297;
	  section.data(298).dtTransOffset = 65931;
	
	  ;% controller_template_P.i_min_Value_j
	  section.data(299).logicalSrcIdx = 298;
	  section.data(299).dtTransOffset = 65961;
	
	  ;% controller_template_P.betas_Value_l
	  section.data(300).logicalSrcIdx = 299;
	  section.data(300).dtTransOffset = 65962;
	
	  ;% controller_template_P.L_Value_n
	  section.data(301).logicalSrcIdx = 300;
	  section.data(301).dtTransOffset = 65969;
	
	  ;% controller_template_P.UnitDelay_X0_ik
	  section.data(302).logicalSrcIdx = 301;
	  section.data(302).dtTransOffset = 65970;
	
	  ;% controller_template_P.UnitDelay1_X0_jc
	  section.data(303).logicalSrcIdx = 302;
	  section.data(303).dtTransOffset = 65973;
	
	  ;% controller_template_P.Saturation_UpperSat_f
	  section.data(304).logicalSrcIdx = 303;
	  section.data(304).dtTransOffset = 66003;
	
	  ;% controller_template_P.Saturation_LowerSat_k
	  section.data(305).logicalSrcIdx = 304;
	  section.data(305).dtTransOffset = 66004;
	
	  ;% controller_template_P.TT_PP_Value_b
	  section.data(306).logicalSrcIdx = 305;
	  section.data(306).dtTransOffset = 66005;
	
	  ;% controller_template_P.LL_PP_Value_j
	  section.data(307).logicalSrcIdx = 306;
	  section.data(307).dtTransOffset = 66905;
	
	  ;% controller_template_P.LL_ref_PP_Value_h
	  section.data(308).logicalSrcIdx = 307;
	  section.data(308).dtTransOffset = 66965;
	
	  ;% controller_template_P.LL_U_ref_PP_Value_o
	  section.data(309).logicalSrcIdx = 308;
	  section.data(309).dtTransOffset = 68825;
	
	  ;% controller_template_P.MM_Value_l
	  section.data(310).logicalSrcIdx = 309;
	  section.data(310).dtTransOffset = 69725;
	
	  ;% controller_template_P.PP_Value_o
	  section.data(311).logicalSrcIdx = 310;
	  section.data(311).dtTransOffset = 69729;
	
	  ;% controller_template_P.AA_delay_Value_l
	  section.data(312).logicalSrcIdx = 311;
	  section.data(312).dtTransOffset = 70629;
	
	  ;% controller_template_P.BB_delay_Value_b
	  section.data(313).logicalSrcIdx = 312;
	  section.data(313).dtTransOffset = 70633;
	
	  ;% controller_template_P.A_Value_f
	  section.data(314).logicalSrcIdx = 313;
	  section.data(314).dtTransOffset = 70637;
	
	  ;% controller_template_P.B_Value_n
	  section.data(315).logicalSrcIdx = 314;
	  section.data(315).dtTransOffset = 70646;
	
	  ;% controller_template_P.C_Value_o
	  section.data(316).logicalSrcIdx = 315;
	  section.data(316).dtTransOffset = 70649;
	
	  ;% controller_template_P.D_Value_j
	  section.data(317).logicalSrcIdx = 316;
	  section.data(317).dtTransOffset = 70655;
	
	  ;% controller_template_P.Q_Value_j
	  section.data(318).logicalSrcIdx = 317;
	  section.data(318).dtTransOffset = 70657;
	
	  ;% controller_template_P.R_Value_ca
	  section.data(319).logicalSrcIdx = 318;
	  section.data(319).dtTransOffset = 70666;
	
	  ;% controller_template_P.UnitDelay1_X0_cw
	  section.data(320).logicalSrcIdx = 319;
	  section.data(320).dtTransOffset = 70670;
	
	  ;% controller_template_P.FixPtUnitDelay1_X0_c
	  section.data(321).logicalSrcIdx = 320;
	  section.data(321).dtTransOffset = 70679;
	
	  ;% controller_template_P.V_max_Value_i
	  section.data(322).logicalSrcIdx = 321;
	  section.data(322).dtTransOffset = 70680;
	
	  ;% controller_template_P.i_min_Value_o
	  section.data(323).logicalSrcIdx = 322;
	  section.data(323).dtTransOffset = 70710;
	
	  ;% controller_template_P.betas_Value_g
	  section.data(324).logicalSrcIdx = 323;
	  section.data(324).dtTransOffset = 70711;
	
	  ;% controller_template_P.L_Value_m
	  section.data(325).logicalSrcIdx = 324;
	  section.data(325).dtTransOffset = 70719;
	
	  ;% controller_template_P.UnitDelay_X0_a2
	  section.data(326).logicalSrcIdx = 325;
	  section.data(326).dtTransOffset = 70720;
	
	  ;% controller_template_P.UnitDelay1_X0_b
	  section.data(327).logicalSrcIdx = 326;
	  section.data(327).dtTransOffset = 70722;
	
	  ;% controller_template_P.Saturation_UpperSat_l
	  section.data(328).logicalSrcIdx = 327;
	  section.data(328).dtTransOffset = 70752;
	
	  ;% controller_template_P.Saturation_LowerSat_cp
	  section.data(329).logicalSrcIdx = 328;
	  section.data(329).dtTransOffset = 70753;
	
	  ;% controller_template_P.TT_PP_Value_o
	  section.data(330).logicalSrcIdx = 329;
	  section.data(330).dtTransOffset = 70754;
	
	  ;% controller_template_P.LL_PP_Value_j5
	  section.data(331).logicalSrcIdx = 330;
	  section.data(331).dtTransOffset = 71654;
	
	  ;% controller_template_P.LL_ref_PP_Value_e
	  section.data(332).logicalSrcIdx = 331;
	  section.data(332).dtTransOffset = 71714;
	
	  ;% controller_template_P.LL_U_ref_PP_Value_b
	  section.data(333).logicalSrcIdx = 332;
	  section.data(333).dtTransOffset = 73574;
	
	  ;% controller_template_P.MM_Value_g
	  section.data(334).logicalSrcIdx = 333;
	  section.data(334).dtTransOffset = 74474;
	
	  ;% controller_template_P.PP_Value_p
	  section.data(335).logicalSrcIdx = 334;
	  section.data(335).dtTransOffset = 74478;
	
	  ;% controller_template_P.AA_delay_Value_o
	  section.data(336).logicalSrcIdx = 335;
	  section.data(336).dtTransOffset = 75378;
	
	  ;% controller_template_P.BB_delay_Value_d
	  section.data(337).logicalSrcIdx = 336;
	  section.data(337).dtTransOffset = 75382;
	
	  ;% controller_template_P.A_Value_k
	  section.data(338).logicalSrcIdx = 337;
	  section.data(338).dtTransOffset = 75394;
	
	  ;% controller_template_P.B_Value_f
	  section.data(339).logicalSrcIdx = 338;
	  section.data(339).dtTransOffset = 75403;
	
	  ;% controller_template_P.C_Value_b
	  section.data(340).logicalSrcIdx = 339;
	  section.data(340).dtTransOffset = 75406;
	
	  ;% controller_template_P.D_Value_c
	  section.data(341).logicalSrcIdx = 340;
	  section.data(341).dtTransOffset = 75412;
	
	  ;% controller_template_P.Q_Value_g
	  section.data(342).logicalSrcIdx = 341;
	  section.data(342).dtTransOffset = 75414;
	
	  ;% controller_template_P.R_Value_o
	  section.data(343).logicalSrcIdx = 342;
	  section.data(343).dtTransOffset = 75423;
	
	  ;% controller_template_P.UnitDelay1_X0_n
	  section.data(344).logicalSrcIdx = 343;
	  section.data(344).dtTransOffset = 75427;
	
	  ;% controller_template_P.FixPtUnitDelay1_X0_e
	  section.data(345).logicalSrcIdx = 344;
	  section.data(345).dtTransOffset = 75436;
	
	  ;% controller_template_P.V_max_Value_f
	  section.data(346).logicalSrcIdx = 345;
	  section.data(346).dtTransOffset = 75437;
	
	  ;% controller_template_P.i_min_Value_n
	  section.data(347).logicalSrcIdx = 346;
	  section.data(347).dtTransOffset = 75467;
	
	  ;% controller_template_P.betas_Value_j
	  section.data(348).logicalSrcIdx = 347;
	  section.data(348).dtTransOffset = 75468;
	
	  ;% controller_template_P.L_Value_g
	  section.data(349).logicalSrcIdx = 348;
	  section.data(349).dtTransOffset = 75473;
	
	  ;% controller_template_P.UnitDelay_X0_fj
	  section.data(350).logicalSrcIdx = 349;
	  section.data(350).dtTransOffset = 75474;
	
	  ;% controller_template_P.UnitDelay1_X0_o
	  section.data(351).logicalSrcIdx = 350;
	  section.data(351).dtTransOffset = 75480;
	
	  ;% controller_template_P.Saturation_UpperSat_o3
	  section.data(352).logicalSrcIdx = 351;
	  section.data(352).dtTransOffset = 75510;
	
	  ;% controller_template_P.Saturation_LowerSat_kn
	  section.data(353).logicalSrcIdx = 352;
	  section.data(353).dtTransOffset = 75511;
	
	  ;% controller_template_P.g_Value_m
	  section.data(354).logicalSrcIdx = 353;
	  section.data(354).dtTransOffset = 75512;
	
	  ;% controller_template_P.Gain_Gain_o
	  section.data(355).logicalSrcIdx = 354;
	  section.data(355).dtTransOffset = 75513;
	
	  ;% controller_template_P.raddeg2_Gain_p
	  section.data(356).logicalSrcIdx = 355;
	  section.data(356).dtTransOffset = 75514;
	
	  ;% controller_template_P.raddeg1_Gain_a
	  section.data(357).logicalSrcIdx = 356;
	  section.data(357).dtTransOffset = 75515;
	
	  ;% controller_template_P.raddeg3_Gain_k
	  section.data(358).logicalSrcIdx = 357;
	  section.data(358).dtTransOffset = 75516;
	
	  ;% controller_template_P.raddeg_Gain_k
	  section.data(359).logicalSrcIdx = 358;
	  section.data(359).dtTransOffset = 75517;
	
	  ;% controller_template_P.pitch_offset_Value
	  section.data(360).logicalSrcIdx = 359;
	  section.data(360).dtTransOffset = 75518;
	
	  ;% controller_template_P.InitialCondition_Value
	  section.data(361).logicalSrcIdx = 360;
	  section.data(361).dtTransOffset = 75519;
	
	  ;% controller_template_P.Constant1_Value_mr
	  section.data(362).logicalSrcIdx = 361;
	  section.data(362).dtTransOffset = 75520;
	
	  ;% controller_template_P.Constant2_Value_a
	  section.data(363).logicalSrcIdx = 362;
	  section.data(363).dtTransOffset = 75521;
	
	  ;% controller_template_P.FixPtUnitDelay1_X0_h
	  section.data(364).logicalSrcIdx = 363;
	  section.data(364).dtTransOffset = 75522;
	
	  ;% controller_template_P.Constant_Value_pe
	  section.data(365).logicalSrcIdx = 364;
	  section.data(365).dtTransOffset = 75523;
	
	  ;% controller_template_P.pitch_cmd2pitch_Gain
	  section.data(366).logicalSrcIdx = 365;
	  section.data(366).dtTransOffset = 75524;
	
	  ;% controller_template_P.Gain1_Gain_eg
	  section.data(367).logicalSrcIdx = 366;
	  section.data(367).dtTransOffset = 75525;
	
	  ;% controller_template_P.roll_offset_Value
	  section.data(368).logicalSrcIdx = 367;
	  section.data(368).dtTransOffset = 75526;
	
	  ;% controller_template_P.roll_cmd2roll_Gain
	  section.data(369).logicalSrcIdx = 368;
	  section.data(369).dtTransOffset = 75527;
	
	  ;% controller_template_P.Gain2_Gain_a
	  section.data(370).logicalSrcIdx = 369;
	  section.data(370).dtTransOffset = 75528;
	
	  ;% controller_template_P.gravity_Value_ch
	  section.data(371).logicalSrcIdx = 370;
	  section.data(371).dtTransOffset = 75529;
	
	  ;% controller_template_P.Constant_Value_lf
	  section.data(372).logicalSrcIdx = 371;
	  section.data(372).dtTransOffset = 75530;
	
	  ;% controller_template_P.SliderGain_Gain_px
	  section.data(373).logicalSrcIdx = 372;
	  section.data(373).dtTransOffset = 75531;
	
	  ;% controller_template_P.Gain5_Gain
	  section.data(374).logicalSrcIdx = 373;
	  section.data(374).dtTransOffset = 75532;
	
	  ;% controller_template_P.Constant1_Value_ih
	  section.data(375).logicalSrcIdx = 374;
	  section.data(375).dtTransOffset = 75533;
	
	  ;% controller_template_P.Saturation_UpperSat_pb
	  section.data(376).logicalSrcIdx = 375;
	  section.data(376).dtTransOffset = 75534;
	
	  ;% controller_template_P.Saturation_LowerSat_h
	  section.data(377).logicalSrcIdx = 376;
	  section.data(377).dtTransOffset = 75535;
	
	  ;% controller_template_P.SliderGain_Gain_o
	  section.data(378).logicalSrcIdx = 377;
	  section.data(378).dtTransOffset = 75536;
	
	  ;% controller_template_P.SliderGain_Gain_mn
	  section.data(379).logicalSrcIdx = 378;
	  section.data(379).dtTransOffset = 75537;
	
	  ;% controller_template_P.trhust_cmd2thrust_Gain
	  section.data(380).logicalSrcIdx = 379;
	  section.data(380).dtTransOffset = 75538;
	
	  ;% controller_template_P.Gain_Gain_k
	  section.data(381).logicalSrcIdx = 380;
	  section.data(381).dtTransOffset = 75539;
	
	  ;% controller_template_P.Gain3_Gain
	  section.data(382).logicalSrcIdx = 381;
	  section.data(382).dtTransOffset = 75540;
	
	  ;% controller_template_P.Gain4_Gain
	  section.data(383).logicalSrcIdx = 382;
	  section.data(383).dtTransOffset = 75541;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% controller_template_P.IntegerDelay3_DelayLength
	  section.data(1).logicalSrcIdx = 383;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_P.IntegerDelay_DelayLength
	  section.data(2).logicalSrcIdx = 384;
	  section.data(2).dtTransOffset = 1;
	
	  ;% controller_template_P.IntegerDelay1_DelayLength
	  section.data(3).logicalSrcIdx = 385;
	  section.data(3).dtTransOffset = 2;
	
	  ;% controller_template_P.IntegerDelay2_DelayLength
	  section.data(4).logicalSrcIdx = 386;
	  section.data(4).dtTransOffset = 3;
	
	  ;% controller_template_P.IntegerDelay3_DelayLength_o
	  section.data(5).logicalSrcIdx = 387;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 33;
      section.data(33)  = dumData; %prealloc
      
	  ;% controller_template_P.FixPtUnitDelay2_X0
	  section.data(1).logicalSrcIdx = 388;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_P.Constant_Value_ki
	  section.data(2).logicalSrcIdx = 389;
	  section.data(2).dtTransOffset = 1;
	
	  ;% controller_template_P.Constant_Value_lwi
	  section.data(3).logicalSrcIdx = 390;
	  section.data(3).dtTransOffset = 2;
	
	  ;% controller_template_P.SwitchControl_Threshold
	  section.data(4).logicalSrcIdx = 391;
	  section.data(4).dtTransOffset = 3;
	
	  ;% controller_template_P.Constant_Value_j
	  section.data(5).logicalSrcIdx = 392;
	  section.data(5).dtTransOffset = 4;
	
	  ;% controller_template_P.SwitchControl_Threshold_a
	  section.data(6).logicalSrcIdx = 393;
	  section.data(6).dtTransOffset = 5;
	
	  ;% controller_template_P.SwitchControl_Threshold_g
	  section.data(7).logicalSrcIdx = 394;
	  section.data(7).dtTransOffset = 6;
	
	  ;% controller_template_P.FixPtConstant_Value
	  section.data(8).logicalSrcIdx = 395;
	  section.data(8).dtTransOffset = 7;
	
	  ;% controller_template_P.Constant_Value_ph
	  section.data(9).logicalSrcIdx = 396;
	  section.data(9).dtTransOffset = 8;
	
	  ;% controller_template_P.SwitchControl_1_Threshold
	  section.data(10).logicalSrcIdx = 397;
	  section.data(10).dtTransOffset = 9;
	
	  ;% controller_template_P.SwitchControl_2_Threshold
	  section.data(11).logicalSrcIdx = 398;
	  section.data(11).dtTransOffset = 10;
	
	  ;% controller_template_P.SwitchControl_3_Threshold
	  section.data(12).logicalSrcIdx = 399;
	  section.data(12).dtTransOffset = 11;
	
	  ;% controller_template_P.SwitchControl_4_Threshold
	  section.data(13).logicalSrcIdx = 400;
	  section.data(13).dtTransOffset = 12;
	
	  ;% controller_template_P.SwitchControl_5_Threshold
	  section.data(14).logicalSrcIdx = 401;
	  section.data(14).dtTransOffset = 13;
	
	  ;% controller_template_P.SwitchControl_6_Threshold
	  section.data(15).logicalSrcIdx = 402;
	  section.data(15).dtTransOffset = 14;
	
	  ;% controller_template_P.SwitchControl_8_Threshold
	  section.data(16).logicalSrcIdx = 403;
	  section.data(16).dtTransOffset = 15;
	
	  ;% controller_template_P.SwitchControl_7_Threshold
	  section.data(17).logicalSrcIdx = 404;
	  section.data(17).dtTransOffset = 16;
	
	  ;% controller_template_P.FixPtUnitDelay2_X0_d
	  section.data(18).logicalSrcIdx = 405;
	  section.data(18).dtTransOffset = 17;
	
	  ;% controller_template_P.FixPtUnitDelay2_X0_n
	  section.data(19).logicalSrcIdx = 406;
	  section.data(19).dtTransOffset = 18;
	
	  ;% controller_template_P.FixPtUnitDelay2_X0_do
	  section.data(20).logicalSrcIdx = 407;
	  section.data(20).dtTransOffset = 19;
	
	  ;% controller_template_P.FixPtUnitDelay2_X0_i
	  section.data(21).logicalSrcIdx = 408;
	  section.data(21).dtTransOffset = 20;
	
	  ;% controller_template_P.FixPtConstant_Value_h
	  section.data(22).logicalSrcIdx = 409;
	  section.data(22).dtTransOffset = 21;
	
	  ;% controller_template_P.FixPtConstant_Value_o
	  section.data(23).logicalSrcIdx = 410;
	  section.data(23).dtTransOffset = 22;
	
	  ;% controller_template_P.FixPtConstant_Value_n
	  section.data(24).logicalSrcIdx = 411;
	  section.data(24).dtTransOffset = 23;
	
	  ;% controller_template_P.FixPtConstant_Value_p
	  section.data(25).logicalSrcIdx = 412;
	  section.data(25).dtTransOffset = 24;
	
	  ;% controller_template_P.FixPtUnitDelay2_X0_g
	  section.data(26).logicalSrcIdx = 413;
	  section.data(26).dtTransOffset = 25;
	
	  ;% controller_template_P.Constant_Value_he
	  section.data(27).logicalSrcIdx = 414;
	  section.data(27).dtTransOffset = 26;
	
	  ;% controller_template_P.SwitchControl_Threshold_e
	  section.data(28).logicalSrcIdx = 415;
	  section.data(28).dtTransOffset = 27;
	
	  ;% controller_template_P.Constant_Value_nk
	  section.data(29).logicalSrcIdx = 416;
	  section.data(29).dtTransOffset = 28;
	
	  ;% controller_template_P.SwitchControl_Threshold_b
	  section.data(30).logicalSrcIdx = 417;
	  section.data(30).dtTransOffset = 29;
	
	  ;% controller_template_P.Constant_Value_a3
	  section.data(31).logicalSrcIdx = 418;
	  section.data(31).dtTransOffset = 30;
	
	  ;% controller_template_P.SwitchControl_Threshold_ef
	  section.data(32).logicalSrcIdx = 419;
	  section.data(32).dtTransOffset = 31;
	
	  ;% controller_template_P.FixPtConstant_Value_i
	  section.data(33).logicalSrcIdx = 420;
	  section.data(33).dtTransOffset = 32;
	
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
    nTotSects     = 25;
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
      section.nData     = 125;
      section.data(125)  = dumData; %prealloc
      
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
	
	  ;% controller_template_B.roll_rot
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 367;
	
	  ;% controller_template_B.pitch_rot
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 368;
	
	  ;% controller_template_B.pitch_bias_rot
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 369;
	
	  ;% controller_template_B.roll_bias_rot
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 370;
	
	  ;% controller_template_B.bias_W
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 371;
	
	  ;% controller_template_B.cmd_W
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 375;
	
	  ;% controller_template_B.pitch_rot_k
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 379;
	
	  ;% controller_template_B.roll_rot_a
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 380;
	
	  ;% controller_template_B.pitch_bias_rot_e
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 381;
	
	  ;% controller_template_B.roll_bias_rot_b
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 382;
	
	  ;% controller_template_B.pitch_cmd_comp
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 383;
	
	  ;% controller_template_B.roll_cmd_comp
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 384;
	
	  ;% controller_template_B.thrust_comp
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 385;
	
	  ;% controller_template_B.thrust_cmd_e
	  section.data(34).logicalSrcIdx = 37;
	  section.data(34).dtTransOffset = 386;
	
	  ;% controller_template_B.u_opt
	  section.data(35).logicalSrcIdx = 38;
	  section.data(35).dtTransOffset = 387;
	
	  ;% controller_template_B.J_star
	  section.data(36).logicalSrcIdx = 39;
	  section.data(36).dtTransOffset = 388;
	
	  ;% controller_template_B.u_buff_out
	  section.data(37).logicalSrcIdx = 40;
	  section.data(37).dtTransOffset = 389;
	
	  ;% controller_template_B.V_init_out
	  section.data(38).logicalSrcIdx = 41;
	  section.data(38).dtTransOffset = 391;
	
	  ;% controller_template_B.u_opt_l
	  section.data(39).logicalSrcIdx = 42;
	  section.data(39).dtTransOffset = 421;
	
	  ;% controller_template_B.J_star_h
	  section.data(40).logicalSrcIdx = 43;
	  section.data(40).dtTransOffset = 422;
	
	  ;% controller_template_B.u_buff_out_i
	  section.data(41).logicalSrcIdx = 44;
	  section.data(41).dtTransOffset = 423;
	
	  ;% controller_template_B.V_init_out_n
	  section.data(42).logicalSrcIdx = 45;
	  section.data(42).dtTransOffset = 429;
	
	  ;% controller_template_B.Switch1
	  section.data(43).logicalSrcIdx = 46;
	  section.data(43).dtTransOffset = 459;
	
	  ;% controller_template_B.Switch
	  section.data(44).logicalSrcIdx = 47;
	  section.data(44).dtTransOffset = 460;
	
	  ;% controller_template_B.UnitDelay1
	  section.data(45).logicalSrcIdx = 48;
	  section.data(45).dtTransOffset = 461;
	
	  ;% controller_template_B.x_ref
	  section.data(46).logicalSrcIdx = 49;
	  section.data(46).dtTransOffset = 462;
	
	  ;% controller_template_B.y_ref
	  section.data(47).logicalSrcIdx = 50;
	  section.data(47).dtTransOffset = 463;
	
	  ;% controller_template_B.z_ref
	  section.data(48).logicalSrcIdx = 51;
	  section.data(48).dtTransOffset = 464;
	
	  ;% controller_template_B.Gain_p
	  section.data(49).logicalSrcIdx = 52;
	  section.data(49).dtTransOffset = 465;
	
	  ;% controller_template_B.raddeg2_p
	  section.data(50).logicalSrcIdx = 53;
	  section.data(50).dtTransOffset = 483;
	
	  ;% controller_template_B.raddeg1_e
	  section.data(51).logicalSrcIdx = 54;
	  section.data(51).dtTransOffset = 486;
	
	  ;% controller_template_B.x_dot_ref
	  section.data(52).logicalSrcIdx = 55;
	  section.data(52).dtTransOffset = 488;
	
	  ;% controller_template_B.y_dot_ref
	  section.data(53).logicalSrcIdx = 56;
	  section.data(53).dtTransOffset = 489;
	
	  ;% controller_template_B.raddeg3_a
	  section.data(54).logicalSrcIdx = 57;
	  section.data(54).dtTransOffset = 490;
	
	  ;% controller_template_B.raddeg_j
	  section.data(55).logicalSrcIdx = 58;
	  section.data(55).dtTransOffset = 493;
	
	  ;% controller_template_B.z_dot_ref
	  section.data(56).logicalSrcIdx = 59;
	  section.data(56).dtTransOffset = 497;
	
	  ;% controller_template_B.Sum
	  section.data(57).logicalSrcIdx = 60;
	  section.data(57).dtTransOffset = 498;
	
	  ;% controller_template_B.Gain_k
	  section.data(58).logicalSrcIdx = 61;
	  section.data(58).dtTransOffset = 500;
	
	  ;% controller_template_B.roll_rot_f
	  section.data(59).logicalSrcIdx = 62;
	  section.data(59).dtTransOffset = 502;
	
	  ;% controller_template_B.pitch_rot_i
	  section.data(60).logicalSrcIdx = 63;
	  section.data(60).dtTransOffset = 503;
	
	  ;% controller_template_B.pitch_bias_rot_p
	  section.data(61).logicalSrcIdx = 64;
	  section.data(61).dtTransOffset = 504;
	
	  ;% controller_template_B.roll_bias_rot_n
	  section.data(62).logicalSrcIdx = 65;
	  section.data(62).dtTransOffset = 505;
	
	  ;% controller_template_B.bias_W_b
	  section.data(63).logicalSrcIdx = 66;
	  section.data(63).dtTransOffset = 506;
	
	  ;% controller_template_B.cmd_W_h
	  section.data(64).logicalSrcIdx = 67;
	  section.data(64).dtTransOffset = 510;
	
	  ;% controller_template_B.pitch_rot_n
	  section.data(65).logicalSrcIdx = 68;
	  section.data(65).dtTransOffset = 514;
	
	  ;% controller_template_B.roll_rot_e
	  section.data(66).logicalSrcIdx = 69;
	  section.data(66).dtTransOffset = 515;
	
	  ;% controller_template_B.pitch_bias_rot_i
	  section.data(67).logicalSrcIdx = 70;
	  section.data(67).dtTransOffset = 516;
	
	  ;% controller_template_B.roll_bias_rot_d
	  section.data(68).logicalSrcIdx = 71;
	  section.data(68).dtTransOffset = 517;
	
	  ;% controller_template_B.pitch_cmd_comp_n
	  section.data(69).logicalSrcIdx = 72;
	  section.data(69).dtTransOffset = 518;
	
	  ;% controller_template_B.roll_cmd_comp_j
	  section.data(70).logicalSrcIdx = 73;
	  section.data(70).dtTransOffset = 519;
	
	  ;% controller_template_B.thrust_comp_k
	  section.data(71).logicalSrcIdx = 74;
	  section.data(71).dtTransOffset = 520;
	
	  ;% controller_template_B.nominal_window_z_out
	  section.data(72).logicalSrcIdx = 75;
	  section.data(72).dtTransOffset = 521;
	
	  ;% controller_template_B.nominal_window_y_out
	  section.data(73).logicalSrcIdx = 76;
	  section.data(73).dtTransOffset = 522;
	
	  ;% controller_template_B.count_out
	  section.data(74).logicalSrcIdx = 77;
	  section.data(74).dtTransOffset = 523;
	
	  ;% controller_template_B.en
	  section.data(75).logicalSrcIdx = 78;
	  section.data(75).dtTransOffset = 524;
	
	  ;% controller_template_B.Gain2
	  section.data(76).logicalSrcIdx = 79;
	  section.data(76).dtTransOffset = 525;
	
	  ;% controller_template_B.SwitchControl
	  section.data(77).logicalSrcIdx = 80;
	  section.data(77).dtTransOffset = 526;
	
	  ;% controller_template_B.RateTransition
	  section.data(78).logicalSrcIdx = 81;
	  section.data(78).dtTransOffset = 527;
	
	  ;% controller_template_B.UnitDelay2
	  section.data(79).logicalSrcIdx = 82;
	  section.data(79).dtTransOffset = 531;
	
	  ;% controller_template_B.RateTransition_l
	  section.data(80).logicalSrcIdx = 83;
	  section.data(80).dtTransOffset = 532;
	
	  ;% controller_template_B.UnitDelay2_p
	  section.data(81).logicalSrcIdx = 84;
	  section.data(81).dtTransOffset = 536;
	
	  ;% controller_template_B.Gain_pk
	  section.data(82).logicalSrcIdx = 85;
	  section.data(82).dtTransOffset = 537;
	
	  ;% controller_template_B.Saturation3
	  section.data(83).logicalSrcIdx = 86;
	  section.data(83).dtTransOffset = 538;
	
	  ;% controller_template_B.RateTransition_i
	  section.data(84).logicalSrcIdx = 87;
	  section.data(84).dtTransOffset = 539;
	
	  ;% controller_template_B.UnitDelay2_o
	  section.data(85).logicalSrcIdx = 88;
	  section.data(85).dtTransOffset = 544;
	
	  ;% controller_template_B.Gain_f
	  section.data(86).logicalSrcIdx = 89;
	  section.data(86).dtTransOffset = 545;
	
	  ;% controller_template_B.Saturation1
	  section.data(87).logicalSrcIdx = 90;
	  section.data(87).dtTransOffset = 546;
	
	  ;% controller_template_B.RateTransition_j
	  section.data(88).logicalSrcIdx = 91;
	  section.data(88).dtTransOffset = 547;
	
	  ;% controller_template_B.Gain_i
	  section.data(89).logicalSrcIdx = 92;
	  section.data(89).dtTransOffset = 550;
	
	  ;% controller_template_B.Sum_b
	  section.data(90).logicalSrcIdx = 93;
	  section.data(90).dtTransOffset = 551;
	
	  ;% controller_template_B.Gain_n
	  section.data(91).logicalSrcIdx = 94;
	  section.data(91).dtTransOffset = 552;
	
	  ;% controller_template_B.thrust_cmd_a
	  section.data(92).logicalSrcIdx = 96;
	  section.data(92).dtTransOffset = 553;
	
	  ;% controller_template_B.RateTransition1
	  section.data(93).logicalSrcIdx = 97;
	  section.data(93).dtTransOffset = 554;
	
	  ;% controller_template_B.RateTransition1_l
	  section.data(94).logicalSrcIdx = 98;
	  section.data(94).dtTransOffset = 555;
	
	  ;% controller_template_B.RateTransition1_lq
	  section.data(95).logicalSrcIdx = 99;
	  section.data(95).dtTransOffset = 556;
	
	  ;% controller_template_B.Gain_g
	  section.data(96).logicalSrcIdx = 100;
	  section.data(96).dtTransOffset = 557;
	
	  ;% controller_template_B.Gain1
	  section.data(97).logicalSrcIdx = 101;
	  section.data(97).dtTransOffset = 558;
	
	  ;% controller_template_B.Gain_d
	  section.data(98).logicalSrcIdx = 102;
	  section.data(98).dtTransOffset = 559;
	
	  ;% controller_template_B.u_thrust_out
	  section.data(99).logicalSrcIdx = 103;
	  section.data(99).dtTransOffset = 560;
	
	  ;% controller_template_B.U
	  section.data(100).logicalSrcIdx = 104;
	  section.data(100).dtTransOffset = 561;
	
	  ;% controller_template_B.flag_oob
	  section.data(101).logicalSrcIdx = 105;
	  section.data(101).dtTransOffset = 562;
	
	  ;% controller_template_B.psi_prime
	  section.data(102).logicalSrcIdx = 106;
	  section.data(102).dtTransOffset = 563;
	
	  ;% controller_template_B.psi_out
	  section.data(103).logicalSrcIdx = 107;
	  section.data(103).dtTransOffset = 564;
	
	  ;% controller_template_B.delta_x
	  section.data(104).logicalSrcIdx = 108;
	  section.data(104).dtTransOffset = 565;
	
	  ;% controller_template_B.psi_prime_l
	  section.data(105).logicalSrcIdx = 109;
	  section.data(105).dtTransOffset = 566;
	
	  ;% controller_template_B.y
	  section.data(106).logicalSrcIdx = 110;
	  section.data(106).dtTransOffset = 567;
	
	  ;% controller_template_B.U_g
	  section.data(107).logicalSrcIdx = 111;
	  section.data(107).dtTransOffset = 568;
	
	  ;% controller_template_B.flag_oob_l
	  section.data(108).logicalSrcIdx = 112;
	  section.data(108).dtTransOffset = 569;
	
	  ;% controller_template_B.input_out
	  section.data(109).logicalSrcIdx = 113;
	  section.data(109).dtTransOffset = 570;
	
	  ;% controller_template_B.y_a
	  section.data(110).logicalSrcIdx = 114;
	  section.data(110).dtTransOffset = 571;
	
	  ;% controller_template_B.U_p
	  section.data(111).logicalSrcIdx = 115;
	  section.data(111).dtTransOffset = 576;
	
	  ;% controller_template_B.flag_oob_o
	  section.data(112).logicalSrcIdx = 116;
	  section.data(112).dtTransOffset = 577;
	
	  ;% controller_template_B.pulse_enable
	  section.data(113).logicalSrcIdx = 117;
	  section.data(113).dtTransOffset = 578;
	
	  ;% controller_template_B.flag_init
	  section.data(114).logicalSrcIdx = 118;
	  section.data(114).dtTransOffset = 579;
	
	  ;% controller_template_B.x_init
	  section.data(115).logicalSrcIdx = 119;
	  section.data(115).dtTransOffset = 580;
	
	  ;% controller_template_B.x_meas
	  section.data(116).logicalSrcIdx = 120;
	  section.data(116).dtTransOffset = 584;
	
	  ;% controller_template_B.Pmeas
	  section.data(117).logicalSrcIdx = 121;
	  section.data(117).dtTransOffset = 588;
	
	  ;% controller_template_B.flag_failure
	  section.data(118).logicalSrcIdx = 122;
	  section.data(118).dtTransOffset = 604;
	
	  ;% controller_template_B.y_i
	  section.data(119).logicalSrcIdx = 123;
	  section.data(119).dtTransOffset = 605;
	
	  ;% controller_template_B.U_gb
	  section.data(120).logicalSrcIdx = 124;
	  section.data(120).dtTransOffset = 609;
	
	  ;% controller_template_B.flag_oob_ow
	  section.data(121).logicalSrcIdx = 125;
	  section.data(121).dtTransOffset = 610;
	
	  ;% controller_template_B.y_o
	  section.data(122).logicalSrcIdx = 126;
	  section.data(122).dtTransOffset = 611;
	
	  ;% controller_template_B.U_a
	  section.data(123).logicalSrcIdx = 127;
	  section.data(123).dtTransOffset = 615;
	
	  ;% controller_template_B.flag_oob_l1
	  section.data(124).logicalSrcIdx = 128;
	  section.data(124).dtTransOffset = 616;
	
	  ;% controller_template_B.pitch_cmd_out
	  section.data(125).logicalSrcIdx = 129;
	  section.data(125).dtTransOffset = 617;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_B.sf_discretekalmanfilter_k.state_est
	  section.data(1).logicalSrcIdx = 130;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_B.sf_discretekalmanfilter_k.P_est
	  section.data(2).logicalSrcIdx = 131;
	  section.data(2).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_B.sf_discretekalmanfilter_n.state_est
	  section.data(1).logicalSrcIdx = 132;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_B.sf_discretekalmanfilter_n.P_est
	  section.data(2).logicalSrcIdx = 133;
	  section.data(2).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_B.sf_discretekalmanfilter_m.state_est
	  section.data(1).logicalSrcIdx = 134;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_B.sf_discretekalmanfilter_m.P_est
	  section.data(2).logicalSrcIdx = 135;
	  section.data(2).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% controller_template_B.sf_runFastGradient_d.u_opt
	  section.data(1).logicalSrcIdx = 136;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_B.sf_runFastGradient_d.J_star
	  section.data(2).logicalSrcIdx = 137;
	  section.data(2).dtTransOffset = 1;
	
	  ;% controller_template_B.sf_runFastGradient_d.u_buff_out
	  section.data(3).logicalSrcIdx = 138;
	  section.data(3).dtTransOffset = 2;
	
	  ;% controller_template_B.sf_runFastGradient_d.V_init_out
	  section.data(4).logicalSrcIdx = 139;
	  section.data(4).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(5) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_B.sf_discretekalmanfilter_b.state_est
	  section.data(1).logicalSrcIdx = 140;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_B.sf_discretekalmanfilter_b.P_est
	  section.data(2).logicalSrcIdx = 141;
	  section.data(2).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(6) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% controller_template_B.sf_runFastGradient.u_opt
	  section.data(1).logicalSrcIdx = 142;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_B.sf_runFastGradient.J_star
	  section.data(2).logicalSrcIdx = 143;
	  section.data(2).dtTransOffset = 1;
	
	  ;% controller_template_B.sf_runFastGradient.u_buff_out
	  section.data(3).logicalSrcIdx = 144;
	  section.data(3).dtTransOffset = 2;
	
	  ;% controller_template_B.sf_runFastGradient.V_init_out
	  section.data(4).logicalSrcIdx = 145;
	  section.data(4).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_B.sf_MATLABFunction_p.y
	  section.data(1).logicalSrcIdx = 146;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_B.sf_generate_X_ref_z.X_ref_z
	  section.data(1).logicalSrcIdx = 147;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(9) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_B.sf_generate_X_ref_yaw.X_ref_yaw
	  section.data(1).logicalSrcIdx = 148;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(10) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_B.sf_generate_X_ref_y.X_ref_y
	  section.data(1).logicalSrcIdx = 149;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(11) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_B.sf_generate_X_ref_x.X_ref_x
	  section.data(1).logicalSrcIdx = 150;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(12) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_B.sf_MATLABFunction.y
	  section.data(1).logicalSrcIdx = 151;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(13) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_B.sf_MATLABFunction_c.y
	  section.data(1).logicalSrcIdx = 152;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(14) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_B.sf_discretekalmanfilter.state_est
	  section.data(1).logicalSrcIdx = 153;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_B.sf_discretekalmanfilter.P_est
	  section.data(2).logicalSrcIdx = 154;
	  section.data(2).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(15) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_B.sf_MATLABFunction_l5.y
	  section.data(1).logicalSrcIdx = 155;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(16) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_B.sf_MATLABFunction_e.y
	  section.data(1).logicalSrcIdx = 156;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(17) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_B.sf_generate_X_ref_z_b.X_ref_z
	  section.data(1).logicalSrcIdx = 157;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(18) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_B.sf_generate_X_ref_yaw_h.X_ref_yaw
	  section.data(1).logicalSrcIdx = 158;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(19) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_B.sf_generate_X_ref_y_k.X_ref_y
	  section.data(1).logicalSrcIdx = 159;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(20) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_B.sf_generate_X_ref_x_a.X_ref_x
	  section.data(1).logicalSrcIdx = 160;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(21) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_B.sf_generate_X_ref_z_l.X_ref_z
	  section.data(1).logicalSrcIdx = 161;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(22) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_B.sf_generate_X_ref_yaw_g.X_ref_yaw
	  section.data(1).logicalSrcIdx = 162;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(23) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_B.sf_generate_X_ref_y_a.X_ref_y
	  section.data(1).logicalSrcIdx = 163;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(24) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_B.sf_generate_X_ref_x_k.X_ref_x
	  section.data(1).logicalSrcIdx = 164;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(25) = section;
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
    nTotSects     = 80;
    sectIdxOffset = 25;
    
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
      section.nData     = 55;
      section.data(55)  = dumData; %prealloc
      
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
	
	  ;% controller_template_DWork.UnitDelay_DSTATE_c
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 206;
	
	  ;% controller_template_DWork.UnitDelay_DSTATE_e
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 207;
	
	  ;% controller_template_DWork.UnitDelay_DSTATE_es
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 208;
	
	  ;% controller_template_DWork.UnitDelay1_DSTATE_o
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 209;
	
	  ;% controller_template_DWork.IntegerDelay3_DSTATE_k
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 210;
	
	  ;% controller_template_DWork.UnitDelay1_DSTATE_bg
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 211;
	
	  ;% controller_template_DWork.FixPtUnitDelay1_DSTATE_i1
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 220;
	
	  ;% controller_template_DWork.UnitDelay1_DSTATE_h
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 222;
	
	  ;% controller_template_DWork.UnitDelay2_DSTATE
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 226;
	
	  ;% controller_template_DWork.UnitDelay2_DSTATE_c
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 227;
	
	  ;% controller_template_DWork.UnitDelay2_DSTATE_m
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 228;
	
	  ;% controller_template_DWork.UnitDelay2_DSTATE_d
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 229;
	
	  ;% controller_template_DWork.UnitDelay_DSTATE_jv
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 230;
	
	  ;% controller_template_DWork.UnitDelay2_DSTATE_l
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 231;
	
	  ;% controller_template_DWork.UnitDelay2_DSTATE_k
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 232;
	
	  ;% controller_template_DWork.UnitDelay_DSTATE_f
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 233;
	
	  ;% controller_template_DWork.UnitDelay2_DSTATE_b
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 234;
	
	  ;% controller_template_DWork.UnitDelay_DSTATE_fw
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 235;
	
	  ;% controller_template_DWork.UnitDelay_DSTATE_lg
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 236;
	
	  ;% controller_template_DWork.UnitDelay2_DSTATE_g
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 237;
	
	  ;% controller_template_DWork.UnitDelay2_DSTATE_ga
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 238;
	
	  ;% controller_template_DWork.UnitDelay_DSTATE_p
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 239;
	
	  ;% controller_template_DWork.UnitDelay1_DSTATE_a
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 240;
	
	  ;% controller_template_DWork.UnitDelay_DSTATE_a
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 241;
	
	  ;% controller_template_DWork.UnitDelay_DSTATE_m
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 242;
	
	  ;% controller_template_DWork.UnitDelay1_DSTATE_j5
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 246;
	
	  ;% controller_template_DWork.UnitDelay_DSTATE_m2
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 262;
	
	  ;% controller_template_DWork.UnitDelay1_DSTATE_ji
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 263;
	
	  ;% controller_template_DWork.UnitDelay1_DSTATE_c3
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 264;
	
	  ;% controller_template_DWork.UnitDelay1_DSTATE_m
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 265;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 38;
      section.data(38)  = dumData; %prealloc
      
	  ;% controller_template_DWork.bias_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 55;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.cmd_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 56;
	  section.data(2).dtTransOffset = 1;
	
	  ;% controller_template_DWork.cmd1_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 57;
	  section.data(3).dtTransOffset = 2;
	
	  ;% controller_template_DWork.mode_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 58;
	  section.data(4).dtTransOffset = 3;
	
	  ;% controller_template_DWork.mode2_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 59;
	  section.data(5).dtTransOffset = 4;
	
	  ;% controller_template_DWork.mode1_PWORK.LoggedData
	  section.data(6).logicalSrcIdx = 60;
	  section.data(6).dtTransOffset = 5;
	
	  ;% controller_template_DWork.mode1_PWORK_h.LoggedData
	  section.data(7).logicalSrcIdx = 61;
	  section.data(7).dtTransOffset = 6;
	
	  ;% controller_template_DWork.ToFile_PWORK.FilePtr
	  section.data(8).logicalSrcIdx = 62;
	  section.data(8).dtTransOffset = 7;
	
	  ;% controller_template_DWork.ToFile1_PWORK.FilePtr
	  section.data(9).logicalSrcIdx = 63;
	  section.data(9).dtTransOffset = 8;
	
	  ;% controller_template_DWork.ToWorkspace_PWORK.LoggedData
	  section.data(10).logicalSrcIdx = 64;
	  section.data(10).dtTransOffset = 9;
	
	  ;% controller_template_DWork.pitchcmd_PWORK.LoggedData
	  section.data(11).logicalSrcIdx = 65;
	  section.data(11).dtTransOffset = 10;
	
	  ;% controller_template_DWork.rollcmd_PWORK.LoggedData
	  section.data(12).logicalSrcIdx = 66;
	  section.data(12).dtTransOffset = 11;
	
	  ;% controller_template_DWork.thrustcmd_PWORK.LoggedData
	  section.data(13).logicalSrcIdx = 67;
	  section.data(13).dtTransOffset = 12;
	
	  ;% controller_template_DWork.x_ref_PWORK.LoggedData
	  section.data(14).logicalSrcIdx = 68;
	  section.data(14).dtTransOffset = 13;
	
	  ;% controller_template_DWork.y_ref_PWORK.LoggedData
	  section.data(15).logicalSrcIdx = 69;
	  section.data(15).dtTransOffset = 14;
	
	  ;% controller_template_DWork.yawcmd_PWORK.LoggedData
	  section.data(16).logicalSrcIdx = 70;
	  section.data(16).dtTransOffset = 15;
	
	  ;% controller_template_DWork.yaw_ref_PWORK.LoggedData
	  section.data(17).logicalSrcIdx = 71;
	  section.data(17).dtTransOffset = 16;
	
	  ;% controller_template_DWork.z_ref_PWORK.LoggedData
	  section.data(18).logicalSrcIdx = 72;
	  section.data(18).dtTransOffset = 17;
	
	  ;% controller_template_DWork.ToFile_PWORK_p.FilePtr
	  section.data(19).logicalSrcIdx = 73;
	  section.data(19).dtTransOffset = 18;
	
	  ;% controller_template_DWork.ToFile1_PWORK_i.FilePtr
	  section.data(20).logicalSrcIdx = 74;
	  section.data(20).dtTransOffset = 19;
	
	  ;% controller_template_DWork.ToWorkspace_PWORK_h.LoggedData
	  section.data(21).logicalSrcIdx = 75;
	  section.data(21).dtTransOffset = 20;
	
	  ;% controller_template_DWork.pitchcmd_PWORK_p.LoggedData
	  section.data(22).logicalSrcIdx = 76;
	  section.data(22).dtTransOffset = 21;
	
	  ;% controller_template_DWork.rollcmd_PWORK_i.LoggedData
	  section.data(23).logicalSrcIdx = 77;
	  section.data(23).dtTransOffset = 22;
	
	  ;% controller_template_DWork.thrustcmd_PWORK_g.LoggedData
	  section.data(24).logicalSrcIdx = 78;
	  section.data(24).dtTransOffset = 23;
	
	  ;% controller_template_DWork.x_ref_PWORK_a.LoggedData
	  section.data(25).logicalSrcIdx = 79;
	  section.data(25).dtTransOffset = 24;
	
	  ;% controller_template_DWork.y_ref_PWORK_j.LoggedData
	  section.data(26).logicalSrcIdx = 80;
	  section.data(26).dtTransOffset = 25;
	
	  ;% controller_template_DWork.yawcmd_PWORK_p.LoggedData
	  section.data(27).logicalSrcIdx = 81;
	  section.data(27).dtTransOffset = 26;
	
	  ;% controller_template_DWork.yaw_ref_PWORK_n.LoggedData
	  section.data(28).logicalSrcIdx = 82;
	  section.data(28).dtTransOffset = 27;
	
	  ;% controller_template_DWork.z_ref_PWORK_e.LoggedData
	  section.data(29).logicalSrcIdx = 83;
	  section.data(29).dtTransOffset = 28;
	
	  ;% controller_template_DWork.Scope_PWORK.LoggedData
	  section.data(30).logicalSrcIdx = 84;
	  section.data(30).dtTransOffset = 29;
	
	  ;% controller_template_DWork.Scope_PWORK_p.LoggedData
	  section.data(31).logicalSrcIdx = 85;
	  section.data(31).dtTransOffset = 30;
	
	  ;% controller_template_DWork.Scope_PWORK_i.LoggedData
	  section.data(32).logicalSrcIdx = 86;
	  section.data(32).dtTransOffset = 31;
	
	  ;% controller_template_DWork.Scope_PWORK_f.LoggedData
	  section.data(33).logicalSrcIdx = 87;
	  section.data(33).dtTransOffset = 32;
	
	  ;% controller_template_DWork.Scope_PWORK_l.LoggedData
	  section.data(34).logicalSrcIdx = 88;
	  section.data(34).dtTransOffset = 33;
	
	  ;% controller_template_DWork.Scope1_PWORK.LoggedData
	  section.data(35).logicalSrcIdx = 89;
	  section.data(35).dtTransOffset = 34;
	
	  ;% controller_template_DWork.Scope_PWORK_j.LoggedData
	  section.data(36).logicalSrcIdx = 90;
	  section.data(36).dtTransOffset = 35;
	
	  ;% controller_template_DWork.Scope1_PWORK_c.LoggedData
	  section.data(37).logicalSrcIdx = 91;
	  section.data(37).dtTransOffset = 36;
	
	  ;% controller_template_DWork.Scope_PWORK_e.LoggedData
	  section.data(38).logicalSrcIdx = 92;
	  section.data(38).dtTransOffset = 37;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 30;
      section.data(30)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sfEvent
	  section.data(1).logicalSrcIdx = 93;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.sfEvent_b
	  section.data(2).logicalSrcIdx = 94;
	  section.data(2).dtTransOffset = 1;
	
	  ;% controller_template_DWork.sfEvent_f
	  section.data(3).logicalSrcIdx = 95;
	  section.data(3).dtTransOffset = 2;
	
	  ;% controller_template_DWork.sfEvent_k
	  section.data(4).logicalSrcIdx = 96;
	  section.data(4).dtTransOffset = 3;
	
	  ;% controller_template_DWork.sfEvent_n
	  section.data(5).logicalSrcIdx = 97;
	  section.data(5).dtTransOffset = 4;
	
	  ;% controller_template_DWork.sfEvent_bq
	  section.data(6).logicalSrcIdx = 98;
	  section.data(6).dtTransOffset = 5;
	
	  ;% controller_template_DWork.sfEvent_j
	  section.data(7).logicalSrcIdx = 99;
	  section.data(7).dtTransOffset = 6;
	
	  ;% controller_template_DWork.sfEvent_c
	  section.data(8).logicalSrcIdx = 100;
	  section.data(8).dtTransOffset = 7;
	
	  ;% controller_template_DWork.sfEvent_a
	  section.data(9).logicalSrcIdx = 101;
	  section.data(9).dtTransOffset = 8;
	
	  ;% controller_template_DWork.sfEvent_jg
	  section.data(10).logicalSrcIdx = 102;
	  section.data(10).dtTransOffset = 9;
	
	  ;% controller_template_DWork.sfEvent_p
	  section.data(11).logicalSrcIdx = 103;
	  section.data(11).dtTransOffset = 10;
	
	  ;% controller_template_DWork.sfEvent_jj
	  section.data(12).logicalSrcIdx = 104;
	  section.data(12).dtTransOffset = 11;
	
	  ;% controller_template_DWork.sfEvent_k0
	  section.data(13).logicalSrcIdx = 105;
	  section.data(13).dtTransOffset = 12;
	
	  ;% controller_template_DWork.sfEvent_ks
	  section.data(14).logicalSrcIdx = 106;
	  section.data(14).dtTransOffset = 13;
	
	  ;% controller_template_DWork.sfEvent_d
	  section.data(15).logicalSrcIdx = 107;
	  section.data(15).dtTransOffset = 14;
	
	  ;% controller_template_DWork.sfEvent_g
	  section.data(16).logicalSrcIdx = 108;
	  section.data(16).dtTransOffset = 15;
	
	  ;% controller_template_DWork.sfEvent_l
	  section.data(17).logicalSrcIdx = 109;
	  section.data(17).dtTransOffset = 16;
	
	  ;% controller_template_DWork.sfEvent_jv
	  section.data(18).logicalSrcIdx = 110;
	  section.data(18).dtTransOffset = 17;
	
	  ;% controller_template_DWork.sfEvent_ab
	  section.data(19).logicalSrcIdx = 111;
	  section.data(19).dtTransOffset = 18;
	
	  ;% controller_template_DWork.sfEvent_i
	  section.data(20).logicalSrcIdx = 112;
	  section.data(20).dtTransOffset = 19;
	
	  ;% controller_template_DWork.sfEvent_cd
	  section.data(21).logicalSrcIdx = 113;
	  section.data(21).dtTransOffset = 20;
	
	  ;% controller_template_DWork.sfEvent_fc
	  section.data(22).logicalSrcIdx = 114;
	  section.data(22).dtTransOffset = 21;
	
	  ;% controller_template_DWork.sfEvent_du
	  section.data(23).logicalSrcIdx = 115;
	  section.data(23).dtTransOffset = 22;
	
	  ;% controller_template_DWork.sfEvent_cq
	  section.data(24).logicalSrcIdx = 116;
	  section.data(24).dtTransOffset = 23;
	
	  ;% controller_template_DWork.sfEvent_h
	  section.data(25).logicalSrcIdx = 117;
	  section.data(25).dtTransOffset = 24;
	
	  ;% controller_template_DWork.sfEvent_ac
	  section.data(26).logicalSrcIdx = 118;
	  section.data(26).dtTransOffset = 25;
	
	  ;% controller_template_DWork.sfEvent_cm
	  section.data(27).logicalSrcIdx = 119;
	  section.data(27).dtTransOffset = 26;
	
	  ;% controller_template_DWork.sfEvent_kd
	  section.data(28).logicalSrcIdx = 120;
	  section.data(28).dtTransOffset = 27;
	
	  ;% controller_template_DWork.sfEvent_cr
	  section.data(29).logicalSrcIdx = 121;
	  section.data(29).dtTransOffset = 28;
	
	  ;% controller_template_DWork.sfEvent_fp
	  section.data(30).logicalSrcIdx = 122;
	  section.data(30).dtTransOffset = 29;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% controller_template_DWork.ToFile_IWORK.Count
	  section.data(1).logicalSrcIdx = 123;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.ToFile1_IWORK.Count
	  section.data(2).logicalSrcIdx = 124;
	  section.data(2).dtTransOffset = 1;
	
	  ;% controller_template_DWork.ToFile_IWORK_g.Count
	  section.data(3).logicalSrcIdx = 125;
	  section.data(3).dtTransOffset = 2;
	
	  ;% controller_template_DWork.ToFile1_IWORK_p.Count
	  section.data(4).logicalSrcIdx = 126;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% controller_template_DWork.FixPtUnitDelay2_DSTATE
	  section.data(1).logicalSrcIdx = 127;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.FixPtUnitDelay2_DSTATE_l
	  section.data(2).logicalSrcIdx = 128;
	  section.data(2).dtTransOffset = 1;
	
	  ;% controller_template_DWork.FixPtUnitDelay2_DSTATE_b
	  section.data(3).logicalSrcIdx = 129;
	  section.data(3).dtTransOffset = 2;
	
	  ;% controller_template_DWork.FixPtUnitDelay2_DSTATE_c
	  section.data(4).logicalSrcIdx = 130;
	  section.data(4).dtTransOffset = 3;
	
	  ;% controller_template_DWork.FixPtUnitDelay2_DSTATE_a
	  section.data(5).logicalSrcIdx = 131;
	  section.data(5).dtTransOffset = 4;
	
	  ;% controller_template_DWork.FixPtUnitDelay2_DSTATE_g
	  section.data(6).logicalSrcIdx = 132;
	  section.data(6).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_DWork.FreeFlightPosCtrl_SubsysRanBC
	  section.data(1).logicalSrcIdx = 133;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.poscontroller_SubsysRanBC
	  section.data(2).logicalSrcIdx = 134;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 30;
      section.data(30)  = dumData; %prealloc
      
	  ;% controller_template_DWork.is_active_c26_Hquad_control_LIB
	  section.data(1).logicalSrcIdx = 135;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.is_active_c4_Hquad_control_LIB_
	  section.data(2).logicalSrcIdx = 136;
	  section.data(2).dtTransOffset = 1;
	
	  ;% controller_template_DWork.is_active_c1_Hquad_control_LIB_
	  section.data(3).logicalSrcIdx = 137;
	  section.data(3).dtTransOffset = 2;
	
	  ;% controller_template_DWork.is_active_c8_Hquad_control_LIB_
	  section.data(4).logicalSrcIdx = 138;
	  section.data(4).dtTransOffset = 3;
	
	  ;% controller_template_DWork.is_active_c9_Hquad_control_LIB_
	  section.data(5).logicalSrcIdx = 139;
	  section.data(5).dtTransOffset = 4;
	
	  ;% controller_template_DWork.is_active_c26_Hquad_control_L_f
	  section.data(6).logicalSrcIdx = 140;
	  section.data(6).dtTransOffset = 5;
	
	  ;% controller_template_DWork.is_active_c10_controller_templa
	  section.data(7).logicalSrcIdx = 141;
	  section.data(7).dtTransOffset = 6;
	
	  ;% controller_template_DWork.is_active_c9_controller_templat
	  section.data(8).logicalSrcIdx = 142;
	  section.data(8).dtTransOffset = 7;
	
	  ;% controller_template_DWork.is_active_c18_controller_templa
	  section.data(9).logicalSrcIdx = 143;
	  section.data(9).dtTransOffset = 8;
	
	  ;% controller_template_DWork.is_active_c11_controller_templa
	  section.data(10).logicalSrcIdx = 144;
	  section.data(10).dtTransOffset = 9;
	
	  ;% controller_template_DWork.is_active_c35_controller_templa
	  section.data(11).logicalSrcIdx = 145;
	  section.data(11).dtTransOffset = 10;
	
	  ;% controller_template_DWork.is_active_c16_controller_templa
	  section.data(12).logicalSrcIdx = 146;
	  section.data(12).dtTransOffset = 11;
	
	  ;% controller_template_DWork.is_active_c3_controller_templat
	  section.data(13).logicalSrcIdx = 147;
	  section.data(13).dtTransOffset = 12;
	
	  ;% controller_template_DWork.is_active_c28_controller_templa
	  section.data(14).logicalSrcIdx = 148;
	  section.data(14).dtTransOffset = 13;
	
	  ;% controller_template_DWork.is_active_c30_controller_templa
	  section.data(15).logicalSrcIdx = 149;
	  section.data(15).dtTransOffset = 14;
	
	  ;% controller_template_DWork.is_active_c25_controller_templa
	  section.data(16).logicalSrcIdx = 150;
	  section.data(16).dtTransOffset = 15;
	
	  ;% controller_template_DWork.is_active_c6_controller_templat
	  section.data(17).logicalSrcIdx = 151;
	  section.data(17).dtTransOffset = 16;
	
	  ;% controller_template_DWork.is_active_c4_controller_templat
	  section.data(18).logicalSrcIdx = 152;
	  section.data(18).dtTransOffset = 17;
	
	  ;% controller_template_DWork.is_active_c17_controller_templa
	  section.data(19).logicalSrcIdx = 153;
	  section.data(19).dtTransOffset = 18;
	
	  ;% controller_template_DWork.is_active_c5_controller_templat
	  section.data(20).logicalSrcIdx = 154;
	  section.data(20).dtTransOffset = 19;
	
	  ;% controller_template_DWork.is_active_c2_controller_templat
	  section.data(21).logicalSrcIdx = 155;
	  section.data(21).dtTransOffset = 20;
	
	  ;% controller_template_DWork.is_active_c40_controller_templa
	  section.data(22).logicalSrcIdx = 156;
	  section.data(22).dtTransOffset = 21;
	
	  ;% controller_template_DWork.is_active_c43_controller_templa
	  section.data(23).logicalSrcIdx = 157;
	  section.data(23).dtTransOffset = 22;
	
	  ;% controller_template_DWork.is_active_c42_controller_templa
	  section.data(24).logicalSrcIdx = 158;
	  section.data(24).dtTransOffset = 23;
	
	  ;% controller_template_DWork.is_active_c41_controller_templa
	  section.data(25).logicalSrcIdx = 159;
	  section.data(25).dtTransOffset = 24;
	
	  ;% controller_template_DWork.is_active_c7_controller_templat
	  section.data(26).logicalSrcIdx = 160;
	  section.data(26).dtTransOffset = 25;
	
	  ;% controller_template_DWork.is_active_c1_controller_templat
	  section.data(27).logicalSrcIdx = 161;
	  section.data(27).dtTransOffset = 26;
	
	  ;% controller_template_DWork.is_active_c26_controller_templa
	  section.data(28).logicalSrcIdx = 162;
	  section.data(28).dtTransOffset = 27;
	
	  ;% controller_template_DWork.is_active_c24_controller_templa
	  section.data(29).logicalSrcIdx = 163;
	  section.data(29).dtTransOffset = 28;
	
	  ;% controller_template_DWork.is_active_c12_controller_templa
	  section.data(30).logicalSrcIdx = 164;
	  section.data(30).dtTransOffset = 29;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 62;
      section.data(62)  = dumData; %prealloc
      
	  ;% controller_template_DWork.isStable
	  section.data(1).logicalSrcIdx = 165;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 166;
	  section.data(2).dtTransOffset = 1;
	
	  ;% controller_template_DWork.isStable_n
	  section.data(3).logicalSrcIdx = 167;
	  section.data(3).dtTransOffset = 2;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_m
	  section.data(4).logicalSrcIdx = 168;
	  section.data(4).dtTransOffset = 3;
	
	  ;% controller_template_DWork.isStable_m
	  section.data(5).logicalSrcIdx = 169;
	  section.data(5).dtTransOffset = 4;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_e
	  section.data(6).logicalSrcIdx = 170;
	  section.data(6).dtTransOffset = 5;
	
	  ;% controller_template_DWork.isStable_i
	  section.data(7).logicalSrcIdx = 171;
	  section.data(7).dtTransOffset = 6;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_h
	  section.data(8).logicalSrcIdx = 172;
	  section.data(8).dtTransOffset = 7;
	
	  ;% controller_template_DWork.isStable_h
	  section.data(9).logicalSrcIdx = 173;
	  section.data(9).dtTransOffset = 8;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_o
	  section.data(10).logicalSrcIdx = 174;
	  section.data(10).dtTransOffset = 9;
	
	  ;% controller_template_DWork.isStable_k
	  section.data(11).logicalSrcIdx = 175;
	  section.data(11).dtTransOffset = 10;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_og
	  section.data(12).logicalSrcIdx = 176;
	  section.data(12).dtTransOffset = 11;
	
	  ;% controller_template_DWork.isStable_o
	  section.data(13).logicalSrcIdx = 177;
	  section.data(13).dtTransOffset = 12;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_c
	  section.data(14).logicalSrcIdx = 178;
	  section.data(14).dtTransOffset = 13;
	
	  ;% controller_template_DWork.isStable_mf
	  section.data(15).logicalSrcIdx = 179;
	  section.data(15).dtTransOffset = 14;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_a
	  section.data(16).logicalSrcIdx = 180;
	  section.data(16).dtTransOffset = 15;
	
	  ;% controller_template_DWork.isStable_g
	  section.data(17).logicalSrcIdx = 181;
	  section.data(17).dtTransOffset = 16;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_ek
	  section.data(18).logicalSrcIdx = 182;
	  section.data(18).dtTransOffset = 17;
	
	  ;% controller_template_DWork.isStable_j
	  section.data(19).logicalSrcIdx = 183;
	  section.data(19).dtTransOffset = 18;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_p
	  section.data(20).logicalSrcIdx = 184;
	  section.data(20).dtTransOffset = 19;
	
	  ;% controller_template_DWork.isStable_od
	  section.data(21).logicalSrcIdx = 185;
	  section.data(21).dtTransOffset = 20;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_em
	  section.data(22).logicalSrcIdx = 186;
	  section.data(22).dtTransOffset = 21;
	
	  ;% controller_template_DWork.isStable_g4
	  section.data(23).logicalSrcIdx = 187;
	  section.data(23).dtTransOffset = 22;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_n
	  section.data(24).logicalSrcIdx = 188;
	  section.data(24).dtTransOffset = 23;
	
	  ;% controller_template_DWork.isStable_c
	  section.data(25).logicalSrcIdx = 189;
	  section.data(25).dtTransOffset = 24;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_ha
	  section.data(26).logicalSrcIdx = 190;
	  section.data(26).dtTransOffset = 25;
	
	  ;% controller_template_DWork.isStable_hz
	  section.data(27).logicalSrcIdx = 191;
	  section.data(27).dtTransOffset = 26;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_l
	  section.data(28).logicalSrcIdx = 192;
	  section.data(28).dtTransOffset = 27;
	
	  ;% controller_template_DWork.isStable_f
	  section.data(29).logicalSrcIdx = 193;
	  section.data(29).dtTransOffset = 28;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_g
	  section.data(30).logicalSrcIdx = 194;
	  section.data(30).dtTransOffset = 29;
	
	  ;% controller_template_DWork.isStable_a
	  section.data(31).logicalSrcIdx = 195;
	  section.data(31).dtTransOffset = 30;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_ga
	  section.data(32).logicalSrcIdx = 196;
	  section.data(32).dtTransOffset = 31;
	
	  ;% controller_template_DWork.isStable_oc
	  section.data(33).logicalSrcIdx = 197;
	  section.data(33).dtTransOffset = 32;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_me
	  section.data(34).logicalSrcIdx = 198;
	  section.data(34).dtTransOffset = 33;
	
	  ;% controller_template_DWork.isStable_hg
	  section.data(35).logicalSrcIdx = 199;
	  section.data(35).dtTransOffset = 34;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_pw
	  section.data(36).logicalSrcIdx = 200;
	  section.data(36).dtTransOffset = 35;
	
	  ;% controller_template_DWork.isStable_oj
	  section.data(37).logicalSrcIdx = 201;
	  section.data(37).dtTransOffset = 36;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_cz
	  section.data(38).logicalSrcIdx = 202;
	  section.data(38).dtTransOffset = 37;
	
	  ;% controller_template_DWork.isStable_nx
	  section.data(39).logicalSrcIdx = 203;
	  section.data(39).dtTransOffset = 38;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_b
	  section.data(40).logicalSrcIdx = 204;
	  section.data(40).dtTransOffset = 39;
	
	  ;% controller_template_DWork.isStable_ke
	  section.data(41).logicalSrcIdx = 205;
	  section.data(41).dtTransOffset = 40;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_d
	  section.data(42).logicalSrcIdx = 206;
	  section.data(42).dtTransOffset = 41;
	
	  ;% controller_template_DWork.isStable_j4
	  section.data(43).logicalSrcIdx = 207;
	  section.data(43).dtTransOffset = 42;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_as
	  section.data(44).logicalSrcIdx = 208;
	  section.data(44).dtTransOffset = 43;
	
	  ;% controller_template_DWork.isStable_b
	  section.data(45).logicalSrcIdx = 209;
	  section.data(45).dtTransOffset = 44;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_o4
	  section.data(46).logicalSrcIdx = 210;
	  section.data(46).dtTransOffset = 45;
	
	  ;% controller_template_DWork.isStable_an
	  section.data(47).logicalSrcIdx = 211;
	  section.data(47).dtTransOffset = 46;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_lb
	  section.data(48).logicalSrcIdx = 212;
	  section.data(48).dtTransOffset = 47;
	
	  ;% controller_template_DWork.isStable_ni
	  section.data(49).logicalSrcIdx = 213;
	  section.data(49).dtTransOffset = 48;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_j
	  section.data(50).logicalSrcIdx = 214;
	  section.data(50).dtTransOffset = 49;
	
	  ;% controller_template_DWork.isStable_bh
	  section.data(51).logicalSrcIdx = 215;
	  section.data(51).dtTransOffset = 50;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_nz
	  section.data(52).logicalSrcIdx = 216;
	  section.data(52).dtTransOffset = 51;
	
	  ;% controller_template_DWork.isStable_hy
	  section.data(53).logicalSrcIdx = 217;
	  section.data(53).dtTransOffset = 52;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_f
	  section.data(54).logicalSrcIdx = 218;
	  section.data(54).dtTransOffset = 53;
	
	  ;% controller_template_DWork.isStable_l
	  section.data(55).logicalSrcIdx = 219;
	  section.data(55).dtTransOffset = 54;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_lo
	  section.data(56).logicalSrcIdx = 220;
	  section.data(56).dtTransOffset = 55;
	
	  ;% controller_template_DWork.isStable_ng
	  section.data(57).logicalSrcIdx = 221;
	  section.data(57).dtTransOffset = 56;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_dn
	  section.data(58).logicalSrcIdx = 222;
	  section.data(58).dtTransOffset = 57;
	
	  ;% controller_template_DWork.isStable_d
	  section.data(59).logicalSrcIdx = 223;
	  section.data(59).dtTransOffset = 58;
	
	  ;% controller_template_DWork.doneDoubleBufferReInit_hm
	  section.data(60).logicalSrcIdx = 224;
	  section.data(60).dtTransOffset = 59;
	
	  ;% controller_template_DWork.FreeFlightPosCtrl_MODE
	  section.data(61).logicalSrcIdx = 225;
	  section.data(61).dtTransOffset = 60;
	
	  ;% controller_template_DWork.poscontroller_MODE
	  section.data(62).logicalSrcIdx = 226;
	  section.data(62).dtTransOffset = 61;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_discretekalmanfilter_k.sfEvent
	  section.data(1).logicalSrcIdx = 227;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_discretekalmanfilter_k.is_active_c27_controller_templa
	  section.data(1).logicalSrcIdx = 228;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(10) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_discretekalmanfilter_k.isStable
	  section.data(1).logicalSrcIdx = 229;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.sf_discretekalmanfilter_k.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 230;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(11) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_discretekalmanfilter_n.sfEvent
	  section.data(1).logicalSrcIdx = 231;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(12) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_discretekalmanfilter_n.is_active_c27_controller_templa
	  section.data(1).logicalSrcIdx = 232;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(13) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_discretekalmanfilter_n.isStable
	  section.data(1).logicalSrcIdx = 233;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.sf_discretekalmanfilter_n.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 234;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(14) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_discretekalmanfilter_m.sfEvent
	  section.data(1).logicalSrcIdx = 235;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(15) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_discretekalmanfilter_m.is_active_c11_Hquad_control_LIB
	  section.data(1).logicalSrcIdx = 236;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(16) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_discretekalmanfilter_m.isStable
	  section.data(1).logicalSrcIdx = 237;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.sf_discretekalmanfilter_m.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 238;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(17) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_runFastGradient_d.sfEvent
	  section.data(1).logicalSrcIdx = 239;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(18) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_runFastGradient_d.is_active_c6_Hquad_control_LIB_
	  section.data(1).logicalSrcIdx = 240;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(19) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_runFastGradient_d.isStable
	  section.data(1).logicalSrcIdx = 241;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.sf_runFastGradient_d.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 242;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(20) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_discretekalmanfilter_b.sfEvent
	  section.data(1).logicalSrcIdx = 243;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(21) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_discretekalmanfilter_b.is_active_c11_Hquad_control_LIB
	  section.data(1).logicalSrcIdx = 244;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(22) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_discretekalmanfilter_b.isStable
	  section.data(1).logicalSrcIdx = 245;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.sf_discretekalmanfilter_b.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 246;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(23) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_runFastGradient.sfEvent
	  section.data(1).logicalSrcIdx = 247;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(24) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_runFastGradient.is_active_c6_Hquad_control_LIB_
	  section.data(1).logicalSrcIdx = 248;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(25) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_runFastGradient.isStable
	  section.data(1).logicalSrcIdx = 249;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.sf_runFastGradient.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 250;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(26) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_MATLABFunction_p.sfEvent
	  section.data(1).logicalSrcIdx = 251;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(27) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_MATLABFunction_p.is_active_c15_controller_templa
	  section.data(1).logicalSrcIdx = 252;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(28) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_MATLABFunction_p.isStable
	  section.data(1).logicalSrcIdx = 253;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.sf_MATLABFunction_p.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 254;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(29) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_generate_X_ref_z.sfEvent
	  section.data(1).logicalSrcIdx = 255;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(30) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_generate_X_ref_z.is_active_c22_controller_templa
	  section.data(1).logicalSrcIdx = 256;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(31) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_generate_X_ref_z.isStable
	  section.data(1).logicalSrcIdx = 257;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.sf_generate_X_ref_z.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 258;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(32) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_generate_X_ref_yaw.sfEvent
	  section.data(1).logicalSrcIdx = 259;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(33) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_generate_X_ref_yaw.is_active_c21_controller_templa
	  section.data(1).logicalSrcIdx = 260;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(34) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_generate_X_ref_yaw.isStable
	  section.data(1).logicalSrcIdx = 261;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.sf_generate_X_ref_yaw.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 262;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(35) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_generate_X_ref_y.sfEvent
	  section.data(1).logicalSrcIdx = 263;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(36) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_generate_X_ref_y.is_active_c20_controller_templa
	  section.data(1).logicalSrcIdx = 264;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(37) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_generate_X_ref_y.isStable
	  section.data(1).logicalSrcIdx = 265;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.sf_generate_X_ref_y.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 266;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(38) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_generate_X_ref_x.sfEvent
	  section.data(1).logicalSrcIdx = 267;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(39) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_generate_X_ref_x.is_active_c19_controller_templa
	  section.data(1).logicalSrcIdx = 268;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(40) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_generate_X_ref_x.isStable
	  section.data(1).logicalSrcIdx = 269;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.sf_generate_X_ref_x.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 270;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(41) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_MATLABFunction.sfEvent
	  section.data(1).logicalSrcIdx = 271;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(42) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_MATLABFunction.is_active_c15_controller_templa
	  section.data(1).logicalSrcIdx = 272;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(43) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_MATLABFunction.isStable
	  section.data(1).logicalSrcIdx = 273;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.sf_MATLABFunction.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 274;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(44) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_MATLABFunction_c.sfEvent
	  section.data(1).logicalSrcIdx = 275;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(45) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_MATLABFunction_c.is_active_c13_controller_templa
	  section.data(1).logicalSrcIdx = 276;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(46) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_MATLABFunction_c.isStable
	  section.data(1).logicalSrcIdx = 277;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.sf_MATLABFunction_c.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 278;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(47) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_discretekalmanfilter.sfEvent
	  section.data(1).logicalSrcIdx = 279;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(48) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_discretekalmanfilter.is_active_c27_controller_templa
	  section.data(1).logicalSrcIdx = 280;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(49) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_discretekalmanfilter.isStable
	  section.data(1).logicalSrcIdx = 281;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.sf_discretekalmanfilter.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 282;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(50) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_MATLABFunction_l5.sfEvent
	  section.data(1).logicalSrcIdx = 283;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(51) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_MATLABFunction_l5.is_active_c13_controller_templa
	  section.data(1).logicalSrcIdx = 284;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(52) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_MATLABFunction_l5.isStable
	  section.data(1).logicalSrcIdx = 285;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.sf_MATLABFunction_l5.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 286;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(53) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_MATLABFunction_e.sfEvent
	  section.data(1).logicalSrcIdx = 287;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(54) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_MATLABFunction_e.is_active_c15_controller_templa
	  section.data(1).logicalSrcIdx = 288;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(55) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_MATLABFunction_e.isStable
	  section.data(1).logicalSrcIdx = 289;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.sf_MATLABFunction_e.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 290;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(56) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_generate_X_ref_z_b.sfEvent
	  section.data(1).logicalSrcIdx = 291;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(57) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_generate_X_ref_z_b.is_active_c22_controller_templa
	  section.data(1).logicalSrcIdx = 292;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(58) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_generate_X_ref_z_b.isStable
	  section.data(1).logicalSrcIdx = 293;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.sf_generate_X_ref_z_b.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 294;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(59) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_generate_X_ref_yaw_h.sfEvent
	  section.data(1).logicalSrcIdx = 295;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(60) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_generate_X_ref_yaw_h.is_active_c21_controller_templa
	  section.data(1).logicalSrcIdx = 296;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(61) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_generate_X_ref_yaw_h.isStable
	  section.data(1).logicalSrcIdx = 297;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.sf_generate_X_ref_yaw_h.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 298;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(62) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_generate_X_ref_y_k.sfEvent
	  section.data(1).logicalSrcIdx = 299;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(63) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_generate_X_ref_y_k.is_active_c20_controller_templa
	  section.data(1).logicalSrcIdx = 300;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(64) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_generate_X_ref_y_k.isStable
	  section.data(1).logicalSrcIdx = 301;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.sf_generate_X_ref_y_k.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 302;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(65) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_generate_X_ref_x_a.sfEvent
	  section.data(1).logicalSrcIdx = 303;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(66) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_generate_X_ref_x_a.is_active_c19_controller_templa
	  section.data(1).logicalSrcIdx = 304;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(67) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_generate_X_ref_x_a.isStable
	  section.data(1).logicalSrcIdx = 305;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.sf_generate_X_ref_x_a.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 306;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(68) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_generate_X_ref_z_l.sfEvent
	  section.data(1).logicalSrcIdx = 307;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(69) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_generate_X_ref_z_l.is_active_c22_controller_templa
	  section.data(1).logicalSrcIdx = 308;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(70) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_generate_X_ref_z_l.isStable
	  section.data(1).logicalSrcIdx = 309;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.sf_generate_X_ref_z_l.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 310;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(71) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_generate_X_ref_yaw_g.sfEvent
	  section.data(1).logicalSrcIdx = 311;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(72) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_generate_X_ref_yaw_g.is_active_c21_controller_templa
	  section.data(1).logicalSrcIdx = 312;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(73) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_generate_X_ref_yaw_g.isStable
	  section.data(1).logicalSrcIdx = 313;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.sf_generate_X_ref_yaw_g.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 314;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(74) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_generate_X_ref_y_a.sfEvent
	  section.data(1).logicalSrcIdx = 315;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(75) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_generate_X_ref_y_a.is_active_c20_controller_templa
	  section.data(1).logicalSrcIdx = 316;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(76) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_generate_X_ref_y_a.isStable
	  section.data(1).logicalSrcIdx = 317;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.sf_generate_X_ref_y_a.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 318;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(77) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_generate_X_ref_x_k.sfEvent
	  section.data(1).logicalSrcIdx = 319;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(78) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_generate_X_ref_x_k.is_active_c19_controller_templa
	  section.data(1).logicalSrcIdx = 320;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(79) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% controller_template_DWork.sf_generate_X_ref_x_k.isStable
	  section.data(1).logicalSrcIdx = 321;
	  section.data(1).dtTransOffset = 0;
	
	  ;% controller_template_DWork.sf_generate_X_ref_x_k.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 322;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(80) = section;
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


  targMap.checksum0 = 1311212718;
  targMap.checksum1 = 2167360693;
  targMap.checksum2 = 1551412072;
  targMap.checksum3 = 3939074620;

