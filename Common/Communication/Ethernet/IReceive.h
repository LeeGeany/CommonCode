class IReceive 
{
public:
    virtual ~IReceive();

public:
    virtual int Receive()=0;
};