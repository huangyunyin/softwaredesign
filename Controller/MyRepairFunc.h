#pragma once
#include "resource.h"
#include "afxcmn.h"
#include <list>
#include "Message.h"

// MyRepairFunc �Ի���

class MyRepairFunc : public CDialogEx
{
	DECLARE_DYNAMIC(MyRepairFunc)

public:
	MyRepairFunc(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~MyRepairFunc();
    virtual BOOL OnInitDialog();

// �Ի�������
	enum { IDD = IDD_FORMVIEW3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
    CListCtrl programLangList;
    afx_msg void OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult);

private:
    std::list<Message> repair_list;
};
