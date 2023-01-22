// find
	case WM_EXITSIZEMOVE:
	{
		RECT rcWnd;
		GetClientRect(&rcWnd);

		uint32_t uWidth = rcWnd.right - rcWnd.left;
		uint32_t uHeight = rcWnd.bottom - rcWnd.left;
		m_grpDevice.ResizeBackBuffer(uWidth, uHeight);
		OnSizeChange(short(LOWORD(lParam)), short(HIWORD(lParam)));
	}
	break;

// change
	case WM_EXITSIZEMOVE:
	{
		// add this
		EndFutureLoop();


// and add this
	case WM_ENTERSIZEMOVE:
	{
		BeginFutureLoop();
		break;
	}