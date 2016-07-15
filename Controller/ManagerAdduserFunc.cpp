// ManagerAdduserFunc.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ManagerAdduserFunc.h"
#include "afxdialogex.h"
#include "Login.h"
#include "User.h"
#include "PersonalMessageFunc.h"
#include <fstream>
#include "ReadPeople.h"
#include "WritePeople.h"
extern CDialogEx *v;


// ManagerAdduserFunc �Ի���

IMPLEMENT_DYNAMIC(ManagerAdduserFunc, CDialogEx)

ManagerAdduserFunc::ManagerAdduserFunc(CWnd* pParent /*=NULL*/)
	: CDialogEx(ManagerAdduserFunc::IDD, pParent)
{
    strLangName = "";
}

ManagerAdduserFunc::~ManagerAdduserFunc()
{
}

void ManagerAdduserFunc::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_LIST1, list_control);
}


BEGIN_MESSAGE_MAP(ManagerAdduserFunc, CDialogEx)
    ON_BN_CLICKED(IDC_BUTTON1, &ManagerAdduserFunc::OnBnClickedButton1)
    ON_BN_CLICKED(IDC_BUTTON2, &ManagerAdduserFunc::OnBnClickedButton2)
    ON_NOTIFY(NM_CLICK, IDC_LIST1, &ManagerAdduserFunc::OnNMClickList1)
END_MESSAGE_MAP()


// ManagerAdduserFunc ��Ϣ�������

BOOL ManagerAdduserFunc::OnInitDialog() {
    CDialogEx::OnInitDialog();
    CRect rect;
    // ��ȡ��������б���ͼ�ؼ���λ�úʹ�С
    list_control.GetClientRect(&rect);
    // Ϊ�б���ͼ�ؼ����ȫ��ѡ�к�դ����
    list_control.SetExtendedStyle(list_control.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
    // Ϊ�б���ͼ�ؼ���Ӱ���
    list_control.InsertColumn(0, _T("�û���"), LVCFMT_CENTER, rect.Width() / 7, 0);
    list_control.InsertColumn(1, _T("����"), LVCFMT_CENTER, rect.Width() / 7, 1);
    list_control.InsertColumn(2, _T("ҵ����"), LVCFMT_CENTER, rect.Width() / 7, 2);
    list_control.InsertColumn(3, _T("���֤��"), LVCFMT_CENTER, rect.Width() / 7, 3);
    list_control.InsertColumn(4, _T("סַ"), LVCFMT_CENTER, rect.Width() / 7, 4);
    list_control.InsertColumn(5, _T("��ϵ��ʽ"), LVCFMT_CENTER, rect.Width() / 7, 5);
    list_control.InsertColumn(6, _T("����"), LVCFMT_CENTER, rect.Width() / 7, 6);

    ReadPeople read_people("Data\\Register_list.txt");
    register_list = read_people.ReadFromFile();
    std::list<User>::iterator it;
    int i = 0;
    for (it = register_list.begin(); it != register_list.end(); it++) {
        list_control.InsertItem(i, it->getUserName());
        list_control.SetItemText(i, 1, it->getPassword());
        list_control.SetItemText(i, 2, it->getRealName());
        list_control.SetItemText(i, 3, it->getIdNumber());
        list_control.SetItemText(i, 4, it->getAddress());
        list_control.SetItemText(i, 5, it->getPhone());
        list_control.SetItemText(i, 6, it->getMail());
        i++;
    }
    return true;
}


void ManagerAdduserFunc::OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
    LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
    // TODO:  �ڴ���ӿؼ�֪ͨ����������
    NMLISTVIEW *pNMListView = (NMLISTVIEW*)pNMHDR;
    if (-1 != pNMListView->iItem){// ���iItem����-1����˵�����б��ѡ��
        // ��ȡ��ѡ���б����һ��������ı�
        strLangName = list_control.GetItemText(pNMListView->iItem, 0);
    }
    *pResult = 0;
}



//��Ӱ�ť������
void ManagerAdduserFunc::OnBnClickedButton1()
{
    // TODO:  �ڴ���ӿؼ�֪ͨ����������
    if (strLangName.GetLength() == 0) {
        AfxMessageBox(_T("��ѡ���û���"));
        return;
    }
    WritePeople write_people;
    std::list<User>::iterator it;
    for (it = register_list.begin(); it != register_list.end(); it++) {
        if (strLangName == it->getUserName()) {
            write_people.WritePeopleAfter("Data\\User_list.txt", *it);
            register_list.erase(it);
            break;
        }
    }
    write_people.WriteAllPeople("Data\\Register_list.txt", register_list);

    delete v;
    v = new ManagerAdduserFunc;
    v->Create(IDD_FORMVIEW12, GetActiveWindow());
    v->ShowWindow(SW_SHOWNORMAL);
    v->MoveWindow(135, 90, 848, 451);
    AfxMessageBox(_T("��ӳɹ���"));
}



//�ܾ���ť������
void ManagerAdduserFunc::OnBnClickedButton2()
{
    // TODO:  �ڴ���ӿؼ�֪ͨ����������
    if (strLangName.GetLength() == 0) {
        AfxMessageBox(_T("��ѡ���û���"));
        return;
    }
    WritePeople write_people;
    std::list<User>::iterator it;
    for (it = register_list.begin(); it != register_list.end(); it++) {
        if (strLangName == it->getUserName()) {
            register_list.erase(it);
            break;
        }
    }
    write_people.WriteAllPeople("Data\\Register_list.txt", register_list);

    delete v;
    v = new ManagerAdduserFunc;
    v->Create(IDD_FORMVIEW12, GetActiveWindow());
    v->ShowWindow(SW_SHOWNORMAL);
    v->MoveWindow(135, 90, 848, 451);
    AfxMessageBox(_T("�ܾ��ɹ���"));
}
