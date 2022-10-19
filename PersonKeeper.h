#ifndef PERSONKEEPER_H
#define PERSONKEEPER_H
#include <QString>
#include "stack.h"
#include "Person.h"
#include <QTextStream>
#include <QFile>

//паттерн Singleton
class PersonKeeper
{
private:
    PersonKeeper(){}// конструкторы по умолчанию
    PersonKeeper(const PersonKeeper &);//конструктор копирования
    ~PersonKeeper(){}//деструктор
    PersonKeeper &operator=(const PersonKeeper &);//оператор присовения
    Stack<Person> s;//имена
public:
    static PersonKeeper &Instance();// хранится единственный экземпляр класса
    void ReadPersons(QString path);//читаем файл
    void WritePersons(QString path) const;//запись файла
    int Size();//количество человек
    void Clear();//стереть человека

};

//количество человек
int PersonKeeper::Size()
{
    return s.Size();
}
//стереть человека
void PersonKeeper::Clear()
{
    return s.Clear();
}
//хранится единственный экземпляр класса
PersonKeeper &PersonKeeper::Instance()
{
    static PersonKeeper instance;
    return instance;
}
//читаем файл
void PersonKeeper::ReadPersons(QString path)
{
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))//проверка, открылся ли файл для чтения
    {
        throw "Файл не открыт";
    }
    QTextStream stream(&file);//поток текстовых данных файла
    QString l;//считывание в буфер строк
    while (stream.readLineInto(&l))
    { s.Push(Person(l));//добавляем человека
    }
    file.close();//закрываем файл
}
//запись файла
void PersonKeeper::WritePersons(QString path) const
{
    QFile file(path);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))//открываем файл для записи
    {
        throw "Файл не открыт";
    }
    QTextStream stream(&file);//поток текстовых данных файла
    s.Print([&](const Person &k)//перебор значения
    {
        stream << k.Get_l_name() << " " << k.Get_f_name() << " " << k.Get_p_name() << Qt::endl;//записываем человека в файл
    });
    file.close();//закрываем файл
};
#endif
