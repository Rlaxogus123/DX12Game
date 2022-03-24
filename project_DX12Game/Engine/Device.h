#pragma once

// 인력 사무소
// 각종 개체 생성

// DX9 에서는 Device에서 전부 관리
// 하지만 버전이 올라감에 따라서
// 각자 관리하는 형식으로 바뀜
class Device
{
public:
	void Init();

	ComPtr<IDXGIFactory> GetDXGI() { return _dxgi; }
	ComPtr<ID3D12Device> GetDevice() { return _device; }
private:
	// COM ( Component Object Model )
	// DX의 프로그래밍 언어의 독립성과 하위 호환성을 가능하게 하는 기술
	// COM객체 ( COM 인터페이스 사용 )
	// ComPtr 일종의 스마트 포인터

	ComPtr<ID3D12Debug>		_debugController;
	ComPtr<IDXGIFactory>	_dxgi; // 화면 관련 기능
	ComPtr<ID3D12Device>	_device; // 각종 객체 생성
};

