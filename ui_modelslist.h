/********************************************************************************
** Form generated from reading UI file 'sv_modelslistk11712.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef SV_MODELSLISTK11712_H
#define SV_MODELSLISTK11712_H

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

class Ui_SvDevModelsListDialog
{
public:
    QVBoxLayout *verticalLayout;
    QTableView *tblModelsList;
    QHBoxLayout *layoutButtons;
    QPushButton *bnNewModel;
    QPushButton *bnEditModel;
    QPushButton *bnDeleteModel;
    QSpacerItem *horizontalSpacer;
    QPushButton *bnSelect;
    QPushButton *bnClose;

    void setupUi(QDialog *SvDevModelsListDialog)
    {
        if (SvDevModelsListDialog->objectName().isEmpty())
            SvDevModelsListDialog->setObjectName(QStringLiteral("SvDevModelsListDialog"));
        SvDevModelsListDialog->resize(661, 377);
        verticalLayout = new QVBoxLayout(SvDevModelsListDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tblModelsList = new QTableView(SvDevModelsListDialog);
        tblModelsList->setObjectName(QStringLiteral("tblModelsList"));

        verticalLayout->addWidget(tblModelsList);

        layoutButtons = new QHBoxLayout();
        layoutButtons->setObjectName(QStringLiteral("layoutButtons"));
        bnNewModel = new QPushButton(SvDevModelsListDialog);
        bnNewModel->setObjectName(QStringLiteral("bnNewModel"));

        layoutButtons->addWidget(bnNewModel);

        bnEditModel = new QPushButton(SvDevModelsListDialog);
        bnEditModel->setObjectName(QStringLiteral("bnEditModel"));

        layoutButtons->addWidget(bnEditModel);

        bnDeleteModel = new QPushButton(SvDevModelsListDialog);
        bnDeleteModel->setObjectName(QStringLiteral("bnDeleteModel"));

        layoutButtons->addWidget(bnDeleteModel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        layoutButtons->addItem(horizontalSpacer);

        bnSelect = new QPushButton(SvDevModelsListDialog);
        bnSelect->setObjectName(QStringLiteral("bnSelect"));

        layoutButtons->addWidget(bnSelect);

        bnClose = new QPushButton(SvDevModelsListDialog);
        bnClose->setObjectName(QStringLiteral("bnClose"));

        layoutButtons->addWidget(bnClose);


        verticalLayout->addLayout(layoutButtons);


        retranslateUi(SvDevModelsListDialog);

        QMetaObject::connectSlotsByName(SvDevModelsListDialog);
    } // setupUi

    void retranslateUi(QDialog *SvDevModelsListDialog)
    {
        SvDevModelsListDialog->setWindowTitle(QApplication::translate("SvDevModelsListDialog", "Dialog", 0));
        bnNewModel->setText(QApplication::translate("SvDevModelsListDialog", "New", 0));
        bnEditModel->setText(QApplication::translate("SvDevModelsListDialog", "Edit", 0));
        bnDeleteModel->setText(QApplication::translate("SvDevModelsListDialog", "Delete", 0));
        bnSelect->setText(QApplication::translate("SvDevModelsListDialog", "Select", 0));
        bnClose->setText(QApplication::translate("SvDevModelsListDialog", "Close", 0));
    } // retranslateUi

};

namespace Ui {
    class SvDevModelsListDialog: public Ui_SvDevModelsListDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // SV_MODELSLISTK11712_H
