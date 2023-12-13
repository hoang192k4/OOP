#pragma once
#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;
class KhachHang
{
private:
	int namHienTai = 2023;
protected:
	int maKhachhang;
	string hoTen;
	int ngay, thang, nam;
	int soLuongKW;
	float donGia;
public:
	KhachHang() {
		this->maKhachhang = 0;
		this->hoTen = "";
		this->ngay = 0;
		this->thang = 0;
		this->nam = 0;
		this->soLuongKW = 0;
		this->donGia = 0;
	}
	~KhachHang() {
		return;
	}
	int getThang() {
		return this->thang;
	}
	int getNam() {
		return this->nam;
	}
	virtual void nhap() {
		cout << "\nNhap ma khach hang : "; cin >> this->maKhachhang;
		cin.ignore();
		cout << "Nhap ho ten khach hang : "; getline(cin, this->hoTen);
		cout << "Nhap ngay : "; cin >> this->ngay;
		if (this->ngay < 1 || this->ngay>31)
		{
			cout << "\n===ERORR===\nNHAP KHONG DUNG NGAY"<<endl;
			system("pause");
		}
		cout << "Nhap thang : "; cin >> this->thang;
		if (this->thang < 1 || this->thang>12)
		{
			cout << "\n===ERORR===\nNHAP KHONG DUNG THANG"<<endl;
			system("pause");
		}
		cout << "Nhap nam : "; cin >> this->nam;
		if (this->nam<1 || this->nam>this->namHienTai)
		{
			cout << "\n===ERORR===\nNHAP KHONG DUNG NAM"<<endl;
			system("pause");
		}
		cout << "Nhap lo luong tieu thu : "; cin >> this->soLuongKW;
		cout << "Nhap don gia tien dien : "; cin >> this->donGia;
	}
	virtual void xuat() {
		cout << "\nMa khach hang " << this->maKhachhang;
		cout << "\nHo ten khach hang " << this->hoTen;
		cout << "\nNgay thang nam Hoa don " << this->ngay << "/" << this->thang << "/" << this->nam;
		cout << "\nSo luong tieu thu dien " << this->soLuongKW;
		cout << "\nDon gia KW dien " << this->donGia;
	}
	virtual float thanhTien() = 0;
};

