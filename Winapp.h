#pragma once
#include <windows.h>
#include <cstdint>

class Winapp
{
public:

	// ウィンドウサイズの設定
	static const int32_t kWindowWidth = 1280;
	static const int32_t kWindowHeight = 720;

	void Initialize();
	bool ProcessMessage();
	void Finalize();

	// ウィンドウハンドルの取得
	HWND GetHwnd() const { return hwnd_; }
private:

	// ウィンドウプロシージャ（Windowsからのメッセージを受け取る関数）
	static LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

	HWND hwnd_ = nullptr;     // ウィンドウハンドル
	WNDCLASS wc_{};           // ウィンドウクラス
};

