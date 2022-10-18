#ifndef PERSONKEEPER_H
#define PERSONKEEPER_H
#include <QString>
#include "stack.h"
#include "Person.h"
#include <QTextStream>
#include <QFile>

class PersonKeeper
{
private:
    PersonKeeper(){}// конструкторы по умолчанию
    PersonKeeper(const PersonKeeper &);//конструктор копирования
    ~PersonKeeper(){}//деструктор
    PersonKeeper &operator=(const PersonKeeper &);//оператор присвоения
    Stack<Person> s;//имена
public:
    static PersonKeeper &Instance();//хранится единственный экземпляр класса
    void ReadPersons(QString path);//читаем файл
    void WritePersons(QString path) const;//запись файла
    int Size();//количество человек
    void Clear();//стереть человека

};


int PersonKeeper::Size()
{
    return s.Size();
}
void PersonKeeper::Clear()
{
    return s.Clear();
}

PersonKeeper &PersonKeeper::Instance()
{
}

void PersonKeeper::ReadPersons(QString path)
{
}


void PersonKeeper::WritePersons(QString path) const
{
};
#endif
