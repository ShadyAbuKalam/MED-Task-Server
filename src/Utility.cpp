//
// Created by jerry on 12/6/17.
//
#include <string>
#include <fstream>
#include <xlnt/xlnt.hpp>
#include "Utility.h"



void Utility::generate(QString path, long long samples_count) {

    xlnt::workbook wb;
    wb.create_sheet();
    auto ws = wb.active_sheet();
    srand(time(0));

    for (xlnt::row_t i = 1; i <= samples_count; ++i) {
        long long stamp = time(0) + random()%(SECONDS_PER_YEAR);
        float value = random() / (static_cast <float> (RAND_MAX / 1000));


        ws.cell(xlnt::cell_reference(1, i)).value(stamp);
        ws.cell(xlnt::cell_reference(2, i)).value(value);

    }

    wb.save(path.toStdString());
}

