#pragma once
#include "resource.h"

// ManagerPasswordFunc 对话框

class ManagerPasswordFunc : public CDialogEx
{
	DECLARE_DYNAMIC(ManagerPasswordFunc)

public:
	ManagerPasswordFunc(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ManagerPasswordFunc();
    virtual BOOL OnInitDialog();
    bool isRightType(char ch);

// 对话框数据
	enum { IDD = IDD_FORMVIEW10 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedButton1();
};
