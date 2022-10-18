#include <QCoreApplication>
#include "stack.h"
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <locale.h>
#include "PersonKeeper.h"

using namespace std;

int main()
{
   //тесты  стека

 Stack<int> stacktest; //создан пустой стек
 cout << "Stack size: " << stacktest.Size() << endl;//проверяем размер стека

 for(int i = 0;i<4;i++)
{
    stacktest.Push(i);//добавили в стек
}
 stacktest.Pop(); //извлечение из стека 3
 cout << "Stack size: " << stacktest.Size() << endl;//проверяем размер стека

 PersonKeeper &person(PersonKeeper::Instance());
    QString path1 = "C:\\CHIKAEED\\untitled5\\ReadPerson.txt";
    QString path2 = "C:\\CHIKAEED\\untitled5\\WritePerson.txt";
    person.Clear();
    person.ReadPersons(path1);
    person.WritePersons(path2);

    return 0;
}
