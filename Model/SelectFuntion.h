#pragma once
#include "resource.h"
#include "User.h"

// SelectFuntion �Ի���

class SelectFuntion : public CDialogEx
{
	DECLARE_DYNAMIC(SelectFuntion)

public:
	SelectFuntion(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~SelectFuntion();
    void Porcess(int num);

// �Ի�������
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnTvnSelchangedTree1(NMHDR *pNMHDR, LRESULT *pResult);

};
