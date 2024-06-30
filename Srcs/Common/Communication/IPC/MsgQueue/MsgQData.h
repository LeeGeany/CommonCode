template <typename DATA>
struct SMsgQData
{
    long msgType;
    char data[sizeof(DATA)];
};

template <typename DATA>
class CMsgQData
{
public:
    CMsgQData(long MsgType, DATA Data)
    {
        m_Data.msgType = MsgType;
        &(m_Data.data) = std::move(reinterpret_cast<char*>(&Data));
    }

    virtual ~CMsgQData()
    {

    }

    operator SMsgQData()
    {
        return m_Data;
    }


private:
    SMsgQData<DATA> m_Data;
};