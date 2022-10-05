#include "calc.h"

int check_inp_string(char *inp_str, int *x_count) {
  int error = 0, str_len = strlen(inp_str), count_x = 0;
  int open = 0, close = 0;
  for (int i = 0; i < str_len; i++) {
    if (inp_str[i] == 'x') {
      count_x++;
    }
    if (inp_str[i] == '(') {
      open++;
    }
    if (inp_str[i] == ')') {
      close++;
    }
  }
  *x_count = count_x;
  if (str_len > 255 || open != close || check_char(inp_str) == 1) {
    error = 1;
  }
  return error;
}

int check_char(char *inp_str) {
  int error = 0;
  int str_len = strlen(inp_str);
  const char correct_char[32] = {40,  41,  42,  43,  45,  46,  47,  48,
                                 49,  50,  51,  52,  53,  54,  55,  56,
                                 57,  94,  97,  99,  100, 103, 105, 108,
                                 109, 110, 111, 113, 114, 115, 116, 120};
  for (int i = 0; i < str_len; i++) {
    int n_eq = 1;
    for (int j = 0; j < 32; j++) {
      if (inp_str[i] == correct_char[j]) {
        n_eq = 0;
      } else if (i == 0 && inp_str[i] == ')') {
        error = 1;
      }
    }
    if (n_eq == 1 && error == 0) {
      error = 1;
    }
  }
  return error;
}

int rebuild_string(char *inp_str, char *new_str) {
  int error = 0;
  char str_buf1[255];
  memset(str_buf1, 0, sizeof(str_buf1));
  char str_buf2[255];
  memset(str_buf2, 0, sizeof(str_buf2));
  error = rebuild_for_mod(inp_str, str_buf1);
  if (error == 0) {
    error = rebuild_for_functions(str_buf1, str_buf2);
    memset(str_buf1, 0, sizeof(str_buf1));
  }
  if (error == 0) {
    error = rebuild_for_sign(str_buf2, str_buf1);
    memset(str_buf2, 0, sizeof(str_buf2));
    set_unary_operation(str_buf1, str_buf2);
    memset(str_buf1, 0, sizeof(str_buf1));
  }
  if (error == 0) {
    error = rebuild_for_mdp(str_buf2, new_str);
    memset(str_buf2, 0, sizeof(str_buf2));
  }
  return error;
}

int rebuild_for_mod(char *inp_str, char *new_str) {
  int i = 0, n = 0, error = 0;
  for (; i < (int)strlen(inp_str) && error == 0;) {
    if (inp_str[i] == 'm') {
      if (inp_str[i + 1] == 'o' && inp_str[i + 2] == 'd' && i != 0 &&
          inp_str[i + 3] != '*' && inp_str[i + 3] != '/' &&
          inp_str[i + 3] != 'm' && inp_str[i + 3] != '^' &&
          inp_str[i + 3] != ')' && inp_str[i + 3] != '\0' &&
          (inp_str[i - 1] == ')' ||
           ((inp_str[i - 1] >= '0' && inp_str[i - 1] <= '9') ||
            inp_str[i - 1] == 'x'))) {
        i = i + 3;
        new_str[n] = 'm';
        n++;
      } else {
        error = 2;
      }
    } else {
      new_str[n] = inp_str[i];
      i = i + 1;
      n++;
    }
  }
  return error;
}

int rebuild_for_sign(char *inp_str, char *new_str) {
  int i = 0, n = 0, error = 0;
  for (; i < (int)strlen(inp_str) && error == 0;) {
    if (inp_str[i] == '-' || inp_str[i] == '+') {
      if (inp_str[i + 1] == '-' || inp_str[i + 1] == '+') {
        int rez = inp_str[i] == '-' ? -1 : 1, count_inp_str = i + 1;
        while (inp_str[count_inp_str] == '-' || inp_str[count_inp_str] == '+') {
          if (inp_str[count_inp_str] == '-') {
            rez *= -1;
          }
          count_inp_str++;
        }
        new_str[n] = rez > 0 ? '+' : '-';
        i = count_inp_str;
        n++;
      } else if (inp_str[i + 1] == '*' || inp_str[i + 1] == '/' ||
                 inp_str[i + 1] == 'm' || inp_str[i + 1] == '^' ||
                 inp_str[i + 1] == '\0' || inp_str[i + 1] == ')') {
        error = 2;
      } else {
        new_str[n] = inp_str[i];
        i = i + 1;
        n++;
      }
    } else {
      new_str[n] = inp_str[i];
      i = i + 1;
      n++;
    }
  }
  return error;
}

void set_unary_operation(char *inp_str, char *new_str) {
  int i = 0, n = 0;
  for (; i < (int)strlen(inp_str);) {
    if (inp_str[i] == '-' || inp_str[i] == '+') {
      if (i == 0) {
        new_str[n] = inp_str[i] == '-' ? 'u' : 'p';
        i = i + 1;
        n++;
      } else if (inp_str[i - 1] == '(' || inp_str[i - 1] == '*' ||
                 inp_str[i - 1] == '/' || inp_str[i - 1] == 'm' ||
                 inp_str[i - 1] == '^' || inp_str[i - 1] == 's' ||
                 inp_str[i - 1] == 'c' || inp_str[i - 1] == 't' ||
                 inp_str[i - 1] == 'n' || inp_str[i - 1] == 'q' ||
                 inp_str[i - 1] == 'l' || inp_str[i - 1] == 'i' ||
                 inp_str[i - 1] == 'o' || inp_str[i - 1] == 'g') {
        new_str[n] = inp_str[i] == '-' ? 'u' : 'p';
        i = i + 1;
        n++;
      } else {
        new_str[n] = inp_str[i];
        i = i + 1;
        n++;
      }
    } else {
      new_str[n] = inp_str[i];
      i = i + 1;
      n++;
    }
  }
}

int rebuild_for_mdp(char *inp_str, char *new_str) {
  int error = 0, i = 0, n = 0;
  for (; i < (int)strlen(inp_str) && error == 0;) {
    if (inp_str[i] == '*' || inp_str[i] == '/' || inp_str[i] == '^') {
      if (i == 0 || inp_str[i + 1] == '-' || inp_str[i + 1] == '+' ||
          inp_str[i + 1] == '*' || inp_str[i + 1] == '/' ||
          inp_str[i + 1] == 'm' || inp_str[i + 1] == '^' ||
          inp_str[i + 1] == ')' || inp_str[i + 1] == '\0' ||
          (inp_str[i - 1] != ')' &&
           (inp_str[i - 1] <= '0' && inp_str[i - 1] >= '9'))) {
        error = 2;
      } else {
        new_str[n] = inp_str[i];
        i = i + 1;
        n++;
      }
    } else {
      new_str[n] = inp_str[i];
      i = i + 1;
      n++;
    }
  }
  return error;
}

int rebuild_for_functions(char *inp_str, char *new_str) {
  int error = 0, i = 0, n = 0;
  for (; i < (int)strlen(inp_str) && error == 0;) {
    if (inp_str[i] == 's' || inp_str[i] == 'c' || inp_str[i] == 't' ||
        inp_str[i] == 'a' || inp_str[i] == 'l') {
      if (inp_str[i + 1] == 'i' && inp_str[i + 2] == 'n' &&
          check_to_functions(inp_str, i + 3, i - 1) == 0) {
        i = i + 3;
        new_str[n] = 's';
        n++;
      } else if (inp_str[i + 1] == 'o' && inp_str[i + 2] == 's' &&
                 check_to_functions(inp_str, i + 3, i - 1) == 0) {
        i = i + 3;
        new_str[n] = 'c';
        n++;
      } else if (inp_str[i + 1] == 'a' && inp_str[i + 2] == 'n' &&
                 check_to_functions(inp_str, i + 3, i - 1) == 0) {
        i = i + 3;
        new_str[n] = 't';
        n++;
      } else if (inp_str[i + 1] == 't' && inp_str[i + 2] == 'a' &&
                 inp_str[i + 3] == 'n' &&
                 check_to_functions(inp_str, i + 4, i - 1) == 0) {
        i = i + 4;
        new_str[n] = 'n';
        n++;
      } else if (inp_str[i + 1] == 's' && inp_str[i + 2] == 'i' &&
                 inp_str[i + 3] == 'n' &&
                 check_to_functions(inp_str, i + 4, i - 1) == 0) {
        i = i + 4;
        new_str[n] = 'i';
        n++;
      } else if (inp_str[i + 1] == 'c' && inp_str[i + 2] == 'o' &&
                 inp_str[i + 3] == 's' &&
                 check_to_functions(inp_str, i + 4, i - 1) == 0) {
        i = i + 4;
        new_str[n] = 'o';
        n++;
      } else if (inp_str[i + 1] == 'q' && inp_str[i + 2] == 'r' &&
                 inp_str[i + 3] == 't' &&
                 check_to_functions(inp_str, i + 4, i - 1) == 0) {
        i = i + 4;
        new_str[n] = 'q';
        n++;
      } else if (inp_str[i + 1] == 'o' && inp_str[i + 2] == 'g' &&
                 check_to_functions(inp_str, i + 3, i - 1) == 0) {
        i = i + 3;
        new_str[n] = 'g';
        n++;
      } else if (inp_str[i + 1] == 'n' &&
                 check_to_functions(inp_str, i + 2, i - 1) == 0) {
        i = i + 2;
        new_str[n] = 'l';
        n++;
      } else {
        error = 2;
      }
    } else {
      new_str[n] = inp_str[i];
      i = i + 1;
      n++;
    }
  }
  return error;
}

int check_to_functions(const char *inp_str, int i_plus, int i_minus) {
  int error = 0;
  if (inp_str[i_plus] == '*' || inp_str[i_plus] == '/' ||
      inp_str[i_plus] == 'm' || inp_str[i_plus] == '^' ||
      inp_str[i_plus] == ')' || inp_str[i_plus] == '\0' ||
      (i_minus >= 0 && inp_str[i_minus] == ')') ||
      (i_minus >= 0 && (inp_str[i_minus] >= '0' && inp_str[i_minus] <= '9'))) {
    error = 2;
  }
  return error;
}
