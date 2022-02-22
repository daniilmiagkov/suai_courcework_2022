#include <iostream>// библиотека
#include <Windows.h> // библиотека
#include "various_functions.h"
#include <fstream>
#include <string>
#include <vector>

void checking_the_balance(std::string s)
{
    std::vector<int> array = {};

    for (int i = 0; i < 6; i++)
    {
        array.push_back(0);
    }    

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            array[0]++;
        }
        else if (s[i] == ')')
        {
            array[1]++;
        }
        else if (s[i] == '[')
        {
            array[2]++;
        }
        else if (s[i] == ']')
        {
            array[3]++;
        }
        else if (s[i] == '{')
        {
            array[4]++;
        }
        else if (s[i] == '}')
        {
            array[5]++;
        }
    }

    for (int i = 0; i < size(array) - 1; i += 2)
    {
        if (array[i] == array[i+1])
        {
            std::cout << "True" << std::endl;
        }
        else
        {
            std::cout << "False" << std::endl;
        }
    }
}

void lab_2_1()
{
    setlocale(0, ""); // поддержка кириллицы в консоли (вывод)
    SetConsoleCP(1251); // поддержка кириллицы в консоли (ввод)
    SetConsoleOutputCP(1251); // поддержка кириллицы в консоли (ввод)

    std::string source_string = "";
    std::cout << "¬ведите исходную строку " << std::endl;
    std::cin >> source_string;

    checking_the_balance(source_string);
}