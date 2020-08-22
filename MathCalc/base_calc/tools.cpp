#include "tools.h"

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

void Tools::replace_var(std::string& m, const char var, std::vector<std::string>& val)
{
    for (int i = 0; i < m.size(); ++i)
        if (m[i] == var) {
            int len = 0;
            for (auto j : val) {
                // this way we insert in correct order, otherwise vals are inserted backwards
                m.insert((int)(i + len), j);
                len += j.size();
            }
            i += len;
            m.erase(m.begin() + i); // remove var
        }
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

int Tools::shift(int num, int bits_count, const std::string type)
{
    if (type == ">>")
        return num >> bits_count;
    else
        return num << bits_count;
}

int Tools::dec_to_hex(double num)
{
    return 0;
}

int Tools::hex_to_dec(double num)
{
    return 0;
}

const std::string Tools::dec_to_bin(double num)
{
    return "";
}

int Tools::bin_to_dec(std::string num)
{
    return 0;
}

int Tools::dec_to_oct(double num)
{
    return 0;
}

int Tools::oct_to_dec(double num)
{
    return 0;
}

// Generates a pair of values of the type {variable : value}
std::pair<std::string, std::vector<std::string>> Tools::gen_var_val_pair(std::string var, const std::vector<std::string>& val) const
{
    return std::pair<std::string, std::vector<std::string>>(var, val);
}

std::pair<std::string, std::vector<char*>> Tools::gen_var_val_pair(std::string var, const std::vector<char*>& val) const
{
    return std::pair<std::string, std::vector<char*>>(var, val);
}

