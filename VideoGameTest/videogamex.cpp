#include <Windows.h>
#include <d3d11.h>
#include "Application.h"
#include "DebugRender.h"

#include "ContextManager.h"
//#include <d3dx11.h>

/*#ifdef NDEBUG
#pragma comment(lib,"d3dx11.lib")
#else
#pragma comment(lib,"d3dx11d.lib")
#endif*/

#pragma comment(lib,"d3d11.lib")
//#pragma comment(lib,"Graphics_d.lib")
/*#pragma comment(lib,"dxerr.lib")
#pragma comment(lib,"dxguid.lib")*/

#define APPLICATION_NAME	"VIDEOGAMETEST"
#define WIDTH_APPLICATION    800
#define HEIGHT_APPLICATION   600

//-----------------------------------------------------------------------------
// Name: MsgProc()
// Desc: The window's message handler
//-----------------------------------------------------------------------------
LRESULT WINAPI MsgProc( HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam )
{

  switch( msg )
  {
  case WM_DESTROY:
    {
      PostQuitMessage( 0 );
      return 0;
    }
    break;
  case WM_KEYDOWN:
    {
      switch( wParam )
      {
      case VK_ESCAPE:
        //Cleanup();
        PostQuitMessage( 0 );
        return 0;
        break;
      }
    }
    break;
  }//end switch( msg )

  return DefWindowProc( hWnd, msg, wParam, lParam );
}





//-----------------------------------------------------------------------
// WinMain
//-----------------------------------------------------------------------
int APIENTRY WinMain(HINSTANCE _hInstance, HINSTANCE _hPrevInstance, LPSTR _lpCmdLine, int _nCmdShow)
{
  // Register the window class
  WNDCLASSEX wc = {	sizeof(WNDCLASSEX), CS_CLASSDC, MsgProc, 0L, 0L, GetModuleHandle(NULL), NULL, NULL, NULL, NULL, APPLICATION_NAME, NULL };

  RegisterClassEx( &wc );

  // Create the application's window
  // Calcular el tamano de nuestra ventana
	RECT rc = {
			0, 0, WIDTH_APPLICATION, HEIGHT_APPLICATION
		};
	AdjustWindowRect( &rc, WS_OVERLAPPEDWINDOW, FALSE);

	// Crear la ventana en si
	HWND hWnd = CreateWindow( APPLICATION_NAME, APPLICATION_NAME, WS_OVERLAPPEDWINDOW, 100, 100, rc.right - rc.left, rc.bottom - rc.top, NULL, NULL, wc.hInstance, NULL);


	

  // Añadir aquí el Init de la applicacioón
	CContextManager context;
	context.CreateContext(hWnd,WIDTH_APPLICATION, HEIGHT_APPLICATION );
	context.CreateBackBuffer(hWnd,WIDTH_APPLICATION, HEIGHT_APPLICATION );
	
	ShowWindow( hWnd, SW_SHOWDEFAULT );
	
	context.InitStates();
	CDebugRender debugRender(context.GetDevice());
	CApplication application(&debugRender,&context);
  
 // contextManager->initRenderTarget();
  UpdateWindow( hWnd );
  MSG msg;
  ZeroMemory( &msg, sizeof(msg) );

  // Añadir en el while la condición de salida del programa de la aplicación

  while( msg.message != WM_QUIT )
  {
    if( PeekMessage( &msg, NULL, 0U, 0U, PM_REMOVE ) )
    {
      TranslateMessage( &msg );
      DispatchMessage( &msg );
    }
    else
    {
       // Main loop: Añadir aquí el Update y Render de la aplicación principal
		application.Update(1/10.f);
		application.Render();
		//Render();

    }
  }
  UnregisterClass( APPLICATION_NAME, wc.hInstance );

  // Añadir una llamada a la alicación para finalizar/liberar memoria de todos sus datos

  return 0;
}


