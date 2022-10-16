#ifndef STACK_H
#define STACK_H
#include "estackexception.h"
#include "estackempty.h"
#include <functional>

template <class T>
class Stack
{
public:
    ~Stack(); //деструктор
    int Size(); //размерность стека
    void Clear(); //удаление из стека всех узлов
    void Push(const T &k); //помещение объекта в стек
    const T Pop(); //извлечение объекта из стека
   void Print(std::function<void(const T &k)> f) const;//метод перебора значений

private:
    struct Node
    {
        const T key;
        Node *pr = nullptr;
    };
    Node *nd = nullptr;
    int size = 0;
};
//метод перебора значений стека
template <class T>void Stack<T>::Print(std::function<void(const T &k)> f) const
{
    Node *tmp = nd; //указатель на последний элемент
    while (tmp != nullptr)
    {
        f(tmp->key); //вызов функции обратной связи
        tmp = tmp->pr; //указатель на предыдущий
    }
}
//размерность стека
template <class T> int Stack<T>::Size()
{
    return size; //размер стека
}
//удаление из стека всех узлов
template <class T> void Stack<T>::Clear()
{
    while (nd != nullptr) //пока в стеке есть элементы
    {
        Node *tmp = nd;
        nd = nd->pr;
        delete tmp; //удаляем узлы
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
    Node *node = new Node{ k, nd }; //создаем новый узел
    if (node == nullptr)
    {
        throw Exception("Память заполнена");
    }
    nd = node; //присваиваем вершину к новому узлу
    size++; //увеличиваем размер
}

//извлечение объекта из стека и возвращающий этот элемент
template <class T> const T Stack<T>::Pop()
{
    if (nd == nullptr) //если стек пуст
    {
        throw EStackEmpty(); //вызываем исключение
    }
    const T k = nd->key; //получаем значения которое удалится
    Node *tmp = nd; //запоминаем узел который будет удален
    nd = nd->pr; //присваиваем вершине следующее значение
    delete tmp; //удаляем предыдущий узел
    size--; //уменьшаем размер стека
    return k; //возвращаем значение
}
#endif // STACK_H
