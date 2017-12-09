//
// Created by jerry on 12/8/17.
//

#include "SynchronousExcelWrapper.h"


void SynchronousExcelWrapper::load(QString path) {
    wb.load(path.toStdString());

}

SynchronousExcelWrapper *SynchronousExcelWrapper::getInstance() {

    if (instance == nullptr)
        instance = new SynchronousExcelWrapper();

    return instance;
}

float SynchronousExcelWrapper::getValue(unsigned int row_no) {
    QMutexLocker mutexLocker(&this->mMutex);
    float x = this->wb.active_sheet().cell(2, row_no).value<float>();
    return x;
}

xlnt::row_t SynchronousExcelWrapper::getHighestRow() {

    return this->wb.active_sheet().highest_row();
}

SynchronousExcelWrapper *SynchronousExcelWrapper::instance = nullptr;

long long SynchronousExcelWrapper::getStamp(unsigned int row_no) {
    QMutexLocker mutexLocker(&this->mMutex);
    return this->wb.active_sheet().cell(1, row_no).value<long long>();
}
