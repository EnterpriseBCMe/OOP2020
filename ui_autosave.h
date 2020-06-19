/********************************************************************************
** Form generated from reading UI file 'autosave.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTOSAVE_H
#define UI_AUTOSAVE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_autosave
{
public:
    QCheckBox *autoSave;
    QLabel *label;
    QSpinBox *changeInterval;
    QPushButton *accept;

    void setupUi(QDialog *autosave)
    {
        if (autosave->objectName().isEmpty())
            autosave->setObjectName(QStringLiteral("autosave"));
        autosave->resize(371, 307);
        autoSave = new QCheckBox(autosave);
        autoSave->setObjectName(QStringLiteral("autoSave"));
        autoSave->setGeometry(QRect(20, 20, 101, 18));
        label = new QLabel(autosave);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 45, 91, 31));
        changeInterval = new QSpinBox(autosave);
        changeInterval->setObjectName(QStringLiteral("changeInterval"));
        changeInterval->setEnabled(false);
        changeInterval->setGeometry(QRect(110, 50, 161, 22));
        changeInterval->setMinimum(1);
        changeInterval->setMaximum(3600);
        changeInterval->setValue(30);
        accept = new QPushButton(autosave);
        accept->setObjectName(QStringLiteral("accept"));
        accept->setGeometry(QRect(20, 180, 80, 20));

        retranslateUi(autosave);

        QMetaObject::connectSlotsByName(autosave);
    } // setupUi

    void retranslateUi(QDialog *autosave)
    {
        autosave->setWindowTitle(QApplication::translate("autosave", "Dialog", Q_NULLPTR));
        autoSave->setText(QApplication::translate("autosave", "\345\220\257\347\224\250\350\207\252\345\212\250\344\277\235\345\255\230", Q_NULLPTR));
        label->setText(QApplication::translate("autosave", "\350\207\252\345\212\250\344\277\235\345\255\230\351\227\264\351\232\224:", Q_NULLPTR));
        changeInterval->setSuffix(QApplication::translate("autosave", " \347\247\222", Q_NULLPTR));
        accept->setText(QApplication::translate("autosave", "\347\241\256\345\256\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class autosave: public Ui_autosave {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTOSAVE_H
