#pragma once

#include "SphericalCameraController.h"
#include "FPSCameraController.h"
#include "HelperTypes.h"
#include "MaterialManager.h"

class CDebugRender;
class CContextManager;

class CApplication
{
public:
	CApplication(CDebugRender *_DebugRender, CContextManager *_ContextManager);
	~CApplication();

	void SwitchCamera();

	void Update(float _ElapsedTime);
	void Render();

	void CApplication::Init()
	{
		m_MaterialManager.AddMaterials("Data\\materials.xml");

		m_Cube.AddSubmesh(m_DebugRender->GetSimpleCube(), "solid material", m_DebugRender->GetSimpleCubeBSRadi(), m_DebugRender->GetSimpleCubeBBMin(), m_DebugRender->GetSimpleCubeBBMax());
	}

private:

	CSphericalCameraController m_SphericalCamera;
	CFPSCameraController m_FPSCamera;
	CMaterialManager m_MaterialManager;
	int m_CurrentCamera;

	CDebugRender *m_DebugRender;
	CContextManager *m_ContextManager;

	CColor m_BackgroundColor;
	SPositionOrientation m_CubeTransform;
};

