// MyRepairFunc.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MyRepairFunc.h"
#include "afxdialogex.h"
#include "Message.h"
#include "Login.h"
#include "User.h"
#include "ReadMessage.h"
extern User current_user;

// MyRepairFunc �Ի���

IMPLEMENT_DYNAMIC(MyRepairFunc, CDialogEx)

MyRepairFunc::MyRepairFunc(CWnd* pParent /*=NULL*/)
	: CDialogEx(MyRepairFunc::IDD, pParent)
{

}

MyRepairFunc::~MyRepairFunc()
{
}

void MyRepairFunc::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_LIST1, programLangList);
}


BEGIN_MESSAGE_MAP(MyRepairFunc, CDialogEx)
    ON_NOTIFY(NM_DBLCLK, IDC_LIST1, &MyRepairFunc::OnNMDblclkList1)
END_MESSAGE_MAP()


// MyRepairFunc ��Ϣ�������
BOOL MyRepairFunc::OnInitDialog() {
    CDialogEx::OnInitDialog();
    CRect rect;
    // ��ȡ��������б���ͼ�ؼ���λ�úʹ�С
    programLangList.GetClientRect(&rect);
    // Ϊ�б���ͼ�ؼ����ȫ��ѡ�к�դ����    
    programLangList.SetExtendedStyle(programLangList.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
    // Ϊ�б���ͼ�ؼ��������    
    programLangList.InsertColumn(0, _T("���ޱ��"), LVCFMT_CENTER, rect.Width() / 6, 0);
    programLangList.InsertColumn(1, _T("ҵ������"), LVCFMT_CENTER, rect.Width() / 6, 1);
    programLangList.InsertColumn(2, _T("��ϵ��ʽ"), LVCFMT_CENTER, rect.Width() / 6, 2);
    programLangList.InsertColumn(3, _T("����ʱ��"), LVCFMT_CENTER, rect.Width() / 6, 3);
    programLangList.InsertColumn(4, _T("����"), LVCFMT_CENTER, rect.Width() / 6, 4);
    programLangList.InsertColumn(5, _T("����״̬"), LVCFMT_CENTER, rect.Width() / 6, 5);

    ReadMessage read_message("Data\\Repair_list.txt");
    repair_list = read_message.ReadFromFile();
    std::list<Message>::iterator it;
    int i = 0;
    for (it = repair_list.begin(); it != repair_list.end(); it++) {
        if (it->getUserName() == current_user.getRealName()) {
            CString str;
            str.Format(_T("%d"), it->getNum());
            programLangList.InsertItem(i, str);
            programLangList.SetItemText(i, 1, it->getUserName());
            programLangList.SetItemText(i, 2, it->getUserPhone());
            programLangList.SetItemText(i, 3, it->getTime());
            programLangList.SetItemText(i, 4, it->getTheme());
            programLangList.SetItemText(i, 5, it->getState());
            i++;
        }
    }
    return true;
}


//���ĳһ����Ŀ�����¼���ϸ��Ϣ
void MyRepairFunc::OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult)
{
    LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
    // TODO:  �ڴ���ӿؼ�֪ͨ����������
    CString strLangName;    // ѡ�����ַ���
    NMLISTVIEW *pNMListView = (NMLISTVIEW*)pNMHDR;
    if (-1 != pNMListView->iItem){// ���iItem����-1����˵�����б��ѡ��
        // ��ȡ��ѡ���б����һ��������ı�
        strLangName = programLangList.GetItemText(pNMListView->iItem, 0);
        int num = _ttoi(strLangName);
        std::list<Message>::iterator it;
        for (it = repair_list.begin(); it != repair_list.end(); it++) {
            if (it->getNum() == num) {
                AfxMessageBox(it->getContents());
                break;
            }
        }
    }
    *pResult = 0;
}
