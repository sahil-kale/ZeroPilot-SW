/*
*
* A skeleton for testing the sensor fusion algorithm
*
*/

#include <gtest/gtest.h>
#include "fff.h"

#include "airspeed_Mock.hpp"
#include "IMU_Mock.hpp"
#include "SensorFusion.hpp"


using namespace std;
using ::testing::Test;
using ::testing::_;
using ::testing::SetArgReferee;

/***********************************************************************************************************************
 * Mocks
 **********************************************************************************************************************/
MockIMU imumock;
MockAirspeed airspeedmock;

/***********************************************************************************************************************
 * Variables
 **********************************************************************************************************************/
IMUData_t IMUTestData;
airspeedData_t airspeedTestData;

/***********************************************************************************************************************
 * Tests
 **********************************************************************************************************************/

TEST(SensorFusion, FailedBusyIMUDataReturnsNegative1) {

   	/***********************SETUP***********************/

	IMUTestData.sensorStatus = -1;
	airspeedTestData.sensorStatus = 0;

	SFError_t error;
	SFOutput_t output;

	/********************DEPENDENCIES*******************/
	/********************STEPTHROUGH********************/
	EXPECT_CALL(imumock, GetResult(_))
		.WillOnce(SetArgReferee<0>(&IMUTestData));

	EXPECT_CALL(airspeedmock, GetResult(_))
		.WillOnce(SetArgReferee<0>(&airspeedTestData));
	
	SF_GetResult(&output, &imumock, &airspeedmock);	

	/**********************ASSERTS**********************/

	ASSERT_EQ(error.errorCode, -1);
}

// TEST(SensorFusion, FailedBusyAirspeedDataReturnsNegative1 ) {

//    	/***********************SETUP***********************/

// 	IMUTestData.sensorStatus = 0;
// 	airspeedTestData.sensorStatus = -1;

// 	SFError_t error;
// 	SFOutput_t output;

// 	/********************DEPENDENCIES*******************/
// 	/********************STEPTHROUGH********************/

// 	SF_GetResult(&output, &IMUTestData, &airspeedTestData);	

// 	/**********************ASSERTS**********************/

// 	ASSERT_EQ(error.errorCode, -1);
// }

// TEST(SensorFusion, OldDataReturns1) {

//    	/***********************SETUP***********************/
// 	IMUTestData.isDataNew = 0;
// 	airspeedTestData.sensorStatus = -1;

// 	//Dummy values 
// 	IMUTestData.magx = 0;
// 	IMUTestData.magy = 0;
// 	IMUTestData.magz = 0;
// 	IMUTestData.accx = 0;
// 	IMUTestData.accy = 0;
// 	IMUTestData.accz = 0;
// 	IMUTestData.gyrx = 0;
// 	IMUTestData.gyry = 0;
// 	IMUTestData.gyrz = 0;	


// 	//Dummy values
// 	airspeedTestData.airspeed = 0;

// 	SFError_t error;
// 	SFOutput_t output;

// 	/********************DEPENDENCIES*******************/
// 	/********************STEPTHROUGH********************/

// 	SF_GetResult(&output, &IMUTestData, &airspeedTestData);	

// 	/**********************ASSERTS**********************/

// 	ASSERT_EQ(error.errorCode, 1);
// }
