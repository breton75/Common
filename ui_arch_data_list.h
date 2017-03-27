/********************************************************************************
** Form generated from reading UI file 'sv_arch_data_listNX5980.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef SV_ARCH_DATA_LISTNX5980_H
#define SV_ARCH_DATA_LISTNX5980_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SvArchDataListDialog
{
public:
    QVBoxLayout *verticalLayout;
    QListView *listData;
    QHBoxLayout *layoutButtons;
    QSpacerItem *spacer1;
    QPushButton *bnSelect;
    QPushButton *bnClose;

    void setupUi(QDialog *SvArchDataListDialog)
    {
        if (SvArchDataListDialog->objectName().isEmpty())
            SvArchDataListDialog->setObjectName(QStringLiteral("SvArchDataListDialog"));
        SvArchDataListDialog->resize(320, 377);
        verticalLayout = new QVBoxLayout(SvArchDataListDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        listData = new QListView(SvArchDataListDialog);
        listData->setObjectName(QStringLiteral("listData"));
        listData->setMovement(QListView::Static);
        listData->setViewMode(QListView::ListMode);

        verticalLayout->addWidget(listData);

        layoutButtons = new QHBoxLayout();
        layoutButtons->setObjectName(QStringLiteral("layoutButtons"));
        spacer1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        layoutButtons->addItem(spacer1);

        bnSelect = new QPushButton(SvArchDataListDialog);
        bnSelect->setObjectName(QStringLiteral("bnSelect"));

        layoutButtons->addWidget(bnSelect);

        bnClose = new QPushButton(SvArchDataListDialog);
        bnClose->setObjectName(QStringLiteral("bnClose"));

        layoutButtons->addWidget(bnClose);


        verticalLayout->addLayout(layoutButtons);
        
        retranslateUi(SvArchDataListDialog);

        QMetaObject::connectSlotsByName(SvArchDataListDialog);
    } // setupUi

    void retranslateUi(QDialog *SvArchDataListDialog)
    {
        SvArchDataListDialog->setWindowTitle(QApplication::translate("SvArchDataListDialog", "Dialog", 0));
        bnSelect->setText(QApplication::translate("SvArchDataListDialog", "Select", 0));
        bnClose->setText(QApplication::translate("SvArchDataListDialog", "Close", 0));
    } // retranslateUi

};

namespace Ui {
    class SvArchDataListDialog: public Ui_SvArchDataListDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // SV_ARCH_DATA_LISTNX5980_H
