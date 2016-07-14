#pragma once
#include "resource.h"

// ChangePasswordFunc 对话框

class ChangePasswordFunc : public CDialogEx
{
	DECLARE_DYNAMIC(ChangePasswordFunc)

public:
	ChangePasswordFunc(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ChangePasswordFunc();
    virtual BOOL OnInitDialog();
    bool isRightType(char ch);

// 对话框数据
	enum { IDD = IDD_FORMVIEW1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedButton1();
};
