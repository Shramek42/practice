#include "../include/header.h"

int main() {
    int n, k;
    double det;
    int t = 1;
    vector<vector<int>> ans;
    while (t == 1) {
        cout << "Enter n" << endl;
        cin >> n;
        cout << "Enter k" << endl;
        cin >> k;
        cout << endl;
        if (n == k) {
            det = 1;
        }
        else {
            det = max_det(n, k, ans); 
            print(ans);
        }
        cout << endl;
        cout << determinant(ans) << endl;
        cout << "Det = " << abs(det) << endl;
        cout << endl;
    }
}