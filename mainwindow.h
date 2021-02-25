#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void readSerial();
    void serialPortError(QSerialPort::SerialPortError error);

private:
    Ui::MainWindow *ui;
    QSerialPort *arduino;
    static const quint16 arduino_leonardo_vendor_id = 9025;
    static const quint16 arduino_leonardo_product_id = 32822;
    QString arduino_port_name;
    bool arduino_is_available;
};
#endif // MAINWINDOW_H
