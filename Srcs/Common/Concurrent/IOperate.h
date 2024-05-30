#ifndef __COMMON_CONCURRENT_IOPERATE_H__
#define __COMMON_CONCURRENT_IOPERATE_H__

class IOperate
{
public:
    virtual ~IOperate(){};

protected:
    virtual void PreStart()=0;
    virtual void OnStart()=0;
    virtual void PostStart()=0;
};

#endif /* __COMMON_CONCURRENT_IOPERATE_H__ */