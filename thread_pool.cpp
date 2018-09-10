
#include "thread_pool.h"

typedef struct tagThread
{
    pthread_t mTid;
    pthread_mutex_t mMutex;
    pthread_cond_t mCond;
    CThreadPool::DispatchFunc_t mFunc;
    void* mArg;
    CThreadPool* mParent;
}Thread_t;

CThreadPool::CThreadPool(int maxThreadNum)
{
    if(maxThreadNum <=0)
        m_nMaxNum = 2;

    m_nTotal = 0;
    m_nIndex = 0;
    m_nShutdown = 0;

    pthread_mutex_init(&m_cMainMutex, NULL);
    pthread_cond_init(&m_cIdleCond, NULL);
    pthread_cond_init(&m_cFullCond, NULL);
    pthread_cond_init(&m_cEmptyCond, NULL);

    m_ThreadList = (Thread_t**)malloc(sizeof(void*)*m_nMaxNum);
    memset(m_ThreadList, 0, sizeof(void*)*m_nMaxNum);
}

CThreadPool::~CThreadPool()
{
    pthread_mutex_lock(&m_cMainMutex);
    // 1. 等待全部线程空闲

    // 2. 设置退出标记

    // 3. 发送工作信号给线程

    // 4. 等待全部线程退出

    pthread_mutex_lock(&m_cMainMutex);
    // 5. 释放线程变量

}

int CThreadPool::dispatch(DispatchFunc_t func, void* arg)
{
    // 1. 等待空闲线程

    // 2. 创建线程

    // 3. 给线程分配任务
}

void* CThreadPool::wrapperFunc(void* arg)
{
    // 1. 循环等待处理任务

    // 2. 线程退出

}

int CThreadPool::saveThread(Thread_t* pTagThread)
{

}