// MyRepairFunc.cpp : 实现文件
//

#include "stdafx.h"
#include "MyRepairFunc.h"
#include "afxdialogex.h"
#include "Message.h"
#include "Login.h"
#include "User.h"
#include "ReadMessage.h"
extern User current_user;

// MyRepairFunc 对话框

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


// MyRepairFunc 消息处理程序
BOOL MyRepairFunc::OnInitDialog() {
    CDialogEx::OnInitDialog();
    CRect rect;
    // 获取编程语言列表视图控件的位置和大小
    programLangList.GetClientRect(&rect);
    // 为列表视图控件添加全行选中和栅格风格    
    programLangList.SetExtendedStyle(programLangList.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
    // 为列表视图控件添加六列    
    programLangList.InsertColumn(0, _T("报修编号"), LVCFMT_CENTER, rect.Width() / 6, 0);
    programLangList.InsertColumn(1, _T("业主姓名"), LVCFMT_CENTER, rect.Width() / 6, 1);
    programLangList.InsertColumn(2, _T("联系方式"), LVCFMT_CENTER, rect.Width() / 6, 2);
    programLangList.InsertColumn(3, _T("报修时间"), LVCFMT_CENTER, rect.Width() / 6, 3);
    programLangList.InsertColumn(4, _T("标题"), LVCFMT_CENTER, rect.Width() / 6, 4);
    programLangList.InsertColumn(5, _T("报修状态"), LVCFMT_CENTER, rect.Width() / 6, 5);

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


//点击某一行条目弹出事件详细信息
void MyRepairFunc::OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult)
{
    LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
    // TODO:  在此添加控件通知处理程序代码
    CString strLangName;    // 选择编号字符串
    NMLISTVIEW *pNMListView = (NMLISTVIEW*)pNMHDR;
    if (-1 != pNMListView->iItem){// 如果iItem不是-1，就说明有列表项被选择
        // 获取被选择列表项第一个子项的文本
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
