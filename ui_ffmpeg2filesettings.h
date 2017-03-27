/********************************************************************************
** Form generated from reading UI file 'sv_ffmpeg2filesettingsJt2896.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef SV_FFMPEG2FILESETTINGSJT2896_H
#define SV_FFMPEG2FILESETTINGSJT2896_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

enum Codecs
{
  h264 = 0,
  mjpeg
};

struct FFmpegSettings
{
  QString device_name;
  QString device_tag;
  QString media_link;
  QString ip;
  quint16 port;
  QString path_to_save_file;
  
  QString datetime_format;
  QString file_name_format;
  
  QString user_name;
  QString password;
  
  QTime file_duaration;
  QTime total_duration;
  
  bool doTotalTime;
  bool doConvert; 
  
  int fps;
  int scale;
  int codec;
    
};

class Ui_SvFFmpeg2FileSettings
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *gbMain;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *layoutDeviceName;
    QLabel *lblDeviceName;
    QLineEdit *editDeviceName;
    QHBoxLayout *layoutMediaLink;
    QLabel *lblMediaLink;
    QLineEdit *editMediaLink;
    QHBoxLayout *layoutSaveDirectory;
    QLabel *lblSaveDirectory;
    QLineEdit *editSaveDirectory;
    QPushButton *bnSelectSaveDirectory;
    QHBoxLayout *layoutFileDuration;
    QLabel *lblFileDuration;
    QTimeEdit *teFileDuration;
    QSpacerItem *spacerFileDuration;
    QHBoxLayout *layoutTotalDuration;
    QLabel *lblTotaDuration;
    QTimeEdit *teTotalDuration;
    QCheckBox *checkBoxTotalDuration;
    QSpacerItem *spacerTotalDuration;
    QSpacerItem *vSpacer_1;
    QGroupBox *gbFileName;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *layoutFileNameFormat;
    QLabel *lblFileNameFormat;
    QLineEdit *editFileNameFormat;
    QHBoxLayout *layoutDateTimeFormat;
    QLabel *lblDateTimeFormat;
    QLineEdit *editDateTimeFormat;
    QHBoxLayout *layoutUserName;
    QLabel *lblUserName;
    QLineEdit *editUserName;
    QHBoxLayout *layoutPassword;
    QLabel *lblPassword;
    QLineEdit *editPassword;
    QHBoxLayout *layoutDeviceTag;
    QLabel *lblDeviceTag;
    QLineEdit *editDeviceTag;
    QSpacerItem *vSpacer_2;
    QGroupBox *gbConvertVideo;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *layoutCodec;
    QLabel *lblCodec;
    QComboBox *cbCodec;
    QHBoxLayout *layoutScale;
    QLabel *lblScale;
    QSpinBox *sbScale;
    QHBoxLayout *layoutFps;
    QLabel *lblFps;
    QSpinBox *sbFps;
    QHBoxLayout *layoutButtons;
    QSpacerItem *spacerButtons;
    QPushButton *bnOk;
    QPushButton *bnCancel;

    void setupUi(QDialog *SvFFmpeg2FileSettings,
                 FFmpegSettings* settings)
    {
        if (SvFFmpeg2FileSettings->objectName().isEmpty())
            SvFFmpeg2FileSettings->setObjectName(QStringLiteral("SvFFmpeg2FileSettings"));
        SvFFmpeg2FileSettings->resize(334, 520);
        verticalLayout = new QVBoxLayout(SvFFmpeg2FileSettings);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gbMain = new QGroupBox(SvFFmpeg2FileSettings);
        gbMain->setObjectName(QStringLiteral("gbMain"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(gbMain->sizePolicy().hasHeightForWidth());
        gbMain->setSizePolicy(sizePolicy);
        verticalLayout_4 = new QVBoxLayout(gbMain);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        layoutDeviceName = new QHBoxLayout();
        layoutDeviceName->setObjectName(QStringLiteral("layoutDeviceName"));
        lblDeviceName = new QLabel(gbMain);
        lblDeviceName->setObjectName(QStringLiteral("lblDeviceName"));
        lblDeviceName->setMinimumSize(QSize(99, 0));
        lblDeviceName->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        layoutDeviceName->addWidget(lblDeviceName);

        editDeviceName = new QLineEdit(gbMain);
        editDeviceName->setObjectName(QStringLiteral("editDeviceName"));

        layoutDeviceName->addWidget(editDeviceName);


        verticalLayout_4->addLayout(layoutDeviceName);

        layoutMediaLink = new QHBoxLayout();
        layoutMediaLink->setObjectName(QStringLiteral("layoutMediaLink"));
        lblMediaLink = new QLabel(gbMain);
        lblMediaLink->setObjectName(QStringLiteral("lblMediaLink"));
        lblMediaLink->setMinimumSize(QSize(99, 0));
        lblMediaLink->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        layoutMediaLink->addWidget(lblMediaLink);

        editMediaLink = new QLineEdit(gbMain);
        editMediaLink->setObjectName(QStringLiteral("editMediaLink"));

        layoutMediaLink->addWidget(editMediaLink);


        verticalLayout_4->addLayout(layoutMediaLink);

        layoutSaveDirectory = new QHBoxLayout();
        layoutSaveDirectory->setObjectName(QStringLiteral("layoutSaveDirectory"));
        lblSaveDirectory = new QLabel(gbMain);
        lblSaveDirectory->setObjectName(QStringLiteral("lblSaveDirectory"));
        lblSaveDirectory->setMinimumSize(QSize(99, 0));
        lblSaveDirectory->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        layoutSaveDirectory->addWidget(lblSaveDirectory);

        editSaveDirectory = new QLineEdit(gbMain);
        editSaveDirectory->setObjectName(QStringLiteral("editSaveDirectory"));

        layoutSaveDirectory->addWidget(editSaveDirectory);

        bnSelectSaveDirectory = new QPushButton(gbMain);
        bnSelectSaveDirectory->setObjectName(QStringLiteral("bnSelectSaveDirectory"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(bnSelectSaveDirectory->sizePolicy().hasHeightForWidth());
        bnSelectSaveDirectory->setSizePolicy(sizePolicy1);
        bnSelectSaveDirectory->setMaximumSize(QSize(24, 24));

        layoutSaveDirectory->addWidget(bnSelectSaveDirectory);


        verticalLayout_4->addLayout(layoutSaveDirectory);

        layoutFileDuration = new QHBoxLayout();
        layoutFileDuration->setObjectName(QStringLiteral("layoutFileDuration"));
        lblFileDuration = new QLabel(gbMain);
        lblFileDuration->setObjectName(QStringLiteral("lblFileDuration"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lblFileDuration->sizePolicy().hasHeightForWidth());
        lblFileDuration->setSizePolicy(sizePolicy2);
        lblFileDuration->setMinimumSize(QSize(99, 0));
        lblFileDuration->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        layoutFileDuration->addWidget(lblFileDuration);

        teFileDuration = new QTimeEdit(gbMain);
        teFileDuration->setObjectName(QStringLiteral("teFileDuration"));
        teFileDuration->setMinimumSize(QSize(90, 0));
        teFileDuration->setMaximumSize(QSize(90, 16777215));

        layoutFileDuration->addWidget(teFileDuration);

        spacerFileDuration = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        layoutFileDuration->addItem(spacerFileDuration);


        verticalLayout_4->addLayout(layoutFileDuration);

        layoutTotalDuration = new QHBoxLayout();
        layoutTotalDuration->setObjectName(QStringLiteral("layoutTotalDuration"));
        lblTotaDuration = new QLabel(gbMain);
        lblTotaDuration->setObjectName(QStringLiteral("lblTotaDuration"));
        sizePolicy2.setHeightForWidth(lblTotaDuration->sizePolicy().hasHeightForWidth());
        lblTotaDuration->setSizePolicy(sizePolicy2);
        lblTotaDuration->setMinimumSize(QSize(99, 0));
        lblTotaDuration->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        layoutTotalDuration->addWidget(lblTotaDuration);

        teTotalDuration = new QTimeEdit(gbMain);
        teTotalDuration->setObjectName(QStringLiteral("teTotalDuration"));
        teTotalDuration->setEnabled(false);
        teTotalDuration->setMinimumSize(QSize(90, 0));
        teTotalDuration->setMaximumSize(QSize(90, 16777215));

        layoutTotalDuration->addWidget(teTotalDuration);

        checkBoxTotalDuration = new QCheckBox(gbMain);
        checkBoxTotalDuration->setObjectName(QStringLiteral("checkBoxTotalDuration"));

        layoutTotalDuration->addWidget(checkBoxTotalDuration);

        spacerTotalDuration = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        layoutTotalDuration->addItem(spacerTotalDuration);


        verticalLayout_4->addLayout(layoutTotalDuration);

        vSpacer_1 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(vSpacer_1);

        gbFileName = new QGroupBox(gbMain);
        gbFileName->setObjectName(QStringLiteral("gbFileName"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        gbFileName->setFont(font);
        gbFileName->setFlat(true);
        verticalLayout_2 = new QVBoxLayout(gbFileName);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        layoutFileNameFormat = new QHBoxLayout();
        layoutFileNameFormat->setObjectName(QStringLiteral("layoutFileNameFormat"));
        lblFileNameFormat = new QLabel(gbFileName);
        lblFileNameFormat->setObjectName(QStringLiteral("lblFileNameFormat"));
        lblFileNameFormat->setMinimumSize(QSize(90, 0));
        QFont font1;
        font1.setBold(false);
        font1.setWeight(50);
        lblFileNameFormat->setFont(font1);
        lblFileNameFormat->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        layoutFileNameFormat->addWidget(lblFileNameFormat);

        editFileNameFormat = new QLineEdit(gbFileName);
        editFileNameFormat->setObjectName(QStringLiteral("editFileNameFormat"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(editFileNameFormat->sizePolicy().hasHeightForWidth());
        editFileNameFormat->setSizePolicy(sizePolicy3);
        editFileNameFormat->setFont(font1);

        layoutFileNameFormat->addWidget(editFileNameFormat);


        verticalLayout_2->addLayout(layoutFileNameFormat);

        layoutDateTimeFormat = new QHBoxLayout();
        layoutDateTimeFormat->setObjectName(QStringLiteral("layoutDateTimeFormat"));
        lblDateTimeFormat = new QLabel(gbFileName);
        lblDateTimeFormat->setObjectName(QStringLiteral("lblDateTimeFormat"));
        lblDateTimeFormat->setMinimumSize(QSize(90, 0));
        lblDateTimeFormat->setFont(font1);
        lblDateTimeFormat->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        layoutDateTimeFormat->addWidget(lblDateTimeFormat);

        editDateTimeFormat = new QLineEdit(gbFileName);
        editDateTimeFormat->setObjectName(QStringLiteral("editDateTimeFormat"));
        sizePolicy3.setHeightForWidth(editDateTimeFormat->sizePolicy().hasHeightForWidth());
        editDateTimeFormat->setSizePolicy(sizePolicy3);
        editDateTimeFormat->setFont(font1);

        layoutDateTimeFormat->addWidget(editDateTimeFormat);


        verticalLayout_2->addLayout(layoutDateTimeFormat);

        layoutUserName = new QHBoxLayout();
        layoutUserName->setObjectName(QStringLiteral("layoutUserName"));
        lblUserName = new QLabel(gbFileName);
        lblUserName->setObjectName(QStringLiteral("lblUserName"));
        lblUserName->setMinimumSize(QSize(90, 0));
        lblUserName->setFont(font1);
        lblUserName->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        layoutUserName->addWidget(lblUserName);

        editUserName = new QLineEdit(gbFileName);
        editUserName->setObjectName(QStringLiteral("editUserName"));
        sizePolicy3.setHeightForWidth(editUserName->sizePolicy().hasHeightForWidth());
        editUserName->setSizePolicy(sizePolicy3);
        editUserName->setFont(font1);

        layoutUserName->addWidget(editUserName);


        verticalLayout_2->addLayout(layoutUserName);

        layoutPassword = new QHBoxLayout();
        layoutPassword->setObjectName(QStringLiteral("layoutPassword"));
        lblPassword = new QLabel(gbFileName);
        lblPassword->setObjectName(QStringLiteral("lblPassword"));
        lblPassword->setMinimumSize(QSize(90, 0));
        lblPassword->setFont(font1);
        lblPassword->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        layoutPassword->addWidget(lblPassword);

        editPassword = new QLineEdit(gbFileName);
        editPassword->setObjectName(QStringLiteral("editPassword"));
        sizePolicy3.setHeightForWidth(editPassword->sizePolicy().hasHeightForWidth());
        editPassword->setSizePolicy(sizePolicy3);
        editPassword->setFont(font1);

        layoutPassword->addWidget(editPassword);


        verticalLayout_2->addLayout(layoutPassword);

        layoutDeviceTag = new QHBoxLayout();
        layoutDeviceTag->setObjectName(QStringLiteral("layoutDeviceTag"));
        lblDeviceTag = new QLabel(gbFileName);
        lblDeviceTag->setObjectName(QStringLiteral("lblDeviceTag"));
        lblDeviceTag->setMinimumSize(QSize(90, 0));
        lblDeviceTag->setFont(font1);
        lblDeviceTag->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        layoutDeviceTag->addWidget(lblDeviceTag);

        editDeviceTag = new QLineEdit(gbFileName);
        editDeviceTag->setObjectName(QStringLiteral("editDeviceTag"));
        sizePolicy3.setHeightForWidth(editDeviceTag->sizePolicy().hasHeightForWidth());
        editDeviceTag->setSizePolicy(sizePolicy3);
        editDeviceTag->setFont(font1);

        layoutDeviceTag->addWidget(editDeviceTag);


        verticalLayout_2->addLayout(layoutDeviceTag);

        vSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(vSpacer_2);


        verticalLayout_4->addWidget(gbFileName);

        gbConvertVideo = new QGroupBox(gbMain);
        gbConvertVideo->setObjectName(QStringLiteral("gbConvertVideo"));
        gbConvertVideo->setFlat(true);
        gbConvertVideo->setCheckable(true);
        gbConvertVideo->setChecked(false);
        verticalLayout_3 = new QVBoxLayout(gbConvertVideo);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        layoutCodec = new QHBoxLayout();
        layoutCodec->setObjectName(QStringLiteral("layoutCodec"));
        lblCodec = new QLabel(gbConvertVideo);
        lblCodec->setObjectName(QStringLiteral("lblCodec"));
        sizePolicy2.setHeightForWidth(lblCodec->sizePolicy().hasHeightForWidth());
        lblCodec->setSizePolicy(sizePolicy2);
        lblCodec->setMinimumSize(QSize(90, 0));
        lblCodec->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        layoutCodec->addWidget(lblCodec);

        cbCodec = new QComboBox(gbConvertVideo);
        cbCodec->setObjectName(QStringLiteral("cbCodec"));

        layoutCodec->addWidget(cbCodec);


        verticalLayout_3->addLayout(layoutCodec);

        layoutScale = new QHBoxLayout();
        layoutScale->setObjectName(QStringLiteral("layoutScale"));
        lblScale = new QLabel(gbConvertVideo);
        lblScale->setObjectName(QStringLiteral("lblScale"));
        sizePolicy2.setHeightForWidth(lblScale->sizePolicy().hasHeightForWidth());
        lblScale->setSizePolicy(sizePolicy2);
        lblScale->setMinimumSize(QSize(90, 0));
        lblScale->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        layoutScale->addWidget(lblScale);

        sbScale = new QSpinBox(gbConvertVideo);
        sbScale->setObjectName(QStringLiteral("sbScale"));
        sbScale->setMinimum(1);
        sbScale->setMaximum(8);

        layoutScale->addWidget(sbScale);


        verticalLayout_3->addLayout(layoutScale);

        layoutFps = new QHBoxLayout();
        layoutFps->setObjectName(QStringLiteral("layoutFps"));
        lblFps = new QLabel(gbConvertVideo);
        lblFps->setObjectName(QStringLiteral("lblFps"));
        sizePolicy2.setHeightForWidth(lblFps->sizePolicy().hasHeightForWidth());
        lblFps->setSizePolicy(sizePolicy2);
        lblFps->setMinimumSize(QSize(90, 0));
        lblFps->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        layoutFps->addWidget(lblFps);

        sbFps = new QSpinBox(gbConvertVideo);
        sbFps->setObjectName(QStringLiteral("sbFps"));
        sbFps->setMinimum(1);
        sbFps->setMaximum(10);

        layoutFps->addWidget(sbFps);


        verticalLayout_3->addLayout(layoutFps);


        verticalLayout_4->addWidget(gbConvertVideo);


        verticalLayout->addWidget(gbMain);

        layoutButtons = new QHBoxLayout();
        layoutButtons->setObjectName(QStringLiteral("layoutButtons"));
        spacerButtons = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        layoutButtons->addItem(spacerButtons);

        bnOk = new QPushButton(SvFFmpeg2FileSettings);
        bnOk->setObjectName(QStringLiteral("bnOk"));

        layoutButtons->addWidget(bnOk);

        bnCancel = new QPushButton(SvFFmpeg2FileSettings);
        bnCancel->setObjectName(QStringLiteral("bnCancel"));

        layoutButtons->addWidget(bnCancel);


        verticalLayout->addLayout(layoutButtons);

        QWidget::setTabOrder(editDeviceName, editMediaLink);
        QWidget::setTabOrder(editMediaLink, editSaveDirectory);
        QWidget::setTabOrder(editSaveDirectory, bnSelectSaveDirectory);
        QWidget::setTabOrder(bnSelectSaveDirectory, teFileDuration);
        QWidget::setTabOrder(teFileDuration, teTotalDuration);
        QWidget::setTabOrder(teTotalDuration, checkBoxTotalDuration);
        QWidget::setTabOrder(checkBoxTotalDuration, editFileNameFormat);
        QWidget::setTabOrder(editFileNameFormat, editDateTimeFormat);
        QWidget::setTabOrder(editDateTimeFormat, editUserName);
        QWidget::setTabOrder(editUserName, editPassword);
        QWidget::setTabOrder(editPassword, editDeviceTag);
        QWidget::setTabOrder(editDeviceTag, gbConvertVideo);
        QWidget::setTabOrder(gbConvertVideo, cbCodec);
        QWidget::setTabOrder(cbCodec, sbScale);
        QWidget::setTabOrder(sbScale, sbFps);
        QWidget::setTabOrder(sbFps, bnOk);
        QWidget::setTabOrder(bnOk, bnCancel);
        
        
        editDeviceName->setText(settings->device_name);
        editMediaLink->setText(settings->media_link);
        editSaveDirectory->setText(settings->path_to_save_file);
        teFileDuration->setTime(settings->file_duaration);
        teTotalDuration->setTime(settings->total_duration);
        checkBoxTotalDuration->setChecked(settings->doTotalTime);
        editFileNameFormat->setText(settings->file_name_format);
        editDateTimeFormat->setText(settings->datetime_format);
        editUserName->setText(settings->user_name);
        editPassword->setText(settings->password);
        editDeviceTag->setText(settings->device_tag); 
        sbScale->setValue(settings->scale);
        sbFps->setValue(settings->fps);
        cbCodec->setCurrentIndex(settings->codec);
          
            
        retranslateUi(SvFFmpeg2FileSettings);

        QMetaObject::connectSlotsByName(SvFFmpeg2FileSettings);
    } // setupUi

    void retranslateUi(QDialog *SvFFmpeg2FileSettings)
    {
        SvFFmpeg2FileSettings->setWindowTitle(QApplication::translate("SvFFmpeg2FileSettings", "Dialog", 0));
        gbMain->setTitle(QString());
        lblDeviceName->setText(QApplication::translate("SvFFmpeg2FileSettings", "Device name", 0));
        lblMediaLink->setText(QApplication::translate("SvFFmpeg2FileSettings", "Media link", 0));
        lblSaveDirectory->setText(QApplication::translate("SvFFmpeg2FileSettings", "Save files to", 0));
        bnSelectSaveDirectory->setText(QApplication::translate("SvFFmpeg2FileSettings", "...", 0));
        lblFileDuration->setText(QApplication::translate("SvFFmpeg2FileSettings", "File duration", 0));
        teFileDuration->setDisplayFormat(QApplication::translate("SvFFmpeg2FileSettings", "HH:mm:ss", 0));
        lblTotaDuration->setText(QApplication::translate("SvFFmpeg2FileSettings", "Total duration", 0));
        teTotalDuration->setDisplayFormat(QApplication::translate("SvFFmpeg2FileSettings", "HH:mm:ss", 0));
        checkBoxTotalDuration->setText(QString());
        gbFileName->setTitle(QApplication::translate("SvFFmpeg2FileSettings", "File name", 0));
        lblFileNameFormat->setText(QApplication::translate("SvFFmpeg2FileSettings", "File name format", 0));
        lblDateTimeFormat->setText(QApplication::translate("SvFFmpeg2FileSettings", "Date/Time format", 0));
        editDateTimeFormat->setText(QApplication::translate("SvFFmpeg2FileSettings", "ddMMyy_hhmmss", 0));
        lblUserName->setText(QApplication::translate("SvFFmpeg2FileSettings", "User name", 0));
        lblPassword->setText(QApplication::translate("SvFFmpeg2FileSettings", "Password", 0));
        lblDeviceTag->setText(QApplication::translate("SvFFmpeg2FileSettings", "Device tag", 0));
        gbConvertVideo->setTitle(QApplication::translate("SvFFmpeg2FileSettings", "Convert video", 0));
        lblCodec->setText(QApplication::translate("SvFFmpeg2FileSettings", "Codec", 0));
        lblScale->setText(QApplication::translate("SvFFmpeg2FileSettings", "Reduce scale", 0));
        lblFps->setText(QApplication::translate("SvFFmpeg2FileSettings", "Reduce fps", 0));
        bnOk->setText(QApplication::translate("SvFFmpeg2FileSettings", "OK", 0));
        bnCancel->setText(QApplication::translate("SvFFmpeg2FileSettings", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class SvFFmpeg2FileSettingsDialog: public Ui_SvFFmpeg2FileSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // SV_FFMPEG2FILESETTINGSJT2896_H
