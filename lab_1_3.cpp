#include <iostream>// библиотека
#include <Windows.h> // библиотека
#include "various_functions.h"
#include <fstream>
#include <string>
#include <vector>

std::vector<int> search_for_an_array_of_residuals(std::vector<int> array_A_f, int length)
{
    std::vector<int> array_dop_1 = {};
    std::vector<int> array_dop_2 = {};
    for (int i = 0; i < length; i++)
    {
        array_dop_1.push_back(array_A_f[i] % 2);
        array_dop_1.push_back(array_A_f[i] % 3);
        array_dop_1.push_back(array_A_f[i] % 5);
    }
    for (int i = 0; i < size(array_dop_1); i++)
    {
        int k = 0;
        for (int j = 0; j < size(array_dop_1); j++)
        {
            if (array_dop_1[i] == array_dop_1[j])
            {
                k++;
            }
        }
        if (k == 1)
        {
            array_dop_2.push_back(array_dop_1[i]);
        }
    }
    return array_dop_2;
}

void lab_1_3()
{
    setlocale(0, ""); // поддержка кириллицы в консоли (вывод)
    SetConsoleCP(1251); // поддержка кириллицы в консоли (ввод)
    SetConsoleOutputCP(1251); // поддержка кириллицы в консоли (ввод)
    
    int length;
    std::string s;
    
    std::cout << "Введите количество элементов исходного массива" << std::endl;
    std::cin >> length;

    std::vector<int> array_A = {};
    std::vector<int> array_B = {};

    std::fstream file_input, file_output;




    file_input.open(
        "D:\\study_in_suai\\programming\\lab\\lab\\texts\\lab3_input_text.txt", 
        std::ios::out); // открываем файл
    
    // Запись данных в исходный файл
    if (file_input) {    // Проверяем открыт ли файл
        file_input << length << std::endl;
        for (int i = 0; i < length; i++) //Ввод исходных элементов  
        {
            std::cout << "Введите " << i + 1 << " число: ";
            file_input << get_number_double() << " "; // Записываем текст в файл
        }            
        file_input.close(); // Закрытие файла
    }
    else // Если файл не удалось открыть, тогда выдаем ошибку
        std::cout << "Файл не открылся!" << std::endl;




    file_input.open(
        "D:\\study_in_suai\\programming\\lab\\lab\\texts\\lab3_input_text.txt",
        std::ios::in); // открываем файл
    
    // Считывание данных из исходного файла
    if (file_input) {    // Проверяем открыт ли файл
        for (int i = 0; i < length + 1; i++) { 
            int temp;
            file_input >> temp;
            array_A.push_back(temp);
        }
        file_input.close(); // Закрытие файла
    }
    else // Если файл не удалось открыть, тогда выдаем ошибку
        std::cout << "Файл не открылся!" << std::endl;

    array_A.erase(array_A.begin());

    array_B = search_for_an_array_of_residuals(array_A, array_A.size());

    file_output.open(
        "D:\\study_in_suai\\programming\\lab\\lab\\texts\\lab3_output_text.txt",
        std::ios::out); // открываем файл в конструкторе
    
    if (file_output) {    // Проверяем открыт ли файл
        file_output << size(array_B) << std::endl;
        for (int i = 0; i < size(array_B); i++) {
            file_output << array_B[i] << " "; // Записываем текст в файл
        }
        file_output.close(); // Закрытие файла
    }
    else // Если файл не удалось открыть, тогда выдаем ошибку
        std::cout << "Файл не открылся!" << std::endl;
}