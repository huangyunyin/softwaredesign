// ManagerSeepublicFunc.cpp : 实现文件
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


// ManagerSeepublicFunc 对话框

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


// ManagerSeepublicFunc 消息处理程序


BOOL ManagerSeepublicFunc::OnInitDialog() {
    CDialogEx::OnInitDialog();
    CRect rect;
    // 获取编程语言列表视图控件的位置和大小
    list_control.GetClientRect(&rect);
    // 为列表视图控件添加全行选中和栅格风格    
    list_control.SetExtendedStyle(list_control.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
    // 为列表视图控件添加六列    
    list_control.InsertColumn(0, _T("信息编号"), LVCFMT_CENTER, rect.Width() / 6, 0);
    list_control.InsertColumn(1, _T("发布人"), LVCFMT_CENTER, rect.Width() / 6, 1);
    list_control.InsertColumn(2, _T("联系方式"), LVCFMT_CENTER, rect.Width() / 6, 2);
    list_control.InsertColumn(3, _T("发布时间"), LVCFMT_CENTER, rect.Width() / 6, 3);
    list_control.InsertColumn(4, _T("标题"), LVCFMT_CENTER, rect.Width() / 3, 4);

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
    // TODO:  在此添加控件通知处理程序代码
    NMLISTVIEW *pNMListView = (NMLISTVIEW*)pNMHDR;
    if (-1 != pNMListView->iItem){// 如果iItem不是-1，就说明有列表项被选择
        // 获取被选择列表项第一个子项的文本
        strLangName = list_control.GetItemText(pNMListView->iItem, 0);
    }
    *pResult = 0;
}


void ManagerSeepublicFunc::OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult)
{
    LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
    // TODO:  在此添加控件通知处理程序代码
    CString strLangName;    // 选择编号字符串
    NMLISTVIEW *pNMListView = (NMLISTVIEW*)pNMHDR;
    if (-1 != pNMListView->iItem){// 如果iItem不是-1，就说明有列表项被选择
        // 获取被选择列表项第一个子项的文本
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
    // TODO:  在此添加控件通知处理程序代码
    if (strLangName.GetLength() == 0) {
        AfxMessageBox(_T("请选择一条报修！"));
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
    AfxMessageBox(_T("删除成功！"));
}
