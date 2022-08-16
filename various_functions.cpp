#include <iostream>// ����������
#include <Windows.h> // ����������
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
        << "��������� �����:" << std::endl
        << std::endl
        << "    1. ������" << std::endl
        << "    2. ��������" << std::endl
        << "    3. �������" << std::endl
        << "    4. 12 �������" << std::endl
        << "    5. ���������������� �����" << std::endl
        << "    6. �������" << std::endl
        << "    7. �������" << std::endl
        << "    8. ���� � ����" << std::endl
        << "    9. ������������ � ���������" << std::endl
        << "    10. ���� � ����" << std::endl
        << std::endl
        << "������� �������� ����� � �������: ";

    vector <pair <string, int>> text_names =
    {
        {"������", 1},
        {"��������", 2},
        {"�������", 3},
        {"12 �������", 4},
        {"���������������� �����", 5},
        {"�������", 6},
        {"�������", 7},
        {"���� � ����", 8},
        {"������������ � ���������", 9},
        {"���� � ����", 10}
    };

    while (true)
    {
        std::cin >> number_file;
        if (number_file == "-1")
            exit(0);

        ifstream file_original; //������� ���������� �����
        file_original.open("D:\\courcework\\texts\\original\\original_" + number_file + ".txt"); // ��������� ����
        
        if (file_original.is_open()) //���� ���� �������� 
        {
            cout << "�� ������� " << text_names[stoi(number_file) - 1].first << endl;
            file_original.close(); // �������� �����
            break;
        }
        else
        {
            std::cout << "������ ����� ���, ������� ������ ��������. ��� ������� -1, ����� ����� �� ���������: " << std::endl;
        }
    }
    return number_file;
}

string get_string(string number_file)
{
    ifstream file_original;

    file_original.open("D:\\courcework\\texts\\original\\original_" + number_file + ".txt"); // ��������� ����

    string source_string = "";

    char ch;
    while (file_original.get(ch)) //���� ����� ������� ������ �� �����
    {
            source_string+= ch;; //���������� ������ � ������ 
    }
    file_original.close(); // �������� �����
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
    string alphabet = "�����Ũ����������������������������������������������������������";
    return alphabet;
}

void writing_to_result(vector <string> words, string number_file)
{
    ofstream file_result;
    file_result.open("D:\\courcework\\texts\\result\\result_" + number_file + ".txt"); // ��������� ����

    for (int i = 0; i < words.size(); i++)
        file_result << words[i] << endl;
}

void writing_to_analysis(string source_string, int count, vector <int> count_words, int time, string number_file)
{
    ofstream file_analysis;
    file_analysis.open("D:\\courcework\\texts\\analysis\\analysis_" + number_file + ".txt"); // ��������� ����

    file_analysis
        << "�������� �����: " << endl
        << "<<" << source_string << ">>" << endl
        << "��������� ���������� �������� (15): ���������, �� ��������, �� �����������, ������������ �����, ���������� ���������" << endl
        << "���������� ����: " << count << endl
        << "����� ����������: " << static_cast<double>(time) / 1000 << " �" << endl
        << "���������� (���������� ���� �� ������ ����� ��������): " << endl;

    cout
        << "�������� �����: " << endl
        << "<<" << source_string << ">>" << endl
        << "��������� ���������� �������� (15): ���������, �� ��������, �� �����������, ������������ �����, ���������� ���������" << endl
        << "���������� ����: " << count << endl
        << "����� ����������: " << static_cast<double>(time) / 1000 << " �" << endl
        << "���������� (���������� ���� �� ������ ����� ��������): " << endl;

    //����� ���������� ���� �� ������ �����
    for (int i = 0; i < count_words.size(); i++)
    {
        file_analysis << alphabet()[i + 33] << ": " << count_words[i] << endl;
        cout << alphabet()[i + 33] << ": " << count_words[i] << endl;
    }
    file_analysis.close();
}
