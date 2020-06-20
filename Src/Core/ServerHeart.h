
/* ----------------------------------------------------/
 *
 * Project created by Frazor Sharp : 2020 Jun 20th
 *
 *      Bladez - Qt C++ Version Bladez 1.0
 *
 * Contact email  : frazor.sharp@virginmail.com
 * Website        : 
 * Twitch         : FrazorBladezSharp
 * Youtube        : Frazor Sharp
 *
 * All code is free to use as you please
 * Please be aware of the Open Source Licence
 * given by Qt    : doc.qt.io/qt-5/opensourcelicence.html
 *
 * ---------------------------------------------------*/
#pragma once 

#include <QObject>
#include <QUdpSocket>
#include <QNetworkDatagram>

class ServerHeart : public QObject
{
    Q_OBJECT

        QUdpSocket* m_udpSocket;

    public:
        explicit ServerHeart();
        ~ServerHeart();

        void InitSocket();

        void readPendingDatagrams();
 
    private:
        void processTheDatagram(QNetworkDatagram datagram);
};