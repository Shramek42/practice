#include "../include/header.h"

int main() {
    int n, k;
    double det;
    int t = 1;
    double k1, n1;
    cin >> n;
    vector<vector<int>> ans;      
    vector<vector<double>> det_(8, vector<double>(8));
    vector<vector<double>> delta(8, vector<double>(8, 1));
    vector<vector<double>> matrix(n, vector<double>(n));
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= i; j++)
            det_[j][i] = max_det(i, j, ans);
    for (int i = 1; i <= n; i++)
        det_[i][i] = 1;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            for (int c = 1; c <= i; c++)
                delta[j][i] *= sqrt(j);
    cout << "Definition table" << endl;
    cout << endl;
    cout << " n ";
    for (int i = 1; i <= n; i++) {
        cout << i << "  ";
    }
    cout << endl;
    cout << "k" << endl;
    for (int i = 1; i <= n; i++) {
        cout << i << "  ";
        for (int j = 1; j <= n; j++)
            if (i > j) cout << "-  ";
            else cout << det_[i][j] <<"  ";
        cout << endl;
    }
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "Estimation table" << endl;
    cout << endl;
    cout << " n ";
    for (int i = 1; i <= n; i++) {
        cout << i << "  ";
    }
    cout << endl;
    cout << "k" << endl;
    for (int i = 1; i <= n; i++) {
        cout << i << "  ";
        for (int j = 1; j <= n; j++)
            if (i > j) cout << "-  ";
            else cout << delta[i][j] << "  ";
        cout << endl;
    }


}