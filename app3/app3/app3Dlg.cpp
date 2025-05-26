// app3Dlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "app3.h"
#include "app3Dlg.h"
#include "afxdialogex.h"
#define IDC_BUTTON_CALCULEAZA 1001
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// resource.h
#define IDC_BUTTON1 1000
#define IDC_BUTTON_CALCULEAZA 1001
#define IDC_BUTTON2 1002
#define IDC_EDIT1 1003
#define IDOK 1004
#define IDCANCEL 1005
// Add other resource IDs here

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
    CAboutDlg();

#ifdef AFX_DESIGN_TIME
    enum { IDD = IDD_ABOUTBOX };
#endif

protected:
    virtual void DoDataExchange(CDataExchange* pDX);
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

// Capp3Dlg dialog

Capp3Dlg::Capp3Dlg(CWnd* pParent /*=nullptr*/)
    : CDialogEx(IDD_APP3_DIALOG, pParent)
    , Introdu_numar(0), SumaDivizori(0), MinPrim(0), MaxPrim(0)
{
    m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Capp3Dlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_EDIT1, Introdu_numar);
    DDX_Control(pDX, IDOK, Resetare);
}

BEGIN_MESSAGE_MAP(Capp3Dlg, CDialogEx)
    ON_WM_SYSCOMMAND()
    ON_WM_PAINT()
    ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED(IDC_BUTTON1, &Capp3Dlg::OnBnClickedVerifica)
    ON_BN_CLICKED(IDOK, &Capp3Dlg::OnBnClickedResetare)
    ON_BN_CLICKED(IDCANCEL, &Capp3Dlg::OnBnClickedIesire)
    ON_BN_CLICKED(IDC_BUTTON_CALCULEAZA, &Capp3Dlg::OnBnClickedCalculeaza)
    ON_BN_CLICKED(IDC_BUTTON2, &Capp3Dlg::OnBnClickedButton2)
    ON_EN_CHANGE(IDC_EDIT1, &Capp3Dlg::OnEnChangeEdit1)
END_MESSAGE_MAP()

BOOL Capp3Dlg::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    CMenu* pSysMenu = GetSystemMenu(FALSE);
    if (pSysMenu != nullptr)
    {
        CString strAboutMenu;
        if (strAboutMenu.LoadString(IDS_ABOUTBOX))
        {
            pSysMenu->AppendMenu(MF_SEPARATOR);
            pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
        }
    }

    SetIcon(m_hIcon, TRUE);
    SetIcon(m_hIcon, FALSE);

    return TRUE;
}

void Capp3Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void Capp3Dlg::OnPaint()
{
    if (IsIconic())
    {
        CPaintDC dc(this);
        SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

        int cxIcon = GetSystemMetrics(SM_CXICON);
        int cyIcon = GetSystemMetrics(SM_CYICON);
        CRect rect;
        GetClientRect(&rect);
        int x = (rect.Width() - cxIcon + 1) / 2;
        int y = (rect.Height() - cyIcon + 1) / 2;

        dc.DrawIcon(x, y, m_hIcon);
    }
    else
    {
        CDialogEx::OnPaint();
    }
}

HCURSOR Capp3Dlg::OnQueryDragIcon()
{
    return static_cast<HCURSOR>(m_hIcon);
}

void Capp3Dlg::OnBnClickedVerifica()
{
    UpdateData(TRUE);
    CString text;
    int n = Introdu_numar;

    if (n < 2)
    {
        MessageBox(_T("Numărul introdus nu este prim!"));
        return;
    }

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            text.Format(_T("Numărul %d nu este prim (se divide prin %d)"), n, i);
            AfxMessageBox(text);
            return;
        }
    }

    text.Format(_T("Numărul %d este prim"), n);
    AfxMessageBox(text);
    UpdateData(FALSE);
}

void Capp3Dlg::OnBnClickedResetare()
{
    Introdu_numar = 0;
    UpdateData(FALSE);
}

void Capp3Dlg::OnBnClickedIesire()
{
    CDialogEx::OnCancel();
}

int SumaDivizorilorProprii(int n)
{
    int suma = 0;
    for (int i = 1; i <= n / 2; i++)
    {
        if (n % i == 0)
            suma += i;
    }
    return suma;
}

bool EstePrim(int n)
{
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0) return false;
    }
    return true;
}

int CelMaiMicPrim(int n)
{
    while (!EstePrim(n))
        n++;
    return n;
}

int CelMaiMarePrim(int n)
{
    while (!EstePrim(n) && n > 1)
        n--;
    return n;
}

void Capp3Dlg::OnBnClickedCalculeaza()
{
    UpdateData(TRUE);

    int n = Introdu_numar;
    SumaDivizori = SumaDivizorilorProprii(n);
    MinPrim = CelMaiMicPrim(n);
    MaxPrim = CelMaiMarePrim(n);

    UpdateData(FALSE);
}

// Implementare funcție 'OnEnChangeEdit1' pentru gestionarea schimbărilor din edit box-ul IDC_EDIT1
void Capp3Dlg::OnEnChangeEdit1()
{
    // Aici poți adăuga codul pentru ce se întâmplă când textul din Edit1 se schimbă
    // De exemplu, poți verifica sau valida input-ul
}

// Implementare funcție 'OnBnClickedButton2' pentru gestionarea butonului IDC_BUTTON2
void Capp3Dlg::OnBnClickedButton2()
{
    // Adaugă logica ce trebuie executată la click pe butonul IDC_BUTTON2
    AfxMessageBox(_T("Butonul 2 a fost apăsat"));
}
