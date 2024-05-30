#ifndef __COMMON_CONCURRNET_IRUN_H__
#define __COMMON_CONCURRNET_IRUN_H__

class IRun
{
public:
    virtual ~IRun(){};

protected:
    virtual void Run()=0;
};

#endif /* __COMMON_CONCURRNET_IRUNNABLE_H__ */