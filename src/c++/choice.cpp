#include "choice.h"

#include "ui_choice.h"

Choice::Choice(QWidget *parent, QString strOut):QDialog(parent),
  ui(new Ui::Choice) {
  ui->setupUi(this);
  globalStr = strOut;
  ui->show->setText(strOut);
  connect(ui->pButton_0, SIGNAL(clicked()), this, SLOT(d_numbers()));
  connect(ui->pButton_1, SIGNAL(clicked()), this, SLOT(d_numbers()));
  connect(ui->pButton_2, SIGNAL(clicked()), this, SLOT(d_numbers()));
  connect(ui->pButton_3, SIGNAL(clicked()), this, SLOT(d_numbers()));
  connect(ui->pButton_4, SIGNAL(clicked()), this, SLOT(d_numbers()));
  connect(ui->pButton_5, SIGNAL(clicked()), this, SLOT(d_numbers()));
  connect(ui->pButton_6, SIGNAL(clicked()), this, SLOT(d_numbers()));
  connect(ui->pButton_7, SIGNAL(clicked()), this, SLOT(d_numbers()));
  connect(ui->pButton_8, SIGNAL(clicked()), this, SLOT(d_numbers()));
  connect(ui->pButton_9, SIGNAL(clicked()), this, SLOT(d_numbers()));
}

Choice::~Choice() { delete ui; }

void Choice::d_numbers() {
  QPushButton *butt = (QPushButton *)sender();
  QString str;
  str = (ui->inter->text() + butt->text());
  ui->inter->setText(str);
}

void Choice::on_pButton_dot_clicked() {
  int count = 0;
  QString str = ui->inter->text();
  int len = str.isNull() ? 0 : str.length();
  for (int i = 0; i < len; i++) {
    if (str[i] == '.') {
      count = 1;
    } else if (str[i] != '0' && str[i] != '1' && str[i] != '2' &&
               str[i] != '3' && str[i] != '4' && str[i] != '5' &&
               str[i] != '6' && str[i] != '7' && str[i] != '8' &&
               str[i] != '9') {
      count = 0;
    }
  }
  if (len != 0) {
    if (count == 0 && (str[len - 1] >= '0' && str[len - 1] <= '9')) {
      ui->inter->setText(ui->inter->text() + ".");
    }
  }
}

void Choice::on_pButton_del_clicked() {
  QString str = ui->inter->text();
  QByteArray ba = str.toLocal8Bit();
  char *c_str2 = ba.data();
  char c_str3[256] = {0};
  if (str.isNull() == false) {
    for (int i = 0; i < str.length() - 1; i++) {
      c_str3[i] = c_str2[i];
    }
    ui->inter->setText(c_str3);
  }
}

void Choice::on_pushpButton_AC_clicked() {
  ui->inter->setText("");
  ui->show->setText(globalStr);
}

void Choice::on_pButton_equals_clicked() {
  double value_x = ui->inter->text().toDouble();
  QString str_expr = globalStr;
  QByteArray ba = str_expr.toLocal8Bit();
  char *c_str2 = ba.data();
  char outStr[256] = {0};
  double out = 0.0;
  int error = 0;
  error = s21_start(c_str2, &out, value_x);
  if (error == 0) {
    if (out == -0.0) {
      out = 0.0;
    }
    sprintf(outStr, "%.15g", out);
    ui->show->setText(globalStr + " = " + outStr);
  } else {
    if (error == 1) {
      sprintf(outStr, "%s", "Error 1: incorrect string");
    } else if (error == 2) {
      sprintf(outStr, "%s", "Error 2: invalid functions");
    } else if (error == 3) {
      sprintf(outStr, "%s", "Error 3: stack overflow error");
    } else if (error == 4) {
      sprintf(outStr, "%s", "Error 4: stack underflow error");
    } else if (error == 5) {
      sprintf(outStr, "%s", "Error 5: division by zero");
    } else if (error == 6) {
      sprintf(outStr, "%s", "Error 6: mod by zero");
    } else if (error == 7) {
      sprintf(outStr, "%s", "Error 7: asin() out of range");
    } else if (error == 8) {
      sprintf(outStr, "%s", "Error 8: acos() out of range");
    } else if (error == 9) {
      sprintf(outStr, "%s", "Error 9: Negative number! Can't take sqrt()");
    } else if (error == 10) {
      sprintf(outStr, "%s", "Error 10: Negative number! Can't take log()");
    } else if (error == 11) {
      sprintf(outStr, "%s", "Error 11: Negative number! Can't take ln()");
    } else {
      sprintf(outStr, "%s", "Unspecified error!");
    }
    ui->show->setText(outStr);
  }
}
