int hasBeenInitialized = 0;

void runAllDCsBackandForth(){
if (hasBeenInitialized == 0){
  BRone = 1;
  BLone = 1;
  TLone = 1;
  TRone = 1;
  hasBeenInitialized = 1;
   Serial.println("HERE");
}

////RunBRDC();
////RunBLDC();
//if (TLone !=2){
RunTLDC();
//}



}


//////////////////////
///RUN DC COMMANDS
//////////////////////////////

///TOP LEFT DC

void RunTLDC(){
  TLstate = digitalRead(TLswitch);
  TLLimitSwitch();
  limitSwitchExecuteTL();

  if (TLone == 1){
    TLleft();
  }
  if (TLone == 0 ){
    TLright();
  }
  if (TLone == 3){
    TLstop();
  }

}

///TOP RIGHT DC



void RunTRDC(){
  TRstate = digitalRead(TRswitch);
  TRLimitSwitch();
  limitSwitchExecuteTR();

  if (TRone == 1){
    TRleft();
  }
  if (TRone == 0 ){
    TRright();
  }
  if (TRone == 3){
    TRstop();
  }
}
/////BOTTOM RIGHT DC

void RunBRDC(){
  BRstate = digitalRead(BRswitch);
  BRLimitSwitch();
   limitSwitchExecuteBR();

  if (BRone == 1){
    BRleft();
  }
  if (BRone == 0 ){
    BRright();
  }
  if (BRone == 3){
    BRstop();
  }
}
/////BOTTOM LEFT

void RunBLDC(){
  BLstate = digitalRead(BLswitch);
  BLLimitSwitch();
   limitSwitchExecuteBL();

  if (BLone == 1){
    BLleft();
  }
  if (BLone == 0 ){
    BLright();
  }
  if (BLone == 3){
    BLstop();
  }
}






