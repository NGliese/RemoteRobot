/***********************************************************************************************+
 *  \brief      BRIEF TEXT
 *  \par
 *  \par        @DETAILS
 *
 *
 *  \li         LIMITATION-TO-CLASS
 *  \li         LIMITATION-TO-CLASS
 *
 *  \note       ANY RELEVANT NOTES
 *
 *  \file       air_sensor.cpp
 *  \author     N.G Pedersen <nikolajgliese@tutanota.com>
 *  \version    1.0
 *  \date       2023
 *  \copyright  --
 *
 *
 ***********************************************************************************************/

#include "../include/air_sensor.hpp"
#include "../../Components/am2320/include/AM2320_Temperature.hpp"
#include "../../Components/am2320/include/AM2320_Humidity.hpp"
#include "../../Components/CO2Sensor/include/co2_sensor.hpp"
#include "../../Components/Timeservice/include/Timeservice.hpp"
#include "../../Components/boards/esp32_boards/include/esp32_env_v1_0.hpp"
//#include "../../Components/uart/include/uart_api.hpp"
//#define DEBUG // default uncommeted

#ifdef DEBUG
static const char* LOG_TAG = "air_sensor";
#endif

air_sensor::air_sensor()
{

}

air_sensor::~air_sensor()
{

}

bool air_sensor::run(void)
{
  //  i2c_conf_t conf{ 100000, esp32_env_v1_0::I2C_SDA, esp32_env_v1_0::I2C_SCLK };
  //  AM2320_Temperature temp = AM2320_Temperature(conf);
  //  AM2320_Humidity hum = AM2320_Humidity(conf);
    co2_sensor co2 = co2_sensor();
   
  //  uart_api uart = uart_api();

    while(1)
    {
        std::cout << "---------------------\n";
        std::cout << "Air sensor\n";
        std::cout << "---------------------\n";
 //       std::cout << "Temperature: " << temp.getMeasurement() << " C\n";
 //       std::cout << "Humidity: " << hum.getMeasurement() << " %\n";
        std::cout << "CO2: " << co2.getMeasurement() << " ppm\n";
        Timeservice::wait_ms(1000);
    }
    return true;
}