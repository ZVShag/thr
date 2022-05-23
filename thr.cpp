#include <iostream> 
#include<thread>
#include<mutex>
using namespace std;
mutex m1, m2;
// Динамический массив совершенных чисел 
// Динамический массив чисел фибоначи
// длинyу массивов задает пользователь 
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
            cout << "thread ID: "<<this_thread::get_id() << " " << "Prost number " << a[i] << endl;
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
            cout <<"thread ID: "<<this_thread::get_id() << " " << "Fibonachi number  " << d[i] << endl;
            this_thread::sleep_for(chrono::microseconds(500));
        }

    }
    ~fib()
    {
        delete[] d;
    }

};
int main()
{
    
    int n = 10;
    fib r;
    thread thread1(&fib::Fib, r, n);
    sov v;
    thread thread2(&sov::Sov, &v, n);
    //r.Print(n);
    //v.Print(n);
    thread1.join();
    thread2.join();
    return 0;
}
