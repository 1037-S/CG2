#pragma once
#include <windows.h>
#include <cstdint>



// WindowsAPI
class WinApp
{
public:

	// ウィンドウサイズの設定
	static const int32_t kClientWidth = 1280;
	static const int32_t kClientHeight = 720;

	// ウィンドウプロシージャ（Windowsからのメッセージを受け取る関数）
	static LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

	void Initialize();
	void Update();
	// メッセージの処理

	// 終了
	void Finalize();

	// ウィンドウハンドルの取得
	HWND GetHwnd() const { return hwnd; }

	// ウィンドウクラスのゲッター
	HINSTANCE GetHInstance() const { return wc.hInstance; }
private:

	//HRESULT hr;
	HWND hwnd = nullptr;     // ウィンドウハンドル
	WNDCLASS wc{};           // ウィンドウクラス
	// ウィンドウサイズを表す構造体にクライアント領域を入れる
	//RECT wrc{};
};

