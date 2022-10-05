#ifndef DEPOSIT_H
#define DEPOSIT_H

#include <QDialog>
#include <QMessageBox>
extern "C" {
#include "calc.h"
}

namespace Ui {
class Deposit;
}

class Deposit : public QDialog {
  Q_OBJECT

 public:
  explicit Deposit(QWidget *parent = nullptr);
  ~Deposit();

 private slots:
  void on_pushButton_drez_clicked();

  void on_comboBox_currentIndexChanged(int index);

  void on_comboBox_2_currentIndexChanged(int index);

  void on_checkBox_clicked(bool checked);

 private:
  Ui::Deposit *ui;

 public:
  int globalTer = 1;
  int globalPeriod = 1;
  int globalKap = 0;
};

#endif  // DEPOSIT_H
