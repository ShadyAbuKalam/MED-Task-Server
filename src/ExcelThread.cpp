//
// Created by jerry on 12/8/17.
//

#include <xlnt/xlnt.hpp>
#include <QMutex>
#include "ExcelThread.h"

ExcelThread::ExcelThread(int socketDescriptor, xlnt::workbook *wb, QMutex *shared_lock, QObject *parent) : QThread(
        parent) {

    this->socketdescriptor = socketDescriptor;
    this->work_book = wb;
    this->shared_lock = shared_lock;
}

void ExcelThread::run() {
    this->socket = new QTcpSocket();

    if (!this->socket->setSocketDescriptor(this->socketdescriptor)) {
        emit error(this->socket->error());
        return;
    }

//    connect(this->socket,SIGNAL(readyRead()),this,SLOT(readyRead()),Qt::DirectConnection);
    connect(this->socket, SIGNAL(disconnected()), this, SLOT(disconnected()), Qt::DirectConnection);

    for (int i = 1; i <= 10; ++i) {
        long long stamp;
        float value;
        {
            QMutexLocker(this->shared_lock);
            stamp = this->work_book->active_sheet().cell(1, i).value<long long>();
            value = this->work_book->active_sheet().cell(1, i).value<float>();

        }
        this->socket->write(QString("%1 - %2\n").arg(stamp).arg(value).toAscii());
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