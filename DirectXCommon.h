#pragma once
#include "Logger.h"

#include <d3d12.h>
#include <dxgi1_6.h>
#include <wrl.h>


using namespace Microsoft::WRL;

// DirectXの基盤
class DirectXCommon
{
public:// メンバ関数
	// 初期化関数
	void Initialize();

	void DeviceInitialize();
	void CommandInitialize();

private:
	HRESULT hr;

	// デバイスの生成
	ComPtr<ID3D12Device> device;
	// DXGIファクトリ
	ComPtr<IDXGIFactory7> dxgiFactory;
};

