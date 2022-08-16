# courcework
Программа предназначена для анализа текста на русском языке (символы кириллицы). На вход требуется файл с расширением .txt. Программа считывает текст из файла, разбивает его на слова, сортирует их по алфавиту в порядке возрастания и выводит в выходной файл. Также в файл анализа выводится небольшой анализ текста. Название исходного файла вводится с консоли, остальные файла создаются в процессе работы программы. Погрешность разбивки слов +- 1 слово, при кол-ве слов 2000.

Для разбивки исходного текста на слова используется функция:
```
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
```
Для сортировки:
```
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
```

Программа работает только с файлами с расширением .txt.

Скриношот файла с исходными данными:
![image](https://user-images.githubusercontent.com/105947302/171845551-4f69ab4f-3914-4147-91ec-74fa1629e807.png)
Скриношот файла с отсортированными словами:
![image](https://user-images.githubusercontent.com/105947302/171845589-c1efe284-293e-4a75-bb6e-ab373f7c635b.png)
Скриношот файла с анализом:
![image](https://user-images.githubusercontent.com/105947302/171845624-ae1b69e8-f344-4c4a-b80c-90520d6fdfd1.png)

