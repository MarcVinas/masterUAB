#include "ContextManager.h"


CContextManager::CContextManager(void)
{
	l_D3DDevice = NULL; // esta clase, el device, nos sirve para crear objetos de DirectX
	l_DeviceContext= NULL; // el contexto nos va a servir para usar objetos de DirectX
	l_SwapChain= NULL;
}


CContextManager::~CContextManager(void)
{
	l_D3DDevice->Release();
	l_DeviceContext->Release();
	l_SwapChain->Release();
}

/***************************************************************************************
**         Primero vamos a coger el rendertarget que ha definido la SwapChain         **
***************************************************************************************/
/*
{
	ID3D11RenderTargetView*	l_RenderTargetView;

	ID3D11Texture2D *pBackBuffer;
	if (FAILED(m_SwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer)))
		return FALSE;
	HRESULT hr = m_D3DDevice->CreateRenderTargetView(pBackBuffer, NULL, &l_RenderTargetView);
	pBackBuffer->Release();
		
}*/

/***************************************************************************************
**  Para pintar en DirectX, primero necesitamos crear un contexto de DirectX.         **
**  Para ello vamos a definir la "cadena de intercambio", o sea, cómo se va a         **
**  comportar nuestro programa cada "frame"                                           **
***************************************************************************************/

HRESULT  CContextManager::Init(int Height, int Width, HWND createWindow){
	// Tendremos que crear y rellenar una estructura de este tipo
	DXGI_SWAP_CHAIN_DESC desc;
	ZeroMemory(&desc, sizeof(desc));
	// o
	//
	//DXGI_SWAP_CHAIN_DESC desc = {};
	desc.BufferCount = 1;
	desc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	desc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	desc.Windowed = TRUE;
	// TODO:
	desc.BufferDesc.Width=Width;
	desc.BufferDesc.Height=Height;
	desc.BufferDesc.RefreshRate.Numerator=1;
	desc.BufferDesc.RefreshRate.Denominator=60;
	desc.OutputWindow=createWindow;
	desc.SampleDesc.Count=1;
	//desc.SampleDesc.Quality;
	//desc. ????

	// Que DirectX queremos
	D3D_FEATURE_LEVEL featureLevels[] =
	{
		D3D_FEATURE_LEVEL_11_0,
		D3D_FEATURE_LEVEL_10_1,
		D3D_FEATURE_LEVEL_10_0,
	};
	UINT numFeatureLevels = ARRAYSIZE(featureLevels);
		/*
	ID3D11Device *l_D3DDevice = NULL; // esta clase, el device, nos sirve para crear objetos de DirectX
	ID3D11DeviceContext *l_DeviceContext=NULL; // el contexto nos va a servir para usar objetos de DirectX
	IDXGISwapChain *l_SwapChain=NULL; // la cadena de swap
	*
	contextManager->
		
	*/
	//if (FAILED(D3D11CreateDeviceAndSwapChain(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, 0, featureLevels, numFeatureLevels, D3D11_SDK_VERSION, &desc, &l_SwapChain, &l_D3DDevice, NULL, &l_DeviceContext)))
	HRESULT hresult=  D3D11CreateDeviceAndSwapChain(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, 0, featureLevels, numFeatureLevels, D3D11_SDK_VERSION, &desc, &l_SwapChain, &l_D3DDevice, NULL, &l_DeviceContext);
	if(FAILED(hresult))
	{
		return S_FALSE;
	}
	return S_OK;
}

/***************************************************************************************
**         Primero vamos a coger el rendertarget que ha definido la SwapChain         **
***************************************************************************************/

bool CContextManager::initRenderTarget(){
	

	ID3D11Texture2D *pBackBuffer;
	if (FAILED(l_SwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer)))
		return FALSE;
	HRESULT hr = l_D3DDevice->CreateRenderTargetView(pBackBuffer, NULL, &l_RenderTargetView);
	pBackBuffer->Release();
		
}

/***************************************************************************************
**					A partir de aquí ya podemos renderizar                            **
***************************************************************************************/

void CContextManager::Render()
{
//Limpiar el framebuffer:
	float color[4] = {1,0,1,1};
l_DeviceContext->ClearRenderTargetView(l_RenderTargetView,color);
//ID3D11DeviceContext::ClearDepthStencilView

//definir a que target vamos a pintar:
l_DeviceContext->OMSetRenderTargets(1, &l_RenderTargetView, nullptr);

//definir el viewport:
l_DeviceContext->RSSetViewports();

//TODO renderizar aqui

//presentar lo pintado:
l_SwapChain->Present();
}