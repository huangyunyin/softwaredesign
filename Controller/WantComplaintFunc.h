#pragma once
#include "resource.h"
#include <list>
#include "Message.h"

// WantComplaintFunc �Ի���

class WantComplaintFunc : public CDialogEx
{
	DECLARE_DYNAMIC(WantComplaintFunc)

public:
	WantComplaintFunc(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~WantComplaintFunc();
    virtual BOOL OnInitDialog();

// �Ի�������
	enum { IDD = IDD_FORMVIEW4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedButton1();
    
private:
    std::list<Message> complaint_list;
};
