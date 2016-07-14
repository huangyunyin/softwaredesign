#pragma once
#include "resource.h"
#include "afxcmn.h"
#include <list>
#include "Message.h"

// MyComplaintFunc �Ի���

class MyComplaintFunc : public CDialogEx
{
	DECLARE_DYNAMIC(MyComplaintFunc)

public:
	MyComplaintFunc(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~MyComplaintFunc();
    virtual BOOL OnInitDialog();

// �Ի�������
	enum { IDD = IDD_FORMVIEW5 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
    CListCtrl list_control;
    afx_msg void OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult);

private:
    std::list<Message> complaint_list;
};
