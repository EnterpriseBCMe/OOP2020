/********************************************************************************
** Form generated from reading UI file 'findreplace.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDREPLACE_H
#define UI_FINDREPLACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_findreplace
{
public:
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *label_find;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *le_find;
    QPushButton *findNext;
    QLabel *label_replace;
    QHBoxLayout *horizontalLayout;
    QLineEdit *le_replace;
    QPushButton *replace;
    QCheckBox *caseSensitive;
    QCheckBox *cycle;

    void setupUi(QDialog *findreplace)
    {
        if (findreplace->objectName().isEmpty())
            findreplace->setObjectName(QStringLiteral("findreplace"));
        findreplace->resize(352, 171);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(findreplace->sizePolicy().hasHeightForWidth());
        findreplace->setSizePolicy(sizePolicy);
        findreplace->setMinimumSize(QSize(0, 0));
        findreplace->setMaximumSize(QSize(999999, 999999));
        horizontalLayout_3 = new QHBoxLayout(findreplace);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_find = new QLabel(findreplace);
        label_find->setObjectName(QStringLiteral("label_find"));

        verticalLayout->addWidget(label_find);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        le_find = new QLineEdit(findreplace);
        le_find->setObjectName(QStringLiteral("le_find"));

        horizontalLayout_2->addWidget(le_find);

        findNext = new QPushButton(findreplace);
        findNext->setObjectName(QStringLiteral("findNext"));

        horizontalLayout_2->addWidget(findNext);


        verticalLayout->addLayout(horizontalLayout_2);

        label_replace = new QLabel(findreplace);
        label_replace->setObjectName(QStringLiteral("label_replace"));

        verticalLayout->addWidget(label_replace);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        le_replace = new QLineEdit(findreplace);
        le_replace->setObjectName(QStringLiteral("le_replace"));

        horizontalLayout->addWidget(le_replace);

        replace = new QPushButton(findreplace);
        replace->setObjectName(QStringLiteral("replace"));

        horizontalLayout->addWidget(replace);


        verticalLayout->addLayout(horizontalLayout);

        caseSensitive = new QCheckBox(findreplace);
        caseSensitive->setObjectName(QStringLiteral("caseSensitive"));

        verticalLayout->addWidget(caseSensitive);

        cycle = new QCheckBox(findreplace);
        cycle->setObjectName(QStringLiteral("cycle"));
        cycle->setChecked(true);

        verticalLayout->addWidget(cycle);


        horizontalLayout_3->addLayout(verticalLayout);


        retranslateUi(findreplace);

        QMetaObject::connectSlotsByName(findreplace);
    } // setupUi

    void retranslateUi(QDialog *findreplace)
    {
        findreplace->setWindowTitle(QApplication::translate("findreplace", "Dialog", Q_NULLPTR));
        label_find->setText(QApplication::translate("findreplace", "\346\237\245\346\211\276", Q_NULLPTR));
        findNext->setText(QApplication::translate("findreplace", "\346\237\245\346\211\276\344\270\213\344\270\200\344\270\252", Q_NULLPTR));
        label_replace->setText(QApplication::translate("findreplace", "\346\233\277\346\215\242", Q_NULLPTR));
        replace->setText(QApplication::translate("findreplace", "\346\233\277\346\215\242", Q_NULLPTR));
        caseSensitive->setText(QApplication::translate("findreplace", "\345\214\272\345\210\206\345\244\247\345\260\217\345\206\231", Q_NULLPTR));
        cycle->setText(QApplication::translate("findreplace", "\345\276\252\347\216\257", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class findreplace: public Ui_findreplace {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDREPLACE_H
