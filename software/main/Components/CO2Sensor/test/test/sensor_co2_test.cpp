/*
 * TEMPLATE.cpp
 *
 *  Created on: Jul 7, 2020
 *      Author: espenv
 */
#include "../../include/co2_sensor.hpp"

#include <iostream>

#include "CppUTest/TestHarness.h"

TEST_GROUP(SNS_CO2_GRP)
{
	co2_sensor m_sensor;
	void setup() {}
	void teardown()
	{
		// Uninit stuff
	}
};

// test init
TEST(SNS_CO2_GRP, notinit)
{
	CHECK_EQUAL(false, m_sensor.measure());
}
