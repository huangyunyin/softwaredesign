#pragma once
#include "resource.h"
#include "afxcmn.h"
#include <list>
#include "Message.h"

// CheckPublicFunc 对话框

class CheckPublicFunc : public CDialogEx
{
	DECLARE_DYNAMIC(CheckPublicFunc)

public:
	CheckPublicFunc(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CheckPublicFunc();
    virtual BOOL OnInitDialog();

// 对话框数据
	enum { IDD = IDD_FORMVIEW7 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
    CListCtrl list_control;
    afx_msg void OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult);

private:
    std::list<Message> public_list;
};
