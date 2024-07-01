#ifndef __MSG_Q_DATA__
#define __MSG_Q_DATA__


namespace comm {
namespace ipc {
namespace msgQ {

template <typename DATA>
struct SMsgQData
{
    long msgType;
    DATA data;
};

template <typename DATA>
class CMsgQData
{
public:
    CMsgQData(long MsgType, DATA Data)
    {
        m_Data.msgType = MsgType;
        m_Data.data = Data;
    }

    virtual ~CMsgQData()
    {

    }

    operator SMsgQData<DATA>() const
    {
        return m_Data;
    }

    SMsgQData<DATA>& GetData()
    {
        return m_Data;
    }


private:
    SMsgQData<DATA> m_Data;
};

}
}
}
#endif