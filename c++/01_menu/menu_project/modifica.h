#ifndef MODIFICA_H
#define MODIFICA_H

#include <QDialog>

namespace Ui {
class Modifica;
}

class Modifica : public QDialog
{
    Q_OBJECT

public:
    explicit Modifica(QWidget *parent = nullptr);
    ~Modifica();

private:
    Ui::Modifica *ui;
};

#endif // MODIFICA_H
