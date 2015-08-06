

#ifndef __CONFIG_H__
#define __CONFIG_H__

#include "Type.h"

struct _REGION_INFO
{
	INT				m_nRegionIndex;			//��Ϸ���������룬ֻ�ܴ�001�ŵ�420�ţ���
	CHAR			m_RegionName[_MAX_PATH];//������������
};

//Config
struct _CONFIG_INFO
{
	INT				m_SystemModel;
	ID_t			m_ServerID ;
	INT				m_ZoneSize ;
	FLOAT			m_DropParam;				//ȫ�ֵ�����������
	FLOAT			m_ExpParam;					//ȫ�־�����������
	INT				m_EquipmentDamagePoint;		//��Ʒ�;öȵ�΢��ֵ
	INT				m_RecoverTime ;
	INT				m_MaxMonster ;
	INT				m_MaxPet ;
	INT				m_PetBodyTime ;
	INT				m_PetHappinessInterval;		// ������ֶ��½�1��ʱ����(����)
	INT				m_PetLifeInterval;			// ���������½�1��ʱ����(����)
	INT				m_PetCallUpHappiness;		// ������ֶȴ��ڲſ����ٳ�
	UINT			m_PetPlacardTime;			// ����һ�����﹫��ĳ���ʱ��
	INT				m_PetPlacardNeedLevel;		// �������﹫��ĳ������輶��
	INT				m_PetPlacardNeedHappiness;	// �������﹫��ĳ���������ֶ�
	INT				m_PetPlacardNeedLife;		// �������﹫��ĳ�����������
	INT				m_DefaultRespawnTime ;
	INT				m_DropBoxRecycleTime;
	INT				m_TimeChangeInterval;		//ʱ��������
	INT				m_PositionRange ;
	INT				m_AIType ;
	INT				m_DisconnectTime ;
	CHAR			m_UserPath[_MAX_PATH] ;
	INT				m_MaxPortal ;
	INT				m_MaxSkillObj ;
	INT				m_DefaultBodyTime ;			//ʬ�����ʱ��
	INT				m_OutGhostTime ;			//�ͷ����ʱ��
	FLOAT			m_CanGetExpRange ;			//ɱ����ɫ����Եõ�EXP�ķ�Χ
	INT				m_DefaultMoveSpeed ;
	INT				m_DefaultAttackSpeed ;
	INT				m_HumanVERecoverInterval;	// ����������Ļָ�ʱ����(����)
	INT				m_WallowAge;
	INT				m_WallowStartTime;
	INT				m_WallowStartTime2;
	INT				m_WallowAwokeTime;
	INT				m_DefaultRefreshRate ;		//������ˢ��ʱ��
	INT				m_DefaultCheckZoneRate ;	//ˢ��������Ϣ��ʱ����
	INT				m_DefaultRefuseScanTime;	//ȱʡ���������󲻻�ɨ����˵�ʱ��
	INT				m_MaxPlatform;
	INT				m_MaxSpecial;				// ����OBJ������
	INT				m_MaxPlayerShopNum;			// ����̵������
	INT             m_MaxTimerCount;			//������ʱ����Ŀ
	INT				m_nMaxHumanUseTimer;		//Obj_Human��ʹ�ü�ʱ����Ŀ
	INT				m_nAvailableFollowDist;		// ��Ӹ������Ч����
	INT				m_nTimeForLoseFollow;		// ��Ӹ��泬����Ч����೤ʱ��������˳���Ӹ���(��)
	INT				m_nFoundDurationHour;		// ��������
	INT				m_nDefaultMaxMemberCount;	// Ĭ�ϰ�����ɰ�����
	INT				m_nResponseUserCount;		// ���������Ҫ����Ӧ���������������
	INT				m_nPasswdPoint;				// ���ٵ��Ѻö���Ҫ�����������
	INT				m_nPromptPoint;				// ���ٵ��Ѻö���Ҫ��ʾ������
	INT				m_nDeleteDelayTime;			// ����Сʱ�Ժ��ٴ�ǿ�ƽ����ɾ����������
	INT				m_nExpPoint;				// ��ö��پ�����������Ѻö�
	INT				m_nHashOnlineUserCount ;	//������ҵ�hash���С
	INT				m_nHashMailUserCount ;		//ӵ���ʼ������hash���С
	INT				m_nMaxOfflineUserCount ;	//��½����Ϸ������������ֵ
	FLOAT			m_fRespawnParam ;			//����ˢ������ϵ��
	INT				m_KickUserTime ;			//����������Ϸ��ҵ��߳�����ʱ��
	INT				m_nDefaultDamageFluctuation; // ȱʡ���˺�����

	INT				m_nMinGoodBadValue;			// ��С�ƶ�ֵ
	INT				m_nMaxGoodBadValue;			// ����ƶ�ֵ
	INT				m_nLevelNeeded;				// ����ƶ�ֵ����͵ȼ�
	INT				m_nMemberLevel;				// �ܸ��ӳ������ƶ�ֵ�Ķ�����ߵȼ�
	FLOAT			m_fGoodBadRadius;			// ����ƶ�ֵ�İ뾶
	INT				m_nBonusPerMember;			// ÿ����Ч���������ӵ��ƶ�ֵ����
	INT				m_nMaxBonus;				// ɱ��һֻ���ܸ��ӳ�����������ƶ�ֵ����
	INT				m_nPenaltyWhenMemberDie;	// ��Ч���ѵ��������ٶӳ����ƶ�ֵ����
	INT             m_nWorldChatItemIndex;

	_REGION_INFO	m_ThisRegion;				//��ǰ��Ϸ��
	_REGION_INFO*	m_OldRegion;				//����
	INT				m_nOldRegionCount;			//�����ĸ���

	_CONFIG_INFO( )
	{
		m_ServerID				= INVALID_ID ;
		m_ZoneSize				= 10 ;
		m_EquipmentDamagePoint	= 1000;
		m_RecoverTime			= 1000 ;
		m_MaxMonster			= 1000 ;
		m_MaxPet				= 1000 ;
		m_PetBodyTime			= 2000 ;
		m_PetHappinessInterval	= 600000;
		m_PetLifeInterval		= 30 * 60 * 1000;
		m_PetCallUpHappiness	= 60;
		m_PetPlacardTime		= 1000*60*30;
		m_DefaultRespawnTime	= 300000 ;
		m_DropBoxRecycleTime	= 300000 ;
		m_TimeChangeInterval	= 300000 ;
		m_PositionRange			= 10 ;
		m_AIType				= 1 ;
		m_DisconnectTime		= 0 ;
		memset( m_UserPath, 0, _MAX_PATH ) ;
		m_MaxPortal				= 0 ;
		m_MaxPlatform			= 0;
		m_MaxSpecial			= 1024;
		m_MaxPlayerShopNum		= 512;
		m_MaxSkillObj			= 1024;
		m_DefaultBodyTime		= 0 ;
		m_OutGhostTime			= 0 ;
		m_CanGetExpRange		= 30.f;
		m_DefaultMoveSpeed      = 2800 ;
		m_DefaultAttackSpeed    = 2000 ;
		m_HumanVERecoverInterval= 300000;
		m_DefaultRefreshRate    = 60000 ;
		m_DefaultCheckZoneRate  = 1000 ;
		m_nAvailableFollowDist	= 15;
		m_nTimeForLoseFollow	= 30;
		m_nFoundDurationHour	= 24;
		m_nDefaultMaxMemberCount= 160;
		m_nResponseUserCount	= 10;
		m_nPasswdPoint			= 0;
		m_nPromptPoint			= 0;
		m_nDeleteDelayTime		= 0;
		m_nExpPoint				= 0;
		m_nHashOnlineUserCount	= 1000 ;
		m_nHashMailUserCount	= 1000 ;
		m_nMaxOfflineUserCount	= 0 ;
		m_fRespawnParam			= 1.0f ;
		m_KickUserTime			= 300000 ;
		m_nDefaultDamageFluctuation = 10 ;

		m_nMinGoodBadValue		= 0;
		m_nMaxGoodBadValue		= 9999;
		m_nLevelNeeded			= 31;
		m_nMemberLevel			= 19;
		m_fGoodBadRadius		= 15.;
		m_nBonusPerMember		= 1;
		m_nMaxBonus				= 2;
		m_nPenaltyWhenMemberDie	= 10;

		m_nWorldChatItemIndex	= 0;

		m_nOldRegionCount		= 0;
		m_OldRegion				= NULL;

	};
	~_CONFIG_INFO( )
	{
		SAFE_DELETE(m_OldRegion);
	};
};





class Config
{
public :
	Config( ) ;
	~Config( ) ;

	BOOL					Init( ) ;
	VOID					ReLoad( ) ;


	VOID					LoadConfigInfo( ) ;
	VOID					LoadConfigInfo_Only( ) ;
	VOID					LoadConfigInfo_ReLoad( ) ;




public :
	_CONFIG_INFO			m_ConfigInfo ;

};


extern Config g_Config ;

#endif
