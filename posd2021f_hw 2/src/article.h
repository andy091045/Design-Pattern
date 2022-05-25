#ifndef ARTICLE_H
#define ARTICLE_H
class Article
{
    //讓我測試一下更新
public:
    virtual ~Article(){};

    virtual std::string getText() const = 0;

    virtual int getLevel() const {}

    virtual void add(Article *dpFormat){};
    int _level = 0;
};

#endif