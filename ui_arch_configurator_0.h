/********************************************************************************
** Form generated from reading UI file 'arch_configurator.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ARCH_CONFIGURATOR_H
#define UI_ARCH_CONFIGURATOR_H

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

#include <QDebug>

QT_BEGIN_NAMESPACE

class Ui_Dialog
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
    QHBoxLayout *horizontalLayout_4;
    QLabel *lblUserName_2;
    QLineEdit *editUserName_2;
    QHBoxLayout *layoutIPPort_2;
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
    QHBoxLayout *horizontalLayout;
    QPushButton *bnConfigure;
    QSpacerItem *spacer3;
    QPushButton *bnOk;
    QPushButton *bnCancel;

    void setupUi(QDialog *SvArchConfigDialog)
    {
        if (SvArchConfigDialog->objectName().isEmpty())
            SvArchConfigDialog->setObjectName(QStringLiteral("SvArchConfigDialog"));
        SvArchConfigDialog->setWindowModality(Qt::ApplicationModal);
        SvArchConfigDialog->resize(478, 430);
        
        
//        QIcon icon;
//        icon.addFile(QStringLiteral("Icons/google/Gears.ico"), QSize(), QIcon::Normal, QIcon::Off);
//        Dialog->setWindowIcon(icon);
        verticalLayout_2 = new QVBoxLayout(SvArchConfigDialog);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        groupBox = new QGroupBox(SvArchConfigDialog);
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

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        lblUserName_2 = new QLabel(groupBox);
        lblUserName_2->setObjectName(QStringLiteral("lblUserName_2"));
        sizePolicy.setHeightForWidth(lblUserName_2->sizePolicy().hasHeightForWidth());
        lblUserName_2->setSizePolicy(sizePolicy);
        lblUserName_2->setMinimumSize(QSize(75, 0));
        lblUserName_2->setMaximumSize(QSize(55, 16777215));
        lblUserName_2->setFont(font1);
        lblUserName_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(lblUserName_2);

        editUserName_2 = new QLineEdit(groupBox);
        editUserName_2->setObjectName(QStringLiteral("editUserName_2"));
        editUserName_2->setMinimumSize(QSize(100, 0));
        editUserName_2->setMaximumSize(QSize(16777215, 16777215));
        editUserName_2->setFont(font1);

        horizontalLayout_4->addWidget(editUserName_2);


        verticalLayout->addLayout(horizontalLayout_4);

        layoutIPPort_2 = new QHBoxLayout();
        layoutIPPort_2->setObjectName(QStringLiteral("layoutIPPort_2"));
        lblUserName = new QLabel(groupBox);
        lblUserName->setObjectName(QStringLiteral("lblUserName"));
        sizePolicy.setHeightForWidth(lblUserName->sizePolicy().hasHeightForWidth());
        lblUserName->setSizePolicy(sizePolicy);
        lblUserName->setMinimumSize(QSize(75, 0));
        lblUserName->setMaximumSize(QSize(55, 16777215));
        lblUserName->setFont(font1);
        lblUserName->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        layoutIPPort_2->addWidget(lblUserName);

        editUserName = new QLineEdit(groupBox);
        editUserName->setObjectName(QStringLiteral("editUserName"));
        editUserName->setMinimumSize(QSize(100, 0));
        editUserName->setMaximumSize(QSize(16777215, 16777215));
        editUserName->setFont(font1);

        layoutIPPort_2->addWidget(editUserName);

        lblPassword = new QLabel(groupBox);
        lblPassword->setObjectName(QStringLiteral("lblPassword"));
        sizePolicy.setHeightForWidth(lblPassword->sizePolicy().hasHeightForWidth());
        lblPassword->setSizePolicy(sizePolicy);
        lblPassword->setMinimumSize(QSize(50, 0));
        lblPassword->setMaximumSize(QSize(50, 16777215));
        lblPassword->setFont(font1);
        lblPassword->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        layoutIPPort_2->addWidget(lblPassword);

        editPassword = new QLineEdit(groupBox);
        editPassword->setObjectName(QStringLiteral("editPassword"));
        sizePolicy1.setHeightForWidth(editPassword->sizePolicy().hasHeightForWidth());
        editPassword->setSizePolicy(sizePolicy1);
        editPassword->setMinimumSize(QSize(100, 0));
        editPassword->setMaximumSize(QSize(16777215, 16777215));
        editPassword->setFont(font1);
        editPassword->setEchoMode(QLineEdit::PasswordEchoOnEdit);
        editPassword->setClearButtonEnabled(false);

        layoutIPPort_2->addWidget(editPassword);


        verticalLayout->addLayout(layoutIPPort_2);


        verticalLayout_2->addWidget(groupBox);

        gbDevices = new QGroupBox(SvArchConfigDialog);
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

        gbData = new QGroupBox(SvArchConfigDialog);
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

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        bnConfigure = new QPushButton(SvArchConfigDialog);
        bnConfigure->setObjectName(QStringLiteral("bnConfigure"));
        bnConfigure->setFont(font);

        horizontalLayout->addWidget(bnConfigure);

        spacer3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(spacer3);

        bnOk = new QPushButton(SvArchConfigDialog);
        bnOk->setObjectName(QStringLiteral("bnOk"));

        horizontalLayout->addWidget(bnOk);

        bnCancel = new QPushButton(SvArchConfigDialog);
        bnCancel->setObjectName(QStringLiteral("bnCancel"));

        horizontalLayout->addWidget(bnCancel);


        verticalLayout_2->addLayout(horizontalLayout);
        

        retranslateUi(SvArchConfigDialog);

        QMetaObject::connectSlotsByName(SvArchConfigDialog);
    } // setupUi

    void retranslateUi(QDialog *SvArchConfigDialog)
    {
      qDebug() << "ddddd";  
      
      SvArchConfigDialog->setWindowTitle(QApplication::translate("SvArchConfigDialog", "Configurator", 0));
        groupBox->setTitle(QApplication::translate("SvArchConfigDialog", "Connection settings", 0));
        lblIP->setText(QApplication::translate("SvArchConfigDialog", "IP", 0));
        editIP->setText(QApplication::translate("SvArchConfigDialog", "255.255.255.255", 0));
        lblPort->setText(QApplication::translate("SvArchConfigDialog", "Port", 0));
        editPort->setText(QApplication::translate("SvArchConfigDialog", "5432", 0));
        lblUserName_2->setText(QApplication::translate("SvArchConfigDialog", "Dtabase name", 0));
        
        editUserName_2->setText(QString());
        lblUserName->setText(QApplication::translate("SvArchConfigDialog", "User name", 0));
        editUserName->setText(QString());
        lblPassword->setText(QApplication::translate("SvArchConfigDialog", "Password", 0));
        editPassword->setText(QString());
        gbDevices->setTitle(QApplication::translate("SvArchConfigDialog", "Select devices for archiving", 0));
        bnAddDevice->setText(QApplication::translate("SvArchConfigDialog", "Add", 0));
        bnDeleteDevice->setText(QApplication::translate("SvArchConfigDialog", "Delete", 0));
        bnDeviceSettings->setText(QApplication::translate("SvArchConfigDialog", "Settings", 0));
        gbData->setTitle(QApplication::translate("SvArchConfigDialog", "Select data for archiving", 0));
        bnAddData->setText(QApplication::translate("SvArchConfigDialog", "Add", 0));
        bnDeleteData->setText(QApplication::translate("SvArchConfigDialog", "Delete", 0));
        bnConfigure->setText(QApplication::translate("SvArchConfigDialog", "Configure", 0));
        bnOk->setText(QApplication::translate("SvArchConfigDialog", "Save", 0));
        bnCancel->setText(QApplication::translate("SvArchConfigDialog", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class SvArchConfigDialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARCH_CONFIGURATOR_H
