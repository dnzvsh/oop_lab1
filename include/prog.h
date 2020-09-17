#ifndef HEADER_H
#define HEADER_H

#include <cstdio>
#include <iostream>

char **init_arr(int n);

char *init_new_arr(int n);

void fill_arr(char **arr, int n);

void print_arr(char **arr, int n);

void print_new_arr(char *new_arr, int n);

void diag_right(char **arr, char *new_arr, int n);

void diag_left(char **arr, char *new_arr, int n);

void spiral_out(char **arr, char *new_arr, int n);

void spiral_in(char **arr, char *new_arr, int n);

#endif