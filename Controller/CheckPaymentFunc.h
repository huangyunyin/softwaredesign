#pragma once
#include "resource.h"
#include "afxcmn.h"

// CheckPaymentFunc �Ի���

class CheckPaymentFunc : public CDialogEx
{
	DECLARE_DYNAMIC(CheckPaymentFunc)

public:
	CheckPaymentFunc(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CheckPaymentFunc();
    virtual BOOL OnInitDialog();

// �Ի�������
	enum { IDD = IDD_FORMVIEW6 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
    CListCtrl list_control;
};
