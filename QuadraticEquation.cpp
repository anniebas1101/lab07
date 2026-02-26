#include "QuadraticEquation.h"

// === Вариант 1: без спецификации исключений ===
double solveQuadraticNoSpec(const QuadraticCoeffs& coeffs) {
    double a = coeffs.a, b = coeffs.b, c = coeffs.c;

    if (a == 0) throw 1; // не квадратное уравнение
    if (isnan(a) || isnan(b) || isnan(c)) throw 2;

    double d = b * b - 4 * a * c;
    if (d < 0) throw 3;

    return (-b + sqrt(d)) / (2 * a); // возвращаем один корень для демонстрации
}

// === Вариант 2: спецификация throw() ===
double solveQuadraticThrow(const QuadraticCoeffs& coeffs) throw() {
    double a = coeffs.a, b = coeffs.b, c = coeffs.c;

    if (a == 0 || isnan(a) || isnan(b) || isnan(c) || (b*b - 4*a*c < 0))
        return 0; // нет исключений — возвращаем 0 как признак ошибки

    double d = b * b - 4 * a * c;
    return (-b + sqrt(d)) / (2 * a);
}

// === Вариант 3: стандартное исключение ===
double solveQuadraticStdExcept(const QuadraticCoeffs& coeffs) throw(invalid_argument) {
    double a = coeffs.a, b = coeffs.b, c = coeffs.c;

    if (a == 0) throw invalid_argument("a == 0: не квадратное уравнение");
    if (isnan(a) || isnan(b) || isnan(c)) throw invalid_argument("NaN аргумент");

    double d = b * b - 4 * a * c;
    if (d < 0) throw invalid_argument("Отрицательный дискриминант");

    return (-b + sqrt(d)) / (2 * a);
}

// === Вариант 4.1: пустой класс ===
double solveQuadraticEmptyExcept(const QuadraticCoeffs& coeffs) throw(EmptyException) {
    double a = coeffs.a, b = coeffs.b, c = coeffs.c;

    if (a == 0 || isnan(a) || isnan(b) || isnan(c) || (b*b - 4*a*c < 0))
        throw EmptyException();

    double d = b * b - 4 * a * c;
    return (-b + sqrt(d)) / (2 * a);
}

// === Вариант 4.2: класс с полями ===
double solveQuadraticFieldExcept(const QuadraticCoeffs& coeffs) throw(QuadraticException) {
    double a = coeffs.a, b = coeffs.b, c = coeffs.c;

    if (a == 0) throw QuadraticException(a, b, c, "a == 0");
    if (isnan(a) || isnan(b) || isnan(c)) throw QuadraticException(a, b, c, "NaN argument");

    double d = b * b - 4 * a * c;
    if (d < 0) throw QuadraticException(a, b, c, "d < 0");

    return (-b + sqrt(d)) / (2 * a);
}

// === Вариант 4.3: наследник стандартного исключения ===
double solveQuadraticStdInherit(const QuadraticCoeffs& coeffs) throw(QuadraticStdException) {
    double a = coeffs.a, b = coeffs.b, c = coeffs.c;

    if (a == 0) throw QuadraticStdException(a, b, c, "a == 0");
    if (isnan(a) || isnan(b) || isnan(c)) throw QuadraticStdException(a, b, c, "NaN argument");

    double d = b * b - 4 * a * c;
    if (d < 0) throw QuadraticStdException(a, b, c, "d < 0");

    return (-b + sqrt(d)) / (2 * a);
}
