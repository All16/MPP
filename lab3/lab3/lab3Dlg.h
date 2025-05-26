
// lab3Dlg.h : header file
//

#pragma once


// Clab3Dlg dialog
class Clab3Dlg : public CDialogEx
{
// Construction
public:
	Clab3Dlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LAB3_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


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
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();


public:
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnEnChangeEdit4();

protected:
	CString listaNumere; 
	int A, B, cmMdc, cmmmc;

	int CalculeazaCmMdc(int a, int b);
	int CalculeazaCmmmc(int a, int b);
	void CalculeazaLista(); 
	void SimplificaFractie();

public:
	afx_msg void OnEnChangeEdit5();
};
