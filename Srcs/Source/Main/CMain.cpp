#include "Source/Main/CMain.h"

#include "Source/Data/SDataStruct.h"
#include "Source/Data/CMsg_IPCHeader.h"

namespace usr
{
    CMain::CMain()
    {

    }
    
    CMain::~CMain()
    {
        
    }

    void CMain::Initiate()
    {
        // Create Manager
        CApp::CreateDataMngr();

        CApp::getDataMngr().CreateData<msg::CMsg_IPCHeader>(static_cast<const unsigned int>(msg::MsgNo::IPC_HEADER));
    }
}