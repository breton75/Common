/********************************************************************************
** Form generated from reading UI file 'sv_classeslistV11712.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef SV_DECIVESLIST_H
#define SV_DEVICESLIST_H

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

class Ui_SvDeviceListDialog
{
public:
    QVBoxLayout *verticalLayout;
    QTableView *tblDeviceList;
    QHBoxLayout *layoutButtons;
    QPushButton *bnNewClass;
    QPushButton *bnEditClass;
    QPushButton *bnDeleteClass;
    QSpacerItem *horizontalSpacer;
    QPushButton *bnSelect;
    QPushButton *bnClose;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(661, 377);
        verticalLayout = new QVBoxLayout(Dialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tblDeviceList = new QTableView(Dialog);
        tblDeviceList->setObjectName(QStringLiteral("tblDeviceList"));

        verticalLayout->addWidget(tblDeviceList);

        layoutButtons = new QHBoxLayout();
        layoutButtons->setObjectName(QStringLiteral("layoutButtons"));
        bnNewClass = new QPushButton(Dialog);
        bnNewClass->setObjectName(QStringLiteral("bnNewClass"));

        layoutButtons->addWidget(bnNewClass);

        bnEditClass = new QPushButton(Dialog);
        bnEditClass->setObjectName(QStringLiteral("bnEditClass"));

        layoutButtons->addWidget(bnEditClass);

        bnDeleteClass = new QPushButton(Dialog);
        bnDeleteClass->setObjectName(QStringLiteral("bnDeleteClass"));

        layoutButtons->addWidget(bnDeleteClass);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        layoutButtons->addItem(horizontalSpacer);

        bnSelect = new QPushButton(Dialog);
        bnSelect->setObjectName(QStringLiteral("bnSelect"));

        layoutButtons->addWidget(bnSelect);

        bnClose = new QPushButton(Dialog);
        bnClose->setObjectName(QStringLiteral("bnClose"));

        layoutButtons->addWidget(bnClose);


        verticalLayout->addLayout(layoutButtons);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0));
        bnNewClass->setText(QApplication::translate("Dialog", "New", 0));
        bnEditClass->setText(QApplication::translate("Dialog", "Edit", 0));
        bnDeleteClass->setText(QApplication::translate("Dialog", "Delete", 0));
        bnSelect->setText(QApplication::translate("Dialog", "Select", 0));
        bnClose->setText(QApplication::translate("Dialog", "Close", 0));
    } // retranslateUi

};

namespace Ui {
    class SvDeviceListDialog: public Ui_SvDeviceListDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // SV_DEVICESLIST_H
