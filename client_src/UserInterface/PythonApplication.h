//find
	void Loop();

// add
	void BeginFutureLoop();
	void EndFutureLoop();

//find
protected:
	int m_iCursorNum;
	int m_iContinuousCursorNum;

//add
	std::future<void> m_future;
	bool m_future_should_continue_processing;
	bool m_future_acknowledged_stop_request;
