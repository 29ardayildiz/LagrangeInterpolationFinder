#include <iostream>
#include <vector>
#include <string>

using namespace std;

string LPolynomial(const vector<int>& x, const vector<int>& y) {
    int n = x.size();
    string polynomial = "P(x) = ";

    for (int i = 0; i < n; ++i) {
        int yi = y[i];
        if (i > 0) polynomial += " + ";
        polynomial += to_string(yi) + " * ";

        // L_i(x)
        string Ln = "";
        string Ld = "(";

        for (int j = 0; j < n; ++j) {
            if (j != i) {
                if (!Ln.empty()) Ln += " * ";
                if (Ld.length() > 1) Ld += " * ";

                Ln += "(x - " + to_string(x[j]) + ")";
                Ld += "(" + to_string(x[i]) + " - " + to_string(x[j]) + ")";
            }
        }
        Ld += ")";

        polynomial += "[" + Ln + "] / " + Ld;
    }

    return polynomial;
}

int main() {
    int n;
    cout << "Enter the number of data points: ";
    cin >> n;

    vector<int> x(n), y(n);
    cout << "Enter the x and y values :" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }

    string polynomial = LPolynomial(x, y);
    cout << polynomial << endl;

    return 0;
}
