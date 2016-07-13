
// MFCApplicationDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include "Register.h"
#include "Login.h"


// CMFCApplicationDlg �Ի���
class CMFCApplicationDlg : public CDialogEx
{
// ����
public:
	CMFCApplicationDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFCAPPLICATION_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
