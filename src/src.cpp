#include "header.h"


vector<int> nextv(int n, int k, vector<int> a) {
    int count = 0;
    int i = 0;
    vector<int> ans = a;
    vector<int> temp = a;
    do {
        if(ans[i]) count++;
        i++;
    } while(count != k);
    i--;
    count = 0;
    if((i == size(a) - 1) && ans[i] == 1) {
        while(ans[i]) {
            count++;
            ans[i] = 0;
            i--;
        }
        while (!(a[i]) && i != 0) {
            i--;
        }
        if (i == 0 && a[i] == 0) {
            ans[0] = -1;
            return ans;
        }
        ans[i] = 0;
        for(int j = 0; j <= count; j++) {
            i++;
            ans[i] = 1;
        }
        if(ans == temp) {
            ans[0] = -1;
            return ans;
        }
    } else {
        ans[i] = 0;
        i++;
        ans[i] = 1;
    }
    return ans;
}
vector<vector<int>> start_matrix(int n, int k) {
    vector<vector<int>> matrix(n, vector<int>(n));
    for(int i = 0; i < k; i++) {
        matrix[0][i] = 1;
    }
    for(int i = 1; i < n; i++) {
        matrix[i] = nextv(n, k, matrix[i - 1]);
    }
    return matrix;
}
void nextm(int n, int k, vector<vector<int>>& a) {
    vector<int> b = a[n - 1];
    b = nextv(size(a), k, a[n - 1]);
    if(b[0] == -1) {
        nextm(n - 1, k, a);
        a[n - 1] = nextv(size(a), k, a[n - 2]);
        return;
    }
    if(n <= size(a) - 1 && b == a[n]){
        nextm(n - 1, k, a);
        a[n - 1] = nextv(size(a), k, a[n - 2]);
        return;
    }
    a[n - 1] = nextv(size(a), k, a[n - 1]);
    return;
}
double determinant(vector<vector<int>> m, vector<vector<double>>& matrix) {
    const double EPS = 1E-9;
    int n = size(m);
    for (int i = 0; i < size(m); i++) {
        for (int j = 0; j < size(m); j++) {
            matrix[i][j] = (double)m[i][j];
        }
    }
    double det = 1;
    for (int i = 0; i < n; i++) {
        int k = i;
        for (int j = i + 1; j < n; j++)
            if (abs(matrix[j][i]) > abs (matrix[k][i])) {
                k = j;
            }
        if (abs (matrix[k][i]) < EPS) {
            det = 0;
            break;
        }
        swap(matrix[i], matrix[k]);
        if (i != k) {
            det = -det;
        }
        det *= matrix[i][i];
        for(int j = i + 1; j < n; j++)
            matrix[i][j] /= matrix[i][i];
        for (int j = 0; j < n; j++) {
            if(j != i && abs(matrix[j][i]) > EPS) {
                for (int k = i + 1; k < n; k++)
                    matrix[j][k] -= matrix[i][k] * matrix[j][i];
            }
        } 
           
    }
    return det;
}
int C_n_k(int n, int k) {
    if(n == k)
        return 1;
    if(k == 1)
        return n;
    return C_n_k(n-1, k-1) + C_n_k(n-1, k);
}
void print(vector<vector<int>> a) {
    for (int i = 0; i < size(a); i++) {
        for (int j = 0; j < size(a); j++) {
            cout << a[j][i] << " ";
        }
        cout << endl;
        
    }
}
double max_det(int& n, int& k, vector<vector<int>>& ans) {
    if (n == k) {
        return 1;
    }
    vector<vector<int>> matrix(n, vector<int>(n));
    vector<vector<double>> m(n, vector<double>(n));
    matrix = start_matrix(n, k);
    int c = C_n_k(C_n_k(n,k), n);
    double det_cur;
    double max_d = determinant(matrix, m);
    ans = matrix;
    for(int i = 1; i < c; i++) {
        det_cur = abs(determinant(matrix, m));
        if (det_cur > max_d) {
            max_d = det_cur;
            ans = matrix;
        }       
        nextm(n, k, matrix);
    }
    det_cur = abs(determinant(matrix, m));
    if (det_cur > max_d) {
        max_d = det_cur;
        ans = matrix;
    }
    return max_d;
}