const int delay_time = 250;

// Define los puertos del arduinos conectados a la la matriz
const int puertosDisponibles[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
const int num_puertos = sizeof(puertosDisponibles) / sizeof(puertosDisponibles[0]);

const int num_filaXcolumna = num_puertos / 2;

//filas positivas
int puertosFilas[num_filaXcolumna];
//columnas negativas
int puertosColumnas[num_filaXcolumna];

void setup() {
  configurarPuertos();
  apagarPuertos();
}

void loop() {
  for (int i = 1+1; i <= num_filaXcolumna+1; i++) {
    digitalWrite(puertosDisponibles[i], HIGH);
    delay(delay_time);
    digitalWrite(puertosDisponibles[i], LOW);
    delay(delay_time);
  }
}

void separarFilasColumnas() {
  // Asigna la primera mitad de puertosDisponibles como filas y la segunda como columnas
  for (int i = 0; i < num_filaXcolumna; i++) {
    puertosFilas[i] = puertosDisponibles[i];
    puertosColumnas[i] = puertosDisponibles[i + num_filaXcolumna];
  }
}

void configurarPuertos() {
  separarFilasColumnas();

  for (int i = 0; i < num_filaXcolumna; i++) {
    pinMode(puertasFilas[i], OUTPUT);
    pinMode(puertasColumnas[i], OUTPUT);
  }
}

void apagarPuertos() {
  for (int i = 0; i < num_puertos; i++) {
    digitalWrite(puertosFilas[i], LOW);
    digitalWrite(puertosColumnas[i], HIGH);
  }
}
