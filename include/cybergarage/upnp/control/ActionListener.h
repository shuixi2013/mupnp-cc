<<<<<<< HEAD
/******************************************************************
*
*	CyberLink for C++
*
*	Copyright (C) Satoshi Konno 2002-2003
*
*	File: ActionListener.h
*
*	Revision;
*
*	07/11/03
*		- first revision
*
******************************************************************/

#ifndef _CLINK_ACTIONLISTENER_H_
#define _CLINK_ACTIONLISTENER_H_

//#include <cybergarage/upnp/Action.h>

namespace CyberLink {

class Action;

class ActionListener
{
public:
	virtual bool actionControlReceived(Action *action) = 0;
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
*	File: ActionListener.h
*
*	Revision;
*
*	07/11/03
*		- first revision
*
******************************************************************/

#ifndef _CLINK_ACTIONLISTENER_H_
#define _CLINK_ACTIONLISTENER_H_

//#include <cybergarage/upnp/Action.h>

namespace CyberLink {

class Action;

class ActionListener
{
public:
	virtual bool actionControlReceived(Action *action) = 0;
};

}

#endif

>>>>>>> a1a830b7f4caaeafd5c2db44ad78fbb5b9f304b2
