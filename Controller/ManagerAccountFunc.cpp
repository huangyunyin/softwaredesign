// ManagerAccountFunc.cpp : 实现文件
//

#include "stdafx.h"
#include "ManagerAccountFunc.h"
#include "afxdialogex.h"
#include "Login.h"
#include "User.h"
#include "PersonalMessageFunc.h"
#include "ReadPeople.h"
#include "WritePeople.h"
extern CDialogEx *v;
// ManagerAccountFunc 对话框

IMPLEMENT_DYNAMIC(ManagerAccountFunc, CDialogEx)

ManagerAccountFunc::ManagerAccountFunc(CWnd* pParent /*=NULL*/)
	: CDialogEx(ManagerAccountFunc::IDD, pParent)
{
    user_name = "";
    m_Row = -1;
    m_Col = -1;
}

ManagerAccountFunc::~ManagerAccountFunc()
{
}

void ManagerAccountFunc::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_LIST1, list_control);
    DDX_Control(pDX, IDC_EDIT1, m_edit);
}


BEGIN_MESSAGE_MAP(ManagerAccountFunc, CDialogEx)
    ON_NOTIFY(NM_CLICK, IDC_LIST1, &ManagerAccountFunc::OnNMClickList1)
    ON_BN_CLICKED(IDC_BUTTON3, &ManagerAccountFunc::OnBnClickedButton3)
    ON_NOTIFY(NM_DBLCLK, IDC_LIST1, &ManagerAccountFunc::OnNMDblclkList1)
    ON_BN_CLICKED(IDC_BUTTON1, &ManagerAccountFunc::OnBnClickedButton1)
END_MESSAGE_MAP()


// ManagerAccountFunc 消息处理程序


BOOL ManagerAccountFunc::OnInitDialog() {
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

    ReadPeople read_people("Data\\User_list.txt");
    list<User> user_list = read_people.ReadFromFile();
    std::list<User>::iterator it;
    int i = 0;
    for (it = user_list.begin(); it != user_list.end(); it++) {
        list_control.InsertItem(i, it->getUserName());
        list_control.SetItemText(i, 1, it->getPassword());
        list_control.SetItemText(i, 2, it->getRealName());
        list_control.SetItemText(i, 3, it->getIdNumber());
        list_control.SetItemText(i, 4, it->getAddress());
        list_control.SetItemText(i, 5, it->getPhone());
        list_control.SetItemText(i, 6, it->getMail());
        i++;
    }
    m_edit.ShowWindow(SW_HIDE);
    return true;
}

//获取被选中的条目
void ManagerAccountFunc::OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
    LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
    // TODO:  在此添加控件通知处理程序代码
    *pResult = 0;
    NMLISTVIEW *pNMListView = (NMLISTVIEW*)pNMHDR;
    if (-1 != pNMListView->iItem){// 如果iItem不是-1，就说明有列表项被选择
        // 获取被选择列表项第一个子项的文本
        user_name = list_control.GetItemText(pNMListView->iItem, 0);
    }
}


//双击编辑单元格修改数据
void ManagerAccountFunc::OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult)
{
    LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
    // TODO:  在此添加控件通知处理程序代码
    NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
    CRect rc;
    if (m_Col > 0) {
        CString tem;
        m_edit.GetWindowText(tem);    //得到用户输入的新的内容
        list_control.SetItemText(m_Row, m_Col, tem);   //设置编辑框的新内容
        m_edit.ShowWindow(SW_HIDE);                //应藏编辑框
    }
    m_Row = pNMListView->iItem;//获得选中的行
    m_Col = pNMListView->iSubItem;//获得选中列


    if (pNMListView->iSubItem != 0) //如果选择的是子项;
    {
        list_control.GetSubItemRect(m_Row, m_Col, LVIR_LABEL, rc);//获得子项的RECT；
        m_edit.SetParent(&list_control);//转换坐标为列表框中的坐标
        m_edit.MoveWindow(rc);//移动Edit到RECT坐在的位置;
        m_edit.SetWindowText(list_control.GetItemText(m_Row, m_Col));//将该子项中的值放在Edit控件中；
        m_edit.ShowWindow(SW_SHOW);//显示Edit控件；
        m_edit.SetFocus();//设置Edit焦点
        m_edit.ShowCaret();//显示光标
        m_edit.SetSel(-1);//将光标移动到最后
    }
    *pResult = 0;
}


//删除业主按钮处理函数
void ManagerAccountFunc::OnBnClickedButton3()
{
    // TODO:  在此添加控件通知处理程序代码
    if (user_name.GetLength() != 0) {
        ReadPeople read_people("Data\\User_list.txt");
        read_people.deletePeople(user_name);

        delete v;
        v = new ManagerAccountFunc;
        v->Create(IDD_FORMVIEW11, GetActiveWindow());
        v->ShowWindow(SW_SHOWNORMAL);
        v->MoveWindow(135, 90, 848, 451);
        AfxMessageBox(_T("删除成功！"));
    }
    else {
        AfxMessageBox(_T("请选择用户！"));
    }

}


//保存修改按钮处理函数
void ManagerAccountFunc::OnBnClickedButton1()
{
    if (m_Col > 0) {
        CString tem;
        m_edit.GetWindowText(tem);    //得到用户输入的新的内容
        list_control.SetItemText(m_Row, m_Col, tem);   //设置编辑框的新内容
        m_edit.ShowWindow(SW_HIDE);                //隐藏编辑框
    }
    // TODO:  在此添加控件通知处理程序代码
    m_edit.ShowWindow(SW_HIDE);
    list<User> user_list;
    CString user_name;
    CString password;
    CString real_name;
    CString id_number;
    CString address;
    CString phone;
    CString mail;
    int i = 0;
    while (1) {
        user_name = list_control.GetItemText(i, 0);
        if (user_name == "") {
            break;
        }
        password = list_control.GetItemText(i, 1);
        real_name = list_control.GetItemText(i, 2);
        id_number = list_control.GetItemText(i, 3);
        address = list_control.GetItemText(i, 4);
        phone = list_control.GetItemText(i, 5);
        mail = list_control.GetItemText(i, 6);
        user_list.push_back(User(user_name, password, real_name, id_number, address, phone, mail));
        i++;
    }
    
    WritePeople write_people;
    write_people.WriteAllPeople("Data\\User_list.txt", user_list);
    AfxMessageBox(_T("保存成功！"));
}
