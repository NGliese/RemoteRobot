/*
 * TEMPLATE.cpp
 *
 *  Created on: Jul 7, 2020
 *      Author: espenv
 */

#include "../../include/S8LP_Modbus_api.hpp"
#include "CppUTest/TestHarness.h"
#include <iostream>

TEST_GROUP(API_S8_GRP)
{
	S8LP_Modbus_api m_api;
	friend_S8LP_Modbus_api m_friend{&m_api};
	void setup() {}
	void teardown()
	{
		// Uninit stuff
	}
};

// test init
TEST(API_S8_GRP, getStatus)
{
	CHECK_EQUAL(true, m_api.getSensorStatus());
}

// test init
TEST(API_S8_GRP, processValue)
{
	// example input from datasheet, p13
	std::string str = {static_cast<char>(0xFE), static_cast<char>(0x04), static_cast<char>(0x02),
					   static_cast<char>(0x01), static_cast<char>(0x90), static_cast<char>(0xAC),
					   static_cast<char>(0xD8)};
	LONGS_EQUAL(400, m_friend.test_value(str));
}
