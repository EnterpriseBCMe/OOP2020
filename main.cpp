#include "mainwindow.h"

#include <QApplication>
#include <QTranslator>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator tran;
    QString dir = a.applicationDirPath();
    if (tran.load(QLocale(), "qt", "_", dir, ".qm"))
    {
        a.installTranslator(&tran);//TODO:中文翻译
    }
    MainWindow w;
    w.show();
    return a.exec();
}
