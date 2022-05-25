#pragma once

#include <string>
#include <vector>

class Scanner
{
public:
    Scanner(std::string input) : _input(input) {}

    void skipWhiteSpace()
    {
        while (_input[pos] == ' ' || _input[pos] == '\n' || _input[pos] == '\t')
        {
            pos++;
        }
    }

    std::string next()
    {
        std::string result = "";
        skipWhiteSpace();
        if (pos == _input.length())
        {
            throw "exceed length";
        }
        while (pos < _input.length())
        {
            for (auto token : tokenList)
            {
                if (_input.compare(pos, token.length(), token) == 0)
                {
                    pos = pos + token.length();
                    result = token;
                    return result;
                }
            }
            pos++;
        }
        return result;
    }

    double nextDouble()
    {
        std::string s = "";
        bool mathIn = false;
        skipWhiteSpace();
        if (pos == _input.length())
        {
            throw "exceed length";
        }
        while (pos < _input.length())
        {
            if ((_input[pos] <= '9' && _input[pos] >= '0') || _input[pos] == '.')
            {
                mathIn = true;
                s = s + _input[pos];
            }
            else
            {
                if (mathIn)
                {
                    break;
                }
            }
            pos++;
        }

        return std::stod(s);
    }

    bool isDone()
    {
        skipWhiteSpace();
        return pos == _input.length();
    }

private:
    std::string _input;
    std::string::size_type pos = 0;
    const std::vector<std::string> tokenList = {"Circle", "Rectangle", "Triangle", "CompoundShape", "(", ")", "[", "]", "{", "}", ","};
};