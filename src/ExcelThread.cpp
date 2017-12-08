//
// Created by jerry on 12/8/17.
//

#include <xlnt/xlnt.hpp>
#include <QMutex>
#include <SynchronousExcelWrapper.h>
#include "ExcelThread.h"

ExcelThread::ExcelThread(int socketDescriptor, QObject *parent) : QThread(
        parent) {

    this->socketdescriptor = socketDescriptor;
    this->synchronousWrapper = SynchronousExcelWrapper::getInstance();
}

void ExcelThread::run() {
    this->socket = new QTcpSocket();

    if (!this->socket->setSocketDescriptor(this->socketdescriptor)) {
        emit error(this->socket->error());
        return;
    }

//    connect(this->socket,SIGNAL(readyRead()),this,SLOT(readyRead()),Qt::DirectConnection);
    connect(this->socket, SIGNAL(disconnected()), this, SLOT(disconnected()), Qt::DirectConnection);

    for (unsigned int i = 1; i <= 10; ++i) {
        long long stamp = this->synchronousWrapper->getStamp(i);
        float value = this->synchronousWrapper->getValue(i);

        this->socket->write(QString("%1:%2\n").arg(stamp).arg(QString::number(value, 'f', 10)).toAscii());
        this->socket->flush();
        QThread::sleep(1);


    }
    this->socket->disconnectFromHost();

    exec();
}

void ExcelThread::readyRead() {

}

void ExcelThread::disconnected() {

    this->socket->deleteLater();
    exit(0);
}