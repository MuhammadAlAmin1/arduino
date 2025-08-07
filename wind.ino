unsigned long previousMillis = 0;
const long interval = 10; // 10 milliseconds between readings
const int reading = 100;  // Total number of readings
int count = 0;
long sum = 0;
bool sampling = false;

void setup() {
  Serial.begin(9600);
}

void loop() {
  static bool printed = false;
  unsigned long currentMillis = millis();

  if (!sampling) {
    // Start a new round of sampling
    sum = 0;
    count = 0;
    printed = false;
    sampling = true;
  }

  if (sampling && (currentMillis - previousMillis >= interval)) {
    previousMillis = currentMillis;

    int rawValue = analogRead(12);
    sum += rawValue;
    count++;

    if (count >= reading) {
      float averageRaw = sum / (float)reading;

      // Convert analog reading to wind speed (assuming 0–1023 maps to 0–32.4 m/s)
      float windSpeed = averageRaw;
      // Print formatted wind speed
      Serial.print("Average Wind Speed: ");
      Serial.print(windSpeed, 2); // 2 decimal places
      Serial.println(" K/h");

      sampling = false;
    }
  }
}
