#pragma once
#include "afxwin.h"


// Register �Ի���

class Register : public CDialogEx
{
	DECLARE_DYNAMIC(Register)

public:
	Register(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Register();
    virtual BOOL OnInitDialog();
    afx_msg void OnBnClickedButton2();
    afx_msg void OnBnClickedButton1();
    void writeToFile(const char *fpath);
    bool isRightType(char ch);

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()


public:
    CFont font;
    CString name;
    CString password;
    CString password_confirm;
    CString user_name;
    CString id_number;
    CString address;
    CString phone_number;
    CString mail;
};
