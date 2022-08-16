#include <iostream>// библиотека
#include <Windows.h> // библиотека
#include "various_functions.h"
#include <vector>
#include <fstream>
#include <string>

using namespace std;

unsigned int sort(std::vector<std::string>& source_words)
{    
    unsigned int average_time = 0;
    unsigned int start_time, end_time;   
    int n = 5;
    std::vector<std::string> words;
    for (int k = 0; k < n; k++)
    {
        start_time = clock();
        words = source_words;
        for (int i = 1; i < words.size(); i++)
        {
            for (int j = i; j > 0; j--)
            {
                if (alphabet().find(words[j - 1][0]) < alphabet().find(words[j][0]))
                    break;
                swap(words[j - 1], words[j]);
            }
        }
        end_time = clock();
        average_time += end_time - start_time;
    }
    source_words = words;
    return average_time / n;
}

std::vector<int> counting_words(std::vector<std::string> words)
{
    std::vector<int> count_words(33);

    for (int i = 0; i < words.size(); i++)
    {
        count_words[alphabet().find(words[i][0]) % 33]++;
    }
    return count_words;
}

string get_number_file()
{
    string number_file = "";

    std::cout
        << "Доступные файлы:" << std::endl
        << std::endl
        << "    1. Есенин" << std::endl
        << "    2. Булгаков" << std::endl
        << "    3. Шолохов" << std::endl
        << "    4. 12 стульев" << std::endl
        << "    5. Публицистический стиль" << std::endl
        << "    6. Обломов" << std::endl
        << "    7. Шолохов" << std::endl
        << "    8. Отцы и дети" << std::endl
        << "    9. Преступление и наказание" << std::endl
        << "    10. Отцы и дети" << std::endl
        << std::endl
        << "Введите номер файла с текстом: ";

    vector <pair <string, int>> text_names =
    {
        {"Есенин", 1},
        {"Булгаков", 2},
        {"Шолохов", 3},
        {"12 стульев", 4},
        {"Публицистический стиль", 5},
        {"Обломов", 6},
        {"Шолохов", 7},
        {"Отцы и дети", 8},
        {"Преступление и наказание", 9},
        {"Отцы и дети", 10}
    };

    while (true)
    {
        std::cin >> number_file;
        if (number_file == "-1")
            exit(0);

        ifstream file_original; //создаем переменную файла
        file_original.open("D:\\courcework\\texts\\original\\original_" + number_file + ".txt"); // открываем файл
        
        if (file_original.is_open()) //если файл открылся 
        {
            cout << "Вы выбрали " << text_names[stoi(number_file) - 1].first << endl;
            file_original.close(); // Закрытие файла
            break;
        }
        else
        {
            std::cout << "Такого файла нет, введите другое название. Или введите -1, чтобы выйти из программы: " << std::endl;
        }
    }
    return number_file;
}

string get_string(string number_file)
{
    ifstream file_original;

    file_original.open("D:\\courcework\\texts\\original\\original_" + number_file + ".txt"); // открываем файл

    string source_string = "";

    char ch;
    while (file_original.get(ch)) //пока можем считать символ из файла
    {
            source_string+= ch;; //прибавляем символ к строке 
    }
    file_original.close(); // Закрытие файла
    return source_string;
}

vector <string> split_text(string source_string)
{    
    source_string = '"' + source_string + '"';

    string word = "";
    vector <string> words;
    for (int i = 1; i < source_string.size() - 1; i++)
    {
        if (alphabet().find(source_string[i]) != -1)
        {
            word += source_string[i];
            if (alphabet().find(source_string[i + 1]) == -1 && source_string[i + 1] != '-')
            {
                words.push_back(word);
                word = "";
            }
        }
        else if (source_string[i] == '-' && alphabet().find(source_string[i + 1]) >= 33 && alphabet().find(source_string[i + 1]) <= source_string.size() - 1 && word.size() != 0)
        {
            word += source_string[i];
        }
    }
    return words;
}

string alphabet()
{
    string alphabet = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдеёжзийклмнопрстуфхцчшщъыьэюя";
    return alphabet;
}

void writing_to_result(vector <string> words, string number_file)
{
    ofstream file_result;
    file_result.open("D:\\courcework\\texts\\result\\result_" + number_file + ".txt"); // открываем файл

    for (int i = 0; i < words.size(); i++)
        file_result << words[i] << endl;
}

void writing_to_analysis(string source_string, int count, vector <int> count_words, int time, string number_file)
{
    ofstream file_analysis;
    file_analysis.open("D:\\courcework\\texts\\analysis\\analysis_" + number_file + ".txt"); // открываем файл

    file_analysis
        << "Исходный текст: " << endl
        << "<<" << source_string << ">>" << endl
        << "Параметры выбранного варианта (15): кириллица, по алфавиту, по возрастанию, игнорировать числа, сортировка вставками" << endl
        << "Количество слов: " << count << endl
        << "Время сортировки: " << static_cast<double>(time) / 1000 << " с" << endl
        << "Статистика (количество слов на каждую букву алфавита): " << endl;

    cout
        << "Исходный текст: " << endl
        << "<<" << source_string << ">>" << endl
        << "Параметры выбранного варианта (15): кириллица, по алфавиту, по возрастанию, игнорировать числа, сортировка вставками" << endl
        << "Количество слов: " << count << endl
        << "Время сортировки: " << static_cast<double>(time) / 1000 << " с" << endl
        << "Статистика (количество слов на каждую букву алфавита): " << endl;

    //вывод количества слов на каждую букву
    for (int i = 0; i < count_words.size(); i++)
    {
        file_analysis << alphabet()[i + 33] << ": " << count_words[i] << endl;
        cout << alphabet()[i + 33] << ": " << count_words[i] << endl;
    }
    file_analysis.close();
}
