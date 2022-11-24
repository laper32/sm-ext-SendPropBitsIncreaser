#ifndef _INCLUDE_SOURCEMOD_EXTENSION_PROPER_H_
#define _INCLUDE_SOURCEMOD_EXTENSION_PROPER_H_

#include "smsdk_ext.h"

class Extension : public SDKExtension
{
public:
	virtual bool SDK_OnLoad(char *error, size_t maxlen, bool late);
	virtual void SDK_OnUnload();
	virtual bool SDK_OnMetamodLoad(ISmmAPI* ismm, char* error, size_t maxlen, bool late);
};

extern ICvar* icvar;
extern IGameConfig* g_pGameConf;
extern CRC32_t* g_SendTableCRC;

#endif // _INCLUDE_SOURCEMOD_EXTENSION_PROPER_H_
