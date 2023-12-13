#pragma once
#include"KhachHang.h"
class VietNam :public KhachHang
{
public:
	static float dinhMuc;
	~VietNam() {
		return;
	}
	void nhap() {
		KhachHang::nhap();
	}
	void xuat() {
		KhachHang::xuat();
		cout << "\nDinh muc la " << VietNam::dinhMuc;
	}
	float thanhTien() {
		if (this->soLuongKW <= dinhMuc)
			return this->soLuongKW * this->donGia;
		else
			return (this->soLuongKW * this->donGia * dinhMuc) + ((this->soLuongKW - dinhMuc) * this->donGia * 2.5);
	}
};

