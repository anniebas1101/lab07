#pragma once

#include <iostream>
#include <stdexcept>
#include <cmath>

using namespace std;

// === Структура для хранения коэффициентов ===
struct QuadraticCoeffs {
    double a, b, c;
    QuadraticCoeffs(double pa, double pb, double pc) : a(pa), b(pb), c(pc) {}
};

// === 1. Пустой класс исключения ===
class EmptyException {};

// === 2. Класс исключения с полями ===
class QuadraticException {
    double a, b, c;
public:
    string message;
    QuadraticException(double pa, double pb, double pc, const string& msg)
        : a(pa), b(pb), c(pc), message(msg) {}
};

// === 3. Класс исключения — наследник standard_exception ===
class QuadraticStdException : public invalid_argument {
    double a, b, c;
public:
    QuadraticStdException(double pa, double pb, double pc, const string& msg)
        : invalid_argument(msg), a(pa), b(pb), c(pc) {}
};
