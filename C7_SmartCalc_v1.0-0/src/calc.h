#ifndef SRC_CALC_H_
#define SRC_CALC_H_
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack_num {
  double m_num[255];
  int top_num;
} n_stack;

typedef struct stack_op {
  char m_operation[255];
  int top_operation;
  int priority;
} o_stack;

/*
  '-' - sub, priority = 1
  '+' - add, priority = 1
  '*' - mul, priority = 2
  '/' - div, priority = 2
  'm' - mod, priority = 2
  '^' - pow, priority = 6
  '(' - open, priority = 0
  ')' - close, priority = 0
  'u' - unary minus, priority = 8
  'p' - unary plus, priority = -2  не должен влиять на выражение, просто
     выкидываем из стека
  's' - sin, priority = 5
  'c' - cos, priority = 5
  't' - tan, priority = 5
  'n' - atan, priority = 5
  'i' - asin, priority = 5
  'o' - acos, priority = 5
  'q' - sqrt, priority = 5
  'g' - log, priority = 5
  'l' - ln, priority = 5
*/

//  проверяет входящую строку на корректность
int check_inp_string(char *inp_str, int *x_count);
//  проверяет корректность чаров в строке
int check_char(char *inp_str);
//  перестраиваем строку, где каждой операции соответствует 1 символ
int rebuild_string(char *inp_str, char *new_str);
//  проверяем корректность операции mod и перестраиваем строку
int rebuild_for_mod(char *inp_str, char *new_str);
//  проверяем корректность знаков и перестраиваем строку
int rebuild_for_sign(char *inp_str, char *new_str);
//  устанавливает унарные знаки
void set_unary_operation(char *inp_str, char *new_str);
//  проверяем корректность *, ^, / и перестариваем строку
int rebuild_for_mdp(char *inp_str, char *new_str);
//  проверяем корректность операци с функциями и перестраиваем строку
int rebuild_for_functions(char *inp_str, char *new_str);
//  проверяет корректность элементов в строке после/до функций
int check_to_functions(const char *inp_str, int i_plus, int i_minus);
//  инициализация стэка чисел нулями
n_stack init_n_stack();
// инициализация стека символов нулями
o_stack init_o_stack();
//  получение верхнего элемента стэка чисел с удалением, если если стек пуст ->
//  NAN
double pop_n_stack(n_stack *ns);
//  получение верхнего элемента стэка символов с удалением, если стек пуст ->
//  127
char pop_o_stack(o_stack *os);
//  добавление на верх стека чисел элемента, если стек переполнен ->3, если
//  удалось ->0
int push_n_stack(n_stack *ns, double num);
//  добавление на верх стека символов элемента, если стек переполнен ->3, если
//  удалось ->0
int push_o_stack(o_stack *os, char op);
//  получение верхнего элемента стека чисел без удаления, если если стек пуст ->
//  NAN
double get_n_stack(n_stack ns);
//  получение верхнего элемента стека символов без удаления, если если стек пуст
//  -> 127
char get_o_stack(o_stack os);
//  вывод стэка чисел
void print_n_stack(n_stack ns);
//  вывод стэка символов
void print_o_stack(o_stack os);
//  устанавливает приоритет операций в стэке символов
int set_priority(char priority);
//  формирование и дальнейшая обработка стэка чисел и стэка операций
int polish_main(char *inp_str, double *out, double x);
//  часть входящей строки конвертирует в дабл
int string_to_num(char *str, int *i, double *rez);
//  обработка мат. действий
double math_actions(char cr, double a, double b, int *error);
//  обработка функция
double actions_on_functions(char cr, double a, int *error);
//  обработка данных в стэке
void stack_processing(o_stack *op, n_stack *num, int *error, char cr);
//  точка входа в логику бэкэнда
int s21_start(char *inp_str, double *out, double x);
//  кредитный калькулятор annuity
int credit_annuity(double sum_credit, double time_credit, double per,
                   double *month_pay, double *over_pay, double *all_pay);
//  кредитный калькулятор dif
int credit_dif(double sum_credit, double time_credit, double per,
               double *month_pay_first, double *month_pay_last,
               double *over_pay, double *all_pay);
//  получает сумму из списка пополнений, по номеру месяца
double get_re_list(double *re1, double const *re2, int count_re,
                   int count_month);
//  получает сумму из списка изъятия, по номеру месяца
double get_wi_list(double *wi1, double const *wi2, int count_wi,
                   int count_month, double all_sum);
//  депозитный калькулятор
int deposit_calculator(double *re1, double *re2, int count_re, double *wi1,
                       double *wi2, int count_wi, double all_sum, double tern,
                       double interest, double tax, int period_s, int kap,
                       double *all_interest, double *all_tax,
                       double *all_sum_after);

#endif  //  SRC_CALC_H_
