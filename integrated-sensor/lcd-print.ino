void lcdi_print(){
  lcd.setCursor(0,0);
  lcd.print("Tinggi air:");
  lcd.setCursor(12,0);
  lcd.print(tinggiair1,1);
  lcd.print("m");
  lcd.setCursor(0,1);
  lcd.print("Kelembapan:");
  lcd.print(lembap);
  lcd.print("%");
  lcd.setCursor(0,2);
  lcd.print("Suhu:");
  lcd.print(suhu);
  lcd.print(" 'C");
  lcd.setCursor(0,3);
  lcd.print("Curah Hujan: ");
  lcd.setCursor(12,3);
  lcd.print(counter,3);
  lcd.print("mm");
  delay(50);
}

