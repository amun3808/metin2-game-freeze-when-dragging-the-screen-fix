// Find
case WM_EXITSIZEMOVE:
{
...
}

// Add
	case WM_NCLBUTTONDOWN:
	{
		switch (wParam)
		{
		case HTMAXBUTTON:
		case HTSYSMENU:
			return 0;
		case HTMINBUTTON:
			ShowWindow(hWnd, SW_MINIMIZE);
			return 0;
		case HTCLOSE:
			RunPressExitKey();
			return 0;
		case HTCAPTION:
			if (!IsUserMovingMainWindow())
				SetUserMovingMainWindow(true);

			return 0;
		}

		break;
	}
	
	case WM_NCLBUTTONUP:
	{
		if (IsUserMovingMainWindow())
			SetUserMovingMainWindow(false);
		
		break;
	}

	case WM_NCRBUTTONDOWN:
	case WM_NCRBUTTONUP:
	case WM_CONTEXTMENU:
		return 0;