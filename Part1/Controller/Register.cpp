// Register.cpp : 实现文件
//
#include <atlbase.h>
#include "stdafx.h"
#include "MFCApplication.h"
#include "Register.h"
#include "MFCApplicationDlg.h"
#include "afxdialogex.h"
#include "ReadPeople.h"
#include "User.h"
#include "WritePeople.h"

// Register 对话框

IMPLEMENT_DYNAMIC(Register, CDialogEx)

Register::Register(CWnd* pParent /*=NULL*/)
	: CDialogEx(Register::IDD, pParent)
{

}

Register::~Register()
{

}

//重载初始化函数，对注册界面对话框进行初始化
BOOL Register::OnInitDialog() {
    CDialogEx::OnInitDialog();
    //注册界面小区管理系统字体设置
    SetWindowPos(NULL, 0, 0, 1000, 600, SWP_NOMOVE);//设置窗口的大小
    font.CreatePointFont(300, _T("华文行楷"), NULL);
    GetDlgItem(IDC_STATIC)->SetFont(&font);
    return true;
}

void Register::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Register, CDialogEx)
    ON_BN_CLICKED(IDC_BUTTON2, &Register::OnBnClickedButton2)
    ON_BN_CLICKED(IDC_BUTTON1, &Register::OnBnClickedButton1)
END_MESSAGE_MAP()


// Register 消息处理程序


void Register::OnBnClickedButton2()
{
    // TODO:  在此添加控件通知处理程序代码
    EndDialog(IDOK);
    CMFCApplicationDlg dlg;
    INT_PTR nResponse = dlg.DoModal();
}


void Register::OnBnClickedButton1()
{
    // TODO:  在此添加控件通知处理程序代码
    GetDlgItem(IDC_EDIT1)->GetWindowText(name);
    GetDlgItem(IDC_EDIT2)->GetWindowText(password);
    GetDlgItem(IDC_EDIT3)->GetWindowText(password_confirm);
    GetDlgItem(IDC_EDIT4)->GetWindowText(user_name);
    GetDlgItem(IDC_EDIT5)->GetWindowText(id_number);
    GetDlgItem(IDC_EDIT6)->GetWindowText(address);
    GetDlgItem(IDC_EDIT7)->GetWindowText(phone_number);
    GetDlgItem(IDC_EDIT8)->GetWindowText(mail);

    if (name.GetLength() == 0){
        //用户名为空
        AfxMessageBox(_T("用户名不能为空"));
        return;
    }
    if (password.GetLength() < 8) {
        //密码长度不足
        AfxMessageBox(_T("密码长度应不小于8！"));
        return;
    }
    if (password != password_confirm) {
        //两次密码不匹配
        AfxMessageBox(_T("两次密码不相同！"));
        return;
    }
    int i = 0;
    while (i < name.GetLength()) {
        if (isRightType(name[i])) {
            i++;
        }
        else {
            AfxMessageBox(_T("用户名格式不正确！"));
            return;
        }
    }
    i = 0;
    while (i < password.GetLength()) {
        if (isRightType(password[i])) {
            i++;
        }
        else {
            AfxMessageBox(_T("密码格式不正确！"));
            return;
        }
    }

    ReadPeople read_people("Data\\User_list.txt");
    list<User>::iterator it;
    if (read_people.isExist(name)) {
        AfxMessageBox(_T("用户名已存在！"));
        return;
    }

    read_people = ReadPeople("Data\\Register_list.txt");
    if (read_people.isExist(name)) {
        AfxMessageBox(_T("用户名已存在！"));
        return;
    }

    //允许注册
    User user = User(name, password, user_name, id_number, address, phone_number, mail);
    WritePeople write_people;
    write_people.WritePeopleAfter("Data\\Register_list.txt", user);
    if (AfxMessageBox(_T("申请成功，请等待核实！"))) {
        EndDialog(IDOK);
        CMFCApplicationDlg dlg;
        INT_PTR nResponse = dlg.DoModal();
    }
}
//用户名和密码的格式
bool Register::isRightType(char ch) {
    if ((ch > 64 && ch < 91) || (ch > 96 && ch < 123) || (ch > 47 && ch < 58)) {
        return true;
    }
    return false;
}
