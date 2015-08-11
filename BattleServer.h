
#ifndef __BATTLESERVER_H__
#define __BATTLESERVER_H__

#include "Type.h"


class BattleServer
{
public:
	BattleServer();
	~BattleServer();



	BOOL		Init();
	BOOL		Loop();
	BOOL		Exit();


protected:
	BOOL		NewStaticManager();
	BOOL		InitStaticManager();
	BOOL		DelStaticManager();


};

extern BattleServer g_BattleServer;


#endif
