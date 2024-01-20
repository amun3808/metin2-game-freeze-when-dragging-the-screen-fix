// Search m_dwLastIdleTime(0),
// Add m_IsMovingMainWindow(false),

// Search 
#ifndef _DEBUG
	SetEterExceptionHandler();
#endif
  
// Add
	m_InitialMouseMovingPoint = {};

// Search
void CPythonApplication::Loop()
{
  ...
}

// Add before:
void CPythonApplication::SetUserMovingMainWindow(bool flag)
{
	if (flag && !GetCursorPos(&m_InitialMouseMovingPoint))
		return;

	m_IsMovingMainWindow = flag;
}
bool CPythonApplication::IsUserMovingMainWindow() const
{
	return m_IsMovingMainWindow;
}
void CPythonApplication::UpdateMainWindowPosition()
{
	POINT finalPoint{};
	if (GetCursorPos(&finalPoint))
	{
		LONG xDiff = finalPoint.x - initialMousePoint.x;
		LONG yDiff = finalPoint.y - initialMousePoint.y;

		RECT r{};
		GetWindowRect(&r);

		SetPosition(r.left + xDiff, r.top + yDiff);
		initialMousePoint = finalPoint;
	}
}


// Search
void CPythonApplication::Loop()
{
#ifdef PROFILING
	Profiler::Instance().beginSession("session1");
#endif

	while (1)
	{

// Add
		if (IsUserMovingMainWindow())
			UpdateMainWindowPosition();

// Looks like this:
	while (1)
	{
		if (IsUserMovingMainWindow())
			UpdateMainWindowPosition();

		if (IsMessage())
		{
			if (!MessageProcess())
				break;
		}
		else
		{
			if (!Process())
				break;

			m_dwLastIdleTime = ELTimer_GetMSec();
		}
	}