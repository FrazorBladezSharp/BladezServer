
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
#include <QCoreApplication>

#include "Src/Core/ServerHeart.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
    ServerHeart server;
    
    return a.exec();
}
