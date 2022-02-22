#include <iostream>// ����������
#include <Windows.h> // ����������
#include "various_functions.h"
#include <vector> 
#include <fstream>
#include <clocale> 
#include <string>

std::vector<std::string> breakdown_into_words(std::string str)
{
    std::vector<std::string> array_of_words = {};
    std::string s = "";

    for (int i = 0; i < str.length() - 1; i++)
    {
        if (   (((str[i] >= '�' && str[i] <= '�') ||
                  str[i] == '�' || str[i] == '�') && str[i + 1] != '�' &&
                 (str[i + 1] < '�' || str[i + 1] > '�')) ||
                    
                 (str[i] == '-' &&
                 (str[i + 1] >= '�' && str[i + 1] <= '�')))
        {
            s += str[i];
            if (((str[i + 1] >= '\0' && str[i + 1] <= ',') ||
                ( str[i + 1] >= '.' || str[i + 1] <= '�') &&
                  str[i + 1] != '�'))
            {
                array_of_words.push_back(s);
                s = "";
            }
        }
        else if (str[i] == '-' && (str[i + 1] < '�' || str[i + 1] >= '\0'))
        {
            array_of_words.push_back(s);
            s = "";
        }
    }
    return array_of_words;
}


void sorting(std::vector<std::string>& array_of_words)
{
    int j;
    std::string tmp;
    for (int i = 0; i < array_of_words.size(); i++)
    {
        j = i;
        for (int k = i; k < array_of_words.size(); k++)
        {
            if (array_of_words[j][0] > array_of_words[k][0])
            {
                j = k;
            }
        }
        tmp = array_of_words[i];
        array_of_words[i] = array_of_words[j];
        array_of_words[j] = tmp;
    }
}

void remove_garbage(std::vector<std::string>& array_of_words)
{
    for (int i = 0; i < array_of_words.size(); i++)
    {
        if (array_of_words[i][0] < '�' || array_of_words[i][0] > '�')
        {
            array_of_words.erase(array_of_words.begin() + i);
        }
    }
}

std::vector<int> counting_words(std::vector<int> array)
{
    std::vector<int> the_number_of_words_per_letter = {};
    
    for (int i = 0; i < 66; i++)
    {
        for 
        the_number_of_words_per_letter.push_back();
    }


}

void main_algolithm(std::string name)
{
    std::fstream file_original, file_result, file_analysis;
    std::string original_str = "D:\\study_in_suai\\programming\\coursework\\texts\\original_texts\\original_" + name + ".txt";
    std::string result_str = "D:\\study_in_suai\\programming\\coursework\\texts\\result_texts\\result_" + name + ".txt";
    std::string analysis_str = "D:\\study_in_suai\\programming\\coursework\\texts\\analysis_texts\\analysis_" + name + ".txt";

    std::vector<std::string> array_of_words = {};

    file_original.open(original_str, std::ios::in); // ��������� ����
    file_result.open(result_str, std::ios::out); // ��������� ����
    file_analysis.open(analysis_str, std::ios::out); // ��������� ����

    if (file_original.is_open())
    {
        if (file_result.is_open()) 
        {    
            if (file_result.is_open())
            {
                std::cout << "��� ����� �������" << std::endl;

                std::string source_string = "";

                while (!file_original.eof())// ���� ���� �� ����, ��������� �� ����� �� ������ �������
                {
                    source_string += file_original.get();
                }
                source_string.erase(source_string.length() - 1, 1);
                array_of_words = breakdown_into_words(source_string);


                remove_garbage(array_of_words);
                sorting(array_of_words);

                file_analysis
                    << "�������� �����: " << std::endl << "<<" << source_string << ">>" << std::endl
                    << "��������� ���������� ��������: " << std::endl
                    << "    1. ��������� " << std::endl
                    << "    2. �� �������� " << std::endl
                    << "    3. �� ����������� " << std::endl
                    << "    4. ������������ ����� " << std::endl
                    << "    5. ���������� ��������� " << std::endl
                    << "���������� ����: " << array_of_words.size() << std::endl
                    ;
                for (int i = 0; i < array_of_words.size(); i++)
                {
                    file_result << array_of_words[i] << std::endl;
                    std::cout << array_of_words[i] << std::endl;
                }
                //�������� ����� ������� � �������� ����

                file_original.close(); // �������� �����
                file_result.close();
                std::cout
                    << std::endl
                    << "���������� ��������� ���������." << std::endl
                    << "����� �������." << std::endl
                    << "���������� ��������: " << source_string.length() << std::endl
                    << "���������� ����: " << array_of_words.size() << std::endl;
            }
            else std::cout << "���� analysis �� ��������!" << std::endl;
        }
        else std::cout << "���� result �� ��������!" << std::endl;
    }
    else std::cout << "���� original �� ��������!" << std::endl;   // ���� ���� �� ������� �������, ����� ������ ������
}


void main()
{
    setlocale(0, ""); // ��������� ��������� � ������� (�����)
    SetConsoleCP(1251); // ��������� ��������� � ������� (����)
    SetConsoleOutputCP(1251); // ��������� ��������� � ������� (����)

    std::string file_name = "";
    std::fstream file_input, file_output;
    
    std::cout 
        << "  ��������� �����:" << std::endl 
        << std::endl
        << "    1. ���� (test)" << std::endl 
        << "    2. �������� (bulgakov)" << std::endl
        << "    3. ������� (sholohov)" << std::endl 
        << "    4. ���� (test)" << std::endl
        << "    5. �������� (bulgakov)" << std::endl
        << "    6. ������� (sholohov)" << std::endl
        << "    7. ���� (test)" << std::endl
        << "    8. �������� (bulgakov)" << std::endl
        << "    9. ������� (sholohov)" << std::endl
        << "    10. ���� (test)" << std::endl
        << std::endl
        << "  ������� �������� ����� � �������: ";
    
    while (true)
    {
        std::cin >> file_name;
        if (file_name == "test" || 
            file_name == "bulgakov" || 
            file_name == "sholohov")
        {
            main_algolithm(file_name);
            break;
        }
        else std::cout << "������ ����� ���, ������� ������ ��������" << std::endl;
    }
}