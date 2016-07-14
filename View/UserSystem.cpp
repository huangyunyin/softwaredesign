// UserSystem.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "UserSystem.h"
#include "afxdialogex.h"
#include "SelectFuntion.h"
#include "Login.h"
#include "MFCApplicationDlg.h"

// UserSystem �Ի���
extern User current_user;

IMPLEMENT_DYNAMIC(UserSystem, CDialogEx)

UserSystem::UserSystem(CWnd* pParent /*=NULL*/)
	: CDialogEx(UserSystem::IDD, pParent)
{
    currentPosition[0] = _T("��������->������Ϣ");
    currentPosition[1] = _T("��������->�޸�����");
    currentPosition[2] = _T("����->��Ҫ����");
    currentPosition[3] = _T("����->�ҵı���");
    currentPosition[4] = _T("Ͷ��->��ҪͶ��");
    currentPosition[5] = _T("Ͷ��->�ҵ�Ͷ��");
    currentPosition[6] = _T("�ɷ���Ϣ->�鿴�ɷ�");
    currentPosition[7] = _T("��ʾ��Ϣ->�鿴��ʾ��Ϣ");
    currentPosition[8] = _T("��ʾ��Ϣ->��ϵ����Ա");
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


// UserSystem ��Ϣ�������
BOOL UserSystem::OnInitDialog() {
    CDialogEx::OnInitDialog();
    SetWindowPos(NULL, 0, 0, 1000, 600, SWP_NOMOVE);//���ô��ڵĴ�С

    HTREEITEM hRoot;
    HTREEITEM hCataItem;

    //�ڻ�������������ӽ�㣬���Ҹ�ÿ������ţ�������ʱ��ȡ���ĸ��������
    hRoot = Function_tree_init.InsertItem(_T("��������"), 0, 0);
    Function_tree_init.SetItemData(hRoot, 10);
    hCataItem = Function_tree_init.InsertItem(_T("������Ϣ"), 1, 1, hRoot);
    Function_tree_init.SetItemData(hCataItem, 1);
    hCataItem = Function_tree_init.InsertItem(_T("�޸�����"), 1, 1, hRoot);
    Function_tree_init.SetItemData(hCataItem, 2);


    hRoot = Function_tree_init.InsertItem(_T("����"), 0, 0);
    Function_tree_init.SetItemData(hRoot, 11);
    hCataItem = Function_tree_init.InsertItem(_T("��Ҫ����"), 1, 1, hRoot);
    Function_tree_init.SetItemData(hCataItem, 3);
    hCataItem = Function_tree_init.InsertItem(_T("�ҵı���"), 1, 1, hRoot);
    Function_tree_init.SetItemData(hCataItem, 4);

    hRoot = Function_tree_init.InsertItem(_T("Ͷ��"), 0, 0);
    Function_tree_init.SetItemData(hRoot, 12);
    hCataItem = Function_tree_init.InsertItem(_T("��ҪͶ��"), 1, 1, hRoot);
    Function_tree_init.SetItemData(hCataItem, 5);
    hCataItem = Function_tree_init.InsertItem(_T("�ҵ�Ͷ��"), 1, 1, hRoot);
    Function_tree_init.SetItemData(hCataItem, 6);

    hRoot = Function_tree_init.InsertItem(_T("�ɷ���Ϣ"), 0, 0);
    Function_tree_init.SetItemData(hRoot, 13);
    hCataItem = Function_tree_init.InsertItem(_T("�鿴�ɷ�"), 1, 1, hRoot);
    Function_tree_init.SetItemData(hCataItem, 7);

    hRoot = Function_tree_init.InsertItem(_T("��ʾ��Ϣ"), 0, 0);
    Function_tree_init.SetItemData(hRoot, 14);
    hCataItem = Function_tree_init.InsertItem(_T("�鿴��ʾ��Ϣ"), 1, 1, hRoot);
    Function_tree_init.SetItemData(hCataItem, 8);
    hCataItem = Function_tree_init.InsertItem(_T("��ϵ����Ա"), 1, 1, hRoot);
    Function_tree_init.SetItemData(hCataItem, 9);

    GetDlgItem(IDC_STATIC1)->SetWindowText(current_user.getRealName());
    return true;
}

//



void UserSystem::FunctionTree(NMHDR *pNMHDR, LRESULT *pResult)
{
    LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
    // TODO:  �ڴ���ӿؼ�֪ͨ����������
    *pResult = 0;
    HTREEITEM htree = Function_tree_init.GetSelectedItem();
    int num = Function_tree_init.GetItemData(htree);
    if (num < 10) {
        GetDlgItem(IDC_STATIC2)->SetWindowText(currentPosition[num - 1]);
    }
    select.Porcess(num);
}

//�û�ϵͳ�˳���¼��ť�����¼�
void UserSystem::ExitThisLogin()
{
    // TODO:  �ڴ���ӿؼ�֪ͨ����������
    EndDialog(IDCANCEL);
    CMFCApplicationDlg dlg;
    INT_PTR nResponse = dlg.DoModal();
}

