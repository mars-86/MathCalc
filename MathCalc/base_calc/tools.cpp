﻿#include "tools.h"

Tools::Tools()
{

}

Tools::~Tools()
{

}

int Tools::replace_v(const char* src, char* dest, int var, const char* val)
{
    while (*src != '\0') {
        if (*src == var) {
            *dest++ = '*';
            const char* tval = val;
            while (*tval != '\0')
                *dest++ = *tval++;
        }
        else
            *dest++ = *src;
        ++src;
    }
    *dest = '\0';

    return 0;
}

int Tools::replace_v(const std::string& src, std::string& dest, int var, const std::string& val)
{
    for (auto i = src.begin(); i != src.end(); ++i) {
        if (*i == var) {
            dest.push_back('*');
            for (auto i2 = val.begin(); i2 != val.end(); ++i2) dest.push_back(*i2);
        }
        else
            dest.push_back(*i);
    }
    return 0;
}

void Tools::replace_var(std::string& m, const char var, std::vector<char*>& val)
{
    for (int i = 0; i < m.size(); ++i)
        if (m[i] == var) {
            int len = 0;
            for (auto j : val) {
                // this way we insert in correct order, otherwise vals are inserted backwards
                m.insert((int)(i + len), (char*)j);
                len += strlen(j);
            }
            i += len;
            m.erase(m.begin() + i); // remove var
        }
}

// Generates a pair of values of the type {variable : value}
std::pair<std::string, std::vector<char*>> Tools::gen_var_val_pair(std::string var, std::vector<char*>& val)
{
    return std::pair<std::string, std::vector<char*>>(var, val);
}
