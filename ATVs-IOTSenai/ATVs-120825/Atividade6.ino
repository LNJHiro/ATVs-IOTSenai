const int botaoPin = 2;
const int ledPin = 13;

bool ledLigado = false;
bool ultimoEstadoBotao = HIGH;

void setup() {
  pinMode(botaoPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
}

void loop() {
  bool estadoBotao = digitalRead(botaoPin);

  // Detecta transição de HIGH para LOW (botão pressionado)
  if (ultimoEstadoBotao == HIGH && estadoBotao == LOW) {
    digitalWrite(ledPin, ledLigado ? HIGH : LOW);
    delay(200); // debounce simples
  }

  ultimoEstadoBotao = estadoBotao;
}
