#ifndef ELIMINA_H
#define ELIMINA_H

#include <QDialog>

namespace Ui {
class Elimina;
}

class Elimina : public QDialog
{
    Q_OBJECT

public:
    explicit Elimina(QWidget *parent = nullptr);
    ~Elimina();

private:
    Ui::Elimina *ui;
};

#endif // ELIMINA_H
