#pragma once
#include "resource.h"
#include "afxcmn.h"
#include <list>
#include "Message.h"

// ManagerSeepublicFunc 对话框

class ManagerSeepublicFunc : public CDialogEx
{
	DECLARE_DYNAMIC(ManagerSeepublicFunc)

public:
	ManagerSeepublicFunc(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ManagerSeepublicFunc();
    virtual BOOL OnInitDialog();

// 对话框数据
	enum { IDD = IDD_FORMVIEW17 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
    CListCtrl list_control;
    afx_msg void OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult);
    afx_msg void OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult);
    afx_msg void OnBnClickedButton1();
    CString strLangName;

private:
    std::list<Message> public_list;
};
