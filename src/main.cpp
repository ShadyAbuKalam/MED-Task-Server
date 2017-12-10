#include <iostream>
#include <Utility.h>
#include <QtGui>
#include <ExcelServer.h>

#define EXCEL_FILE_NAME "example.xlsx"
#define TO_BE_GENERATED_RECORDS 10000

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);
    QTextStream out(stdout);

    QString path = QDir::currentPath().append(QDir::separator()).append(EXCEL_FILE_NAME);
    out << QString("Excel file : %1").arg(path) << endl;
    // Generate the excel file if it doesn't exist
    if (!QFileInfo(path).exists()) {
        out << QString("File not found ! Generating %1 records excel sheet").arg(TO_BE_GENERATED_RECORDS) << endl;

        Utility::generate(path, TO_BE_GENERATED_RECORDS);
    } else
        out << "File found "<<endl;

    ExcelServer server(path);
    server.startServer();
    return app.exec();

}

