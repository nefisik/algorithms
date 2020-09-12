#include <iostream>

int fibonacci(int number)
{
    if (number == 0)
        return 0; // базовый случай (условие завершения)
    if (number == 1)
        return 1; // базовый случай (условие завершения)
    return fibonacci(number-1) + fibonacci(number-2);
}

// Выводим первые 13 чисел Фибоначчи
int main()
{
    for (int count=0; count < 13; ++count)
        std:: cout << fibonacci(count) << " ";

    return 0;
}
