#include "../include/prog.h"
#include <cstdio>
#include <iostream>

int main() {
  using namespace std;
  cout << "1) Создать двумерный массив 200х200 и вывести его определенным "
          "образом"
       << endl;
  cout << "2) Создать двумерный массив с произвольным количеством элементов и "
          "вывести его на экран"
       << endl;
  char a;
  cin >> a;
  if (a == '1') {
    int n = 200;
    char **arr = init_arr(n);
    fill_arr(arr, n);
    char *new_arr = init_new_arr(n * n);
    cout << "1) По правым диагоналям, начиная с правого верхнего элемента"
         << endl;
    cout << "2) По левым диагоналям, начиная с левого верхнего элемента"
         << endl;
    cout << "3) По спирали, начиная с центрального элемента" << endl;
    cout << "4) По спирали, начиная с левого верхнего элемента" << endl;
    char c;
    cout << "Выберете вариант" << endl;
    cin >> c;
    if (c == '1') {
      diag_right(arr, new_arr, n);
    } else if (c == '2') {
      diag_left(arr, new_arr, n);
    } else if (c == '3') {
      spiral_out(arr, new_arr, n);
    } else if (c == '4') {
      spiral_in(arr, new_arr, n);
    } else {
      cout << "Выберите один из представленных выше вариантов" << endl;
    }
  } else if (a == '2') {
    int n;
    cout << "Введите размерность матрицы" << endl;
    cin >> n;
    char **arr = init_arr(n);
    fill_arr(arr, n);
    print_arr(arr, n);
  } else {
    cout << "Выберите один из представленных выше вариантов" << endl;
  }
  return 0;
}