<<<<<<< HEAD
/******************************************************************
*
*	CyberLink for C++
*
*	Copyright (C) Satoshi Konno 2002-2003
*
*	File: Action.h
*
*	Revision;
*
*	07/08/03
*		- first revision
*
******************************************************************/

#ifndef _CLINK_ACTION_H_
#define _CLINK_ACTION_H_

#include <cybergarage/upnp/control/ActionRequest.h>
#include <cybergarage/upnp/control/ActionResponse.h>
#include <cybergarage/xml/Node.h>
#include <cybergarage/upnp/UPnPStatus.h>
#include <cybergarage/upnp/xml/ServiceData.h>
#include <cybergarage/upnp/xml/ActionData.h>
#include <cybergarage/upnp/ArgumentList.h>
#include <cybergarage/upnp/control/ActionListener.h>
#include <uhttp/util/Mutex.h>

#include <sstream>

namespace CyberLink {

class Service;

class Action
{
	CyberXML::Node *serviceNode;
	CyberXML::Node *actionNode;
	
	ArgumentList *argumentList;
	ArgumentList *argumentInList;
	ArgumentList *argumentOutList;

	UPnPStatus upnpStatus;

	uHTTP::Mutex mutex;

	////////////////////////////////////////////////
	//	Constants
	////////////////////////////////////////////////

public:

	static const char *ELEM_NAME;
	static const char *NAME;

	////////////////////////////////////////////////
	//	Member
	////////////////////////////////////////////////

private:

	CyberXML::Node *getServiceNode()
	{
		return serviceNode;
	}

public:

	Service *getService();
	
	CyberXML::Node *getActionNode()
	{
		return actionNode;
	}
	
	////////////////////////////////////////////////
	//	Constructor
	////////////////////////////////////////////////

	Action(CyberXML::Node *serviceNode, CyberXML::Node *actionNode);
	Action(Action *action);

	~Action();

	////////////////////////////////////////////////
	// Mutex
	////////////////////////////////////////////////
	
public:

	void lock()
	{
		mutex.lock();
	}
	
	void unlock()
	{
		mutex.unlock();
	}

	////////////////////////////////////////////////
	//	isActionNode
	////////////////////////////////////////////////

	static bool isActionNode(CyberXML::Node *node)
	{
		std::string nodeName = node->getName();
		if (nodeName.compare(Action::ELEM_NAME) == 0)
			return true;
		return false;
	}

	////////////////////////////////////////////////
	//	name
	////////////////////////////////////////////////

	void setName(const std::string &value)
	{
		getActionNode()->setNode(Action::NAME, value);
	}

	const char *getName()
	{
		return getActionNode()->getNodeValue(Action::NAME);
	}

	////////////////////////////////////////////////
	//	argumentList
	////////////////////////////////////////////////

private:

	void initArgumentList();
	void clearOutputAgumentValues();

public:

	ArgumentList *getArgumentList()
	{
		return argumentList;
	}

	ArgumentList *getInputArgumentList()
	{
		return argumentInList;
	}

	ArgumentList *getOutputArgumentList()
	{
		return argumentOutList;
	}

	Argument *getArgument(const std::string &name);
=======
/******************************************************************
*
*	CyberLink for C++
*
*	Copyright (C) Satoshi Konno 2002-2003
*
*	File: Action.h
*
*	Revision;
*
*	07/08/03
*		- first revision
*
******************************************************************/

#ifndef _CLINK_ACTION_H_
#define _CLINK_ACTION_H_

#include <cybergarage/upnp/control/ActionRequest.h>
#include <cybergarage/upnp/control/ActionResponse.h>
#include <cybergarage/xml/Node.h>
#include <cybergarage/upnp/UPnPStatus.h>
#include <cybergarage/upnp/xml/ServiceData.h>
#include <cybergarage/upnp/xml/ActionData.h>
#include <cybergarage/upnp/ArgumentList.h>
#include <cybergarage/upnp/control/ActionListener.h>
#include <cybergarage/util/Mutex.h>

#include <sstream>

namespace CyberLink {

class Service;

class Action
{
	CyberXML::Node *serviceNode;
	CyberXML::Node *actionNode;
	
	ArgumentList *argumentList;
	ArgumentList *argumentInList;
	ArgumentList *argumentOutList;

	UPnPStatus upnpStatus;

	CyberUtil::Mutex mutex;

	////////////////////////////////////////////////
	//	Constants
	////////////////////////////////////////////////

public:

	static const char *ELEM_NAME;
	static const char *NAME;

	////////////////////////////////////////////////
	//	Member
	////////////////////////////////////////////////

private:

	CyberXML::Node *getServiceNode()
	{
		return serviceNode;
	}

public:

	Service *getService();
	
	CyberXML::Node *getActionNode()
	{
		return actionNode;
	}
	
	////////////////////////////////////////////////
	//	Constructor
	////////////////////////////////////////////////

	Action(CyberXML::Node *serviceNode, CyberXML::Node *actionNode);
	Action(Action *action);

	~Action();

	////////////////////////////////////////////////
	// Mutex
	////////////////////////////////////////////////
	
public:

	void lock()
	{
		mutex.lock();
	}
	
	void unlock()
	{
		mutex.unlock();
	}

	////////////////////////////////////////////////
	//	isActionNode
	////////////////////////////////////////////////

	static bool isActionNode(CyberXML::Node *node)
	{
		std::string nodeName = node->getName();
		if (nodeName.compare(Action::ELEM_NAME) == 0)
			return true;
		return false;
	}

	////////////////////////////////////////////////
	//	name
	////////////////////////////////////////////////

	void setName(const char *value)
	{
		getActionNode()->setNode(Action::NAME, value);
	}

	const char *getName()
	{
		return getActionNode()->getNodeValue(Action::NAME);
	}

	////////////////////////////////////////////////
	//	argumentList
	////////////////////////////////////////////////

private:

	void initArgumentList();
	void clearOutputAgumentValues();

public:

	ArgumentList *getArgumentList()
	{
		return argumentList;
	}

	ArgumentList *getInputArgumentList()
	{
		return argumentInList;
	}

	ArgumentList *getOutputArgumentList()
	{
		return argumentOutList;
	}

	Argument *getArgument(const char *name);
>>>>>>> a1a830b7f4caaeafd5c2db44ad78fbb5b9f304b2

	void setArgumentValues(ArgumentList *argList)
	{
		getArgumentList()->set(argList);
	}
	
<<<<<<< HEAD
	void setArgumentValue(const std::string &name, const std::string &value)
=======
	void setArgumentValue(const char *name, const char *value)
>>>>>>> a1a830b7f4caaeafd5c2db44ad78fbb5b9f304b2
	{
		Argument *arg = getArgument(name);
		if (arg == NULL)
			return;
		arg->setValue(value);
	}
<<<<<<< HEAD

	void setArgumentValue(const std::string &name, int value)
	{
		Argument *arg = getArgument(name);
		if (arg == NULL)
			return;
		arg->setValue(value);
	}

	const char *getArgumentValue(const std::string &name)
	{
		Argument *arg = getArgument(name);
		if (arg == NULL)
			return "";
		return arg->getValue();
	}

	int getArgumentIntegerValue(const std::string &name)
	{
		Argument *arg = getArgument(name);
		if (arg == NULL)
			return 0;
		return arg->getIntegerValue();
	}
=======

	void setArgumentValue(const char *name, int value)
	{
		Argument *arg = getArgument(name);
		if (arg == NULL)
			return;
		arg->setValue(value);
	}

	const char *getArgumentValue(const char *name)
	{
		Argument *arg = getArgument(name);
		if (arg == NULL)
			return "";
		return arg->getValue();
	}

	int getArgumentIntegerValue(const char *name)
	{
		Argument *arg = getArgument(name);
		if (arg == NULL)
			return 0;
		return arg->getIntegerValue();
	}
>>>>>>> a1a830b7f4caaeafd5c2db44ad78fbb5b9f304b2
	
	////////////////////////////////////////////////
	//	UserData
	////////////////////////////////////////////////

	ActionData *getActionData()
	{
		CyberXML::Node *node = getActionNode();
		ActionData *userData = (ActionData *)node->getUserData();
		if (userData == NULL) {
			userData = new ActionData();
<<<<<<< HEAD
			node->setUserData(userData);
=======
			node->setUserData(userData);
>>>>>>> a1a830b7f4caaeafd5c2db44ad78fbb5b9f304b2
		}
		return userData;
	}
	
	////////////////////////////////////////////////
	//	controlAction
	////////////////////////////////////////////////

	ActionListener *getActionListener() 
	{
		return getActionData()->getActionListener();
	}

	void setActionListener(ActionListener *listener) 
	{
		getActionData()->setActionListener(listener);
	}
<<<<<<< HEAD

	bool performActionListener(ActionRequest *actionReq);

=======

	bool performActionListener(ActionRequest *actionReq);

>>>>>>> a1a830b7f4caaeafd5c2db44ad78fbb5b9f304b2
	////////////////////////////////////////////////
	//	ActionControl
	////////////////////////////////////////////////

	ControlResponse *getControlResponse() 
	{
		return getActionData()->getControlResponse();
	}

	void setControlResponse(ControlResponse *res) 
	{
		getActionData()->setControlResponse(res);
	}
<<<<<<< HEAD
	
	UPnPStatus *getControlStatus()
	{
		return getControlResponse()->getUPnPError();
	}

	////////////////////////////////////////////////
	//	postControlAction
	////////////////////////////////////////////////

public:

	bool postControlAction();

	////////////////////////////////////////////////
	//	UPnPStatus
	////////////////////////////////////////////////

public:

	void setStatus(int code, const std::string &descr)
	{
		upnpStatus.setCode(code);
		upnpStatus.setDescription(descr);
	}

	void setStatus(int code)
	{
		setStatus(code, UPnP::StatusCode2String(code));
	}
	
	UPnPStatus *getStatus()
	{
		return &upnpStatus;
	}

};

}

#endif
=======
	
	UPnPStatus *getControlStatus()
	{
		return getControlResponse()->getUPnPError();
	}

	////////////////////////////////////////////////
	//	postControlAction
	////////////////////////////////////////////////

public:

	bool postControlAction();

	////////////////////////////////////////////////
	//	UPnPStatus
	////////////////////////////////////////////////

public:

	void setStatus(int code, const char *descr)
	{
		upnpStatus.setCode(code);
		upnpStatus.setDescription(descr);
	}

	void setStatus(int code)
	{
		setStatus(code, UPnP::StatusCode2String(code));
	}
	
	UPnPStatus *getStatus()
	{
		return &upnpStatus;
	}

};

}

#endif
>>>>>>> a1a830b7f4caaeafd5c2db44ad78fbb5b9f304b2

