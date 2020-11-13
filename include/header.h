#ifndef header_h
#define header_h

#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
void nextm(int n, int k, vector<vector<int>>& a);
vector<int> nextv(int n, int k, vector<int> a);
vector<vector<int>> start_matrix(int n, int k);
vector<vector<int>> next_matrix(vector<vector<int>> matrix);
double determinant(vector<vector<int>> m, vector<vector<double>>& matrix);
double max_det(int& n, int& k, vector<vector<int>>& ans);
void print(vector<vector<int>>);
int C_n_k(int n, int k);
#endif