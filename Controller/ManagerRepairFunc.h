#pragma once
#include "resource.h"
#include "afxcmn.h"
#include <list>
#include "Message.h"

// ManagerRepairFunc �Ի���

class ManagerRepairFunc : public CDialogEx
{
	DECLARE_DYNAMIC(ManagerRepairFunc)

public:
	ManagerRepairFunc(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ManagerRepairFunc();
    virtual BOOL OnInitDialog();

// �Ի�������
	enum { IDD = IDD_FORMVIEW13 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

public:
    CString strLangName;
    afx_msg void OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult);
    afx_msg void OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult);
    afx_msg void OnBnClickedButton1();
    CListCtrl list_control;

private:
    std::list<Message> repair_list;
};
