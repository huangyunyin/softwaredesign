#pragma once
#include "resource.h"
#include "afxcmn.h"
#include <list>
#include "Message.h"

// MyComplaintFunc 对话框

class MyComplaintFunc : public CDialogEx
{
	DECLARE_DYNAMIC(MyComplaintFunc)

public:
	MyComplaintFunc(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~MyComplaintFunc();
    virtual BOOL OnInitDialog();

// 对话框数据
	enum { IDD = IDD_FORMVIEW5 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
    CListCtrl list_control;
    afx_msg void OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult);

private:
    std::list<Message> complaint_list;
};
