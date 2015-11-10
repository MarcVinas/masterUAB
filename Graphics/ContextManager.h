#pragma once

#include <d3d11.h>
#pragma comment(lib,"d3d11.lib")


class CContextManager
{
private:
	ID3D11Device *l_D3DDevice; // esta clase, el device, nos sirve para crear objetos de DirectX
	ID3D11DeviceContext *l_DeviceContext; // el contexto nos va a servir para usar objetos de DirectX
	IDXGISwapChain *l_SwapChain; // la cadena de swap*/
	ID3D11RenderTargetView*	l_RenderTargetView;
public:
	CContextManager(void);
	~CContextManager(void);

	
	ID3D11Device* GetID3D11Device(){
		return l_D3DDevice;
	}
	void SetID3D11Device(ID3D11Device* iD3D11Device)
	{
		l_D3DDevice=iD3D11Device;
	}

	ID3D11DeviceContext* GetID3D11DeviceContext(){
		return l_DeviceContext;
	}
	void SetID3D11DeviceContext(ID3D11DeviceContext* iD3D11DeviceContext)
	{
		l_DeviceContext=iD3D11DeviceContext;
	}

	ID3D11Device* GetIDXGISwapChain(){
		return l_D3DDevice;
	}
	void SetIDXGISwapChain(IDXGISwapChain* iDXGISwapChain)
	{
		l_SwapChain=iDXGISwapChain;
	}

	HRESULT  Init(int Height, int Width, HWND createWindow);
	bool initRenderTarget();
	void Render();

};

