#include <iostream>
#include <libi2c.h>
#include <stdexcept>

class SensorManager {
public:
    SensorManager(const std::string& devicePath) : devicePath_(devicePath) {
        if ((i2c_fd_ = i2c_open(devicePath_.c_str())) < 0) {
            throw std::runtime_error("Failed to open I2C device");
        }
    }

    int readSensor(int address, int reg) {
        if (i2c_set_slave(i2c_fd_, address) < 0) {
            throw std::runtime_error("Failed to set I2C address");
        }
        return i2c_read_byte_data(i2c_fd_, reg);
    }

    ~SensorManager() {
        if (i2c_fd_ >= 0) {
            i2c_close(i2c_fd_);
        }
    }

private:
    std::string devicePath_;
    int i2c_fd_;
};