// ManagerAddpublicFunc.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ManagerAddpublicFunc.h"
#include "afxdialogex.h"
#include "Login.h"
#include "Message.h"
#include "User.h"
#include <fstream>
#include "ReadMessage.h"
#include "WriteMessage.h"
extern CDialogEx *v;
extern User current_user;


// ManagerAddpublicFunc �Ի���

IMPLEMENT_DYNAMIC(ManagerAddpublicFunc, CDialogEx)

ManagerAddpublicFunc::ManagerAddpublicFunc(CWnd* pParent /*=NULL*/)
	: CDialogEx(ManagerAddpublicFunc::IDD, pParent)
{

}

ManagerAddpublicFunc::~ManagerAddpublicFunc()
{
}

void ManagerAddpublicFunc::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ManagerAddpublicFunc, CDialogEx)
    ON_BN_CLICKED(IDC_BUTTON1, &ManagerAddpublicFunc::OnBnClickedButton1)
END_MESSAGE_MAP()


// ManagerAddpublicFunc ��Ϣ�������


BOOL ManagerAddpublicFunc::OnInitDialog() {
    CDialogEx::OnInitDialog();
    ReadMessage read_message("Data\\Public_list.txt");
    public_list = read_message.ReadFromFile();
    int n = public_list.size() + 1;
    CString str;
    str.Format(_T("%d"), n);
    GetDlgItem(IDC_EDIT1)->SetWindowText(str);
    return true;
}


//�ύ��ť������
void ManagerAddpublicFunc::OnBnClickedButton1()
{
    // TODO:  �ڴ���ӿؼ�֪ͨ����������
    CString theme;
    CString contents;
    CString state = _T("û��");
    CString time;
    CTime c = CTime::GetCurrentTime();
    time = c.Format("%Y��%m��%d��");
    GetDlgItem(IDC_EDIT2)->GetWindowText(theme);
    GetDlgItem(IDC_EDIT3)->GetWindowText(contents);
    if (theme.GetLength() == 0) {
        AfxMessageBox(_T("���ⲻ��Ϊ�գ�"));
        return;
    }
    if (contents.GetLength() == 0) {
        AfxMessageBox(_T("��ʾ��Ϣ���ݲ���Ϊ�գ�"));
        return;
    }

    Message new_message = Message((public_list.size() + 1), current_user.getRealName(), current_user.getPhone(), time, theme, contents, state);
    WriteMessage write_message("Data\\Public_list.txt");
    write_message.WriteMessageAfter(new_message);

    delete v;
    v = new ManagerAddpublicFunc;
    v->Create(IDD_FORMVIEW18, GetActiveWindow());
    v->ShowWindow(SW_SHOWNORMAL);
    v->MoveWindow(135, 90, 848, 451);
    AfxMessageBox(_T("�ύ�ɹ���"));
}