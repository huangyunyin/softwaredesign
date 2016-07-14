// UserSystem.cpp : 实现文件
//

#include "stdafx.h"
#include "UserSystem.h"
#include "afxdialogex.h"
#include "SelectFuntion.h"
#include "Login.h"
#include "MFCApplicationDlg.h"

// UserSystem 对话框
extern User current_user;

IMPLEMENT_DYNAMIC(UserSystem, CDialogEx)

UserSystem::UserSystem(CWnd* pParent /*=NULL*/)
	: CDialogEx(UserSystem::IDD, pParent)
{
    currentPosition[0] = _T("基本操作->个人信息");
    currentPosition[1] = _T("基本操作->修改密码");
    currentPosition[2] = _T("报修->我要报修");
    currentPosition[3] = _T("报修->我的报修");
    currentPosition[4] = _T("投诉->我要投诉");
    currentPosition[5] = _T("投诉->我的投诉");
    currentPosition[6] = _T("缴费信息->查看缴费");
    currentPosition[7] = _T("公示信息->查看公示信息");
    currentPosition[8] = _T("公示信息->联系管理员");
}

UserSystem::~UserSystem()
{
}

void UserSystem::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_TREE1, Function_tree_init);
}


BEGIN_MESSAGE_MAP(UserSystem, CDialogEx)
    ON_NOTIFY(TVN_SELCHANGED, IDC_TREE1, &UserSystem::FunctionTree)
    ON_BN_CLICKED(IDC_BUTTON2, &UserSystem::ExitThisLogin)
END_MESSAGE_MAP()


// UserSystem 消息处理程序
BOOL UserSystem::OnInitDialog() {
    CDialogEx::OnInitDialog();
    SetWindowPos(NULL, 0, 0, 1000, 600, SWP_NOMOVE);//设置窗口的大小

    HTREEITEM hRoot;
    HTREEITEM hCataItem;

    //在基本操作框中添加结点，并且给每个结点编号，方便点击时获取是哪个被点击了
    hRoot = Function_tree_init.InsertItem(_T("基本操作"), 0, 0);
    Function_tree_init.SetItemData(hRoot, 10);
    hCataItem = Function_tree_init.InsertItem(_T("个人信息"), 1, 1, hRoot);
    Function_tree_init.SetItemData(hCataItem, 1);
    hCataItem = Function_tree_init.InsertItem(_T("修改密码"), 1, 1, hRoot);
    Function_tree_init.SetItemData(hCataItem, 2);


    hRoot = Function_tree_init.InsertItem(_T("报修"), 0, 0);
    Function_tree_init.SetItemData(hRoot, 11);
    hCataItem = Function_tree_init.InsertItem(_T("我要报修"), 1, 1, hRoot);
    Function_tree_init.SetItemData(hCataItem, 3);
    hCataItem = Function_tree_init.InsertItem(_T("我的报修"), 1, 1, hRoot);
    Function_tree_init.SetItemData(hCataItem, 4);

    hRoot = Function_tree_init.InsertItem(_T("投诉"), 0, 0);
    Function_tree_init.SetItemData(hRoot, 12);
    hCataItem = Function_tree_init.InsertItem(_T("我要投诉"), 1, 1, hRoot);
    Function_tree_init.SetItemData(hCataItem, 5);
    hCataItem = Function_tree_init.InsertItem(_T("我的投诉"), 1, 1, hRoot);
    Function_tree_init.SetItemData(hCataItem, 6);

    hRoot = Function_tree_init.InsertItem(_T("缴费信息"), 0, 0);
    Function_tree_init.SetItemData(hRoot, 13);
    hCataItem = Function_tree_init.InsertItem(_T("查看缴费"), 1, 1, hRoot);
    Function_tree_init.SetItemData(hCataItem, 7);

    hRoot = Function_tree_init.InsertItem(_T("公示信息"), 0, 0);
    Function_tree_init.SetItemData(hRoot, 14);
    hCataItem = Function_tree_init.InsertItem(_T("查看公示信息"), 1, 1, hRoot);
    Function_tree_init.SetItemData(hCataItem, 8);
    hCataItem = Function_tree_init.InsertItem(_T("联系管理员"), 1, 1, hRoot);
    Function_tree_init.SetItemData(hCataItem, 9);

    GetDlgItem(IDC_STATIC1)->SetWindowText(current_user.getRealName());
    return true;
}

//



void UserSystem::FunctionTree(NMHDR *pNMHDR, LRESULT *pResult)
{
    LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
    // TODO:  在此添加控件通知处理程序代码
    *pResult = 0;
    HTREEITEM htree = Function_tree_init.GetSelectedItem();
    int num = Function_tree_init.GetItemData(htree);
    if (num < 10) {
        GetDlgItem(IDC_STATIC2)->SetWindowText(currentPosition[num - 1]);
    }
    select.Porcess(num);
}

//用户系统退出登录按钮处理事件
void UserSystem::ExitThisLogin()
{
    // TODO:  在此添加控件通知处理程序代码
    EndDialog(IDCANCEL);
    CMFCApplicationDlg dlg;
    INT_PTR nResponse = dlg.DoModal();
}

