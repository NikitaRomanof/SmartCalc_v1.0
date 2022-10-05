#include <check.h>

#include "calc.h"

START_TEST(test1_math) {
  char *test1 = "1+2";
  double t1 = 0.0;
  s21_start(test1, &t1, 0.0);
  double ch1 = 1 + 2;
  ck_assert_double_eq(t1, ch1);
}
END_TEST

START_TEST(test2_math) {
  char *test2 = "1-2";
  double t2 = 0.0;
  s21_start(test2, &t2, 0.0);
  double ch2 = 1 - 2;
  ck_assert_double_eq(t2, ch2);
}
END_TEST

START_TEST(test3_math) {
  char *test3 = "1000";
  double t3 = 0.0;
  s21_start(test3, &t3, 0.0);
  double ch3 = 1000;
  ck_assert_double_eq(t3, ch3);
}
END_TEST

START_TEST(test4_math) {
  char *test4 = "(1000)";
  double t4 = 0.0;
  s21_start(test4, &t4, 0.0);
  double ch4 = 1000;
  ck_assert_double_eq(t4, ch4);
}
END_TEST

START_TEST(test5_math) {
  char *test5 = "2/(1+1)";
  double t5 = 0.0;
  s21_start(test5, &t5, 0.0);
  double ch5 = 2 / (1 + 1);
  ck_assert_double_eq(t5, ch5);
}
END_TEST

START_TEST(test6_math) {
  char *test6 = "2*(5-2)";
  double t6 = 0.0;
  s21_start(test6, &t6, 0.0);
  double ch6 = 2 * (5 - 2);
  ck_assert_double_eq(t6, ch6);
}
END_TEST

START_TEST(test7_math) {
  char *test7 = "2*(5-x)";
  double t7 = 0.0;
  s21_start(test7, &t7, 2.0);
  double ch7 = 2 * (5 - 2);
  ck_assert_double_eq(t7, ch7);
}
END_TEST

START_TEST(test8_math) {
  char *test8 = "(2^2)+(2^2)";
  double t8 = 0.0;
  s21_start(test8, &t8, 0.0);
  double ch8 = pow(2, 2) + pow(2, 2);
  ck_assert_double_eq(t8, ch8);
}
END_TEST

START_TEST(test9_math) {
  char *test9 = "2^2)+(2^2)";
  double t9 = 0.0;
  int error9 = s21_start(test9, &t9, 0.0);
  int ch_error9 = 1;
  ck_assert_int_eq(error9, ch_error9);
}
END_TEST

START_TEST(test10_math) {
  char *test10 = "mod2";
  double t10 = 0.0;
  int error10 = s21_start(test10, &t10, 0.0);
  int ch_error10 = 2;
  ck_assert_int_eq(error10, ch_error10);
}
END_TEST

START_TEST(test11_math) {
  char *test11 = "()";
  double t11 = 0.0;
  int error11 = s21_start(test11, &t11, 0.0);
  int ch_error11 = 4;
  ck_assert_int_eq(error11, ch_error11);
}
END_TEST

START_TEST(test12_math) {
  char *test12 = "1/0";
  double t12 = 0.0;
  int error12 = s21_start(test12, &t12, 0.0);
  int ch_error12 = 5;
  ck_assert_int_eq(error12, ch_error12);
}
END_TEST

START_TEST(test13_math) {
  char *test13 = "2mod0";
  double t13 = 0.0;
  int error13 = s21_start(test13, &t13, 0.0);
  int ch_error13 = 6;
  ck_assert_int_eq(error13, ch_error13);
}
END_TEST

START_TEST(test14_math) {
  char *test14 = "((((10))))";
  double t14 = 0.0;
  s21_start(test14, &t14, 0.0);
  double ch14 = 10;
  ck_assert_double_eq(t14, ch14);
}
END_TEST

START_TEST(test15_math) {
  char *test15 = "sqrt9";
  double t15 = 0.0;
  s21_start(test15, &t15, 0.0);
  double ch15 = 3;
  ck_assert_double_eq(t15, ch15);
}
END_TEST

START_TEST(test16_math) {
  char *test16 = "10mod5";
  double t16 = 0.0;
  s21_start(test16, &t16, 0.0);
  double ch16 = 0;
  ck_assert_double_eq(t16, ch16);
}
END_TEST

START_TEST(test17_math) {
  char *test17 = "log10";
  double t17 = 0.0;
  s21_start(test17, &t17, 0.0);
  double ch17 = 1;
  ck_assert_double_eq(t17, ch17);
}
END_TEST

START_TEST(test18_math) {
  char *test18 = "ln2.718281828459045";
  double t18 = 0.0;
  s21_start(test18, &t18, 0.0);
  double ch18 = 1;
  ck_assert_double_eq(t18, ch18);
}
END_TEST

START_TEST(test19_math) {
  char *test19 = "log-10";
  double t19 = 0.0;
  int error19 = s21_start(test19, &t19, 0.0);
  int ch_error19 = 10;
  ck_assert_int_eq(error19, ch_error19);
}
END_TEST

START_TEST(test20_math) {
  char *test20 = "ln-10";
  double t20 = 0.0;
  int error20 = s21_start(test20, &t20, 0.0);
  int ch_error20 = 11;
  ck_assert_int_eq(error20, ch_error20);
}
END_TEST

START_TEST(test21_math) {
  char *test21 = "sqrt-10";
  double t21 = 0.0;
  int error21 = s21_start(test21, &t21, 0.0);
  int ch_error21 = 9;
  ck_assert_int_eq(error21, ch_error21);
}
END_TEST

START_TEST(test22_math) {
  char *test22 = "---5";
  double t22 = 0.0;
  s21_start(test22, &t22, 0.0);
  double ch22 = -5;
  ck_assert_double_eq(t22, ch22);
}
END_TEST

START_TEST(test23_math) {
  char *test23 = "--++5";
  double t23 = 0.0;
  s21_start(test23, &t23, 0.0);
  double ch23 = 5;
  ck_assert_double_eq(t23, ch23);
}
END_TEST

START_TEST(test24_math) {
  char *test24 = "5-10";
  double t24 = 0.0;
  s21_start(test24, &t24, 0.0);
  double ch24 = -5;
  ck_assert_double_eq(t24, ch24);
}
END_TEST

START_TEST(test25_math) {
  char *test25 = "3*3";
  double t25 = 0.0;
  s21_start(test25, &t25, 0.0);
  double ch25 = 3 * 3;
  ck_assert_double_eq(t25, ch25);
}
END_TEST

START_TEST(test26_math) {
  char *test26 = "9/3";
  double t26 = 0.0;
  s21_start(test26, &t26, 0.0);
  double ch26 = 9 / 3;
  ck_assert_double_eq(t26, ch26);
}
END_TEST

START_TEST(test27_math) {
  char *test27 = "0*3";
  double t27 = 0.0;
  s21_start(test27, &t27, 0.0);
  double ch27 = 0 * 3;
  ck_assert_double_eq(t27, ch27);
}
END_TEST

START_TEST(test28_math) {
  char *test28 = "0^(-1)";
  double t28 = 0.0;
  s21_start(test28, &t28, 0.0);
  double ch28 = INFINITY;
  ck_assert_double_eq(t28, ch28);
}
END_TEST

START_TEST(test29_math) {
  char *test29 = "ln0";
  double t29 = 0.0;
  s21_start(test29, &t29, 0.0);
  double ch29 = -INFINITY;
  ck_assert_double_eq(t29, ch29);
}
END_TEST

START_TEST(test30_math) {
  char *test30 = "-0";
  double t30 = 0.0;
  s21_start(test30, &t30, 0.0);
  double ch30 = 0;
  ck_assert_double_eq(t30, ch30);
}
END_TEST

Suite *calc_math(void) {
  Suite *s;
  TCase *tc_math;
  s = suite_create("calc_math");
  tc_math = tcase_create("math");
  tcase_add_test(tc_math, test1_math);
  tcase_add_test(tc_math, test2_math);
  tcase_add_test(tc_math, test3_math);
  tcase_add_test(tc_math, test4_math);
  tcase_add_test(tc_math, test5_math);
  tcase_add_test(tc_math, test6_math);
  tcase_add_test(tc_math, test7_math);
  tcase_add_test(tc_math, test8_math);
  tcase_add_test(tc_math, test9_math);
  tcase_add_test(tc_math, test10_math);
  tcase_add_test(tc_math, test11_math);
  tcase_add_test(tc_math, test12_math);
  tcase_add_test(tc_math, test13_math);
  tcase_add_test(tc_math, test14_math);
  tcase_add_test(tc_math, test15_math);
  tcase_add_test(tc_math, test16_math);
  tcase_add_test(tc_math, test17_math);
  tcase_add_test(tc_math, test18_math);
  tcase_add_test(tc_math, test19_math);
  tcase_add_test(tc_math, test20_math);
  tcase_add_test(tc_math, test21_math);
  tcase_add_test(tc_math, test22_math);
  tcase_add_test(tc_math, test23_math);
  tcase_add_test(tc_math, test24_math);
  tcase_add_test(tc_math, test25_math);
  tcase_add_test(tc_math, test26_math);
  tcase_add_test(tc_math, test27_math);
  tcase_add_test(tc_math, test28_math);
  tcase_add_test(tc_math, test29_math);
  tcase_add_test(tc_math, test30_math);
  suite_add_tcase(s, tc_math);
  return s;
}

START_TEST(test1_trig) {
  char *test_t1 = "sin(3.141592653589793/2)";
  double tt1 = 0.0;
  s21_start(test_t1, &tt1, 0.0);
  double cht1 = sin(3.141592653589793 / 2);
  ck_assert_double_eq(tt1, cht1);
}
END_TEST

START_TEST(test2_trig) {
  char *test_t2 = "cos(3.141592653589793)";
  double tt2 = 0.0;
  s21_start(test_t2, &tt2, 0.0);
  double cht2 = cos(3.141592653589793);
  ck_assert_double_eq(tt2, cht2);
}
END_TEST

START_TEST(test3_trig) {
  char *test_t3 = "cos(0)";
  double tt3 = 0.0;
  s21_start(test_t3, &tt3, 0.0);
  double cht3 = cos(0);
  ck_assert_double_eq(tt3, cht3);
}
END_TEST

START_TEST(test4_trig) {
  char *test_t4 = "cos(3.141592653589793/2)+(10)*(-1)";
  double tt4 = 0.0;
  s21_start(test_t4, &tt4, 0.0);
  double cht4 = cos(3.141592653589793 / 2) + (10) * (-1);
  ck_assert_double_eq(tt4, cht4);
}
END_TEST

START_TEST(test5_trig) {
  char *test_t5 = "sin(0)";
  double tt5 = 0.0;
  s21_start(test_t5, &tt5, 0.0);
  double cht5 = sin(0);
  ck_assert_double_eq(tt5, cht5);
}
END_TEST

START_TEST(test6_trig) {
  char *test_t6 = "-sin(3.141592653589793/2)";
  double tt6 = 0.0;
  s21_start(test_t6, &tt6, 0.0);
  double cht6 = -sin(3.141592653589793 / 2);
  ck_assert_double_eq(tt6, cht6);
}
END_TEST

START_TEST(test7_trig) {
  char *test_t7 = "tan(0)";
  double tt7 = 0.0;
  s21_start(test_t7, &tt7, 0.0);
  double cht7 = tan(0);
  ck_assert_double_eq(tt7, cht7);
}
END_TEST

START_TEST(test8_trig) {
  char *test_t8 = "-tan(3.141592653589793/4)";
  double tt8 = 0.0;
  s21_start(test_t8, &tt8, 0.0);
  double cht8 = -tan(3.141592653589793 / 4);
  ck_assert_double_eq(tt8, cht8);
}
END_TEST

START_TEST(test9_trig) {
  char *test_t9 = "tan(3.141592653589793/2)";
  double tt9 = 0.0;
  s21_start(test_t9, &tt9, 0.0);
  double cht9 = tan(3.141592653589793 / 2);
  ck_assert_double_eq(tt9, cht9);
}
END_TEST

START_TEST(test10_trig) {
  char *test_t10 = "atan(0)";
  double tt10 = 0.0;
  s21_start(test_t10, &tt10, 0.0);
  double cht10 = atan(0);
  ck_assert_double_eq(tt10, cht10);
}
END_TEST

START_TEST(test11_trig) {
  char *test_t11 = "asin(0)";
  double tt11 = 0.0;
  s21_start(test_t11, &tt11, 0.0);
  double cht11 = asin(0);
  ck_assert_double_eq(tt11, cht11);
}
END_TEST

START_TEST(test12_trig) {
  char *test_t12 = "asin(-1)";
  double tt12 = 0.0;
  s21_start(test_t12, &tt12, 0.0);
  double cht12 = asin(-1);
  ck_assert_double_eq(tt12, cht12);
}
END_TEST

START_TEST(test13_trig) {
  char *test_t13 = "acos(0)";
  double tt13 = 0.0;
  s21_start(test_t13, &tt13, 0.0);
  double cht13 = acos(0);
  ck_assert_double_eq(tt13, cht13);
}
END_TEST

START_TEST(test14_trig) {
  char *test_t14 = "acos(1)";
  double tt14 = 0.0;
  s21_start(test_t14, &tt14, 0.0);
  double cht14 = acos(1);
  ck_assert_double_eq(tt14, cht14);
}
END_TEST

START_TEST(test15_trig) {
  char *test_t15 = "acos(-2)";
  double tt15 = 0.0;
  int error_t15 = s21_start(test_t15, &tt15, 0.0);
  int ch_error_t15 = 8;
  ck_assert_int_eq(error_t15, ch_error_t15);
}
END_TEST

START_TEST(test16_trig) {
  char *test_t16 = "asin(-2)";
  double tt16 = 0.0;
  int error_t16 = s21_start(test_t16, &tt16, 0.0);
  int ch_error_t16 = 7;
  ck_assert_int_eq(error_t16, ch_error_t16);
}
END_TEST

Suite *calc_trig(void) {
  Suite *s;
  TCase *tc_trig;
  s = suite_create("calc_trig");
  tc_trig = tcase_create("trig");
  tcase_add_test(tc_trig, test1_trig);
  tcase_add_test(tc_trig, test2_trig);
  tcase_add_test(tc_trig, test3_trig);
  tcase_add_test(tc_trig, test4_trig);
  tcase_add_test(tc_trig, test5_trig);
  tcase_add_test(tc_trig, test6_trig);
  tcase_add_test(tc_trig, test7_trig);
  tcase_add_test(tc_trig, test8_trig);
  tcase_add_test(tc_trig, test9_trig);
  tcase_add_test(tc_trig, test10_trig);
  tcase_add_test(tc_trig, test11_trig);
  tcase_add_test(tc_trig, test12_trig);
  tcase_add_test(tc_trig, test13_trig);
  tcase_add_test(tc_trig, test14_trig);
  tcase_add_test(tc_trig, test15_trig);
  tcase_add_test(tc_trig, test16_trig);
  suite_add_tcase(s, tc_trig);
  return s;
}

START_TEST(test1_credit) {
  double sum_credit1 = 1000000;
  double time_credit1 = 12.0;
  double per1 = 15;
  double month_pay1 = 0.0;
  double over_pay1 = 0.0;
  double all_pay1 = 0.0;
  int error1 = credit_annuity(sum_credit1, time_credit1, per1, &month_pay1,
                              &over_pay1, &all_pay1);

  double month_pay_check1 = 90258.31;
  double over_pay_check1 = 83099.72;
  double all_pay_check1 = 1083099.72;
  int error_check1 = 0;
  ck_assert_int_eq((int)month_pay1, (int)month_pay_check1);
  ck_assert_int_eq((int)over_pay1, (int)over_pay_check1);
  ck_assert_int_eq((int)all_pay1, (int)all_pay_check1);
  ck_assert_int_eq(error1, error_check1);
}
END_TEST

START_TEST(test2_credit) {
  double sum_credit2 = 1000000;
  double time_credit2 = 12.0;
  double per2 = 15;
  double month_pay2 = 0.0;
  double month_pay2_last = 0.0;
  double over_pay2 = 0.0;
  double all_pay2 = 0.0;
  int error2 = credit_dif(sum_credit2, time_credit2, per2, &month_pay2,
                          &month_pay2_last, &over_pay2, &all_pay2);

  double month_pay_check2 = 95833.33;
  double month_pay_last_check2 = 84375.00;
  double over_pay_check2 = 81250.00;
  double all_pay_check2 = 1081250.00;
  int error_check2 = 0;
  ck_assert_int_eq((int)month_pay2, (int)month_pay_check2);
  ck_assert_int_eq((int)month_pay2_last, (int)month_pay_last_check2);
  ck_assert_int_eq((int)over_pay2, (int)over_pay_check2);
  ck_assert_int_eq((int)all_pay2, (int)all_pay_check2);
  ck_assert_int_eq(error2, error_check2);
}
END_TEST

START_TEST(test3_credit) {
  double sum_credit3 = 1000000;
  double time_credit3 = 12.0;
  double per3 = 0;
  double month_pay3 = 0.0;
  double over_pay3 = 0.0;
  double all_pay3 = 0.0;
  int error3 = credit_annuity(sum_credit3, time_credit3, per3, &month_pay3,
                              &over_pay3, &all_pay3);
  int error_check3 = 1;
  ck_assert_int_eq(error3, error_check3);
}
END_TEST

START_TEST(test4_credit) {
  double sum_credit4 = 1000000;
  double time_credit4 = 12.0;
  double per4 = 15;
  double month_pay4 = 0.0;
  double month_pay4_last = 0.0;
  double over_pay4 = 0.0;
  double all_pay4 = 0.0;
  int error4 = credit_dif(sum_credit4, time_credit4, per4, &month_pay4,
                          &month_pay4_last, &over_pay4, &all_pay4);
  int error_check4 = 0;
  ck_assert_int_eq(error4, error_check4);
}
END_TEST

Suite *calc_credit(void) {
  Suite *s;
  TCase *tc_credit;
  s = suite_create("calc_credit");
  tc_credit = tcase_create("credit");
  tcase_add_test(tc_credit, test1_credit);
  tcase_add_test(tc_credit, test2_credit);
  tcase_add_test(tc_credit, test3_credit);
  tcase_add_test(tc_credit, test4_credit);
  suite_add_tcase(s, tc_credit);
  return s;
}

START_TEST(test1_deposit) {
  double *re1 = {0};
  double *re2 = {0};
  int count_re = 0;
  double *wi1 = {0};
  double *wi2 = {0};
  int count_wi = 0;
  double all_sum = 1000000;
  double tern = 12;
  double interest = 15;
  double tax = 13;
  int period_s = 1;
  int kap = 0;
  double all_interest = 0;
  double all_tax = 0;
  double all_sum_after = 0;
  int errordep1 = deposit_calculator(
      re1, re2, count_re, wi1, wi2, count_wi, all_sum, tern, interest, tax,
      period_s, kap, &all_interest, &all_tax, &all_sum_after);
  double all_interest_check = 149999;
  double all_tax_check = 7149;
  double all_sum_after_check = 1000000;
  ck_assert_int_eq((int)all_interest, (int)all_interest_check);
  ck_assert_int_eq((int)all_tax, (int)all_tax_check);
  ck_assert_int_eq((int)all_sum_after, (int)all_sum_after_check);
  ck_assert_int_eq(errordep1, 0);
}
END_TEST

START_TEST(test2_deposit) {
  double re1[10] = {0};
  re1[0] = 1;
  double re2[10] = {0};
  re2[0] = 100000;
  int count_re = 1;
  double wi1[10] = {0};
  wi1[0] = 10;
  double wi2[10] = {0};
  wi2[0] = 1000;
  int count_wi = 1;
  double all_sum = 1000000;
  double tern = 12;
  double interest = 15;
  double tax = 13;
  int period_s = 6;
  int kap = 1;
  double all_interest = 0;
  double all_tax = 0;
  double all_sum_after = 0;
  int errordep1 = deposit_calculator(
      re1, re2, count_re, wi1, wi2, count_wi, all_sum, tern, interest, tax,
      period_s, kap, &all_interest, &all_tax, &all_sum_after);
  double all_interest_check = 171112;
  double all_tax_check = 9894;
  double all_sum_after_check = 1270112;
  ck_assert_int_eq((int)all_interest, (int)all_interest_check);
  ck_assert_int_eq((int)all_tax, (int)all_tax_check);
  ck_assert_int_eq((int)all_sum_after, (int)all_sum_after_check);
  ck_assert_int_eq(errordep1, 0);
}
END_TEST

Suite *calc_deposit(void) {
  Suite *s;
  TCase *tc_deposit;
  s = suite_create("calc_deposit");
  tc_deposit = tcase_create("deposit");
  tcase_add_test(tc_deposit, test1_deposit);
  tcase_add_test(tc_deposit, test2_deposit);
  suite_add_tcase(s, tc_deposit);
  return s;
}

void calc_tests(SRunner **sr) {
  *sr = srunner_create(calc_math());
  srunner_add_suite(*sr, calc_trig());
  srunner_add_suite(*sr, calc_credit());
  srunner_add_suite(*sr, calc_deposit());
}

int main(void) {
  int number_failed;
  SRunner *sr = NULL;
  calc_tests(&sr);
  srunner_run_all(sr, CK_ENV);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? 0 : 1;
}
