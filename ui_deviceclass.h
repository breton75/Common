/********************************************************************************
** Form generated from reading UI file 'sv_deviceclassZ11712.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef SV_DEVICECLASSZ11712_H
#define SV_DEVICECLASSZ11712_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SvClassDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *layoutID;
    QLabel *lblID;
    QLineEdit *editID;
    QHBoxLayout *layoutClassName;
    QLabel *lblClassName;
    QLineEdit *editClassName;
    QHBoxLayout *layoutLibPath;
    QLabel *lblLibPath;
    QLineEdit *editLibPath;
    QPushButton *bnLibPath;
    QVBoxLayout *layoutDescription;
    QLabel *lblDescription;
    QTextEdit *textDescription;
    QHBoxLayout *layoutButtons;
    QSpacerItem *horizontalSpacer;
    QPushButton *bnSave;
    QPushButton *bnCancel;

    enum ShowMode { smNew = 0, smEdit = 1 };
    
    void setupUi(QDialog *SvClassDialog = 0,
                 QString className = "",
                 QString libPath = "",
                 QString description = "",
                 int id = -1,
                 int showMode = smNew)
    {
        if (SvClassDialog->objectName().isEmpty())
            SvClassDialog->setObjectName(QStringLiteral("SvClassDialog"));
        SvClassDialog->resize(370, 248);
        verticalLayout_2 = new QVBoxLayout(SvClassDialog);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        groupBox = new QGroupBox(SvClassDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        layoutID = new QHBoxLayout();
        layoutID->setObjectName(QStringLiteral("layoutID"));
        lblID = new QLabel(groupBox);
        lblID->setObjectName(QStringLiteral("lblID"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lblID->sizePolicy().hasHeightForWidth());
        lblID->setSizePolicy(sizePolicy1);
        lblID->setMinimumSize(QSize(75, 0));
        lblID->setMaximumSize(QSize(75, 16777215));
        lblID->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        layoutID->addWidget(lblID);

        editID = new QLineEdit(groupBox);
        editID->setObjectName(QStringLiteral("editID"));
        editID->setStyleSheet(QStringLiteral("background-color: rgb(209, 209, 209);"));
        editID->setReadOnly(true);

        layoutID->addWidget(editID);


        verticalLayout->addLayout(layoutID);

        layoutClassName = new QHBoxLayout();
        layoutClassName->setObjectName(QStringLiteral("layoutClassName"));
        lblClassName = new QLabel(groupBox);
        lblClassName->setObjectName(QStringLiteral("lblClassName"));
        sizePolicy1.setHeightForWidth(lblClassName->sizePolicy().hasHeightForWidth());
        lblClassName->setSizePolicy(sizePolicy1);
        lblClassName->setMinimumSize(QSize(75, 0));
        lblClassName->setMaximumSize(QSize(75, 16777215));
        lblClassName->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        layoutClassName->addWidget(lblClassName);

        editClassName = new QLineEdit(groupBox);
        editClassName->setObjectName(QStringLiteral("editClassName"));

        layoutClassName->addWidget(editClassName);


        verticalLayout->addLayout(layoutClassName);

        layoutLibPath = new QHBoxLayout();
        layoutLibPath->setObjectName(QStringLiteral("layoutLibPath"));
        lblLibPath = new QLabel(groupBox);
        lblLibPath->setObjectName(QStringLiteral("lblLibPath"));
        sizePolicy1.setHeightForWidth(lblLibPath->sizePolicy().hasHeightForWidth());
        lblLibPath->setSizePolicy(sizePolicy1);
        lblLibPath->setMinimumSize(QSize(75, 0));
        lblLibPath->setMaximumSize(QSize(75, 16777215));
        lblLibPath->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        layoutLibPath->addWidget(lblLibPath);

        editLibPath = new QLineEdit(groupBox);
        editLibPath->setObjectName(QStringLiteral("editLibPath"));

        layoutLibPath->addWidget(editLibPath);

        bnLibPath = new QPushButton(groupBox);
        bnLibPath->setObjectName(QStringLiteral("bnLibPath"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(bnLibPath->sizePolicy().hasHeightForWidth());
        bnLibPath->setSizePolicy(sizePolicy2);
        bnLibPath->setMinimumSize(QSize(23, 0));
        bnLibPath->setMaximumSize(QSize(23, 16777215));

        layoutLibPath->addWidget(bnLibPath);


        verticalLayout->addLayout(layoutLibPath);

        layoutDescription = new QVBoxLayout();
        layoutDescription->setObjectName(QStringLiteral("layoutDescription"));
        lblDescription = new QLabel(groupBox);
        lblDescription->setObjectName(QStringLiteral("lblDescription"));
        sizePolicy1.setHeightForWidth(lblDescription->sizePolicy().hasHeightForWidth());
        lblDescription->setSizePolicy(sizePolicy1);
        lblDescription->setMinimumSize(QSize(55, 0));
        lblDescription->setMaximumSize(QSize(55, 16777215));
        lblDescription->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        layoutDescription->addWidget(lblDescription);

        textDescription = new QTextEdit(groupBox);
        textDescription->setObjectName(QStringLiteral("textDescription"));

        layoutDescription->addWidget(textDescription);


        verticalLayout->addLayout(layoutDescription);


        verticalLayout_2->addWidget(groupBox);

        layoutButtons = new QHBoxLayout();
        layoutButtons->setObjectName(QStringLiteral("layoutButtons"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        layoutButtons->addItem(horizontalSpacer);

        bnSave = new QPushButton(SvClassDialog);
        bnSave->setObjectName(QStringLiteral("bnSave"));
        sizePolicy2.setHeightForWidth(bnSave->sizePolicy().hasHeightForWidth());
        bnSave->setSizePolicy(sizePolicy2);
        bnSave->setMaximumSize(QSize(80, 16777215));
        bnSave->setDefault(true);

        layoutButtons->addWidget(bnSave);

        bnCancel = new QPushButton(SvClassDialog);
        bnCancel->setObjectName(QStringLiteral("bnCancel"));
        sizePolicy2.setHeightForWidth(bnCancel->sizePolicy().hasHeightForWidth());
        bnCancel->setSizePolicy(sizePolicy2);
        bnCancel->setMaximumSize(QSize(80, 16777215));

        layoutButtons->addWidget(bnCancel);


        verticalLayout_2->addLayout(layoutButtons);

        QWidget::setTabOrder(editClassName, editLibPath);
        QWidget::setTabOrder(editLibPath, bnLibPath);
        QWidget::setTabOrder(bnLibPath, bnSave);
        QWidget::setTabOrder(bnSave, bnCancel);
        QWidget::setTabOrder(bnCancel, editID);
        QWidget::setTabOrder(editID, textDescription);
        
        editClassName->setText(className);
        editLibPath->setText(libPath);
        textDescription->setText(description);

        retranslateUi(SvClassDialog, showMode, className);

        QMetaObject::connectSlotsByName(SvClassDialog);
    } // setupUi

    void retranslateUi(QDialog *SvClassDialog, int showMode, QString className)
    {
      QString title;
      title = QApplication::translate("SvBrandDialog", "Brand - ", 0);
      if(showMode = smNew)
        title = title + QApplication::translate("SvBrandDialog", "New", 0);
      else title = title + className;
      SvClassDialog->setWindowTitle(title);

        groupBox->setTitle(QString());
        lblID->setText(QApplication::translate("SvClassDialog", "ID", 0));
        lblClassName->setText(QApplication::translate("SvClassDialog", "Class name", 0));
        lblLibPath->setText(QApplication::translate("SvClassDialog", "Driver lib", 0));
        bnLibPath->setText(QApplication::translate("SvClassDialog", "...", 0));
        lblDescription->setText(QApplication::translate("SvClassDialog", "Description", 0));
        bnSave->setText(QApplication::translate("SvClassDialog", "Save", 0));
        bnCancel->setText(QApplication::translate("SvClassDialog", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class SvClassDialog: public Ui_SvClassDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // SV_DEVICECLASSZ11712_H
