#pragma once
#include"NuocNgoai.h"
#include"KhachHang.h"
class HoaDon
{
private:
	int soLuong;
	KhachHang** dsHoaDon;
public:
	HoaDon() {
		this->soLuong = 0;
		this->dsHoaDon = NULL;
	}
	~HoaDon() {
		for (int i = 0; i < this->soLuong; i++) {
			this->dsHoaDon[i] = NULL;
		}
		this->soLuong = 0;
	}
	void nhap() {
		cout << "\n------Nhap so luong hoa don--------" << endl;
		cin >>this->soLuong;
		this->dsHoaDon = new KhachHang * [this->soLuong];
		for (int i = 0; i < this->soLuong; i++) {
			string quocGia = "";
			cout << "\n--Nhap quoc gia can thanh toan--"<<endl;
			cin >> quocGia;
			KhachHang* kh = NULL;
			if (quocGia == "VN")
				kh = new VietNam();
			else if (quocGia == "NN")
				kh = new NuocNgoai();
			else
			{
				cout << "\n===ERORR===\nNHAP SAI QUOC GIA" << endl;
				system("pause");
			}
			kh->nhap();
			this->dsHoaDon[i] = kh;
		}
	}
	void xuat() {
		for (int i = 0; i < this->soLuong; i++) {
			cout << "\nDanh sach hoa don thu " << i+1;
			this->dsHoaDon[i]->xuat();
			cout << "\n";
		}
	}
	void tongTungLoaiKhachHang(int & khachHangVN, int & khachHangNN) {
		for (int i = 0; i < this->soLuong; i++) {
			string quocGia = typeid(*this->dsHoaDon[i]).name();
			if (quocGia == "class VietNam")
				khachHangVN = khachHangVN + this->dsHoaDon[i]->thanhTien();
			else if (quocGia == "class NuocNgoai")
				khachHangNN = khachHangNN + this->dsHoaDon[i]->thanhTien();
		}
	}
	float trungBinhThanhTienNN() {
		float tinhTrungBinh = 0;
		int dem = 0;
		for (int i = 0; i < this->soLuong; i++) {
			string quocGia = typeid(*this->dsHoaDon[i]).name();
			if (quocGia == "class NuocNgoai")
			{
				tinhTrungBinh = tinhTrungBinh + this->dsHoaDon[i]->thanhTien();
				dem++;
			}
		}
		if (dem == 0)
			return dem;
		else
			return tinhTrungBinh / dem;
	}
	float maxTienDienVietNamCanTim() {
		float maxTienDien = 0;
		for (int i = 0; i < this->soLuong; i++) {
			string quocGia = typeid(*this->dsHoaDon[i]).name();
			if (quocGia == "class VietNam")
			{
				if (this->dsHoaDon[i]->getThang() == 11 && this->dsHoaDon[i]->getNam() == 2015)
					if (maxTienDien < this->dsHoaDon[i]->thanhTien())
						maxTienDien = this->dsHoaDon[i]->thanhTien();
			}
		}
		return maxTienDien;
	}
	HoaDon timKhachHangCoNhieuTienDIenNhat() {
		float maxTienDien = maxTienDienVietNamCanTim();
		HoaDon dsKetQua;
		dsKetQua.dsHoaDon = new KhachHang * [this->soLuong];
		for (int i = 0; i < this->soLuong; i++) {
			string quocGia = typeid(*this->dsHoaDon[i]).name();
			if (quocGia == "class VietNam")
			{
				if (this->dsHoaDon[i]->getThang() == 11 && this->dsHoaDon[i]->getNam() == 2015)
					if (maxTienDien == this->dsHoaDon[i]->thanhTien())
						dsKetQua.dsHoaDon[dsKetQua.soLuong++] = this->dsHoaDon[i];
			}
		}
		return dsKetQua;
	}
	
};

