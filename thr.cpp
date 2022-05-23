#include <iostream> 
#include<thread>
using namespace std;
// Динамический массив совершенных чисел 
// Динамический массив чисел фибоначи
// длинyу массивов задает пользователь 
int fl(int i)
{
    if (i > 1)
        return i * fl(i - 1);/// n*(n-1)!
    if (i >=0)
        return 1;

}
class sov
{
    int* a;
public:
    void Sov(int n)
    {
        this->a = new int[n];
        int k = 0;
        int t = 0;
            for (int i = 2; i < 1000000000; i++)
            {
                k = 0;
                for (int j = 2; j <= i/2; j++)
                {
                    if (i % j == 0) 
                    {
                        k ++ ;
                        break;
                    }
                    
                }
                
                if (k==0)
                {
          
                    a[t] = i;
                    t++;
                }
                if (t==n)
                    break;
            }    
    
        cout << endl;
        this_thread::sleep_for(chrono::microseconds(200));
        for (int i = 0; i < n; i++)
        {
            cout <<endl<< "thread ID: "<<this_thread::get_id() << " " << "Prost number " << a[i] << endl;
            this_thread::sleep_for(chrono::microseconds(500));
        }
    }
    ~sov()
    {
        delete[] a;
    }
};
class fib
{
    int* d;
public:
    void Fib(int n)
    {
        this->d = new int[n];
        int a = 1;
        int b = 1;
        int c = 0;
        int z = 0;
        for (int i = 0; i < pow(10,10); i++)
        {
            c = a + b;
            a = b;
            b = c;
            d[z] = c;
            z++;
            if (z == n)
                break;
        }
        this_thread::sleep_for(chrono::microseconds(200));
        for (int i = 0; i < n; i++)
        {
            cout <<endl<<"thread ID: "<<this_thread::get_id() << " " << "Fibonachi number  " << d[i] << endl;
            this_thread::sleep_for(chrono::microseconds(500));
        }

    }
    ~fib()
    {
        delete[] d;
    }

};
class factorial
{
    int* c;
public:
    void Factorial(int n)
    {
        this->c = new int[n];
        for (int i = 0; i < n+1; i++)
        {
            c[i] = fl(i);
            
        }
        this_thread::sleep_for(chrono::microseconds(200));
        for (int i = 0; i < n; i++)
        {
            cout << endl << "thread ID: " << this_thread::get_id() << " " << "Factorial  " << c[i] << endl;
            this_thread::sleep_for(chrono::microseconds(500));
        }
    }
    ~factorial()
    {
        delete[] c;
    }

};
/*
5!=5*4! n!=n*(n-1)!
4!=4*3!
3!=3*2!

*/
int main()
{
    int n = 10;
    fib r;
    factorial c;
    thread thread1(&fib::Fib, r, n);
    sov v;
    thread thread2(&sov::Sov, v, n);
    thread thread3(&factorial::Factorial, c, n);
    thread1.join();
    thread2.join();
    thread3.join();
    return 0;
}
