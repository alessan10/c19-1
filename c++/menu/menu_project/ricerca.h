#ifndef RICERCA_H
#define RICERCA_H

#include <QDialog>

namespace Ui {
class Ricerca;
}

class Ricerca : public QDialog
{
    Q_OBJECT

public:
    explicit Ricerca(QWidget *parent = nullptr);
    ~Ricerca();

private:
    Ui::Ricerca *ui;
};

#endif // RICERCA_H
