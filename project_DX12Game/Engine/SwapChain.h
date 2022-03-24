#pragma once

// 교환 사슬 장치
// [ 외주 과정 ]
// - 현재 게임 세상에 있는 상황을 묘사
// - 어떤 공식으로 어떻게 계산할지 요청함
// - GPU가 열심히 계산함 ( 외주 )
// - 결과물들을 받아서 화면에 출력

// [ 외주 결과물 ]을 어디서 받지?
// - 어떤 종이(Buffer) 에 그려서 건내달라고 부탁하자.
// - 특수 종이를 만들어서 → 처음에 건네주고 → 결과물을 해당 종이에 그린다 OK
// - 우리 화면에 특수 종이(외주 결과물)를 출력해준다

// [문제 발생]
// - 화면에 현재 결과물을 출력하는 와중에 다음 화면 외주도 맡겨야 한다.
// - 따라서 특수 종이를 2개를 만들어 바꾸어 가는 형식을 채택
// - Double Buffering

// - [1] [2]
// 현재 화면 : [1] <-> GPU 작업중 : [2]


class SwapChain
{
public:
	void Init(const WindowInfo& info, ComPtr<IDXGIFactory> dxgi, ComPtr<ID3D12CommandQueue> cmdQueue);
	void Present();
	void SwapIndex();

	ComPtr<IDXGISwapChain> GetSwapChain() { return _swapChain; }
	ComPtr<ID3D12Resource> GetRenderTarget(int32 index) { return _renderTargets[index]; }
	
	uint32 GetCurrentBackBufferIndex() { return _backBufferIndex; }
	ComPtr<ID3D12Resource> GetCurrentBackBufferResources() { return _renderTargets[_backBufferIndex]; }

private:
	ComPtr<IDXGISwapChain>	_swapChain;
	ComPtr<ID3D12Resource>	_renderTargets[SWAP_CHAIN_BUFFER_COUNT];
	uint32					_backBufferIndex = 0;
};

