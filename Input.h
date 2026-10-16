#pragma once
#include <Windows.h>
#include <wrl.h>
#define DIRECTINPUT_VERSION 0x0800 // DirectInputのバージョン指定
#include <dinput.h>


class Input
{
public:
	// namespaceを省略
	template <class T> using ComPtr = Microsoft::WRL::ComPtr<T>;

public:
	// 初期化関数
	void Initialize(HINSTANCE hInstance, HWND hwnd);
	// 更新関数
	void Update();

/// <summary>
/// キーの押下状態をチェックする関数
/// </summary>
/// <param name="keyNumber">キーの番号( DIK_0 等)</param>
/// <returns>キーが押されている場合はtrue、それ以外はfalse</returns>
	bool PushKey(BYTE keyNumber);

/// <summary>
/// キーのトリガーをチェックする関数
/// </summary>
/// <param name="keyNumber">キーの番号( DIK_0 等)</param>
/// <returns>トリガーか否か</returns>
	bool TriggerKey(BYTE keyNumber);

private:
	// すべてのキーの「入力状態」を取得する
	BYTE key[256] = {};
	// 前回の全キーの状態
	BYTE keyPre[256] = {};
	// キーボードのデバイス
	ComPtr<IDirectInputDevice8>keyboard;
	// DirectInputのインスタンス
	ComPtr<IDirectInput8>directInput;
};

