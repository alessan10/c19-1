#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <worker.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
     MainWindow(Worker &worker, QWidget *parent = nullptr);
    //MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionAbout_Our_Project_triggered();

    void on_actionExit_triggered();

    void on_actioninserisci_triggered();

    void on_actionRicerca_triggered();

    void on_actionVisualizza_Database_triggered();

    void on_actionTable_triggered();


private:
    Ui::MainWindow *ui;
    Worker worker;
};
#endif // MAINWINDOW_H
