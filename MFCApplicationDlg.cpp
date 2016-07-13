
// MFCApplicationDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication.h"
#include "MFCApplicationDlg.h"
#include "afxdialogex.h"
#include "Register.h"
#include "Login.h"
#include "UserSystem.h"
#include "ManagerSystem.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框
class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplicationDlg 对话框



CMFCApplicationDlg::CMFCApplicationDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCApplicationDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplicationDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_COMBO1, Login_identity);
}

BEGIN_MESSAGE_MAP(CMFCApplicationDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED(IDC_BUTTON9, &CMFCApplicationDlg::OnBnClickedButton9)
    ON_COMMAND(ID_32772, &CMFCApplicationDlg::MenuExit)
    ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplicationDlg::OnBnClickedButton1)
    ON_COMMAND(ID_32771, &CMFCApplicationDlg::MenuReLogin)
END_MESSAGE_MAP()


// CMFCApplicationDlg 消息处理程序

BOOL CMFCApplicationDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码




    SetWindowPos(NULL, 0, 0, 1000, 600, SWP_NOMOVE);//设置窗口的大小

    //登录界面小区管理系统字体设置
    font.CreatePointFont(300, _T("华文行楷"), NULL);
    GetDlgItem(IDC_STATIC)->SetFont(&font);

    //下拉身份菜单选择
    Login_identity.AddString(_T("业主"));
    Login_identity.AddString(_T("管理员"));

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCApplicationDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCApplicationDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCApplicationDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//菜单退出
void CMFCApplicationDlg::MenuExit()
{
    // TODO:  在此添加命令处理程序代码
    exit(0);
}

//菜单重新登录
void CMFCApplicationDlg::MenuReLogin()
{
    // TODO:  在此添加命令处理程序代码
    ::SendMessage(GetActiveWindow()->m_hWnd, WM_CLOSE, 0, 0);
    //EndDialog(IDCANCEL);
    CMFCApplicationDlg dlg;
    dlg.DoModal();
}

//登录界面的登录按钮事件
void CMFCApplicationDlg::OnBnClickedButton9()
{
    // TODO:  在此添加控件通知处理程序代码
    Login myLogin = new Login();
    CString login_name;
    CString login_password;
    int login_identity;
    GetDlgItem(IDC_EDIT2)->GetWindowText(login_name);
    GetDlgItem(IDC_EDIT3)->GetWindowText(login_password);
    login_identity = Login_identity.GetCurSel();
    if (myLogin.Judge(login_name, login_password, login_identity)) {
        //登录成功
        if (login_identity == 0) {
            //管理员登录，进入管理员主系统界面
            EndDialog(IDCANCEL);
            UserSystem myDialog;
            myDialog.DoModal();
        }
        else{
            //用户登录，进入用户主系统界面
            EndDialog(IDCANCEL);
            ManagerSystem myDialog;
            myDialog.DoModal();
        }
    }
}


//登录界面点击注册按钮跳转到注册页面
void CMFCApplicationDlg::OnBnClickedButton1()
{
    // TODO:  在此添加控件通知处理程序代码
    EndDialog(IDCANCEL);
    Register user_register;
    user_register.DoModal();
}
