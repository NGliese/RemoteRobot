/*
 * ADC_API_ESP32.hpp
 *
 *  Created on: Sep 21, 2021
 *      Author: nikolaj
 */

#ifndef INCLUDE_ADC_API_ESP32_HPP_
#define INCLUDE_ADC_API_ESP32_HPP_

/*------------------------------------------------------------------------------+
 |   		 	C L A S S   I N F O R M A T I O N                               |
 +------------------------------------------------------------------------------+
 |  ToDo: check auto generated function comment
 |
 |  Function Name:  ADC_API_ESP32.hpp
 |
 |  Author       :  Nikolaj Gliese Pedersen
 |  Email 		 :  <nikolajgliese@tutanota.com>
 |
 |  Description  :  This class, ADC_API_ESP32.hpp, is designed as:
 |
 |
 |
 |
 |
 |
 |
 |  version       : 1.0
 |
 |  Return Value  :   return_type
 |
 +-----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------+
 |   		 					Includes                     		            |
 +------------------------------------------------------------------------------*/

#include <stdint.h>
#include <string>
#include "ADCBase.hpp"

#ifdef __ESP32__
#include <driver/adc.h>
#include <esp_adc_cal.h>
#endif

/*------------------------------------------------------------------------------+
 |                               Typedef                                        |
 +------------------------------------------------------------------------------*/

#ifndef __ESP32__
#define adc1_channel_t int
#endif

/**
 * @class ADC interface to use for the ESP32
 *        the class is derived from @see ADCBase
 *
 * @code {.cpp}
 *  //implement a basic adc and measure the value
 *  ADC_API_ESP32::config conf{"adc_test",64,ADC_CHANNEL_1};
 *  ADC_API_ESP32 m_adc{conf};
 *  auto val = m_adc.measureValue();
 * @endcode
 */

/*------------------------------------------------------------------------------+
 |   		 					 Class                     		                |
 +------------------------------------------------------------------------------*/

class ADC_API_ESP32 final : public ADCBase<uint32_t>
{
#ifdef __UNITTEST__
	friend class friend_ADC_API_ESP32;
#endif
  public:
	struct config
	{
		std::string name; ///< name of the device
		size_t samples; ///< amount of samples to average
		adc1_channel_t channel; ///< the channel / gpio pin
		uint32_t vRef = 1107; ///< calibration refereance, lookup
							  ///< $IDF_PATH/components/esptool_py/esptool/espefuse.py --port
							  ///< /dev/ttyUSB0 adc_info
	};
	explicit ADC_API_ESP32(const config& conf);
	~ADC_API_ESP32();
	uint32_t measureValue(void) override;

  private:
	config m_conf;
#ifdef __ESP32__
	esp_adc_cal_characteristics_t m_adc_chars;
	const adc_bits_width_t m_width = ADC_WIDTH_BIT_12;
	const adc_atten_t m_atten = ADC_ATTEN_DB_11;
	const adc_unit_t m_unit = ADC_UNIT_1;
#endif
};

/*------------------------------------------------------------------------------+
 |   		 				 Unit Test Class               		                |
 +------------------------------------------------------------------------------*/

#ifdef __UNITTEST__
class friend_ADC_API_ESP32
{
  public:
	explicit friend_ADC_API_ESP32(ADC_API_ESP32* ADC_API_ESP32) : m_sensor{ADC_API_ESP32} {};

	~friend_ADC_API_ESP32(){};

  private:
	ADC_API_ESP32* m_sensor;
};
#endif

#endif /* INCLUDE_ADC_API_ESP32_HPP_ */
