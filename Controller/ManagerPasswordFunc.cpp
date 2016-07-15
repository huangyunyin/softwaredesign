// ManagerPasswordFunc.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ManagerPasswordFunc.h"
#include "afxdialogex.h"
#include "Login.h"
#include "User.h"
#include "ManagerPersonalFunc.h"
#include "ReadPeople.h"
extern CDialogEx *v;
extern User current_user;

// ManagerPasswordFunc �Ի���

IMPLEMENT_DYNAMIC(ManagerPasswordFunc, CDialogEx)

ManagerPasswordFunc::ManagerPasswordFunc(CWnd* pParent /*=NULL*/)
	: CDialogEx(ManagerPasswordFunc::IDD, pParent)
{

}

ManagerPasswordFunc::~ManagerPasswordFunc()
{
}

void ManagerPasswordFunc::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ManagerPasswordFunc, CDialogEx)
    ON_BN_CLICKED(IDC_BUTTON1, &ManagerPasswordFunc::OnBnClickedButton1)
END_MESSAGE_MAP()


// ManagerPasswordFunc ��Ϣ�������


BOOL ManagerPasswordFunc::OnInitDialog() {
    CDialogEx::OnInitDialog();
    GetDlgItem(IDC_EDIT1)->SetWindowText(current_user.getUserName());
    return true;
}


//�ύ���Ĵ�����
void ManagerPasswordFunc::OnBnClickedButton1()
{
    // TODO:  �ڴ���ӿؼ�֪ͨ����������
    CString current_password;
    CString confirm_password;
    GetDlgItem(IDC_EDIT2)->GetWindowText(current_password);
    GetDlgItem(IDC_EDIT3)->GetWindowText(confirm_password);
    if (current_password.GetLength() < 8) {
        AfxMessageBox(_T("���볤��Ӧ��С��8��"));
        return;
    }
    if (current_password != confirm_password) {
        AfxMessageBox(_T("�������벻��ͬ��"));
        return;
    }
    int i = 0;
    while (i < current_password.GetLength()) {
        if (isRightType(current_password[i])) {
            i++;
        }
        else {
            AfxMessageBox(_T("�����ʽ����ȷ��"));
            return;
        }
    }
    current_user.setPassword(current_password);
    ReadPeople read_people("Data\\Administrator_list.txt");
    read_people.ChangePeople(current_user);

    delete v;
    v = new ManagerPasswordFunc;
    v->Create(IDD_FORMVIEW10, GetActiveWindow());
    v->ShowWindow(SW_SHOWNORMAL);
    v->MoveWindow(135, 90, 848, 451);
    AfxMessageBox(_T("���ĳɹ���"));
}


//�����ʽ�Ƿ���ȷ
bool ManagerPasswordFunc::isRightType(char ch) {
    if ((ch > 64 && ch < 91) || (ch > 96 && ch < 123) || (ch > 47 && ch < 58)) {
        return true;
    }
    return false;
}