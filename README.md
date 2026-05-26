
**Monitoring Environmental Conditions Using a Simplified DIY Sensor**

This project is a low-cost Arduino-based environmental monitoring system. It measures and logs temperature, relative humidity, and carbon dioxide concentration in an indoor office environment.

The system uses an Arduino Uno as the main controller, an SHT40 sensor for temperature and relative humidity, an SCD30 sensor for carbon dioxide, temperature, and relative humidity, and a microSD card module for storing the measured data.

**Project Objectives**

1. Build a simple DIY environmental monitoring system.

2. Measure indoor temperature, relative humidity, and CO2 concentration.

3. Store sensor readings automatically on a microSD card.

4. Compare temperature and relative humidity readings from the SHT40 and SCD30 sensors.


**Hardware Used**

| Component | Purpose |
|---|---|
| Arduino Uno R3 | Main microcontroller |
| Adafruit SHT40 Temperature and Humidity Sensor | Measures temperature and relative humidity |
| Adafruit SCD30 CO2, Temperature, and Humidity Sensor | Measures CO2, temperature, and relative humidity |
| MicroSD card breakout board | Saves the data to an SD card |
| 32 GB microSD card | Stores the logged data |
| Breadboard and splitter | Used for connections |

**Wiring Summary**

| Sensor Pin | Arduino Uno Pin |
|---|---|
| VCC/VIN | 5V or 3.3V |
| GND | GND |
| SDA | A4 / SDA |
| SCL | A5 / SCL |


**Required Arduino Libraries**

- Adafruit SHT4x

- Adafruit SCD30

- Adafruit BusIO

- Adafruit Unified Sensor

- SD

- SPI

- Wire

The circuit was designed using Fritzing.

<img width="679" height="417" alt="image" src="https://github.com/user-attachments/assets/39c783f0-0005-4df6-9a12-a1c465fb5a6e" />

**The complete design of the system**


<img width="568" height="258" alt="image" src="https://github.com/user-attachments/assets/7d727316-4d4f-4484-8871-1528412064b4" />


The code for the system is inside [C02_T_RH_and_SD.ino]

**Result Summary**

The system was tested for three days in an office environment. The SHT40 and SCD30 temperature and relative humidity measurements followed similar temporal patterns.

During the experiment, the SCD30 generally measured higher temperature values than the SHT40. The relative humidity values showed the opposite pattern, with the SHT40 generally recording higher humidity values than the SCD30.

The CO2 concentration also changed with room conditions. CO2 values increased when the air conditioner was operating and decreased sharply when it was turned off.



<img width="678" height="462" alt="image" src="https://github.com/user-attachments/assets/aa0c9064-ef38-45a6-97ef-a71dfaadf29c" />









**Note**
- The system logs data every 30 seconds.

- The SHT40 and SCD30 share the same I2C pins.

- The SD card file name should be short, for example DAY4.TXT.

-  Make sure the SD card module chip select pin matches the code. This project uses D10.

- The SD card should be formatted as FAT32.

 **Future Improvements**
- Add a battery or power bank for longer outdoor or indoor monitoring.

- Add a real-time clock module to save actual date and time instead of only millis().

- Add a display screen to show live readings.

- Test the system in different indoor and outdoor environments.

- Compare the sensor readings with reference instruments.
 
**Author**

This project was developed as part of a DIY Sensors for Environmental Monitoring course.
