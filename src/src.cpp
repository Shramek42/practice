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
vector<int> backv(int n, int k) {
    vector<int> a(n, 0);
    for(int i = n - 1; i >= n - k; i--) {
        a[i] = 1;
    }
    return a;
}
vector<int> int_to_v(int n, int a) {
    vector<int> col(n, 0);
    int p = 1;
    int count = 0;
    while(count < n) {
        if(a & p) col[count] = 1;
        count++;
        p <<= 1;
    }
    return col;
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
double determinant(vector<vector<int>> m) {
    const double EPS = 1E-9;
    int n = size(m);
    vector<vector<double>> matrix(n, vector<double>(n));
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
    vector<vector<int>> matrix(n, vector<int>(n));
    matrix = start_matrix(n, k);
    int c = C_n_k(C_n_k(n,k), n);
    double max_d = determinant(matrix);
    ans = matrix;
    for(int i = 1; i < c; i++) {
        if (abs(determinant(matrix)) > max_d) {
            max_d = abs(determinant(matrix));
            ans = matrix;
        }       
        nextm(n, k, matrix);
    }
    if (abs(determinant(matrix)) > max_d) {
        max_d = abs(determinant(matrix));
        ans = matrix;
    }
    return max_d;
}