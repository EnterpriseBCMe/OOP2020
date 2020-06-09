#ifndef LAYOUT_H
#define LAYOUT_H

#pragma execution_character_set("utf-8")

#include <QDialog>

namespace Ui {
class layout;
}

class layout : public QDialog
{
    Q_OBJECT

public:
    explicit layout(QWidget *parent = nullptr);
    ~layout();

private:
    Ui::layout *ui;
signals:
    void sendLayout(QString, qreal, qreal, qreal);
private slots:
    void on_accept_clicked();
    void on_firstLineIndent_stateChanged();
};

#endif // LAYOUT_H
