#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#pragma execution_character_set("utf-8")

#include <QMainWindow>
#include <QFile>
#include "findreplace.h"
#include "layout.h"
#include "autosave.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QString filename;
    QString findString;
    QString replaceString;
    QTimer *timer_autosave;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void newFile();
    void openFile();
    void save();
    void saveAs();
    void closeExe();
    void findAndReplace();
    void setFont();
    void setLayout();
    void insertTimeAndDate();
    void dragEnterEvent(QDragEnterEvent*event);
    void dropEvent(QDropEvent*event);
    void setFontColor();
    void autoSave();

private:
    Ui::MainWindow *ui;
    findreplace* fr;
    class layout* lo;
    autosave* as;
private slots:
    void receiveFindString(QString fs, bool isCaseSensetive, bool isCycle);
    void receiveReplaceString(QString fs, QString rs, bool isCaseSensetive, bool isAll);
    void receiveLayout(QString alignment, qreal lineSpacing, qreal margin, qreal indent);
    void receiveAutoSave(bool isAutoSave, int interval);
    void handleAutoSave();
};
#endif // MAINWINDOW_H
