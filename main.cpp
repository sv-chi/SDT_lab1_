#include <QCoreApplication>
#include "stack.h"
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <locale.h>

using namespace std;

int main()
{
 Stack<int> st;
for(int i = 0;i<10;i++)
{
    st.Push(i);
}
st.Pop();
cout<<st.Size()<<endl;
    return 0;
}
