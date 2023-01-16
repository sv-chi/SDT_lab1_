#ifndef ESTACKEXCEPTION_H
#define ESTACKEXCEPTION_H
#include <cstring>

class Exception{
private:
    char* message;
public:
// конструктор
Exception(const char* arg_message)
{
    message = new char[strlen(arg_message) +1 ]; //выделяем память под сообщение и получаем его длину
    strcpy(message,arg_message); //сохраняем сообщение
}
// конструктор копирования
Exception(const Exception& arg)
{
    message = new char[strlen(arg.message) +1 ]; //выделяем память под сообщение и получаем его длину
    strcpy(message,arg.message); //сохраняем сообщение
}
// деструктор
~Exception()
{
    delete message;
}

    const char* what() const { return message; }
/*класс должен содержать публичный метод char* what(), возвращающий диагностическое сообщение*/
};
#endif // ESTACKEXCEPTION_H
