#pragma once

// �η� �繫��
// ���� ��ü ����

// DX9 ������ Device���� ���� ����
// ������ ������ �ö󰨿� ����
// ���� �����ϴ� �������� �ٲ�
class Device
{
public:
	void Init();

	ComPtr<IDXGIFactory> GetDXGI() { return _dxgi; }
	ComPtr<ID3D12Device> GetDevice() { return _device; }
private:
	// COM ( Component Object Model )
	// DX�� ���α׷��� ����� �������� ���� ȣȯ���� �����ϰ� �ϴ� ���
	// COM��ü ( COM �������̽� ��� )
	// ComPtr ������ ����Ʈ ������

	ComPtr<ID3D12Debug>		_debugController;
	ComPtr<IDXGIFactory>	_dxgi; // ȭ�� ���� ���
	ComPtr<ID3D12Device>	_device; // ���� ��ü ����
};

