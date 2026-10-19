#include "Input.h"
#include <cassert>
#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")



void Input::Initialize(WinApp* winApp)
{
	// 借りてきたWinAppのインスタンスを記録
	//this->winApp = winApp;

	HRESULT result;

	// DirectInputの初期化
	//ComPtr<IDirectInput8>directInput = nullptr;
	result = DirectInput8Create(winApp->GetHInstance(), DIRECTINPUT_VERSION, IID_IDirectInput8,
		(void**)&directInput, nullptr);
	assert(SUCCEEDED(result));

	// キーボードデバイスの初期化
	result = directInput->CreateDevice(GUID_SysKeyboard, &keyboard, NULL);
	assert(SUCCEEDED(result));

	// 入力データ形式のセット
	result = keyboard->SetDataFormat(&c_dfDIKeyboard); // 標準形式
	assert(SUCCEEDED(result));

	// 排他制御レベルのセット
	result = keyboard->SetCooperativeLevel(
		winApp->GetHwnd(), DISCL_FOREGROUND | DISCL_NONEXCLUSIVE | DISCL_NOWINKEY);
	assert(SUCCEEDED(result));
}

void Input::Update()
{		
	HRESULT result;

	// 前回のキー入力を保存
	memcpy(keyPre,key,sizeof(key));

	// キーボードの取得開始
	result = keyboard->Acquire();
	// すべてのキーの「入力状態を取得する
	result = keyboard->GetDeviceState(sizeof(key), key);
}

bool Input::PushKey(BYTE keyNumber)
{
	if (key[keyNumber])
	{
		return true;
	}

	return false;
}

bool Input::TriggerKey(BYTE keyNumber)
{
	if (!keyPre[keyNumber] && key[keyNumber])
	{
		return true;
	}
	return false;
}
