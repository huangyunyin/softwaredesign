#pragma once
#include "resource.h"
#include "User.h"
// PersonalMessageFunc 对话框

class PersonalMessageFunc : public CDialogEx
{
	DECLARE_DYNAMIC(PersonalMessageFunc)

public:
    PersonalMessageFunc(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~PersonalMessageFunc();
    virtual BOOL OnInitDialog();

// 对话框数据
	enum { IDD = IDD_FORMVIEW };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

public:
    afx_msg void OnBnClickedButton1();

};
