#ifndef AUTOSAVE_H
#define AUTOSAVE_H

#include <QDialog>

namespace Ui {
class autosave;
}

class autosave : public QDialog
{
    Q_OBJECT

public:
    explicit autosave(QWidget *parent = nullptr);
    ~autosave();

private:
    Ui::autosave *ui;
signals:
    void sendAutoSave(bool, int);
private slots:
    void on_autoSave_stateChanged();
    void on_accept_clicked();
};

#endif // AUTOSAVE_H
