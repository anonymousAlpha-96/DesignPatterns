/****************************************************************
*   Problem: Singleton Design pattern                           *
*   Author:  https://github.com/anonymousAlpha-96               *
*   Date:    22.Aug.23                                          *
*   Note: C++11 onwards no need to put ctors in pvt developers  *
*         can use =delete; used infront of constructors.        *
*****************************************************************/

#include<iostream>
#include<thread>
#include<mutex>

using namespace std;

class Logger{
    Logger();   //ctor declared as private
    static int counter; 
    static Logger *LoggerInstance;  
    static mutex mt;
    Logger(const Logger &);
    Logger operator=(const Logger &);

public:
    void logDetails(string msg);
    static Logger *getLogger();
};

//static definations
int Logger::counter =0;
Logger* Logger::LoggerInstance = nullptr;
mutex Logger::mt;

//Logger class function definations
Logger::Logger()
{
    counter++;
    cout<<"Instance created : "<<counter<<endl;
}

void Logger::logDetails(string msg)
{
    cout<<msg<<endl;
}

Logger *Logger::getLogger()
{
    //double check for logger instance in the multiple thread senario
    if(LoggerInstance == nullptr)
    {
        mt.lock();
        if(LoggerInstance==nullptr)
        {
            LoggerInstance = new Logger();
        }
        mt.unlock();
    }
    return LoggerInstance;
}


//threads to execute the instances
void userOneThread()
{
    Logger *log = Logger::getLogger();
    log->logDetails("Singleton pattern created");

}
void userTwoThread()
{
    Logger *log1 = Logger::getLogger();
    log1->logDetails("Singleton pattern created twice ");
}

int main()
{
    thread t1(userOneThread);

    thread t2(userTwoThread);   
    t1.join();
    t2.join();
    
    return 0;
}