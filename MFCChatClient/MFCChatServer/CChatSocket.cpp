#include "pch.h"
#include "CChatSocket.h"
#include "MFCChatServer.h"
#include "MFCChatServerDlg.h"

CChatSocket::CChatSocket()
{

}

CChatSocket::~CChatSocket()
{

}

void CChatSocket::OnReceive(int nErrorCode)
{
	TRACE("######Server OnReceive");
	CMFCChatServerDlg* dlg = (CMFCChatServerDlg*)AfxGetApp()->GetMainWnd();
	char szRecvBuf[200] = {0};
	Receive(szRecvBuf, 200, 0);
	TRACE("######Server Receive: %s", szRecvBuf);

	//��ʾbuf
	USES_CONVERSION;
	CString strRecvMsg = A2W(szRecvBuf);

	//��ʾ���б����
	CString strShow = _T("�ͻ���: ");
	CString strTime;

	dlg->m_time = CTime::GetCurrentTime();
	strTime = dlg->m_time.Format("%X ");

	strShow = strTime + strShow;
	strShow += strRecvMsg;
	dlg->m_list.AddString(strShow);

	CAsyncSocket::OnReceive(nErrorCode);
}
