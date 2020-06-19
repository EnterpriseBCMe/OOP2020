/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *newfile;
    QAction *openfile;
    QAction *save;
    QAction *saveas;
    QAction *findandreplace;
    QAction *format;
    QAction *layout;
    QAction *undo;
    QAction *redo;
    QAction *timeanddate;
    QAction *exit;
    QAction *about;
    QAction *cut;
    QAction *copy;
    QAction *paste;
    QAction *selectAll;
    QAction *delete_2;
    QAction *fontcolor;
    QAction *autosave;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout_2;
    QTextEdit *mainEdit;
    QMenuBar *menubar;
    QMenu *file;
    QMenu *operation;
    QMenu *menu_H;
    QMenu *menu_C;
    QMenu *menu_T;
    QMenu *menu_S;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(687, 800);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(0, 0));
        MainWindow->setMaximumSize(QSize(999999, 999999));
        MainWindow->setMouseTracking(false);
        MainWindow->setAcceptDrops(false);
        newfile = new QAction(MainWindow);
        newfile->setObjectName(QStringLiteral("newfile"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/\346\226\260\345\273\272\346\226\207\346\241\243.png"), QSize(), QIcon::Normal, QIcon::Off);
        newfile->setIcon(icon);
        openfile = new QAction(MainWindow);
        openfile->setObjectName(QStringLiteral("openfile"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/\346\211\223\345\274\200.png"), QSize(), QIcon::Normal, QIcon::Off);
        openfile->setIcon(icon1);
        save = new QAction(MainWindow);
        save->setObjectName(QStringLiteral("save"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/\344\277\235\345\255\230.png"), QSize(), QIcon::Normal, QIcon::Off);
        save->setIcon(icon2);
        saveas = new QAction(MainWindow);
        saveas->setObjectName(QStringLiteral("saveas"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix1/\345\217\246\345\255\230\344\270\272.png"), QSize(), QIcon::Normal, QIcon::Off);
        saveas->setIcon(icon3);
        findandreplace = new QAction(MainWindow);
        findandreplace->setObjectName(QStringLiteral("findandreplace"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/prefix1/\346\237\245\346\211\276\346\233\277\346\215\242.png"), QSize(), QIcon::Normal, QIcon::Off);
        findandreplace->setIcon(icon4);
        format = new QAction(MainWindow);
        format->setObjectName(QStringLiteral("format"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/new/prefix1/\346\226\207\345\255\227.png"), QSize(), QIcon::Normal, QIcon::Off);
        format->setIcon(icon5);
        layout = new QAction(MainWindow);
        layout->setObjectName(QStringLiteral("layout"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/new/prefix1/\346\216\222\347\211\210.png"), QSize(), QIcon::Normal, QIcon::Off);
        layout->setIcon(icon6);
        undo = new QAction(MainWindow);
        undo->setObjectName(QStringLiteral("undo"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/new/prefix1/\346\222\244\351\224\200.png"), QSize(), QIcon::Normal, QIcon::Off);
        undo->setIcon(icon7);
        redo = new QAction(MainWindow);
        redo->setObjectName(QStringLiteral("redo"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/new/prefix1/\351\207\215\345\201\232.png"), QSize(), QIcon::Normal, QIcon::Off);
        redo->setIcon(icon8);
        timeanddate = new QAction(MainWindow);
        timeanddate->setObjectName(QStringLiteral("timeanddate"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/new/prefix1/\346\227\245\346\234\237.png"), QSize(), QIcon::Normal, QIcon::Off);
        timeanddate->setIcon(icon9);
        exit = new QAction(MainWindow);
        exit->setObjectName(QStringLiteral("exit"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/new/prefix1/\351\200\200\345\207\272.png"), QSize(), QIcon::Normal, QIcon::Off);
        exit->setIcon(icon10);
        about = new QAction(MainWindow);
        about->setObjectName(QStringLiteral("about"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/new/prefix1/\345\205\263\344\272\216.png"), QSize(), QIcon::Normal, QIcon::Off);
        about->setIcon(icon11);
        cut = new QAction(MainWindow);
        cut->setObjectName(QStringLiteral("cut"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/new/prefix1/\345\211\252\345\210\207.png"), QSize(), QIcon::Normal, QIcon::Off);
        cut->setIcon(icon12);
        copy = new QAction(MainWindow);
        copy->setObjectName(QStringLiteral("copy"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/new/prefix1/\345\244\215\345\210\266.png"), QSize(), QIcon::Normal, QIcon::Off);
        copy->setIcon(icon13);
        paste = new QAction(MainWindow);
        paste->setObjectName(QStringLiteral("paste"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/new/prefix1/\347\262\230\350\264\264.png"), QSize(), QIcon::Normal, QIcon::Off);
        paste->setIcon(icon14);
        selectAll = new QAction(MainWindow);
        selectAll->setObjectName(QStringLiteral("selectAll"));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/new/prefix1/\345\205\250\351\200\211.png"), QSize(), QIcon::Normal, QIcon::Off);
        selectAll->setIcon(icon15);
        delete_2 = new QAction(MainWindow);
        delete_2->setObjectName(QStringLiteral("delete_2"));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/new/prefix1/\345\210\240\351\231\244.png"), QSize(), QIcon::Normal, QIcon::Off);
        delete_2->setIcon(icon16);
        fontcolor = new QAction(MainWindow);
        fontcolor->setObjectName(QStringLiteral("fontcolor"));
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/new/prefix1/\345\255\227\344\275\223\351\242\234\350\211\262.png"), QSize(), QIcon::Normal, QIcon::Off);
        fontcolor->setIcon(icon17);
        autosave = new QAction(MainWindow);
        autosave->setObjectName(QStringLiteral("autosave"));
        QIcon icon18;
        icon18.addFile(QString::fromUtf8(":/new/prefix1/\350\207\252\345\212\250.png"), QSize(), QIcon::Normal, QIcon::Off);
        autosave->setIcon(icon18);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setEnabled(true);
        scrollArea->setStyleSheet(QStringLiteral("border:none;"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 669, 684));
        horizontalLayout_2 = new QHBoxLayout(scrollAreaWidgetContents);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        mainEdit = new QTextEdit(scrollAreaWidgetContents);
        mainEdit->setObjectName(QStringLiteral("mainEdit"));
        QFont font;
        font.setPointSize(12);
        mainEdit->setFont(font);

        horizontalLayout_2->addWidget(mainEdit);

        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout->addWidget(scrollArea);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 687, 21));
        file = new QMenu(menubar);
        file->setObjectName(QStringLiteral("file"));
        operation = new QMenu(menubar);
        operation->setObjectName(QStringLiteral("operation"));
        menu_H = new QMenu(menubar);
        menu_H->setObjectName(QStringLiteral("menu_H"));
        menu_C = new QMenu(menubar);
        menu_C->setObjectName(QStringLiteral("menu_C"));
        menu_T = new QMenu(menubar);
        menu_T->setObjectName(QStringLiteral("menu_T"));
        menu_S = new QMenu(menubar);
        menu_S->setObjectName(QStringLiteral("menu_S"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setIconSize(QSize(24, 24));
        toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        toolBar->setFloatable(true);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(file->menuAction());
        menubar->addAction(operation->menuAction());
        menubar->addAction(menu_C->menuAction());
        menubar->addAction(menu_T->menuAction());
        menubar->addAction(menu_H->menuAction());
        menubar->addAction(menu_S->menuAction());
        file->addAction(newfile);
        file->addAction(openfile);
        file->addSeparator();
        file->addAction(save);
        file->addAction(saveas);
        file->addSeparator();
        file->addAction(exit);
        operation->addAction(undo);
        operation->addAction(redo);
        operation->addSeparator();
        operation->addAction(cut);
        operation->addAction(copy);
        operation->addAction(paste);
        operation->addAction(delete_2);
        operation->addSeparator();
        operation->addAction(selectAll);
        operation->addAction(timeanddate);
        menu_H->addAction(about);
        menu_C->addAction(format);
        menu_C->addAction(fontcolor);
        menu_T->addAction(layout);
        menu_T->addAction(findandreplace);
        menu_S->addAction(autosave);
        toolBar->addAction(newfile);
        toolBar->addAction(openfile);
        toolBar->addAction(save);
        toolBar->addAction(saveas);
        toolBar->addSeparator();
        toolBar->addAction(format);
        toolBar->addAction(fontcolor);
        toolBar->addSeparator();
        toolBar->addAction(layout);
        toolBar->addAction(findandreplace);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        newfile->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272(&N)", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        newfile->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        openfile->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200(&O)", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        openfile->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        save->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230(&S)", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        save->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        saveas->setText(QApplication::translate("MainWindow", "\345\217\246\345\255\230\344\270\272(&A)", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        saveas->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+S", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        findandreplace->setText(QApplication::translate("MainWindow", "\346\237\245\346\211\276\344\270\216\346\233\277\346\215\242(&F)", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        findandreplace->setShortcut(QApplication::translate("MainWindow", "Ctrl+F", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        format->setText(QApplication::translate("MainWindow", "\346\226\207\345\255\227\346\240\274\345\274\217", Q_NULLPTR));
        layout->setText(QApplication::translate("MainWindow", "\351\241\265\351\235\242\346\216\222\347\211\210(&U)", Q_NULLPTR));
        undo->setText(QApplication::translate("MainWindow", "\346\222\244\351\224\200(&Z)", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        undo->setShortcut(QApplication::translate("MainWindow", "Ctrl+Z", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        redo->setText(QApplication::translate("MainWindow", "\351\207\215\345\201\232(&R)", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        redo->setShortcut(QApplication::translate("MainWindow", "Ctrl+Y", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        timeanddate->setText(QApplication::translate("MainWindow", "\346\227\266\351\227\264/\346\227\245\346\234\237", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        timeanddate->setShortcut(QApplication::translate("MainWindow", "F5", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        exit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272(&E)", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        exit->setShortcut(QApplication::translate("MainWindow", "Ctrl+W", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        about->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216(&A)", Q_NULLPTR));
        cut->setText(QApplication::translate("MainWindow", "\345\211\252\345\210\207(&T)", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        cut->setShortcut(QApplication::translate("MainWindow", "Ctrl+X", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        copy->setText(QApplication::translate("MainWindow", "\345\244\215\345\210\266(&C)", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        copy->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        paste->setText(QApplication::translate("MainWindow", "\347\262\230\350\264\264(&P)", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        paste->setShortcut(QApplication::translate("MainWindow", "Ctrl+V", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        selectAll->setText(QApplication::translate("MainWindow", "\345\205\250\351\200\211(&A)", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        selectAll->setShortcut(QApplication::translate("MainWindow", "Ctrl+A", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        delete_2->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244(&L)", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        delete_2->setShortcut(QApplication::translate("MainWindow", "Del", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        fontcolor->setText(QApplication::translate("MainWindow", "\345\255\227\344\275\223\351\242\234\350\211\262", Q_NULLPTR));
        autosave->setText(QApplication::translate("MainWindow", "\350\207\252\345\212\250\344\277\235\345\255\230(&A)", Q_NULLPTR));
        file->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266(&F)", Q_NULLPTR));
        operation->setTitle(QApplication::translate("MainWindow", "\347\274\226\350\276\221(&E)", Q_NULLPTR));
        menu_H->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251(&H)", Q_NULLPTR));
        menu_C->setTitle(QApplication::translate("MainWindow", "\346\226\207\345\255\227(&C)", Q_NULLPTR));
        menu_T->setTitle(QApplication::translate("MainWindow", "\345\267\245\345\205\267(&T)", Q_NULLPTR));
        menu_S->setTitle(QApplication::translate("MainWindow", "\350\256\276\347\275\256(&S)", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
