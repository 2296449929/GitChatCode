#include "pch.h"
#include "CMySocket.h"
#include "MFCChatClient.h"
#include "MFCChatClientDlg.h"

CMySocket::CMySocket()
{
}

CMySocket::~CMySocket()
{
}

void CMySocket::OnConnect(int nErrorCode)
{
	TRACE("######OnConnect");
	CMFCChatClientDlg* dlg = (CMFCChatClientDlg*)AfxGetApp()->GetMainWnd();
	CString str;
	dlg->m_time = CTime::GetCurrentTime();
	str = dlg->m_time.Format("%X ");
	str += _T("����������ӳɹ�");
	dlg->m_list.AddString(str);
	CAsyncSocket::OnConnect(nErrorCode);
}

void CMySocket::OnReceive(int nErrorCode)
{
	TRACE("######OnReceive");

	CMFCChatClientDlg* dlg = (CMFCChatClientDlg*)AfxGetApp()->GetMainWnd();

	char szRecvBuf[200] = {0};
	Receive(szRecvBuf, 200, 0);

	TRACE("########## ReceiveServerMsg: %s", szRecvBuf);

	//��ʾbuf
	USES_CONVERSION;
	CString strRecvMsg = A2W(szRecvBuf);

	//��ʾ���б����
	CString strShow = _T("�����: ");
	CString strTime;

	dlg->m_time = CTime::GetCurrentTime();
	strTime = dlg->m_time.Format("%X ");

	strShow = strTime + strShow;
	strShow += strRecvMsg;
	dlg->m_list.AddString(strShow);

	CAsyncSocket::OnReceive(nErrorCode);
}
