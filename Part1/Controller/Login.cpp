// Login.cpp : ʵ���ļ�
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

// Login �Ի���


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
        //δ�����û���
        AfxMessageBox(_T("�������û�����"));
        return false;
    }
    if (password == "") {
        //δ��������
        AfxMessageBox(_T("���������룡"));
        return false;
    }
    if (identity == -1) {
        AfxMessageBox(_T("��ѡ����ݣ�"));
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
        //�û��������벻��ȷ
        AfxMessageBox(_T("�û������������"));
        return false;
    }
    return true;
}

BEGIN_MESSAGE_MAP(Login, CDialogEx)
END_MESSAGE_MAP()


// Login ��Ϣ�������



