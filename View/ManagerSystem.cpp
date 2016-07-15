// ManagerSystem.cpp : 实现文件
//

#include "stdafx.h"
#include "ManagerSystem.h"
#include "afxdialogex.h"
#include "SelectFuntion.h"
#include "Login.h"
#include "MFCApplicationDlg.h"
extern User current_user;

// ManagerSystem 对话框

IMPLEMENT_DYNAMIC(ManagerSystem, CDialogEx)

ManagerSystem::ManagerSystem(CWnd* pParent /*=NULL*/)
	: CDialogEx(ManagerSystem::IDD, pParent)
{
    currentPosition[0] = _T("基本操作->个人信息管理");
    currentPosition[1] = _T("基本操作->修改密码");
    currentPosition[2] = _T("业主管理->管理业主");
    currentPosition[3] = _T("业主管理->添加业主");
    currentPosition[4] = _T("报修管理");
    currentPosition[5] = _T("投诉管理");
    currentPosition[6] = _T("收费管理->添加收费");
    currentPosition[7] = _T("收费管理->查看收费");
    currentPosition[8] = _T("公示信息管理->公示信息管理");
    currentPosition[9] = _T("公示信息管理->发布公示信息");
}

ManagerSystem::~ManagerSystem()
{
}

void ManagerSystem::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_TREE1, Function_tree_init);
}


BEGIN_MESSAGE_MAP(ManagerSystem, CDialogEx)
    ON_NOTIFY(TVN_SELCHANGED, IDC_TREE1, &ManagerSystem::FunctionTree)
    ON_BN_CLICKED(IDC_BUTTON2, &ManagerSystem::OnBnClickedButton2)
END_MESSAGE_MAP()


// ManagerSystem 消息处理程序

BOOL ManagerSystem::OnInitDialog() {
    CDialogEx::OnInitDialog();
    SetWindowPos(NULL, 0, 0, 1000, 600, SWP_NOMOVE);//设置窗口的大小

    HTREEITEM hRoot;
    HTREEITEM hCataItem;
    hRoot = Function_tree_init.InsertItem(_T("基本操作"), 0, 0);
    Function_tree_init.SetItemData(hRoot, 25);
    hCataItem = Function_tree_init.InsertItem(_T("个人信息管理"), 1, 1, hRoot);
    Function_tree_init.SetItemData(hCataItem, 15);
    hCataItem = Function_tree_init.InsertItem(_T("修改密码"), 1, 1, hRoot);
    Function_tree_init.SetItemData(hCataItem, 16);

    hRoot = Function_tree_init.InsertItem(_T("业主管理"), 0, 0);
    Function_tree_init.SetItemData(hRoot, 26);
    hCataItem = Function_tree_init.InsertItem(_T("管理业主"), 1, 1, hRoot);
    Function_tree_init.SetItemData(hCataItem, 17);
    hCataItem = Function_tree_init.InsertItem(_T("添加业主"), 1, 1, hRoot);
    Function_tree_init.SetItemData(hCataItem, 18);

    hRoot = Function_tree_init.InsertItem(_T("报修管理"), 0, 0);
    Function_tree_init.SetItemData(hRoot, 19);

    hRoot = Function_tree_init.InsertItem(_T("投诉管理"), 0, 0);
    Function_tree_init.SetItemData(hRoot, 20);

    hRoot = Function_tree_init.InsertItem(_T("收费管理"), 0, 0);
    Function_tree_init.SetItemData(hRoot, 27);
    hCataItem = Function_tree_init.InsertItem(_T("添加收费"), 1, 1, hRoot);
    Function_tree_init.SetItemData(hCataItem, 21);
    hCataItem = Function_tree_init.InsertItem(_T("查看收费"), 1, 1, hRoot);
    Function_tree_init.SetItemData(hCataItem, 22);

    hRoot = Function_tree_init.InsertItem(_T("公示信息管理"), 0, 0);
    Function_tree_init.SetItemData(hRoot, 28);
    hCataItem = Function_tree_init.InsertItem(_T("公示信息管理"), 1, 1, hRoot);
    Function_tree_init.SetItemData(hCataItem, 23);
    hCataItem = Function_tree_init.InsertItem(_T("发布公示信息"), 1, 1, hRoot);
    Function_tree_init.SetItemData(hCataItem, 24);

    GetDlgItem(IDC_STATIC1)->SetWindowText(current_user.getRealName());
    return true;
}

void ManagerSystem::FunctionTree(NMHDR *pNMHDR, LRESULT *pResult)
{
    LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
    // TODO:  在此添加控件通知处理程序代码
    *pResult = 0;
    HTREEITEM htree = Function_tree_init.GetSelectedItem();
    int num = Function_tree_init.GetItemData(htree);
    if (num > 14 && num < 25) {
        GetDlgItem(IDC_STATIC2)->SetWindowText(currentPosition[num - 15]);
    }
    select.Porcess(num);
}


void ManagerSystem::OnBnClickedButton2()
{
    // TODO:  在此添加控件通知处理程序代码
    EndDialog(IDCANCEL);
    CMFCApplicationDlg dlg;
    INT_PTR nResponse = dlg.DoModal();
}
