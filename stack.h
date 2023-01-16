#ifndef STACK_H
#define STACK_H
#include "estackexception.h"
#include "estackempty.h"
#include <functional>
#include <iostream>
#include <stdlib.h>
using namespace std;
template <class T>
class Stack
{
public:
    ~Stack(); //деструктор
    int Size(){return size;}; // метод возвращающий размер
    void Clear(); //удаление из стека всех узлов
    void Push(const T &k); //помещение объекта в стек, k - значение
    const T Pop(); //извлечение объекта из стека
   void Print();//метод вывода стека

private:
    struct Node //узел, элемент односвязного списка
    {
        const T key; // значение элемента стека
        Node *pr = nullptr; // указатель на соседний элемент
    };

    int size = 0;//размер стека
    Node *head = nullptr; // указатель на верхний элемент стека

};
//метод вывода стека
template <class T>void Stack<T>::Print()
{
    Node *tmp = head; //указатель на первый элемент
    while (tmp != nullptr) //пока не пройдем все элементы
    {
        cout << tmp->key << " "; //выводим их
        tmp = tmp->pr; //берем указатель на соседний элемент
    }
}
//удаление из стека всех узлов
template <class T> void Stack<T>::Clear()
{
    while (head != nullptr) //пока в стеке есть элементы
    {
        Node *tmp = head;//указатель на первый элемент
        head = head->pr;//переприсваеваем: первым элементом становится соседний
        delete tmp; //предыдущий удаляем
    }
}
//деструктор
template <class T>Stack<T>::~Stack()
{
    Clear(); //удаление из стека всех узлов
}
//помещение объекта в стек
template <class T>void Stack<T>::Push(const T &k)
{
    Node *node = new Node{ k, head }; //создаем новый узел со значением k, указывающим на верхний элемент стека
    head = node; //присваиваем вершину к новому узлу
    size++; //увеличиваем размер
}

//удаление объекта из стека и возвращение его значения
template <class T> const T Stack<T>::Pop()
{
    if (head == nullptr) //если стек пуст
    {
        throw EStackEmpty(); //вызываем исключение
    }
    const T k = head->key; //получаем значения которое удалится (запомнили значение вершины)
    Node *tmp = head; //указатель на вершину
    head = head->pr; //присваиваем вершине следующее значение
    delete tmp; //удаляем соседний узел
    size--; //уменьшаем размер стека
    return k; //возвращаем значение
}
#endif // STACK_H
