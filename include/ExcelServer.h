//
// Created by jerry on 12/6/17.
//

#ifndef MED_TASK_SERVER_SERVER_H
#define MED_TASK_SERVER_SERVER_H

#include <xlnt/xlnt.hpp>
#include <QTcpServer>
#include <QMutex>

class ExcelServer : public QTcpServer {

Q_OBJECT

private:
    xlnt::workbook wb;
    QMutex mMutex;
    QString path;
    QTcpServer *qTcpServer;
public:
    explicit ExcelServer(QString path, QObject *parent = 0);

    void startServer();

protected:
    void incomingConnection(int socketDescriptor) override;
};


#endif //MED_TASK_SERVER_SERVER_H
