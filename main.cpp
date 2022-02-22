/*#include <iostream>// библиотека
#include <Windows.h> // библиотека
#include "various_functions.h"
#include <vector> 
#include <fstream>
#include <clocale> 
#include <string>

std::vector<std::string> breakdown_into_words(std::string str)
{

}

std::string source_str()
{

}

std::fstream main_algolithm(std::fstream& file_input_f)
{
    std::cout << "файлы открыты ";
    char c;
    std::fstream file_output_f;
    while (!file_input_f.eof()) // пока файл не пуст, считываем из файла по одному символу и выводим на экран
    {
        file_input_f >> c;
        std::cout << c;
        file_output_f << c;

    }
    return file_output_f;
}


void main()
{
    setlocale(0, ""); // поддержка кириллицы в консоли (вывод)
    SetConsoleCP(1251); // поддержка кириллицы в консоли (ввод)
    SetConsoleOutputCP(1251); // поддержка кириллицы в консоли (ввод)

    std::cout << "Введите номер текста " << std::endl << "Текст № ";
    int task_number = get_number_int();

    std::fstream file_input, file_output;

    switch (task_number)
    {
        case (1):
        {
            file_input.open("D:\\study_in_suai\\programming\\coursework\\input_texts\\input_esenin.txt",
                std::ios::in); // открываем файл

            file_output.open("D:\\study_in_suai\\programming\\coursework\\output_texts\\output_esenin.txt",
                std::ios::out); // открываем файл

            if (file_input.is_open() == true)
            {
                if (file_output.is_open() == true) {    // Проверяем открыт ли файл
                    file_output = main_algolithm(file_input);
                    file_input.close(); // Закрытие файла
                    file_output.close();
                }
                else                 
                    std::cout << "Файл 2 не открылся!" << std::endl;
            }
            else // Если файл не удалось открыть, тогда выдаем ошибку
                std::cout << "Файл 1 не открылся!" << std::endl;
        }
    }
} */