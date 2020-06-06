#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QString>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QPalette>
#include <QFontDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->newfile->setShortcut(tr("ctrl+n"));
    ui->openfile->setShortcut(tr("ctrl+o"));
    ui->save->setShortcut(tr("ctrl+s"));
    ui->saveas->setShortcut(tr("ctrl+shift+s"));
    ui->undo->setShortcut(tr("ctrl+z"));
    ui->redo->setShortcut(tr("ctrl+y"));
    ui->findandreplace->setShortcut(tr("ctrl+f"));

    connect(ui->newfile,&QAction::triggered,this,&MainWindow::newFile);
    connect(ui->openfile,&QAction::triggered,this,&MainWindow::openFile);
    connect(ui->save,&QAction::triggered,this,&MainWindow::save);
    connect(ui->saveas,&QAction::triggered,this,&MainWindow::saveAs);
    connect(ui->findandreplace,&QAction::triggered,this,&MainWindow::findAndReplace);
    connect(ui->format,&QAction::triggered,this,&MainWindow::setFont);
    connect(ui->layout,&QAction::triggered,this,&MainWindow::setLayout);
    this->fr=new findreplace(this);
    this->lo=new class layout(this);

    connect(fr,SIGNAL(sendFindString(QString)),this,SLOT(receiveFindString(QString)));
    connect(fr,SIGNAL(sendReplaceString(QString,QString)),this,SLOT(receiveReplaceString(QString,QString)));
    connect(lo,SIGNAL(sendLayout(QString,qreal, qreal, bool)),this,SLOT(receiveLayout(QString ,qreal,qreal,bool)));

    this->setWindowTitle(tr("简单的文档编辑系统"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::newFile()
{
    if(ui->mainEdit->toPlainText()!="")
    {
        QMessageBox message(QMessageBox::Warning,"未保存的工作", "工作区有未保存的工作,是否保存?",QMessageBox::Yes|QMessageBox::No,NULL);
        if (message.exec()==QMessageBox::Yes)
            save();

    }
    ui->mainEdit->setText("");
}
void MainWindow::openFile()
{
    filename=QFileDialog::getOpenFileName(this, tr("打开文档"), ".", tr("文本文档(*.txt)"));
    if(filename.length() == 0) {
        QMessageBox::information(NULL, tr("Path"), tr("未选择文件"));
        return;
    }
    QFile textFile(filename);
    if(!textFile.exists())
    {
        QMessageBox::information(NULL, tr("Path"), tr("文件不存在"));
        return;
    }
    if(!textFile.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        QMessageBox::information(NULL, tr("Path"), tr("文件打开失败"));
        return;
    }
    QTextStream in(&textFile);
    ui->mainEdit->setText(in.readAll());
    this->setWindowTitle(filename);
    textFile.close();
}
void MainWindow::save()//TODO:保存为富文本格式如HTML
{
    if(filename=="")
    {
        filename=QFileDialog::getSaveFileName(this,tr("保存"),".","文本文档(*.txt)");
        if(filename=="")
        {
            QMessageBox::information(NULL, tr("Path"), tr("未选择文件"));
            return;
        }
    }
    this->setWindowTitle(filename);
    QFile textFile(filename);
    if(!textFile.open(QIODevice::WriteOnly|QIODevice::Text))
    {
        QMessageBox::information(NULL, tr("Path"), tr("文件打开失败"));
        return;
    }
    QTextStream out(&textFile);
    out<<ui->mainEdit->toPlainText();
    textFile.close();
}
void MainWindow::saveAs()
{
    filename=QFileDialog::getSaveFileName(this,tr("另存为"),".","文本文档(*.txt)");
    QFile textFile(filename);
    if(!textFile.open(QIODevice::WriteOnly|QIODevice::Text))
    {
        QMessageBox::information(NULL, tr("Path"), tr("文件打开失败"));
        return;
    }
    this->setWindowTitle(filename);
    QTextStream out(&textFile);
    out<<ui->mainEdit->toPlainText();
    textFile.close();
}
void MainWindow::findAndReplace()
{
    fr->show();
}
void MainWindow::setFont()
{
    bool ok;
    QTextCharFormat format;
    QTextCursor cursor=ui->mainEdit->textCursor();
    cursor.beginEditBlock();
    format.setFont(QFontDialog::getFont(&ok));
    if(ok){
        cursor.setCharFormat(format);
    }
    cursor.endEditBlock();
}
void MainWindow::setLayout()
{
    lo->show();
}

void MainWindow::receiveFindString(QString fs)
{
    this->findString=fs;
    if (findString.trimmed().isEmpty())
    {
        QMessageBox::information(NULL, tr("Path"), "空字符串!");
        return;
    }
    if(!ui->mainEdit->find(findString))
    {
        QMessageBox::information(NULL, tr("Path"), "未找到指定字符串!");
        return;
    }
}
void MainWindow::receiveReplaceString(QString fs,QString rs)
{
    this->replaceString=rs;
    int count=0;
    QTextCursor cursor=ui->mainEdit->textCursor();
    cursor.beginEditBlock();
    cursor.setPosition(0);
    while(ui->mainEdit->find(fs))
    {
        QTextCursor replace_cursor=ui->mainEdit->textCursor();
        replace_cursor.removeSelectedText();
        replace_cursor.insertText(rs);
        count++;
    }
    cursor.endEditBlock();
    QMessageBox::information(NULL, tr("Path"), "替换完成,共替换"+QString::number(count)+"处");
}

void MainWindow::receiveLayout(QString alignment,qreal lineSpacing, qreal margin, bool indent)
{
    QTextCursor cursor=ui->mainEdit->textCursor();
    cursor.beginEditBlock();
    QTextBlockFormat blockFormat=cursor.blockFormat();
    if(alignment==tr("左对齐"))
        blockFormat.setAlignment(Qt::AlignLeft);
    else if(alignment==tr("右对齐"))
        blockFormat.setAlignment(Qt::AlignRight);
    else if(alignment==tr("居中对齐"))
        blockFormat.setAlignment(Qt::AlignCenter);
    if(lineSpacing>=0)
        blockFormat.setLineHeight(lineSpacing,QTextBlockFormat::FixedHeight);
    if(margin>=0)
    {
        blockFormat.setTopMargin(margin);
        blockFormat.setBottomMargin(margin);
    }
    //TODO:首行缩进
    cursor.setBlockFormat(blockFormat);
    cursor.endEditBlock();
}
