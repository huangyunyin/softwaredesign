#pragma once
#include "resource.h"
#include "afxcmn.h"
#include <list>
#include "Message.h"

// CheckPublicFunc �Ի���

class CheckPublicFunc : public CDialogEx
{
	DECLARE_DYNAMIC(CheckPublicFunc)

public:
	CheckPublicFunc(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CheckPublicFunc();
    virtual BOOL OnInitDialog();

// �Ի�������
	enum { IDD = IDD_FORMVIEW7 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
    CListCtrl list_control;
    afx_msg void OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult);

private:
    std::list<Message> public_list;
};
