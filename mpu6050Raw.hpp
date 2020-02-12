#include "hwlib.hpp"
#define MPU6050_ACCEL_XOUT_H       0x3B   // R  
#define MPU6050_ACCEL_XOUT_L       0x3C   // R  
#define MPU6050_ACCEL_YOUT_H       0x3D   // R  
#define MPU6050_ACCEL_YOUT_L       0x3E   // R  
#define MPU6050_ACCEL_ZOUT_H       0x3F   // R  
#define MPU6050_ACCEL_ZOUT_L       0x40   // R  
#define MPU6050_TEMP_OUT_H         0x41   // R  
#define MPU6050_TEMP_OUT_L         0x42   // R  
#define MPU6050_GYRO_XOUT_H        0x43   // R  
#define MPU6050_GYRO_XOUT_L        0x44   // R  
#define MPU6050_GYRO_YOUT_H        0x45   // R  
#define MPU6050_GYRO_YOUT_L        0x46   // R  
#define MPU6050_GYRO_ZOUT_H        0x47   // R  
#define MPU6050_GYRO_ZOUT_L        0x48   // R  
#define MPU6050_PWR_MGMT_1         0x6B   // R/W

class mpu6050Raw{
protected:
    int16_t rawAccelX 
    int16_t rawAccely;
    int16_t rawAccelZ;
    int16_t rawTemp;
    int16_t rawGyroX;
    int16_t rawGyroY ;
    int16_t rawGyroZ;
    uint8_t address;
    hwlib::i2c_bus & bus;

uint8_t readSingleReg(uint8_t registerData){
    bus.i2c_bus::write(address).write(registerData);
    bus.i2c_bus::read(address).read(registerData);
    return registerData;
  }
public:
    mpu6050Raw(hwlib::i2c_bus & bus, uint8_t address=0x68):
    bus(bus),
    address(address)
    {
    wake();
    refresh();
    }

    //! Wakes up the MPU6050.
    /*!
        Writes 0 to the register 0x6B which wakes up the MPU6050.
    */
    virtual void wake(){
        uint8_t wake[2] = { MPU6050_PWR_MGMT_1, 0};
        bus.i2c_bus::write(address).write(wake,2);
    }

     //! Retrieves the latest data from the MPU6050.
    /*!
        Reads the latest reading the MPU6050 made from its gyro, accelerometer and temperature sensor and puts it in the corrosponding variable.
    */
    void refresh(){
        uint8_t data[14]={};
        bus.i2c_bus::write(address).write(MPU6050_ACCEL_XOUT_H);
        bus.i2c_bus::read(address).read(data,14);
        rawAccelX=  (data[0]<<8)+data[1];
        rawAccelY=  (data[2]<<8)+data[3];
        rawAccelZ=  (data[4]<<8)+data[5];
        rawTemp=     (data[6]<<8)+data[7] ;
        rawGyroX=   (data[8]<<8)+data[9];
        rawGyroY=   (data[10]<<8)+data[11];
        rawGyroZ=   (data[12]<<8)+data[13];
    }

    int16_t getRawAccelX(){  //!< returns the last read raw accelerometer value in the x axis.
        return rawAccelX;
    }
    int16_t getRawAccelY(){  //!< returns the last read raw accelerometer value in the y axis.
        return rawAccelY;
    } 
    int16_t getRawAccelZ(){  //!< returns the last read raw accelerometer value in the z axis.
        return rawAccelZ;
    } 

    int16_t GetRawTemp(){     //!< returns the last read raw temperature value.
        return rawTemp;
    }

    int16_t getRawGyroX(){   //!< returns the last read raw gyrometer value in the x axis.
        return rawGyroX;
    }
    int16_t getRawGyroY(){   //!< returns the last read raw gyrometer value in the y axis.
        return rawGyroY;
    }
    int16_t getRawGyroZ(){   //!< returns the last read raw gyrometer value in the z axis.
        return rawGyroZ;
    }
};