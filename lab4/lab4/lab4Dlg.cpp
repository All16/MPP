#include "pch.h"
#include "framework.h"
#include "lab4.h"
#include "lab4Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// Clab4Dlg dialog
Clab4Dlg::Clab4Dlg(CWnd* pParent /*=nullptr*/)
    : CDialogEx(IDD_LAB4_DIALOG, pParent), Operatie(-1), Text(_T("Selectează o operație"))
{
    m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Clab4Dlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_A, EditA);
    DDX_Control(pDX, IDC_B, EditB);
    DDX_Control(pDX, IDC_Iesire, EditIesire);
    DDX_Control(pDX, IDC_N, EditN);
    DDX_Control(pDX, IDC_STATIC1, StaticText);  // Legătură pentru textul static
    DDX_Radio(pDX, IDC_OPERATIE1, Operatie);   // Mapare variabilă Operatie pentru butoanele radio
}

BEGIN_MESSAGE_MAP(Clab4Dlg, CDialogEx)
    ON_BN_CLICKED(IDC_Calculeaza, &Clab4Dlg::OnBnClickedCalculeaza)
    ON_BN_CLICKED(IDC_Cancel, &Clab4Dlg::OnBnClickedCancel)
    ON_BN_CLICKED(IDC_Operatie8, &Clab4Dlg::OnBnClickedOperatie8)
END_MESSAGE_MAP()

BOOL Clab4Dlg::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    // Setăm icoana
    SetIcon(m_hIcon, TRUE);			// Set big icon
    SetIcon(m_hIcon, FALSE);		// Set small icon

    // Inițializăm textul static
    GetDlgItem(IDC_STATIC1)->SetWindowText(Text);
    
    return TRUE;  // return TRUE  unless you set the focus to a control
}

void Clab4Dlg::OnBnClickedCalculeaza()
{
    UpdateData(TRUE);

    CString strA, strB, strN;
    EditA.GetWindowText(strA);
    EditB.GetWindowText(strB);
    EditN.GetWindowText(strN);

    if (strA.IsEmpty() || strB.IsEmpty()) {
        AfxMessageBox(_T("Vă rugăm să introduceți valori pentru A și B."));
        return;
    }

    double A = _ttof(strA);
    double B = _ttof(strB);
    int n = _ttoi(strN);

    if ((Operatie == 7 || Operatie == 8) && n <= 0) {
        AfxMessageBox(_T("Valoarea lui n trebuie să fie pozitivă!"));
        return;
    }

    double Rezultat = 0.0;
    switch (Operatie)
    {
    case 0: // Adunare
        Rezultat = A + B;
        Text = "A + B =";
        break;
    case 1: // Scădere
        Rezultat = A - B;
        Text = "A - B =";
        break;
    case 2: // Înmulțire
        Rezultat = A * B;
        Text = "A * B =";
        break;
    case 3: // Împărțire reală
        if (B == 0.0) {
            AfxMessageBox(_T("Împărțire la 0!"));
            return;
        }
        Rezultat = A / B;
        Text = "A / B =";
        break;
    case 4: // Împărțire întreagă
        if (B == 0.0) {
            AfxMessageBox(_T("Împărțire la 0!"));
            return;
        }
        Rezultat = (int)(A / B);
        Text = "[A / B] =";
        break;
    case 5: // Partea Fracționară a Împărțirii
        if (B == 0.0) {
            AfxMessageBox(_T("Împărțire la 0!"));
            return;
        }
        Rezultat = (double)(A/B)-(INT)(A/B);
        Text = "{A / B} =";
        break;

    case 6: // Partea Fracționară a Împărțirii
        if (B == 0.0) {
            AfxMessageBox(_T("Împărțire la 0!"));
            return;
        }
        Rezultat = (double)(A / B) - (INT)(A / B);
        Text = "{A / B} =";
        break;

    case 7: // Adunare Modulo n
        Rezultat = fmod(A + B, n);
        if (Rezultat < 0) Rezultat += n;
        Text = "(A + B) mod n =";
        break;
    case 8: // Înmulțire Modulo n
        Rezultat = fmod(A * B, n);
        if (Rezultat < 0) Rezultat += n;
        Text = "(A * B) mod n =";
        break;
    default:
        AfxMessageBox(_T("Nu s-a ales o operație validă!"));
        return;
    }

    UpdateData(FALSE);

    CString strRezultat;
    strRezultat.Format(_T("%.2f"), Rezultat);
    EditIesire.SetWindowText(strRezultat);

    // Actualizăm textul static
    GetDlgItem(IDC_STATIC1)->SetWindowText(Text);
}

void Clab4Dlg::OnBnClickedCancel()
{
    EditA.SetWindowText(_T(""));
    EditB.SetWindowText(_T(""));
    EditN.SetWindowText(_T(""));
    EditIesire.SetWindowText(_T(""));
    Text = _T("Selectează o operație");

    Operatie = -1;
    GetDlgItem(IDC_STATIC1)->SetWindowText(Text);

    UpdateData(FALSE);
}

void Clab4Dlg::OnBnClickedOperatie8()
{
    // TODO: Add your control notification handler code here
}
