//#include <QWidget>
//#include <QTextEdit>
//#include <QColor>
//#include <QDockWidget>
//#include <QVBoxLayout>
//#include <QMainWindow>
#include <QDateTime>
#include <ios>
#include <iostream>
#include <QDebug>

#include "console_log.h"
//#include "mainwindow.h"

using namespace clog_ns;
using namespace std;

//void log(int mode, QString text);

//QTextEdit   *wLog;  
//QDockWidget *wDock;
//QWidget     *wDockContents;
//QVBoxLayout *verticalLayout;

//void log_ns::create_log(QMainWindow *parent)
//{
//  if (!parent)
//    {
//      wLog = new QTextEdit;
//      wLog->show();
//    }
//  else 
//    {
//      wDock = new QDockWidget(parent);
//      wDock->setObjectName(QStringLiteral("wDock"));
//      wDock->setWindowTitle("Log");
//      wDock->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
//      wDock->setFeatures(QDockWidget::DockWidgetVerticalTitleBar);
//      wDock->setMinimumSize(QSize(100, 50));
//      wDock->setMaximumSize(QSize(16635, 16635));
      
//      wDockContents = new QWidget();
//      wDockContents->setObjectName(QStringLiteral("wDockContents"));
      
//      verticalLayout = new QVBoxLayout(wDockContents);
//      verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
//      wLog = new QTextEdit(wDockContents);
//      wLog->setObjectName(QStringLiteral("wLog"));

//      verticalLayout->addWidget(wLog);

//      wDock->setWidget(wDockContents);
//      parent->addDockWidget(static_cast<Qt::DockWidgetArea>(4), wDock);

//    }
//}

//void log_ns::assign_log(QTextEdit *Widget)
//{
//  if (!Widget)
//  {
//    wLog = new QTextEdit;
//    wLog->show();
//  }
//  else
//  {
//    wLog = Widget;
//  }
//}
  

void clog_ns::clog(int mode, QString text)
{
  switch (mode) {
      
    case m_Data:
      {     
//        wLog->setTextColor(Qt::blue);
        break;
      }

    case m_Err:
      {
//        wLog->setTextColor(Qt::red);
        break;
      }
      
    case m_Info:
      {
//        wLog->setTextColor(Qt::green);
        break;
      }
    }
  
  QDateTime time;
  QString a = time.currentDateTime().toString("dd.MM.yyyy hh:mm:ss.zzz: ") + text;
  
  
//  printf("%s", a.at(1));
  qDebug() << a; //.at(1);
//  cout << '\n';
}
