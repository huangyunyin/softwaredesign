#pragma once
#include "resource.h"
#include "afxcmn.h"

// CheckPaymentFunc 对话框

class CheckPaymentFunc : public CDialogEx
{
	DECLARE_DYNAMIC(CheckPaymentFunc)

public:
	CheckPaymentFunc(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CheckPaymentFunc();
    virtual BOOL OnInitDialog();

// 对话框数据
	enum { IDD = IDD_FORMVIEW6 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
    CListCtrl list_control;
};
