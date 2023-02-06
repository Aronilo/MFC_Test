
// MFCApplication2Dlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication2.h"
#include "MFCApplication2Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
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


// Диалоговое окно CMFCApplication2Dlg



CMFCApplication2Dlg::CMFCApplication2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION2_DIALOG, pParent)
	, CValue(_T("")), RdBn(-1), CEntry(_T("")) {
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, EditControl);
	DDX_Control(pDX, IDC_COMBO1, ComboBox);
	DDX_Control(pDX, IDC_PROGRESS1, ProgressBar);
	DDX_Control(pDX, IDC_SLIDER1, Slider);
	DDX_Control(pDX, IDC_LIST1, ListBox);
	DDX_Text(pDX, IDC_EDIT2, CValue);
	DDX_Control(pDX, IDC_LIST2, ListCtrl);
	DDX_Text(pDX, IDC_EDIT3, CEntry);
}

BEGIN_MESSAGE_MAP(CMFCApplication2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication2Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication2Dlg::OnBnClickedButton2)
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCApplication2Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication2Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_CHECK1, &CMFCApplication2Dlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_BN_TWICE, &CMFCApplication2Dlg::OnBnClickedBnTwice)
	ON_BN_CLICKED(IDC_RADIO1, &CMFCApplication2Dlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CMFCApplication2Dlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &CMFCApplication2Dlg::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_ENTRY, &CMFCApplication2Dlg::OnBnClickedEntry)
	ON_BN_CLICKED(IDC_CHANGE, &CMFCApplication2Dlg::OnBnClickedChange)
END_MESSAGE_MAP()


// Обработчики сообщений CMFCApplication2Dlg

BOOL CMFCApplication2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
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

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию

	LVCOLUMN lvColumn;
	int nCol;

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;
	lvColumn.cx = 150;
	lvColumn.pszText = L"Имя";
	nCol = ListCtrl.InsertColumn(0, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_CENTER;
	lvColumn.cx = 150;
	lvColumn.pszText = L"Возраст";
	ListCtrl.InsertColumn(1, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;
	lvColumn.cx = 150;
	lvColumn.pszText = L"Пол";
	ListCtrl.InsertColumn(2, &lvColumn);

	ReadOnly = false;

	ListCtrl.SetExtendedStyle(ListCtrl.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EDITLABELS);

	Slider.SetPos(50);

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CMFCApplication2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CMFCApplication2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CMFCApplication2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication2Dlg::OnBnClickedButton1()
{
	int len = EditControl.LineLength(EditControl.LineIndex(0));
	CString s;
	LPTSTR p = s.GetBuffer(len);
	EditControl.GetLine(0, p, len);
	s.ReleaseBuffer();

	ComboBox.AddString(s);

	// TODO: добавьте свой код обработчика уведомлений
}


void CMFCApplication2Dlg::OnBnClickedButton2()
{
	int len = EditControl.LineLength(EditControl.LineIndex(0));
	CString s;
	LPTSTR p = s.GetBuffer(len);
	EditControl.GetLine(0, p, len);
	s.ReleaseBuffer();

	int value = _ttoi(s);

	ProgressBar.SetPos(value);
}



void CMFCApplication2Dlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного

	int value = Slider.GetPos();

	ProgressBar.SetPos(value);

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}


void CMFCApplication2Dlg::OnBnClickedButton4()
{
	// TODO: добавьте свой код обработчика уведомлений
	int len = EditControl.LineLength(EditControl.LineIndex(0));
	CString s;
	LPTSTR p = s.GetBuffer(len);
	EditControl.GetLine(0, p, len);
	s.ReleaseBuffer();

	ListBox.AddString(s);
}


void CMFCApplication2Dlg::OnBnClickedButton3()
{
	// TODO: добавьте свой код обработчика уведомлений
	int nCount = ListBox.GetSelCount();
	CArray<int, int> aryListBoxSel;

	aryListBoxSel.SetSize(nCount);
	ListBox.GetSelItems(nCount, aryListBoxSel.GetData());

	CString s;
	
	for (int i = 0; i < aryListBoxSel.GetSize(); i++) {
		ListBox.GetText(aryListBoxSel[i], s);
		ComboBox.AddString(s);
	}
}

void CMFCApplication2Dlg::OnBnClickedCheck1()
{
	if (ReadOnly) {
		EditControl.SetReadOnly(FALSE);
		ReadOnly = false;
	}
	else {
		EditControl.SetReadOnly();
		ReadOnly = true;
	}
	// TODO: добавьте свой код обработчика уведомлений
}


void CMFCApplication2Dlg::OnBnClickedBnTwice() {
	// TODO: добавьте свой код обработчика уведомлений
	UpdateData(TRUE);
	int value = atoi(_bstr_t(CValue.GetString()));

	CValue.Format(L"%d", value * 4);
	UpdateData(FALSE);

}


void CMFCApplication2Dlg::OnBnClickedRadio1() {
	// TODO: добавьте свой код обработчика уведомлений
	RdBn = -1;
}


void CMFCApplication2Dlg::OnBnClickedRadio2() {
	// TODO: добавьте свой код обработчика уведомлений
	RdBn = 0;
}


void CMFCApplication2Dlg::OnBnClickedRadio3() {
	// TODO: добавьте свой код обработчика уведомлений
	RdBn = 1;
}


void CMFCApplication2Dlg::OnBnClickedEntry() {
	// TODO: добавьте свой код обработчика уведомлений
	UpdateData(TRUE); 
	
	int i1;
	for (i1 = 0; CEntry[i1] != '\0' && CEntry[i1] != ' '; i1++);

	if (CEntry[i1] == '\0')
		return;

	int i2;
	for (i2 = i1 + 1; CEntry[i2] != '\0' && CEntry[i2] != ' '; i2++);

	if (CEntry[i2] == '\0')
		return;
	

	CString first_word = CString(CEntry.Mid(0, i1));
	CString second_word = CString(CEntry.Mid((i1 + 1), (i2 - i1 - 1)));
	CString third_word = CString(CEntry.Right(CEntry.GetLength() - i2 - 1));



	int l_iItem = ListCtrl.InsertItem(LVIF_TEXT | LVIF_STATE, 0, first_word, 0, LVIS_SELECTED, 0, 0);
	ListCtrl.SetItemText(l_iItem, 1, second_word);
	ListCtrl.SetItemText(l_iItem, 2, third_word);

	UpdateData(FALSE);
	
}


void CMFCApplication2Dlg::OnBnClickedChange() {
	// TODO: добавьте свой код обработчика уведомлений
	
	UpdateData(TRUE);

	int n_items = 0, index;
	for (int i = 0; i < ListCtrl.GetItemCount(); i++) {
		if (ListCtrl.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED) {
			n_items++;
			index = i;
		}
	}

	if (n_items == 1) {
		ListCtrl.SetItemText(index, RdBn + 1, CEntry);
	}

	UpdateData(FALSE);
	
}
