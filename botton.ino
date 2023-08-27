void set_botton() {
  cont = EEPROM.read(1);    
  if (cont == 1) {     
    if (eprom == 1) { 
      EEPROM.write(1, 2);  
     }   
    }
  if (cont == 2) {     
    if (eprom == 2) {
      EEPROM.write(1, 3);
    }  
    }   
  if (cont == 3) {    
    if (eprom == 3) {
      EEPROM.write(1, 1);
    }
  }
}
