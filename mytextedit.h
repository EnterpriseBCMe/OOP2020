#ifndef MYTEXTEDIT_H
#define MYTEXTEDIT_H

#include <QObject>
#include <QWidget>
#include <QTextEdit>

class myTextEdit : public QTextEdit
{
    Q_OBJECT
public:
    explicit myTextEdit(QWidget *parent=nullptr);
    ~myTextEdit();
private:
    void dragEnterEvent(QDragEnterEvent* event) override;
    void dropEvent(QDropEvent *event) override;
};

#endif // MYTEXTEDIT_H
