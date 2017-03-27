/********************************************************************************
** Form generated from reading UI file 'sv_devicebrandI11712.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef SV_DEVICEBRANDI11712_H
#define SV_DEVICEBRANDI11712_H

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

class Ui_SvBrandDialog
{
public:
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *layoutID;
    QLabel *lblID;
    QLineEdit *editID;
    QHBoxLayout *layoutBrandName;
    QLabel *lblBrandName;
    QLineEdit *editBrandName;
    QHBoxLayout *layoutClass;
    QLabel *lblAddress;
    QLineEdit *editAddress;
    QHBoxLayout *layoutBrand;
    QLabel *lblEmail;
    QLineEdit *editEmail;
    QHBoxLayout *layoutLibPath;
    QLabel *lblSite;
    QLineEdit *editSite;
    QVBoxLayout *layoutDescription;
    QLabel *lblDescription;
    QTextEdit *textDescription;
    QHBoxLayout *layoutButtons;
    QSpacerItem *horizontalSpacer;
    QPushButton *bnSave;
    QPushButton *bnCancel;

    enum ShowMode { smNew = 0, smEdit = 1 };
    
    void setupUi(QDialog *SvBrandDialog = 0,
                 QString brandName = "",
                 QString description = "",
                 int id = -1,
                 int showMode = smNew)
    {
      if (SvBrandDialog->objectName().isEmpty())
          SvBrandDialog->setObjectName(QStringLiteral("SvBrandDialog"));
      SvBrandDialog->resize(370, 320);
      verticalLayout_3 = new QVBoxLayout(SvBrandDialog);
      verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
      groupBox = new QGroupBox(SvBrandDialog);
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

      layoutBrandName = new QHBoxLayout();
      layoutBrandName->setObjectName(QStringLiteral("layoutBrandName"));
      lblBrandName = new QLabel(groupBox);
      lblBrandName->setObjectName(QStringLiteral("lblBrandName"));
      sizePolicy1.setHeightForWidth(lblBrandName->sizePolicy().hasHeightForWidth());
      lblBrandName->setSizePolicy(sizePolicy1);
      lblBrandName->setMinimumSize(QSize(75, 0));
      lblBrandName->setMaximumSize(QSize(75, 16777215));
      lblBrandName->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

      layoutBrandName->addWidget(lblBrandName);

      editBrandName = new QLineEdit(groupBox);
      editBrandName->setObjectName(QStringLiteral("editBrandName"));

      layoutBrandName->addWidget(editBrandName);


      verticalLayout->addLayout(layoutBrandName);

      layoutClass = new QHBoxLayout();
      layoutClass->setObjectName(QStringLiteral("layoutClass"));
      lblAddress = new QLabel(groupBox);
      lblAddress->setObjectName(QStringLiteral("lblAddress"));
      sizePolicy1.setHeightForWidth(lblAddress->sizePolicy().hasHeightForWidth());
      lblAddress->setSizePolicy(sizePolicy1);
      lblAddress->setMinimumSize(QSize(75, 0));
      lblAddress->setMaximumSize(QSize(75, 16777215));
      lblAddress->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

      layoutClass->addWidget(lblAddress);

      editAddress = new QLineEdit(groupBox);
      editAddress->setObjectName(QStringLiteral("editAddress"));
      QFont font;
      font.setBold(false);
      font.setWeight(50);
      editAddress->setFont(font);
      editAddress->setStyleSheet(QStringLiteral(""));

      layoutClass->addWidget(editAddress);


      verticalLayout->addLayout(layoutClass);

      layoutBrand = new QHBoxLayout();
      layoutBrand->setObjectName(QStringLiteral("layoutBrand"));
      lblEmail = new QLabel(groupBox);
      lblEmail->setObjectName(QStringLiteral("lblEmail"));
      sizePolicy1.setHeightForWidth(lblEmail->sizePolicy().hasHeightForWidth());
      lblEmail->setSizePolicy(sizePolicy1);
      lblEmail->setMinimumSize(QSize(75, 0));
      lblEmail->setMaximumSize(QSize(75, 16777215));
      lblEmail->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

      layoutBrand->addWidget(lblEmail);

      editEmail = new QLineEdit(groupBox);
      editEmail->setObjectName(QStringLiteral("editEmail"));
      editEmail->setFont(font);
      editEmail->setStyleSheet(QStringLiteral(""));

      layoutBrand->addWidget(editEmail);


      verticalLayout->addLayout(layoutBrand);

      layoutLibPath = new QHBoxLayout();
      layoutLibPath->setObjectName(QStringLiteral("layoutLibPath"));
      lblSite = new QLabel(groupBox);
      lblSite->setObjectName(QStringLiteral("lblSite"));
      sizePolicy1.setHeightForWidth(lblSite->sizePolicy().hasHeightForWidth());
      lblSite->setSizePolicy(sizePolicy1);
      lblSite->setMinimumSize(QSize(75, 0));
      lblSite->setMaximumSize(QSize(75, 16777215));
      lblSite->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

      layoutLibPath->addWidget(lblSite);

      editSite = new QLineEdit(groupBox);
      editSite->setObjectName(QStringLiteral("editSite"));

      layoutLibPath->addWidget(editSite);


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


      verticalLayout_3->addWidget(groupBox);

      layoutButtons = new QHBoxLayout();
      layoutButtons->setObjectName(QStringLiteral("layoutButtons"));
      horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

      layoutButtons->addItem(horizontalSpacer);

      bnSave = new QPushButton(SvBrandDialog);
      bnSave->setObjectName(QStringLiteral("bnSave"));
      QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
      sizePolicy2.setHorizontalStretch(0);
      sizePolicy2.setVerticalStretch(0);
      sizePolicy2.setHeightForWidth(bnSave->sizePolicy().hasHeightForWidth());
      bnSave->setSizePolicy(sizePolicy2);
      bnSave->setMaximumSize(QSize(80, 16777215));
      bnSave->setDefault(true);

      layoutButtons->addWidget(bnSave);

      bnCancel = new QPushButton(SvBrandDialog);
      bnCancel->setObjectName(QStringLiteral("bnCancel"));
      sizePolicy2.setHeightForWidth(bnCancel->sizePolicy().hasHeightForWidth());
      bnCancel->setSizePolicy(sizePolicy2);
      bnCancel->setMaximumSize(QSize(80, 16777215));

      layoutButtons->addWidget(bnCancel);


      verticalLayout_3->addLayout(layoutButtons);

      QWidget::setTabOrder(editBrandName, editAddress);
      QWidget::setTabOrder(textDescription, bnSave);
      QWidget::setTabOrder(bnSave, bnCancel);
      QWidget::setTabOrder(bnCancel, editID);

        if(id != -1) editID->setText(QString("%1").arg(id));
        editBrandName->setText(brandName);
        textDescription->setText(description);
        
        retranslateUi(SvBrandDialog, showMode, brandName);

        QMetaObject::connectSlotsByName(SvBrandDialog);
    } // setupUi

    void retranslateUi(QDialog *SvBrandDialog, int showMode, QString brandName)
    {
      QString title;
      title = QApplication::translate("SvBrandDialog", "Brand - ", 0);
      if(showMode = smNew)
        title = title + QApplication::translate("SvBrandDialog", "New", 0);
      else title = title + brandName;
      SvBrandDialog->setWindowTitle(title);
      
        groupBox->setTitle(QString());
        lblID->setText(QApplication::translate("SvBrandDialog", "ID", 0));
        lblBrandName->setText(QApplication::translate("SvBrandDialog", "Brand name", 0));
        lblAddress->setText(QApplication::translate("SvBrandDialog", "Address", 0));
        lblEmail->setText(QApplication::translate("SvBrandDialog", "Email", 0));
        lblSite->setText(QApplication::translate("SvBrandDialog", "Site", 0));
        lblDescription->setText(QApplication::translate("SvBrandDialog", "Description", 0));
        bnSave->setText(QApplication::translate("SvBrandDialog", "Save", 0));
        bnCancel->setText(QApplication::translate("SvBrandDialog", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class SvBrandDialog: public Ui_SvBrandDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // SV_DEVICEBRANDI11712_H
