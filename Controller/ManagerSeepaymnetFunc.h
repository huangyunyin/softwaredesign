#pragma once
#include "resource.h"
#include "afxcmn.h"

// ManagerSeepaymnetFunc 对话框

class ManagerSeepaymnetFunc : public CDialogEx
{
	DECLARE_DYNAMIC(ManagerSeepaymnetFunc)

public:
	ManagerSeepaymnetFunc(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ManagerSeepaymnetFunc();
    virtual BOOL OnInitDialog();

// 对话框数据
	enum { IDD = IDD_FORMVIEW16 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
    CListCtrl list_control;
};
