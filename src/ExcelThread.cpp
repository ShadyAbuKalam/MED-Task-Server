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

    connect(this->socket, SIGNAL(readyRead()), this, SLOT(readyRead()), Qt::DirectConnection);
    connect(this->socket, SIGNAL(disconnected()), this, SLOT(disconnected()), Qt::DirectConnection);


    exec();
}

void ExcelThread::readyRead() {
    char buff[10];

    this->socket->readLine(buff, sizeof(buff));
    unsigned int i = static_cast<unsigned int>(QString(buff).toInt());
    xlnt::row_t limit = this->synchronousWrapper->getHighestRow();
    for (; i <= limit; ++i) {
        long long stamp = this->synchronousWrapper->getStamp(i);
        float value = this->synchronousWrapper->getValue(i);

        this->socket->write(QString("%1:%2\n").arg(stamp).arg(QString::number(value, 'f', 10)).toAscii());
        this->socket->flush();
        QThread::sleep(1);


    }
    this->socket->disconnectFromHost();
}

void ExcelThread::disconnected() {


    QTextStream out(stdout);
    out << "Client disconnected" << endl;
    this->socket->deleteLater();
    exit(0);
}