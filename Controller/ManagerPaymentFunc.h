#pragma once
#include "resource.h"
#include "afxwin.h"
#include "User.h"
#include "afxdtctl.h"

// ManagerPaymentFunc �Ի���

class ManagerPaymentFunc : public CDialogEx
{
	DECLARE_DYNAMIC(ManagerPaymentFunc)

public:
	ManagerPaymentFunc(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ManagerPaymentFunc();
    virtual BOOL OnInitDialog();

// �Ի�������
	enum { IDD = IDD_FORMVIEW15 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
    CComboBox select_user;
    afx_msg void OnBnClickedButton1();
    User currentSelect;
    afx_msg void OnBnClickedButton2();
    CDateTimeCtrl m_date;
};
