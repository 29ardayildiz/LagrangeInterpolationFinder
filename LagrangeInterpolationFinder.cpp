#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

string generateLagrangePolynomial(const vector<int>& x, const vector<int>& y) {
    int n = x.size();
    stringstream polynomial;

    polynomial << "P(x) = ";

    for (int i = 0; i < n; ++i) {
        double yi = y[i];
        if (i > 0) polynomial << " + ";
        polynomial << yi << " * ";

        // L_i(x)
        stringstream LiNumerator;
        stringstream LiDenominator;

        LiDenominator << "(";
        for (int j = 0; j < n; ++j) {
            if (j != i) {
                if (LiNumerator.str().length() > 0) LiNumerator << " * ";
                if (LiDenominator.str().length() > 1) LiDenominator << " * ";

                LiNumerator << "(x - " << x[j] << ")";
                LiDenominator << "(" << x[i] << " - " << x[j] << ")";
            }
        }
        LiDenominator << ")";

        polynomial << "[" << LiNumerator.str() << "] / " << LiDenominator.str();
    }

    return polynomial.str();
}

int main() {
    int n;
    cout << "Enter the number of data points: ";
    cin >> n;

    vector<int> x(n), y(n);
    cout << "Enter the x and y values for each point:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }

    string polynomial = generateLagrangePolynomial(x, y);
    cout << polynomial << endl;

    return 0;
}
