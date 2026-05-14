// SEARCH:

PyObject* appGetCamera(PyObject* poSelf, PyObject* poArgs)

// ADD BEFORE:

#ifdef ENABLE_SHAKE_CAMERA
PyObject* appSetShakeCamera(PyObject* poSelf, PyObject* poArgs)
{
	float fDuration;
	if (!PyTuple_GetFloat(poArgs, 0, &fDuration))
		return Py_BuildException();

	int iLevel;
	if (!PyTuple_GetInteger(poArgs, 1, &iLevel))
		return Py_BuildException();

	CPythonApplication::Instance().SetShakeCamera(fDuration, iLevel);
	return Py_BuildNone();
}
#endif

// SEARCH:

{ "GetCamera", appGetCamera, METH_VARARGS },

// ADD BEFORE:

#ifdef ENABLE_SHAKE_CAMERA
		{ "SetShakeCamera", appSetShakeCamera, METH_VARARGS },
#endif