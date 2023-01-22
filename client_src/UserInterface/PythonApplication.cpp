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
	m_future_acknowledged_stop_request = true;
	m_future_should_continue_processing = false;
#ifdef PROFILING
	Profiler::Instance().beginSession("session1");
#endif

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
#ifdef PROFILING
	Profiler::Instance().endSession();
#endif
}