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
    bool parseName(QString full_name){
        QStringList str = full_name.split(QString(" "));//разбиение
        if (str.size() != 2 && str.size() != 3)//если размер строки не равен 2, 3, то выводим сообщение в ошибке
            {
              //throw "Size error";
            return false;
            }
        l_name = str[0];//присваиваем фамилию
        _name = str[1]; //присваиваем имя
            if (str.size() == 3){
                p_name = str[2]; //присваиваем отчество
            }
        return true;
    }
    Person(){}// конструктор по умолчанию
    //конструктор с аргументами
    Person(QString l_n, QString f_n, QString p_n){
        l_name = l_n;//в поля заносим значения параметров
        f_name = f_n;
        p_name = p_n;
    }

    //задать значения
    void Set_l_name(const QString &l_n) {
        l_name = l_n;
    }
    void Set_f_name(const QString &f_n) {
        f_name = f_n;
    }
    void Set_p_name(const QString &p_n) {
        p_name = p_n;
    }
    //получить значения
     QString Get_l_name()  { return l_name; }
     QString Get_f_name()  { return f_name; }
     QString Get_p_name()  { return p_name; }

};



#endif // PERSON_H
