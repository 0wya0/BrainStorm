#include <iostream>
#include "thread.h"
#include "tcpserver.h"
#include "myserver.h"
using namespace std;

int main()
{
    MyServer ms;
    ms.listen(8888);
    ms.start();
}
