/* pthread/std::thread example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <iostream>

#include "App/include/plc_mock.hpp"
#include "App/include/wifi_test.hpp"
#include "App/include/moist_sensor.hpp"
#include "App/include/air_sensor.hpp"

#include "sdkconfig.h"
#include <driver/gpio.h>
#include <esp_err.h>
#include <esp_log.h>
extern "C" void app_main(void)
{

  //  plc_mock plc;
  //  plc.run();
    std::cout << "Hello World!\n";
    wifi_test wifi;
    wifi.run_http_server();
  
    //air_sensor air;
    //air.run();

}
