#include "Horner.h"

using namespace std;


int main() {
    int n;
    cout << "Input max power: ";
    cin >> n;

    vector<int> coefficients(n + 1);

    cout << "Input coeffs: " << endl;
    for (int i = n; i >= 0; --i) {
        cout << "Coeff of x^" << i << ": ";
        cin >> coefficients[i];
    }

    int x;
    cout << "Input x: ";
    cin >> x;

    cout << "Polinomial value at x: " << hornerScheme<int>(coefficients, x) << endl;

    printHornerTable(coefficients, x);

    return 0;
}
