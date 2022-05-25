#include"article.h"
#include"list_item.h"
#include"text.h"
#include <list>
#include<typeinfo>
#include"./iterator/compound_iterator.h"
#pragma once
class Paragraph : public Article {
public:
    Paragraph(int level, std::string text):_level(level),_title(text) {
         if(_level<1||_level>6){
            throw "level should >=1 and <=6";
        }
     }

    ~Paragraph() { 
        for (std::list<Article*>::const_iterator it = _content.begin(); it != _content.end(); it++){
             delete *it;
         }
    }

    std::string getText() const override {
        std::string result="";
        result+=_title;
        //  for (std::list<Article*>::const_iterator it = _content.begin(); it != _content.end(); it++){
        //      if(it==--_content.end()){
        //          result+=(*it)->getText();
        //      }
        //      else{
        //          result+=(*it)->getText();
        //         // result+="\n";
        //      }
        //  }
         return result;
     }

    int getLevel() const override {
        return _level;
     }

     std::string gettitle() const{
        return _title;
    }

    Iterator* createIterator() override { 
         Iterator* compoundit=new CompoundIterator<std::list<Article*>::iterator>(_content.begin(),_content.end());
      compoundit->first();
      return compoundit;
    }

    void add(Article* content) override {
        if (typeid(*content).name()==typeid(Paragraph).name())
        {
            if(content->getLevel()>this->_level){
                 _content.push_back(content);
            }
            else{
                throw("can't not add");
            }
        }
        else{
            _content.push_back(content);
        }
     }

    void accept(ArticleVisitor* visitor) override {
        visitor->visitParagraph(this);
     }
    private:
    int _level;
    std::string _title;
    list<Article*>  _content;
};