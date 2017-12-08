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
    ExcelThread(int socketDescriptor, xlnt::workbook *wb, QMutex *shared_lock, QObject *parent = 0);

    void run() override;

signals:

    void error(QTcpSocket::SocketError socketerror);

public slots:

    void readyRead();

    void disconnected();

private:
    QTcpSocket *socket;
    int socketdescriptor;
    QMutex *shared_lock;
    xlnt::workbook *work_book;
};


#endif //MED_TASK_SERVER_EXCELTHREAD_H
