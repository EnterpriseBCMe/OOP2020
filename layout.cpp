#include "layout.h"
#include "ui_layout.h"

layout::layout(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::layout)
{
    ui->setupUi(this);
    ui->cb_alignment->addItem(tr("左对齐"));
    ui->cb_alignment->addItem(tr("右对齐"));
    ui->cb_alignment->addItem(tr("居中对齐"));
    this->setWindowTitle(tr("排版设置"));
    QRegExp floatregx("[0-9]+(\.)?[0-9]*");
    QValidator *fvalidator = new QRegExpValidator(floatregx, nullptr);
    ui->le_lineSpacing->setValidator(fvalidator);
    ui->le_margin->setValidator(fvalidator);
    connect(ui->accept,SIGNAL(clicked()),this,SLOT(on_accept_clicked()));
}

layout::~layout()
{
    delete ui;
}

void layout::on_accept_clicked()
{
    QString alignment=ui->cb_alignment->currentText();
    qreal lineSpacing=ui->le_lineSpacing->isModified()?ui->le_lineSpacing->text().toDouble():-1;
    qreal margin=ui->le_margin->isModified()?ui->le_margin->text().toDouble():-1;
    bool indent=ui->firstLineIndent->isChecked();
    emit sendLayout(alignment,lineSpacing,margin, indent);
    this->hide();
}
