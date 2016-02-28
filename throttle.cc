//Throttle Example
using namespace std;
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <iostream>
#include <unistd.h>
#include "time.h"
#include "sys/time.h"

class Request
{
    public:
     Request(int id, string header, string body) : id_(id), header_(header), body_(body)
     {
     }
    private:
     int id_;
     string header_;
     string body_;
};

template <typename T>
class Queue
{
 public:

  Queue()
  {
      head_ = 0;
      tail_ = 0;
  }
  T pop()
  {
    std::unique_lock<std::mutex> mlock(mutex_);
    while (queue_.empty())
    {
      cond_.wait(mlock);
    }
    auto item = queue_.front();
    queue_.pop();
    return item;
  }

  void pop(T& item)
  {
    std::unique_lock<std::mutex> mlock(mutex_);
    while (queue_.empty())
    {
      cond_.wait(mlock);
    }
    item = queue_.front();
    queue_.pop();
  }

  void push(const T& item)
  {
    std::unique_lock<std::mutex> mlock(mutex_);
    queue_.push(item);
    mlock.unlock();
    cond_.notify_one();
  }

  void push(T&& item)
  {
    std::unique_lock<std::mutex> mlock(mutex_);
    queue_.push(std::move(item));
    mlock.unlock();
    cond_.notify_one();
  }
  
  int size()
  {
      return int(queue_.size());
  }
  
  bool isEmpty()
  {
      return bool(queue_.empty());
  }

 private:
  std::queue<T> queue_;
  std::mutex mutex_;
  std::condition_variable cond_;
  int head_;
  int tail_;
};

class Timer
{
    public:
     static long long get_time_ms()
     {
        struct timeval t;
        gettimeofday(&t, NULL);
        return (long long)((t.tv_sec + (t.tv_usec / 1000000.0)) * 1000.0);    
     }
};

class LeakyBucket
{
    public:
     LeakyBucket(int maxRate) : maxRate_(maxRate)
     {
         this->minTime_ = (long)(10.0f / ((float) maxRate_));
         this->lastSchedAction_ = (long long) Timer::get_time_ms();
     }
     const int getMaxRate()
     {
         return maxRate_;
     }
     const long getMinTime()
     {
         return minTime_;   
     }
     const long long getLastSchedAction()
     {
         return lastSchedAction_;
     }
     void consume()
     {
         long long curTime = Timer::get_time_ms();
         long long timeLeft;
         
         timeLeft = lastSchedAction_ + minTime_ - curTime;
         if(timeLeft > 0) 
         {
             lastSchedAction_ += minTime_;
         }
         else 
         {
             lastSchedAction_ = curTime;
         }
         if(timeLeft <= 0) 
         {
            return;
         }
         else 
         {
             //std::cerr << "Time Left = " << timeLeft << std::endl;
             sleep(timeLeft);
         }
         return;
     }
    private:
     int maxRate_;
     long minTime_;
     long long lastSchedAction_;
     
};

int main()
{
    //std::cerr << "Hello, world!\n";
    Queue<int> queue;
    const int MAXQUEUESIZE = 10;
    const int MAXFLOWRATE = 2;
    for(int iCnt = 0; iCnt < MAXQUEUESIZE; iCnt++)
    {
        queue.push(iCnt+1);
    }
    
    std::cerr << "Size of Queue = " << queue.size() << std::endl;
    LeakyBucket leakyBucket = LeakyBucket(MAXFLOWRATE);
    std::cerr << "Time : " << Timer::get_time_ms() << std::endl;    
    while(queue.isEmpty() == false)
    {
        for(int iCnt = 0; iCnt < MAXFLOWRATE; iCnt++)    
        {
            if(queue.isEmpty() == false)
            {
                std::cerr << "Fetched value :" << queue.pop() << std::endl;
            }
            else
            {
                break;
            }
        }
        leakyBucket.consume();
        //std::cerr << "Fetching next set !!" << std::endl;
        std::cerr << "Time : " << Timer::get_time_ms() << std::endl;
    }
    std::cerr << "Done with fetching all values !!" << std::endl;
    //std::cerr << "Maximum Rate :" << leakybucket.getMaxRate() << std::endl;
    //std::cerr << "Minimum Time :" << leakybucket.getMinTime() << std::endl;
    //std::cerr << "Last Scheduled Action :" << leakybucket.getLastSchedAction() << std::endl;
    return 0;
}