#pragma once
#include "resource.h"

// ManagerPersonalFunc �Ի���

class ManagerPersonalFunc : public CDialogEx
{
	DECLARE_DYNAMIC(ManagerPersonalFunc)

public:
	ManagerPersonalFunc(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ManagerPersonalFunc();
    virtual BOOL OnInitDialog();

// �Ի�������
	enum { IDD = IDD_FORMVIEW9 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedButton1();
};
