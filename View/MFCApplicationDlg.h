
// MFCApplicationDlg.h : 头文件
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include "Register.h"
#include "Login.h"


// CMFCApplicationDlg 对话框
class CMFCApplicationDlg : public CDialogEx
{
// 构造
public:
	CMFCApplicationDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MFCAPPLICATION_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
    CListCtrl m_programLangList;
    CSplitButton m_comboWeb;
    CComboBox Login_identity;
    afx_msg void OnBnClickedButton9();
    afx_msg void MenuExit();
    afx_msg void OnBnClickedButton1();
    afx_msg void MenuReLogin();

private:
    CFont font;
};
