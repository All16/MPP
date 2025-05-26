#pragma once
#include "afxdialogex.h"


// OnBnClickedCalculeaza dialog

class OnBnClickedCalculeaza : public CDialogEx
{
	DECLARE_DYNAMIC(OnBnClickedCalculeaza)

public:
	OnBnClickedCalculeaza(CWnd* pParent = nullptr);   // standard constructor
	virtual ~OnBnClickedCalculeaza();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_APP3_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
