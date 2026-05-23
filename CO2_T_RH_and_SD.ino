// THIS CODE  READS TEMPERTAURE,RH AND CO2 VALUES FROM THE SENORS 
// AND PRINT UNTO THE SCREEN, LATER STOTRE THE VALUES ON SD CARD

#include <Wire.h>
#include <SPI.h>
#include <SD.h>

#include "Adafruit_SHT4x.h"
#include "Adafruit_SCD30.h"

Adafruit_SHT4x sht4 = Adafruit_SHT4x();
Adafruit_SCD30 scd30;

File dataFile;

const int chipSelect = 10;   // SD card CS pin

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ;
  }

  Wire.begin();

  Serial.println("Starting system...");

  // Start SHT40 sensor
  if (!sht4.begin()) {
    Serial.println("SHT40 not found");
    while (1);
  }

  // Start SCD30 sensor
  if (!scd30.begin()) {
    Serial.println("SCD30 not found");
    while (1);
  }

  // Set SCD30 measurement interval
  scd30.setMeasurementInterval(2);

  // Start SD card
  if (!SD.begin(chipSelect)) {
    Serial.println("SD card failed");
    while (1);
  }

  Serial.println("SD card ready");

  // Write file heading
  dataFile = SD.open("day_5.txt", FILE_WRITE);

  if (dataFile) {
    dataFile.println("millis,SHT40_T_C,SHT40_RH_%,SCD30_CO2_ppm,SCD30_T_C,SCD30_RH_%");
    dataFile.close();
  }

  Serial.println("millis, SHT40_T_C, SHT40_RH_%, SCD30_CO2_ppm, SCD30_T_C, SCD30_RH_%");
}

void loop() {
  float sht40Temp = 0;
  float sht40Hum = 0;

  float scd30CO2 = 0;
  float scd30Temp = 0;
  float scd30Hum = 0;

  // Read temperature and humidity from SHT40
  sensors_event_t humEvent, tempEvent;
  sht4.getEvent(&humEvent, &tempEvent);

  sht40Temp = tempEvent.temperature;
  sht40Hum = humEvent.relative_humidity;

  // Read CO2, temperature, and humidity from SCD30
  if (scd30.dataReady()) {
    if (scd30.read()) {
      scd30CO2 = scd30.CO2;
      scd30Temp = scd30.temperature;
      scd30Hum = scd30.relative_humidity;
    }
  }

  // Print data to Serial Monitor
  Serial.print(millis());
  Serial.print(", ");
  Serial.print(sht40Temp);
  Serial.print(", ");
  Serial.print(sht40Hum);
  Serial.print(", ");
  Serial.print(scd30CO2);
  Serial.print(", ");
  Serial.print(scd30Temp);
  Serial.print(", ");
  Serial.println(scd30Hum);

  // Save data to SD card
  dataFile = SD.open("day_5.txt", FILE_WRITE);

  if (dataFile) {
    dataFile.print(millis());
    dataFile.print(",");
    dataFile.print(sht40Temp);
    dataFile.print(",");
    dataFile.print(sht40Hum);
    dataFile.print(",");
    dataFile.print(scd30CO2);
    dataFile.print(",");
    dataFile.print(scd30Temp);
    dataFile.print(",");
    dataFile.println(scd30Hum);

    dataFile.close();
  } else {
    Serial.println("Error opening day_5.txt");
  }

  // Wait 30 seconds before next reading
  delay(30000);
}
