#include"UIlib.h"
using namespace DuiLib;

#pragma comment(lib,"DuiLib_ud.lib")
#if 0
class CDuiFramWnd : public CWindowWnd, public INotifyUI
{
public:
	// CWindowWnd��Ĵ��麯�����ڸú����б��뷵���û������崰�ڵ������ƣ�ע�ᴰ��ʱ��Ҫ�õ�
	virtual LPCTSTR GetWindowClassName() const
	{
		return _T("DuiFramWnd");
	}
	virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		if (WM_CREATE == uMsg){
			/*m_PaintManager.Init(m_hWnd);
			//�ڴ��ڴ����ڼ䴴��һ����ť
			CControlUI* pBTN = new CButtonUI;
			pBTN->SetText(_T("hello"));
			pBTN->SetBkColor(0xFF00FF00);
			m_PaintManager.AttachDialog(pBTN);
			m_PaintManager.AddNotifier(this);*/
			m_PaintManager.Init(m_hWnd);
			CDialogBuilder builder;
			// duilib.xml��Ҫ�ŵ�exeĿ¼��
			CControlUI* pRoot = builder.Create(_T("duilib.xml"), (UINT)0, NULL, &m_PaintManager);
			m_PaintManager.AttachDialog(pRoot);
			m_PaintManager.AddNotifier(this);
			
			return 0;
		}
		else if (uMsg == WM_NCACTIVATE)
		{
			if (!::IsIconic(m_hWnd))
			{
				return (wParam == 0) ? TRUE : FALSE;
			}
		}
		else if (uMsg == WM_NCCALCSIZE)
		{
			return 0;
		}
		else if (uMsg == WM_NCPAINT)
		{
			return 0;
		}
		//���ػ滭�����Ϣ
		LRESULT lRes = 0;
		if (m_PaintManager.MessageHandler(uMsg, wParam, lParam, lRes))
		{
			return lRes;
		}

		return CWindowWnd::HandleMessage(uMsg, wParam, lParam);
	}

	virtual void Notify(TNotifyUI& msg)
	{
		//��Ӧ��ť�����Ϣ
		if (msg.sType == _T("click")){
			MessageBox(m_hWnd, _T("��ť����"), _T("Test"), IDOK);
		}
	}
private:
	CPaintManagerUI m_PaintManager;
};
int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int
	nCmdShow)
{ 
	CPaintManagerUI::SetInstance(hInstance);
	// ������Դ��Ĭ��·�����˴�����Ϊ��exe��ͬһĿ¼��
	CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath());
	CDuiFramWnd framWnd;
	// Cashier���ڴ������Ͻ���ʽ������
	// UI_WNDSTYLE_FRAME: duilib��װ�ĺ꣬�����ڿ��ӣ����б������������С�����رչ��ܵ�
	// WS_EX_WINDOWEDGE: Win32�Ĵ��ڷ�񣬴��б߿�
	framWnd.Create(NULL, _T("Cashier"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);

	//��ʾ���ڣ�������Ϣѭ��
	framWnd.ShowModal();
	return 0;
}
#endif

class CDuiFramWnd : public WindowImplBase
{
protected:
	virtual CDuiString GetSkinFolder()
	{
		return _T("");
	}
	virtual CDuiString GetSkinFile()
	{
		return _T("Duilib.xml");
	}
	virtual LPCTSTR GetWindowClassName(void) const
	{
		return _T("DuiWnd");
	}

	virtual void Notify(TNotifyUI& msg)
	{
		if (msg.sType == _T("click"))
		{
			MessageBox(m_hWnd, _T("��ť����"), _T("Test"), IDOK);
		}
	}
};
int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int
	nCmdShow)
{
	CPaintManagerUI::SetInstance(hInstance);
	// ������Դ��Ĭ��·�����˴�����Ϊ��exe��ͬһĿ¼��
	CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath());
	CDuiFramWnd framWnd;
	// Cashier���ڴ������Ͻ���ʽ������
	// UI_WNDSTYLE_FRAME: duilib��װ�ĺ꣬�����ڿ��ӣ����б������������С�����رչ��ܵ�
	// WS_EX_WINDOWEDGE: Win32�Ĵ��ڷ�񣬴��б߿�
	framWnd.Create(NULL, _T("Cashier"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
	framWnd.CenterWindow();
	//��ʾ���ڣ�������Ϣѭ��
	framWnd.ShowModal();
	return 0;
}