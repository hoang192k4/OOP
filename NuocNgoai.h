#pragma once
#include"KhachHang.h"
class NuocNgoai :public KhachHang
{
private:
	string quocTich;
public:
	NuocNgoai() {
		this->quocTich = "";
	}
	~NuocNgoai() {
		return;
	}
	void nhap() {
		KhachHang::nhap();
		cout << "Nhap quoc tich "; cin >> this->quocTich;
	}
	void xuat() {
		KhachHang::xuat();
		cout << "\nQuoc tich la " << this->quocTich;
	}
	float thanhTien() {
		return this->soLuongKW * this->donGia;
	}
};

