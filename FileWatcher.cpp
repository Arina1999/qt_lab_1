#include "FileWatcher.h"

#include <QFileInfo>
#include <QDateTime>
#include <QDebug>

FileWatcher::FileWatcher(const QString &watchedFilePath, QObject *parent)
    : QObject(parent)
    , watchedFile_(watchedFilePath)
{ }

void FileWatcher::setFile(const QString &path)
{
    watchedFile_ = path;
}

QString FileWatcher::getInfo() const
{
    if (watchedFile_.isEmpty())
        return "No data";

    if (!QFile::exists(watchedFile_)) {
        return watchedFile_ + " -- no file";
    }

    return QString("Info:\n\tName: %2\n\tSize: %3\n\tLast modified: %4\n")
            .arg(watchedFile_)
            .arg(size_)
            .arg(last_modified_.toString(Qt::ISODate));
}

void FileWatcher::onFileInfoUpdated(const QFileInfo &newInfo)
{
    if (newInfo.filePath() == watchedFile_) {
        size_ = newInfo.size();
        last_modified_ = newInfo.lastModified();
        emit infoUpdated();
    }
}
