#include "calc.h"

n_stack init_n_stack() {
  n_stack new;
  memset(new.m_num, 0.0, sizeof(new.m_num));
  new.top_num = -1;
  return new;
}

o_stack init_o_stack() {
  o_stack new;
  memset(new.m_operation, 0, sizeof(new.m_operation));
  new.top_operation = -1;
  new.priority = 0;
  return new;
}

double pop_n_stack(n_stack *ns) {
  double rez = 0.0;
  if (ns->top_num >= 0) {
    rez = ns->m_num[ns->top_num];
    ns->m_num[ns->top_num] = 0.0;
    ns->top_num -= 1;
  } else {
    rez = NAN;
  }
  return rez;
}
char pop_o_stack(o_stack *os) {
  char rez = 0;
  if (os->top_operation >= 0) {
    rez = os->m_operation[os->top_operation];
    os->m_operation[os->top_operation] = 0;
    os->top_operation -= 1;
    os->priority = set_priority(get_o_stack(*os));
  } else {
    rez = 127;
  }
  return rez;
}

int push_n_stack(n_stack *ns, double num) {
  int error = 0;
  if (ns->top_num < 255) {
    ns->top_num += 1;
    ns->m_num[ns->top_num] = num;
  } else {
    error = 3;
  }
  return error;
}

int push_o_stack(o_stack *os, char op) {
  int error = 0;
  if (os->top_operation < 255) {
    os->top_operation += 1;
    os->m_operation[os->top_operation] = op;
    os->priority = set_priority(op);
  } else {
    error = 1;
  }
  return error;
}

int set_priority(char priority) {
  int rez = -20;
  if (priority == '-') {
    rez = 1;
  } else if (priority == '+') {
    rez = 1;
  } else if (priority == '*') {
    rez = 2;
  } else if (priority == '/') {
    rez = 2;
  } else if (priority == 'm') {
    rez = 2;
  } else if (priority == '^') {
    rez = 6;
  } else if (priority == '(') {
    rez = 0;
  } else if (priority == ')') {
    rez = 0;
  } else if (priority == 'u') {
    rez = 8;
  } else if (priority == 'p') {
    rez = -2;
  } else if (priority == 's') {
    rez = 5;
  } else if (priority == 'c') {
    rez = 5;
  } else if (priority == 't') {
    rez = 5;
  } else if (priority == 'n') {
    rez = 5;
  } else if (priority == 'q') {
    rez = 5;
  } else if (priority == 'l') {
    rez = 5;
  } else if (priority == 'i') {
    rez = 5;
  } else if (priority == 'o') {
    rez = 5;
  } else if (priority == 'g') {
    rez = 5;
  }
  return rez;
}

// double get_n_stack(n_stack ns) {
//   double rez = 0.0;
//   if (ns.top_num >= 0) {
//     rez = ns.m_num[ns.top_num];
//   } else {
//     rez = NAN;
//   }
//   return rez;
// }

char get_o_stack(o_stack os) {
  char rez = 0;
  if (os.top_operation >= 0) {
    rez = os.m_operation[os.top_operation];
  } else {
    rez = 127;
  }
  return rez;
}

// void print_n_stack(n_stack ns) {
//   for (int i = 0; i <= ns.top_num; i++) {
//     printf("num: %lf", ns.m_num[i]);
//     printf(" ");
//   }
//   printf("\ntop num %d\n", ns.top_num);
// }

// void print_o_stack(o_stack os) {
//   for (int i = 0; i <= os.top_operation; i++) {
//     printf("operation: %c", os.m_operation[i]);
//     printf(" ");
//   }
//   printf("\ntop operation: %d\n", os.top_operation);
//   printf("priority top: %d\n", os.priority);
// }
