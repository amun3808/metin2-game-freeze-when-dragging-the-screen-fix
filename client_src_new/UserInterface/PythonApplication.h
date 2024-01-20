// Find
void Loop();

// Add
	bool IsUserMovingMainWindow() const;
	void SetUserMovingMainWindow(bool flag);
	void UpdateMainWindowPosition();

// Go to the end and
protected:
	bool m_IsMovingMainWindow;//add this
	POINT m_InitialMouseMovingPoint; // and this
	int m_iCursorNum;