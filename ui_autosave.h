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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_autosave
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QCheckBox *autoSave;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *changeInterval;
    QPushButton *accept;

    void setupUi(QDialog *autosave)
    {
        if (autosave->objectName().isEmpty())
            autosave->setObjectName(QStringLiteral("autosave"));
        autosave->resize(242, 101);
        gridLayout = new QGridLayout(autosave);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        autoSave = new QCheckBox(autosave);
        autoSave->setObjectName(QStringLiteral("autoSave"));

        verticalLayout->addWidget(autoSave);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(autosave);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        changeInterval = new QSpinBox(autosave);
        changeInterval->setObjectName(QStringLiteral("changeInterval"));
        changeInterval->setEnabled(false);
        changeInterval->setMinimum(1);
        changeInterval->setMaximum(3600);
        changeInterval->setValue(30);

        horizontalLayout->addWidget(changeInterval);


        verticalLayout->addLayout(horizontalLayout);

        accept = new QPushButton(autosave);
        accept->setObjectName(QStringLiteral("accept"));

        verticalLayout->addWidget(accept);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


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
