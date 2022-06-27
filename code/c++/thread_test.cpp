#include<iostream>
#include<thread>
#include<mutex>
#include<queue>
#include<condition_variable>
#include <unistd.h>
#include<string>
#include<vector>
#include<list>
#include <chrono>
#include <future>

using namespace std;

class Test_thread{

public:

struct CacheData
{
	int id;
	string data;
};

queue<CacheData> Q;
const int MAX_CACHEDATA_LENGTH = 10;
mutex m;
int ID ;
condition_variable condConsumer;
condition_variable condProducer;

public:
	Test_thread():ID(1)
	{
	    
	};
	~Test_thread()
	{
	    
	};
	void ConsumerActor();
	void ProducerActor();

};


void Test_thread::ConsumerActor()
{
	unique_lock<mutex> lockerConsumer(m);
	cout << "[" << this_thread::get_id() << "] 获取了锁" << endl; 
	while (Q.empty())
	{
		cout << "[" << this_thread::get_id() << "] 不再持有锁" << endl;
		//消费者停止，等待生产者唤醒 
		condConsumer.wait(lockerConsumer);
		cout << "[" << this_thread::get_id() << "] Weak, 重新获取了锁" << endl; 
	}
	cout << "[" << this_thread::get_id() << "] "; 
	CacheData temp = Q.front();
	cout << "- ID:" << temp.id << " Data:" << temp.data << endl;
	Q.pop(); 
	condProducer.notify_one();
	cout << "[" << this_thread::get_id() << "] 释放了锁" << endl; 
}

//生产者动作 
void Test_thread::ProducerActor()
{
	unique_lock<mutex> lockerProducer(m);
	cout << "[" << this_thread::get_id() << "] 获取了锁" << endl; 
	while (Q.size() > MAX_CACHEDATA_LENGTH)
	{
		cout << "[" << this_thread::get_id() << "] 不再持有锁" << endl; 
		//生产者停止，等待消费者唤醒 
		condProducer.wait(lockerProducer);
		cout << "[" << this_thread::get_id() << "] Weak, 重新获取了锁" << endl; 
	}
	cout << "[" << this_thread::get_id() << "] "; 
	CacheData temp;
	temp.id = ID++;
	temp.data = "*****";
	cout << "+ ID:" << temp.id << " Data:" << temp.data << endl; 
	Q.push(temp);
	condConsumer.notify_one();
	cout << "[" << this_thread::get_id() << "] 释放了锁" << endl; 
}



 
class A
{
public:
    void inMsgRecvQueue()
    {
        for (int i = 0; i < 100; i++)
        {
            cout << "inMsgRecvQueue()执行，插入一个元素" << i << endl;
            { 
                std::unique_lock<std::mutex> my_guard(my_mutex, std::try_to_lock);
                if (my_guard.owns_lock())
                {
                    //lock 
                    msgRecvQueue.push_back(i); 
                    //...others
                }
                else
                {
                    //others
                    cout << "没拿到锁" << i << endl;
                }
            }
        }
    }
 
    bool outMsgLULProc(int &command)
    {
        my_mutex.lock();//要先lock(),后续才能用unique_lock的std::adopt_lock参数
        std::unique_lock<std::mutex> my_guard(my_mutex, std::adopt_lock);
 
        std::chrono::milliseconds dura(2);
        std::this_thread::sleep_for(dura); 
 
        if (!msgRecvQueue.empty())
        {
            //消息不为空
            int command = msgRecvQueue.front();//返回第一个元素;
            msgRecvQueue.pop_front();//移除第一个元素;
            
            return true;
        }
        return false;
    }
    //把数据从消息队列取出的线程
    void outMsgRecvQueue()
    {
        int command = 0;
        for (int i = 0; i < 100; i++)
        {
            bool result = outMsgLULProc(command);
 
            if (result == true)
            {
                cout << "outMsgRecvQueue()执行，取出一个元素" << endl;
                //处理数据
            }
            else
            {
                //empty 
                cout << "inMsgRecvQueue()执行，但目前消息队列中为空！" << i << endl;
            }
        }
        cout << "end!" << endl;
    }
 
private:
    std::list<int> msgRecvQueue;//容器（消息队列）
    std::mutex my_mutex;//创建一个互斥量（一把锁）
};

/////////////////////////std::async////////////////////////////////////////////////

int GetFromDB(int recvData) {
 
	std::cout << "GetFromDB start" << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));
	return  recvData;
}
int test_async_1() {
  
    std::cout << " start" << std::this_thread::get_id() << std::endl;
    std::future<int> resultFromDB = std::async(std::launch::async, GetFromDB, 5);
    int dbData = resultFromDB.get();
    if (dbData == 5){
	    std::cout << "right..." << std::endl;     
    }else{
	    std::cout << "wrong..." << std::endl;       
    }
    return 0;
} 
 





