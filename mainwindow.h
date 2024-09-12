#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "i2c.h"  // Include the I2C header for access to I2C functions

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // Slot for read button
    void on_readButton_clicked();
    
    // Slot for write button
    void on_writeButton_clicked();

    // Slot for blink button
    void on_blinkButton_clicked();
    void on_Configure_clicked();


private:
    Ui::MainWindow *ui;
    int i2c_file; 
    int device_address;  
    QString device;  
    bool configureI2CDevice();
    void closeI2CDevice();
    bool CONFIGURED;
    QString slaveAddressStr = "0x27";
    QString i2cDeviceStr = "2";
    QString regAddressStr = "0x14";
    QString dataStr = "0x01";
    QString blinkDelayStr = "500";
    QString blinkTimesStr = "3";
};

#endif // MAINWINDOW_H

