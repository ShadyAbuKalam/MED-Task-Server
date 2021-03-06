//
// Created by jerry on 12/6/17.
//

#include "ExcelServer.h"
#include <ExcelThread.h>

#define PORT 1234

ExcelServer::ExcelServer(QString path, QObject *parent) : QTcpServer(parent) {
    excelwrapper = SynchronousExcelWrapper::getInstance();
    excelwrapper->load(path);

}

void ExcelServer::startServer() {
    QTextStream out(stdout);

    if (!this->listen(QHostAddress::Any, PORT)) {
        out << QString("Unable to start server : %1").arg(this->qTcpServer->errorString()) << endl;
    } else {
        out << "Listening..." << endl;
    }
}

void ExcelServer::incomingConnection(int socketdescriptor) {

    QTextStream out(stdout);
    out << "Client connected" << endl;
    ExcelThread *t = new ExcelThread(socketdescriptor, this);

    t->start();

}
