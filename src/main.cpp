
#include "DirectoryManager.h"

#include <iostream>

#include <QtCore>
#include <QThread>
#include <QApplication>
#include <QMediaMetaData>
#include <QMediaPlayer>
#include <QAudioOutput>

void foo() {
   MediaPro::DirectoryManager test("/home/douell8/dev/cpp-workspace/CS4474/project/test_data/library");

   std::cout << test.getPath() << std::endl;
   std::cout << test.getLibrary()->dump(4) << std::endl;



   return;
}

int main(int argc, char** argv) {
   QApplication app(argc, argv);
   // std::cout << "constructor done" << std::endl;
   // foo();
   // QThread bar(QThread::create(foo));
   // std::cout << bar.isRunning() << std::endl;
   // bar.start();
   // std::cout << bar.isRunning() << std::endl;
   // QThread::sleep(10);
   // std::cout << "slept" << std::endl;
   // bar.wait();

   // app.quitOnLastWindowClosed();
   // std::cout << "test" << std::endl;
   // app.exec();
   // std::cout << "exec" << std::endl;
   // // app.exit();
   // app.quit();
   // app.moveToThread(&bar);

   auto player = new QMediaPlayer;
   auto audioOutput = new QAudioOutput;
   player->setAudioOutput(audioOutput);

   player->setSource(QUrl::fromLocalFile("/home/douell8/dev/cpp-workspace/CS4474/project/test_data/library/124 The Rolling Stones - Jumping Jack Flash.mp3"));
   audioOutput->setVolume(50);
   player->play();

   

   QThread::sleep(20);

   const auto metaData = player->metaData();
          
   std::cout << metaData.value(metaData.Title).toString().toStdString() << std::endl;
   std::cout << metaData.isEmpty() << std::endl;

   player->pause();


   return 0;
}