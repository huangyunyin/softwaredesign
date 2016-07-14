#pragma once
#include "resource.h"
#include "afxcmn.h"
// ContactManagerFunc 对话框

class ContactManagerFunc : public CDialogEx
{
	DECLARE_DYNAMIC(ContactManagerFunc)

public:
	ContactManagerFunc(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ContactManagerFunc();
    virtual BOOL OnInitDialog();

// 对话框数据
	enum { IDD = IDD_FORMVIEW8 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
    CListCtrl list_control;
};
