/********************************************************************************
** Form generated from reading UI file 'layout.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LAYOUT_H
#define UI_LAYOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_layout
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *cb_alignment;
    QLabel *label_2;
    QLineEdit *le_lineSpacing;
    QLabel *label_3;
    QLineEdit *le_margin;
    QHBoxLayout *horizontalLayout;
    QCheckBox *firstLineIndent;
    QDoubleSpinBox *changeIndent;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *accept;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *layout)
    {
        if (layout->objectName().isEmpty())
            layout->setObjectName(QStringLiteral("layout"));
        layout->resize(322, 261);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(layout->sizePolicy().hasHeightForWidth());
        layout->setSizePolicy(sizePolicy);
        layout->setMinimumSize(QSize(0, 0));
        layout->setMaximumSize(QSize(999999, 999999));
        gridLayout = new QGridLayout(layout);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(layout);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        cb_alignment = new QComboBox(layout);
        cb_alignment->setObjectName(QStringLiteral("cb_alignment"));

        gridLayout->addWidget(cb_alignment, 1, 0, 1, 1);

        label_2 = new QLabel(layout);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        le_lineSpacing = new QLineEdit(layout);
        le_lineSpacing->setObjectName(QStringLiteral("le_lineSpacing"));

        gridLayout->addWidget(le_lineSpacing, 3, 0, 1, 1);

        label_3 = new QLabel(layout);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label_3, 4, 0, 1, 1);

        le_margin = new QLineEdit(layout);
        le_margin->setObjectName(QStringLiteral("le_margin"));

        gridLayout->addWidget(le_margin, 5, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        firstLineIndent = new QCheckBox(layout);
        firstLineIndent->setObjectName(QStringLiteral("firstLineIndent"));

        horizontalLayout->addWidget(firstLineIndent);

        changeIndent = new QDoubleSpinBox(layout);
        changeIndent->setObjectName(QStringLiteral("changeIndent"));
        changeIndent->setEnabled(false);
        changeIndent->setDecimals(1);
        changeIndent->setSingleStep(0.5);
        changeIndent->setValue(2);

        horizontalLayout->addWidget(changeIndent);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout, 6, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        accept = new QPushButton(layout);
        accept->setObjectName(QStringLiteral("accept"));

        horizontalLayout_2->addWidget(accept);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout_2, 7, 0, 1, 1);


        retranslateUi(layout);

        QMetaObject::connectSlotsByName(layout);
    } // setupUi

    void retranslateUi(QDialog *layout)
    {
        layout->setWindowTitle(QApplication::translate("layout", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("layout", "\345\257\271\351\275\220\346\226\271\345\274\217", Q_NULLPTR));
        label_2->setText(QApplication::translate("layout", "\350\241\214\351\227\264\350\267\235", Q_NULLPTR));
        label_3->setText(QApplication::translate("layout", "\346\256\265\351\227\264\350\267\235", Q_NULLPTR));
        firstLineIndent->setText(QApplication::translate("layout", "\351\246\226\350\241\214\347\274\251\350\277\233", Q_NULLPTR));
        changeIndent->setPrefix(QString());
        changeIndent->setSuffix(QApplication::translate("layout", " \345\255\227\347\254\246", Q_NULLPTR));
        accept->setText(QApplication::translate("layout", "\347\241\256\345\256\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class layout: public Ui_layout {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LAYOUT_H
