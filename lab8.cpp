#include <iostream>
#include <thread>
#include <time.h>
#include <pthread.h>

using namespace std;

long long int Counter = 0;

void summ()
{
for(int i = 0; i < 10000; i++){
Counter +=1;
}
}

int main()
{

thread th1(summ);
thread th2(summ);
thread th3(summ);
thread th4(summ);
th1.detach();
th2.detach();
th3.detach();
th4.detach();
cout << Counter <<endl;
}
