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
//тест  стека 1
 Stack<int> stacktest; //создан пустой стек
 cout << "Stack size: " << stacktest.Size() << endl;//проверяем размер стека

 for(int i = 0;i<4;i++)
{
    stacktest.Push(i);//добавили в стек
}
 stacktest.Pop(); //извлечение из стека 3
 cout << "Stack size: " << stacktest.Size() << endl;//проверяем размер стека

//тест стека 2
 Stack<int> stacktest2; // создаем пустой стек
   int num = 5;
   stacktest2.Push(num);
   stacktest2.Push(10);
   cout << stacktest2.Pop() << ' ' << stacktest2.Pop() << endl;
   try {
       stacktest2.Pop(); // пытаемся получить последний элемент
   }  catch (const EStackEmpty & exception) {
       cout << exception.what() << endl; //выводим ошибку
   }

//тест стека 3
   Stack<float> stacktest3;
   for (int i = 0; i < 10; ++i) {
       stacktest3.Push(0.001*rand()/10);
   }

   cout << "Print float: ";
   stacktest3.Print([&](const float &k){ //печатаем значения типа float
           cout<<k<<" ";
       });

//тест стека 4
   Stack<string> stacktest4;
   string v1="Print", v2="string";
   cout << endl;
   stacktest4.Push(v2);
   stacktest4.Push(v1);
   stacktest4.Print([&](const string &k){
           cout<<k<<" ";
       });
   cout <<endl;

//тест PersonKeeper 1
 PersonKeeper &person(PersonKeeper::Instance());
 QString path1 = "C:\\CHIKAEED\\untitled5\\ReadPerson.txt";
 QString path2 = "C:\\CHIKAEED\\untitled5\\WritePerson.txt";
 person.Clear();
 person.ReadPersons(path1);
 person.WritePersons(path2);

    return 0;
}
