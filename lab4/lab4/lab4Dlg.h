#pragma once
#include "afxwin.h"

class Clab4Dlg : public CDialogEx
{
public:
    Clab4Dlg(CWnd* pParent = nullptr); // Constructor

#ifdef AFX_DESIGN_TIME
    enum { IDD = IDD_LAB4_DIALOG };
#endif

protected:
    virtual void DoDataExchange(CDataExchange* pDX);
    virtual BOOL OnInitDialog();

    HICON m_hIcon;

    afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
    afx_msg void OnPaint();
    afx_msg HCURSOR OnQueryDragIcon();

    DECLARE_MESSAGE_MAP()

private:
    int Operatie;    // Stores the selected operation
    CString Text;    // Stores UI display text
    CStatic StaticText;
    CEdit EditA;
    CEdit EditB;
    CEdit EditIesire;
    CEdit EditN;

public:
    afx_msg void OnBnClickedCalculeaza();   // Handles calculation logic
    afx_msg void OnBnClickedCancel();       // Clears input fields
    afx_msg void OnBnClickedOperatie8();
};
