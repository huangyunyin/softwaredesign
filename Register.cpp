// Register.cpp : ʵ���ļ�
//
#include <atlbase.h>
#include "stdafx.h"
#include "MFCApplication.h"
#include "Register.h"
#include "MFCApplicationDlg.h"
#include "afxdialogex.h"
#include "ReadPeople.h"
#include "User.h"
#include "WritePeople.h"

// Register �Ի���

IMPLEMENT_DYNAMIC(Register, CDialogEx)

Register::Register(CWnd* pParent /*=NULL*/)
	: CDialogEx(Register::IDD, pParent)
{

}

Register::~Register()
{

}

//���س�ʼ����������ע�����Ի�����г�ʼ��
BOOL Register::OnInitDialog() {
    CDialogEx::OnInitDialog();
    //ע�����С������ϵͳ��������
    SetWindowPos(NULL, 0, 0, 1000, 600, SWP_NOMOVE);//���ô��ڵĴ�С
    font.CreatePointFont(300, _T("�����п�"), NULL);
    GetDlgItem(IDC_STATIC)->SetFont(&font);
    return true;
}

void Register::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Register, CDialogEx)
    ON_BN_CLICKED(IDC_BUTTON2, &Register::OnBnClickedButton2)
    ON_BN_CLICKED(IDC_BUTTON1, &Register::OnBnClickedButton1)
END_MESSAGE_MAP()


// Register ��Ϣ�������


void Register::OnBnClickedButton2()
{
    // TODO:  �ڴ���ӿؼ�֪ͨ����������
    EndDialog(IDOK);
    CMFCApplicationDlg dlg;
    INT_PTR nResponse = dlg.DoModal();
}


void Register::OnBnClickedButton1()
{
    // TODO:  �ڴ���ӿؼ�֪ͨ����������
    GetDlgItem(IDC_EDIT1)->GetWindowText(name);
    GetDlgItem(IDC_EDIT2)->GetWindowText(password);
    GetDlgItem(IDC_EDIT3)->GetWindowText(password_confirm);
    GetDlgItem(IDC_EDIT4)->GetWindowText(user_name);
    GetDlgItem(IDC_EDIT5)->GetWindowText(id_number);
    GetDlgItem(IDC_EDIT6)->GetWindowText(address);
    GetDlgItem(IDC_EDIT7)->GetWindowText(phone_number);
    GetDlgItem(IDC_EDIT8)->GetWindowText(mail);

    if (name.GetLength() == 0){
        //�û���Ϊ��
        AfxMessageBox(_T("�û�������Ϊ��"));
        return;
    }
    if (password.GetLength() < 8) {
        //���볤�Ȳ���
        AfxMessageBox(_T("���볤��Ӧ��С��8��"));
        return;
    }
    if (password != password_confirm) {
        //�������벻ƥ��
        AfxMessageBox(_T("�������벻��ͬ��"));
        return;
    }
    int i = 0;
    while (i < name.GetLength()) {
        if (isRightType(name[i])) {
            i++;
        }
        else {
            AfxMessageBox(_T("�û�����ʽ����ȷ��"));
            return;
        }
    }
    i = 0;
    while (i < password.GetLength()) {
        if (isRightType(password[i])) {
            i++;
        }
        else {
            AfxMessageBox(_T("�����ʽ����ȷ��"));
            return;
        }
    }

    ReadPeople read_people("Data\\User_list.txt");
    list<User>::iterator it;
    if (read_people.isExist(name)) {
        AfxMessageBox(_T("�û����Ѵ��ڣ�"));
        return;
    }

    read_people = ReadPeople("Data\\Register_list.txt");
    if (read_people.isExist(name)) {
        AfxMessageBox(_T("�û����Ѵ��ڣ�"));
        return;
    }

    //����ע��
    User user = User(name, password, user_name, id_number, address, phone_number, mail);
    WritePeople write_people;
    write_people.WritePeopleAfter("Data\\Register_list.txt", user);
    if (AfxMessageBox(_T("����ɹ�����ȴ���ʵ��"))) {
        EndDialog(IDOK);
        CMFCApplicationDlg dlg;
        INT_PTR nResponse = dlg.DoModal();
    }
}
//�û���������ĸ�ʽ
bool Register::isRightType(char ch) {
    if ((ch > 64 && ch < 91) || (ch > 96 && ch < 123) || (ch > 47 && ch < 58)) {
        return true;
    }
    return false;
}
