/*#include <iostream>// ����������
#include <Windows.h> // ����������
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
    std::cout << "����� ������� ";
    char c;
    std::fstream file_output_f;
    while (!file_input_f.eof()) // ���� ���� �� ����, ��������� �� ����� �� ������ ������� � ������� �� �����
    {
        file_input_f >> c;
        std::cout << c;
        file_output_f << c;

    }
    return file_output_f;
}


void main()
{
    setlocale(0, ""); // ��������� ��������� � ������� (�����)
    SetConsoleCP(1251); // ��������� ��������� � ������� (����)
    SetConsoleOutputCP(1251); // ��������� ��������� � ������� (����)

    std::cout << "������� ����� ������ " << std::endl << "����� � ";
    int task_number = get_number_int();

    std::fstream file_input, file_output;

    switch (task_number)
    {
        case (1):
        {
            file_input.open("D:\\study_in_suai\\programming\\coursework\\input_texts\\input_esenin.txt",
                std::ios::in); // ��������� ����

            file_output.open("D:\\study_in_suai\\programming\\coursework\\output_texts\\output_esenin.txt",
                std::ios::out); // ��������� ����

            if (file_input.is_open() == true)
            {
                if (file_output.is_open() == true) {    // ��������� ������ �� ����
                    file_output = main_algolithm(file_input);
                    file_input.close(); // �������� �����
                    file_output.close();
                }
                else                 
                    std::cout << "���� 2 �� ��������!" << std::endl;
            }
            else // ���� ���� �� ������� �������, ����� ������ ������
                std::cout << "���� 1 �� ��������!" << std::endl;
        }
    }
} */