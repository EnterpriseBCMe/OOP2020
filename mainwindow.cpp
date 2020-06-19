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
#include <QDateTime>
#include <QRegularExpression>
#include <QColorDialog>
#include <QDragEnterEvent>
#include <QMimeData>
#include <QDropEvent>
#include <QUrl>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->newfile,&QAction::triggered,this,&MainWindow::newFile);
    connect(ui->openfile,&QAction::triggered,this,&MainWindow::openFile);
    connect(ui->save,&QAction::triggered,this,&MainWindow::save);
    connect(ui->saveas,&QAction::triggered,this,&MainWindow::saveAs);
    connect(ui->findandreplace,&QAction::triggered,this,&MainWindow::findAndReplace);
    connect(ui->format,&QAction::triggered,this,&MainWindow::setFont);
    connect(ui->layout,&QAction::triggered,this,&MainWindow::setLayout);
    connect(ui->exit,&QAction::triggered,this,&MainWindow::closeExe);
    connect(ui->timeanddate,&QAction::triggered,this,&MainWindow::insertTimeAndDate);
    connect(ui->fontcolor,&QAction::triggered,this,&MainWindow::setFontColor);
    connect(ui->autosave,&QAction::triggered,this,&MainWindow::autoSave);
    this->fr = new findreplace(this);
    this->lo = new class layout(this);
    this->as = new autosave(this);

    connect(fr,SIGNAL(sendFindString(QString,bool,bool)),this,SLOT(receiveFindString(QString,bool,bool)));
    connect(fr,SIGNAL(sendReplaceString(QString,QString,bool)),this,SLOT(receiveReplaceString(QString,QString,bool)));
    connect(lo,SIGNAL(sendLayout(QString, qreal, qreal, qreal)),this,SLOT(receiveLayout(QString ,qreal,qreal,qreal)));
    connect(as,SIGNAL(sendAutoSave(bool, int)),this,SLOT(receiveAutoSave(bool, int)));

    this->setWindowTitle(tr("简单的文档编辑系统"));
    this->setAcceptDrops(true);

    timer_autosave = new QTimer(this);
    connect(timer_autosave, SIGNAL(timeout()), this, SLOT(handleAutoSave()));
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

void MainWindow::openFile()    //TODO:打开和保存文件时的pdf/doc/txt/html互转
{
    filename=QFileDialog::getOpenFileName(this, tr("打开文档"), ".", tr("文本文档(*.txt);;网页(*.htm;*.html)"));
    if(filename.length() == 0)
        return;
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
    if(QRegularExpression("html$").match(filename).hasMatch())  //TODO:中文乱码问题
        ui->mainEdit->setHtml(in.readAll());
    else
        ui->mainEdit->setText(in.readAll());
    this->setWindowTitle(filename);
    textFile.close();
}

void MainWindow::save()
{
    if(filename=="")
    {
        filename=QFileDialog::getSaveFileName(this,tr("保存"),".","文本文档(*.txt);;网页(*.htm;*.html)");
        if(filename=="")
            return;
    }
    this->setWindowTitle(filename);
    QFile textFile(filename);
    if(!textFile.open(QIODevice::WriteOnly|QIODevice::Text))
        return;
    QTextStream out(&textFile);
    if(QRegularExpression("html$").match(filename).hasMatch())
        out << ui->mainEdit->toHtml();
    else
        out << ui->mainEdit->toPlainText();

    textFile.close();
}

void MainWindow::saveAs()
{
    filename=QFileDialog::getSaveFileName(this,tr("另存为"),".","文本文档(*.txt)");
    QFile textFile(filename);
    if(!textFile.open(QIODevice::WriteOnly|QIODevice::Text))
        return;
    this->setWindowTitle(filename);
    QTextStream out(&textFile);
    out<<ui->mainEdit->toPlainText();
    textFile.close();
}

void MainWindow::closeExe()
{
    this->close();
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

void MainWindow::receiveFindString(QString fs, bool isCaseSensetive, bool isCycle)
{
    this->findString=fs;
    if(findString.trimmed().isEmpty())
    {
        QMessageBox::information(NULL, tr("Path"), "空字符串!");
        return;
    }
    if(!ui->mainEdit->find(findString, isCaseSensetive ? QTextDocument::FindFlags() : QTextDocument::FindCaseSensitively))
    {
        if(isCycle)
            ui->mainEdit->moveCursor(QTextCursor::Start);
        else
            QMessageBox::information(NULL, tr("Path"), "未找到指定字符串!");
    }
}

void MainWindow::receiveReplaceString(QString fs, QString rs, bool isCaseSensetive)  // TODO:分解成"替换下一个"+"全部替换"两个选项
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

void MainWindow::receiveLayout(QString alignment,qreal lineSpacing, qreal margin, qreal indent)
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

    blockFormat.setTextIndent(indent * ui->mainEdit->fontMetrics().width("一"));

    cursor.setBlockFormat(blockFormat);
    cursor.endEditBlock();
}

void MainWindow::insertTimeAndDate()
{
    QTextCursor cursor = ui->mainEdit->textCursor();
    cursor.insertText(QDateTime::currentDateTime().toString());
}

void MainWindow::dragEnterEvent(QDragEnterEvent* event)
{
    QString extension = event->mimeData()->urls()[0].fileName();
    if(!(QRegExp("(txt$)|(html$)|(htm$)").exactMatch(extension)))
        event->acceptProposedAction();
    else
        event->ignore();
}

void MainWindow::dropEvent(QDropEvent* event)
{
    const QMimeData* mimeData = event->mimeData();
    if(mimeData->hasUrls())
    {
        QString fileName = mimeData->urls().at(0).toLocalFile();
        if(!fileName.isEmpty())
        {
            QFile file(fileName);
            if(!file.open(QIODevice::ReadOnly))
                return;
            QTextStream in(&file);
            ui->mainEdit->setText(in.readAll());
        }
    }
}

void MainWindow::setFontColor()
{
    ui->mainEdit->setTextColor(QColorDialog::getColor(Qt::white, this, "颜色"));
}

void MainWindow::autoSave()
{
    as->show();
}

void MainWindow::receiveAutoSave(bool isAutoSave, int interval)
{
    if(isAutoSave)
        MainWindow::timer_autosave->start(interval * 1000);
    else
        MainWindow::timer_autosave->stop();
}

void MainWindow::handleAutoSave()
{
    if(filename == "")
        return;
    else
    {
        QFile textFile(filename);
        if(!textFile.open(QIODevice::WriteOnly|QIODevice::Text))
            return;
        QTextStream out(&textFile);
        if(QRegularExpression("html$").match(filename).hasMatch())
            out << ui->mainEdit->toHtml();
        else
            out << ui->mainEdit->toPlainText();
        textFile.close();
    }
}
