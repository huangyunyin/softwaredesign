#pragma once
#include "resource.h"
#include "afxcmn.h"
#include "User.h"
#include <list>
#include "Message.h"


// ManagerAdduserFunc �Ի���

class ManagerAdduserFunc : public CDialogEx
{
	DECLARE_DYNAMIC(ManagerAdduserFunc)

public:
	ManagerAdduserFunc(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ManagerAdduserFunc();
    virtual BOOL OnInitDialog();

// �Ի�������
	enum { IDD = IDD_FORMVIEW12 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
    CListCtrl list_control;
    afx_msg void OnBnClickedButton1();
    afx_msg void OnBnClickedButton2();
    afx_msg void OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult);
    CString strLangName;

private:
    std::list<User> register_list;
};
