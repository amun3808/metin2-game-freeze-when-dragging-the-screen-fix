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