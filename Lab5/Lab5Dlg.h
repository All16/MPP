#pragma once
#include "afxdialogex.h"

class CLab5Dlg : public CDialogEx
{
    DECLARE_DYNAMIC(CLab5Dlg)

public:
    CLab5Dlg(CWnd* pParent = nullptr);
    virtual ~CLab5Dlg();

#ifdef AFX_DESIGN_TIME
    enum { IDD = IDD_LAB5_DIALOG };
#endif

protected:
    virtual void DoDataExchange(CDataExchange* pDX);
    virtual BOOL OnInitDialog();

    DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedCalculeaza();
    afx_msg void OnBnClickedIesire();
    afx_msg void OnLvnItemchangedListDVD(NMHDR* pNMHDR, LRESULT* pResult);
    afx_msg void OnBnClickedButtonIesire();
    afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
    afx_msg void OnPaint();
    afx_msg HCURSOR OnQueryDragIcon();

private:
    CListCtrl m_ListDVD;
    CComboBox m_ComboZile;
    CEdit m_EditTotal;
    CButton m_CheckReducere;
    int numarDVD;
    HICON m_hIcon;
};