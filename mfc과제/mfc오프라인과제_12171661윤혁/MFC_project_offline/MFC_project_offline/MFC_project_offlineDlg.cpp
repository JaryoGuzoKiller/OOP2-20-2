
// MFC_project_offlineDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFC_project_offline.h"
#include "MFC_project_offlineDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// CMFCprojectofflineDlg 대화 상자



CMFCprojectofflineDlg::CMFCprojectofflineDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFC_PROJECT_OFFLINE_DIALOG, pParent)
	, m_editBox(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCprojectofflineDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_RADIO1, m_radio1);
	DDX_Control(pDX, IDC_RADIO2, m_radio2);
	DDX_Control(pDX, IDC_CHECK1, m_checkBox1);
	DDX_Control(pDX, IDC_CHECK2, m_checkBox2);
	DDX_Control(pDX, IDC_LIST1, m_listBox);
	DDX_Text(pDX, IDC_EDIT1, m_editBox);
	DDX_Control(pDX, IDC_COMBO1, m_comboBox);
}

BEGIN_MESSAGE_MAP(CMFCprojectofflineDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_RADIO2, &CMFCprojectofflineDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO1, &CMFCprojectofflineDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_CHECK1, &CMFCprojectofflineDlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_CHECK2, &CMFCprojectofflineDlg::OnBnClickedCheck2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCprojectofflineDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCprojectofflineDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCprojectofflineDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCprojectofflineDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCprojectofflineDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CMFCprojectofflineDlg 메시지 처리기

BOOL CMFCprojectofflineDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMFCprojectofflineDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFCprojectofflineDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFCprojectofflineDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCprojectofflineDlg::OnBnClickedRadio2()
{
	CString str;
	if (m_radio2.GetCheck() == BST_CHECKED) {
		str = "2st radio button is selected";
		m_listBox.AddString(str);
		m_comboBox.AddString(str);
	}
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCprojectofflineDlg::OnBnClickedRadio1()
{
	CString str;
	if (m_radio1.GetCheck() == BST_CHECKED) {
		str = "1st radio button is selected";
		m_listBox.AddString(str);
		m_comboBox.AddString(str);
	}
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCprojectofflineDlg::OnBnClickedCheck1()
{
	CString str;
	if (m_checkBox1.GetCheck() == BST_CHECKED) {
		str = "1st checkbox selected-true";
		m_listBox.AddString(str);
		m_comboBox.AddString(str);
	}
	else {
		str = "1st checkbox selected-false";
		m_listBox.AddString(str);
		m_comboBox.AddString(str);
	}
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


	void CMFCprojectofflineDlg::OnBnClickedCheck2()
	{
		CString str;
		if (m_checkBox2.GetCheck() == BST_CHECKED) {
			str = "2st checkbox selected-true";
			m_listBox.AddString(str);
			m_comboBox.AddString(str);
		}
		else {
			str = "2st checkbox selected-false";
			m_listBox.AddString(str);
			m_comboBox.AddString(str);
		}
		// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	}


	void CMFCprojectofflineDlg::OnBnClickedButton3()
	{
		UpdateData(TRUE);
		m_listBox.AddString(m_editBox);
		m_comboBox.AddString(m_editBox);
		UpdateData(FALSE);
		// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	}


	void CMFCprojectofflineDlg::OnBnClickedButton4()
	{
		CString temp;
		m_comboBox.GetLBText(m_comboBox.GetCurSel(), temp);
		m_listBox.AddString(temp);
		// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	}


	void CMFCprojectofflineDlg::OnBnClickedButton5()
	{
		CString temp;
		m_comboBox.GetLBText(m_comboBox.GetCurSel(), temp);

		// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	}


	void CMFCprojectofflineDlg::OnBnClickedButton1()
	{
		int idx=m_listBox.GetCount();
		for (int i = 0; i < idx; i++) {
			m_listBox.DeleteString(i);
		}
		int idx2 = m_comboBox.GetCount();
		for (int i = 0; i < idx; i++) {
			m_comboBox.DeleteString(i);
		}
		// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	}


	void CMFCprojectofflineDlg::OnBnClickedButton2()
	{
		system("pause");
		// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	}
