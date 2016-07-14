#pragma once
#include "resource.h"
#include <list>
#include "Message.h"

// WantComplaintFunc 对话框

class WantComplaintFunc : public CDialogEx
{
	DECLARE_DYNAMIC(WantComplaintFunc)

public:
	WantComplaintFunc(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~WantComplaintFunc();
    virtual BOOL OnInitDialog();

// 对话框数据
	enum { IDD = IDD_FORMVIEW4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedButton1();
    
private:
    std::list<Message> complaint_list;
};
