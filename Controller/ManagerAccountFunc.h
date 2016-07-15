#pragma once
#include "resource.h"
#include "afxcmn.h"
#include "afxwin.h"

// ManagerAccountFunc 对话框

class ManagerAccountFunc : public CDialogEx
{
	DECLARE_DYNAMIC(ManagerAccountFunc)

public:
	ManagerAccountFunc(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ManagerAccountFunc();
    virtual BOOL OnInitDialog();

// 对话框数据
	enum { IDD = IDD_FORMVIEW11 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
    CListCtrl list_control;
    afx_msg void OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult);
    CString user_name;
    afx_msg void OnBnClickedButton3();
    afx_msg void OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult);
    CEdit m_edit;
    int m_Row;
    int m_Col;
    afx_msg void OnBnClickedButton1();
};
