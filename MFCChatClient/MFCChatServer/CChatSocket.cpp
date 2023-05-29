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

	//显示buf
	USES_CONVERSION;
	CString strRecvMsg = A2W(szRecvBuf);

	//显示到列表框内
	CString strShow = _T("客户端: ");
	CString strTime;

	dlg->m_time = CTime::GetCurrentTime();
	strTime = dlg->m_time.Format("%X ");

	strShow = strTime + strShow;
	strShow += strRecvMsg;
	dlg->m_list.AddString(strShow);

	CAsyncSocket::OnReceive(nErrorCode);
}
