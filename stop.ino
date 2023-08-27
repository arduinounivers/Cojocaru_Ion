void stop(){  
  i=0;  
  digitalWrite(4,1); //pin led rosu
  digitalWrite(3,0); //pin led galben
  analogWrite(6,0);  //pin led alb   
  analogWrite(5,i);
  i=60;   
}      
