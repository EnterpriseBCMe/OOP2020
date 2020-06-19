#include "mainwindow.h"

#include <QApplication>
#include <QTranslator>
int main(int argc, char *argv[])
{

#if (QT_VERSION >= QT_VERSION_CHECK(5,9,0))
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QApplication a(argc, argv);
    a.setWindowIcon(QIcon("./image/myico.ico"));
    QTranslator tran;
    QString dir = a.applicationDirPath();
    if (tran.load(QLocale(), "qt", "_", dir, ".qm"))
    {
        a.installTranslator(&tran);   //TODO:翻译
    }
    MainWindow w;
    w.show();
    return a.exec();
}


//TODO:拖动文件至文本框内打开
//TODO:右键菜单操作翻译
//TODO:在窗口内打开多个文本编辑框
//TODO:未保存标志，自动保存的状态显示
