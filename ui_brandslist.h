/********************************************************************************
** Form generated from reading UI file 'sv_brandslistRy3844.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef SV_BRANDSLISTRY3844_H
#define SV_BRANDSLISTRY3844_H

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

class Ui_SvDevBrandsListDialog
{
public:
    QVBoxLayout *verticalLayout;
    QTableView *tblBrandsList;
    QHBoxLayout *layoutButtons;
    QPushButton *bnNewBrand;
    QPushButton *bnEditBrand;
    QPushButton *bnDeleteBrand;
    QSpacerItem *horizontalSpacer;
    QPushButton *bnSelect;
    QPushButton *bnClose;

    void setupUi(QDialog *SvDevBrandsListDialog)
    {
        if (SvDevBrandsListDialog->objectName().isEmpty())
            SvDevBrandsListDialog->setObjectName(QStringLiteral("SvDevBrandsListDialog"));
        SvDevBrandsListDialog->resize(661, 377);
        verticalLayout = new QVBoxLayout(SvDevBrandsListDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tblBrandsList = new QTableView(SvDevBrandsListDialog);
        tblBrandsList->setObjectName(QStringLiteral("tblBrandsList"));

        verticalLayout->addWidget(tblBrandsList);

        layoutButtons = new QHBoxLayout();
        layoutButtons->setObjectName(QStringLiteral("layoutButtons"));
        bnNewBrand = new QPushButton(SvDevBrandsListDialog);
        bnNewBrand->setObjectName(QStringLiteral("bnNewBrand"));

        layoutButtons->addWidget(bnNewBrand);

        bnEditBrand = new QPushButton(SvDevBrandsListDialog);
        bnEditBrand->setObjectName(QStringLiteral("bnEditBrand"));

        layoutButtons->addWidget(bnEditBrand);

        bnDeleteBrand = new QPushButton(SvDevBrandsListDialog);
        bnDeleteBrand->setObjectName(QStringLiteral("bnDeleteBrand"));

        layoutButtons->addWidget(bnDeleteBrand);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        layoutButtons->addItem(horizontalSpacer);

        bnSelect = new QPushButton(SvDevBrandsListDialog);
        bnSelect->setObjectName(QStringLiteral("bnSelect"));

        layoutButtons->addWidget(bnSelect);

        bnClose = new QPushButton(SvDevBrandsListDialog);
        bnClose->setObjectName(QStringLiteral("bnClose"));

        layoutButtons->addWidget(bnClose);


        verticalLayout->addLayout(layoutButtons);


        retranslateUi(SvDevBrandsListDialog);

        QMetaObject::connectSlotsByName(SvDevBrandsListDialog);
    } // setupUi

    void retranslateUi(QDialog *SvDevBrandsListDialog)
    {
        SvDevBrandsListDialog->setWindowTitle(QApplication::translate("SvDevBrandsListDialog", "Dialog", 0));
        bnNewBrand->setText(QApplication::translate("SvDevBrandsListDialog", "New", 0));
        bnEditBrand->setText(QApplication::translate("SvDevBrandsListDialog", "Edit", 0));
        bnDeleteBrand->setText(QApplication::translate("SvDevBrandsListDialog", "Delete", 0));
        bnSelect->setText(QApplication::translate("SvDevBrandsListDialog", "Select", 0));
        bnClose->setText(QApplication::translate("SvDevBrandsListDialog", "Close", 0));
    } // retranslateUi

};

namespace Ui {
    class SvDevBrandsListDialog: public Ui_SvDevBrandsListDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // SV_BRANDSLISTRY3844_H
