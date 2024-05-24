#include "parser.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <exception>
#include <algorithm>
//#include <locale>
 
//void parser::read_text(const std::string& filein, dict_abstract& dict)
//{
//    if (!filein.empty())
//    {
//        std::ifstream fin(filein);
//        std::string word;
//
//        while (!fin.eof())
//        {
//            fin >> word;
//            word = filter(word);
//            dict.add_dict(word);
//        }
//        fin.close();
//    }
//    else
//        throw std::invalid_argument("Empty name of file!");
//    
//}

void parser::read_text(std::istream& fin, dict_abstract& dict)
{
    if (fin)
    {
        std::string word;
        while (!fin.eof())
        {
            fin >> word;
            word = filter(word);
            dict.add_dict(word);
        }
    }
    else
        throw std::invalid_argument("Empty name of input!");
}

std::string parser::filter(const std::string& word)
{
    if (!word.empty())
    {
        std::string result = word.substr();
        result[0] = tolower(result[0]);
        /*if (iswalpha(result.back()) == false)
            std::erase(result, result.back());*/
        std::erase_if(result, ispunct);
        return result;
    }
    else
        throw std::invalid_argument("Empty word!");
    
    //size_t i = 0;
    //size_t max_size = word.length();
    /*const char* forbidden{ "—.,:;+=()[]{}!? " };
    size_t it = 0;

    while (it < word.length())
    {

        auto punct = word.find_first_of(forbidden, it);
        if (punct == std::string::npos)
        {
            result = word.substr(it, word.length());
            break;
        }
        else if (punct != it)
        {
            result = word.substr(it, punct - it);
        }
        it = punct + 1;
    }*/
    /*while (i < max_size)
    {
        if (isalpha(word[i]) == true)
        {
            if (isupper(word[i]) == true)
                result.push_back(tolower(word[i]));
            else
                result.push_back(word[i]);
        }
        i++;*/
        //std::cout << word << std::endl;
    //}
    //std::cout << result << std::endl;

    

    /*if (isupper(result[0]) == true)
        result[0] = tolower(result[0]);*/
    
}

void parser::write_result(const std::string& fileout, dict_abstract& dict)
{
    if (!fileout.empty())
    {
        std::ofstream fout(fileout);
        std::pair<std::string, size_t> item;
        while (true)
        {
            item = dict.get_dict();
            if (item.first == "STOP")
                break;
            fout << item.first << " - " << item.second << std::endl;
        }

        fout << "------------------------------------------" << std::endl;
        fout << "Time - " << clock() << " sec" << std::endl;
        fout.close();
    }
    else
        throw std::invalid_argument("Empty name of file!");
}
