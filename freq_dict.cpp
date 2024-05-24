#include "freq_dict.h"
#include <iostream>
#include <fstream>

std::map<std::string, size_t>::iterator dict_map::begin()
{
    return dict.begin();
}

std::map<std::string, size_t>::iterator dict_map::end()
{
    return dict.end();
}



void dict_map::add_dict(const std::string& word)
{
    if (!word.empty())
        dict[word]++;
    else
        throw std::invalid_argument("Empty word!");
}

std::pair<std::string, size_t> dict_map::get_dict()
{
    if (dict.empty())
        throw std::out_of_range("Dictionary is empty");

    if (reload == true)
    {
        it = begin();
        reload = false;
    }

    std::pair<std::string, size_t> item;
    if (it != end())
    {
        item = *it;
        ++it;
    }
    else
    {
        item = { "STOP", 0 };
        reload = true;
    }

    return item;
}

std::unordered_map<std::string, size_t>::iterator dict_unordered_map::begin()
{
    return dict.begin();
}

std::unordered_map<std::string, size_t>::iterator dict_unordered_map::end()
{
    return dict.end();
}

void dict_unordered_map::add_dict(const std::string& word)
{
    if (!word.empty())
        dict[word]++;
    else
        throw std::invalid_argument("Empty word!");
}

std::pair<std::string, size_t> dict_unordered_map::get_dict()
{
    if (dict.empty())
        throw std::out_of_range("Dictionary is empty");

    if (reload == true)
    {
        it = begin();
        reload = false;
    }

    std::pair<std::string, size_t> item;
    if (it != end())
    {
        item = *it;
        ++it;
    }
    else
    {
        item = { "STOP", 0 };
        reload = true;
    }

    return item;
}

std::vector<std::pair<std::string, size_t> >::iterator dict_vector::begin()
{
    return dict.begin();
}

std::vector<std::pair<std::string, size_t> >::iterator dict_vector::end()
{
    return dict.end();
}

void dict_vector::add_dict(const std::string& word)
{
    if (!word.empty())
    {
        auto pp = find_if(begin(), end(), [word](const std::pair<std::string, size_t>& element) {
            return element.first == word;
            });
        if (pp == end())
        {
            dict.push_back(make_pair(word, 1));
        }
        else
        {
            (*pp).second++;
        }
    }
    else
        throw std::invalid_argument("Empty word!");
}

std::pair<std::string, size_t> dict_vector::get_dict()
{
    if (dict.empty())
        throw std::out_of_range("Dictionary is empty");

    if (reload == true)
    {
        it = begin();
        reload = false;
    }

    std::pair<std::string, size_t> item;
    if (it != end())
    {
        item = *it;
        ++it;
    }
    else
    {
        item = { "STOP", 0 };
        reload = true;
    }

    return item;
}

std::list<std::pair<std::string, size_t> >::iterator dict_list::begin()
{
    return dict.begin();
}

std::list<std::pair<std::string, size_t> >::iterator dict_list::end()
{
    return dict.end();
}

void dict_list::add_dict(const std::string& word)
{
    if (!word.empty())
    {
        auto pp = find_if(begin(), end(), [word](const std::pair<std::string, size_t>& element) {
            return element.first == word;
            });
        if (pp == end())
        {
            dict.push_back(make_pair(word, 1));
        }
        else
        {
            (*pp).second++;
        }
    }
    else
        throw std::invalid_argument("Empty word!");
}

std::pair<std::string, size_t> dict_list::get_dict()
{
    if (dict.empty())
        throw std::out_of_range("Dictionary is empty");

    if (reload == true)
    {
        it = begin();
        reload = false;
    }

    std::pair<std::string, size_t> item;
    if (it != end())
    {
        item = *it;
        ++it;
    }
    else
    {
        item = { "STOP", 0 };
        reload = true;
    }

    return item;
}

std::set<std::pair<std::string, size_t> >::iterator dict_set::begin()
{
    return dict.begin();
}

std::set<std::pair<std::string, size_t> >::iterator dict_set::end()
{
    return dict.end();
}

void dict_set::add_dict(const std::string& word)
{
    if (!word.empty())
    {
        auto pp = find_if(begin(), end(), [word](const std::pair<std::string, size_t>& element) {
            return element.first == word;
            });
        if (pp == end())
        {
            dict.insert(make_pair(word, 1));
        }
        else
        {
            dict.insert(make_pair(word, 1 + (*pp).second));
            dict.erase(pp);
        }
    }
    else
        throw std::invalid_argument("Empty word!");
}

std::pair<std::string, size_t> dict_set::get_dict()
{
    if (dict.empty())
        throw std::out_of_range("Dictionary is empty");

    if (reload == true)
    {
        it = begin();
        reload = false;
    }

    std::pair<std::string, size_t> item;
    if (it != end())
    {
        item = *it;
        ++it;
    }
    else
    {
        item = { "STOP", 0 };
        reload = true;
    }

    return item;
}

std::unordered_set< std::pair<std::string, size_t>, dict_unordered_set::pair_hash >::iterator dict_unordered_set::begin()
{
    return dict.begin();
}

std::unordered_set< std::pair<std::string, size_t>, dict_unordered_set::pair_hash >::iterator dict_unordered_set::end()
{
    return dict.end();
}

void dict_unordered_set::add_dict(const std::string& word)
{
    if (!word.empty())
    {
        auto pp = find_if(begin(), end(), [word](const std::pair<std::string, size_t>& element) {
            return element.first == word;
            });
        if (pp == end())
        {
            dict.insert(make_pair(word, 1));
        }
        else
        {
            dict.insert(make_pair(word, 1 + (*pp).second));
            dict.erase(pp);
        }
    }
    else
        throw std::invalid_argument("Empty word!");
}

std::pair<std::string, size_t> dict_unordered_set::get_dict()
{
    if (dict.empty())
        throw std::out_of_range("Dictionary is empty");

    if (reload == true)
    {
        it = begin();
        reload = false;
    }

    std::pair<std::string, size_t> item;
    if (it != end())
    {
        item = *it;
        ++it;
    }
    else
    {
        item = { "STOP", 0 };
        reload = true;
    }

    return item;
}