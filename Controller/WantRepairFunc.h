#pragma once
#include "resource.h"
#include <list>
#include "Message.h"

// WantRepairFunc 对话框

class WantRepairFunc : public CDialogEx
{
	DECLARE_DYNAMIC(WantRepairFunc)

public:
	WantRepairFunc(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~WantRepairFunc();
    virtual BOOL OnInitDialog();

// 对话框数据
	enum { IDD = IDD_FORMVIEW2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedButton1();

private:
    std::list<Message> repair_list;
};
