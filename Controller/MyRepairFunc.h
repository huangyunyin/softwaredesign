#pragma once
#include "resource.h"
#include "afxcmn.h"
#include <list>
#include "Message.h"

// MyRepairFunc 对话框

class MyRepairFunc : public CDialogEx
{
	DECLARE_DYNAMIC(MyRepairFunc)

public:
	MyRepairFunc(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~MyRepairFunc();
    virtual BOOL OnInitDialog();

// 对话框数据
	enum { IDD = IDD_FORMVIEW3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
    CListCtrl programLangList;
    afx_msg void OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult);

private:
    std::list<Message> repair_list;
};
