#pragma once
#include "resource.h"
#include <list>
#include "Message.h"

// ManagerAddpublicFunc 对话框

class ManagerAddpublicFunc : public CDialogEx
{
	DECLARE_DYNAMIC(ManagerAddpublicFunc)

public:
	ManagerAddpublicFunc(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ManagerAddpublicFunc();
    virtual BOOL OnInitDialog();

// 对话框数据
	enum { IDD = IDD_FORMVIEW18 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedButton1();

private:
    std::list<Message> public_list;
};
