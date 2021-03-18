#include <QApplication>
#include <QDir>
#include <QSharedPointer>
#include <QDebug>

#include "mainwindow.h"

//int main(int argc, char *argv[])
//{
//    QCoreApplication a(argc, argv);

//    FileManager& manager = FileManager::Instance();

//    QString currentDir = QString(DIR);
//    QStringList files = {
//        currentDir + "/test_file_1.txt",
//        currentDir + "/test_file_2.txt",
//    };

//    QVector<QSharedPointer<FileInfoWatcher>> watchers;
//    watchers.reserve(files.size());

//    for(const QString &path : files) {
//        auto watcher = QSharedPointer<FileInfoWatcher>::create(path);
//        watchers.append(watcher);
//        QObject::connect(&manager, &FileManager::fileInfoUpdated, watcher.get(), &FileInfoWatcher::onFileInfoUpdated);
//        QObject::connect(watcher.get(), &FileInfoWatcher::infoUpdated, [watcher]{
//            qDebug().noquote() << watcher->getInfo();
//        });
//    }

//    for(const QString &path : files) {
//        if (!manager.addPath(path)) {
//            return -1;
//        }
//    }

//    return a.exec();
//}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow wnd;
    wnd.show();
    return app.exec();
}

