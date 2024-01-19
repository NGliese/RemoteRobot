/*
 * uart_api.hpp
 *
 *  Created on: Jan 4, 2021
 *      Author: espenv
 */

#ifndef MAIN_COMPONENTS_DATA_PROTOCOL_INCLUDE_uart_api_HPP_
#define MAIN_COMPONENTS_DATA_PROTOCOL_INCLUDE_uart_api_HPP_

/*------------------------------------------------------------------------------+
 |   		 	C L A S S   I N F O R M A T I O N                               |
 +------------------------------------------------------------------------------+
 |  ToDo: check auto generated function comment
 |
 |  Function Name:  uart_api.hpp
 |
 |  Author       :  Nikolaj Gliese Pedersen
 |  Email 		 :  <nikolajgliese@tutanota.com>
 |
 |  Description  :  This class, uart_api.hpp, is designed as:
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
 |   		 					INFORMATION         		        |
 +------------------------------------------------------------------------------+
 |
 |  This UART API is the 2nd version of uart developed.
 |  Focus is on applying RAII consept and increases encapsulation
 |  and easy-to-use interface
 |
 |
  +-----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------+
 |   		 					Includes                     		            |
 +------------------------------------------------------------------------------*/


#include "uart_hal.hpp"

/*------------------------------------------------------------------------------+
 |                               Typedef                                        |
 +------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------+
 |   		 					 Class                     		                |
 +------------------------------------------------------------------------------*/

class uart_api
{
#ifdef __UNITTEST__
	friend class friend_uart_api;
#endif
  public:
	uart_api();
	~uart_api();

	bool write(const std::string& str);
	bool read(std::string* str);
	bool updateConfig();

  private:
	bool enableDriver(void);
	bool disableDriver(void);
	uart_hal m_hal;
#ifdef __UNITTEST__
	std::string hidden_string;
#endif
};

/*------------------------------------------------------------------------------+
 |   		 				 Unit Test Class               		                |
 +------------------------------------------------------------------------------*/

#ifdef __UNITTEST__
class friend_uart_api
{
  public:
	explicit friend_uart_api(uart_api* uart_api) : m_sensor{uart_api} {};

	std::string getHiddenString(void)
	{
		return (m_sensor->hidden_string);
	}
	~friend_uart_api(){};

  private:
	uart_api* m_sensor;
};
#endif

#endif /* MAIN_COMPONENTS_DATA_PROTOCOL_INCLUDE_uart_api_HPP_ */
