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
    PersonKeeper(){}// конструктор по умолчанию
    ~PersonKeeper(){}//деструктор
    Stack<Person> s;//имена

public:
    static PersonKeeper &Instance();// хранится единственный экземпляр класса
    void ReadPersons(QString path);//читаем файл
    void WritePersons(QString path);//запись файла
    int Size();//размер стека
    void Clear();//очистить стек

};

//количество человек
int PersonKeeper::Size()
{
    return s.Size();
}
//стереть человека
void PersonKeeper::Clear()
{
    s.Clear();
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
    QFile file(path);//создаётся объект типа QFile по путю
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))//проверка, открылся ли файл для чтения(только для чтения и только текстовый)
    {
        throw "Файл не открыт";
    }
    QTextStream stream(&file);//поток текстовых данных файла
    QString l;// для считывания строк
    while (stream.readLineInto(&l))//пока есть строки
    {
        Person person = Person();
        if (person.parseName(l)){
            s.Push(person);//Создаём человека по строке и добавляем в стек
        }
    }
    file.close();//закрываем файл
}
//запись файла
void PersonKeeper::WritePersons(QString path)
{
    QFile file(path);//создаётся объект типа QFile по путю
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))//открываем файл для записи
    {
        throw "Файл не открыт";
    }
    QTextStream stream(&file);//поток текстовых данных файла
    Stack <Person> sp(s);//создали стек персонов равный стеку s
     Person P;//временная переменная с ФИО
     for (int i=0;i<s.Size();i++){
         P =sp.Pop();//извлекаем из стека по одному персону

    stream << P.Get_l_name() << " " << P.Get_f_name() << " " << P.Get_p_name() << Qt::endl;//записываем человека в файл
}
    file.close();//закрываем файл

};
#endif

/*Stack <Person> sp(s), ts, temp;//копия стека и временный пустой стек
 Person P;//временная переменная с ФИО

 //заполняем временный стек значениями из копии исходного стека
 for (int i=0;i<s.size;i++)
     ts.Push(sp.Pop());//обратный порядок

 for (int i=0;i<s.size;i++){//возвращаем значения в изначальный стек
     Person p = ts.Pop();
     sp.Push(p);
     temp.Push(p);
 }

 for (int i=0;i<s.size;i++){
        P = temp.Pop();
*/
