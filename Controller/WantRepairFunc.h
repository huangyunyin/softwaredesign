#pragma once
#include "resource.h"
#include <list>
#include "Message.h"

// WantRepairFunc �Ի���

class WantRepairFunc : public CDialogEx
{
	DECLARE_DYNAMIC(WantRepairFunc)

public:
	WantRepairFunc(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~WantRepairFunc();
    virtual BOOL OnInitDialog();

// �Ի�������
	enum { IDD = IDD_FORMVIEW2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedButton1();

private:
    std::list<Message> repair_list;
};
