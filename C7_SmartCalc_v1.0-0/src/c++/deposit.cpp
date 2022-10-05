#include "deposit.h"

#include "ui_deposit.h"

Deposit::Deposit(QWidget *parent) : QDialog(parent), ui(new Ui::Deposit) {
  ui->setupUi(this);
}

Deposit::~Deposit() { delete ui; }

void Deposit::on_pushButton_drez_clicked() {
  double re1[10];
  double re2[10];
  QList<QLineEdit *> r1 = {ui->lineEdit_r1_1, ui->lineEdit_r1_2,
                           ui->lineEdit_r1_3, ui->lineEdit_r1_4,
                           ui->lineEdit_r1_5, ui->lineEdit_r1_6,
                           ui->lineEdit_r1_7, ui->lineEdit_r1_8,
                           ui->lineEdit_r1_9, ui->lineEdit_r1_10};
  QList<QLineEdit *> r2 = {ui->lineEdit_r2_1, ui->lineEdit_r2_2,
                           ui->lineEdit_r2_3, ui->lineEdit_r2_4,
                           ui->lineEdit_r2_5, ui->lineEdit_r2_6,
                           ui->lineEdit_r2_7, ui->lineEdit_r2_8,
                           ui->lineEdit_r2_9, ui->lineEdit_r2_10};
  int countR = 0, errorUi = 0, j = 0;
  double buf1 = 0.0, buf2 = 0.0;
  for (int i = 0; i < 10; i++) {
    if (r1.at(i)->text().isEmpty() == false &&
        r2.at(i)->text().isEmpty() == false && errorUi == 0) {
      bool ok1, ok2;
      buf1 = r1.at(i)->text().toDouble(&ok1);
      buf2 = r2.at(i)->text().toDouble(&ok2);
      if (ok1 == true && ok2 == true && buf1 < 601) {
        re1[j] = buf1;
        re2[j] = buf2;
        j++;
        countR++;
      } else {
        errorUi = 1;
      }
    }
  }
  double wi1[10];
  double wi2[10];
  QList<QLineEdit *> w1 = {ui->lineEdit_w1_1, ui->lineEdit_w1_2,
                           ui->lineEdit_w1_3, ui->lineEdit_w1_4,
                           ui->lineEdit_w1_5, ui->lineEdit_w1_6,
                           ui->lineEdit_w1_7, ui->lineEdit_w1_8,
                           ui->lineEdit_w1_9, ui->lineEdit_w1_10};
  QList<QLineEdit *> w2 = {ui->lineEdit_w2_1, ui->lineEdit_w2_2,
                           ui->lineEdit_w2_3, ui->lineEdit_w2_4,
                           ui->lineEdit_w2_5, ui->lineEdit_w2_6,
                           ui->lineEdit_w2_7, ui->lineEdit_w2_8,
                           ui->lineEdit_w2_9, ui->lineEdit_w2_10};

  int countW = 0, k = 0;
  double bw1 = 0.0, bw2 = 0.0;
  for (int i = 0; i < 10; i++) {
    if (w1.at(i)->text().isEmpty() == false &&
        w2.at(i)->text().isEmpty() == false && errorUi == 0) {
      bool ok1, ok2;
      bw1 = w1.at(i)->text().toDouble(&ok1);
      bw2 = w2.at(i)->text().toDouble(&ok2);
      if (ok1 == true && ok2 == true && buf1 < 601) {
        wi1[k] = bw1;
        wi2[k] = bw2;
        k++;
        countW++;
      } else {
        errorUi = 1;
      }
    }
  }
  bool k1, k2, k3, k4;
  double all_sum = ui->lineEdit_1->text().toDouble(&k1);
  double tern = ui->lineEdit_2->text().toDouble(&k2);
  tern *= globalTer;
  double interest = ui->lineEdit_3->text().toDouble(&k3);
  double tax = ui->lineEdit_4->text().toDouble(&k4);
  double all_interest = 0.0, all_tax = 0.0, all_sum_after = 0.0;
  if (k1 == true && k2 == true && k3 == true && k4 == true) {
    int err = deposit_calculator(re1, re2, countR, wi1, wi2, countW, all_sum,
                                 tern, interest, tax, globalPeriod, globalKap,
                                 &all_interest, &all_tax, &all_sum_after);
    if (err == 0) {
      ui->label_10->setText(QString::number(all_interest, 'f', 2));
      ui->label_12->setText(QString::number(all_tax, 'f', 2));
      ui->label_14->setText(QString::number(all_sum_after, 'f', 2));
    } else {
      QMessageBox::critical(this, "Error", "Incorrect data entry!");
    }
  } else {
    QMessageBox::critical(this, "Error", "Incorrect data entry!");
  }
}

void Deposit::on_comboBox_currentIndexChanged(int index) {
  if (index == 1) {
    globalTer = 12;
  } else if (index == 0) {
    globalTer = 1;
  }
}

void Deposit::on_comboBox_2_currentIndexChanged(int index) {
  if (index == 0) {
    globalPeriod = 1;
  } else if (index == 1) {
    globalPeriod = 6;
  } else if (index == 2) {
    globalPeriod = 12;
  } else if (index == 3) {
    globalPeriod = 1;
  }
}

void Deposit::on_checkBox_clicked(bool checked) {
  if (checked == true) {
    globalKap = 1;
  } else {
    globalKap = 0;
  }
}
