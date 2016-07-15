// ManagerSystem.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ManagerSystem.h"
#include "afxdialogex.h"
#include "SelectFuntion.h"
#include "Login.h"
#include "MFCApplicationDlg.h"
extern User current_user;

// ManagerSystem �Ի���

IMPLEMENT_DYNAMIC(ManagerSystem, CDialogEx)

ManagerSystem::ManagerSystem(CWnd* pParent /*=NULL*/)
	: CDialogEx(ManagerSystem::IDD, pParent)
{
    currentPosition[0] = _T("��������->������Ϣ����");
    currentPosition[1] = _T("��������->�޸�����");
    currentPosition[2] = _T("ҵ������->����ҵ��");
    currentPosition[3] = _T("ҵ������->���ҵ��");
    currentPosition[4] = _T("���޹���");
    currentPosition[5] = _T("Ͷ�߹���");
    currentPosition[6] = _T("�շѹ���->����շ�");
    currentPosition[7] = _T("�շѹ���->�鿴�շ�");
    currentPosition[8] = _T("��ʾ��Ϣ����->��ʾ��Ϣ����");
    currentPosition[9] = _T("��ʾ��Ϣ����->������ʾ��Ϣ");
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


// ManagerSystem ��Ϣ�������

BOOL ManagerSystem::OnInitDialog() {
    CDialogEx::OnInitDialog();
    SetWindowPos(NULL, 0, 0, 1000, 600, SWP_NOMOVE);//���ô��ڵĴ�С

    HTREEITEM hRoot;
    HTREEITEM hCataItem;
    hRoot = Function_tree_init.InsertItem(_T("��������"), 0, 0);
    Function_tree_init.SetItemData(hRoot, 25);
    hCataItem = Function_tree_init.InsertItem(_T("������Ϣ����"), 1, 1, hRoot);
    Function_tree_init.SetItemData(hCataItem, 15);
    hCataItem = Function_tree_init.InsertItem(_T("�޸�����"), 1, 1, hRoot);
    Function_tree_init.SetItemData(hCataItem, 16);

    hRoot = Function_tree_init.InsertItem(_T("ҵ������"), 0, 0);
    Function_tree_init.SetItemData(hRoot, 26);
    hCataItem = Function_tree_init.InsertItem(_T("����ҵ��"), 1, 1, hRoot);
    Function_tree_init.SetItemData(hCataItem, 17);
    hCataItem = Function_tree_init.InsertItem(_T("���ҵ��"), 1, 1, hRoot);
    Function_tree_init.SetItemData(hCataItem, 18);

    hRoot = Function_tree_init.InsertItem(_T("���޹���"), 0, 0);
    Function_tree_init.SetItemData(hRoot, 19);

    hRoot = Function_tree_init.InsertItem(_T("Ͷ�߹���"), 0, 0);
    Function_tree_init.SetItemData(hRoot, 20);

    hRoot = Function_tree_init.InsertItem(_T("�շѹ���"), 0, 0);
    Function_tree_init.SetItemData(hRoot, 27);
    hCataItem = Function_tree_init.InsertItem(_T("����շ�"), 1, 1, hRoot);
    Function_tree_init.SetItemData(hCataItem, 21);
    hCataItem = Function_tree_init.InsertItem(_T("�鿴�շ�"), 1, 1, hRoot);
    Function_tree_init.SetItemData(hCataItem, 22);

    hRoot = Function_tree_init.InsertItem(_T("��ʾ��Ϣ����"), 0, 0);
    Function_tree_init.SetItemData(hRoot, 28);
    hCataItem = Function_tree_init.InsertItem(_T("��ʾ��Ϣ����"), 1, 1, hRoot);
    Function_tree_init.SetItemData(hCataItem, 23);
    hCataItem = Function_tree_init.InsertItem(_T("������ʾ��Ϣ"), 1, 1, hRoot);
    Function_tree_init.SetItemData(hCataItem, 24);

    GetDlgItem(IDC_STATIC1)->SetWindowText(current_user.getRealName());
    return true;
}

void ManagerSystem::FunctionTree(NMHDR *pNMHDR, LRESULT *pResult)
{
    LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
    // TODO:  �ڴ���ӿؼ�֪ͨ����������
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
    // TODO:  �ڴ���ӿؼ�֪ͨ����������
    EndDialog(IDCANCEL);
    CMFCApplicationDlg dlg;
    INT_PTR nResponse = dlg.DoModal();
}
