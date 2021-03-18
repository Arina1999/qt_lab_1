#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "FileWatcher.h"
#include "FileManager.h"

#include <QFileDialog>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setInfo()
{
    on_listWidget_itemSelectionChanged();
    qDebug() << 1;
}

void MainWindow::on_selectPushButton_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, "Select file");
    if (!path.isEmpty())
    {
        ui->listWidget->addItem(path);
        FileWatcher *w = new FileWatcher(path, this);
        QObject::connect(&FileManager::Instance(), &FileManager::fileInfoUpdated, w, &FileWatcher::onFileInfoUpdated);

        QVariant v;
        v.setValue(w);
        ui->listWidget->item(ui->listWidget->count() - 1)->setData(Qt::UserRole, v);
        QObject::connect(w, &FileWatcher::infoUpdated, this, &MainWindow::setInfo);

        FileManager::Instance().addPath(path);
    }
}

void MainWindow::on_listWidget_doubleClicked(const QModelIndex &index)
{
    if (index.isValid())
    {
        index.data(Qt::UserRole).value<FileWatcher*>()->deleteLater();
        ui->listWidget->model()->removeRow(index.row());
        ui->textEdit->clear();
    }
}

void MainWindow::on_listWidget_itemSelectionChanged()
{
    auto it = ui->listWidget->currentItem();
    if (it)
    {
        ui->textEdit->setText(it->data(Qt::UserRole).value<FileWatcher*>()->getInfo());
    }
}
