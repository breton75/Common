/********************************************************************************
** Form generated from reading UI file 'sv_classeslistV11712.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef SV_CLASSESLISTV11712_H
#define SV_CLASSESLISTV11712_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SvDevClassesListDialog
{
public:
    QVBoxLayout *verticalLayout;
    QTableView *tblClassesList;
    QHBoxLayout *layoutButtons;
    QPushButton *bnNewClass;
    QPushButton *bnEditClass;
    QPushButton *bnDeleteClass;
    QSpacerItem *horizontalSpacer;
    QPushButton *bnSelect;
    QPushButton *bnClose;

    void setupUi(QDialog *SvDevClassesListDialog)
    {
        if (SvDevClassesListDialog->objectName().isEmpty())
            SvDevClassesListDialog->setObjectName(QStringLiteral("SvDevClassesListDialog"));
        SvDevClassesListDialog->resize(661, 377);
        verticalLayout = new QVBoxLayout(SvDevClassesListDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tblClassesList = new QTableView(SvDevClassesListDialog);
        tblClassesList->setObjectName(QStringLiteral("tblClassesList"));

        verticalLayout->addWidget(tblClassesList);

        layoutButtons = new QHBoxLayout();
        layoutButtons->setObjectName(QStringLiteral("layoutButtons"));
        bnNewClass = new QPushButton(SvDevClassesListDialog);
        bnNewClass->setObjectName(QStringLiteral("bnNewClass"));

        layoutButtons->addWidget(bnNewClass);

        bnEditClass = new QPushButton(SvDevClassesListDialog);
        bnEditClass->setObjectName(QStringLiteral("bnEditClass"));

        layoutButtons->addWidget(bnEditClass);

        bnDeleteClass = new QPushButton(SvDevClassesListDialog);
        bnDeleteClass->setObjectName(QStringLiteral("bnDeleteClass"));

        layoutButtons->addWidget(bnDeleteClass);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        layoutButtons->addItem(horizontalSpacer);

        bnSelect = new QPushButton(SvDevClassesListDialog);
        bnSelect->setObjectName(QStringLiteral("bnSelect"));

        layoutButtons->addWidget(bnSelect);

        bnClose = new QPushButton(SvDevClassesListDialog);
        bnClose->setObjectName(QStringLiteral("bnClose"));

        layoutButtons->addWidget(bnClose);


        verticalLayout->addLayout(layoutButtons);


        retranslateUi(SvDevClassesListDialog);

        QMetaObject::connectSlotsByName(SvDevClassesListDialog);
    } // setupUi

    void retranslateUi(QDialog *SvDevClassesListDialog)
    {
        SvDevClassesListDialog->setWindowTitle(QApplication::translate("SvDevClassesListDialog", "Dialog", 0));
        bnNewClass->setText(QApplication::translate("SvDevClassesListDialog", "New", 0));
        bnEditClass->setText(QApplication::translate("SvDevClassesListDialog", "Edit", 0));
        bnDeleteClass->setText(QApplication::translate("SvDevClassesListDialog", "Delete", 0));
        bnSelect->setText(QApplication::translate("SvDevClassesListDialog", "Select", 0));
        bnClose->setText(QApplication::translate("SvDevClassesListDialog", "Close", 0));
    } // retranslateUi

};

namespace Ui {
    class SvDevClassesListDialog: public Ui_SvDevClassesListDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // SV_CLASSESLISTV11712_H
