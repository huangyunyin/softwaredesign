// ContactManagerFunc.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ContactManagerFunc.h"
#include "afxdialogex.h"
#include "Login.h"
#include "User.h"
#include "ReadPeople.h"

// ContactManagerFunc �Ի���

IMPLEMENT_DYNAMIC(ContactManagerFunc, CDialogEx)

ContactManagerFunc::ContactManagerFunc(CWnd* pParent /*=NULL*/)
	: CDialogEx(ContactManagerFunc::IDD, pParent)
{

}

ContactManagerFunc::~ContactManagerFunc()
{
}

void ContactManagerFunc::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_LIST1, list_control);
}


BEGIN_MESSAGE_MAP(ContactManagerFunc, CDialogEx)
END_MESSAGE_MAP()


// ContactManagerFunc ��Ϣ�������


BOOL ContactManagerFunc::OnInitDialog() {
    CDialogEx::OnInitDialog();
    CRect rect;
    // ��ȡ��������б���ͼ�ؼ���λ�úʹ�С
    list_control.GetClientRect(&rect);
    // Ϊ�б���ͼ�ؼ����ȫ��ѡ�к�դ����
    list_control.SetExtendedStyle(list_control.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
    // Ϊ�б���ͼ�ؼ��������
    list_control.InsertColumn(0, _T("����"), LVCFMT_CENTER, rect.Width() / 3, 0);
    list_control.InsertColumn(1, _T("��ϵ��ʽ"), LVCFMT_CENTER, rect.Width() / 3, 1);
    list_control.InsertColumn(2, _T("����"), LVCFMT_CENTER, rect.Width() / 3, 2);

    ReadPeople read_people("Data\\Administrator_list.txt");
    list<User> manager_list = read_people.ReadFromFile();
    std::list<User>::iterator it;
    int i = 0;
    for (it = manager_list.begin(); it != manager_list.end(); it++) {
        list_control.InsertItem(i, it->getRealName());
        list_control.SetItemText(i, 1, it->getPhone());
        list_control.SetItemText(i, 2, it->getMail());
        i++;
    }
    return true;
}