/********************************************************************************
** Form generated from reading UI file 'sv_deviceyO7120.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef SV_DEVICE_H
#define SV_DEVICE_H

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
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SvDevice
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *gbGeneral;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *layoutID;
    QLabel *lblID;
    QLineEdit *editID;
    QHBoxLayout *layoutDevName;
    QLabel *lblDevName;
    QLineEdit *editDevName;
    QHBoxLayout *layoutIPPort;
    QLabel *lblIP;
    QLineEdit *editIP;
    QLabel *lblPort;
    QLineEdit *editPort;
    QGroupBox *gbModel;
    QVBoxLayout *layoutModel;
    QHBoxLayout *layoutModelName;
    QLabel *lblModelName;
    QLineEdit *editModelName;
    QHBoxLayout *layoutClass;
    QLabel *lblClass;
    QLineEdit *editClass;
    QHBoxLayout *layoutBrand;
    QLabel *lblBrand;
    QLineEdit *editBrand;
    QHBoxLayout *layoutDriver;
    QLabel *lblDriver;
    QLineEdit *editDriver;
    QHBoxLayout *layoutModelButtons;
    QSpacerItem *hSpacerModelButtons;
    QPushButton *bnNewModel;
    QPushButton *bnSelectModel;
    QGroupBox *gbLocation;
    QHBoxLayout *horizontalLayout;
    QLabel *lblX;
    QSpinBox *sbX;
    QLabel *lblY;
    QSpinBox *sbY;
    QLabel *lblZ;
    QSpinBox *sbZ;
    QVBoxLayout *layoutDescription;
    QLabel *lblDescription;
    QTextEdit *textDescription;
    QHBoxLayout *layoutButtons;
    QSpacerItem *hSpacerButtons;
    QPushButton *bnSave;
    QPushButton *bnCancel;

    enum ShowMode { smNew = 0, smEdit = 1 };
    
    void setupUi(QDialog *SvDevice,
                 QString deviceName,
                 QString ip,
                 int port,
                 QString modelName,
                 QString clssName,
                 QString brandName,
                 QString libPath,
                 QString description,
                 int locationX,
                 int locationY,
                 int locationZ,
                 int id,
                 int showMode)
    {
      if (SvDevice->objectName().isEmpty())
          SvDevice->setObjectName(QStringLiteral("SvDevice"));
      SvDevice->resize(370, 513);
      verticalLayout_2 = new QVBoxLayout(SvDevice);
      verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
      groupBox = new QGroupBox(SvDevice);
      groupBox->setObjectName(QStringLiteral("groupBox"));
      QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
      sizePolicy.setHorizontalStretch(0);
      sizePolicy.setVerticalStretch(0);
      sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
      groupBox->setSizePolicy(sizePolicy);
      verticalLayout_3 = new QVBoxLayout(groupBox);
      verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
      gbGeneral = new QGroupBox(groupBox);
      gbGeneral->setObjectName(QStringLiteral("gbGeneral"));
      QFont font;
      font.setBold(true);
      font.setWeight(75);
      gbGeneral->setFont(font);
      verticalLayout = new QVBoxLayout(gbGeneral);
      verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
      layoutID = new QHBoxLayout();
      layoutID->setObjectName(QStringLiteral("layoutID"));
      lblID = new QLabel(gbGeneral);
      lblID->setObjectName(QStringLiteral("lblID"));
      QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
      sizePolicy1.setHorizontalStretch(0);
      sizePolicy1.setVerticalStretch(0);
      sizePolicy1.setHeightForWidth(lblID->sizePolicy().hasHeightForWidth());
      lblID->setSizePolicy(sizePolicy1);
      lblID->setMinimumSize(QSize(75, 0));
      lblID->setMaximumSize(QSize(55, 16777215));
      QFont font1;
      font1.setBold(false);
      font1.setWeight(50);
      lblID->setFont(font1);
      lblID->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

      layoutID->addWidget(lblID);

      editID = new QLineEdit(gbGeneral);
      editID->setObjectName(QStringLiteral("editID"));
      QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
      sizePolicy2.setHorizontalStretch(0);
      sizePolicy2.setVerticalStretch(0);
      sizePolicy2.setHeightForWidth(editID->sizePolicy().hasHeightForWidth());
      editID->setSizePolicy(sizePolicy2);
      editID->setFont(font1);
      editID->setStyleSheet(QStringLiteral("background-color: rgb(209, 209, 209);"));
      editID->setReadOnly(true);

      layoutID->addWidget(editID);


      verticalLayout->addLayout(layoutID);

      layoutDevName = new QHBoxLayout();
      layoutDevName->setObjectName(QStringLiteral("layoutDevName"));
      lblDevName = new QLabel(gbGeneral);
      lblDevName->setObjectName(QStringLiteral("lblDevName"));
      sizePolicy1.setHeightForWidth(lblDevName->sizePolicy().hasHeightForWidth());
      lblDevName->setSizePolicy(sizePolicy1);
      lblDevName->setMinimumSize(QSize(75, 0));
      lblDevName->setMaximumSize(QSize(55, 16777215));
      lblDevName->setFont(font1);
      lblDevName->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

      layoutDevName->addWidget(lblDevName);

      editDevName = new QLineEdit(gbGeneral);
      editDevName->setObjectName(QStringLiteral("editDevName"));
      editDevName->setFont(font1);

      layoutDevName->addWidget(editDevName);


      verticalLayout->addLayout(layoutDevName);

      layoutIPPort = new QHBoxLayout();
      layoutIPPort->setObjectName(QStringLiteral("layoutIPPort"));
      lblIP = new QLabel(gbGeneral);
      lblIP->setObjectName(QStringLiteral("lblIP"));
      sizePolicy1.setHeightForWidth(lblIP->sizePolicy().hasHeightForWidth());
      lblIP->setSizePolicy(sizePolicy1);
      lblIP->setMinimumSize(QSize(75, 0));
      lblIP->setMaximumSize(QSize(55, 16777215));
      lblIP->setFont(font1);
      lblIP->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

      layoutIPPort->addWidget(lblIP);

      editIP = new QLineEdit(gbGeneral);
      editIP->setObjectName(QStringLiteral("editIP"));
      editIP->setFont(font1);

      layoutIPPort->addWidget(editIP);

      lblPort = new QLabel(gbGeneral);
      lblPort->setObjectName(QStringLiteral("lblPort"));
      sizePolicy1.setHeightForWidth(lblPort->sizePolicy().hasHeightForWidth());
      lblPort->setSizePolicy(sizePolicy1);
      lblPort->setMinimumSize(QSize(30, 0));
      lblPort->setFont(font1);
      lblPort->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

      layoutIPPort->addWidget(lblPort);

      editPort = new QLineEdit(gbGeneral);
      editPort->setObjectName(QStringLiteral("editPort"));
      QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
      sizePolicy3.setHorizontalStretch(0);
      sizePolicy3.setVerticalStretch(0);
      sizePolicy3.setHeightForWidth(editPort->sizePolicy().hasHeightForWidth());
      editPort->setSizePolicy(sizePolicy3);
      editPort->setMinimumSize(QSize(40, 0));
      editPort->setMaximumSize(QSize(60, 16777215));
      editPort->setFont(font1);

      layoutIPPort->addWidget(editPort);


      verticalLayout->addLayout(layoutIPPort);


      verticalLayout_3->addWidget(gbGeneral);

      gbModel = new QGroupBox(groupBox);
      gbModel->setObjectName(QStringLiteral("gbModel"));
      QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Fixed);
      sizePolicy4.setHorizontalStretch(0);
      sizePolicy4.setVerticalStretch(0);
      sizePolicy4.setHeightForWidth(gbModel->sizePolicy().hasHeightForWidth());
      gbModel->setSizePolicy(sizePolicy4);
      gbModel->setFont(font);
      gbModel->setFlat(false);
      layoutModel = new QVBoxLayout(gbModel);
      layoutModel->setObjectName(QStringLiteral("layoutModel"));
      layoutModelName = new QHBoxLayout();
      layoutModelName->setObjectName(QStringLiteral("layoutModelName"));
      lblModelName = new QLabel(gbModel);
      lblModelName->setObjectName(QStringLiteral("lblModelName"));
      sizePolicy1.setHeightForWidth(lblModelName->sizePolicy().hasHeightForWidth());
      lblModelName->setSizePolicy(sizePolicy1);
      lblModelName->setMinimumSize(QSize(65, 0));
      lblModelName->setMaximumSize(QSize(65, 16777215));
      lblModelName->setFont(font1);
      lblModelName->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

      layoutModelName->addWidget(lblModelName);

      editModelName = new QLineEdit(gbModel);
      editModelName->setObjectName(QStringLiteral("editModelName"));
      editModelName->setFont(font1);
      editModelName->setStyleSheet(QStringLiteral("background-color: rgb(209, 209, 209);"));
      editModelName->setReadOnly(true);

      layoutModelName->addWidget(editModelName);


      layoutModel->addLayout(layoutModelName);

      layoutClass = new QHBoxLayout();
      layoutClass->setObjectName(QStringLiteral("layoutClass"));
      lblClass = new QLabel(gbModel);
      lblClass->setObjectName(QStringLiteral("lblClass"));
      sizePolicy1.setHeightForWidth(lblClass->sizePolicy().hasHeightForWidth());
      lblClass->setSizePolicy(sizePolicy1);
      lblClass->setMinimumSize(QSize(65, 0));
      lblClass->setMaximumSize(QSize(65, 16777215));
      lblClass->setFont(font1);
      lblClass->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

      layoutClass->addWidget(lblClass);

      editClass = new QLineEdit(gbModel);
      editClass->setObjectName(QStringLiteral("editClass"));
      editClass->setFont(font1);
      editClass->setStyleSheet(QStringLiteral("background-color: rgb(209, 209, 209);"));
      editClass->setReadOnly(true);

      layoutClass->addWidget(editClass);


      layoutModel->addLayout(layoutClass);

      layoutBrand = new QHBoxLayout();
      layoutBrand->setObjectName(QStringLiteral("layoutBrand"));
      lblBrand = new QLabel(gbModel);
      lblBrand->setObjectName(QStringLiteral("lblBrand"));
      sizePolicy1.setHeightForWidth(lblBrand->sizePolicy().hasHeightForWidth());
      lblBrand->setSizePolicy(sizePolicy1);
      lblBrand->setMinimumSize(QSize(65, 0));
      lblBrand->setMaximumSize(QSize(65, 16777215));
      lblBrand->setFont(font1);
      lblBrand->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

      layoutBrand->addWidget(lblBrand);

      editBrand = new QLineEdit(gbModel);
      editBrand->setObjectName(QStringLiteral("editBrand"));
      editBrand->setFont(font1);
      editBrand->setStyleSheet(QStringLiteral("background-color: rgb(209, 209, 209);"));
      editBrand->setReadOnly(true);

      layoutBrand->addWidget(editBrand);


      layoutModel->addLayout(layoutBrand);

      layoutDriver = new QHBoxLayout();
      layoutDriver->setObjectName(QStringLiteral("layoutDriver"));
      lblDriver = new QLabel(gbModel);
      lblDriver->setObjectName(QStringLiteral("lblDriver"));
      sizePolicy1.setHeightForWidth(lblDriver->sizePolicy().hasHeightForWidth());
      lblDriver->setSizePolicy(sizePolicy1);
      lblDriver->setMinimumSize(QSize(65, 0));
      lblDriver->setMaximumSize(QSize(65, 16777215));
      lblDriver->setFont(font1);
      lblDriver->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

      layoutDriver->addWidget(lblDriver);

      editDriver = new QLineEdit(gbModel);
      editDriver->setObjectName(QStringLiteral("editDriver"));
      editDriver->setFont(font1);
      editDriver->setStyleSheet(QStringLiteral("background-color: rgb(209, 209, 209);"));
      editDriver->setReadOnly(true);

      layoutDriver->addWidget(editDriver);


      layoutModel->addLayout(layoutDriver);

      layoutModelButtons = new QHBoxLayout();
      layoutModelButtons->setObjectName(QStringLiteral("layoutModelButtons"));
      hSpacerModelButtons = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

      layoutModelButtons->addItem(hSpacerModelButtons);

      bnNewModel = new QPushButton(gbModel);
      bnNewModel->setObjectName(QStringLiteral("bnNewModel"));
      sizePolicy3.setHeightForWidth(bnNewModel->sizePolicy().hasHeightForWidth());
      bnNewModel->setSizePolicy(sizePolicy3);
      bnNewModel->setMinimumSize(QSize(23, 23));
      bnNewModel->setMaximumSize(QSize(23, 23));
      bnNewModel->setFont(font1);

      layoutModelButtons->addWidget(bnNewModel);

      bnSelectModel = new QPushButton(gbModel);
      bnSelectModel->setObjectName(QStringLiteral("bnSelectModel"));
      bnSelectModel->setFont(font1);

      layoutModelButtons->addWidget(bnSelectModel);


      layoutModel->addLayout(layoutModelButtons);


      verticalLayout_3->addWidget(gbModel);

      gbLocation = new QGroupBox(groupBox);
      gbLocation->setObjectName(QStringLiteral("gbLocation"));
      sizePolicy4.setHeightForWidth(gbLocation->sizePolicy().hasHeightForWidth());
      gbLocation->setSizePolicy(sizePolicy4);
      gbLocation->setFont(font);
      horizontalLayout = new QHBoxLayout(gbLocation);
      horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
      lblX = new QLabel(gbLocation);
      lblX->setObjectName(QStringLiteral("lblX"));
      sizePolicy1.setHeightForWidth(lblX->sizePolicy().hasHeightForWidth());
      lblX->setSizePolicy(sizePolicy1);
      lblX->setMinimumSize(QSize(25, 0));
      lblX->setFont(font1);
      lblX->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

      horizontalLayout->addWidget(lblX);

      sbX = new QSpinBox(gbLocation);
      sbX->setObjectName(QStringLiteral("sbX"));
      sbX->setFont(font1);

      horizontalLayout->addWidget(sbX);

      lblY = new QLabel(gbLocation);
      lblY->setObjectName(QStringLiteral("lblY"));
      sizePolicy1.setHeightForWidth(lblY->sizePolicy().hasHeightForWidth());
      lblY->setSizePolicy(sizePolicy1);
      lblY->setMinimumSize(QSize(25, 0));
      lblY->setFont(font1);
      lblY->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

      horizontalLayout->addWidget(lblY);

      sbY = new QSpinBox(gbLocation);
      sbY->setObjectName(QStringLiteral("sbY"));
      sbY->setFont(font1);

      horizontalLayout->addWidget(sbY);

      lblZ = new QLabel(gbLocation);
      lblZ->setObjectName(QStringLiteral("lblZ"));
      sizePolicy1.setHeightForWidth(lblZ->sizePolicy().hasHeightForWidth());
      lblZ->setSizePolicy(sizePolicy1);
      lblZ->setMinimumSize(QSize(25, 0));
      lblZ->setFont(font1);
      lblZ->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

      horizontalLayout->addWidget(lblZ);

      sbZ = new QSpinBox(gbLocation);
      sbZ->setObjectName(QStringLiteral("sbZ"));
      sbZ->setFont(font1);

      horizontalLayout->addWidget(sbZ);


      verticalLayout_3->addWidget(gbLocation);

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


      verticalLayout_3->addLayout(layoutDescription);


      verticalLayout_2->addWidget(groupBox);

      layoutButtons = new QHBoxLayout();
      layoutButtons->setObjectName(QStringLiteral("layoutButtons"));
      hSpacerButtons = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

      layoutButtons->addItem(hSpacerButtons);

      bnSave = new QPushButton(SvDevice);
      bnSave->setObjectName(QStringLiteral("bnSave"));
      sizePolicy3.setHeightForWidth(bnSave->sizePolicy().hasHeightForWidth());
      bnSave->setSizePolicy(sizePolicy3);
      bnSave->setMaximumSize(QSize(80, 16777215));
      bnSave->setDefault(true);

      layoutButtons->addWidget(bnSave);

      bnCancel = new QPushButton(SvDevice);
      bnCancel->setObjectName(QStringLiteral("bnCancel"));
      sizePolicy3.setHeightForWidth(bnCancel->sizePolicy().hasHeightForWidth());
      bnCancel->setSizePolicy(sizePolicy3);
      bnCancel->setMaximumSize(QSize(80, 16777215));

      layoutButtons->addWidget(bnCancel);


      verticalLayout_2->addLayout(layoutButtons);

      QWidget::setTabOrder(editDevName, editIP);
      QWidget::setTabOrder(editIP, editPort);
      QWidget::setTabOrder(editPort, editModelName);
      QWidget::setTabOrder(editModelName, editClass);
      QWidget::setTabOrder(editClass, editBrand);
      QWidget::setTabOrder(editBrand, editDriver);
      QWidget::setTabOrder(editDriver, bnNewModel);
      QWidget::setTabOrder(bnNewModel, bnSelectModel);
      QWidget::setTabOrder(bnSelectModel, sbX);
      QWidget::setTabOrder(sbX, sbY);
      QWidget::setTabOrder(sbY, sbZ);
      QWidget::setTabOrder(sbZ, textDescription);
      QWidget::setTabOrder(textDescription, bnSave);
      QWidget::setTabOrder(bnSave, bnCancel);
      QWidget::setTabOrder(bnCancel, editID);
      

      if(id != -1) editID->setText(QString("%1").arg(id));
      editDevName->setText(deviceName);
      editIP->setText(ip);
      editPort->setText(QString("%1").arg(port));
      editModelName->setText(modelName);
      editClass->setText(clssName);
      editBrand->setText(brandName);
      editDriver->setText(libPath);
      sbX->setValue(locationX);
      sbY->setValue(locationY);
      sbZ->setValue(locationZ);
      textDescription->setText(description);

      retranslateUi(SvDevice, showMode, deviceName);

      QMetaObject::connectSlotsByName(SvDevice);
      
    } // setupUi

    void retranslateUi(QDialog *SvDevice, int showMode, QString devName)
    {
      QString title;
      title = QApplication::translate("SvDevice", "Device - ", 0);
      if(showMode = smNew)
        title = title + QApplication::translate("SvDevice", "New", 0);
      else title = title + devName;
      
      SvDevice->setWindowTitle(title);
      groupBox->setTitle(QString());
      lblID->setText(QApplication::translate("SvDevice", "ID", 0));
      lblDevName->setText(QApplication::translate("SvDevice", "Device name", 0));
      lblIP->setText(QApplication::translate("SvDevice", "IP", 0));
      lblPort->setText(QApplication::translate("SvDevice", "Port", 0));
      gbModel->setTitle(QApplication::translate("SvDevice", "Model", 0));
      lblModelName->setText(QApplication::translate("SvDevice", "Model name", 0));
      lblClass->setText(QApplication::translate("SvDevice", "Device class", 0));
      lblBrand->setText(QApplication::translate("SvDevice", "Brand", 0));
      lblDriver->setText(QApplication::translate("SvDevice", "Driver lib", 0));
      bnNewModel->setText(QApplication::translate("SvDevice", "+", 0));
      bnSelectModel->setText(QApplication::translate("SvDevice", "Select", 0));
      gbLocation->setTitle(QApplication::translate("SvDevice", "Location", 0));
      lblX->setText(QApplication::translate("SvDevice", "X", 0));
      lblY->setText(QApplication::translate("SvDevice", "Y", 0));
      lblZ->setText(QApplication::translate("SvDevice", "Z", 0));
      lblDescription->setText(QApplication::translate("SvDevice", "Description", 0));
      bnSave->setText(QApplication::translate("SvDevice", "Save", 0));
      bnCancel->setText(QApplication::translate("SvDevice", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class SvDeviceDialog: public Ui_SvDevice {};
} // namespace Ui

QT_END_NAMESPACE

#endif // SV_DEVICEYO7120_H
