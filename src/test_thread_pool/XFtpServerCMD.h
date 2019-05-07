#pragma once
#include "XTask.h"
class XFtpServerCMD :public XTask
{
public:
	//初始化任务
	virtual bool Init();
	XFtpServerCMD();
	~XFtpServerCMD();
};

