#pragma once
#include "resource.h"
#include "User.h"

// SelectFuntion 对话框

class SelectFuntion : public CDialogEx
{
	DECLARE_DYNAMIC(SelectFuntion)

public:
	SelectFuntion(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~SelectFuntion();
    void Porcess(int num);

// 对话框数据
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnTvnSelchangedTree1(NMHDR *pNMHDR, LRESULT *pResult);

};
