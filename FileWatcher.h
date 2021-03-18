#ifndef FILEWATCHER_H
#define FILEWATCHER_H

#include <QObject>
#include <QFileInfo>
#include <QDateTime>

class FileWatcher : public QObject
{
    Q_OBJECT
public:
    FileWatcher(const QString &watchedFilePath, QObject *parent = nullptr);

    void setFile(const QString &path);

    QString getInfo() const;

signals:
    void infoUpdated();

public slots:
    void onFileInfoUpdated(const QFileInfo& newInfo);

private:
    QString watchedFile_;
    qint64 size_;
    QDateTime last_modified_;
};

Q_DECLARE_METATYPE(FileWatcher*)

#endif // FILEWATCHER_H
