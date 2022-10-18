#ifndef PERSON_H
#define PERSON_H
#include <QString>
#include <QRegularExpression>


class Person
{
private:
    QString l_name;//фамилия
    QString f_name;//имя
    QString p_name;//отчество
public:
    Person(){}// конструктор по умолчанию
    Person(QString l_name, QString f_name, QString p_name): l_name(l_name), f_name(f_name), p_name(p_name){ }//конструктор с аргументами
    Person(QString full_name);
    void Set_l_name(const QString &l_name) {
        this->l_name = l_name;
    }
    void Set_f_name(const QString &f_name) {
        this->f_name = f_name;
    }
    void Set_p_name(const QString &p_name) {
        this->p_name = p_name;
    }
    const QString &Get_l_name() const { return l_name; }//getter фамилии
    const QString &Get_f_name() const { return f_name; }//getter имени
    const QString &Get_p_name() const { return p_name; }//getter отвество

};

Person::Person(QString full_name)//метод разбиения строки на подстроки:фамилия, имя, отчество. Можно без отчества
{

}

#endif // PERSON_H
