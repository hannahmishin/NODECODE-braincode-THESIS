
/////////////////////////////////////
///////BASIC DC LEFT RIGHT STOP
////////////////////


///TOP RIGHT DC
void TRright(){
  digitalWrite(TR1, HIGH);  
  digitalWrite(TR2, LOW);  
  TRone = 0;
}
void TRleft(){ 
  digitalWrite(TR1, LOW);  
  digitalWrite(TR2, HIGH); 
  TRone = 1;
}
void TRstop(){
  digitalWrite(TR1, LOW);  
  digitalWrite(TR2, LOW); 
  TRone = 3;
}



///TOP LEFT DC
void TLleft(){
  digitalWrite(TL1, HIGH);  
  digitalWrite(TL2, LOW);   
  TLone = 1;
}
void TLright(){
  digitalWrite(TL1, LOW);  
  digitalWrite(TL2, HIGH); 
  TLone = 0;
}

void TLstop(){
  digitalWrite(TL1, LOW);  
  digitalWrite(TL2, LOW); 
  TLone = 3;
}






//BOTTOM RIGHT DC
void BRleft(){
  digitalWrite(BR1, HIGH);  
  digitalWrite(BR2, LOW);  
  BRone = 1;
}
void BRright(){
  digitalWrite(BR1, LOW);  
  digitalWrite(BR2, HIGH);   
  BRone = 0;
}

void BRstop(){
  digitalWrite(BR1, LOW);  
  digitalWrite(BR2, LOW);
  BRone = 3;
} 


///BOTTOM LEFT
void BLright(){
  digitalWrite(BL1, HIGH);  
  digitalWrite(BL2, LOW); 
  BLone = 0;
}

void BLleft(){
  digitalWrite(BL1, LOW);  
  digitalWrite(BL2, HIGH);  
  BLone = 1;
}
void BLstop(){
  digitalWrite(BL1, LOW);  
  digitalWrite(BL2, LOW);
  BLone = 3;
}




/////////////////////////////////////
////////////////REVERSE DIRECTION DC
///////////////


///////////////////////////////
//////////////TOP LEFT
///////////////////////////////

///Function to just reverse motor
void TLchangeDir(){
  ChangecounterTL ++;

  Serial.println(ChangecounterTL);

  if (ChangecounterTL > waitTime*10){
    TLchangeDirTemp();
    Serial.println("ChangeDIRCOMMAND");
    ChangecounterTL= 1;
    TLDirState = 0;
  }
}
  

void TLchangeDirTemp(){
  if (TLDirState == 0 && TLone == 0){
     TLchangeDirLeft();
    Serial.println("LEFT");
  
  }

  if (TLDirState == 0 && TLone == 1){
    TLchangeDirRight();
    Serial.println("RIGHT");
  

  }
}

void TLchangeDirLeft(){
  if (TLone == 0){
   // Serial.println("HERE");
    TLleft();
    TLDirState = 1; 
    preDirTL = 0;  
  }

}

void TLchangeDirRight(){
  if (TLone == 1){
   
    TLright();
    TLDirState = 1;
    
    preDirTL = 1;
  }
}


///////////////////////////////
///////////////////TOP RIGHT
///////////////////////////////

void TRchangeDir(){
  ChangecounterTR ++;

  Serial.println(ChangecounterTR);

  if (ChangecounterTR > waitTime*10){
    TRchangeDirTemp();
    Serial.println("ChangeDIRCOMMAND");
    ChangecounterTR= 1;
    TRDirState = 0;
  }
}
  

void TRchangeDirTemp(){
  if (TRDirState == 0 && TRone == 0){
     TRchangeDirLeft();
    Serial.println("LEFT");
  
  }

  if (TRDirState == 0 && TRone == 1){
    TRchangeDirRight();
    Serial.println("RIGHT");
  

  }
}

void TRchangeDirLeft(){
  if (TRone == 0){
   // Serial.println("HERE");
    TRleft();
    TRDirState = 1; 
    preDirTR = 0;  
  }

}

void TRchangeDirRight(){
  if (TRone == 1){
   
    TRright();
    TRDirState = 1;
    
    preDirTR = 1;
  }
}





//////////////////////////////
//////////////BOTTOM RIGHT
///////////////////////////////

void BRchangeDir(){
  ChangecounterBR ++;

  Serial.println(ChangecounterBR);

  if (ChangecounterBR > waitTime*10){
    BRchangeDirTemp();
    Serial.println("ChangeDIRCOMMAND");
    ChangecounterBR= 1;
    BRDirState = 0;
  }
}
  

void BRchangeDirTemp(){
  if (BRDirState == 0 && BRone == 0){
     BRchangeDirLeft();
    Serial.println("LEFT");
  
  }

  if (BRDirState == 0 && BRone == 1){
    BRchangeDirRight();
    Serial.println("RIGHT");
  

  }
}

void BRchangeDirLeft(){
  if (BRone == 0){
   // Serial.println("HERE");
    BRleft();
    BRDirState = 1; 
    preDirBR = 0;  
  }

}

void BRchangeDirRight(){
  if (BRone == 1){
   
    BRright();
    BRDirState = 1;
    
    preDirBR = 1;
  }
}




//////////////////////////////
//////////////BOTTOM LEFT
///////////////////////////////

void BLchangeDir(){
  ChangecounterBL ++;

  Serial.println(ChangecounterBL);

  if (ChangecounterBL > waitTime*10){
    BLchangeDirTemp();
    Serial.println("ChangeDIRCOMMAND");
    ChangecounterBL= 1;
    BLDirState = 0;
  }
}
  

void BLchangeDirTemp(){
  if (BLDirState == 0 && BLone == 0){
     BLchangeDirLeft();
    Serial.println("LEFT");
  
  }

  if (BLDirState == 0 && BLone == 1){
    BLchangeDirRight();
    Serial.println("RIGHT");
  

  }
}

void BLchangeDirLeft(){
  if (BLone == 0){
   // Serial.println("HERE");
    BLleft();
    BLDirState = 1; 
    preDirBL = 0;  
  }

}

void BLchangeDirRight(){
  if (BLone == 1){
   
    BLright();
    BLDirState = 1;
    
    preDirBL = 1;
  }
}



