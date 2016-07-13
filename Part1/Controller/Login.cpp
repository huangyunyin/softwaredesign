// Login.cpp : 实现文件
//

#include<stdlib.h>
#include "stdafx.h"
#include "MFCApplication.h"
#include "Login.h"
#include "afxdialogex.h"
#include "Register.h"
#include "User.h"
#include "Message.h"
#include "Payment.h"
#include "ReadPeople.h"

User current_user;

// Login 对话框


IMPLEMENT_DYNAMIC(Login, CDialogEx)

Login::Login(CWnd* pParent /*=NULL*/)
	: CDialogEx(Login::IDD, pParent)
{

}

Login::~Login()
{
}

void Login::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


bool Login::Judge(CString name, CString password, int identity) {
    if (name == "") {
        //未输入用户名
        AfxMessageBox(_T("请输入用户名！"));
        return false;
    }
    if (password == "") {
        //未输入密码
        AfxMessageBox(_T("请输入密码！"));
        return false;
    }
    if (identity == -1) {
        AfxMessageBox(_T("请选择身份！"));
        return false;
    }
    char *fpath;
    if (identity == 0) {
        fpath = "Data\\User_list.txt";
    }
    else {
        fpath = "Data\\Administrator_list.txt";
    }
    ReadPeople people(fpath);
    if (people.FindPeople(name, password)) {
        current_user = people.getPeople();
        return true;
    }
    else {
        //用户名或密码不正确
        AfxMessageBox(_T("用户名或密码错误！"));
        return false;
    }
    return true;
}

BEGIN_MESSAGE_MAP(Login, CDialogEx)
END_MESSAGE_MAP()


// Login 消息处理程序



