// ManagerSeepublicFunc.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ManagerSeepublicFunc.h"
#include "afxdialogex.h"
#include "Login.h"
#include "Message.h"
#include "ManagerRepairFunc.h"
#include "ReadMessage.h"
#include "WriteMessage.h"
extern CDialogEx *v;


// ManagerSeepublicFunc �Ի���

IMPLEMENT_DYNAMIC(ManagerSeepublicFunc, CDialogEx)

ManagerSeepublicFunc::ManagerSeepublicFunc(CWnd* pParent /*=NULL*/)
	: CDialogEx(ManagerSeepublicFunc::IDD, pParent)
{

}

ManagerSeepublicFunc::~ManagerSeepublicFunc()
{
}

void ManagerSeepublicFunc::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_LIST1, list_control);
}


BEGIN_MESSAGE_MAP(ManagerSeepublicFunc, CDialogEx)
    ON_NOTIFY(NM_CLICK, IDC_LIST1, &ManagerSeepublicFunc::OnNMClickList1)
    ON_NOTIFY(NM_DBLCLK, IDC_LIST1, &ManagerSeepublicFunc::OnNMDblclkList1)
    ON_BN_CLICKED(IDC_BUTTON1, &ManagerSeepublicFunc::OnBnClickedButton1)
END_MESSAGE_MAP()


// ManagerSeepublicFunc ��Ϣ�������


BOOL ManagerSeepublicFunc::OnInitDialog() {
    CDialogEx::OnInitDialog();
    CRect rect;
    // ��ȡ��������б���ͼ�ؼ���λ�úʹ�С
    list_control.GetClientRect(&rect);
    // Ϊ�б���ͼ�ؼ����ȫ��ѡ�к�դ����    
    list_control.SetExtendedStyle(list_control.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
    // Ϊ�б���ͼ�ؼ��������    
    list_control.InsertColumn(0, _T("��Ϣ���"), LVCFMT_CENTER, rect.Width() / 6, 0);
    list_control.InsertColumn(1, _T("������"), LVCFMT_CENTER, rect.Width() / 6, 1);
    list_control.InsertColumn(2, _T("��ϵ��ʽ"), LVCFMT_CENTER, rect.Width() / 6, 2);
    list_control.InsertColumn(3, _T("����ʱ��"), LVCFMT_CENTER, rect.Width() / 6, 3);
    list_control.InsertColumn(4, _T("����"), LVCFMT_CENTER, rect.Width() / 3, 4);

    ReadMessage read_message("Data\\Public_list.txt");
    public_list = read_message.ReadFromFile();
    std::list<Message>::iterator it;
    int i = 0;
    for (it = public_list.begin(); it != public_list.end(); it++) {
        CString str;
        str.Format(_T("%d"), it->getNum());
        list_control.InsertItem(i, str);
        list_control.SetItemText(i, 1, it->getUserName());
        list_control.SetItemText(i, 2, it->getUserPhone());
        list_control.SetItemText(i, 3, it->getTime());
        list_control.SetItemText(i, 4, it->getTheme());
        i++;
    }
    return true;
}

void ManagerSeepublicFunc::OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult)
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


void ManagerSeepublicFunc::OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult)
{
    LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
    // TODO:  �ڴ���ӿؼ�֪ͨ����������
    CString strLangName;    // ѡ�����ַ���
    NMLISTVIEW *pNMListView = (NMLISTVIEW*)pNMHDR;
    if (-1 != pNMListView->iItem){// ���iItem����-1����˵�����б��ѡ��
        // ��ȡ��ѡ���б����һ��������ı�
        strLangName = list_control.GetItemText(pNMListView->iItem, 0);
        int num = _ttoi(strLangName);
        std::list<Message>::iterator it;
        for (it = public_list.begin(); it != public_list.end(); it++) {
            if (it->getNum() == num) {
                AfxMessageBox(it->getContents());
                break;
            }
        }
    }
    *pResult = 0;
}


void ManagerSeepublicFunc::OnBnClickedButton1()
{
    // TODO:  �ڴ���ӿؼ�֪ͨ����������
    if (strLangName.GetLength() == 0) {
        AfxMessageBox(_T("��ѡ��һ�����ޣ�"));
        return;
    }
    std::list<Message>::iterator it;
    for (it = public_list.begin(); it != public_list.end(); it++) {
        if (_ttoi(strLangName) == it->getNum()) {
            public_list.erase(it);
            break;
        }
    }

    WriteMessage write_message("Data\\Public_list.txt");
    write_message.WriteMessageAll(public_list);

    delete v;
    v = new ManagerSeepublicFunc;
    v->Create(IDD_FORMVIEW17, GetActiveWindow());
    v->ShowWindow(SW_SHOWNORMAL);
    v->MoveWindow(135, 90, 848, 451);
    AfxMessageBox(_T("ɾ���ɹ���"));
}
