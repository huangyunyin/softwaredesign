#pragma once
#include "resource.h"
#include <list>
#include "Message.h"

// ManagerAddpublicFunc �Ի���

class ManagerAddpublicFunc : public CDialogEx
{
	DECLARE_DYNAMIC(ManagerAddpublicFunc)

public:
	ManagerAddpublicFunc(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ManagerAddpublicFunc();
    virtual BOOL OnInitDialog();

// �Ի�������
	enum { IDD = IDD_FORMVIEW18 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedButton1();

private:
    std::list<Message> public_list;
};
