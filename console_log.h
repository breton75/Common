#ifndef C_LOG_H
#define C_LOG_H

//#include <QWidget>
//#include <QTextEdit>
//#include <QColor>
#include <QString>
//#include <QMainWindow>

namespace clog_ns
{

  const int m_Data = 0;
  const int m_Err = 1;
  const int m_Info = 2;
  
//  void create_log(QMainWindow *parent = 0);
//  void assign_log(QTextEdit *Widget = 0);
  void clog(int mode, QString text);
}




#endif // C_LOG_H
