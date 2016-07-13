#pragma once
#include <string>
#include <fstream>
#include <list>
#include "User.h"

// Login �Ի���
class Login : public CDialogEx
{
	DECLARE_DYNAMIC(Login)

public:
	Login(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Login();
    bool Judge(CString name, CString password, int identity);
    User getUser() { return currentUser; }
    void readMessage(const char *fpath, int n);
    void readPayment(const char *fpath);

// �Ի�������
	enum { IDD = IDD_MFCAPPLICATION_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

private:
    User currentUser;
};