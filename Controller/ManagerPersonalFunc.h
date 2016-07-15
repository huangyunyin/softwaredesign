#pragma once
#include "resource.h"

// ManagerPersonalFunc 对话框

class ManagerPersonalFunc : public CDialogEx
{
	DECLARE_DYNAMIC(ManagerPersonalFunc)

public:
	ManagerPersonalFunc(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ManagerPersonalFunc();
    virtual BOOL OnInitDialog();

// 对话框数据
	enum { IDD = IDD_FORMVIEW9 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedButton1();
};
