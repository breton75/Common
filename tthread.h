#ifndef TTHREAD_H
#define TTHREAD_H

#include <QThread>
#include <ios>
#include <iostream>
#include <QTimer>

#include "log.h"
using namespace log_ns;

//namespace threads {
//  class TThread;
//}

class TThread : public QThread
{
    Q_OBJECT
  private:
    int thread_interval = 0;
    
  
  public:
    explicit TThread(int interval, QObject *parent = 0)
    {
      thread_interval = interval;
    }

    void run()
    {
       QTimer timer;
       timer.setInterval(thread_interval);
       timer.setSingleShot(false);
       connect(&timer, SIGNAL(timeout()), this, SIGNAL(progressed()));
       timer.start();
       log(m_Data, "timer started");
       exec();
    }
    
    
  signals:
    void progressed();
    
  public slots:
//    void ggg() { clog_ns::clog(0, "xxx"); }
    
};

//template <class T>
//class Threaded: public QObject
//{
//  protected:
//    T	*_obj;		// объект, исполняемый в новом потоке
//    TThread *_thr;
    
//  private:
//    int thread_interval = 0;
    
//  public:
//    explicit Threaded(QObject *parent = 0);
    
//    void start()
//    {
//      _thr = new TThread(thread_interval);
//      _obj = new T;
//      _obj->moveToThread(_thr);
//      connect(_thr, SIGNAL(progressed()), this, SIGNAL(progress()));
////      QObject::connect(thr, SIGNAL(progressed()), thr, SLOT(ggg()));
//      _thr->start();      
//    }
    
//    void setTimer(int interval)
//    {
//      thread_interval = interval;
//    }
    
//    T* ptr (void)               { return reinterpret_cast <T*> (_obj); }        // указатель на объект
//    const T* cptr (void) const	{ return reinterpret_cast <const T*> (_obj); }	// указатель на константный объект
    
//  signals:
//    void progress();
     
    
//};

#endif // TTHREAD_H
