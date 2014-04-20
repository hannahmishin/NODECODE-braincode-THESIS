

////////////
////////////DC LIMIT SWITCH SHIT
/////////////////////

///////////////////
///TOP LEFT DC
//////////////////

void TLLimitSwitch(){

  if (TLstate == HIGH && switchHitTL == false){
    switchHitTL = true;
     TLDirState = 0; 
    executeLimitSwitchTL = false; ///resetting auto run command in case last time limit switch was hit, the resume running command was not executed
    Serial.println ("SWITCH HIT");
  }

  if (switchHitTL == true){
    if (SwitchcounterTL < waitTime){
      TLchangeDirTemp();
      Serial.println("CHANGEDIRTEMP");
      SwitchcounterTL++;
   
    }
    if (SwitchcounterTL >= waitTime){
      TL= true;
    }
  }

  if (TL == true){
    TLstop();
    Serial.println("STOP");
    TL = false;
    switchHitTL = false;
    TLone = 2; //Sets TLone to Null
    SwitchcounterTL = 0;
    ///resets ability to change DIR
    Serial.println("SWITCHRESET");
    executeLimitSwitchTL = true;
  } 

}


///this function reverses the DC after limit switch has been hit

void limitSwitchExecuteTL(){

  if (executeLimitSwitchTL) { ///gets set to true after limit switch has stopped motor
   
    if (switchHitTL == true){
      TLone == 3;
      
    }
    
    ResumecounterTL++;
    //Serial.println(ResumecounterTL);

  }


  if (ResumecounterTL >= 100){
   if (preDirTL == 0){
     
    TLone = 1;
   }
   
  if (preDirTL == 1){
    TLone = 0;
  }
  if (ResumecounterTL >= 110){ ///set the preDirTL to accurate number
     if (preDirTL == 1){
     preDirTL == 0;
  }
       if (preDirTL == 0){
     preDirTL == 1;
  }
    
    
    Serial.println("PREDIRRESET");
    Serial.println(preDirTL);
    
    TLDirState = 0; 
    ResumecounterTL = 1;
    executeLimitSwitchTL  = false;
    Serial.println("reverse after switch");
    
  }
}
}

////////////////////////
//TOP RIGHT DC
///////////////////////

void TRLimitSwitch(){

  if (TRstate == HIGH && switchHitTR == false){
    switchHitTR = true;
     TRDirState = 0; 
    executeLimitSwitchTR = false; ///resetting auto run command in case last time limit switch was hit, the resume running command was not executed
    Serial.println ("SWITCH HIT");
  }

  if (switchHitTR == true){
    if (SwitchcounterTR < waitTime){
      TRchangeDirTemp();
      Serial.println("CHANGEDIRTEMP");
      SwitchcounterTR++;
   
    }
    if (SwitchcounterTR >= waitTime){
      TR= true;
    }
  }

  if (TR == true){
    TRstop();
    Serial.println("STOP");
    TR = false;
    switchHitTR = false;
    TRone = 2; //Sets TLone to Null
    SwitchcounterTR = 0;
    ///resets ability to change DIR
    Serial.println("SWITCHRESET");
    executeLimitSwitchTR = true;
  } 

}


///this function reverses the DC after limit switch has been hit

void limitSwitchExecuteTR(){

  if (executeLimitSwitchTR) { ///gets set to true after limit switch has stopped motor
   
    if (switchHitTR == true){
      TRone == 3;
      
    }
    
    ResumecounterTR++;
    //Serial.println(ResumecounterTL);

  }


  if (ResumecounterTR >= 100){
   if (preDirTR == 0){
     
    TRone = 1;
   }
   
  if (preDirTR == 1){
    TRone = 0;
  }
  if (ResumecounterTR >= 110){ ///set the preDirTL to accurate number
     if (preDirTR == 1){
     preDirTR == 0;
  }
       if (preDirTR == 0){
     preDirTR == 1;
  }
    
    
    Serial.println("PREDIRRESET");
    Serial.println(preDirTR);
    
    TRDirState = 0; 
    ResumecounterTR = 1;
    executeLimitSwitchTR  = false;
    Serial.println("reverse after switch");
    
  }
}
}

///////////////////////////////
//BOTTOM RIGHT DC
////////////////////////////////

void BRLimitSwitch(){

  if (BRstate == HIGH && switchHitBR == false){
    switchHitBR = true;
     BRDirState = 0; 
    executeLimitSwitchBR = false; ///resetting auto run command in case last time limit switch was hit, the resume running command was not executed
    Serial.println ("SWITCH HIT");
  }

  if (switchHitBR == true){
    if (SwitchcounterBR < waitTime){
      BRchangeDirTemp();
      Serial.println("CHANGEDIRTEMP");
      SwitchcounterBR++;
   
    }
    if (SwitchcounterBR >= waitTime){
      BR= true;
    }
  }

  if (BR == true){
    BRstop();
    Serial.println("STOP");
    BR = false;
    switchHitBR = false;
    BRone = 2; //Sets TLone to Null
    SwitchcounterBR = 0;
    ///resets ability to change DIR
    Serial.println("SWITCHRESET");
    executeLimitSwitchBR = true;
  } 

}


///this function reverses the DC after limit switch has been hit

void limitSwitchExecuteBR(){

  if (executeLimitSwitchBR) { ///gets set to true after limit switch has stopped motor
   
    if (switchHitBR == true){
      BRone == 3;
      
    }
    
    ResumecounterBR++;
    //Serial.println(ResumecounterTL);

  }


  if (ResumecounterBR >= 100){
   if (preDirBR == 0){
     
    BRone = 1;
   }
   
  if (preDirBR == 1){
    BRone = 0;
  }
  if (ResumecounterBR >= 110){ ///set the preDirTL to accurate number
     if (preDirBR== 1){
     preDirBR == 0;
  }
       if (preDirBR == 0){
     preDirBR == 1;
  }
    
    
    Serial.println("PREDIRRESET");
    Serial.println(preDirBR);
    
    BRDirState = 0; 
    ResumecounterBR = 1;
    executeLimitSwitchBR  = false;
    Serial.println("reverse after switch");
    
  }
}
}

////////////////////////////////////
//BOTTOM LEFT DC
/////////////////////////////////

void BLLimitSwitch(){

  if (BLstate == HIGH && switchHitBL == false){
    switchHitBL = true;
     BLDirState = 0; 
    executeLimitSwitchBL = false; ///resetting auto run command in case last time limit switch was hit, the resume running command was not executed
    Serial.println ("SWITCH HIT");
  }

  if (switchHitBL == true){
    if (SwitchcounterBL < waitTime){
      BLchangeDirTemp();
      Serial.println("CHANGEDIRTEMP");
      SwitchcounterBL++;
   
    }
    if (SwitchcounterBL >= waitTime){
      BL= true;
    }
  }

  if (BL == true){
    BLstop();
    Serial.println("STOP");
    BL = false;
    switchHitBL = false;
    BLone = 2; //Sets TLone to Null
    SwitchcounterBL = 0;
    ///resets ability to change DIR
    Serial.println("SWITCHRESET");
    executeLimitSwitchBL = true;
  } 

}


///this function reverses the DC after limit switch has been hit

void limitSwitchExecuteBL(){

  if (executeLimitSwitchBL) { ///gets set to true after limit switch has stopped motor
   
    if (switchHitBL == true){
      BLone == 3;
      
    }
    
    ResumecounterBL++;
    //Serial.println(ResumecounterTL);

  }


  if (ResumecounterBL >= 100){
   if (preDirBL == 0){
     
    BLone = 1;
   }
   
  if (preDirBL == 1){
    BLone = 0;
  }
  if (ResumecounterBL >= 110){ ///set the preDirTL to accurate number
     if (preDirBL == 1){
     preDirBL == 0;
  }
       if (preDirBL == 0){
     preDirBL == 1;
  }
    
    
    Serial.println("PREDIRRESET");
    Serial.println(preDirBL);
    
    BLDirState = 0; 
    ResumecounterBL = 1;
    executeLimitSwitchBL  = false;
    Serial.println("reverse after switch");
    
  }
}
}


//////////////////////////////////////////////////////////////////////////














