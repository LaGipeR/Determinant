#include <bits/stdc++.h>
#include "matrix.h"

using namespace std;

enum class HELPER {
    NEW_USER,
    OLD_USER
} HELP(HELPER::NEW_USER);

void init() {
    DEBUG = DEBUG_ENUM::WITHOUT_DEBUG;
    HELP = HELPER::NEW_USER;



    if (HELP == HELPER::NEW_USER) {
        cout << "Hello, this program calculate determinant.\n";
    }
}

long long calcDeterminant(Matrix& matrix) {

    matrix.deb();

    if (matrix.get_sz() == 1) {
        if (DEBUG == DEBUG_ENUM::ALL_DEBUG) {
            cout << " determinant(size == 1) = " << matrix[0][0] << endl;
        }

        return matrix[0][0];
    }

    Matrix next_matrix(matrix.get_sz() - 1);
    for (size_t row = 1; row < matrix.get_sz(); ++row) {
        copy(matrix[row] + 1, matrix[row] + matrix.get_sz(), next_matrix[row - 1]);
    }

    long long determinant = 0, sign = 1;
    for (size_t row = 0; row < matrix.get_sz(); ++row) {
        if (matrix[row][0] != 0) {
            determinant += sign * matrix[row][0] * calcDeterminant(next_matrix);
        }

        if (row + 1 != matrix.get_sz()) {
            copy(matrix[row] + 1, matrix[row] + matrix.get_sz(), next_matrix[row]);
            sign *= -1ll;
        }
    }

    if (DEBUG == DEBUG_ENUM::ALL_DEBUG) {
        cout << " determinant = " << determinant << endl;
    }

    return determinant;
}

int main() {
    init();

    if (HELP == HELPER::NEW_USER) {
        cout << "\nInput size of matrix. n = ";
    }
    size_t n;
    cin >> n;


    if (HELP == HELPER::NEW_USER) {
        cout << "\nInput matrix row by row.\n"
                "Matrix must be square with size n.\n"
                "Matrix input:\n";
    }
    Matrix y(n);
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            cin >> y[i][j];
        }
    }

    if (HELP == HELPER::NEW_USER) {
        cout << "\nDeterminant = ";
    }

    cout << calcDeterminant(y) << endl;
}
