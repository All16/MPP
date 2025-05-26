
// lab3Dlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "lab3.h"
#include "lab3Dlg.h"
#include "afxdialogex.h"
#include <vector>


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Clab3Dlg dialog



Clab3Dlg::Clab3Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LAB3_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Clab3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, A);
	DDX_Text(pDX, IDC_EDIT2, B);
	DDX_Text(pDX, IDC_EDIT3, cmMdc);
	DDX_Text(pDX, IDC_EDIT4, cmmmc);
	DDX_Text(pDX, IDC_EDIT5, listaNumere);  

}


BEGIN_MESSAGE_MAP(Clab3Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &Clab3Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Clab3Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &Clab3Dlg::OnBnClickedButton3)
	ON_EN_CHANGE(IDC_EDIT1, &Clab3Dlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &Clab3Dlg::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT3, &Clab3Dlg::OnEnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT4, &Clab3Dlg::OnEnChangeEdit4)
	ON_EN_CHANGE(IDC_EDIT5, &Clab3Dlg::OnEnChangeEdit5)
END_MESSAGE_MAP()


// Clab3Dlg message handlers

BOOL Clab3Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void Clab3Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void Clab3Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}


// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR Clab3Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void Clab3Dlg::SimplificaFractie() {
	UpdateData(TRUE);

	if (B == 0) {
		AfxMessageBox(_T("Numitorul nu poate fi zero!"));
		return;
	}

	int divizorComun = CalculeazaCmMdc(A, B);
	A /= divizorComun;
	B /= divizorComun;

	UpdateData(FALSE);
}


int Clab3Dlg::CalculeazaCmMdc(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int Clab3Dlg::CalculeazaCmmmc(int a, int b) {
	return (a / CalculeazaCmMdc(a, b)) * b;
}

void Clab3Dlg::CalculeazaLista() {
	UpdateData(TRUE); // Preia datele din interfață
	std::vector<int> numere;

	CString delimitatori = _T(" ,");
	int start = 0;
	CString token = listaNumere.Tokenize(delimitatori, start);

	while (!token.IsEmpty()) {
		numere.push_back(_ttoi(token));
		token = listaNumere.Tokenize(delimitatori, start);
	}

	if (numere.size() < 2) {
		AfxMessageBox(_T("Introduceți cel puțin două numere!"));
		return;
	}

	int rezultatMdc = numere[0];
	int rezultatMmc = numere[0];

	for (size_t i = 1; i < numere.size(); i++) {
		rezultatMdc = CalculeazaCmMdc(rezultatMdc, numere[i]);
		rezultatMmc = CalculeazaCmmmc(rezultatMmc, numere[i]);
	}

	cmMdc = rezultatMdc;
	cmmmc = rezultatMmc;
	UpdateData(FALSE);
}



void Clab3Dlg::OnBnClickedButton1(){
	UpdateData(TRUE);

	if (!listaNumere.IsEmpty()) {
		CalculeazaLista();
	}
	else {
		if (A == 0 && B == 0) {
			AfxMessageBox(_T("A și B nu pot fi simultan nule!"));
			return;
		}

		cmMdc = CalculeazaCmMdc(A, B);
		cmmmc = CalculeazaCmmmc(A, B);
		UpdateData(FALSE);
	}
	SimplificaFractie();

}


void Clab3Dlg::OnBnClickedButton2()
{

	// TODO: Add your control notification handler code here
	A = B = cmMdc = cmmmc = 0;
	listaNumere.Empty();
	UpdateData(FALSE);

}

void Clab3Dlg::OnBnClickedButton3()
{
		CDialogEx::OnCancel(); // Închide dialogul

}

void Clab3Dlg::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}

void Clab3Dlg::OnEnChangeEdit2()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}

void Clab3Dlg::OnEnChangeEdit3()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}

void Clab3Dlg::OnEnChangeEdit4()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}



void Clab3Dlg::OnEnChangeEdit5()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}
