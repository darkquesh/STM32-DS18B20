# STM32 DS18B20 Temperature Sensor Library
**Finally**, a working C Library for interfacing the DS18B20 Temperature Sensor with a STM32 like the STM32L452 (NUCLEO)!

Based on the Library by https://controllerstech.com/ds18b20-and-stm32/

# Usage
Using the Library is very easy. Follow the steps.

0. Enable any general purpose timer like `TIM16`. According to your system clock, set Prescaler and ARR values to make it tick every microsecond.  
> For instance, let's say TIM16 is used with 80 MHz HCLK. To work in the microsecond domain, set the Prescaler value to 80. Since 1/80,000,000 * 80 = 1e-6 sec = 1 us

  ![TIM16 settings in STM32CubeIDE](/assets/tim16_values.JPG)

1. Download the codes to your machine

        git clone https://github.com/darkquesh/STM32-DS18B20.git
   
3. Copy the four files of the src folder to your source / include folder (also `main.c` if you prefer).  
4. Include the two header files 
        
        #include "Timing.h"
        #include "DS18B20.h"  
5. Create a new TIMER object by using a hardware timer. 
        
        TIMER timer;  
6. Create a new DS18B20 object
        
        DS18B20 sensor;

7. Initialise TIMER and DS18B20 sensor  
   
        TIMER_Init(&timer, &htim16);
        DS18B20_Init(&sensor, &timer);
           
8. Use the implemented functions to read the temperature
        
        float temperature = DS18B20_readTemperature(&sensor);


# References
* SparkFun Electronics. “DS18B20 Datasheet”. Programmable Resolution 1-Wire Digital Thermometer Datasheet, https://cdn.sparkfun.com/datasheets/Sensors/Temp/DS18B20.pdf
* vtx22. “VTX22/STM32-DS18B20.” GitHub, https://github.com/vtx22/STM32-DS18B20
* Newton, Alex. “Interfacing DS18B20 Temperature Sensor with STM32.” How To Electronics, 21 Aug. 2022, https://how2electronics.com/interfacing-ds18b20-temperature-sensor-with-stm32/

  
*12/2023*
