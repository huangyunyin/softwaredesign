#pragma once
#include "resource.h"
#include "User.h"
// PersonalMessageFunc �Ի���

class PersonalMessageFunc : public CDialogEx
{
	DECLARE_DYNAMIC(PersonalMessageFunc)

public:
    PersonalMessageFunc(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~PersonalMessageFunc();
    virtual BOOL OnInitDialog();

// �Ի�������
	enum { IDD = IDD_FORMVIEW };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

public:
    afx_msg void OnBnClickedButton1();

};
