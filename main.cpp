#include "QuadraticEquation.h"

int main() {
    setlocale(LC_ALL, "Russian");

    // Пример с ошибкой: a == 0
    QuadraticCoeffs coeffs(0, 2, 3);

    cout << "=== Вариант 1: без спецификации ===" << endl;
    try {
        double res = solveQuadraticNoSpec(coeffs);
        cout << "Корень: " << res << endl;
    }
    catch (int e) {
        cout << "Ошибка (код " << e << ")" << endl;
    }

    cout << "\n=== Вариант 2: throw() ===" << endl;
    double res2 = solveQuadraticThrow(coeffs);
    if (res2 == 0)
        cout << "Ошибка (возврат 0)" << endl;
    else
        cout << "Корень: " << res2 << endl;

    cout << "\n=== Вариант 3: стандартное исключение ===" << endl;
    try {
        double res3 = solveQuadraticStdExcept(coeffs);
        cout << "Корень: " << res3 << endl;
    }
    catch (const invalid_argument& e) {
        cout << "Стандартное исключение: " << e.what() << endl;
    }

    cout << "\n=== Вариант 4.1: пустой класс ===" << endl;
    try {
        double res4 = solveQuadraticEmptyExcept(coeffs);
        cout << "Корень: " << res4 << endl;
    }
    catch (EmptyException) {
        cout << "Пустое исключение" << endl;
    }

    cout << "\n=== Вариант 4.2: класс с полями ===" << endl;
    try {
        double res5 = solveQuadraticFieldExcept(coeffs);
        cout << "Корень: " << res5 << endl;
    }
    catch (const QuadraticException& e) {
        cout << "Исключение: " << e.message << endl;
    }

    cout << "\n=== Вариант 4.3: наследник std::exception ===" << endl;
    try {
        double res6 = solveQuadraticStdInherit(coeffs);
        cout << "Корень: " << res6 << endl;
    }
    catch (const QuadraticStdException& e) {
        cout << "Стандартное исключение (what): " << e.what() << endl;
    }

    int a;
    cin >> a;
    return 0;
}
