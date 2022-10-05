#include "credit.h"

#include "ui_credit.h"

Credit::Credit(QWidget *parent) : QDialog(parent), ui(new Ui::Credit) {
  ui->setupUi(this);
}

Credit::~Credit() { delete ui; }

void Credit::on_radioButton_clicked() { globalStr = "A"; }

void Credit::on_radioButton_2_clicked() { globalStr = "D"; }

void Credit::on_pushButton_ac_clicked() {
  bool ok1;
  bool ok2;
  bool ok3;
  double sumCredit = ui->lineEdit->text().toDouble(&ok1);
  double tern = ui->lineEdit_2->text().toDouble(&ok2);
  tern *= globalInt;
  double per = ui->lineEdit_3->text().toDouble(&ok3);
  double month = 0.0;
  double over = 0.0;
  double all = 0.0;

  int error = 0;
  if (ok1 == true && ok2 == true && ok3 == true && tern < 601.00 &&
      globalStr.contains("A")) {
    error = credit_annuity(sumCredit, tern, per, &month, &over, &all);
    if (error == 0) {
      ui->label_7->setText(QString::number(month, 'f', 2));
      ui->label_9->setText(QString::number(over, 'f', 2));
      ui->label_11->setText(QString::number(all, 'f', 2));
    } else {
      QMessageBox::critical(this, "Error", "Incorrect data entry!");
    }
  } else if (ok1 == true && ok2 == true && ok3 == true && tern < 601.00 &&
             globalStr.contains("D")) {
    double month_pay_last = 0.0;
    error =
        credit_dif(sumCredit, tern, per, &month, &month_pay_last, &over, &all);
    if (error == 0) {
      ui->label_7->setText(QString::number(month, 'f', 2) + " ... " +
                           QString::number(month_pay_last, 'f', 2));
      ui->label_9->setText(QString::number(over, 'f', 2));
      ui->label_11->setText(QString::number(all, 'f', 2));
    } else {
      QMessageBox::critical(this, "Error", "Incorrect data entry!");
    }

  } else {
    QMessageBox::critical(this, "Error", "Incorrect data entry!");
  }
}

void Credit::on_comboBox_currentIndexChanged(int index) {
  if (index == 1) {
    globalInt = 12;
  } else if (index == 0) {
    globalInt = 1;
  }
}
