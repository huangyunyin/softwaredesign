// WantComplaintFunc.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "WantComplaintFunc.h"
#include "WantRepairFunc.h"
#include "afxdialogex.h"
#include "Message.h"
#include "User.h"
#include "Login.h"
#include "ReadMessage.h"
#include "WriteMessage.h"
extern CDialogEx *v;
extern User current_user;

// WantComplaintFunc �Ի���

IMPLEMENT_DYNAMIC(WantComplaintFunc, CDialogEx)

WantComplaintFunc::WantComplaintFunc(CWnd* pParent /*=NULL*/)
	: CDialogEx(WantComplaintFunc::IDD, pParent)
{

}

WantComplaintFunc::~WantComplaintFunc()
{
}

void WantComplaintFunc::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(WantComplaintFunc, CDialogEx)
    ON_BN_CLICKED(IDC_BUTTON1, &WantComplaintFunc::OnBnClickedButton1)
END_MESSAGE_MAP()


// WantComplaintFunc ��Ϣ�������
BOOL WantComplaintFunc::OnInitDialog() {
    CDialogEx::OnInitDialog();
    ReadMessage read_message("Data\\Complaint_list.txt");
    complaint_list = read_message.ReadFromFile();
    int n = complaint_list.size() + 1;
    CString str;
    str.Format(_T("%d"), n);
    GetDlgItem(IDC_EDIT1)->SetWindowText(str);
    return true;
}


//�ύͶ�߰�ť�����¼�
void WantComplaintFunc::OnBnClickedButton1()
{
    // TODO:  �ڴ���ӿؼ�֪ͨ����������
    CString theme;
    CString contents;
    CString str1;
    CString str2;
    string state = "δ����";
    str2 = state.c_str();
    CTime c = CTime::GetCurrentTime();
    str1 = c.Format("%Y��%m��%d��");
    GetDlgItem(IDC_EDIT2)->GetWindowText(theme);
    GetDlgItem(IDC_EDIT3)->GetWindowText(contents);
    if (theme.GetLength() == 0) {
        AfxMessageBox(_T("���ⲻ��Ϊ�գ�"));
        return;
    }
    if (contents.GetLength() == 0) {
        AfxMessageBox(_T("Ͷ�����ݲ���Ϊ�գ�"));
        return;
    }

    Message new_message = Message((complaint_list.size() + 1), current_user.getRealName(), current_user.getPhone(), str1, theme, contents, str2);
    WriteMessage write_message("Data\\Complaint_list.txt");
    write_message.WriteMessageAfter(new_message);

    delete v;
    v = new WantComplaintFunc;
    v->Create(IDD_FORMVIEW4, GetActiveWindow());
    v->ShowWindow(SW_SHOWNORMAL);
    v->MoveWindow(135, 90, 848, 451);
    AfxMessageBox(_T("�ύ�ɹ���"));
}
