#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include "findreplace.h"
#include "layout.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT;
    QString filename;
    QString findString;
    QString replaceString;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void newFile();
    void openFile();
    void save();
    void saveAs();
    void findAndReplace();
    void setFont();
    void setLayout();

private:
    Ui::MainWindow *ui;
    findreplace* fr;
    class layout* lo;
private slots:
    void receiveFindString(QString fs);
    void receiveReplaceString(QString fs,QString rs);
    void receiveLayout(QString alignment,qreal lineSpacing, qreal margin, bool indent);
};
#endif // MAINWINDOW_H
