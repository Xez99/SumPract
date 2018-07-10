#include "mainwindow.h"
#include "creationmenu.h"
#include <QApplication>
#include <QSystemSemaphore>
#include <QSharedMemory>
#include <QMessageBox>


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    QSystemSemaphore semaphore("RacerManagerApp_Semaphore", 1);
      semaphore.acquire();

  #ifndef Q_OS_WIN32
      QSharedMemory nix_fix_shared_memory("RacerManagerApp_Shared_Memory");
      if(nix_fix_shared_memory.attach()){
          nix_fix_shared_memory.detach();
      }
  #endif

      QSharedMemory sharedMemory("RacerManagerApp_Shared_Memory");

      bool is_running;
      if (sharedMemory.attach()){
          is_running = true;
      }else{
          sharedMemory.create(1);
          is_running = false;
      }
      semaphore.release();

      if(is_running){
          QMessageBox msgBox;
          msgBox.setIcon(QMessageBox::Warning);
          msgBox.setText(QString("Приложение уже запущено.\nРазрешен запуск только одного экземпляра приложения."));
          msgBox.exec();
          return 1;
      }

    MainWindow w;
    w.show();

    return a.exec();
}
