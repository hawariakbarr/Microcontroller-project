void ultrasonic1() {
  digitalWrite(trigpin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin1, LOW);

  //pengukuran

  duration1 = pulseIn(echopin1, HIGH);
  waterlevel1 = (duration1 / 2) * 0.000343;

}

