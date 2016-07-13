#pragma once
#include "afxwin.h"


// Register 对话框

class Register : public CDialogEx
{
	DECLARE_DYNAMIC(Register)

public:
	Register(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Register();
    virtual BOOL OnInitDialog();
    afx_msg void OnBnClickedButton2();
    afx_msg void OnBnClickedButton1();
    void writeToFile(const char *fpath);
    bool isRightType(char ch);

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

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
