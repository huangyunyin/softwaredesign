#pragma once
#include "resource.h"
#include "afxcmn.h"

// ManagerSeepaymnetFunc �Ի���

class ManagerSeepaymnetFunc : public CDialogEx
{
	DECLARE_DYNAMIC(ManagerSeepaymnetFunc)

public:
	ManagerSeepaymnetFunc(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ManagerSeepaymnetFunc();
    virtual BOOL OnInitDialog();

// �Ի�������
	enum { IDD = IDD_FORMVIEW16 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
    CListCtrl list_control;
};
