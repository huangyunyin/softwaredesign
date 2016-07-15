#pragma once
#include "resource.h"
#include "afxwin.h"
#include "User.h"
#include "afxdtctl.h"

// ManagerPaymentFunc 对话框

class ManagerPaymentFunc : public CDialogEx
{
	DECLARE_DYNAMIC(ManagerPaymentFunc)

public:
	ManagerPaymentFunc(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ManagerPaymentFunc();
    virtual BOOL OnInitDialog();

// 对话框数据
	enum { IDD = IDD_FORMVIEW15 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
    CComboBox select_user;
    afx_msg void OnBnClickedButton1();
    User currentSelect;
    afx_msg void OnBnClickedButton2();
    CDateTimeCtrl m_date;
};
