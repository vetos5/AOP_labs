#pragma once
#include <iostream>
#include <vector>


using namespace std;

template <typename T>
T hornerScheme(const vector<T> coefficients, T x) {
    int n = coefficients.size() - 1;
    double result = coefficients[n];

    for (int i = n - 1; i >= 0; --i) {
        result = result * x + coefficients[i];
    }

    return result;
}

template <typename T>
void printHornerTable(const vector<T>& coefficients, T x) {
    int n = coefficients.size() - 1;
    vector<T> powers;
    vector<T> values;

    T x_power = 1.0;
    for (int i = 0; i <= n; ++i) {
        powers.push_back(x_power);
        values.push_back(coefficients[i] * x_power);
        x_power *= x;
    }

    cout << "Step | x Power | Term Value | Cumulative Value " << endl;
    cout << "------------------------------------------------------" << endl;


    T sum = 0;
    for (int i = 0; i <= n; ++i) {
        cout <<"\t" << i + 1 << "\t|\t" << powers[i] << "\t|\t" << values[i] << "\t|\t";
        sum += values[i];
        cout << sum << endl;
    }

}