#include "pch.h"
#include "framework.h"
#include "Lab5.h"
#include "Lab5Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNAMIC(CLab5Dlg, CDialogEx)

CLab5Dlg::CLab5Dlg(CWnd* pParent /*=nullptr*/)
    : CDialogEx(IDD_LAB5_DIALOG, pParent), numarDVD(0)
{
    m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLab5Dlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_LISTDVD, m_ListDVD);
    DDX_Control(pDX, IDC_COMBOZILE, m_ComboZile);
    DDX_Control(pDX, IDC_TOTAL, m_EditTotal);
    DDX_Control(pDX, IDC_REDUCERE, m_CheckReducere);
}

BEGIN_MESSAGE_MAP(CLab5Dlg, CDialogEx)
    ON_WM_SYSCOMMAND()
    ON_WM_PAINT()
    ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED(IDC_CALCULEAZA, &CLab5Dlg::OnBnClickedCalculeaza)
    ON_BN_CLICKED(IDCANCEL, &CLab5Dlg::OnBnClickedIesire)
    ON_NOTIFY(LVN_ITEMCHANGED, IDC_LISTDVD, &CLab5Dlg::OnLvnItemchangedListDVD)
    ON_BN_CLICKED(IDC_BUTTON_IESIRE, &CLab5Dlg::OnBnClickedButtonIesire)
END_MESSAGE_MAP()

BOOL CLab5Dlg::OnInitDialog()
{
    CDialogEx::OnInitDialog();
    SetIcon(m_hIcon, TRUE);
    SetIcon(m_hIcon, FALSE);

    m_ListDVD.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | LVS_EX_CHECKBOXES);
    m_ListDVD.InsertColumn(0, L"Nume", LVCFMT_LEFT, 150);
    m_ListDVD.InsertColumn(1, L"Tip", LVCFMT_LEFT, 100);
    m_ListDVD.InsertColumn(2, L"Calitate", LVCFMT_LEFT, 100);
    m_ListDVD.InsertColumn(3, L"Preț", LVCFMT_RIGHT, 70);

    int index;

    index = m_ListDVD.InsertItem(0, L"Red Notice");
    m_ListDVD.SetItemText(index, 1, L"Film");
    m_ListDVD.SetItemText(index, 2, L"HD");
    m_ListDVD.SetItemText(index, 3, L"20");

    index = m_ListDVD.InsertItem(1, L"Kingdom: Ashin of the North");
    m_ListDVD.SetItemText(index, 1, L"Film");
    m_ListDVD.SetItemText(index, 2, L"4K");
    m_ListDVD.SetItemText(index, 3, L"25");

    index = m_ListDVD.InsertItem(2, L"Forever Rich");
    m_ListDVD.SetItemText(index, 1, L"Film");
    m_ListDVD.SetItemText(index, 2, L"HD");
    m_ListDVD.SetItemText(index, 3, L"18");

    index = m_ListDVD.InsertItem(3, L"The Last Mercenary");
    m_ListDVD.SetItemText(index, 1, L"Film");
    m_ListDVD.SetItemText(index, 2, L"HD");
    m_ListDVD.SetItemText(index, 3, L"22");

    index = m_ListDVD.InsertItem(4, L"Security");
    m_ListDVD.SetItemText(index, 1, L"Film");
    m_ListDVD.SetItemText(index, 2, L"HD");
    m_ListDVD.SetItemText(index, 3, L"17");

    index = m_ListDVD.InsertItem(5, L"Prey");
    m_ListDVD.SetItemText(index, 1, L"Film");
    m_ListDVD.SetItemText(index, 2, L"4K");
    m_ListDVD.SetItemText(index, 3, L"23");

    index = m_ListDVD.InsertItem(6, L"The Witcher: Nightmare of the Wolf");
    m_ListDVD.SetItemText(index, 1, L"Film");
    m_ListDVD.SetItemText(index, 2, L"4K");
    m_ListDVD.SetItemText(index, 3, L"26");

    index = m_ListDVD.InsertItem(7, L"Imagine Dragons - Live");
    m_ListDVD.SetItemText(index, 1, L"Audio");
    m_ListDVD.SetItemText(index, 2, L"MP3");
    m_ListDVD.SetItemText(index, 3, L"15");


    m_ComboZile.AddString(L"1 zi");
    m_ComboZile.AddString(L"3 zile");
    m_ComboZile.AddString(L"7 zile");
    m_ComboZile.SetCurSel(0);

    return TRUE;
}

void CLab5Dlg::OnBnClickedCalculeaza()
{
    UpdateData(TRUE);

    int indexZile = m_ComboZile.GetCurSel();
    int zile = (indexZile == 0) ? 1 : (indexZile == 1) ? 3 : 7;
    double total = 0.0;
    numarDVD = 0;

    for (int i = 0; i < m_ListDVD.GetItemCount(); i++)
    {
        if (m_ListDVD.GetCheck(i))
        {
            CString strPret = m_ListDVD.GetItemText(i, 3);
            double pretDVD = _wtof(strPret);
            numarDVD++;
            total += pretDVD * zile;
        }
    }

    if (numarDVD == 0)
    {
        AfxMessageBox(L"Selectați cel puțin un film!");
        return;
    }

    if (zile == 3) total *= 0.9;
    if (zile == 7) total *= 0.8;
    if (m_CheckReducere.GetCheck() == BST_CHECKED) total *= 0.75;

    CString strTotal;
    strTotal.Format(L"%.2f", total);
    m_EditTotal.SetWindowTextW(strTotal);

    CString mesaj;
    mesaj.Format(L"Ați selectat %d DVD-uri.", numarDVD);
    AfxMessageBox(mesaj, MB_ICONINFORMATION | MB_OK);
}


void CLab5Dlg::OnBnClickedIesire()
{
    EndDialog(0);
}

void CLab5Dlg::OnLvnItemchangedListDVD(NMHDR* pNMHDR, LRESULT* pResult)
{
    *pResult = 0;
}

void CLab5Dlg::OnBnClickedButtonIesire()
{
    EndDialog(IDCANCEL);
}

void CLab5Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
    CDialogEx::OnSysCommand(nID, lParam);
}

void CLab5Dlg::OnPaint()
{
    if (IsIconic())
    {
        CPaintDC dc(this);
        SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);
        CRect rect;
        GetClientRect(&rect);
        dc.DrawIcon((rect.Width() - 32) / 2, (rect.Height() - 32) / 2, m_hIcon);
    }
    else
    {
        CDialogEx::OnPaint();
    }
}

HCURSOR CLab5Dlg::OnQueryDragIcon()
{
    return static_cast<HCURSOR>(m_hIcon);
}
CLab5Dlg::~CLab5Dlg()
{
    // Cleanup code if necessary
}