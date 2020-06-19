#include "autosave.h"
#include "ui_autosave.h"

autosave::autosave(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::autosave)
{
    ui->setupUi(this);
}

autosave::~autosave()
{
    delete ui;
}

void autosave::on_autoSave_stateChanged()
{
    if(ui->autoSave->isChecked())
        ui->changeInterval->setEnabled(true);
    else
        ui->changeInterval->setDisabled(true);
}

void autosave::on_accept_clicked()
{
    emit sendAutoSave(ui->autoSave->isChecked(), ui->changeInterval->value());
    this->hide();
}
