#include"NuocNgoai.h"
#include"VietNam.h"
#include"HoaDon.h"
float VietNam::dinhMuc = 0;
int main() {
	VietNam::dinhMuc = 250;
	HoaDon hd;
	cout << "===========Nhap danh sach hoa don=============";
	hd.nhap();
	cout << "=============Xuat danh sach hoa don=============";
	hd.xuat();
	int thanhTienKHVN = 0, thanhTienKHNN = 0;
	hd.tongTungLoaiKhachHang(thanhTienKHVN, thanhTienKHNN);
	cout << "\nTong thanh tien dien VIET NAM " << thanhTienKHVN;
	cout << "\nTong thanh tien dien NUOC NGOAI " << thanhTienKHNN;
	float tungBinhTTNN = hd.trungBinhThanhTienNN();
	cout << "\nTrung binh thanh tien cua tong hoa don nguoi nuoc ngoai " << tungBinhTTNN;
	HoaDon dsVietNam= hd.timKhachHangCoNhieuTienDIenNhat();
	cout << "\n\n=======DS nhung hoa don co gia tien cao nhat trong thang 11 nam 2015=======";
	dsVietNam.xuat();
	return 0;
}