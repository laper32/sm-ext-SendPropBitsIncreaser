#include "extension.h"
#include <dt_send.h>
Extension g_Ext;
SMEXT_LINK(&g_Ext);

// We do not have to import JSON and Log4SM, because this is just a game patching.

ICvar* icvar = nullptr;
IGameConfig* g_pGameConf = nullptr;
CRC32_t* g_SendTableCRC = nullptr;

void ExpandSize(const char* key)
{
	SendProp* self = g_pGameConf->GetSendProp(key);
	if (!self)
	{
		smutils->LogError(myself, "%s not found.", key);
		return;
	}
	self->m_nBits = 32;
}

bool Extension::SDK_OnLoad(char* error, size_t maxlen, bool late)
{
	ConVar* sm_sendtables = g_pCVar->FindVar("sv_sendtables");
	if (!sm_sendtables)
	{
		smutils->LogError(myself, "sm_sendtables does not exist.");
		return false;
	}
	sm_sendtables->SetValue(true);

	char errmsg[256] = {};
	if (!gameconfs->LoadGameConfigFile("sendpropbitsincreaser.games", &g_pGameConf, errmsg, sizeof(errmsg)))
	{
		smutils->LogError(myself, "%s", errmsg);
		return false;
	}

	g_pGameConf->GetAddress("g_SendTableCRC", (void**)&g_SendTableCRC);
	
	ExpandSize("CCSPlayer::m_ArmorValue");
	ExpandSize("CCSPlayer::m_iAccount");
	ExpandSize("CBasePlayer::m_iHealth");
	ExpandSize("CBaseCombatWeapon::m_iClip1");
	ExpandSize("CBaseCombatWeapon::m_iClip2");
	ExpandSize("CBaseCombatWeapon::m_iPrimaryReserveAmmoCount");
	ExpandSize("CBaseCombatWeapon::m_iSecondaryReserveAmmoCount");
	ExpandSize("CBasePlayer::m_iAmmo");
	ExpandSize("CCSPlayer::m_iProgressBarDuration");

	if (g_SendTableCRC)
	{
		*g_SendTableCRC = 1337;
	}
	else
	{
		smutils->LogMessage(myself, "g_SendTableCRC is null.");
		return false;
	}
	
	return SDKExtension::SDK_OnLoad(error, maxlen, late);
}

void Extension::SDK_OnUnload()
{
	return SDKExtension::SDK_OnUnload();
}

bool Extension::SDK_OnMetamodLoad(ISmmAPI* ismm, char* error, size_t maxlen, bool late)
{
	GET_V_IFACE_CURRENT(GetEngineFactory, icvar, ICvar, CVAR_INTERFACE_VERSION);
	g_pCVar = icvar;
	return SDKExtension::SDK_OnMetamodLoad(ismm, error, maxlen, late);
}
