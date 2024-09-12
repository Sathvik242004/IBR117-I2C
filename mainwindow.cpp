#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "i2c.h"
#include <QMessageBox>
#include <QString>

I2C* i2cDevice = nullptr;

bool CONFIGURED = false;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->slaveAddressEdit->setText(slaveAddressStr);
    ui->i2cDeviceEdit->setText(i2cDeviceStr);
    ui->regAddressEdit->setText(regAddressStr);
    ui->dataEdit->setText(dataStr);
    ui->blinkDelayEdit->setText(blinkDelayStr);
    ui->blinkTimesEdit->setText(blinkTimesStr);


}

MainWindow::~MainWindow()
{
    closeI2CDevice();
    delete ui;
}

void MainWindow::closeI2CDevice() {
    if (i2cDevice) {
        delete i2cDevice;
        i2cDevice = nullptr;
    }
}

void MainWindow::on_Configure_clicked() {
    std::string basePath = "/dev/i2c-";
    int deviceNumber = ui->i2cDeviceEdit->text().toInt();
    std::string device = basePath + std::to_string(deviceNumber);
    uint8_t slaveAddress = static_cast<uint8_t>(ui->slaveAddressEdit->text().toUInt(nullptr, 16));

    closeI2CDevice();
    i2cDevice = new I2C(device, slaveAddress);
    if (i2cDevice->writeByte(0x00, 0x00)) {
        CONFIGURED = true;
        ui->outputText->setText("I2C device configured successfully.");
    } else {
        CONFIGURED = false;
        ui->outputText->setText("Failed to configure I2C device.");
    }
}

void MainWindow::on_readButton_clicked()
{
    if (!CONFIGURED || !i2cDevice) {
        ui->outputText->setText("I2C device is not configured.");
        return;
    }

    uint8_t reg = static_cast<uint8_t>(ui->regAddressEdit->text().toUInt(nullptr, 16));
    uint8_t buffer;
    if (!i2cDevice->readByte(reg, &buffer)) {
        ui->outputText->setText("I2C read failed.");
    } else {
        ui->outputText->setText(QString::number(buffer, 16).toUpper());
    }
}

void MainWindow::on_writeButton_clicked()
{
    if (!CONFIGURED || !i2cDevice) {
        ui->outputText->setText("I2C device is not configured.");
        return;
    }

    uint8_t reg = static_cast<uint8_t>(ui->regAddressEdit->text().toUInt(nullptr, 16));
    uint8_t data = static_cast<uint8_t>(ui->dataEdit->text().toUInt(nullptr, 16));
    if (!i2cDevice->writeByte(reg, data)) {
        ui->outputText->setText("I2C write failed.");
    } else {
        ui->outputText->setText("I2C write succeeded.");
    }
}

void MainWindow::on_blinkButton_clicked()
{
    if (!CONFIGURED || !i2cDevice) {
        ui->outputText->setText("I2C device is not configured.");
        return;
    }

    uint8_t reg = static_cast<uint8_t>(ui->regAddressEdit->text().toUInt(nullptr, 16));
    unsigned int delayMs = ui->blinkDelayEdit->text().toUInt();
    uint8_t times = static_cast<uint8_t>(ui->blinkTimesEdit->text().toUInt());

    // Call the blinkLED function from the I2C class
    i2cDevice->blinkLED(delayMs, reg, times);

    ui->outputText->setText("Blinking completed.");
}

