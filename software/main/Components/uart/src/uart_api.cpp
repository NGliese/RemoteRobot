/*
 * uart_api.cpp
 *
 *  Created on: Jan 4, 2021
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
 *  \file       uart_api.cpp
 *  \author     N.G Pedersen <nikolajgliese@tutanota.com>
 *  \version    1.0
 *  \date       2021
 *  \copyright  --
 *
 *
 ***********************************************************************************************/

#include "../include/uart_api.hpp"

static bool m_driver_enabled = false;

//#define DEBUG // default uncommeted

#ifdef DEBUG
static const char* LOG_TAG = "uart_api";
#endif


uart_api::uart_api() 
{
	// install driver

	if(!m_driver_enabled)
	{

		updateConfig();
	}
	else
	{
		std::cout << "*** UART is created, but config file ignored due to multipe instances ***"
				  << "\n";
		std::cout << "*** Use   uart_api::updateConfig(const uart_api::config& conf) To update ***"
				  << "\n";
	}
}

uart_api::~uart_api() {}

bool uart_api::write(const std::string& str)
{
#ifdef DEBUG
	LOG_PRINT_INFO(LOG_TAG, ">> uart_api::write >> ");
#endif

#ifdef __UNITTEST__
	hidden_string = str;
#endif
	m_hal.write(str);


#ifdef DEBUG
	LOG_PRINT_INFO(LOG_TAG, "<< uart_api::write << ");
#endif

	return true;
}

bool uart_api::read(std::string* str)
{
#ifdef DEBUG
	LOG_PRINT_INFO(LOG_TAG, ">> uart_api::read >> ");
#endif


	m_hal.read(str);
#ifdef __UNITTEST__
	*str = hidden_string;
#endif

#ifdef DEBUG
	LOG_PRINT_INFO(LOG_TAG, "<< uart_api::read << ");
#endif

	return true;
}

bool uart_api::updateConfig()
{
#ifdef DEBUG
	LOG_PRINT_INFO(LOG_TAG, ">> uart_api::updateConfig >> ");
#endif



	// Executable code:
	if(m_driver_enabled)
	{
		// disable driver
		disableDriver();
	}
	m_hal.initialize();

	enableDriver();


#ifdef DEBUG
	LOG_PRINT_INFO(LOG_TAG, "<< uart_api::updateConfig << ");
#endif

	return true;
}

bool uart_api::enableDriver(void)
{
#ifdef DEBUG
	LOG_PRINT_INFO(LOG_TAG, ">> uart_api::enableDriver >> ");
#endif
	// Executable code:

	// therefor
	if(!m_driver_enabled)
	{
		// we have now initialized the driver
		m_driver_enabled = true;
		m_hal.open();
		return true;
	}
#ifdef DEBUG
	LOG_PRINT_INFO(LOG_TAG, "<< uart_api::enableDriver << ");
#endif

	return false;
}

bool uart_api::disableDriver(void)
{
#ifdef DEBUG
	LOG_PRINT_INFO(LOG_TAG, ">> uart_api::disableDriver >> ");
#endif
	// Executable code:
	// therefor
	if(m_driver_enabled)
	{
		// we have now disabled the driver
		m_driver_enabled = false;

		m_hal.close();
		return true;
	}

#ifdef DEBUG
	LOG_PRINT_INFO(LOG_TAG, "<< uart_api::disableDriver << ");
#endif

	return false;
}
