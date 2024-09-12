#ifndef I2C_H
#define I2C_H

#include <linux/i2c-dev.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string>
#include <iostream>

class I2C {
public:

    I2C(const std::string& device, uint8_t slave_address)
        : device(device), slave_address(slave_address), i2c_file(-1) {
        openDevice();
        setSlaveAddress();
    }

    ~I2C() {
        closeDevice();
    }


    bool openDevice() {
        std::cout << device;
        i2c_file = open(device.c_str(), O_RDWR);
        if (i2c_file < 0) {
            perror("Failed to open I2C device");
            return false;
        }
        return true;
    }

    bool setSlaveAddress() {
        std::cout << slave_address;
        if (ioctl(i2c_file, I2C_SLAVE, slave_address) < 0) {
            perror("Failed to set I2C slave address");
            return false;
        }
        return true;
    }


    void closeDevice() {
        if (i2c_file >= 0) {
            close(i2c_file);
        }
    }


    bool writeData(uint8_t reg, uint8_t* data, size_t length) {
        uint8_t* buffer = (uint8_t*)malloc(length + 1);
        if (!buffer) {
            perror("Failed to allocate memory");
            return false;
        }

        buffer[0] = reg;
        for (size_t i = 0; i < length; i++) {
            buffer[i + 1] = data[i];
        }

        ssize_t result = write(i2c_file, buffer, length + 1);
        free(buffer);
        return result == static_cast<ssize_t>(length + 1);
    }

    bool readData(uint8_t reg, uint8_t* buffer, size_t length) {
        if (write(i2c_file, &reg, 1) != 1) {
            perror("Failed to write register address");
            return false;
        }

        ssize_t result = read(i2c_file, buffer, length);
        return result == static_cast<ssize_t>(length);
    }


    bool writeByte(uint8_t reg, uint8_t value) {
        return writeData(reg, &value, 1);
    }


    bool readByte(uint8_t reg, uint8_t* value) {
        return readData(reg, value, 1);
    }


    void delay_set(unsigned int milliseconds) {
        usleep(milliseconds * 1000);
    }

    void blinkLED(uint16_t delay_ms, uint8_t led_reg, uint8_t times) {
        for (uint8_t i = 0; i < times; ++i) {
            uint8_t on_value = 1;
            if (!writeByte(led_reg, on_value)) {
                std::cerr << "Failed to turn LED on\n";
                return;
            }
            delay_set(delay_ms);
            
            uint8_t off_value = 0;
            if (!writeByte(led_reg, off_value)) {
                std::cerr << "Failed to turn LED off\n";
                return;
            }
            delay_set(delay_ms);
        }
    }

private:
    std::string device;
    uint8_t slave_address;
    int i2c_file;
};

#endif  // I2C_H

