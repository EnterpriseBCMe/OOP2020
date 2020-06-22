#include "findreplace.h"
#include "ui_findreplace.h"
#include <QAction>

findreplace::findreplace(QWidget *parent,QString findString,QString replaceString) :
    QDialog(parent),
    ui(new Ui::findreplace)
{
    ui->setupUi(this);
    ui->le_find->setText(findString);
    ui->le_replace->setText(replaceString);
}

findreplace::~findreplace()
{
    delete ui;
}

void findreplace::on_findNext_clicked()
{
    emit sendFindString(ui->le_find->text(), ui->caseSensitive->isChecked(), ui->cycle->isChecked());
}

void findreplace::on_replaceAll_clicked()
{
    emit sendReplaceString(ui->le_find->text(),ui->le_replace->text(), ui->caseSensitive->isChecked(), true);
}

void findreplace::on_replaceNextOne_clicked()
{
    emit sendReplaceString(ui->le_find->text(),ui->le_replace->text(), ui->caseSensitive->isChecked(), false);
}
