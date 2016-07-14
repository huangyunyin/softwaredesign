// CheckPublicFunc.cpp : 实现文件
//

#include "stdafx.h"
#include "CheckPublicFunc.h"
#include "afxdialogex.h"
#include "Login.h"
#include "Message.h"
#include "User.h"
#include "ReadMessage.h"

// CheckPublicFunc 对话框

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


// CheckPublicFunc 消息处理程序

BOOL CheckPublicFunc::OnInitDialog() {
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



void CheckPublicFunc::OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult)
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
