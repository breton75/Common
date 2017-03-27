/********************************************************************************
** Form generated from reading UI file 'arch_configuratorGZ5568.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef ARCH_CONFIGURATORGZ5568_H
#define ARCH_CONFIGURATORGZ5568_H

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
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ArchDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *layoutIPPort;
    QLabel *lblIP;
    QLineEdit *editIP;
    QLabel *lblPort;
    QLineEdit *editPort;
    QHBoxLayout *layoutDbName;
    QLabel *lblDbName;
    QLineEdit *editDbName;
    QHBoxLayout *layoutUserPass;
    QLabel *lblUserName;
    QLineEdit *editUserName;
    QLabel *lblPassword;
    QLineEdit *editPassword;
    QGroupBox *gbDevices;
    QHBoxLayout *horizontalLayout_2;
    QTableView *tblDevices;
    QVBoxLayout *layoutDeviceButtons;
    QPushButton *bnAddDevice;
    QPushButton *bnDeleteDevice;
    QPushButton *bnDeviceSettings;
    QSpacerItem *spacer1;
    QGroupBox *gbData;
    QHBoxLayout *horizontalLayout_3;
    QTableView *tblData;
    QVBoxLayout *layoutDataButtons;
    QPushButton *bnAddData;
    QPushButton *bnDeleteData;
    QSpacerItem *spacer2;
    QHBoxLayout *layoutButtons;
    QPushButton *bnConfigure;
    QSpacerItem *spacer3;
    QPushButton *bnSave;
    QPushButton *bnCancel;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->setWindowModality(Qt::ApplicationModal);
        Dialog->resize(550, 430);
        QIcon icon;
        icon.addFile(QStringLiteral("Icons/google/Gears.ico"), QSize(), QIcon::Normal, QIcon::Off);
        Dialog->setWindowIcon(icon);
        verticalLayout_2 = new QVBoxLayout(Dialog);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        groupBox = new QGroupBox(Dialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        groupBox->setFont(font);
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        layoutIPPort = new QHBoxLayout();
        layoutIPPort->setObjectName(QStringLiteral("layoutIPPort"));
        lblIP = new QLabel(groupBox);
        lblIP->setObjectName(QStringLiteral("lblIP"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lblIP->sizePolicy().hasHeightForWidth());
        lblIP->setSizePolicy(sizePolicy);
        lblIP->setMinimumSize(QSize(75, 0));
        lblIP->setMaximumSize(QSize(55, 16777215));
        QFont font1;
        font1.setBold(false);
        font1.setWeight(50);
        lblIP->setFont(font1);
        lblIP->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        layoutIPPort->addWidget(lblIP);

        editIP = new QLineEdit(groupBox);
        editIP->setObjectName(QStringLiteral("editIP"));
        editIP->setMinimumSize(QSize(100, 0));
        editIP->setMaximumSize(QSize(16777215, 16777215));
        editIP->setFont(font1);

        layoutIPPort->addWidget(editIP);

        lblPort = new QLabel(groupBox);
        lblPort->setObjectName(QStringLiteral("lblPort"));
        sizePolicy.setHeightForWidth(lblPort->sizePolicy().hasHeightForWidth());
        lblPort->setSizePolicy(sizePolicy);
        lblPort->setMinimumSize(QSize(50, 0));
        lblPort->setFont(font1);
        lblPort->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        layoutIPPort->addWidget(lblPort);

        editPort = new QLineEdit(groupBox);
        editPort->setObjectName(QStringLiteral("editPort"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(editPort->sizePolicy().hasHeightForWidth());
        editPort->setSizePolicy(sizePolicy1);
        editPort->setMinimumSize(QSize(100, 0));
        editPort->setMaximumSize(QSize(16777215, 16777215));
        editPort->setFont(font1);

        layoutIPPort->addWidget(editPort);


        verticalLayout->addLayout(layoutIPPort);

        layoutDbName = new QHBoxLayout();
        layoutDbName->setObjectName(QStringLiteral("layoutDbName"));
        lblDbName = new QLabel(groupBox);
        lblDbName->setObjectName(QStringLiteral("lblDbName"));
        sizePolicy.setHeightForWidth(lblDbName->sizePolicy().hasHeightForWidth());
        lblDbName->setSizePolicy(sizePolicy);
        lblDbName->setMinimumSize(QSize(75, 0));
        lblDbName->setMaximumSize(QSize(55, 16777215));
        lblDbName->setFont(font1);
        lblDbName->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        layoutDbName->addWidget(lblDbName);

        editDbName = new QLineEdit(groupBox);
        editDbName->setObjectName(QStringLiteral("editDbName"));
        editDbName->setMinimumSize(QSize(100, 0));
        editDbName->setMaximumSize(QSize(16777215, 16777215));
        editDbName->setFont(font1);

        layoutDbName->addWidget(editDbName);


        verticalLayout->addLayout(layoutDbName);

        layoutUserPass = new QHBoxLayout();
        layoutUserPass->setObjectName(QStringLiteral("layoutUserPass"));
        lblUserName = new QLabel(groupBox);
        lblUserName->setObjectName(QStringLiteral("lblUserName"));
        sizePolicy.setHeightForWidth(lblUserName->sizePolicy().hasHeightForWidth());
        lblUserName->setSizePolicy(sizePolicy);
        lblUserName->setMinimumSize(QSize(75, 0));
        lblUserName->setMaximumSize(QSize(55, 16777215));
        lblUserName->setFont(font1);
        lblUserName->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        layoutUserPass->addWidget(lblUserName);

        editUserName = new QLineEdit(groupBox);
        editUserName->setObjectName(QStringLiteral("editUserName"));
        editUserName->setMinimumSize(QSize(100, 0));
        editUserName->setMaximumSize(QSize(16777215, 16777215));
        editUserName->setFont(font1);

        layoutUserPass->addWidget(editUserName);

        lblPassword = new QLabel(groupBox);
        lblPassword->setObjectName(QStringLiteral("lblPassword"));
        sizePolicy.setHeightForWidth(lblPassword->sizePolicy().hasHeightForWidth());
        lblPassword->setSizePolicy(sizePolicy);
        lblPassword->setMinimumSize(QSize(50, 0));
        lblPassword->setMaximumSize(QSize(50, 16777215));
        lblPassword->setFont(font1);
        lblPassword->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        layoutUserPass->addWidget(lblPassword);

        editPassword = new QLineEdit(groupBox);
        editPassword->setObjectName(QStringLiteral("editPassword"));
        sizePolicy1.setHeightForWidth(editPassword->sizePolicy().hasHeightForWidth());
        editPassword->setSizePolicy(sizePolicy1);
        editPassword->setMinimumSize(QSize(100, 0));
        editPassword->setMaximumSize(QSize(16777215, 16777215));
        editPassword->setFont(font1);
        editPassword->setEchoMode(QLineEdit::PasswordEchoOnEdit);
        editPassword->setClearButtonEnabled(false);

        layoutUserPass->addWidget(editPassword);


        verticalLayout->addLayout(layoutUserPass);


        verticalLayout_2->addWidget(groupBox);

        gbDevices = new QGroupBox(Dialog);
        gbDevices->setObjectName(QStringLiteral("gbDevices"));
        gbDevices->setFont(font);
        horizontalLayout_2 = new QHBoxLayout(gbDevices);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        tblDevices = new QTableView(gbDevices);
        tblDevices->setObjectName(QStringLiteral("tblDevices"));
        tblDevices->setFont(font1);

        horizontalLayout_2->addWidget(tblDevices);

        layoutDeviceButtons = new QVBoxLayout();
        layoutDeviceButtons->setObjectName(QStringLiteral("layoutDeviceButtons"));
        bnAddDevice = new QPushButton(gbDevices);
        bnAddDevice->setObjectName(QStringLiteral("bnAddDevice"));
        bnAddDevice->setFont(font1);

        layoutDeviceButtons->addWidget(bnAddDevice);

        bnDeleteDevice = new QPushButton(gbDevices);
        bnDeleteDevice->setObjectName(QStringLiteral("bnDeleteDevice"));
        bnDeleteDevice->setFont(font1);

        layoutDeviceButtons->addWidget(bnDeleteDevice);

        bnDeviceSettings = new QPushButton(gbDevices);
        bnDeviceSettings->setObjectName(QStringLiteral("bnDeviceSettings"));
        bnDeviceSettings->setFont(font1);

        layoutDeviceButtons->addWidget(bnDeviceSettings);

        spacer1 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        layoutDeviceButtons->addItem(spacer1);


        horizontalLayout_2->addLayout(layoutDeviceButtons);


        verticalLayout_2->addWidget(gbDevices);

        gbData = new QGroupBox(Dialog);
        gbData->setObjectName(QStringLiteral("gbData"));
        gbData->setFont(font);
        horizontalLayout_3 = new QHBoxLayout(gbData);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        tblData = new QTableView(gbData);
        tblData->setObjectName(QStringLiteral("tblData"));
        tblData->setFont(font1);

        horizontalLayout_3->addWidget(tblData);

        layoutDataButtons = new QVBoxLayout();
        layoutDataButtons->setObjectName(QStringLiteral("layoutDataButtons"));
        bnAddData = new QPushButton(gbData);
        bnAddData->setObjectName(QStringLiteral("bnAddData"));
        bnAddData->setFont(font1);

        layoutDataButtons->addWidget(bnAddData);

        bnDeleteData = new QPushButton(gbData);
        bnDeleteData->setObjectName(QStringLiteral("bnDeleteData"));
        bnDeleteData->setFont(font1);

        layoutDataButtons->addWidget(bnDeleteData);

        spacer2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        layoutDataButtons->addItem(spacer2);


        horizontalLayout_3->addLayout(layoutDataButtons);


        verticalLayout_2->addWidget(gbData);

        layoutButtons = new QHBoxLayout();
        layoutButtons->setObjectName(QStringLiteral("layoutButtons"));
        bnConfigure = new QPushButton(Dialog);
        bnConfigure->setObjectName(QStringLiteral("bnConfigure"));
        bnConfigure->setFont(font);

        layoutButtons->addWidget(bnConfigure);

        spacer3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        layoutButtons->addItem(spacer3);

        bnSave = new QPushButton(Dialog);
        bnSave->setObjectName(QStringLiteral("bnSave"));

        layoutButtons->addWidget(bnSave);

        bnCancel = new QPushButton(Dialog);
        bnCancel->setObjectName(QStringLiteral("bnCancel"));

        layoutButtons->addWidget(bnCancel);


        verticalLayout_2->addLayout(layoutButtons);

        QWidget::setTabOrder(editIP, editPort);
        QWidget::setTabOrder(editPort, editDbName);
        QWidget::setTabOrder(editDbName, editUserName);
        QWidget::setTabOrder(editUserName, editPassword);
        QWidget::setTabOrder(editPassword, bnAddDevice);
        QWidget::setTabOrder(bnAddDevice, bnDeleteDevice);
        QWidget::setTabOrder(bnDeleteDevice, bnDeviceSettings);
        QWidget::setTabOrder(bnDeviceSettings, bnAddData);
        QWidget::setTabOrder(bnAddData, bnDeleteData);
        QWidget::setTabOrder(bnDeleteData, bnSave);
        QWidget::setTabOrder(bnSave, bnCancel);
        QWidget::setTabOrder(bnCancel, bnConfigure);
        QWidget::setTabOrder(bnConfigure, tblDevices);
        QWidget::setTabOrder(tblDevices, tblData);

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Configurator", 0));
        groupBox->setTitle(QApplication::translate("Dialog", "Connection settings", 0));
        lblIP->setText(QApplication::translate("Dialog", "IP", 0));
        editIP->setText(QApplication::translate("Dialog", "255.255.255.255", 0));
        lblPort->setText(QApplication::translate("Dialog", "Port", 0));
        editPort->setText(QApplication::translate("Dialog", "5432", 0));
        lblDbName->setText(QApplication::translate("Dialog", "Dtabase name", 0));
        editDbName->setText(QString());
        lblUserName->setText(QApplication::translate("Dialog", "User name", 0));
        editUserName->setText(QString());
        lblPassword->setText(QApplication::translate("Dialog", "Password", 0));
        editPassword->setText(QString());
        gbDevices->setTitle(QApplication::translate("Dialog", "Select devices for archiving", 0));
        bnAddDevice->setText(QApplication::translate("Dialog", "Add", 0));
        bnDeleteDevice->setText(QApplication::translate("Dialog", "Delete", 0));
        bnDeviceSettings->setText(QApplication::translate("Dialog", "Settings", 0));
        gbData->setTitle(QApplication::translate("Dialog", "Select data for archiving", 0));
        bnAddData->setText(QApplication::translate("Dialog", "Add", 0));
        bnDeleteData->setText(QApplication::translate("Dialog", "Delete", 0));
        bnConfigure->setText(QApplication::translate("Dialog", "Configure", 0));
        bnSave->setText(QApplication::translate("Dialog", "Save", 0));
        bnCancel->setText(QApplication::translate("Dialog", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class ArchDialog: public Ui_ArchDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // ARCH_CONFIGURATORGZ5568_H
