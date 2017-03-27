/********************************************************************************
** Form generated from reading UI file 'sv_devicetype.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

/* автоматически генерируемый код */
#ifndef UI_SV_DEVICEMODEL_H
#define UI_SV_DEVICEMODEL_H

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

class Ui_SvDeviceModel
{
public:
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *layoutID;
    QLabel *lblID;
    QLineEdit *editID;
    QHBoxLayout *layoutModelName;
    QLabel *lblModelName;
    QLineEdit *editModelName;
    QHBoxLayout *layoutClass;
    QLabel *lblClass;
    QLineEdit *editClass;
    QPushButton *bnSelectClass;
    QPushButton *bnNewClass;
    QHBoxLayout *layoutBrand;
    QLabel *lblBrand;
    QLineEdit *editBrand;
    QPushButton *bnSelectBrand;
    QPushButton *bnNewBrand;
    QHBoxLayout *layoutLibPath;
    QLabel *lblLibPath;
    QLineEdit *editLibPath;
    QPushButton *bnLibPath;
    QVBoxLayout *layoutDescription;
    QLabel *lblDescription;
    QTextEdit *textDescription;
    QHBoxLayout *layoutButtons;
    QSpacerItem *horizontalSpacer;
    QPushButton *bnOk;
    QPushButton *bnCancel;
    /* конец автоматически генерируемого кода */
    

    enum ShowMode { smNew = 0, smEdit = 1 };
    enum DataType { dtMessage = 0, dtStream = 1 };
    
    void setupUi(QDialog *SvDeviceModelDialog,
                 int showMode = smNew,
                 QString modelName = "",
                 QString className = "",
                 QString brandName = "",
                 QString libPath = "",
                 QString description = "",
                 int dataType = dtMessage,
                 int id = -1)
    {
      /* автоматически генерируемый код */
      if (SvDeviceModelDialog->objectName().isEmpty())
                 SvDeviceModelDialog->setObjectName(QStringLiteral("SvDeviceModelDialog"));
      SvDeviceModelDialog->resize(370, 320);
      verticalLayout_3 = new QVBoxLayout(SvDeviceModelDialog);
      verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
      groupBox = new QGroupBox(SvDeviceModelDialog);
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
     
      layoutModelName = new QHBoxLayout();
      layoutModelName->setObjectName(QStringLiteral("layoutModelName"));
      lblModelName = new QLabel(groupBox);
      lblModelName->setObjectName(QStringLiteral("lblModelName"));
      sizePolicy1.setHeightForWidth(lblModelName->sizePolicy().hasHeightForWidth());
      lblModelName->setSizePolicy(sizePolicy1);
      lblModelName->setMinimumSize(QSize(75, 0));
      lblModelName->setMaximumSize(QSize(75, 16777215));
      lblModelName->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
     
      layoutModelName->addWidget(lblModelName);
     
      editModelName = new QLineEdit(groupBox);
      editModelName->setObjectName(QStringLiteral("editModelName"));
     
      layoutModelName->addWidget(editModelName);
     
     
      verticalLayout->addLayout(layoutModelName);
     
      layoutClass = new QHBoxLayout();
      layoutClass->setObjectName(QStringLiteral("layoutClass"));
      lblClass = new QLabel(groupBox);
      lblClass->setObjectName(QStringLiteral("lblClass"));
      sizePolicy1.setHeightForWidth(lblClass->sizePolicy().hasHeightForWidth());
      lblClass->setSizePolicy(sizePolicy1);
      lblClass->setMinimumSize(QSize(75, 0));
      lblClass->setMaximumSize(QSize(75, 16777215));
      lblClass->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
     
      layoutClass->addWidget(lblClass);
     
      editClass = new QLineEdit(groupBox);
      editClass->setObjectName(QStringLiteral("editClass"));
      QFont font;
      font.setBold(false);
      font.setWeight(50);
      editClass->setFont(font);
      editClass->setStyleSheet(QStringLiteral("background-color: rgb(209, 209, 209);"));
      editClass->setReadOnly(true);
     
      layoutClass->addWidget(editClass);
     
      bnSelectClass = new QPushButton(groupBox);
      bnSelectClass->setObjectName(QStringLiteral("bnSelectClass"));
      QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
      sizePolicy2.setHorizontalStretch(0);
      sizePolicy2.setVerticalStretch(0);
      sizePolicy2.setHeightForWidth(bnSelectClass->sizePolicy().hasHeightForWidth());
      bnSelectClass->setSizePolicy(sizePolicy2);
      bnSelectClass->setMinimumSize(QSize(23, 0));
      bnSelectClass->setMaximumSize(QSize(23, 16777215));
     
      layoutClass->addWidget(bnSelectClass);
     
      bnNewClass = new QPushButton(groupBox);
      bnNewClass->setObjectName(QStringLiteral("bnNewClass"));
      sizePolicy2.setHeightForWidth(bnNewClass->sizePolicy().hasHeightForWidth());
      bnNewClass->setSizePolicy(sizePolicy2);
      bnNewClass->setMinimumSize(QSize(23, 23));
      bnNewClass->setMaximumSize(QSize(23, 23));
     
      layoutClass->addWidget(bnNewClass);
     
     
      verticalLayout->addLayout(layoutClass);
     
      layoutBrand = new QHBoxLayout();
      layoutBrand->setObjectName(QStringLiteral("layoutBrand"));
      lblBrand = new QLabel(groupBox);
      lblBrand->setObjectName(QStringLiteral("lblBrand"));
      sizePolicy1.setHeightForWidth(lblBrand->sizePolicy().hasHeightForWidth());
      lblBrand->setSizePolicy(sizePolicy1);
      lblBrand->setMinimumSize(QSize(75, 0));
      lblBrand->setMaximumSize(QSize(75, 16777215));
      lblBrand->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
     
      layoutBrand->addWidget(lblBrand);
     
      editBrand = new QLineEdit(groupBox);
      editBrand->setObjectName(QStringLiteral("editBrand"));
      editBrand->setFont(font);
      editBrand->setStyleSheet(QStringLiteral("background-color: rgb(209, 209, 209);"));
      editBrand->setReadOnly(true);
     
      layoutBrand->addWidget(editBrand);
     
      bnSelectBrand = new QPushButton(groupBox);
      bnSelectBrand->setObjectName(QStringLiteral("bnSelectBrand"));
      sizePolicy2.setHeightForWidth(bnSelectBrand->sizePolicy().hasHeightForWidth());
      bnSelectBrand->setSizePolicy(sizePolicy2);
      bnSelectBrand->setMinimumSize(QSize(23, 0));
      bnSelectBrand->setMaximumSize(QSize(23, 16777215));
     
      layoutBrand->addWidget(bnSelectBrand);
     
      bnNewBrand = new QPushButton(groupBox);
      bnNewBrand->setObjectName(QStringLiteral("bnNewBrand"));
      sizePolicy2.setHeightForWidth(bnNewBrand->sizePolicy().hasHeightForWidth());
      bnNewBrand->setSizePolicy(sizePolicy2);
      bnNewBrand->setMinimumSize(QSize(23, 23));
      bnNewBrand->setMaximumSize(QSize(23, 23));
     
      layoutBrand->addWidget(bnNewBrand);
     
     
      verticalLayout->addLayout(layoutBrand);
     
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
     
     
      verticalLayout_3->addWidget(groupBox);
     
      layoutButtons = new QHBoxLayout();
      layoutButtons->setObjectName(QStringLiteral("layoutButtons"));
      horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
     
      layoutButtons->addItem(horizontalSpacer);
     
      bnOk = new QPushButton(SvDeviceModelDialog);
      bnOk->setObjectName(QStringLiteral("bnOk"));
      sizePolicy2.setHeightForWidth(bnOk->sizePolicy().hasHeightForWidth());
      bnOk->setSizePolicy(sizePolicy2);
      bnOk->setMaximumSize(QSize(80, 16777215));
      bnOk->setDefault(true);
     
      layoutButtons->addWidget(bnOk);
     
      bnCancel = new QPushButton(SvDeviceModelDialog);
      bnCancel->setObjectName(QStringLiteral("bnCancel"));
      sizePolicy2.setHeightForWidth(bnCancel->sizePolicy().hasHeightForWidth());
      bnCancel->setSizePolicy(sizePolicy2);
      bnCancel->setMaximumSize(QSize(80, 16777215));
     
      layoutButtons->addWidget(bnCancel);
     
     
      verticalLayout_3->addLayout(layoutButtons);
     
      QWidget::setTabOrder(editModelName, editClass);
      QWidget::setTabOrder(editClass, bnSelectClass);
      QWidget::setTabOrder(bnSelectClass, bnNewClass);
      QWidget::setTabOrder(bnNewClass, editBrand);
      QWidget::setTabOrder(editBrand, bnSelectBrand);
      QWidget::setTabOrder(bnSelectBrand, bnNewBrand);
      QWidget::setTabOrder(bnNewBrand, editLibPath);
      QWidget::setTabOrder(editLibPath, bnLibPath);
      QWidget::setTabOrder(bnLibPath, textDescription);
      QWidget::setTabOrder(textDescription, bnOk);
      QWidget::setTabOrder(bnOk, bnCancel);
      QWidget::setTabOrder(bnCancel, editID);

      /* конец автоматически генерируемого текста */
        
      if(id != -1) editID->setText(QString("%1").arg(id));
      editModelName->setText(modelName);
      editClass->setText(className);  
      editBrand->setText(brandName);
      editLibPath->setText(libPath);        
      textDescription->setText(description);

      retranslateUi(SvDeviceModelDialog, showMode, modelName);

      QMetaObject::connectSlotsByName(SvDeviceModelDialog);
      
    } // setupUi

    void retranslateUi(QDialog *Dialog, int showMode, QString modelName)
    {
      QString title;
      title = QApplication::translate("SvDeviceModel", "Device model: ", 0);
      if(showMode = smNew)
        title = title + QApplication::translate("SvDeviceModel", "New", 0);
      else title = title + modelName;
      
      Dialog->setWindowTitle(title);
        
      groupBox->setTitle(QString());
      lblID->setText(QApplication::translate("SvDeviceModel", "ID", 0));
      lblModelName->setText(QApplication::translate("SvDeviceModel", "Model name", 0));
      lblClass->setText(QApplication::translate("SvDeviceModel", "Device class", 0));
      bnSelectClass->setText(QApplication::translate("SvDeviceModel", "...", 0));
      bnNewClass->setText(QApplication::translate("SvDeviceModel", "+", 0));
      lblBrand->setText(QApplication::translate("SvDeviceModel", "Brand", 0));
      bnSelectBrand->setText(QApplication::translate("SvDeviceModel", "...", 0));
      bnNewBrand->setText(QApplication::translate("SvDeviceModel", "+", 0));
      lblLibPath->setText(QApplication::translate("SvDeviceModel", "Driver lib", 0));
      bnLibPath->setText(QApplication::translate("SvDeviceModel", "...", 0));
      lblDescription->setText(QApplication::translate("SvDeviceModel", "Description", 0));
      bnOk->setText(QApplication::translate("SvDeviceModel", "Save", 0));
      bnCancel->setText(QApplication::translate("SvDeviceModel", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class SvDeviceModelDialog: public Ui_SvDeviceModel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SV_DEVICEMODEL_H
