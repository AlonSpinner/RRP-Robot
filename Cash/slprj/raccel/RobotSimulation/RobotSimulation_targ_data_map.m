  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
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
    ;% Auto data (rtP)
    ;%
      section.nData     = 35;
      section.data(35)  = dumData; %prealloc
      
	  ;% rtP.ArcLength
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.H
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtP.L
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtP.MActual
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtP.MPlanned
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtP.P0
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtP.Pf
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 8;
	
	  ;% rtP.T
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 11;
	
	  ;% rtP.elbows
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 12;
	
	  ;% rtP.LPFforqdot_Freq
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 14;
	
	  ;% rtP.LPF1forqdot2_Freq
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 15;
	
	  ;% rtP.LPF2forqdot2_Freq
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 16;
	
	  ;% rtP.DiscreteDerivative_ICPrevScaledInput
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 17;
	
	  ;% rtP.InverseDynamicsPD_Kd
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 18;
	
	  ;% rtP.InverseDynamicsPD_Kp
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 21;
	
	  ;% rtP.MinJerkTrajectoryPlanner_Tbreaks
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 24;
	
	  ;% rtP.MinJerkTrajectoryPlanner_Tbreaks_bavenone0d
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 25;
	
	  ;% rtP.LPFforqdot_s0
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 26;
	
	  ;% rtP.LPF1forqdot2_s0
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 27;
	
	  ;% rtP.LPF2forqdot2_s0
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 28;
	
	  ;% rtP.Constant1_Value
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 29;
	
	  ;% rtP.Int_2q_IC
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 30;
	
	  ;% rtP.Int_2qdot_IC
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 33;
	
	  ;% rtP.TSamp_WtEt
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 36;
	
	  ;% rtP.Memory_InitialCondition
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 37;
	
	  ;% rtP.Memory1_InitialCondition
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 38;
	
	  ;% rtP.Constant_Value
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 39;
	
	  ;% rtP.DiscreteTimeIntegrator1_gainval
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 40;
	
	  ;% rtP.DiscreteTimeIntegrator1_gainval_lk5uk2rrci
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 41;
	
	  ;% rtP.DiscreteTimeIntegrator1_gainval_jt1p1klapo
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 42;
	
	  ;% rtP.RateTransition1_InitialCondition
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 43;
	
	  ;% rtP.Step_Time
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 44;
	
	  ;% rtP.Step_Y0
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 45;
	
	  ;% rtP.Step_YFinal
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 46;
	
	  ;% rtP.Quantizer_Interval
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 47;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
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
    nTotSects     = 13;
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
    ;% Auto data (rtB)
    ;%
      section.nData     = 31;
      section.data(31)  = dumData; %prealloc
      
	  ;% rtB.jjv3wr13aa
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtB.g3hbvfsfhp
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 3;
	
	  ;% rtB.ijksz3mwsc
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 4;
	
	  ;% rtB.i1fnqqwanu
	  section.data(4).logicalSrcIdx = 4;
	  section.data(4).dtTransOffset = 7;
	
	  ;% rtB.fx14ydaqio
	  section.data(5).logicalSrcIdx = 5;
	  section.data(5).dtTransOffset = 10;
	
	  ;% rtB.dx4qfoouu3
	  section.data(6).logicalSrcIdx = 6;
	  section.data(6).dtTransOffset = 13;
	
	  ;% rtB.dhnlb4gzje
	  section.data(7).logicalSrcIdx = 7;
	  section.data(7).dtTransOffset = 16;
	
	  ;% rtB.lfrmso4j40
	  section.data(8).logicalSrcIdx = 8;
	  section.data(8).dtTransOffset = 19;
	
	  ;% rtB.fbzun2rgtp
	  section.data(9).logicalSrcIdx = 9;
	  section.data(9).dtTransOffset = 22;
	
	  ;% rtB.mv031dgyem
	  section.data(10).logicalSrcIdx = 10;
	  section.data(10).dtTransOffset = 23;
	
	  ;% rtB.azozh0ni1z
	  section.data(11).logicalSrcIdx = 11;
	  section.data(11).dtTransOffset = 26;
	
	  ;% rtB.itcf1zidza
	  section.data(12).logicalSrcIdx = 12;
	  section.data(12).dtTransOffset = 29;
	
	  ;% rtB.f4mdnihu4k
	  section.data(13).logicalSrcIdx = 13;
	  section.data(13).dtTransOffset = 32;
	
	  ;% rtB.g1obqvlufw
	  section.data(14).logicalSrcIdx = 14;
	  section.data(14).dtTransOffset = 35;
	
	  ;% rtB.jwa5m1quha
	  section.data(15).logicalSrcIdx = 15;
	  section.data(15).dtTransOffset = 38;
	
	  ;% rtB.atgwh4qunb
	  section.data(16).logicalSrcIdx = 16;
	  section.data(16).dtTransOffset = 41;
	
	  ;% rtB.chrv4y5ams
	  section.data(17).logicalSrcIdx = 17;
	  section.data(17).dtTransOffset = 44;
	
	  ;% rtB.m4vjemwhgy
	  section.data(18).logicalSrcIdx = 18;
	  section.data(18).dtTransOffset = 45;
	
	  ;% rtB.c0fkxjxeef
	  section.data(19).logicalSrcIdx = 19;
	  section.data(19).dtTransOffset = 46;
	
	  ;% rtB.bvw24fh042
	  section.data(20).logicalSrcIdx = 20;
	  section.data(20).dtTransOffset = 47;
	
	  ;% rtB.nreersdhrm
	  section.data(21).logicalSrcIdx = 21;
	  section.data(21).dtTransOffset = 48;
	
	  ;% rtB.h4umnby0fu
	  section.data(22).logicalSrcIdx = 22;
	  section.data(22).dtTransOffset = 49;
	
	  ;% rtB.mrs1pmhp1d
	  section.data(23).logicalSrcIdx = 23;
	  section.data(23).dtTransOffset = 50;
	
	  ;% rtB.ndfmx5opo3
	  section.data(24).logicalSrcIdx = 24;
	  section.data(24).dtTransOffset = 53;
	
	  ;% rtB.mt4g2ecmso
	  section.data(25).logicalSrcIdx = 25;
	  section.data(25).dtTransOffset = 56;
	
	  ;% rtB.di5zg3biou
	  section.data(26).logicalSrcIdx = 26;
	  section.data(26).dtTransOffset = 59;
	
	  ;% rtB.enw4u3xr3e
	  section.data(27).logicalSrcIdx = 27;
	  section.data(27).dtTransOffset = 62;
	
	  ;% rtB.fxyjxb2a3b
	  section.data(28).logicalSrcIdx = 28;
	  section.data(28).dtTransOffset = 65;
	
	  ;% rtB.mz0ojksblg
	  section.data(29).logicalSrcIdx = 29;
	  section.data(29).dtTransOffset = 68;
	
	  ;% rtB.ddsa0w12hq
	  section.data(30).logicalSrcIdx = 30;
	  section.data(30).dtTransOffset = 71;
	
	  ;% rtB.l021hpyxvi
	  section.data(31).logicalSrcIdx = 31;
	  section.data(31).dtTransOffset = 74;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.dxs50bidke.pvyobdscrq
	  section.data(1).logicalSrcIdx = 32;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.dgygkhiskz.cxxywhieo5
	  section.data(1).logicalSrcIdx = 33;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.epk3a1n2lr.dkehoz2q2i
	  section.data(1).logicalSrcIdx = 34;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.ej5252hcor.pvyobdscrq
	  section.data(1).logicalSrcIdx = 35;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.oitjezxpmx.cxxywhieo5
	  section.data(1).logicalSrcIdx = 36;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.hnu3zwzkde.dkehoz2q2i
	  section.data(1).logicalSrcIdx = 37;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.dzynjsmsgs.gth0wwswdl
	  section.data(1).logicalSrcIdx = 38;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.p3gwq53bun.gth0wwswdl
	  section.data(1).logicalSrcIdx = 39;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(9) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.f1kcndijvu.pvyobdscrq
	  section.data(1).logicalSrcIdx = 40;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(10) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.e3vd5ofmev.pvyobdscrq
	  section.data(1).logicalSrcIdx = 41;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(11) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.nnubrvj5fv.cxxywhieo5
	  section.data(1).logicalSrcIdx = 42;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(12) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.kalm0nmkn2.dkehoz2q2i
	  section.data(1).logicalSrcIdx = 43;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(13) = section;
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
    nTotSects     = 3;
    sectIdxOffset = 13;
    
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
    ;% Auto data (rtDW)
    ;%
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% rtDW.cn0jcb2rgj
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.h4pprbp2zw
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 3;
	
	  ;% rtDW.bjor124ftp
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 6;
	
	  ;% rtDW.hbhhzhssgt
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 9;
	
	  ;% rtDW.arabdgyja5
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 12;
	
	  ;% rtDW.gtbumdp141
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 15;
	
	  ;% rtDW.nwjbwtsk0s
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 18;
	
	  ;% rtDW.aonnjayrqu
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 19;
	
	  ;% rtDW.gey2dafowy
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 20;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 11;
      section.data(11)  = dumData; %prealloc
      
	  ;% rtDW.f4cgpynrj4.LoggedData
	  section.data(1).logicalSrcIdx = 9;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.p5vastsvrw.AQHandles
	  section.data(2).logicalSrcIdx = 10;
	  section.data(2).dtTransOffset = 2;
	
	  ;% rtDW.f0vm4ehx4o.AQHandles
	  section.data(3).logicalSrcIdx = 11;
	  section.data(3).dtTransOffset = 3;
	
	  ;% rtDW.buw2g0pqmj.AQHandles
	  section.data(4).logicalSrcIdx = 12;
	  section.data(4).dtTransOffset = 4;
	
	  ;% rtDW.pqmhoyu5lv.LoggedData
	  section.data(5).logicalSrcIdx = 13;
	  section.data(5).dtTransOffset = 5;
	
	  ;% rtDW.hnwbshcjdz.LoggedData
	  section.data(6).logicalSrcIdx = 14;
	  section.data(6).dtTransOffset = 7;
	
	  ;% rtDW.e1ux5t5pq4.LoggedData
	  section.data(7).logicalSrcIdx = 15;
	  section.data(7).dtTransOffset = 9;
	
	  ;% rtDW.f220u1tzs1.LoggedData
	  section.data(8).logicalSrcIdx = 16;
	  section.data(8).dtTransOffset = 11;
	
	  ;% rtDW.njf1v3jmtu.LoggedData
	  section.data(9).logicalSrcIdx = 17;
	  section.data(9).dtTransOffset = 13;
	
	  ;% rtDW.hspu4502dq.LoggedData
	  section.data(10).logicalSrcIdx = 18;
	  section.data(10).dtTransOffset = 14;
	
	  ;% rtDW.jwoqu1igx4.LoggedData
	  section.data(11).logicalSrcIdx = 19;
	  section.data(11).dtTransOffset = 16;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% rtDW.gbgkc2rm53
	  section.data(1).logicalSrcIdx = 20;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.aipubp0sep
	  section.data(2).logicalSrcIdx = 21;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
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


  targMap.checksum0 = 4102892843;
  targMap.checksum1 = 2685053547;
  targMap.checksum2 = 2124228778;
  targMap.checksum3 = 1766344491;

