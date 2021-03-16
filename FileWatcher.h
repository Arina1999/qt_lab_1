#ifndef FILEWATCHER_H
#define FILEWATCHER_H

#include <QObject>
#include <QFileInfo>
#include <QDateTime>

class FileInfoWatcher : public QObject
{
    Q_OBJECT
public:
    FileInfoWatcher(const QString &watchedFilePath, QObject *parent = nullptr);

    void setFile(const QString &path);

    QString getInfo() const;

signals:
    void fileChanged();

public slots:

    void fileInfoUpdated(const QFileInfo& newInfo);

private:
    QString watchedFile_;
    qint64 size_;
    QDateTime last_modified_;
};


#endif // FILEWATCHER_H
