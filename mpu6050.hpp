#ifndef MPU6050_HPP
#define MPU6050_HPP
#include "mpu6050enums.hpp"


namespace mpu6050 {

/// @brief  Class to interface to the MPU6050 sensor using i2c.
/// @author Wilco Matthijssen
class Sensor {
 protected:
	std::uint8_t address;

	/// @brief   Reads a single register on the sensor
    /// @details Reads information located on the given reg on the sensor and returns it.
    /// @param   reg		Reg that needs to be read.
    /// @return  const std::uint8_t
	const std::uint8_t readSingleReg(const Reg& reg);

	/// @brief   Reads a two registers on the sensor
	/// @details Reads information located on the given reg and the one next to it on the sensor and returns it.
	/// @param   reg		First Reg that needs to be read.
	/// @return  const std::int16_t
	const std::int16_t readDoubleReg(const Reg& reg);

	/// @brief   Writes data to the register.
	/// @details Writes data to the given reg on the Sensor.
	/// @param   reg		Reg that needs to be read.
	/// @param	 data		data that needs to be written to the Sensor
	/// @return  void
	void writeSingleReg(const Reg& reg, const std::uint8_t& data);

 public:

	/// @brief   Constructs a Sensor object.
	/// @details Wakes the device using the wake() function. 
	/// @param   AD0	status of AD0 pin on the MPU6050. by default false i.e. AD0 is connected to ground.
	/// @return  void
	Sensor(const bool &AD0); // Maybe change Address to a bool since it only has 2 options and do bitwise operation in constexpr if possible.


	/// @brief   Wakes up the sensor.
	/// @details Writes the wake command to the Sensor. 
	/// @details The sensor is in sleep mode on power up.
	/// @return  void
	void wake();

	/// @brief	 Get accelerometer x-axis.
	/// @details Gets the accelerometer reading from the Sensor in the x-axis directly using i2c.
	/// @return  const std::int16_t
	const std::int16_t getAccelX();

	/// @brief   Get accelerometer y-axis.
	/// @details Gets the accelerometer reading from the Sensor in the y-axis directly using i2c.
	/// @return  const std::int16_t
	const std::int16_t getAccelY();

	/// @brief   Get accelerometer z-axis.
	/// @details Gets the accelerometer reading from the Sensor in the z-axis directly using i2c.
	/// @return  const std::int16_t
	const std::int16_t getAccelZ();



	/// @brief   Get gyroscope x-axis.
	/// @details Gets the gyroscope reading from the Sensor in the x-axis directly using i2c.
	/// @return  const std::int16_t
	const std::int16_t getGyroX();

	/// @brief   Get gyroscope y-axis.
	/// @details Gets the gyroscope reading from the Sensor in the y-axis directly using i2c.
	/// @return  const std::int16_t
	const std::int16_t getGyroY();

	/// @brief   Get gyroscope z-axis.
	/// @details Gets the gyroscope reading from the Sensor in the z-axis directly using i2c.
	/// @return  const std::int16_t
	const std::int16_t getGyroZ();


	/// @brief   Get temprature in Celcius.
	/// @details Reads the temperature reading from the Sensor and converts it to Celcius.
	/// @return  const double
	const double getTemp();

	/// @brief   Sets the AccelRange.
	/// @details Writes the desired accelerometer range to the Sensor.
	/// @param   range	AccelRange desired for the Sensor.
	/// @return  void
	void setAccelRange(const AccelRange& range);

	/// @brief   Sets the GyroRange.
	/// @details Writes the desired gyroscope range to the Sensor.
	/// @param   range	GyroRange desired for the sensor.
	/// @return  void
	void setGyroRange (const GyroRange&  range);


};

}
#endif // !MPU6050_HPP

