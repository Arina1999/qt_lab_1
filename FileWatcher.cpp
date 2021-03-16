#include "FileWatcher.h"

#include <QFileInfo>
#include <QDateTime>

FileInfoWatcher::FileInfoWatcher(const QString &watchedFilePath, QObject *parent)
    : QObject(parent)
    , watchedFile_(watchedFilePath)
{ }

void FileInfoWatcher::setFile(const QString &path)
{
    watchedFile_ = path;
}

QString FileInfoWatcher::getInfoToString() const
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

void FileInfoWatcher::fileInfoUpdated(const QFileInfo &newInfo)
{
    if (newInfo.filePath() == watchedFile_) {
        size_ = newInfo.size();
        last_modified_ = newInfo.lastModified();
        emit fileChanged();
    }
}
