#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void setInfo();

private slots:
    void on_selectPushButton_clicked();

    void on_listWidget_doubleClicked(const QModelIndex &index);

    void on_listWidget_itemSelectionChanged();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
