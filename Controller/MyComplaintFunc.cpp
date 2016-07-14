// MyComplaintFunc.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MyComplaintFunc.h"
#include "afxdialogex.h"
#include "Message.h"
#include "Login.h"
#include "User.h"
#include "ReadMessage.h"
extern User current_user;


// MyComplaintFunc �Ի���

IMPLEMENT_DYNAMIC(MyComplaintFunc, CDialogEx)

MyComplaintFunc::MyComplaintFunc(CWnd* pParent /*=NULL*/)
	: CDialogEx(MyComplaintFunc::IDD, pParent)
{

}

MyComplaintFunc::~MyComplaintFunc()
{
}

void MyComplaintFunc::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_LIST1, list_control);
}


BEGIN_MESSAGE_MAP(MyComplaintFunc, CDialogEx)
    ON_NOTIFY(NM_DBLCLK, IDC_LIST1, &MyComplaintFunc::OnNMDblclkList1)
END_MESSAGE_MAP()


// MyComplaintFunc ��Ϣ�������

BOOL MyComplaintFunc::OnInitDialog() {
    CDialogEx::OnInitDialog();
    CRect rect;
    // ��ȡ��������б���ͼ�ؼ���λ�úʹ�С
    list_control.GetClientRect(&rect);
    // Ϊ�б���ͼ�ؼ����ȫ��ѡ�к�դ����    
    list_control.SetExtendedStyle(list_control.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
    // Ϊ�б���ͼ�ؼ��������    
    list_control.InsertColumn(0, _T("Ͷ�߱��"), LVCFMT_CENTER, rect.Width() / 6, 0);
    list_control.InsertColumn(1, _T("ҵ������"), LVCFMT_CENTER, rect.Width() / 6, 1);
    list_control.InsertColumn(2, _T("��ϵ��ʽ"), LVCFMT_CENTER, rect.Width() / 6, 2);
    list_control.InsertColumn(3, _T("Ͷ��ʱ��"), LVCFMT_CENTER, rect.Width() / 6, 3);
    list_control.InsertColumn(4, _T("����"), LVCFMT_CENTER, rect.Width() / 6, 4);
    list_control.InsertColumn(5, _T("Ͷ��״̬"), LVCFMT_CENTER, rect.Width() / 6, 5);

    ReadMessage read_message("Data\\Complaint_list.txt");
    complaint_list = read_message.ReadFromFile();
    std::list<Message>::iterator it;
    int i = 0;
    for (it = complaint_list.begin(); it != complaint_list.end(); it++) {
        if (it->getUserName() == current_user.getRealName()) {
            CString str;
            str.Format(_T("%d"), it->getNum());
            list_control.InsertItem(i, str);
            list_control.SetItemText(i, 1, it->getUserName());
            list_control.SetItemText(i, 2, it->getUserPhone());
            list_control.SetItemText(i, 3, it->getTime());
            list_control.SetItemText(i, 4, it->getTheme());
            list_control.SetItemText(i, 5, it->getState());
            i++;
        }
    }
    return true;
}


//���ĳ��������Ŀ
void MyComplaintFunc::OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult)
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
        for (it = complaint_list.begin(); it != complaint_list.end(); it++) {
            if (it->getNum() == num) {
                AfxMessageBox(it->getContents());
                break;
            }
        }
    }
    *pResult = 0;
}
