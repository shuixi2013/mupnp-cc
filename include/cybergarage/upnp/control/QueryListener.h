<<<<<<< HEAD
/******************************************************************
*
*	CyberLink for C++
*
*	Copyright (C) Satoshi Konno 2002-2003
*
*	File: QueryListener.h
*
*	Revision;
*
*	07/11/03
*		- first revision
*
******************************************************************/

#ifndef _CLINK_QUERYLISTENER_H_
#define _CLINK_QUERYLISTENER_H_

#include <string>

namespace CyberLink {

class StateVariable;

class QueryListener
{
public:
	virtual bool queryControlReceived(StateVariable *stateVar) = 0;
};

}

#endif
=======
/******************************************************************
*
*	CyberLink for C++
*
*	Copyright (C) Satoshi Konno 2002-2003
*
*	File: QueryListener.h
*
*	Revision;
*
*	07/11/03
*		- first revision
*
******************************************************************/

#ifndef _CLINK_QUERYLISTENER_H_
#define _CLINK_QUERYLISTENER_H_

#include <string>

namespace CyberLink {

class StateVariable;

class QueryListener
{
public:
	virtual bool queryControlReceived(StateVariable *stateVar) = 0;
};

}

#endif
>>>>>>> a1a830b7f4caaeafd5c2db44ad78fbb5b9f304b2
