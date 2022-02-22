#include <iostream>
#include <Windows.h> // библиотека
#include <string>
int main()
{
    setlocale(0, ""); // поддержка кириллицы в консоли (вывод)
    SetConsoleCP(1251); // поддержка кириллицы в консоли (ввод)
    SetConsoleOutputCP(1251); // поддержка кириллицы в консоли (ввод)
    std::string str = "", password = "qwerty098";
    std::cout << "Введите пароль: " << std::endl;
    std::cin >> str;
    int count = 0;
    while (true)
    {
        if (str == password)
        {
            std::cout << "Добро пожаловать, Сергей";
            break;
        }
        else
        {
            std::cout << "Введите другой пароль: ";
            std::cin >> str;
            count++;
        }
        if (count == 2)
        {
            while (true)
            {
                std::cout << rand();
            }
        }
    }
}
