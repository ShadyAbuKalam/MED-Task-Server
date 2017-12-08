//
// Created by jerry on 12/8/17.
//

#ifndef MED_TASK_SERVER_SYNCRHONOUSEXCELWRAPPER_H
#define MED_TASK_SERVER_SYNCRHONOUSEXCELWRAPPER_H

#include <QMutex>
#include <QString>
#include <xlnt/xlnt.hpp>

class SynchronousExcelWrapper {
public:
    static SynchronousExcelWrapper *getInstance();

    void load(QString path);

    float getValue(unsigned int row_no);

    long long getStamp(unsigned int row_no);

private:
    xlnt::workbook wb;
    QMutex mMutex;

    SynchronousExcelWrapper() = default;

    static SynchronousExcelWrapper *instance;

};


#endif //MED_TASK_SERVER_SYNCRHONOUSEXCELWRAPPER_H
