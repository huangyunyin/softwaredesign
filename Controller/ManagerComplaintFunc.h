#pragma once
#include "resource.h"
#include "afxcmn.h"
#include <list>
#include "Message.h"

// ManagerComplaintFunc �Ի���

class ManagerComplaintFunc : public CDialogEx
{
	DECLARE_DYNAMIC(ManagerComplaintFunc)

public:
	ManagerComplaintFunc(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ManagerComplaintFunc();
    virtual BOOL OnInitDialog();

// �Ի�������
	enum { IDD = IDD_FORMVIEW14 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
    CListCtrl list_control;
    afx_msg void OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult);
    afx_msg void OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult);
    afx_msg void OnBnClickedButton1();
    CString strLangName;

private:
    std::list<Message> complaint_list;
};
