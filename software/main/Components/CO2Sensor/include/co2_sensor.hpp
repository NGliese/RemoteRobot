/*
 * co2_sensor.hpp
 *
 *  Created on: Jan 13, 2021
 *      Author: espenv
 */

#ifndef MAIN_COMPONENTS_SENSOR_INCLUDE_CO2_SENSOR_HPP_
#define MAIN_COMPONENTS_SENSOR_INCLUDE_CO2_SENSOR_HPP_

/*------------------------------------------------------------------------------+
 |   		 	C L A S S   I N F O R M A T I O N                               |
 +------------------------------------------------------------------------------+
 |  ToDo: check auto generated function comment
 |
 |  Function Name:  co2_sensor.hpp
 |
 |  Author       :  Nikolaj Gliese Pedersen
 |  Email 	      :  <nikolajgliese@tutanota.com>
 |
 |  Description  :  This class, co2_sensor.hpp, is designed as:
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
 |   		 					Datasheet Awareness              		        |
 +------------------------------------------------------------------------------+
 |
 |
 |  Datasheet Awareness 1):
 |  	Link:[ ], Jan 13, 2021
 |		Brief:
 |
 |  Datasheet Awareness 2):
 |  	Link:[ ], Jan 13, 2021
 |
 |		Brief:
 |
 |
 |
 |
 |
  +-----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------+
 |   		 					Includes                     		            |
 +------------------------------------------------------------------------------*/



#include "S8LP_Modbus_api.hpp"


#include "../../utils/include/utils.h"

#include "../../Timeservice/include/Timeservice.hpp"
/*------------------------------------------------------------------------------+
 |                               Typedef                                        |
 +------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------+
 |   		 					 Class                     		                |
 +------------------------------------------------------------------------------*/

class co2_sensor final 
{
#ifdef __UNITTEST__
	friend class friend_co2_sensor;
#endif
  public:
	co2_sensor();
	~co2_sensor();
	bool measure(void) ;
	uint16_t getMeasurement(void) ;

  private:
	S8LP_Modbus_api m_modbus;
	uint16_t m_value;
};

/*------------------------------------------------------------------------------+
 |   		 				 Unit Test Class               		                |
 +------------------------------------------------------------------------------*/



#endif /* MAIN_COMPONENTS_SENSOR_INCLUDE_CO2_SENSOR_HPP_ */
