// ManagerRepairFunc.cpp : 实现文件
//

#include "stdafx.h"
#include "ManagerRepairFunc.h"
#include "afxdialogex.h"
#include "Login.h"
#include "User.h"
#include "Message.h"
#include <fstream>
#include "ReadMessage.h"
#include "WriteMessage.h"
extern CDialogEx *v;


// ManagerRepairFunc 对话框

IMPLEMENT_DYNAMIC(ManagerRepairFunc, CDialogEx)

ManagerRepairFunc::ManagerRepairFunc(CWnd* pParent /*=NULL*/)
	: CDialogEx(ManagerRepairFunc::IDD, pParent)
{
    strLangName = "";
}

ManagerRepairFunc::~ManagerRepairFunc()
{
}

void ManagerRepairFunc::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_LIST1, list_control);
}


BEGIN_MESSAGE_MAP(ManagerRepairFunc, CDialogEx)
    ON_NOTIFY(NM_CLICK, IDC_LIST1, &ManagerRepairFunc::OnNMClickList1)
    ON_NOTIFY(NM_DBLCLK, IDC_LIST1, &ManagerRepairFunc::OnNMDblclkList1)
    ON_BN_CLICKED(IDC_BUTTON1, &ManagerRepairFunc::OnBnClickedButton1)
END_MESSAGE_MAP()


// ManagerRepairFunc 消息处理程序

BOOL ManagerRepairFunc::OnInitDialog() {
    CDialogEx::OnInitDialog();
    CRect rect;
    // 获取编程语言列表视图控件的位置和大小
    list_control.GetClientRect(&rect);
    // 为列表视图控件添加全行选中和栅格风格    
    list_control.SetExtendedStyle(list_control.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
    // 为列表视图控件添加六列    
    list_control.InsertColumn(0, _T("报修编号"), LVCFMT_CENTER, rect.Width() / 6, 0);
    list_control.InsertColumn(1, _T("业主姓名"), LVCFMT_CENTER, rect.Width() / 6, 1);
    list_control.InsertColumn(2, _T("联系方式"), LVCFMT_CENTER, rect.Width() / 6, 2);
    list_control.InsertColumn(3, _T("报修时间"), LVCFMT_CENTER, rect.Width() / 6, 3);
    list_control.InsertColumn(4, _T("标题"), LVCFMT_CENTER, rect.Width() / 6, 4);
    list_control.InsertColumn(5, _T("报修状态"), LVCFMT_CENTER, rect.Width() / 6, 5);
    ReadMessage read_message("Data\\Repair_list.txt");
    repair_list = read_message.ReadFromFile();
    std::list<Message>::iterator it;
    int i = 0;
    for (it = repair_list.begin(); it != repair_list.end(); it++) {
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
    return true;
}




void ManagerRepairFunc::OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult)
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


void ManagerRepairFunc::OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult)
{
    LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
    // TODO:  在此添加控件通知处理程序代码
    CString str;    // 选择编号字符串
    NMLISTVIEW *pNMListView = (NMLISTVIEW*)pNMHDR;
    if (-1 != pNMListView->iItem){// 如果iItem不是-1，就说明有列表项被选择
        // 获取被选择列表项第一个子项的文本
        str = list_control.GetItemText(pNMListView->iItem, 0);
        int num = _ttoi(str);
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


void ManagerRepairFunc::OnBnClickedButton1()
{
    // TODO:  在此添加控件通知处理程序代码
    if (strLangName.GetLength() == 0) {
        AfxMessageBox(_T("请选择一条报修！"));
        return;
    }
    std::list<Message>::iterator it;
    for (it = repair_list.begin(); it != repair_list.end(); it++) {
        if (_ttoi(strLangName) == it->getNum()) {
            if (it->getState() == _T("已处理")) {
                AfxMessageBox(_T("已处理！"));
                strLangName = "";
                return;
            }
            else {
                it->setState(_T("已处理"));
                break;
            }
        }
    }
    WriteMessage write_message("Data\\Repair_list.txt");
    write_message.WriteMessageAll(repair_list);

    delete v;
    v = new ManagerRepairFunc;
    v->Create(IDD_FORMVIEW13, GetActiveWindow());
    v->ShowWindow(SW_SHOWNORMAL);
    v->MoveWindow(135, 90, 848, 451);
    AfxMessageBox(_T("更改成功！"));
}
