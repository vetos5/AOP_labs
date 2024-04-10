#include <iostream>
#include <list>
#include <cmath>

using namespace std;
void print_() {
    for (int i = 0; i < 120; i++) {
        cout << "_";
    }
    cout << endl;
}
template<typename T>
class Polynomial {
private:
    list<T> coefficients;

public:

    Polynomial(int n) {
        coefficients.resize(n + 1, 0);
    }

    void readCoefficients() {
        int i = 0;
        for (auto& coeff : coefficients) {
            cout << "Input a" << i++ << ": ";
            cin >> coeff;
        }
    }

    T evaluate(T x) const {
        T result = 0;
        int n = coefficients.size() - 1;
        for (auto it = coefficients.begin(); it != coefficients.end(); ++it) {
            result += *it * pow(x, n--);
        }
        return result;
    }

    

    void printPolynomial() const {

		cout << "The polynomial is: ";
        int n = coefficients.size() - 1;
        bool first = true;
        for (auto it = coefficients.begin(); it != coefficients.end(); ++it) {
            if (*it != 0) {
                if (!first) {
                    cout << " + ";
                }
                if (n > 1) {
                    cout << *it << "*x^" << n--;
                }
                else if (n == 1) {
                    cout << *it << "*x";
                    --n;
                }
                else {
                    cout << *it;
                }
                first = false;
            }
            else {
                --n;
            }
        }
        cout << endl;
        print_();
    }

    

    Polynomial<T> operator*(T scalar) const {
        int n = coefficients.size() - 1;
        Polynomial<T> result(n);

        auto itResult = result.coefficients.begin();
        for (auto it = coefficients.begin(); it != coefficients.end(); ++it, ++itResult) {
            *itResult = *it * scalar;
        }

        return result;
    }

    Polynomial<T> operator*(const Polynomial<T>& p) const {
        int n1 = coefficients.size();
        int n2 = p.coefficients.size();
        Polynomial<T> result(n1 + n2);

        auto it1 = coefficients.begin();
        auto it2 = p.coefficients.begin();
        auto itRes = result.coefficients.begin();

        for (int i = 0; i < n1; ++i) {
            it2 = p.coefficients.begin();
            for (int j = 0; j < n2; ++j) {
                auto index = distance(result.coefficients.begin(), itRes) + i + j;
                *(next(itRes, index)) += *it1 * *it2;
                ++it2;
            }
            ++it1;
        }
        return result;
    }


    Polynomial<T> operator+(const Polynomial<T>& other) const {
        int n = max(coefficients.size(), other.coefficients.size()) - 1;
        Polynomial<T> result(n);

        auto it1 = coefficients.rbegin();
        auto it2 = other.coefficients.rbegin();
        auto itRes = result.coefficients.rbegin();

        while (it1 != coefficients.rend() && it2 != other.coefficients.rend()) {
            *itRes = *it1 + *it2;
            ++it1;
            ++it2;
            ++itRes;
        }

        while (it1 != coefficients.rend()) {
            *itRes = *it1;
            ++it1;
            ++itRes;
        }

        while (it2 != other.coefficients.rend()) {
            *itRes = *it2;
            ++it2;
            ++itRes;
        }

        return result;
    }

    void printMultiply() const {
        cout << "The result of the multiplication is: ";
        int n = coefficients.size() - 3;
        bool first = true;
        for (auto it = coefficients.begin(); it != coefficients.end(); ++it) {
            if (*it != 0) {
                if (!first) {
                    cout << " + ";
                }
                if (n > 1) {
                    cout << *it << "*x^" << n--;
                }
                else if (n == 1) {
                    cout << *it << "*x";
                    --n;
                }
                else {
                    cout << *it;
                }
                first = false;
            }
            else {
                --n;
            }
        }
        cout << endl;
        print_();
    }


    Polynomial<T> findDerivative() const {
        Polynomial<T> derivative(coefficients.size() - 1);

        int power = coefficients.size() - 1;
        auto it = coefficients.begin();
        auto itRes = derivative.coefficients.begin();

        while (it != coefficients.end() and itRes != derivative.coefficients.end()) {
            *itRes = *it * power--;
            ++it;
            ++itRes;
        }

        return derivative;
    }


    void printDerivative() const {
        cout << "The derivative is: ";
        int n = coefficients.size() - 2;
        bool first = true;
        for (auto it = coefficients.begin(); it != coefficients.end(); ++it) {
            if (*it != 0) {
                if (!first) {
                    cout << " + ";
                }
                if (n > 1) {
                    cout << *it << "*x^" << n--;
                }
                else if (n == 1) {
                    cout << *it << "*x";
                    --n;
                }
                else {
                    cout << *it;
                }
                first = false;
            }
            else {
                --n;
            }
        }
        cout << endl;
        print_();
    }
};