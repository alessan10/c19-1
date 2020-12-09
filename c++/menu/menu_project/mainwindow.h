#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionAbout_Our_Project_triggered();

    void on_actionExit_triggered();

    void on_actioninserisci_triggered();

    void on_actionRicerca_triggered();

    void on_actionElimina_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
