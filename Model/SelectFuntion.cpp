// SelectFuntion.cpp : 实现文件
//

#include "stdafx.h"
#include "SelectFuntion.h"
#include "afxdialogex.h"
#include "PersonalMessageFunc.h"
#include "ChangePasswordFunc.h"
#include "WantRepairFunc.h"
#include "MyRepairFunc.h"
#include "WantComplaintFunc.h"
#include "MyComplaintFunc.h"
#include "CheckPaymentFunc.h"
#include "CheckPublicFunc.h"
#include "ContactManagerFunc.h"
#include "ManagerPersonalFunc.h"
#include "ManagerPasswordFunc.h"
#include "ManagerAccountFunc.h"
#include "ManagerAdduserFunc.h"
#include "ManagerRepairFunc.h"
#include "ManagerComplaintFunc.h"
#include "ManagerPaymentFunc.h"
#include "ManagerSeepaymnetFunc.h"
#include "ManagerSeepublicFunc.h"
#include "ManagerAddpublicFunc.h"
CDialogEx *v;
extern User currentUser;

// SelectFuntion 对话框

IMPLEMENT_DYNAMIC(SelectFuntion, CDialogEx)

SelectFuntion::SelectFuntion(CWnd* pParent /*=NULL*/)
	: CDialogEx(SelectFuntion::IDD, pParent)
{
}

SelectFuntion::~SelectFuntion()
{
}

void SelectFuntion::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(SelectFuntion, CDialogEx)
    ON_NOTIFY(TVN_SELCHANGED, IDC_TREE1, &SelectFuntion::OnTvnSelchangedTree1)
END_MESSAGE_MAP()


// SelectFuntion 消息处理程序

void SelectFuntion::Porcess(int num) {
    if (num < 10 && v != NULL) {
        delete v;
    }
    if (num > 14 && num < 25 && v != NULL) {
        delete v;
    }
    if (num == 1) {
        //点击个人信息功能
        v = new PersonalMessageFunc();
        v->Create(IDD_FORMVIEW, GetActiveWindow());
        v->ShowWindow(SW_SHOWNORMAL);
    }
    else if (num == 2) {
        //点击修改密码功能
        v = new ChangePasswordFunc;
        v->Create(IDD_FORMVIEW1, GetActiveWindow());
        v->ShowWindow(SW_SHOWNORMAL);
    }
    else if (num == 3) {
        //点击我要报修功能
        v = new WantRepairFunc;
        v->Create(IDD_FORMVIEW2, GetActiveWindow());
        v->ShowWindow(SW_SHOWNORMAL);
    }
    else if (num == 4) {
        //点击我的报修功能
        v = new MyRepairFunc;
        v->Create(IDD_FORMVIEW3, GetActiveWindow());
        v->ShowWindow(SW_SHOWNORMAL);
    }
    else if (num == 5) {
        //点击我要投诉功能
        v = new WantComplaintFunc;
        v->Create(IDD_FORMVIEW4, GetActiveWindow());
        v->ShowWindow(SW_SHOWNORMAL);
    }
    else if (num == 6) {
        //点击我的投诉功能
        v = new MyComplaintFunc;
        v->Create(IDD_FORMVIEW5, GetActiveWindow());
        v->ShowWindow(SW_SHOWNORMAL);
    }
    else if (num == 7) {
        v = new CheckPaymentFunc;
        v->Create(IDD_FORMVIEW6, GetActiveWindow());
        v->ShowWindow(SW_SHOWNORMAL);
    }
    else if (num == 8) {
        v = new CheckPublicFunc;
        v->Create(IDD_FORMVIEW7, GetActiveWindow());
        v->ShowWindow(SW_SHOWNORMAL);
    }
    else if (num == 9) {
        v = new ContactManagerFunc;
        v->Create(IDD_FORMVIEW8, GetActiveWindow());
        v->ShowWindow(SW_SHOWNORMAL);
    }
    else if (num == 15) {
        v = new ManagerPersonalFunc;
        v->Create(IDD_FORMVIEW9, GetActiveWindow());
        v->ShowWindow(SW_SHOWNORMAL);
    }
    else if (num == 16) {
        v = new ManagerPasswordFunc;
        v->Create(IDD_FORMVIEW10, GetActiveWindow());
        v->ShowWindow(SW_SHOWNORMAL);
    }
    else if (num == 17) {
        v = new ManagerAccountFunc;
        v->Create(IDD_FORMVIEW11, GetActiveWindow());
        v->ShowWindow(SW_SHOWNORMAL);
    }
    else if (num == 18) {
        v = new ManagerAdduserFunc;
        v->Create(IDD_FORMVIEW12, GetActiveWindow());
        v->ShowWindow(SW_SHOWNORMAL);
    }
    else if (num == 19) {
        v = new ManagerRepairFunc;
        v->Create(IDD_FORMVIEW13, GetActiveWindow());
        v->ShowWindow(SW_SHOWNORMAL);
    }
    else if (num == 20) {
        v = new ManagerComplaintFunc;
        v->Create(IDD_FORMVIEW14, GetActiveWindow());
        v->ShowWindow(SW_SHOWNORMAL);
    }
    else if (num == 21) {
        v = new ManagerPaymentFunc;
        v->Create(IDD_FORMVIEW15, GetActiveWindow());
        v->ShowWindow(SW_SHOWNORMAL);
    }
    else if (num == 22) {
        v = new ManagerSeepaymnetFunc;
        v->Create(IDD_FORMVIEW16, GetActiveWindow());
        v->ShowWindow(SW_SHOWNORMAL);
    }
    else if (num == 23) {
        v = new ManagerSeepublicFunc;
        v->Create(IDD_FORMVIEW17, GetActiveWindow());
        v->ShowWindow(SW_SHOWNORMAL);
    }
    else if (num == 24) {
        v = new ManagerAddpublicFunc;
        v->Create(IDD_FORMVIEW18, GetActiveWindow());
        v->ShowWindow(SW_SHOWNORMAL);
    }
    if (v != NULL) {
        v->MoveWindow(135, 90, 848, 451);
    }
}

void SelectFuntion::OnTvnSelchangedTree1(NMHDR *pNMHDR, LRESULT *pResult)
{
    LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
    // TODO:  在此添加控件通知处理程序代码
    *pResult = 0;
}

