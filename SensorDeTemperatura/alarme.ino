void handleAlarme(AdafruitIO_Data *data){
  String valor = data -> toString();
  Serial.print(F("Valor recebido do feed: "));
  Serial.println(valor);

  if (valor == "true"){
     alarmeAtivo = true;
     Serial.println(F("Alarme ARMADO pelo dash/app"));
     digitalWrite(LED_AMARELO, HIGH);
     digitalWrite(LED_VERDE, LOW);
  }else{
    alarmeAtivo = false;
    Serial.println(F("Alarme DESARMADO pelo dash/app"));
    digitalWrite(LED_AMARELO, LOW);
    digitalWrite(LED_VERDE, HIGH);
  }
}

void ativarAlerta(){
  digitalWrite(LED_AMARELO, LOW);
  digitalWrite(LED_VERDE, LOW);
  digitalWrite(BUZZER_PIN, HIGH);
  digitalWrite(LED_ALARM, HIGH);
}

void desligarAlerta(){
  digitalWrite(BUZZER_PIN, LOW);
  digitalWrite(LED_ALARM, LOW);
}