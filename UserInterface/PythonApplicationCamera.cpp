// SEARCH IN: void CPythonApplication::__UpdateCamera()

	//////////////////////

	if (pMainCamera->IsDraging())
		SkipRenderBuffering(3000);

	//////////////////////

// ADD BEFORE:

#ifdef ENABLE_SHAKE_CAMERA
	const float fCurrentShakeTime = DX::StepTimer::Instance().GetTotalSeconds();
	if (m_fShakeCameraEndTime > fCurrentShakeTime)
	{
		if (fCurrentShakeTime >= m_fShakeCameraNextTime)
		{
			const float fPower = static_cast<float>(m_iShakeCameraLevel) * 4.0f;
			const float fFade = fMIN(1.0f, (m_fShakeCameraEndTime - fCurrentShakeTime) * 4.0f);
			const float fStrength = fPower * fFade;

			m_v3ShakeCameraOffset.x = (static_cast<float>((rand() % 2001) - 1000) / 1000.0f) * fStrength;
			m_v3ShakeCameraOffset.y = (static_cast<float>((rand() % 2001) - 1000) / 1000.0f) * (fStrength * 0.65f);
			m_v3ShakeCameraOffset.z = (static_cast<float>((rand() % 2001) - 1000) / 1000.0f) * (fStrength * 0.85f);
			m_fShakeCameraNextTime = fCurrentShakeTime + 0.035f;
		}

		pMainCamera->MoveAlongCross(m_v3ShakeCameraOffset.x);
		pMainCamera->MoveFront(m_v3ShakeCameraOffset.y);
		pMainCamera->MoveVertical(m_v3ShakeCameraOffset.z);
	}
	else if (m_iShakeCameraLevel != 0)
	{
		m_fShakeCameraEndTime = 0.0f;
		m_fShakeCameraNextTime = 0.0f;
		m_iShakeCameraLevel = 0;
		m_v3ShakeCameraOffset = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	}
#endif