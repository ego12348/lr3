#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>

// Прототипи власних функцій
double f(double x);
double df(double x);
void printHeader(const char* title);
void printTableRow(int n, double x, double val);

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    double x1, x2, delta, current_x;
    unsigned int n_points, i, choice;

    printf("--- Лабораторна робота №3 (Частина 1) ---\n");
    printf("Дослідження функції: f(x) = 2x^3 - 0.2x^2 + 0.5x + 3\n\n");

    printf("Оберіть варіант введення даних:\n");
    printf("1. Початкове x, Кінцеве x, Кількість точок (N)\n");
    printf("2. Початкове x, Кінцеве x, Крок (delta)\n");
    printf("Ваш вибір: ");
    scanf("%u", &choice);

    if (choice == 1) {
        printf("Введіть X1, X2 та N: ");
        scanf("%lf %lf %u", &x1, &x2, &n_points);
        if (n_points <= 1) { printf("N повинно бути > 1\n"); return 1; }
        delta = (x2 - x1) / (n_points - 1);
    } else if (choice == 2) {
        printf("Введіть X1, X2 та delta: ");
        scanf("%lf %lf %lf", &x1, &x2, &delta);
        n_points = (unsigned int)((x2 - x1) / delta) + 1;
    } else {
        printf("Невірний вибір!\n");
        return 1;
    }

    // Виведення таблиці значень функції
    printHeader("Таблиця значень функції f(x)");
    for (i = 0; i < n_points; i++) {
        current_x = x1 + i * delta;
        printTableRow(i + 1, current_x, f(current_x));
    }
    printf("--------------------------------------------\n\n");

    // Виведення таблиці значень похідної
    printHeader("Таблиця значень похідної f'(x)");
    for (i = 0; i < n_points; i++) {
        current_x = x1 + i * delta;
        printTableRow(i + 1, current_x, df(current_x));
    }
    printf("--------------------------------------------\n");

    return 0;
}

// Функція f(x)
double f(double x) {
    return 2 * pow(x, 3) - 0.2 * pow(x, 2) + 0.5 * x + 3;
}

// Похідна f'(x)
double df(double x) {
    return 6 * pow(x, 2) - 0.4 * x + 0.5;
}

// Допоміжні функції для псевдографіки
void printHeader(const char* title) {
    printf("\n%s\n", title);
    printf("--------------------------------------------\n");
    printf("|  №  |      x      |       Значення      |\n");
    printf("--------------------------------------------\n");
}

void printTableRow(int n, double x, double val) {
    printf("| %3d | %11.4f | %17.4f |\n", n, x, val);
}
