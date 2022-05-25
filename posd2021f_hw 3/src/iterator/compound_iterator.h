// you should define a template class or type `ForwardIterator`
#ifndef COMPOUNDITERATIR_H
#define COMPOUNDITERATIR_H

#include "./iterator.h"

class CompoundIterator : public Iterator
{
public:
    template <class ForwardIterator>
    CompoundIterator(ForwardIterator begin, ForwardIterator end) : _begin(begin), _end(end) { _current = _begin; }

    void first() override { _current = _begin; }

    Shape *currentItem() const override { return *_current; }

    void next() override { ++_current; }

    bool isDone() const override { return _current == _end; }

private:
    std::list<Shape *>::iterator _begin, _end, _current;
};

#endif