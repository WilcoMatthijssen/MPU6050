#include "mpu6050.hpp"
#include <iostream>
#include <cassert>
namespace mpu6050 {



const std::uint8_t Sensor::readSingleReg(const Reg& reg) {
	std::uint8_t data;
#ifdef HWLIB
	// NOT TESTED
	bus.i2c_bus::write(static_cast<unsigned std::uint8_t>(address)).write(static_cast<unsigned std::uint8_t>(reg));
	bus.i2c_bus::read(static_cast<unsigned std::uint8_t>(address)).read(data);
#elif ARDUINO
	//TODO
#else
	data = static_cast<std::uint8_t>(reg);
	std::cout << data << std::endl;
#endif
	return data;
}

const std::int16_t Sensor::readDoubleReg(const Reg& reg) {
	std::int16_t data;
	
#ifdef HWLIB
	// NOT TESTED
	std::uint8_t tmp[2]{ static_cast<std::uint8_t>(reg), data };
	bus.i2c_bus::write(address).write(tmp, 2);
	data = (tmp[0] << 8) + tmp[1]);
#elif ARDUINO
	//TODO
#else
	data = static_cast<std::int16_t>(reg);
	std::cout << data << std::endl;
#endif
	return data;
}

void Sensor::writeSingleReg(const Reg& reg, const std::uint8_t & data) {
#ifdef HWLIB
	// NOT TESTED
	unsigned std::uint8_t tmp[2] = { static_cast<std::uint8_t>(reg), data };
	bus.i2c_bus::write(address).write(tmp, 2);
#elif ARDUINO
	// TODO
#else
	std::cout << static_cast<std::underlying_type<Reg>::type>(reg) << '\t' << data  << std::endl;
#endif
}

Sensor::Sensor(const bool & AD0 =0):address(Addr | AD0) {
	wake();
}

void Sensor::wake() {
	writeSingleReg(Reg::PWR_MGMT_1, 0);
}


const std::int16_t Sensor::getAccelX() {
	return readDoubleReg(Reg::ACCEL_XOUT_H);
}
const std::int16_t Sensor::getAccelY() {
	return readDoubleReg(Reg::ACCEL_YOUT_H);
}
const std::int16_t Sensor::getAccelZ() {
	return readDoubleReg(Reg::ACCEL_ZOUT_H);
}


const std::int16_t Sensor::getGyroX() {
	return readDoubleReg(Reg::GYRO_XOUT_H);
}
const std::int16_t Sensor::getGyroY() {
	return readDoubleReg(Reg::GYRO_YOUT_H);
}
const std::int16_t Sensor::getGyroZ() {
	return readDoubleReg(Reg::GYRO_ZOUT_H);
}


const double Sensor::getTemp() {
	// maybe create function to return raw reading and 2 functions with Celcius and Fahrenheit
	return readDoubleReg(Reg::TEMP_OUT_H) / 340.00 + 36.54;
}

void Sensor::setAccelRange(const AccelRange& range) {
	std::uint8_t config = readSingleReg(Reg::ACCEL_CONFIG) & 0b11100000;
	config |= static_cast<std::underlying_type<AccelRange>::type>(range);
	writeSingleReg(Reg::ACCEL_CONFIG, config);
}

void Sensor::setGyroRange(const GyroRange& range) {
	std::uint8_t config = readSingleReg(Reg::GYRO_CONFIG) & 0b11100000;
	config |= static_cast<std::underlying_type<AccelRange>::type>(range);
	writeSingleReg(Reg::GYRO_CONFIG, config);
}
}