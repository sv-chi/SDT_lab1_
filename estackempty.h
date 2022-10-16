#ifndef ESTACKEMPTY_H
#define ESTACKEMPTY_H
#include "estackexception.h"
class EStackEmpty : public Exception
{
public:
    // конструктор по умолчанию
    EStackEmpty(): Exception("Данный стек пуст"){} //инициализируем базовый класс с сообщением об ошибке

    // конструктор копирования
    EStackEmpty(const EStackEmpty &st): Exception(st){} //инициализируем базовый класс переданным аргуметом
};
#endif // ESTACKEMPTY_H
