/*
 * co2_sensor.cpp
 *
 *  Created on: Jan 13, 2021
 *      Author: espenv
 */

/***********************************************************************************************+
 *  \brief       -- XX -- Library - CPP Source file
 *  \par
 *  \par        @DETAILS
 *
 *
 *  \li         LIMITATION-TO-CLASS
 *  \li         LIMITATION-TO-CLASS
 *
 *  \note       ANY RELEVANT NOTES
 *
 *  \file       co2_sensor.cpp
 *  \author     N.G Pedersen <nikolajgliese@tutanota.com>
 *  \version    1.0
 *  \date       2021
 *  \copyright  --
 *
 *
 ***********************************************************************************************/

#include "../include/co2_sensor.hpp"

//#define DEBUG // default uncommeted

#ifdef DEBUG
static const char* LOG_TAG = "co2_sensor";
#endif

co2_sensor::~co2_sensor() {}

co2_sensor::co2_sensor()  {}

bool co2_sensor::measure(void)
{
#ifdef DEBUG
	LOG_PRINT_INFO(LOG_TAG, ">> co2_sensor::measure >> ");
#endif

	// Safty check

		if(m_modbus.getSensorStatus() != false)
		{
			return false;
		}
		Timeservice::wait_ms(500);
	

	uint16_t tmp = m_modbus.getCO2Level();

	if(tmp == 0)
	{
		return false;
	}

	m_value = tmp;
#ifdef DEBUG
	LOG_PRINT_INFO(LOG_TAG, "<< co2_sensor::measure << ");
#endif

	return true;
}
uint16_t co2_sensor::getMeasurement()
{
#ifdef DEBUG
	LOG_PRINT_INFO(LOG_TAG, ">> co2_sensor::getMeasurement >> ");
#endif
	if(!measure())
	{
		return 0;
	}
	
	return m_value;
}
