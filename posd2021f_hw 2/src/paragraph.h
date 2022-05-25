#ifndef PARAGRAPH_H
#define PARAGRAPH_H
#include "./article.h"
#include <vector>

class Paragraph : public Article
{
public:
    Paragraph(int level, std::string text) : _text(text), _level(level)
    {
        std::string ptext;
        if (_level <= 0 || _level > 6)
        {
            throw "no  Paragraph";
        }
        for (int i = 0; i < _level; i++)
        {
            ptext += "#";
        }
        ptext += " ";
        ptext += _text;
        vect.push_back(ptext);
    }

    ~Paragraph() {}

    std::string getText() const override
    {
        std::string gtext;
        for (int i = 0; i < vect.size(); i++)
        {
            if (i == vect.size() - 1 && vect.size() > 1)
            {
                gtext = gtext + vect.at(i);
            }
            else
            {
                gtext = gtext + vect.at(i) + "\n";
            }
        }
        return gtext;
    }

    int getLevel() const override
    {
        return _level;
    }

    void add(Article *content) override
    {
        if (typeid(*content) == typeid(Paragraph) && content->getLevel() <= _level)
        {
            throw "no  add";
        }
        else
        {
            vect.push_back(content->getText());
        }
    }

    std::string _text;
    int _level;
    std::vector<std::string> vect;
};

#endif