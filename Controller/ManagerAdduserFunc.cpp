// ManagerAdduserFunc.cpp : 实现文件
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


// ManagerAdduserFunc 对话框

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


// ManagerAdduserFunc 消息处理程序

BOOL ManagerAdduserFunc::OnInitDialog() {
    CDialogEx::OnInitDialog();
    CRect rect;
    // 获取编程语言列表视图控件的位置和大小
    list_control.GetClientRect(&rect);
    // 为列表视图控件添加全行选中和栅格风格
    list_control.SetExtendedStyle(list_control.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
    // 为列表视图控件添加八列
    list_control.InsertColumn(0, _T("用户名"), LVCFMT_CENTER, rect.Width() / 7, 0);
    list_control.InsertColumn(1, _T("密码"), LVCFMT_CENTER, rect.Width() / 7, 1);
    list_control.InsertColumn(2, _T("业主名"), LVCFMT_CENTER, rect.Width() / 7, 2);
    list_control.InsertColumn(3, _T("身份证号"), LVCFMT_CENTER, rect.Width() / 7, 3);
    list_control.InsertColumn(4, _T("住址"), LVCFMT_CENTER, rect.Width() / 7, 4);
    list_control.InsertColumn(5, _T("联系方式"), LVCFMT_CENTER, rect.Width() / 7, 5);
    list_control.InsertColumn(6, _T("邮箱"), LVCFMT_CENTER, rect.Width() / 7, 6);

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
    // TODO:  在此添加控件通知处理程序代码
    NMLISTVIEW *pNMListView = (NMLISTVIEW*)pNMHDR;
    if (-1 != pNMListView->iItem){// 如果iItem不是-1，就说明有列表项被选择
        // 获取被选择列表项第一个子项的文本
        strLangName = list_control.GetItemText(pNMListView->iItem, 0);
    }
    *pResult = 0;
}



//添加按钮处理函数
void ManagerAdduserFunc::OnBnClickedButton1()
{
    // TODO:  在此添加控件通知处理程序代码
    if (strLangName.GetLength() == 0) {
        AfxMessageBox(_T("请选择用户！"));
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
    AfxMessageBox(_T("添加成功！"));
}



//拒绝按钮处理函数
void ManagerAdduserFunc::OnBnClickedButton2()
{
    // TODO:  在此添加控件通知处理程序代码
    if (strLangName.GetLength() == 0) {
        AfxMessageBox(_T("请选择用户！"));
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
    AfxMessageBox(_T("拒绝成功！"));
}
