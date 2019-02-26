void rain_gauge(){
inputRead = digitalRead(rain_pin);
  if (inputRead == HIGH) {
    currentState = 1;
  }
  else {
    currentState = 0;
  }
  if (currentState != previousState) {
    if (currentState == 1) {
      counter = counter + 0.0704;
    }
  }
  delay(20);
}

