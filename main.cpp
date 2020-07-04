#include "mainwindow.h"
#include <QApplication>
#include <QTranslator>
#include <QPixmap>
#include <QSplashScreen>
#include <QDateTime>
#include <QProgressBar>
#include <QThread>
#include <QApplication>

int main(int argc, char *argv[])
{

#if (QT_VERSION >= QT_VERSION_CHECK(5,9,0))
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);    // 自适应高分辨率
#endif

    QApplication a(argc, argv);

    QTranslator tran;
    QString dir = a.applicationDirPath();
    if (tran.load(QLocale(), "qt", "_", dir, ".qm"))  // 翻译
        a.installTranslator(&tran);

    a.setWindowIcon(QIcon("./image/myico.ico"));  // 设置程序图标

    MainWindow w;
    w.show();

    return a.exec();
}
