
// MFC_project_offlineDlg.h: 헤더 파일
//

#pragma once


// CMFCprojectofflineDlg 대화 상자
class CMFCprojectofflineDlg : public CDialogEx
{
// 생성입니다.
public:
	CMFCprojectofflineDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_PROJECT_OFFLINE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedRadio2();
	CButton m_radio1;
	CButton m_radio2;
	CButton m_checkBox1;
	CButton m_checkBox2;
	CListBox m_listBox;
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedCheck2();
	afx_msg void OnBnClickedButton3();
	CString m_editBox;
	CComboBox m_comboBox;
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
