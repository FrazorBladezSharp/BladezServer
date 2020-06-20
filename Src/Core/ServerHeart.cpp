
/* ----------------------------------------------------/
 *
 * Project created by Frazor Sharp : 2020 Jun 20th
 *
 *      Bladez - Qt C++ Version Bladez 1.0
 *      Github : FrazorBladezSharp
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
#include "ServerHeart.h"
#include <QDebug>

ServerHeart::ServerHeart() 
    : m_udpSocket(new QUdpSocket(this))
{
    m_udpSocket->bind(
        QHostAddress::LocalHost, // this needs to be the servers IP Address.
        IN_PORT
    );

    // (TODO:) (FRAZOR) intiialize Services ???

    connect(
        m_udpSocket,
        &QUdpSocket::readyRead,
        this,
        &ServerHeart::readPendingDatagrams
    );

    qDebug(
        "ServerHeart Constructed. \n"
    );
}

ServerHeart::~ServerHeart()
{
    delete m_udpSocket;

    qDebug(
        "ServerHeart Destroyed. \n"
    );
}

void ServerHeart::readPendingDatagrams()
{
    while (m_udpSocket->hasPendingDatagrams()) 
    {
        QNetworkDatagram datagram = 
            m_udpSocket->receiveDatagram();

        processTheDatagram(
            datagram
        );
    }
 }

////////////////////// Private //////////////////////////

// All of the private functions will be the core of the services 
// that we shall offer.
// these all need changing to a generic format.
// need to have a series of numerical services
// and a series of numerical responces.

void ServerHeart::processTheDatagram(QNetworkDatagram datagram)
{
    qDebug() << "Data Recieved : " << datagram.data();
    QByteArray message = datagram.data();
    QHostAddress sender = datagram.senderAddress();
    qDebug() << "Sent By : " << sender;

    // close the client 
    sendDatagrams();
}

void ServerHeart::sendDatagrams()
{
    QByteArray message = CreateTheDatagram();
    QUdpSocket* tempSocket = new QUdpSocket(this);
    tempSocket->bind(QHostAddress::LocalHost, OUT_PORT);
    tempSocket->writeDatagram(message, QHostAddress::LocalHost, 20201);
    qDebug(" Shutdown Datagram Sent. \n");
}

QByteArray ServerHeart::CreateTheDatagram()
{
    QByteArray stuff("0");
    return stuff;
}
