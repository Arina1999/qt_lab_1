#include "FileManager.h"

#include <QTimer>
#include <QFile>
#include <QDateTime>

FileManager::FileManager()
    : QObject(nullptr)
    , timer_(new QTimer(this))
{
    timer_->setInterval(250); // 250ms
    timer_->setSingleShot(false);
    timer_->start();

    connect(timer_, &QTimer::timeout, this, &FileManager::onTimer);
}

bool FileManager::addPath(const QString &path)
{
    if (!QFile::exists(path) || filesData_.contains(path)) {
        return false;
    }

    QFileInfo info(path);
    if (info.isDir()) {
        return false;
    }

    filesData_.insert(path, info);
    emit fileInfoUpdated(info);
    return true;
}

bool FileManager::removePath(const QString &path)
{
    return filesData_.remove(path) > 0;
}

void FileManager::onTimer()
{
    for(const QString& path : filesData_.keys()) {
        QFileInfo info(path);
        if (info.exists()) {
            if (info.lastModified() != filesData_[path].lastModified()) {
                filesData_[path] = info;
                emit fileInfoUpdated(info);
            }
        } else {
            filesData_.remove(path);
            emit fileInfoUpdated(info);
        }
    }
}
