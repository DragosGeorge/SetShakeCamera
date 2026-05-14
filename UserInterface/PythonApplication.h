// SEARCH:

float GetPitch();

// ADD UNDER:

#ifdef ENABLE_SHAKE_CAMERA
	void SetShakeCamera(float fDuration, int iLevel);
#endif

// SEARCH:

float m_fCameraZoomSpeed;

// ADD UNDER:

#ifdef ENABLE_SHAKE_CAMERA
	float m_fShakeCameraEndTime;
	float m_fShakeCameraNextTime;
	int m_iShakeCameraLevel;
	D3DXVECTOR3 m_v3ShakeCameraOffset;
#endif