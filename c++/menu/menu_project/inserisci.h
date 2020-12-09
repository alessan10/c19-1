#ifndef INSERISCI_H
#define INSERISCI_H

#include <QDialog>

namespace Ui {
class Inserisci;
}

class Inserisci : public QDialog
{
    Q_OBJECT

public:
    explicit Inserisci(QWidget *parent = nullptr);
    ~Inserisci();

private:
    Ui::Inserisci *ui;
};

#endif // INSERISCI_H
