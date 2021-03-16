#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QFileInfo>
#include <QTimer>
#include <QMap>

class FileManager : public QObject
{
    Q_OBJECT
public:
    static FileManager& Instance()
    {
        static FileManager instance;
        return instance;
    }

    bool addPath(const QString &path);

    bool removePath(const QString &path);

signals:
    void fileInfoUpdated(const QFileInfo& newInfo);

private slots:
    void onTimer();

private:
    FileManager();
    FileManager(FileManager&&) = delete;
    FileManager& operator=(const FileManager&) = delete;

private:
    QTimer *timer_;
    QMap<QString, QFileInfo> filesData_;
};

#endif // FILEMANAGER_H
