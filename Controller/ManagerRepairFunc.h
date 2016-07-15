#pragma once
#include "resource.h"
#include "afxcmn.h"
#include <list>
#include "Message.h"

// ManagerRepairFunc 对话框

class ManagerRepairFunc : public CDialogEx
{
	DECLARE_DYNAMIC(ManagerRepairFunc)

public:
	ManagerRepairFunc(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ManagerRepairFunc();
    virtual BOOL OnInitDialog();

// 对话框数据
	enum { IDD = IDD_FORMVIEW13 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

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
