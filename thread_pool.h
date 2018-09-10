#ifndef __THREAD_POOL_H__
#define __THREAD_POOL_H__
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

typedef struct tagThread Thread_t;
class CThreadPool
{
public:
    typedef void (*DispatchFunc_t) (void*);
    CThreadPool(int maxThreadNum);
    ~CThreadPool();

    int dispatch(DispatchFunc_t func, void* arg);

    static void* wrapperFunc(void* arg);
    int saveThread(Thread_t* pTagThread);
private:
    int m_nTotal;  // 运行线程
    int m_nIndex;  // 可分配任务线程
    int m_nShutdown;  // 停止开关
    int m_nMaxNum;  // 线程池最大线程数

    pthread_mutex_t m_cMainMutex;  
    pthread_cond_t  m_cIdleCond;   // 有空闲线程
    pthread_cond_t  m_cFullCond;   // 全部空闲
    phtread_cond_t  m_cEmptyCond;  // 全部退出

    Thread_t** m_ThreadList;
};

#endif