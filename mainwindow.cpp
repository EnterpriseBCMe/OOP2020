#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mytextedit.h"
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
#include <QImageReader>
#include <QPrinter>
#include <QPropertyAnimation>
#include <QApplication>
#include <QDesktopWidget>
#include <QPoint>
#include <QLabel>

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
    connect(ui->insertoroverwrite,&QAction::triggered,this,&MainWindow::changeInputMode);
    connect(ui->zoomIn,&QAction::triggered,this,&MainWindow::zoomIn);
    connect(ui->zoomOut,&QAction::triggered,this,&MainWindow::zoomOut);
    connect(ui->fullscreen,&QAction::triggered,this,&MainWindow::fullScreen);
    connect(ui->formatbrush,&QAction::triggered,this,&MainWindow::formatBrush);
    this->fr = new findreplace(this);
    this->lo = new class layout(this);
    this->as = new autosave(this);

    connect(fr,SIGNAL(sendFindString(QString,bool,bool)),this,SLOT(receiveFindString(QString,bool,bool)));
    connect(fr,SIGNAL(sendReplaceString(QString,QString,bool,bool)),this,SLOT(receiveReplaceString(QString,QString,bool,bool)));
    connect(lo,SIGNAL(sendLayout(QString, qreal, qreal, qreal)),this,SLOT(receiveLayout(QString ,qreal,qreal,qreal)));
    connect(as,SIGNAL(sendAutoSave(bool, int)),this,SLOT(receiveAutoSave(bool, int)));

    this->setWindowTitle(tr("简单的文档编辑系统"));
    this->setAcceptDrops(true);

    this->setWindowFlags(Qt::WindowStaysOnTopHint);  // 窗口保持在最上层

    timer_autosave = new QTimer(this);
    connect(timer_autosave, SIGNAL(timeout()), this, SLOT(handleAutoSave()));

    this->statusBar()->setStyleSheet("QStatusBar{border-top:1px solid lightgray;}");
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
    this->setWindowTitle("新文件");
}

void MainWindow::openFile()
{
    filename=QFileDialog::getOpenFileName(this, tr("打开文档"), ".", tr("文本文档(*.txt);;网页(*.htm;*.html)"));
    if(filename.length() == 0)
        return;

    QFile textFile(filename);
    if(!textFile.exists())
    {
        QMessageBox::information(NULL, tr("提示"), tr("文件不存在"));
        return;
    }
    if(!textFile.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        QMessageBox::information(NULL, tr("提示"), tr("文件打开失败"));
        return;
    }

    QTextStream in(&textFile);
    in.setCodec("UTF-8");
    if(QRegularExpression("txt$").match(filename).hasMatch())
        ui->mainEdit->setText(in.readAll());
    else if(QRegularExpression("html$").match(filename).hasMatch())
        ui->mainEdit->setHtml(in.readAll());

    this->setWindowTitle(filename);
    textFile.close();
}

void MainWindow::save()
{
    if(filename=="")
    {
        filename=QFileDialog::getSaveFileName(this,tr("保存"),".","文本文档(*.txt);;网页(*.htm;*.html);;PDF(*.pdf)");
        if(filename=="")
            return;
    }
    this->setWindowTitle(filename);

    QFile textFile(filename);
    if(!textFile.open(QIODevice::WriteOnly|QIODevice::Text))
        return;

    QTextStream out(&textFile);
    if(QRegularExpression("txt$").match(filename).hasMatch())
        out << ui->mainEdit->toPlainText();
    else if(QRegularExpression("html$").match(filename).hasMatch())
        out << ui->mainEdit->toHtml();
    else if(QRegularExpression("pdf$").match(filename).hasMatch())
    {
        QPrinter printer;
        printer.setPaperSize(QPrinter::A4);
        printer.setPageMargins(30,30,30,30,QPrinter::DevicePixel);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName(filename);
        ui->mainEdit->print(&printer);
    }

    textFile.close();
}

void MainWindow::saveAs()
{
    filename=QFileDialog::getSaveFileName(this,tr("另存为"),".","文本文档(*.txt);;网页(*.htm;*.html);;PDF(*.pdf)");
    this->setWindowTitle(filename);

    QFile textFile(filename);
    if(!textFile.open(QIODevice::WriteOnly|QIODevice::Text))
        return;

    QTextStream out(&textFile);
    if(QRegularExpression("txt$").match(filename).hasMatch())
        out << ui->mainEdit->toPlainText();
    else if(QRegularExpression("html$").match(filename).hasMatch())
        out << ui->mainEdit->toHtml();
    else if(QRegularExpression("pdf$").match(filename).hasMatch())
    {
        QPrinter printer;
        printer.setPaperSize(QPrinter::A4);
        printer.setPageMargins(30,30,30,30,QPrinter::DevicePixel);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName(filename);
        ui->mainEdit->print(&printer);
    }

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
    format.setFont(QFontDialog::getFont(&ok,this));
    if(ok){
        cursor.setCharFormat(format);  // 对选中部分的样式进行修改
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
    if(!ui->mainEdit->find(findString, isCaseSensetive ? QTextDocument::FindCaseSensitively : QTextDocument::FindFlag()))
    {
        if(isCycle)
            ui->mainEdit->moveCursor(QTextCursor::Start);  // 如果设置了循环查找且没有找到下一个，从文档头部开始继续查找
        else
            QMessageBox::information(NULL, tr("Path"), "未找到指定字符串!");
    }
}

void MainWindow::receiveReplaceString(QString fs, QString rs, bool isCaseSensetive, bool isAll)
{
    this->replaceString=rs;
    QTextCursor cursor=ui->mainEdit->textCursor();
    cursor.beginEditBlock();
    if(isAll)
    {
        int count=0;
        cursor.setPosition(0);
        while(ui->mainEdit->find(fs, isCaseSensetive ? QTextDocument::FindCaseSensitively : QTextDocument::FindFlag()))
        {
            ui->mainEdit->textCursor().removeSelectedText();
            ui->mainEdit->textCursor().insertText(rs);
            count++;
        }
        QMessageBox::information(NULL, tr("Path"), "替换完成,共替换"+QString::number(count)+"处");
    }
    else
    {
        if(ui->mainEdit->find(fs, isCaseSensetive ? QTextDocument::FindCaseSensitively : QTextDocument::FindFlag()))
        {
            ui->mainEdit->textCursor().removeSelectedText();
            ui->mainEdit->textCursor().insertText(rs);
        }
        else
            QMessageBox::information(NULL, tr("Path"), "未找到指定的字符串");
    }

    cursor.endEditBlock();
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
    // 接受指定格式的文件拖入窗口打开
    QString extension = event->mimeData()->urls()[0].fileName();
    if(QRegularExpression("(txt$)|(html$)|(htm$)|(png$)|(jpg$)|(jpeg$)|(bmp$)|(gif$)").match(extension).hasMatch())
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
            newFile();
            // 打开图片
            if(QRegularExpression("(png$)|(jpg$)|(jpeg$)|(bmp$)|(gif$)").match(fileName).hasMatch())
            {
                QImage image = QImageReader(fileName).read();
                QTextCursor cursor = ui->mainEdit->textCursor();
                QTextDocument *document = ui->mainEdit->document();
                document->addResource(QTextDocument::ImageResource, QUrl(fileName), image);
                cursor.insertImage(fileName);
                MainWindow::filename = fileName;
                setWindowTitle(fileName);
            }
            // 打开文本
            else
            {
                QFile file(fileName);
                if(!file.open(QIODevice::ReadOnly))
                    return;
                QTextStream in(&file);
                if(QRegularExpression(".html$").match(fileName).hasMatch())
                    in.setCodec("UTF-8");
                ui->mainEdit->setText(in.readAll());
                MainWindow::filename = fileName;
                setWindowTitle(fileName);
            }
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
        MainWindow::timer_autosave->start(interval * 1000);  // 启用自动保存定时器
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
        ui->statusbar->showMessage(tr("自动保存中..."), 1000);
        textFile.close();
    }
}

void MainWindow::changeInputMode()
{
    if(ui->mainEdit->overwriteMode())
    {
        ui->mainEdit->setOverwriteMode(false);
        ui->insertoroverwrite->setText(tr("插入模式"));
    }
    else
    {
        ui->mainEdit->setOverwriteMode(true);
        ui->insertoroverwrite->setText(tr("改写模式"));
    }
}

void MainWindow::zoomIn()
{
    ui->mainEdit->zoomIn(3);
}

void MainWindow::zoomOut()
{
    ui->mainEdit->zoomOut(3);
}

void MainWindow::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        if(windowState() != Qt::WindowFullScreen)
            setWindowState(Qt::WindowFullScreen);
        else
            setWindowState(Qt::WindowNoState);
    }
}

void MainWindow::fullScreen()
{
    if(windowState() != Qt::WindowFullScreen)
        setWindowState(Qt::WindowFullScreen);
    else
        setWindowState(Qt::WindowNoState);
}

void MainWindow::wheelEvent(QWheelEvent *event)
{
    if(QApplication::keyboardModifiers() == Qt::ControlModifier)
    {
        if(event->delta() > 0)
            zoomIn();
        else
            zoomOut();
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        isDraged = true;
        mousePos = event->pos();
    }

    // 在非全屏模式下检测是否贴边
    if(!isFullScreen())
    {
        if(x() < 1)
            hide = LEFT;
        else if(y() < 1)
            hide = UP;
        else if(x()+width() > QApplication::desktop()->screenGeometry().right() - 1)
            hide = RIGHT;
        else
            hide = NO;
    }
}

void MainWindow::enterEvent(QEvent *event)
{
    // 鼠标进入窗口时，若窗口被隐藏，则展示显示动画
    if(hide == NO)
        return;
    Q_UNUSED(event);
    QPropertyAnimation * animation = new QPropertyAnimation(this, "pos");
    animation->setStartValue(QPoint(x(),y()));
    if(hide == LEFT)
        animation->setEndValue(QPoint(0,y()));
    else if(hide == UP)
        animation->setEndValue(QPoint(x(),0));
    else if(hide == RIGHT)
        animation->setEndValue(QPoint(QApplication::desktop()->screenGeometry().right()-width(),y()));
    animation->setDuration(250);
    animation->start();
}

void MainWindow::leaveEvent(QEvent *event)
{
    // 鼠标移出窗口后，若hide不为NO，则继续隐藏
    if(hide == NO)
        return;
    Q_UNUSED(event);
    QPropertyAnimation * animation = new QPropertyAnimation(this, "pos");
    animation->setStartValue(QPoint(x(),y()));
    if(hide == LEFT)
        animation->setEndValue(QPoint(-5-width(),y()));
    else if(hide == UP)
        animation->setEndValue(QPoint(x(),-28-height()));
    else if(hide == RIGHT)
        animation->setEndValue(QPoint(QApplication::desktop()->screenGeometry().right()-6,y()));
    animation->setDuration(250);
    animation->start();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    // 支持在窗口内部拖拽进行整个窗体的移动
    if(isDraged)
    {
        QPoint distance = event->pos() - mousePos;
        move(frameGeometry().topLeft() + distance);
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
        isDraged = false;

    if(!isFullScreen())
    {
        if(x() < 1)
            hide = LEFT;
        else if(y() < 1)
            hide = UP;
        else if(x()+width() > QApplication::desktop()->screenGeometry().right() - 1)
            hide = RIGHT;
        else
            hide = NO;
    }
}

void MainWindow::formatBrush()
{
    static bool isFormat = false;
    static QLabel *prompt;
    static QTextCharFormat format;
    const static QTextCharFormat defaultFormat;

    // 如果用户按下Ctrl+Shift+V，对选中部分应用格式刷
    if(this->keyEvent->key() == Qt::Key_V && this->keyEvent->modifiers() == (Qt::ShiftModifier | Qt::ControlModifier))
    {
        if(isFormat && ui->mainEdit->textCursor().hasSelection())
        {
            if(!format.isEmpty())
                ui->mainEdit->textCursor().setCharFormat(format);
            else
                ui->mainEdit->textCursor().setCharFormat(defaultFormat);
        }
    }
    else
    {
        if(!isFormat)
        {
            // 获取用户选中文本的格式
            format = ui->mainEdit->textCursor().charFormat();
            prompt = new QLabel("格式刷已开启");
            ui->statusbar->addWidget(prompt);
        }
        else
            ui->statusbar->removeWidget(prompt);
        isFormat = !isFormat;
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    this->keyEvent = event;
    if (event->key() == Qt::Key_V && event->modifiers() == (Qt::ShiftModifier | Qt::ControlModifier))
        formatBrush();
}
