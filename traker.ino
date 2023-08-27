void traker(){
    digitalWrite(4,0); //pin led rosu
    digitalWrite(3,0); //pin led galben
    analogWrite(6,5);  //pin led alb     

  emon1.calcVI(20,2000);         // Calculate all. No.of half wavelengths (crossings), time-out
  emon1.serialprint();           // Print out all variables (realpower, apparent power, Vrms, Irms, power factor)
  
  float realPower       = emon1.realPower;        //extract Real Power into variable
  float apparentPower   = emon1.apparentPower;    //extract Apparent Power into variable
  float powerFActor     = emon1.powerFactor;      //extract Power Factor into Variable
  float supplyVoltage   = emon1.Vrms;             //extract Vrms into Variable
  float Irms            = emon1.Irms;             //extract Irms into Variable
    if (emon1.realPower > 500.00) {  
      if (i<255){
        i++;
      }
    analogWrite(5,i);   
   }

    if (emon1.realPower < 50.00) { 
      if (i>0){
        if (i<256){
          i--;
        }
      }
    Serial.println(i);
    analogWrite(5,i); 
    }
}
