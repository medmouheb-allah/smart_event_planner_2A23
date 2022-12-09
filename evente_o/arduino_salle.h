#ifndef ARDUINO_SALLE_H
#define ARDUINO_SALLE_H
#include "QtSerialPort/QSerialPort"
#include "QtSerialPort/qserialportinfo.h"
#include<QDebug>
#include<QSqlQueryModel>




class arduino
{
public:

    arduino();
    int connect_arduino();
    int close_arduino();
    int write_to_arduino(QByteArray);
    QByteArray read_from_arduino();
    QSerialPort* getserial(){return serial;};
    QString getarduino_port_name(){return arduino_port_name;};
   // QSqlQueryModel * afficher() ;

public:
    QSerialPort *serial;
    static const quint16 arduino_uno_vendor_id=9025;
    static const quint16 arduino_uno_producy_id=67;
    QString arduino_port_name;
    bool arduino_is_available;
    QByteArray data ;


};




#endif // ARDUINO_SALLE_H
