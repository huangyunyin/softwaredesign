#pragma once
#include "resource.h"
#include "afxcmn.h"
#include "SelectFuntion.h"

// ManagerSystem 对话框

class ManagerSystem : public CDialogEx
{
	DECLARE_DYNAMIC(ManagerSystem)

public:
	ManagerSystem(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ManagerSystem();
    virtual BOOL OnInitDialog();

// 对话框数据
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

public:
    CString currentPosition[10];
    CTreeCtrl Function_tree_init;
    afx_msg void FunctionTree(NMHDR *pNMHDR, LRESULT *pResult);
    SelectFuntion select;
    afx_msg void OnBnClickedButton2();
};
