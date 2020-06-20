
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
#include "ServerHeart.h"
#include <QDebug>

ServerHeart::ServerHeart() 
    : m_udpSocket(new QUdpSocket(this))
{
    m_udpSocket->bind(QHostAddress::LocalHost, 2020);
    qDebug("ServerHeart Constructed. \n");
}

ServerHeart::~ServerHeart()
{
    delete m_udpSocket;
    qDebug("ServerHeart Destroyed. \n");
}

void ServerHeart::InitSocket()
{
    connect(m_udpSocket, &QUdpSocket::readyRead,
             this, &ServerHeart::readPendingDatagrams);

 }

void ServerHeart::readPendingDatagrams()
{
    while (m_udpSocket->hasPendingDatagrams()) 
    {
        QNetworkDatagram datagram = m_udpSocket->receiveDatagram();
        processTheDatagram(datagram);
    }
 }

void ServerHeart::processTheDatagram(QNetworkDatagram datagram)
{
    qDebug() << "Data Recieved : " << datagram.data();
}