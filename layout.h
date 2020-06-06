#ifndef LAYOUT_H
#define LAYOUT_H

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
    void sendLayout(QString ,qreal,qreal, bool);
private slots:
    void on_accept_clicked();
};

#endif // LAYOUT_H
