#ifndef FINDREPLACE_H
#define FINDREPLACE_H

#pragma execution_character_set("utf-8")

#include <QDialog>

namespace Ui {
class findreplace;
}

class findreplace : public QDialog
{
    Q_OBJECT

public:
    explicit findreplace(QWidget *parent = nullptr,QString findString="",QString replaceString="");
    ~findreplace();
private:
    Ui::findreplace *ui;
signals:
    void sendFindString(QString, bool, bool);
    void sendReplaceString(QString, QString, bool, bool);
private slots:
    void on_findNext_clicked();
    void on_replaceAll_clicked();
    void on_replaceNextOne_clicked();
};

#endif // FINDREPLACE_H
