#pragma once
#include "resource.h"

// ChangePasswordFunc �Ի���

class ChangePasswordFunc : public CDialogEx
{
	DECLARE_DYNAMIC(ChangePasswordFunc)

public:
	ChangePasswordFunc(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ChangePasswordFunc();
    virtual BOOL OnInitDialog();
    bool isRightType(char ch);

// �Ի�������
	enum { IDD = IDD_FORMVIEW1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedButton1();
};
