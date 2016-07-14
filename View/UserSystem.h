#pragma once
#include "resource.h"
#include "afxcmn.h"
#include "afxwin.h"
#include "SelectFuntion.h"
#include "User.h"

// UserSystem �Ի���

class UserSystem : public CDialogEx
{
	DECLARE_DYNAMIC(UserSystem)

public:
	UserSystem(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~UserSystem();
    virtual BOOL OnInitDialog();

// �Ի�������
    enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
    afx_msg void FunctionTree(NMHDR *pNMHDR, LRESULT *pResult);
    CTreeCtrl Function_tree_init;
    afx_msg void ExitThisLogin();
    CString currentPosition[9];

private:
    SelectFuntion select;
};
