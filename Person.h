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
    const QString &Get_l_name() const { return l_name; }
    const QString &Get_f_name() const { return f_name; }
    const QString &Get_p_name() const { return p_name; }

};

Person::Person(QString full_name)//метод разбиения строки на подстроки:фамилия, имя, отчество. Можно без отчества
{
    QStringList str = full_name.split(QRegularExpression("\\s+"), Qt::SkipEmptyParts);//разбиение
    if (str.size() != 2 && str.size() != 3)//если размер строки не равен 2, 3, то выводим сообщение в ошибке
    {
        throw "Size error";
    }
    l_name = str[0];//присваиваем фамилию
    f_name = str[1]; //присваиваем имя
    if (str.size() == 3)
    {
        p_name = str[2]; //присваиваем отчество
    }
}

#endif // PERSON_H
