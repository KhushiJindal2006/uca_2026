#include <iostream>
#include <vector>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {

    int m = matrix.size();
    int n = matrix[0].size();

    bool firstRowZero = false;
    bool firstColZero = false;

   
    for (int j = 0; j < n; j++) {
        if (matrix[0][j] == 0) {
            firstRowZero = true;
            break;
        }
    }

 
    for (int i = 0; i < m; i++) {
        if (matrix[i][0] == 0) {
            firstColZero = true;
            break;
        }
    }


    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {

            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for (int i = 1; i < m; i++) {
        if (matrix[i][0] == 0) {

            for (int j = 1; j < n; j++) {
                matrix[i][j] = 0;
            }
        }
    }

 
    for (int j = 1; j < n; j++) {
        if (matrix[0][j] == 0) {

            for (int i = 1; i < m; i++) {
                matrix[i][j] = 0;
            }
        }
    }

    if (firstRowZero) {
        for (int j = 0; j < n; j++) {
            matrix[0][j] = 0;
        }
    }

    if (firstColZero) {
        for (int i = 0; i < m; i++) {
            matrix[i][0] = 0;
        }
    }
}

int main() {

    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };

    setZeroes(matrix);

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
