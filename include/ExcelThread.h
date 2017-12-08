//
// Created by jerry on 12/8/17.
//

#ifndef MED_TASK_SERVER_EXCELTHREAD_H
#define MED_TASK_SERVER_EXCELTHREAD_H

#include <QThread>
#include <QTcpSocket>

class ExcelThread : public QThread {
Q_OBJECT

public:
    ExcelThread(int socketDescriptor, QObject *parent = 0);

    void run() override;

signals:

    void error(QTcpSocket::SocketError socketerror);

public slots:

    void readyRead();

    void disconnected();

private:
    QTcpSocket *socket;
    int socketdescriptor;
    SynchronousExcelWrapper *synchronousWrapper;
};


#endif //MED_TASK_SERVER_EXCELTHREAD_H
