#include <iostream>// ����������
#include <Windows.h> // ����������
#include "various_functions.h"
#include <vector> 
#include <fstream>
#include <clocale> 

using namespace std;

int main()
{
    setlocale(0, ""); // ��������� ��������� � ������� (�����)
    SetConsoleCP(1251); // ��������� ��������� � ������� (����)
    SetConsoleOutputCP(1251); // ��������� ��������� � ������� (����)

    string number_file = get_number_file();

    string source_string = get_string(number_file);

    vector <string> words = split_text(source_string);

    vector <int> count_words = counting_words(words);

    unsigned int time = sort(words);

    writing_to_result(words, number_file);

    writing_to_analysis(source_string, words.size(), count_words, time, number_file);

    return 0;

}

