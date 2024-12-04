#include <thread>
#include <iostream>
#include <mutex>
#include <string>
#include <cmath>

std::mutex m;

void Func(std::string name)
{
    const auto start = std::chrono::steady_clock::now();
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> seconds = (end - start);
    long double i = 0;
    while(seconds.count() <= 1)
    {
    end = std::chrono::steady_clock::now();
    seconds = (end - start); 
    i += pow(10, -9);
    }
    
    m.lock();
    std::cout << name << ": " << i << std::endl;
    m.unlock();

}

int main()
{
    std::thread thread1(Func, "t1");
    std::thread thread2(Func, "t2");
    std::thread thread3(Func, "t3");
    thread1.join();
    thread2.join();
    thread3.join();

}
