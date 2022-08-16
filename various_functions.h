#pragma once
#include <iostream>
#include <vector>

using namespace std;

unsigned int sort(std::vector<std::string>& words);

std::vector<int> counting_words(std::vector<std::string> array);

string get_number_file();

string get_string(string number_file);

vector<string> split_text(string source_string);

string alphabet();

void writing_to_result(vector<string> words, string number_file);

void writing_to_analysis(string source_string, int count, vector<int> count_words, int time, string number_file);
