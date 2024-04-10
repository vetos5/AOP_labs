#include "Polynomial.h"

using namespace std;

int main() {
    int switcher;
    cout << " Enter 1 to evaluate the polynomial at x point\n Enter 2 to find derivative\n Enter 3 to add the two polynomials\n Enter 4 to multiply the two polynomials\n Enter 5 to multiply the polynomial by number\n";
    cin >> switcher;
    do {
        switch (switcher) {
        case 1: {
            int n;
            double x;
            cout << "Enter the power of the polynomial\n";
            cin >> n;
            Polynomial<int> p(n);
            p.readCoefficients();
            p.printPolynomial();
            cout << "Enter the x point\n";
            cin >> x;
            cout << "The result is " << p.evaluate(x) << endl;
            break;
        }
        case 2: {
            int n;
            cout << "Enter the power of the polynomial\n";
            cin >> n;
            Polynomial<int> p(n);
            p.readCoefficients();
            p.printPolynomial();
            p.findDerivative().printDerivative();
            break;
        }
        case 3: {
            int n1, n2;
            cout << "Enter the power of the polynomial 1\n";
            cin >> n1;
            Polynomial<int> p1(n1);
            p1.readCoefficients();
            p1.printPolynomial();

            cout << "Enter the power of the polynomial 2\n";
            cin >> n2;
            Polynomial<int> p2(n2);
            p2.readCoefficients();
            p2.printPolynomial();

            Polynomial<int> p3 = p1 + p2;
            p3.printPolynomial();
            break;
        }
        case 4: {
            int n1, n2;
            cout << "Enter the power of the polynomial 1\n";
            cin >> n1;
            Polynomial<int> p1(n1);
            p1.readCoefficients();
            p1.printPolynomial();

            cout << "Enter the power of the polynomial 2\n";
            cin >> n2;
            Polynomial<int> p2(n2);
            p2.readCoefficients();
            p2.printPolynomial();

            Polynomial<int> p3 = p1 * p2;
            p3.printMultiply();
            break;
        }
        case 5: {
            int n;
            cout << "Enter the power of the polynomial\n";
            cin >> n;
            Polynomial<int> p(n);
            p.readCoefficients();
            p.printPolynomial();
            int number;
            cout << "Enter the number\n";
            cin >> number;
            Polynomial<int> p1 = p * number;
            p1.printPolynomial();
            break;
        }
        default:
            cout << "Invalid input\n";
        }
        cout << "Enter another choice or '0' to exit\n";
        cin >> switcher;
    } while (switcher != 0);
    return 0;
}
