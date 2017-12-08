#include <iostream>
#include <Utility.h>
#include <QtGui>
#include <ExcelServer.h>
#include <SynchronousExcelWrapper.h>

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);
    QTextStream out(stdout);

    QString path = QDir::currentPath().append(QDir::separator()).append("example.xlsx");
    out << QString("Excel file : %1").arg(path) << endl;
    // Generate the excel file if it doesn't exist
    if (!QFileInfo(path).exists()) {
        out << "File not found ! Generating 10K records excel sheet" << endl;

        Utility::generate(path, 10000);
    } else
        out << "File found "<<endl;

    ExcelServer server(path);
    server.startServer();
    return app.exec();

}

