
// MFCApplicationDlg.cpp : ʵ���ļ�
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

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���
class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CMFCApplicationDlg �Ի���



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


// CMFCApplicationDlg ��Ϣ�������

BOOL CMFCApplicationDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������




    SetWindowPos(NULL, 0, 0, 1000, 600, SWP_NOMOVE);//���ô��ڵĴ�С

    //��¼����С������ϵͳ��������
    font.CreatePointFont(300, _T("�����п�"), NULL);
    GetDlgItem(IDC_STATIC)->SetFont(&font);

    //������ݲ˵�ѡ��
    Login_identity.AddString(_T("ҵ��"));
    Login_identity.AddString(_T("����Ա"));

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFCApplicationDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMFCApplicationDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//�˵��˳�
void CMFCApplicationDlg::MenuExit()
{
    // TODO:  �ڴ���������������
    exit(0);
}

//�˵����µ�¼
void CMFCApplicationDlg::MenuReLogin()
{
    // TODO:  �ڴ���������������
    ::SendMessage(GetActiveWindow()->m_hWnd, WM_CLOSE, 0, 0);
    //EndDialog(IDCANCEL);
    CMFCApplicationDlg dlg;
    dlg.DoModal();
}

//��¼����ĵ�¼��ť�¼�
void CMFCApplicationDlg::OnBnClickedButton9()
{
    // TODO:  �ڴ���ӿؼ�֪ͨ����������
    Login myLogin = new Login();
    CString login_name;
    CString login_password;
    int login_identity;
    GetDlgItem(IDC_EDIT2)->GetWindowText(login_name);
    GetDlgItem(IDC_EDIT3)->GetWindowText(login_password);
    login_identity = Login_identity.GetCurSel();
    if (myLogin.Judge(login_name, login_password, login_identity)) {
        //��¼�ɹ�
        if (login_identity == 0) {
            //����Ա��¼���������Ա��ϵͳ����
            EndDialog(IDCANCEL);
            UserSystem myDialog;
            myDialog.DoModal();
        }
        else{
            //�û���¼�������û���ϵͳ����
            EndDialog(IDCANCEL);
            ManagerSystem myDialog;
            myDialog.DoModal();
        }
    }
}


//��¼������ע�ᰴť��ת��ע��ҳ��
void CMFCApplicationDlg::OnBnClickedButton1()
{
    // TODO:  �ڴ���ӿؼ�֪ͨ����������
    EndDialog(IDCANCEL);
    Register user_register;
    user_register.DoModal();
}
