//
// Created by jerry on 12/6/17.
//

#include "ExcelServer.h"
#include <ExcelThread.h>

ExcelServer::ExcelServer(QString path, QObject *parent) : QTcpServer(parent) {
    this->path = path;
    this->wb.load(this->path.toStdString());

}

void ExcelServer::startServer() {
    QTextStream out(stdout);

    if (!this->listen(QHostAddress::Any, 1234)) {
        out << QString("Unable to start server : %1").arg(this->qTcpServer->errorString()) << endl;
    } else {
        out << "Listening..." << endl;
    }
}

void ExcelServer::incomingConnection(int socketdescriptor) {

    QTextStream out(stdout);
    out << "Client connected" << endl;
    ExcelThread *t = new ExcelThread(socketdescriptor, &this->wb, &this->mMutex, this);

    t->start();

}
