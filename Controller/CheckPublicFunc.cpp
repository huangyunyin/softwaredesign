// CheckPublicFunc.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CheckPublicFunc.h"
#include "afxdialogex.h"
#include "Login.h"
#include "Message.h"
#include "User.h"
#include "ReadMessage.h"

// CheckPublicFunc �Ի���

IMPLEMENT_DYNAMIC(CheckPublicFunc, CDialogEx)

CheckPublicFunc::CheckPublicFunc(CWnd* pParent /*=NULL*/)
	: CDialogEx(CheckPublicFunc::IDD, pParent)
{

}

CheckPublicFunc::~CheckPublicFunc()
{
}

void CheckPublicFunc::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_LIST1, list_control);
}


BEGIN_MESSAGE_MAP(CheckPublicFunc, CDialogEx)
    ON_NOTIFY(NM_DBLCLK, IDC_LIST1, &CheckPublicFunc::OnNMDblclkList1)
END_MESSAGE_MAP()


// CheckPublicFunc ��Ϣ�������

BOOL CheckPublicFunc::OnInitDialog() {
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



void CheckPublicFunc::OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult)
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
