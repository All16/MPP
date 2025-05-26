// app3Dlg.h : header file
//

#pragma once

// Capp3Dlg dialog
class Capp3Dlg : public CDialogEx
{
    // Construction
public:
    Capp3Dlg(CWnd* pParent = nullptr);    // standard constructor

    // Dialog Data
#ifdef AFX_DESIGN_TIME
    enum { IDD = IDD_APP3_DIALOG };
#endif

protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

    // Implementation
protected:
    HICON m_hIcon;

    // Generated message map functions
    virtual BOOL OnInitDialog();
    afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
    afx_msg void OnPaint();
    afx_msg HCURSOR OnQueryDragIcon();
    DECLARE_MESSAGE_MAP()

public:
    afx_msg void OnBnClickedVerifica();
    afx_msg void OnBnClickedResetare();
    afx_msg void OnBnClickedIesire();
    afx_msg void OnBnClickedCalculeaza();
    afx_msg void OnEnChangeEdit1();
    afx_msg void OnBnClickedButton2(); // Add this line

    // Variabile pentru numere
    INT Introdu_numar;
    int SumaDivizori;
    int MinPrim;
    int MaxPrim;

    // Controale UI
    CButton Resetare;
    CEdit EditSum;
    CEdit EditMinPrime;
    CEdit EditMaxPrime;
};
