// find
CPythonApplication::CPythonApplication() :
	m_bCursorVisible(TRUE),
	m_bLiarCursorOn(false),
	m_iCursorMode(CURSOR_MODE_HARDWARE),
	m_isWindowed(false),
	m_isFrameSkipDisable(false),
	m_poMouseHandler(NULL),
	m_dwUpdateFPS(0),
	m_dwRenderFPS(0),
	m_fAveRenderTime(0.0f),
	m_dwFaceCount(0),
	m_fGlobalTime(0.0f),
	m_fGlobalElapsedTime(0.0f),
	m_dwLButtonDownTime(0),
	m_dwLastIdleTime(0),// don't forget the comma here
//add
	m_future_should_continue_processing(false),
	m_future_acknowledged_stop_request(true)


//find

void CPythonApplication::Loop()
{
	while (1)
	{
		if (IsMessage())
		{
			if (!MessageProcess())
			{
				break;
			}
		}
		else
		{
			if (!Process())
				break;

			m_dwLastIdleTime = ELTimer_GetMSec();
		}
	}
}


// replace with
void CPythonApplication::BeginFutureLoop()
{
	m_future_acknowledged_stop_request = false;
	m_future_should_continue_processing = true;

	auto lmbd = [&]() {
		while (m_future_should_continue_processing)
		{
			if (!Process())
				break;

			m_dwLastIdleTime = ELTimer_GetMSec();
		}

		m_future_acknowledged_stop_request = true;
	};

	m_future = std::async(std::launch::async, lmbd);
}

void CPythonApplication::EndFutureLoop()
{
	m_future_should_continue_processing = false;
	m_future.wait();
}

void CPythonApplication::Loop()
{
	while (1)
	{
		if (IsMessage())
		{
			if (!MessageProcess())
			{
				m_future_should_continue_processing = false;
				break;
			}
		}
		else if (m_future_acknowledged_stop_request)
		{
			if (!Process())
				break;

			m_dwLastIdleTime = ELTimer_GetMSec();
		}
	}
}