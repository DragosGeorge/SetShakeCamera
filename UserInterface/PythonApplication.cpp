// SEARCH CPythonApplication::CPythonApplication() : UNDER -> 

m_fRotationSpeed = 0.0f;
m_fPitchSpeed = 0.0f;
m_fZoomSpeed = 0.0f;

// ADD:

#ifdef ENABLE_SHAKE_CAMERA
	m_fShakeCameraEndTime = 0.0f;
	m_fShakeCameraNextTime = 0.0f;
	m_iShakeCameraLevel = 0;
	m_v3ShakeCameraOffset = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
#endif


// SEARCH:

void CPythonApplication::SetCameraSpeed(int iPercentage)
{
	m_fCameraRotateSpeed = c_fDefaultCameraRotateSpeed * float(iPercentage) / 100.0f;
	m_fCameraPitchSpeed = c_fDefaultCameraPitchSpeed * float(iPercentage) / 100.0f;
	m_fCameraZoomSpeed = c_fDefaultCameraZoomSpeed * float(iPercentage) / 100.0f;
}

// ADD UNDER:

#ifdef ENABLE_SHAKE_CAMERA
void CPythonApplication::SetShakeCamera(float fDuration, int iLevel)
{
	if (fDuration <= 0.0f || iLevel <= 0)
	{
		m_fShakeCameraEndTime = 0.0f;
		m_fShakeCameraNextTime = 0.0f;
		m_iShakeCameraLevel = 0;
		m_v3ShakeCameraOffset = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		return;
	}

	m_iShakeCameraLevel = MINMAX(1, iLevel, 10);
	m_fShakeCameraEndTime = DX::StepTimer::Instance().GetTotalSeconds() + fDuration;
	m_fShakeCameraNextTime = 0.0f;
	m_v3ShakeCameraOffset = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
}
#endif