void set_botton() {
  Serial.print("Stare button:  ");
  Serial.println(buttonState);
  cont = EEPROM.read(1);    
  Serial.print("Cont:  ");
  Serial.println(cont);   
  if (cont == 1) {     
    if (eprom == 1) { 
      EEPROM.write(1, 2);  
      //delay(1000); 
     }   
    }
  if (cont == 2) {     
    if (eprom == 2) {
      EEPROM.write(1, 3);
      //delay(1000); 
    }  
    }   
  if (cont == 3) {    
    if (eprom == 3) {
      EEPROM.write(1, 1);
      //delay(1000);  
    }
  }
}
