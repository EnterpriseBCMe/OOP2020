#include "mytextedit.h"
#include <QMimeData>
#include <QDropEvent>
#include <QTextStream>
#include <QRegularExpression>
#include <QImageReader>
#include <QDebug>

myTextEdit::myTextEdit(QWidget *parent):QTextEdit(parent)
{
}

myTextEdit::~myTextEdit()
{
}

void myTextEdit::dragEnterEvent(QDragEnterEvent* event)
{
    if(event->mimeData()->hasUrls())
    {
        QString extension = event->mimeData()->urls()[0].fileName();
        qDebug() << extension;
        if(QRegularExpression("(png$)|(jpg$)|(jpeg$)|(bmp$)|(gif$)").match(extension).hasMatch())
            event->acceptProposedAction();
        else
            event->ignore();
    }
}

void myTextEdit::dropEvent(QDropEvent *event)
{
    const QMimeData* mimeData = event->mimeData();
    QTextCursor cursor = this->textCursor();
    QTextDocument *document = this->document();
    cursor.beginEditBlock();
    if(mimeData->hasUrls())
    {
        QString fileName = mimeData->urls().at(0).toLocalFile();
        if(!fileName.isEmpty())
        {
            // 插入图片
            QImage image = QImageReader(fileName).read();
            document->addResource(QTextDocument::ImageResource, QUrl(fileName), image);
            cursor.insertImage(fileName);
        }
    }
    cursor.endEditBlock();
}
