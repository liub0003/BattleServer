
#include "Config.h"
#include "Ini.h"
#include "Log.h"
#include "FileDef.h"

Config g_Config ;

Config::Config( )
{
__ENTER_FUNCTION


__LEAVE_FUNCTION
}

Config::~Config( )
{
__ENTER_FUNCTION


__LEAVE_FUNCTION
}

BOOL Config::Init( )
{
__ENTER_FUNCTION

	LoadConfigInfo( ) ;

	return TRUE ;

__LEAVE_FUNCTION

	return FALSE ;
}

VOID Config::ReLoad( )
{
	LoadConfigInfo_ReLoad( ) ;
}

VOID Config::LoadConfigInfo( )
{
__ENTER_FUNCTION

	LoadConfigInfo_Only( ) ;
	LoadConfigInfo_ReLoad( ) ;

__LEAVE_FUNCTION
}
VOID Config::LoadConfigInfo_Only( )
{//不能被重复读取的数据
__ENTER_FUNCTION

	Ini ini( FILE_CONFIG_INFO ) ;

	m_ConfigInfo.m_SystemModel = ini.ReadInt( "SystemModel", "SystemModel" ) ;
	m_ConfigInfo.m_ServerID = (ID_t)(ini.ReadInt( "System", "ServerId" )) ;
	m_ConfigInfo.m_ZoneSize = ini.ReadInt( "Zone", "ZoneSize" ) ;
	m_ConfigInfo.m_MaxPortal = ini.ReadInt( "Portal", "MaxCount" ) ;
	m_ConfigInfo.m_MaxSkillObj = ini.ReadInt( "SkillObj", "MaxCount" ) ;
	m_ConfigInfo.m_MaxPlatform = ini.ReadInt( "Platform", "MaxCount" );
	m_ConfigInfo.m_MaxSpecial = ini.ReadInt( "SpecialObj", "MaxCount" );
	m_ConfigInfo.m_MaxPlayerShopNum = ini.ReadInt( "PlayerShop", "MaxCount" );
	m_ConfigInfo.m_MaxTimerCount = ini.ReadInt("SceneTimer","MaxCount");
	m_ConfigInfo.m_nMaxHumanUseTimer = ini.ReadInt("HumanTimer","MaxCount");

	Log::SaveLog( CONFIG_LOGFILE, "Load ConfigInfo.ini ...Only OK! " ) ;

__LEAVE_FUNCTION
}
VOID Config::LoadConfigInfo_ReLoad( )
{//可以重复读取的数据
__ENTER_FUNCTION

	Ini ini( FILE_CONFIG_INFO ) ;
	CHAR	szText[32];

	ini.ReadText( "Global", "DropParam", szText, sizeof( szText ) -1 ) ;
	m_ConfigInfo.m_DropParam = (FLOAT)(atof( szText ));

	ini.ReadText( "Global", "ExpParam", szText, sizeof( szText ) -1 ) ;
	m_ConfigInfo.m_ExpParam = (FLOAT)(atof( szText ));
	m_ConfigInfo.m_EquipmentDamagePoint = ini.ReadInt( "Global", "EquipmentDamagePoint" ) ;

	m_ConfigInfo.m_RecoverTime = ini.ReadInt( "TimeSetting", "RecoverTime" ) ;
	m_ConfigInfo.m_MaxMonster = ini.ReadInt( "Monster", "MaxCount" ) ;
	m_ConfigInfo.m_MaxPet = ini.ReadInt( "Pet", "MaxCount" ) ;
	m_ConfigInfo.m_PetBodyTime = ini.ReadInt( "Pet", "PetBodyTime" ) ;
	m_ConfigInfo.m_PetHappinessInterval = ini.ReadInt( "Pet", "PetHappinessInterval" );
	m_ConfigInfo.m_PetLifeInterval = ini.ReadInt( "Pet", "PetLifeInterval" );
	m_ConfigInfo.m_PetCallUpHappiness = ini.ReadInt( "Pet", "PetCallUpHappiness" );
	m_ConfigInfo.m_PetPlacardTime = (UINT)(ini.ReadInt( "Pet", "PetPlacardTime" ));
	m_ConfigInfo.m_PetPlacardNeedLevel = ini.ReadInt( "Pet", "PetPlacardNeedLevel" );
	m_ConfigInfo.m_PetPlacardNeedHappiness = ini.ReadInt( "Pet", "PetPlacardNeedHappiness" );
	m_ConfigInfo.m_PetPlacardNeedLife = ini.ReadInt( "Pet", "PetPlacardNeedLife" );
	m_ConfigInfo.m_DefaultRespawnTime = ini.ReadInt( "Monster", "DefaultRespawnTime" ) ;
	m_ConfigInfo.m_DropBoxRecycleTime = ini.ReadInt("TimeSetting","DropBoxRecycle");
	m_ConfigInfo.m_TimeChangeInterval	= ini.ReadInt("TimeSetting","TimeChangeInterval");
	m_ConfigInfo.m_PositionRange = ini.ReadInt( "Monster", "DefaultPositionRange" ) ;
	m_ConfigInfo.m_AIType = ini.ReadInt( "Monster", "DefaultAIType" ) ;
	m_ConfigInfo.m_DisconnectTime = ini.ReadInt( "TimeSetting", "DisconnectTime" ) ;
	ini.ReadText( "Temp", "UserPath", m_ConfigInfo.m_UserPath, _MAX_PATH ) ;
	m_ConfigInfo.m_DefaultBodyTime = ini.ReadInt( "Monster", "DefaultBodyTime" ) ;
	m_ConfigInfo.m_DefaultRefuseScanTime = ini.ReadInt( "Monster", "DefaultRefuseScanTime");
	m_ConfigInfo.m_OutGhostTime = ini.ReadInt( "Human", "OutGhostTime" ) ;
	m_ConfigInfo.m_CanGetExpRange = (FLOAT)(ini.ReadInt( "Human", "CanGetExpRange" ));
	m_ConfigInfo.m_DefaultMoveSpeed = ini.ReadInt( "Human", "DefaultMoveSpeed" ) ;
	m_ConfigInfo.m_DefaultAttackSpeed = ini.ReadInt( "Human", "DefaultAttackSpeed" ) ;
	m_ConfigInfo.m_HumanVERecoverInterval = ini.ReadInt( "Human", "HumanVERecoverInterval" ) ;
	m_ConfigInfo.m_WallowAge = ini.ReadInt( "Human", "WallowAge" ) ;
	m_ConfigInfo.m_WallowStartTime = ini.ReadInt( "Human", "WallowStartTime" ) ;
	m_ConfigInfo.m_WallowStartTime2 = ini.ReadInt( "Human", "WallowStartTime2" ) ;
	m_ConfigInfo.m_WallowAwokeTime = ini.ReadInt( "Human", "WallowAwokeTime" ) ;
	m_ConfigInfo.m_nAvailableFollowDist = ini.ReadInt( "Team", "AvailableFollowDist" );
	m_ConfigInfo.m_nTimeForLoseFollow = ini.ReadInt( "Team", "TimeForLoseFollow" );
	m_ConfigInfo.m_nFoundDurationHour = ini.ReadInt( "Guild", "FoundDuration" );
	m_ConfigInfo.m_nDefaultMaxMemberCount = ini.ReadInt( "Guild", "DefaultMaxMemberCount" );
	m_ConfigInfo.m_nResponseUserCount = ini.ReadInt( "Guild", "ResponseUserCount" );
	m_ConfigInfo.m_nPasswdPoint = ini.ReadInt( "Relation", "PasswdPoint" );
	m_ConfigInfo.m_nPromptPoint = ini.ReadInt( "Relation", "PromptPoint" );
	m_ConfigInfo.m_nDeleteDelayTime = ini.ReadInt( "MinorPassword", "DeleteDelayTime" );
	m_ConfigInfo.m_nDeleteDelayTime *= 3600;
	m_ConfigInfo.m_nExpPoint = ini.ReadInt( "Relation", "ExpPoint" );
	//m_ConfigInfo.m_DefaultRefreshRate	=	ini.ReadInt("Obj_Human","DefaultRefreshRate")	;
	m_ConfigInfo.m_nHashOnlineUserCount = ini.ReadInt( "World", "HashOnlineUserCount" );
	m_ConfigInfo.m_nHashMailUserCount = ini.ReadInt( "World", "HashMailUserCount" );
	m_ConfigInfo.m_nMaxOfflineUserCount = ini.ReadInt( "World", "MaxOfflineUserCount" );
	ini.ReadText( "Global", "RespawnParam", szText, sizeof(szText)-1 ) ;
	m_ConfigInfo.m_fRespawnParam = (FLOAT)(atof(szText)) ;
	m_ConfigInfo.m_KickUserTime = ini.ReadInt( "TimeSetting", "KickUserTime" );
	m_ConfigInfo.m_nDefaultDamageFluctuation = ini.ReadInt("Combat","DefaultDamageFluctuation");

	m_ConfigInfo.m_nMinGoodBadValue = ini.ReadInt( "GoodBad", "MinGoodBadValue" );
	m_ConfigInfo.m_nMaxGoodBadValue = ini.ReadInt( "GoodBad", "MaxGoodBadValue" );
	m_ConfigInfo.m_nLevelNeeded = ini.ReadInt( "GoodBad", "LevelNeeded" );
	m_ConfigInfo.m_nMemberLevel = ini.ReadInt( "GoodBad", "MemberLevel" );
	m_ConfigInfo.m_fGoodBadRadius = (FLOAT)ini.ReadInt( "GoodBad", "GoodBadRadius" );
	m_ConfigInfo.m_nBonusPerMember = ini.ReadInt( "GoodBad", "BonusPerMember" );
	m_ConfigInfo.m_nMaxBonus = ini.ReadInt( "GoodBad", "MaxBonus" );
	m_ConfigInfo.m_nPenaltyWhenMemberDie = ini.ReadInt( "GoodBad", "PenaltyWhenMemberDie" );
	m_ConfigInfo.m_nWorldChatItemIndex = ini.ReadInt("WorldChat","ItemIndex");

	m_ConfigInfo.m_ThisRegion.m_nRegionIndex = ini.ReadInt("ThisRegion","RegionIndex");
	ini.ReadText( "ThisRegion", "RegionName", m_ConfigInfo.m_ThisRegion.m_RegionName, _MAX_PATH ) ;

	m_ConfigInfo.m_nOldRegionCount = ini.ReadInt("OldRegion","RegionCount");
	if( m_ConfigInfo.m_nOldRegionCount > 0 )
	{
		m_ConfigInfo.m_OldRegion = new _REGION_INFO[m_ConfigInfo.m_nOldRegionCount];
		for( INT i = 0; i < m_ConfigInfo.m_nOldRegionCount; i ++ )
		{
			CHAR szRegionIndex[100];
			CHAR szRegionName[100];
			tsnprintf( szRegionIndex, 99, "RegionIndex%03d", i+1 );
			tsnprintf( szRegionName, 99, "RegionName%03d", i+1 );
			m_ConfigInfo.m_OldRegion[i].m_nRegionIndex = ini.ReadInt( "OldRegion", szRegionIndex ) ;
			ini.ReadText( "OldRegion", szRegionName, m_ConfigInfo.m_OldRegion[i].m_RegionName, _MAX_PATH ) ;
		}
	}

	Log::SaveLog( CONFIG_LOGFILE, "Load ConfigInfo.ini ...ReLoad OK! " ) ;

__LEAVE_FUNCTION
}



