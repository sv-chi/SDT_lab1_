#include <QCoreApplication>
#include "stack.h"
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <locale.h>


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

    return 0;
}
