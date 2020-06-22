#include "mainwindow.h"
#include "splashscreen.h"
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
    if (tran.load(QLocale(), "qt", "_", dir, ".qm"))
    {
        a.installTranslator(&tran);   //TODO:翻译
    }

    a.setWindowIcon(QIcon("./image/myico.ico"));

    QPixmap pixmap("./image/splash.png");
    pixmap = pixmap.scaled(654, 463, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    SplashScreen splash(pixmap, 4000);
    splash.show();

    MainWindow w;
    w.show();

    return a.exec();
}


//TODO:右键菜单操作以及调色盘部分控件的翻译
//TODO:在窗口内打开多个文本编辑框（QTabWidget）
//TODO:未保存标志，自动保存的状态显示
//TODO:模态启动界面
//TODO:整体美化
//TODO:自定义工具栏
//TODO:格式刷
//TODO:插入图片后光标不闪烁的问题，以及从word中拖入图片报错：index out of range
//TODO:分页
