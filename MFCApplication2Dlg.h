
// MFCApplication2Dlg.h: файл заголовка
//

#pragma once


// Диалоговое окно CMFCApplication2Dlg
class CMFCApplication2Dlg : public CDialogEx
{
// Создание
public:
	CMFCApplication2Dlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION2_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CEdit EditControl;
	CComboBox ComboBox;
	afx_msg void OnBnClickedButton2();
	CProgressCtrl ProgressBar;
	CSliderCtrl Slider;
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	CListBox ListBox;
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedCheck1();
	// Переменная, связанная с полем ввода
	CString CValue;
	CString CEntry;
	afx_msg void OnBnClickedBnTwice();
	CListCtrl ListCtrl;

	int RdBn;
	bool ReadOnly;
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedEntry();
	afx_msg void OnBnClickedChange();
};
