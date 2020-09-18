#include "../include/prog.h"
#include <cmath>
#include <cstdio>

char **init_arr(int n) {
  char **arr = new char *[n];
  for (int i = 0; i < n; i++) {
    arr[i] = new char[n];
  }
  return arr;
}

char *init_new_arr(int n) {
  char *new_arr = new char[n];
  return new_arr;
}

void fill_arr(char **arr, int n) {
  for (int row = 0; row < n; row++) {
    for (int col = 0; col < n; col++) {
      // arr[row][col] = char('0' + rand() % ('9' - '0'));
      arr[row][col] = char('a' + rand() % ('z' - 'a'));
      //для удобства можно вывести английский алфавит или цифры
    }
  }
}

void print_arr(char **arr, int n) {
  for (int row = 0; row < n; row++) {
    for (int col = 0; col < n; col++) {
      std::cout << arr[row][col] << " ";
    }
    std::cout << std::endl;
  }
}

void print_new_arr(char *new_arr, int n) {
  for (int i = 0; i < n * n; i++) {
    std::cout << new_arr[i] << " ";
  }
  std::cout << std::endl;
}

void diag_left(char **arr, char *new_arr, int n) {
  int count = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      new_arr[count] = arr[j][i - j];
      count++;
    }
  }
  for (int i = 1; i < n; i++) {
    for (int j = n; j > i; j--) {
      new_arr[count] = arr[n - j + i][j - 1];
      count++;
    }
  }
}

void diag_right(char **arr, char *new_arr, int n) {
  int count = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      new_arr[count] = arr[j][n - i + j - 1];
      count++;
    }
  }
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < n - i; j++) {
      new_arr[count] << arr[i + j][j];
      count++;
    }
  }
}

void spiral_out(char **arr, char *new_arr, int n) {
  int row = n / 2;
  int col = (n - 1) / 2;
  int count = 0;
  int c = 0;
  while (true) {
    for (int i = 0; i < count; i++) {
      new_arr[c++] = arr[row][col--];
    }
    if (count == n)
      break;
    for (int i = 0; i < count; i++) {
      new_arr[c++] = arr[row++][col];
    }
    count++;
    for (int i = 0; i < count; i++) {
      new_arr[c++] = arr[row][col++];
    }
    for (int i = 0; i < count; i++) {
      new_arr[c++] = arr[row--][col];
    }
    count++;
  }
}

void spiral_in(char **arr, char *new_arr, int n) {
  int col = 0;
  int row = 0;
  int count = n;
  int c = 0;
  for (int i = 0; i < count - 1; i++) {
    new_arr[c++] = arr[row][col++];
  }
  while (count != 0) {
    count--;
    for (int i = 0; i < count; i++) {
      new_arr[c++] = arr[row++][col];
    }
    for (int i = 0; i < count; i++) {
      new_arr[c++] = arr[row][col--];
    }
    for (int i = 0; i < count - 1; i++) {
      new_arr[c++] = arr[row--][col];
    }
    count--;
    for (int i = 0; i < count; i++) {
      new_arr[c++] = arr[row][col++];
    }
  }
}