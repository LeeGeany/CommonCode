/**
 * @file    CEthernetManager.h
 * @author  jinhee.lee
 * @date    2025.03.23
 * @brief   Class of Ethernet Manager Header
 * 
 * @copyright jinhee.lee
 */

#ifndef __APP_MANAGER_ETHERNET_CETHERNETMANAGER_H__
#define __APP_MANAGER_ETHERNET_CETHERNETMANAGER_H__

#include "Common/Common.h"
#include "Common/Communication/Ethernet/TCP/CTCPServer.h"
#include "Common/Communication/Ethernet/TCP/CTCPClient.h"

class CEthernetManager
{
public:
    CEthernetManager();
    virtual ~CEthernetManager();

public:
    /**
     * @brief 
     */
    void Initiate();

    /**
     * @brief 
     * 
     * @tparam T 
     * @param _serverName 
     * @param _localPort 
     * @return true 
     * @return false 
     */
    template<typename T>
    bool CreateTCPServer(std::string _serverName, const short _localPort)
    {
        bool ret = true;
        auto item = m_ServerMap.find(_serverName);
    
        if(item != m_ServerMap.end())
        {
            ret = false;
        }
        else
        {
            if(std::is_base_of_v<comm::eth::tcp::CTCPServer, T> == true)
            {
                std::unique_ptr<T> tEthernet = std::make_unique<T>(_localPort);

                m_ServerMap[_serverName] = tEthernet.release();
            }
            else
            {
                ret = false;
            }
        }
        return ret;
    }

    /**
     * @brief 
     * 
     * @tparam T 
     * @param _destIP 
     * @param _DestPort 
     * @return true 
     * @return false 
     */
    template<typename T>
    bool CreateTCPClient(std::string _clientName, const char * _destIP, const short _DestPort)
    {
        bool ret = true;
        auto item = m_ClientMap.find(_clientName);
    
        if(item != m_ClientMap.end())
        {
            ret = false;
        }
        else
        {
            if(std::is_base_of_v<comm::eth::tcp::CTCPClient, T> == true)
            {
                std::unique_ptr<T> tEthernet = std::make_unique<T>(_destIP, _DestPort);

                m_ClientMap[_clientName] = tEthernet.release();
            }
            else
            {
                ret = false;
            }
        }
        return ret;
    }

private:
    std::unordered_map<std::string,  comm::eth::tcp::CTCPServer*> m_ServerMap;
    std::unordered_map<std::string,  comm::eth::tcp::CTCPClient*> m_ClientMap;

}; /* class CEthernetManager */
 #endif /* __APP_MANAGER_ETHERNET_CETHERNETMANAGER_H__ */