#pragma once
#include "resource.h"

// ManagerPasswordFunc �Ի���

class ManagerPasswordFunc : public CDialogEx
{
	DECLARE_DYNAMIC(ManagerPasswordFunc)

public:
	ManagerPasswordFunc(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ManagerPasswordFunc();
    virtual BOOL OnInitDialog();
    bool isRightType(char ch);

// �Ի�������
	enum { IDD = IDD_FORMVIEW10 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedButton1();
};
