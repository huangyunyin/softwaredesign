#pragma once
#include "resource.h"
#include "afxcmn.h"
// ContactManagerFunc �Ի���

class ContactManagerFunc : public CDialogEx
{
	DECLARE_DYNAMIC(ContactManagerFunc)

public:
	ContactManagerFunc(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ContactManagerFunc();
    virtual BOOL OnInitDialog();

// �Ի�������
	enum { IDD = IDD_FORMVIEW8 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
    CListCtrl list_control;
};
