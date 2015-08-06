#include "Type.h"
#include "GameUtil.h"

#ifdef __LINUX__
#include <execinfo.h>
#include <signal.h>
#include <exception>
#include <setjmp.h>
#endif

INT					g_LockTimes=0 ;
BOOL				g_LockTimeOutEnable=FALSE;


VOID	sm_lock(CHAR& flag,CHAR type)
{
	bgsm_loop:
	if(flag==SM_FREE)
	{
		flag=type;
		if(flag!=type)
		{
			MySleep(1);
#ifdef __LINUX__
			g_LockTimes ++ ;
			printf("lock fail %s,%d,%s",__FILE__,__LINE__,__PRETTY_FUNCTION__);
#endif
			if((g_LockTimes>100)&&g_LockTimeOutEnable)
			{
				g_LockTimes =0;
				return;
			}
			goto bgsm_loop;
		}
		return;
	}
	else
	{
		MySleep(1);
		goto	bgsm_loop;
	}
}



VOID	sm_unlock(CHAR& flag,CHAR type)
{
	edsm_loop:
		
		if(flag==SM_FREE)
		{
			return;
		}
		
		flag=SM_FREE;
	
		if(flag!=SM_FREE)
		{
			MySleep(1);
#ifdef __LINUX__
			printf("unlock fail %s,%s,%s",__FILE__,__LINE__,__PRETTY_FUNCTION__);
			if((g_LockTimes>100)&&g_LockTimeOutEnable)
			{
				g_LockTimes =0;
				return;
			}
#endif
			goto edsm_loop;
		}
		return;
	
}

BOOL sm_trylock(CHAR& flag,CHAR type)
{
	INT LockTimes;

bgsm_loop:

	if(flag==SM_FREE)
	{
		flag=type;
		if(flag!=type)
		{
			LockTimes++;
			MySleep(1);
			if(LockTimes>10)
			{
				return FALSE;
			}
			goto bgsm_loop;
		}
		return TRUE;
	}
	else
	{
		LockTimes++;
		MySleep(1);
		if(LockTimes>10)
		{
			return FALSE;
		}
		goto	bgsm_loop;
	}
}




VOID MySleep( UINT millionseconds )
{
#if defined(__WINDOWS__)
	Sleep( millionseconds ) ;
#elif defined(__LINUX__)
	usleep( millionseconds*1000 ) ;
#endif
}

TID MyGetCurrentThreadID( )
{
#if defined(__WINDOWS__)
	return GetCurrentThreadId( ) ;
#elif defined(__LINUX__)
	return pthread_self();
#endif
}


CHAR* MySocketError( )
{
#ifndef _ESIZE
#define _ESIZE 256
#endif

extern CHAR Error[_ESIZE] ;
	return Error ;
}


CHAR		Value2Ascii(CHAR in)
{
	__ENTER_FUNCTION
		switch(in) 
		{
			case 0:
				return '0';
				break;
			case 1:
				return '1';
			case 2:
				return '2';
				break;
			case 3:
				return '3';
				break;
			case 4:
				return '4';
				break;
			case 5:
				return '5';
				break;
			case 6:
				return '6';
				break;
			case 7:
				return '7';
				break;
			case 8:
				return '8';
				break;
			case 9:
				return '9';
				break;
			case 10:
				return 'A';
				break;
			case 11:
				return 'B';
				break;
			case 12:
				return 'C';
				break;
			case 13:
				return 'D';
				break;
			case 14:
				return 'E';
				break;
			case 15:
				return 'F';
				break;
			default:
				Assert(FALSE);
				return '?';
				break;
		}

	__LEAVE_FUNCTION

		return '?';
}

CHAR Ascii2Value(CHAR in)
{
	__ENTER_FUNCTION
		switch(in) 
	{
		case '0':
			return 0;
			break;
		case '1':
			return 1;
		case '2':
			return 2;
			break;
		case '3':
			return 3;
			break;
		case '4':
			return 4;
			break;
		case '5':
			return 5;
			break;
		case '6':
			return 6;
			break;
		case '7':
			return 7;
			break;
		case '8':
			return 8;
			break;
		case '9':
			return 9;
			break;
		case 'A':
			return 10;
			break;
		case 'B':
			return 11;
			break;
		case 'C':
			return 12;
			break;
		case 'D':
			return 13;
			break;
		case 'E':
			return 14;
			break;
		case 'F':
			return 15;
			break;
		default:
			Assert(FALSE);
			return '?';
			break;
	}

	__LEAVE_FUNCTION

		return '?';
}


BOOL	Binary2String(const CHAR* pIn,UINT InLength,CHAR* pOut)
{
	__ENTER_FUNCTION

		if(InLength==0)
		{
			return FALSE;
		}
		UINT iOut = 0;

		
		for(UINT i = 0 ;i<InLength;i++)
		{
			
			pOut[iOut] = Value2Ascii(((unsigned char)pIn[i]&0xF0)>>4);
			iOut++;
			pOut[iOut] = Value2Ascii(pIn[i]&0x0F);
			iOut++;
		

		}
		return TRUE;

		__LEAVE_FUNCTION

			return FALSE;
}

BOOL DBStr2Binary(const CHAR* pIn,UINT InLength,CHAR* pOut,UINT OutLimit,UINT& OutLength)
{
	__ENTER_FUNCTION

		if(InLength==0)
		{
			return FALSE;
		}

		UINT iOut = 0;
		UINT i;
		for( i = 0 ;i<InLength-1;)
		{
			if(pIn[i]=='\0'||pIn[i+1]=='\0')
			{
				break;
			}
			
			pOut[iOut]	=	(Ascii2Value(pIn[i])<<4) + Ascii2Value(pIn[i+1]);
			iOut++;
			i+=2;
			if(iOut>=OutLimit)
				break;
		}
		OutLength = iOut;
		return TRUE;
		__LEAVE_FUNCTION
		return FALSE;
}


BOOL String2Binary(const CHAR* pIn,UINT InLength,CHAR* pOut,UINT OutLimit,UINT& OutLength)
{
	__ENTER_FUNCTION

		if(InLength==0)
		{
			return FALSE;
		}

		UINT iOut = 0;
		UINT i;
		for( i = 0 ;i<InLength-1;)
		{
			if((pIn[i]=='\\') && (pIn[i+1]=='0'))
			{
				pOut[iOut]	=	'\0';
				iOut++;
				i+=2;
				continue;
			}
			else if((pIn[i]=='\'') && (pIn[i+1]=='\''))
			{
			pOut[iOut]	=	'\'';
			iOut++;
			i+=2;
			continue;
			}
			else if((pIn[i]=='\\') && (pIn[i+1]=='\"'))
			{
				pOut[iOut]	=	'\"';
				iOut++;
				i+=2;
				continue;
			}
			else if((pIn[i]=='\\') && (pIn[i+1]=='\\'))
			{
				pOut[iOut]	=	'\\';
				iOut++;
				i+=2;
				continue;
			}
			else if(pIn[i]=='\0')
			{
				break;
			}

			pOut[iOut] = pIn[i];
			iOut++;
			i++;

			if(iOut>=OutLimit)
				break;
		}
		OutLength = iOut;
		return TRUE;

		__LEAVE_FUNCTION
}

BOOL		StrSafeCheck(const CHAR* pIn,UINT InLength)
{
	if(InLength==0)
	{
		return FALSE;
	}
	for(UINT i = 0 ;i<InLength;i++)
	{
		switch(pIn[i]) 
		{
			case '\0':
				{
					return TRUE;
					break;
				}
			case '\'':
			case '\"':
			case ')':
			case '(':
			case '=':
			case '%':
				{
					return FALSE;
				}
		}
	}

	return TRUE;

}

BOOL		CommandSafeCheck(const CHAR* pIn,UINT InLength)
{
	if(InLength==0)
	{
		return FALSE;
	}
	for(UINT i = 0 ;i<InLength;i++)
	{
		switch(pIn[i]) 
		{
		case '\0':
			{
				return TRUE;
				break;
			}
		case '%':
			{
				return FALSE;
			}
		}
	}

	return TRUE;

}


CHAR* ReplaceIllegalString( CHAR* strText, INT nLength, INT nLevel )
{
	if( strText == NULL ) return NULL;
	INT i;
	for( i = 0; i < nLength; i ++ )
	{
		if( strText[i] == '%' ) strText[i] = '?';
		if( strText[i] == '\0' ) break;
	}

	return strText;
}

BOOL CheckIllegalString( const CHAR* strText, INT nLength, INT nLevel )
{
	if( strText == NULL ) return FALSE;
	INT i;
	if( nLevel == CHECK_STRING_NORMAL )
	{
		for( i = 0; i < nLength; i ++ )
		{
			if( strText[i] == '%' ) return TRUE;
			if( strText[i] == '\0' ) return FALSE;
		}
	}
	else if( nLevel == CHECK_STRING_CHARNAME )
	{
		for( i = 0; i < nLength; i ++ )
		{
			switch( strText[i] )
			{
			case ' ':
			case '#':
			case '\\':
			case '/':
			case '`':
			case '~':
			case '!':
			case '@':
			case '$':
			case '%':
			case '^':
			case '&':
			case '*':
			case '(':
			case ')':
			case '-':
			case '_':
			case '+':
			case '|':
			case '{':
			case '}':
			case '[':
			case ']':
			case ';':
			case ':':
			case '\'':
			case '\"':
			case '<':
			case '>':
			case ',':
			case '.':
			case '?':
			case '0xA1':
				return TRUE;
			}
			if( strText[i] == '\0' ) return FALSE;
		}
	}
	return FALSE;
}

#if defined (__BATTLESERVER__) 
#define DUMP_LOG	"./Log/battle_dump.log"
#endif


VOID  DumpStack(const CHAR* type)
{
#ifdef __LINUX__
	void *	DumpArray[25];
	int	Size =	backtrace(DumpArray,25);
	char ** symbols = backtrace_symbols(DumpArray, Size);
	if(symbols)
	{
		if(Size>10) Size= 10;
		if(Size>0)
		{
			FILE* f = fopen( DUMP_LOG, "a" ) ;
			char threadinfo[256] = {0};
			sprintf(threadinfo,"threadid = %d cause dump\r\n",MyGetCurrentThreadID());
			fwrite(threadinfo,1,strlen(threadinfo),f);
			fwrite(type,1,strlen(type),f);
			for(int	i=0;i<Size;i++)
			{
				printf("%s\r\n",symbols[i]);
				fwrite(symbols[i],1,strlen(symbols[i]),f);
				fwrite("\r\n",1,2,f);
			}
			fclose(f) ;
		}
		free(symbols);
	}
	else
	{
		FILE* f = fopen( DUMP_LOG, "a" ) ;
		char	buffer[256] = {0};
		char threadinfo[256] = {0};
		sprintf(threadinfo,"threadid = %d cause dump\r\n",MyGetCurrentThreadID());
		fwrite(threadinfo,1,strlen(threadinfo),f);
		fwrite(type,1,strlen(type),f);
		fclose(f);
	}
#endif
}

