// ManagerAccountFunc.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ManagerAccountFunc.h"
#include "afxdialogex.h"
#include "Login.h"
#include "User.h"
#include "PersonalMessageFunc.h"
#include "ReadPeople.h"
#include "WritePeople.h"
extern CDialogEx *v;
// ManagerAccountFunc �Ի���

IMPLEMENT_DYNAMIC(ManagerAccountFunc, CDialogEx)

ManagerAccountFunc::ManagerAccountFunc(CWnd* pParent /*=NULL*/)
	: CDialogEx(ManagerAccountFunc::IDD, pParent)
{
    user_name = "";
    m_Row = -1;
    m_Col = -1;
}

ManagerAccountFunc::~ManagerAccountFunc()
{
}

void ManagerAccountFunc::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_LIST1, list_control);
    DDX_Control(pDX, IDC_EDIT1, m_edit);
}


BEGIN_MESSAGE_MAP(ManagerAccountFunc, CDialogEx)
    ON_NOTIFY(NM_CLICK, IDC_LIST1, &ManagerAccountFunc::OnNMClickList1)
    ON_BN_CLICKED(IDC_BUTTON3, &ManagerAccountFunc::OnBnClickedButton3)
    ON_NOTIFY(NM_DBLCLK, IDC_LIST1, &ManagerAccountFunc::OnNMDblclkList1)
    ON_BN_CLICKED(IDC_BUTTON1, &ManagerAccountFunc::OnBnClickedButton1)
END_MESSAGE_MAP()


// ManagerAccountFunc ��Ϣ�������


BOOL ManagerAccountFunc::OnInitDialog() {
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

    ReadPeople read_people("Data\\User_list.txt");
    list<User> user_list = read_people.ReadFromFile();
    std::list<User>::iterator it;
    int i = 0;
    for (it = user_list.begin(); it != user_list.end(); it++) {
        list_control.InsertItem(i, it->getUserName());
        list_control.SetItemText(i, 1, it->getPassword());
        list_control.SetItemText(i, 2, it->getRealName());
        list_control.SetItemText(i, 3, it->getIdNumber());
        list_control.SetItemText(i, 4, it->getAddress());
        list_control.SetItemText(i, 5, it->getPhone());
        list_control.SetItemText(i, 6, it->getMail());
        i++;
    }
    m_edit.ShowWindow(SW_HIDE);
    return true;
}

//��ȡ��ѡ�е���Ŀ
void ManagerAccountFunc::OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
    LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
    // TODO:  �ڴ���ӿؼ�֪ͨ����������
    *pResult = 0;
    NMLISTVIEW *pNMListView = (NMLISTVIEW*)pNMHDR;
    if (-1 != pNMListView->iItem){// ���iItem����-1����˵�����б��ѡ��
        // ��ȡ��ѡ���б����һ��������ı�
        user_name = list_control.GetItemText(pNMListView->iItem, 0);
    }
}


//˫���༭��Ԫ���޸�����
void ManagerAccountFunc::OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult)
{
    LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
    // TODO:  �ڴ���ӿؼ�֪ͨ����������
    NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
    CRect rc;
    if (m_Col > 0) {
        CString tem;
        m_edit.GetWindowText(tem);    //�õ��û�������µ�����
        list_control.SetItemText(m_Row, m_Col, tem);   //���ñ༭���������
        m_edit.ShowWindow(SW_HIDE);                //Ӧ�ر༭��
    }
    m_Row = pNMListView->iItem;//���ѡ�е���
    m_Col = pNMListView->iSubItem;//���ѡ����


    if (pNMListView->iSubItem != 0) //���ѡ���������;
    {
        list_control.GetSubItemRect(m_Row, m_Col, LVIR_LABEL, rc);//��������RECT��
        m_edit.SetParent(&list_control);//ת������Ϊ�б���е�����
        m_edit.MoveWindow(rc);//�ƶ�Edit��RECT���ڵ�λ��;
        m_edit.SetWindowText(list_control.GetItemText(m_Row, m_Col));//���������е�ֵ����Edit�ؼ��У�
        m_edit.ShowWindow(SW_SHOW);//��ʾEdit�ؼ���
        m_edit.SetFocus();//����Edit����
        m_edit.ShowCaret();//��ʾ���
        m_edit.SetSel(-1);//������ƶ������
    }
    *pResult = 0;
}


//ɾ��ҵ����ť������
void ManagerAccountFunc::OnBnClickedButton3()
{
    // TODO:  �ڴ���ӿؼ�֪ͨ����������
    if (user_name.GetLength() != 0) {
        ReadPeople read_people("Data\\User_list.txt");
        read_people.deletePeople(user_name);

        delete v;
        v = new ManagerAccountFunc;
        v->Create(IDD_FORMVIEW11, GetActiveWindow());
        v->ShowWindow(SW_SHOWNORMAL);
        v->MoveWindow(135, 90, 848, 451);
        AfxMessageBox(_T("ɾ���ɹ���"));
    }
    else {
        AfxMessageBox(_T("��ѡ���û���"));
    }

}


//�����޸İ�ť������
void ManagerAccountFunc::OnBnClickedButton1()
{
    if (m_Col > 0) {
        CString tem;
        m_edit.GetWindowText(tem);    //�õ��û�������µ�����
        list_control.SetItemText(m_Row, m_Col, tem);   //���ñ༭���������
        m_edit.ShowWindow(SW_HIDE);                //���ر༭��
    }
    // TODO:  �ڴ���ӿؼ�֪ͨ����������
    m_edit.ShowWindow(SW_HIDE);
    list<User> user_list;
    CString user_name;
    CString password;
    CString real_name;
    CString id_number;
    CString address;
    CString phone;
    CString mail;
    int i = 0;
    while (1) {
        user_name = list_control.GetItemText(i, 0);
        if (user_name == "") {
            break;
        }
        password = list_control.GetItemText(i, 1);
        real_name = list_control.GetItemText(i, 2);
        id_number = list_control.GetItemText(i, 3);
        address = list_control.GetItemText(i, 4);
        phone = list_control.GetItemText(i, 5);
        mail = list_control.GetItemText(i, 6);
        user_list.push_back(User(user_name, password, real_name, id_number, address, phone, mail));
        i++;
    }
    
    WritePeople write_people;
    write_people.WriteAllPeople("Data\\User_list.txt", user_list);
    AfxMessageBox(_T("����ɹ���"));
}
