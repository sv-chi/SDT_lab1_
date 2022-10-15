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
    message = new char[strlen(arg_message) +1 ];
    strcpy(message,arg_message);
}
// конструктор копирования
Exception(const Exception& arg)
{
    message = new char[strlen(arg.message) +1 ];
    strcpy(message,arg.message);
}
// деструктор
~Exception()
{
    delete message;
}

    const char* what() const { return message; }
};
#endif // ESTACKEXCEPTION_H
