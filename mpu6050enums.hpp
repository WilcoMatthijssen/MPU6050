#ifndef MPU6050ENUMS_HPP
#define MPU6050ENUMS_HPP
#include <cinttypes>
namespace mpu6050 {

/// Enum containing all used mpu6050 registers
enum class Reg : std::uint8_t {
	ACCEL_XOUT_H = 0x3B,	// R
	ACCEL_XOUT_L = 0x3C,	// R
	ACCEL_YOUT_H = 0x3D,	// R
	ACCEL_YOUT_L = 0x3E,	// R
	ACCEL_ZOUT_H = 0x3F,	// R
	ACCEL_ZOUT_L = 0x40,	// R
	TEMP_OUT_H = 0x41,	// R  
	TEMP_OUT_L = 0x42,	// R  
	GYRO_XOUT_H = 0x43,	// R  
	GYRO_XOUT_L = 0x44,	// R  
	GYRO_YOUT_H = 0x45,	// R  
	GYRO_YOUT_L = 0x46,	// R  
	GYRO_ZOUT_H = 0x47,	// R  
	GYRO_ZOUT_L = 0x48,	// R  
	PWR_MGMT_1 = 0x6B,	// R/W
	ACCEL_CONFIG = 0x1C,	// R/W
	GYRO_CONFIG = 0x1B,	// R/W

	EXT_SENS_DATA_00 = 0x49, //R
	EXT_SENS_DATA_01 = 0x4A, //R
	EXT_SENS_DATA_02 = 0x4D, //R
	EXT_SENS_DATA_03 = 0x4E, //R
	EXT_SENS_DATA_04 = 0x4F, //R
	EXT_SENS_DATA_05 = 0x50, //R
	EXT_SENS_DATA_06 = 0x51, //R
	EXT_SENS_DATA_07 = 0x52, //R
	EXT_SENS_DATA_08 = 0x53, //R
	EXT_SENS_DATA_09 = 0x54, //R
	EXT_SENS_DATA_10 = 0x55, //R
	EXT_SENS_DATA_11 = 0x56, //R
	EXT_SENS_DATA_12 = 0x57, //R
	EXT_SENS_DATA_13 = 0x58, //R
	EXT_SENS_DATA_14 = 0x59, //R
	EXT_SENS_DATA_15 = 0x5A, //R
	EXT_SENS_DATA_16 = 0x5B, //R
	EXT_SENS_DATA_17 = 0x5C, //R
	EXT_SENS_DATA_18 = 0x5D, //R
	EXT_SENS_DATA_19 = 0x5E, //R
	EXT_SENS_DATA_20 = 0x5F, //R
	EXT_SENS_DATA_21 = 0x60, //R
	EXT_SENS_DATA_22 = 0x61, //R
	EXT_SENS_DATA_23 = 0x62, //R
};

/// i2c address to reach the mpu6050 sensor with.
constexpr std::uint8_t Addr = 0x68;


/// Enum containing all possible accelerometer range options
enum class AccelRange : std::uint8_t {
	_2G = 0b00000,
	_4G = 0b01000,
	_8G = 0b10000,
	_16G = 0b11000
};

/// Enum containing all possible gyroscope range options
enum class GyroRange : std::uint8_t {
	_250S = 0b00000,
	_500S = 0b01000,
	_1000S = 0b10000,
	_2000S = 0b11000
};
}
#endif // !MPU6050ENUMS_HPP

