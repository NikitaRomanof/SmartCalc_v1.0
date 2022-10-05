#include "calc.h"

int s21_start(char *inp_str, double *out, double x) {
  int error = 0;
  int x_count = 0;
  char new[255];
  memset(new, 0, sizeof(new));
  error = check_inp_string(inp_str, &x_count);
  error = error == 0 ? check_char(inp_str) : error;
  error = error == 0 ? rebuild_string(inp_str, new) : error;
  if (error == 0) {
    double buf = 0.0;
    double z = x_count == 0 ? 0.0 : x;
    error = polish_main(new, &buf, z);
    if (buf < 1e-15 && buf > -1e-15) {
      buf = 0;
    }
    if (error == 0) {
      *out = buf;
    }
  }
  return error;
}

int polish_main(char *new_str, double *out, double x) {
  n_stack num = init_n_stack();
  o_stack op = init_o_stack();
  int error = 0;
  for (int i = 0; i < (int)strlen(new_str) && error == 0;) {
    if (new_str[i] >= '0' && new_str[i] <= '9') {
      if (new_str[i - 1] == ')') error = 2;
      double buf_rez = 0.0;
      if (error == 0) error = string_to_num(new_str, &i, &buf_rez);
      if (new_str[i] == '(') error = 2;
      if (error == 0) {
        error = push_n_stack(&num, buf_rez);
      }
    } else if (new_str[i] == 'p') {
      i++;
    } else if (new_str[i] == 'x') {
      error = push_n_stack(&num, x);
      i++;
    } else {
      if ((op.top_operation == -1 || set_priority(new_str[i]) > op.priority ||
           new_str[i] == '(' ||
           (set_priority(new_str[i]) == 5 &&
            (op.priority == 5 || op.priority == 8))) &&
          new_str[i] != ')') {
        error = push_o_stack(&op, new_str[i]);
        i++;
      } else {
        stack_processing(&op, &num, &error, new_str[i]);
        i++;
      }
    }
  }
  stack_processing(&op, &num, &error, 0);
  if (error == 0) {
    *out = pop_n_stack(&num);
  }
  if (isnan(*out) != 0) {
    error = 4;
  }
  return error;
}

void stack_processing(o_stack *op, n_stack *num, int *error, char cr) {
  while ((((cr == ')' && get_o_stack(*op) != '(') ||
           (cr != ')' && (set_priority(cr) <= op->priority))) ||
          (cr == 0)) &&
         (get_o_stack(*op) != 127 && *error == 0)) {
    int priority = op->priority;
    char ch = pop_o_stack(op);
    double rez = 0.0;
    if (priority != 5 && priority != 8) {
      double b = pop_n_stack(num);
      double a = pop_n_stack(num);
      if (isnan(a) == 0 && isnan(b) == 0) {
        rez = math_actions(ch, a, b, error);
        *error = *error == 0 ? push_n_stack(num, rez) : *error;
      } else {
        *error = 4;
      }
    } else if (priority == 8) {
      double a = pop_n_stack(num);
      if (isnan(a) == 0) {
        a *= -1;
        *error = push_n_stack(num, a);
      } else {
        *error = 4;
      }
    } else if (priority == 5) {
      double a = pop_n_stack(num);
      if (isnan(a) == 0) {
        rez = actions_on_functions(ch, a, error);
        *error = *error == 0 ? push_n_stack(num, rez) : *error;
      } else {
        *error = 4;
      }
    } else {
      *error = 4;
    }
  }
  if (cr == ')' && *error == 0) pop_o_stack(op);
  if (cr != ')' && *error == 0) push_o_stack(op, cr);
}

double math_actions(char cr, double a, double b, int *error) {
  double rez = 0.0;
  if (cr == '-' && *error == 0) {
    rez = a - b;
  } else if (cr == '+' && *error == 0) {
    rez = a + b;
  } else if (cr == '*' && *error == 0) {
    rez = a * b;
  } else if (cr == '/' && *error == 0) {
    if (fabs(b) > 1e-15) {
      rez = a / b;
    } else {
      *error = 5;
    }
  } else if (cr == 'm' && *error == 0) {
    if (fabs(b) > 1e-15) {
      rez = fmod(a, b);
    } else {
      *error = 6;
    }
  } else if (cr == '^' && *error == 0) {
    rez = pow(a, b);
  }
  return rez;
}

double actions_on_functions(char cr, double a, int *error) {
  double rez = 0.0;
  if (cr == 's' && *error == 0) {
    rez = sin(a);
  } else if (cr == 'c' && *error == 0) {
    rez = cos(a);
  } else if (cr == 't' && *error == 0) {
    rez = tan(a);
  } else if (cr == 'n' && *error == 0) {
    rez = atan(a);
  } else if (cr == 'i' && *error == 0) {
    if (a >= -1 && a <= 1) {
      rez = asin(a);
    } else {
      *error = 7;
    }
  } else if (cr == 'o' && *error == 0) {
    if (a >= -1.0 && a <= 1.0) {
      rez = acos(a);
    } else {
      *error = 8;
    }
  } else if (cr == 'q' && *error == 0) {
    if (a > -1e-15) {
      rez = sqrt(a);
    } else {
      *error = 9;
    }
  } else if (cr == 'g' && *error == 0) {
    if (a > -1e-15) {
      rez = log10(a);
    } else {
      *error = 10;
    }
  } else if (cr == 'l' && *error == 0) {
    if (a > -1e-15) {
      rez = log(a);
    } else {
      *error = 11;
    }
  }
  return rez;
}

int string_to_num(char *str, int *i, double *rez) {
  int count_num = 0, count_dot = 0, error = 0;
  char buf_num[255];
  memset(buf_num, 0, sizeof(buf_num));
  while (((str[*i] >= '0' && str[*i] <= '9') || str[*i] == '.') && error == 0 &&
         *i < (int)strlen(str)) {
    if (str[*i] == '.') {
      count_dot++;
    }
    error = count_dot > 1 ? 1 : error;
    buf_num[count_num] = str[*i];
    count_num++;
    *i = *i + 1;
  }
  buf_num[count_num] = '\0';
  *rez = strtod(buf_num, NULL);
  return error;
}
