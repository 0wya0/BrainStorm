#include <iostream>
#include "thread.h"
#include "tcpserver.h"
#include "myserver.h"
using namespace std;

int main()
{
    MyServer ms;
    ms.listen(6666);
    ms.start();
}
