#ifndef ESTACKEMPTY_H
#define ESTACKEMPTY_H
#include "estackexception.h"
class EStackEmpty : public Exception
{
public:
    // конструктор по умолчанию
    EStackEmpty(): Exception("данный стек пуст"){}

    // конструктор копирования
    EStackEmpty(const EStackEmpty &st): Exception(st){}
};
#endif // ESTACKEMPTY_H
