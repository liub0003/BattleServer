// BattleServer.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "TimeManager.h"
#include "Log.h"
#include "BattleServer.h"
#include "ExceptionHandler.h"
#include "Config.h"

#if __LINUX__
#include <sys/signal.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <errno.h>
#endif

BattleServer g_BattleServer;



int _tmain(int argc, _TCHAR* argv[])
{
#if defined(__WINDOWS__)
	_CrtSetDbgFlag(_CrtSetDbgFlag(0) | _CRTDBG_LEAK_CHECK_DF);
#endif

	__ENTER_FUNCTION

	//int* a = new int[10];
	//if (argc > 1)
	//{
	//	for (int i = 1; i < argc; i++)
	//	{
	//		if (strcmp(argv[i], "-ignoreassert") == 0)
	//		{
	//			g_Command_Assert = 1;
	//		}
	//		if (strcmp(argv[i], "-retryassert") == 0)
	//		{
	//			g_Command_Assert = 2;
	//		}
	//		else if (strcmp(argv[i], "-ignoremessagebox") == 0)
	//		{
	//			g_Command_IgnoreMessageBox = TRUE;
	//		}
	//	}
	//}

	//BOOL bRet;

	////时间模块需要最开始的时候设置
	//g_pTimeManager = new TimeManager;
	//Assert(g_pTimeManager);
	//g_pTimeManager->Init();

	////信号处理初始化
	//g_ExceptionHandler.Init();

	//Log::SaveLog(BATTLESERVER_LOGFILE, "(###) main...");
	//Log::SaveLog(BATTLESERVER_LOGFILE, "BattleServer Start... ");

	//bRet = g_BattleServer.Init();
	//if (bRet == FALSE)
	//{
	//	Assert(FALSE);
	//	return 1;
	//}

	//bRet = g_BattleServer.Loop();
	//if (bRet == FALSE)
	//{
	//	Assert(FALSE);
	//	return 1;
	//}

	//bRet = g_BattleServer.Exit();
	//if (bRet == FALSE)
	//{
	//	Assert(FALSE);
	//	return 1;
	//}


	__LEAVE_FUNCTION

		return 0;
	return 0;
}

BattleServer::BattleServer()
{
	__ENTER_FUNCTION

#if defined(__WINDOWS__)
		WORD wVersionRequested;
	WSADATA wsaData;
	int err;
	wVersionRequested = MAKEWORD(2, 2);
	err = WSAStartup(wVersionRequested, &wsaData);
#endif


	__LEAVE_FUNCTION
}

BattleServer::~BattleServer()
{
	__ENTER_FUNCTION

#if defined(__WINDOWS__)
		WSACleanup();
#endif

	__LEAVE_FUNCTION
}


BOOL BattleServer::Init()
{
	__ENTER_FUNCTION

		BOOL bRet;

	Log::SaveLog(BATTLESERVER_LOGFILE, "Start Read Config Files...");
	bRet = g_Config.Init();
	Assert(bRet);
	Log::SaveLog(BATTLESERVER_LOGFILE, "Read Config Files...OK!");

	Log::SaveLog(BATTLESERVER_LOGFILE, "Start New Managers...");
	bRet = NewStaticManager();
	Assert(bRet);
	Log::SaveLog(BATTLESERVER_LOGFILE, "New Managers...OK!");

	Log::SaveLog(BATTLESERVER_LOGFILE, "Start Init Managers...");
	bRet = InitStaticManager();
	Assert(bRet);
	Log::SaveLog(BATTLESERVER_LOGFILE, "Init Managers...OK!");

	return TRUE;

	__LEAVE_FUNCTION

		return FALSE;
}

BOOL BattleServer::Loop()
{
	__ENTER_FUNCTION

		Log::SaveLog(BATTLESERVER_LOGFILE, "Loop...");
	//g_pServerManager->Loop();

	__LEAVE_FUNCTION

		return TRUE;
}

BOOL BattleServer::Exit()
{
	__ENTER_FUNCTION

		BOOL bRet;

	Log::SaveLog(BATTLESERVER_LOGFILE, "Start Exit...");
	bRet = DelStaticManager();
	Assert(bRet);
	Log::SaveLog(BATTLESERVER_LOGFILE, "Exit...OK!");


	__LEAVE_FUNCTION

		return TRUE;
}

BOOL BattleServer::NewStaticManager()
{
	__ENTER_FUNCTION

	//初始化分配内存


	__LEAVE_FUNCTION

		return TRUE;
}

BOOL BattleServer::InitStaticManager()
{
	__ENTER_FUNCTION

	BOOL ret;

	//ret = g_TableInit.Init();
	//Assert(ret);
	//Log::SaveLog(BATTLESERVER_LOGFILE, "g_TableInit.Init()...OK!");

	////
	//ret = g_pServerManager->Init();
	//Assert(ret);
	//Log::SaveLog(BATTLESERVER_LOGFILE, "g_pServerManager->Init()...OK");

	////
	////________________________________________________________
	//if (g_Config.m_ConfigInfo.m_SystemModel == 0)
	//{
	//	nTemp = 10;
	//}
	//else
	//{
	//	nTemp = MAX_POOL_SIZE;
	//}


	return TRUE;

	__LEAVE_FUNCTION

		return FALSE;
}

BOOL BattleServer::DelStaticManager()
{
	__ENTER_FUNCTION


	SAFE_DELETE(g_pTimeManager);
	Log::SaveLog(BATTLESERVER_LOGFILE, "g_pTimeManager delete...OK");


	__LEAVE_FUNCTION

		return TRUE;
}

