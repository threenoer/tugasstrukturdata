#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#define N 100
using namespace std;

//---------------------------D A T A  M O B I L------------------------------
typedef struct
{
	string noTNKB;
	string merek;
	string warna;
	string carStatus;
	int IDcarStatus;
	int tahunPembuatan;
	int tarifSewa;
}dataMobil;

typedef struct tNodeMobil *addressMobil;
typedef struct tNodeMobil
{
	dataMobil InfoMobil;
	addressMobil NextMobil;
}NodeMobil;

typedef NodeMobil *ListMobil;

//----------------------------D A T A  D R I V E R-----------------------------
typedef struct
{
	string noKTP;
	string namaDriver;
	string alamatDriver;
	string statusDriver;
	int IDstatusDriver;
	int usiaDriver;
}dataDriver;

typedef struct tNodeDriver *addressDriver;
typedef struct tNodeDriver
{
	dataDriver InfoDriver;
	addressDriver NextDriver;
}NodeDriver;

typedef NodeDriver *ListDriver;

//--------------------------D A T A  K O N S U M E N---------------------------
typedef struct
{
	string noKtp;
	string nama;
	string alamat;
}dataKonsumen;

typedef struct tNodeKonsumen *addressKonsumen;
typedef struct tNodeKonsumen
{
	dataKonsumen InfoKonsumen;
	addressKonsumen NextKonsumen;
}NodeKonsumen;

typedef NodeKonsumen *ListKonsumen;

//-------------------------D A T A  T R A N S A K S I--------------------------
typedef struct
{
	string namaKonsumen;
	string alamat;
	string noTNKB;
	string namaDriver;
	string HTanggalPinjam;
	string HTanggalKembali;
	int ATanggalPinjam;
	int AtanggalKembali;
	int IDdriver;
	int hargaMobil;
}dataTransaksi;

typedef struct tNodeTransaksi *addressTransaksi;
typedef struct tNodeTransaksi
{
	dataTransaksi InfoTransaksi;
	addressTransaksi NextTransakksi;
}NodeTransaksi;

typedef NodeTransaksi *ListTransaksi;

//----------------------D A T A  P E N G E M B A L I A N----------------------
typedef struct
{
	string nama;
	string alamat;
	string noTNKB;
	string namaDriver;
	string HTanggalPinjam;
	string HTanggalSekarang;
	int lamaHari;
	int ATanggalSekarang;
	int ATanggalPinjam;
	int denda;
	int tarifDriver;
	int tarifMobil;
	int total;
	int payment;
	int change;
}dataPengembalian;

typedef struct tNodePengembalian *addressPengembalian;
typedef struct tNodePengembalian
{
	dataPengembalian InfoPengembalian;
	addressPengembalian NextPengembalian;
}NodePengembalian;

typedef NodePengembalian *ListPengembali;
//----------------------------S P E S I F I K A S I---------------------------
void CreateEmptyMobil(ListMobil &Mobil);
void CreateEmptyDriver(ListDriver &Driver);
void CreateEmptyKonsumen(ListKonsumen &Konsumen);
void CreateEmptyTPeminjaman(ListTransaksi &Transaksi);
void CreateEmptyPengembalian(ListPengembali &Pengembali);
bool IsEmptyMobil(ListMobil Mobil);
bool IsEmptyDriver(ListDriver Driver);
bool IsEmptyKonsumen(ListKonsumen Konsumen);
bool IsEmptyTPeminjaman(ListTransaksi Transaksi);
bool IsEmptyPengembalian(ListPengembali Pengembali);
bool IsOneElementMobil(ListMobil Mobil);
bool IsOneElementDriver(ListDriver Driver);
bool IsOneElementKonsumen(ListKonsumen Konsumen);
bool IsOneElementTPeminjaman(ListTransaksi Transaksi);
bool IsOneElementPengembalian(ListPengembali Pengembali);
addressMobil AlokasiMobil(dataMobil Mobil);
addressDriver AlokasiDriver(dataDriver Driver);
addressKonsumen AlokasiKonsumen(dataKonsumen Konsumen);
addressTransaksi AlokasiTPeminjaman(dataTransaksi Transaksi);
addressPengembalian AlokasiPengembalian(dataPengembalian Pengembali);
void InsertFirstMobil(ListMobil &Mobil, addressMobil Car);
void InsertFirstDriver(ListDriver &Driver, addressDriver Pengemudi);
void InsertFirstKonsumen(ListKonsumen &Konsumen, addressKonsumen Renter);
void InsertFirstTPeminjaman(ListTransaksi &Transaksi, addressTransaksi Trans);
void InsertFirstPengembalian(ListPengembali &Pengembali, addressPengembalian Return);
void InsertAfterMobil(ListMobil &Mobil, addressMobil Prec, addressMobil Car);
void InsertAfterDriver(ListDriver &Driver, addressDriver Prec, addressDriver Pengemudi);
void InsertAfterKonsumen(ListKonsumen &Konsumen, addressKonsumen Prec, addressKonsumen Renter);
void InsertAfterTPeminjaman(ListTransaksi &Transaksi, addressTransaksi Prec, addressTransaksi Trans);
void InsertAfterPengembalian(ListPengembali &Pengembali, addressPengembalian Prec, addressPengembalian Return);
void InsertLastMobil(ListMobil &Mobil, addressMobil Car);
void InsertLastDriver(ListDriver &Driver, addressDriver Pengemudi);
void InsertLastKonsumen(ListKonsumen &Konsumen, addressKonsumen Renter);
void InsertLastTPeminjaman(ListTransaksi &Transaksi, addressTransaksi Trans);
void InsertLastPengembalian(ListPengembali &Pengembali, addressPengembalian Return);
void PrintInfoMobil(ListMobil Mobil);
void PrintInfoDriver(ListDriver Driver);
void PrintInfoKonsumen(ListKonsumen Konsumen);
void PrintInfoTPeminjaman(ListTransaksi Transaksi);
void PrintInfoPengembalian(ListPengembali Pengembali);
bool IsFoundMobil(ListMobil &Mobil, string _noTNKB);
bool IsFoundDriver(ListDriver &Driver, string nama);
bool IsFoundKonsumen(ListKonsumen &Konsumen, string _nama);
bool IsFoundTPeminjaman(ListTransaksi &Transaksi, string _nama);
bool IsFoundPengembalian(ListPengembali &Pengembali, string _nama);
void DelMobilFirst(ListMobil &Mobil);
void DelDriverFirst(ListDriver &Driver);
void DelKonsumenFirst(ListKonsumen &Konsumen);
void DelTPeminjamanFirst(ListTransaksi &Transaksi);
void DelPengembalianFirst(ListPengembali &Pengembali);
void DelMobilLast(ListMobil &Mobil);
void DelDriverLast(ListDriver &Driver);
void DelKonsumenLast(ListKonsumen &Konsumen);
void DelTPeminjamanLast(ListTransaksi &Transaksi);
void DelPengembalianLast(ListPengembali &Pengembali);
void DelMobil(ListMobil &Mobil, string noTNKB);
void DelDriver(ListDriver &Driver, string nama);
void DelKonsumen(ListKonsumen &Konsumen, string nama);
void DelTPeminjaman(ListTransaksi &Transaksi, string nama);
void DelPengembalian(ListPengembali &Pengembali, string nama);
addressMobil EditMobil(ListMobil Mobil, string cari);
addressDriver EditDriver(ListDriver Driver, string cari);
addressKonsumen EditKonsumen(ListKonsumen Konsumen, string cari);
addressTransaksi EditTPeminjaman(ListTransaksi Transaksi, string cari);
addressPengembalian EditPengembalian(ListPengembali Pengembali, string cari);
unsigned int AutoNumber();
void menu();

ListMobil Mobil;
ListDriver Driver;
ListKonsumen Konsumen;
ListTransaksi Transaksi;
ListPengembali Pengembali;
int no=0;

//--------------------------M A I N  P R O G R A M---------------------------
int main()
{
		system("color 0d");
 		cout<<"\n\n\t\t\t\tL O A D I N G !!\n\n";
 		char a=177, b=219;
 		cout<<"\t\t\t\t";
 		for (int i=0;i<=15;i++)
 		cout<<a;
 		cout<<"\r";
 		cout<<"\t\t\t\t";
		for (int i=0;i<=15;i++)
 		{
  		cout<<b;
  		for (int j=0;j<=1e8;j++); 
 }
 system("color 0f");

	int pil, pil2;
	char ulangi;
	string BUG;
	string find;
	string nama, noTNKB, namaDriver;
	dataMobil InsertMobil;
	dataDriver InsertDriver;
	dataKonsumen InsertKonsumen;
	dataTransaksi InsertTransaksi;
	dataPengembalian InsertPengembali;
	CreateEmptyMobil(Mobil);
	CreateEmptyDriver(Driver);
	CreateEmptyKonsumen(Konsumen);
	CreateEmptyTPeminjaman(Transaksi);
	CreateEmptyPengembalian(Pengembali);

	mainmenu:
	system("cls");
	menu();
	do
	{
		cout << "Masukan pilihan anda : ";
		pil = _getch();
		switch (pil)
		{
		case '1':
		ulang :
			system("cls");
			  cout << "Master Data Mobil\n";
			  cout << "1. Tambah Data Mobil\n";
			  cout << "2. Lihat Data Mobil\n";
			  cout << "3. Edit Data Mobil\n";
			  cout << "4. Hapus Data Mobil\n";
			  cout << "0. Kembali\n";
			  cout << "Masukan Pilihan Anda : "; 
			  pil2=_getch();
			  if (pil2 == '1')
			  {
				  system("cls");
				  cout << "Tambahkan Data Mobil"<<endl<<endl;
				  getline(cin, BUG);
				  cout << "Masukan NO TNKB Mobil          : "; getline(cin, InsertMobil.noTNKB);
				  cout << "Masukan Merek Mobil            : "; getline (cin, InsertMobil.merek);
				  cout << "Masukan Warna Mobil            : "; getline(cin, InsertMobil.warna);
				  cout << "Masukan Tahun Pembuatan        : "; cin >> InsertMobil.tahunPembuatan;
				  cout << "Masukan Tarif Sewa             : "; cin >> InsertMobil.tarifSewa;
				  cout << "Masukan Status Kendaraan [0/1] : "; cin >> InsertMobil.IDcarStatus;
				  if (InsertMobil.IDcarStatus == 0)
				  {
					  InsertMobil.carStatus = "Tersedia";
				  }
				  else if (InsertMobil.IDcarStatus == 1)
				  {
					  InsertMobil.carStatus = "Disewakan";
				  }
				  addressMobil mobilBaru = AlokasiMobil(InsertMobil);
				  InsertLastMobil(Mobil, mobilBaru);
				  system("pause");
				  goto ulang;
			  }
			  else if (pil2 == '2')
			  {
				  system("cls");
				  cout << "Data Mobil" << endl << endl;
				  cout << "---------------------------------------------------------------------------------" << endl;
				  cout << setw(2) << "No" << setw(15) << "No TNKB" << setw(10) << "Merek" << setw(10) << "Warna" << setw(10) << "Tahun" << setw(15) << "Tarif Sewa" << setw(14) << "Status" << endl;
				  cout << "---------------------------------------------------------------------------------" << endl;
				  PrintInfoMobil(Mobil);
				  cout << "\n-------------------------------------------------------------------------------" << endl;
				  system("pause");
				  goto ulang;
			  }
			  else if (pil2 == '3')
			  {
				  system("cls");
				  cout << "Edit Data Mobil"<<endl<<endl;
				  getline(cin, BUG);
				  cout << "Masukan No TNKB Mobil yang ingin diedit : "; getline(cin, find);
				  addressMobil alamat;
				  alamat = EditMobil(Mobil, find);
				  if (alamat != NULL)
				  {
					  cout << "\nmasukkan nilai baru: "<<endl;
					  cout << "Masukan NO TNKB Mobil          : "; getline(cin, InsertMobil.noTNKB);
					  cout << "Masukan Merek Mobil            : "; getline(cin, InsertMobil.merek);
					  cout << "Masukan Warna Mobil            : "; getline(cin, InsertMobil.warna);
					  cout << "Masukan Tahun Pembuatan        : "; cin >> InsertMobil.tahunPembuatan;
					  cout << "Masukan Tarif Sewa             : "; cin >> InsertMobil.tarifSewa;
					  cout << "Masukan Status Kendaraan [0/1] : "; cin >> InsertMobil.IDcarStatus;
					  if (InsertMobil.IDcarStatus == 0)
					  {
						  InsertMobil.carStatus = "Tersedia";
					  }
					  else if (InsertMobil.IDcarStatus == 1)
					  {
						  InsertMobil.carStatus = "Disewakan";
					  }
					  alamat->InfoMobil = InsertMobil;
				  }
				  else
					  cout << "\nnilai "<< find <<" tidak ditemukan di dalam List";
				  system("pause");
				  goto ulang;
			  }
			  else if (pil2 == '4')
			  {
				  system("cls");
				  cout << "Hapus Data Mobil\n";
				  getline(cin, BUG);
				  cout << "Masukan No TNKB mobil yang ingin dihapus : "; getline(cin, find);
				  DelMobil(Mobil, find);
				  system("pause");
				  goto ulang;
			  }

			  else if (pil2 == '0')
			  {
				  goto mainmenu;
			  }
			  _getch();
			  break;

		case '2':
		ulang2 :
			system("cls");
			  cout << "Master Data Driver\n";
			  cout << "1. Tambah Data Driver\n";
			  cout << "2. Lihat Data Driver\n";
			  cout << "3. Edit Data Driver\n";
			  cout << "4. Hapus Data Driver\n";
			  cout << "0. Kembali\n";
			  cout << "Masukan Pilihan Anda : ";
			  pil2 = _getch();
			  if (pil2 == '1')
			  {
				  system("cls");
				  cout << "Tambahkan Data Driver" << endl << endl;
				  getline(cin, BUG);
				  cout << "Masukan No KTP Driver       : "; getline(cin, InsertDriver.noKTP);
				  cout << "Masukan Nama  Driver        : "; getline(cin, InsertDriver.namaDriver);
				  cout << "Masukan Alamat Driver       : "; getline(cin, InsertDriver.alamatDriver);
				  cout << "Masukan Usia Driver         : "; cin >> InsertDriver.usiaDriver;
				  cout << "Masukan Status Driver [0/1] : "; cin >> InsertDriver.IDstatusDriver;
				  if (InsertDriver.IDstatusDriver == 0)
				  {
					  InsertDriver.statusDriver = "Tersedia";
				  }
				  else if (InsertDriver.IDstatusDriver == 1)
				  {
					  InsertDriver.statusDriver = "Bertugas";
				  }
				  addressDriver driverBaru = AlokasiDriver(InsertDriver);
				  InsertLastDriver(Driver, driverBaru);
				  system("pause");
				  goto ulang2;
			  }
			  else if (pil2 == '2')
			  {
				  system("cls");
				  cout << "Data Driver" << endl << endl;
				  cout << "----------------------------------------------------------------------------------" << endl;
				  cout << setw(16) << "No KTP" << setw(15) << "Nama Driver" << setw(24) << "Alamat" << setw(9) << "Usia" << setw(12) << "Status" << endl;
				  cout << "----------------------------------------------------------------------------------" << endl;
				  PrintInfoDriver(Driver);
				  cout << "\n----------------------------------------------------------------------------------" << endl;
				  system("pause");
				  goto ulang2;
			  }
			  else if (pil2 == '3')
			  {
				  system("cls");
				  cout << "Edit Data Driver" << endl << endl;
				  getline(cin, BUG);
				  cout << "Masukan Nama Driver yang ingin diedit : "; getline(cin, find);
				  addressDriver alamat;
				  alamat = EditDriver(Driver, find);
				  if (alamat != NULL)
				  {
					  cout << "\nmasukkan nilai baru: " << endl;
					  cout << "Masukan No KTP Driver       : "; getline(cin, InsertDriver.noKTP);
					  cout << "Masukan Nama  Driver        : "; getline(cin, InsertDriver.namaDriver);
					  cout << "Masukan Alamat Driver       : "; getline(cin, InsertDriver.alamatDriver);
					  cout << "Masukan Usia Driver         : "; cin >> InsertDriver.usiaDriver;
					  cout << "Masukan Status Driver [0/1] : "; cin >> InsertDriver.IDstatusDriver;
					  if (InsertDriver.IDstatusDriver == 0)
					  {
						  InsertDriver.statusDriver = "Tersedia";
					  }
					  else if (InsertDriver.IDstatusDriver == 1)
					  {
						  InsertDriver.statusDriver = "Bertugas";
					  }
					  alamat->InfoDriver = InsertDriver;
				  }
				  else
					  cout << "\nnilai " << find << " tidak ditemukan di dalam List";
				  system("pause");
				  goto ulang2;
			  }
			  else if (pil2 == '4')
			  {
				  system("cls");
				  cout << "Hapus Data Driver\n";
				  getline(cin, BUG);
				  cout << "Masukan Nama Driver yang ingin dihapus : "; getline(cin, find);
				  DelDriver(Driver, find);
				  system("pause");
				  goto ulang2;
			  }

			  else if (pil2 == '0')
			  {
				  goto mainmenu;
			  }
			_getch();
			break;

		case '3':
		ulang3 :
			system("cls");
			   cout << "Master Data Konsumen\n";
			   cout << "1. Tambah Data Konsumen\n";
			   cout << "2. Lihat Data Konsumen\n";
			   cout << "3. Edit Data Konsumen\n";
			   cout << "4. Hapus Data Konsumen\n";
			   cout << "0. Kembali\n";
			   cout << "Masukan Pilihan Anda : ";
			   pil2 = _getch();
			   if (pil2 == '1')
			   {
				   system("cls");
				   cout << "Tambahkan Data Konsumen" << endl << endl;
				   getline(cin, BUG);
				   cout << "Masukan No KTP Konsumen  : "; getline(cin, InsertKonsumen.noKtp);
				   cout << "Masukan Nama  Konsumen   : "; getline(cin, InsertKonsumen.nama);
				   cout << "Masukan Alamat Konsumen  : "; getline(cin, InsertKonsumen.alamat);
				   addressKonsumen konsumenBaru = AlokasiKonsumen(InsertKonsumen);
				   InsertLastKonsumen(Konsumen, konsumenBaru);
				   system("pause");
				   goto ulang3;
			   }
			   else if (pil2 == '2')
			   {
				   system("cls");
				   cout << "Data Konsumen" << endl << endl;
				   cout << "-----------------------------------------------------------" << endl;
				   cout << setw(16) << "No KTP" << setw(18) << "Nama Konsumen" << setw(24) << "Alamat" << endl;
				   cout << "-----------------------------------------------------------" << endl;
				   PrintInfoKonsumen(Konsumen);
				   cout << "\n---------------------------------------------------------" << endl;
				   system("pause");
				   goto ulang3;
			   }
			   else if (pil2 == '3')
			   {
				   system("cls");
				   cout << "Edit Data Konsumen" << endl << endl;
				   cout << "Masukan Nama Konsumen yang ingin diedit : "; getline(cin, find);
				   addressKonsumen alamat;
				   alamat = EditKonsumen(Konsumen, find);
				   if (alamat != NULL)
				   {
					   cout << "\nmasukkan nilai baru: " << endl;
					   cout << "Masukan No KTP Konsumen  : "; getline(cin, InsertKonsumen.noKtp);
					   cout << "Masukan Nama Konsumen    : "; getline(cin, InsertKonsumen.nama);
					   cout << "Masukan Alamat Konsumen  : "; getline(cin, InsertKonsumen.alamat);
					   alamat->InfoKonsumen = InsertKonsumen;
				   }
				   else
					   cout << "\nnilai " << find << " tidak ditemukan di dalam List";
				   system("pause");
				   goto ulang3;
			   }
			   else if (pil2 == '4')
			   {
				   system("cls");
				   cout << "Hapus Data Konsumen\n";
				   cout << "Masukan Nama Driver yang ingin dihapus : "; getline(cin, find);
				   DelKonsumen(Konsumen, find);
				   system("pause");
				   goto ulang3;
			   }

			   else if (pil2 == '0')
			   {
				   goto mainmenu;
			   }
			_getch();
			break;

		case '4':
		ulang4 :
			system("cls");
			   cout << "Master Data Transaksi Peminjaman\n";
			   cout << "1. Transaksi Peminjaman\n";
			   cout << "2. Lihat Data Transaksi Peminjaman\n";
			   cout << "3. Edit Data Transaksi Peminjaman\n";
			   cout << "4. Hapus Data Transaksi Peminjaman\n";
			   cout << "0. Kembali\n";
			   cout << "Masukan Pilihan Anda : ";
			   pil2 = _getch();
			   if (pil2 == '1')
			   {
				   system("cls");
				   cout << "Transaksi Peminjaman" << endl << endl;
			   reinputname:
				   getline(cin, BUG);
				   cout << "Masukan Nama Peminjam        : "; getline(cin, nama);
				   if (IsFoundKonsumen(Konsumen, nama))
				   {
					   addressKonsumen adrToEdit = NULL;
					   if (IsEmptyKonsumen(Konsumen))
					   {
						   adrToEdit;
					   }
					   else
					   {
						   addressKonsumen temp = Konsumen;
						   while (temp != NULL)
						   {
							   if (temp->InfoKonsumen.nama == nama)
							   {
								   adrToEdit = temp;
								   InsertTransaksi.namaKonsumen = temp->InfoKonsumen.nama;
								   InsertTransaksi.alamat = temp->InfoKonsumen.alamat;
								   break;
							   }
							   else
								   temp = temp->NextKonsumen;
						   }
						   adrToEdit;
					   }
				   }
				   else
				   {
					   cout << "Nama Konsumen Belum Terdaftar\n\n";
					   cout << "Ulangi [Y/T] : "; cin >> ulangi;
					   if (ulangi == 'Y' || ulangi == 'y') goto reinputname;
					   else goto mainmenu;
				   }


			   reinputnoTNKB:
				   getline(cin, BUG);
				   cout << "Masukan NO TNKB Mobil        : "; getline(cin, noTNKB);
				   if (IsFoundMobil(Mobil, noTNKB))
				   {
					   addressMobil adrToEdit = NULL;
					   if (IsEmptyMobil(Mobil))
					   {
						   adrToEdit;
					   }
					   else
					   {
						   addressMobil temp = Mobil;
						   while (temp != NULL)
						   {
							   if (temp->InfoMobil.noTNKB == noTNKB && temp->InfoMobil.IDcarStatus == 0)
							   {
								   adrToEdit = temp;
								   InsertTransaksi.noTNKB = temp->InfoMobil.noTNKB;
								   InsertTransaksi.hargaMobil = temp->InfoMobil.tarifSewa;
								   break;
							   }
							   else if (temp->InfoMobil.noTNKB == noTNKB && temp->InfoMobil.IDcarStatus == 1)
							   {
								   cout << "Mobil dengan nomor TNKB " << temp->InfoMobil.noTNKB << " sedang tidak tersedia\n\n";
								   cout << "Ulangi [Y/T] : "; cin >> ulangi;
								   if (ulangi == 'Y' || ulangi == 'y') goto reinputnoTNKB;
								   else goto mainmenu;
							   }
							   else
								   temp = temp->NextMobil;
						   }
						   adrToEdit;
					   }
				   }
				   else
				   {
					   cout << "Nomor TNKB mobil tidak tersedia\n";
					   cout << "Ulangi [Y/T] : "; cin >> ulangi;
					   if (ulangi == 'Y' || ulangi == 'y') goto reinputnoTNKB;
					   else goto mainmenu;
				   }
				   cout << "Dengan Driver [Y/T] : "; cin >> ulangi;
				   if (ulangi == 'Y' || ulangi == 'y') goto reinputDriver;
				   else
				   {
					   InsertTransaksi.namaDriver = "-";
					   InsertTransaksi.IDdriver = 0;
					   goto lanjut;
				   }
			   reinputDriver:
				   getline(cin, BUG);
				   cout << "Masukan Nama Driver          : "; getline(cin, namaDriver);
				   if (IsFoundDriver(Driver, namaDriver))
				   {
					   addressDriver adrToEdit = NULL;
					   if (IsEmptyDriver(Driver))
					   {
						   adrToEdit;
					   }
					   else
					   {
						   addressDriver temp = Driver;
						   while (temp != NULL)
						   {
							   if (temp->InfoDriver.namaDriver == namaDriver && temp->InfoDriver.IDstatusDriver == 0)
							   {
								   adrToEdit = temp;
								   InsertTransaksi.namaDriver = temp->InfoDriver.namaDriver;
								   InsertTransaksi.IDdriver = 1;
								   break;
							   }
							   else if (temp->InfoDriver.namaDriver == namaDriver && temp->InfoDriver.IDstatusDriver == 1)
							   {
								   cout << "Driver dengan nama " << temp->InfoDriver.namaDriver << " sedang tidak tersedia\n\n";
								   cout << "Ulangi [Y/T] : "; cin >> ulangi;
								   if (ulangi == 'Y' || ulangi == 'y') goto reinputDriver;
								   else goto mainmenu;
							   }
							   else
								   temp = temp->NextDriver;
						   }
						   adrToEdit;
					   }
				   }
				   else
				   {
					   cout << "Nama Driver tidak tersedia\n";
					   cout << "Ulangi [Y/T] : "; cin >> ulangi;
					   if (ulangi == 'Y' || ulangi == 'y') goto reinputDriver;
					   else goto mainmenu;
				   }
				   lanjut:
				   cout << "Masukan Tanggal Penyewaan    : "; cin >> InsertTransaksi.ATanggalPinjam; getline(cin, InsertTransaksi.HTanggalPinjam);
				   cout << "Masukan Tanggal Pengembalian : "; cin >> InsertTransaksi.AtanggalKembali; getline(cin, InsertTransaksi.HTanggalKembali);
				   if (InsertTransaksi.ATanggalPinjam == InsertTransaksi.AtanggalKembali)
				   {
					   cout << "Minimal Lama Peminjaman Adalah 1 Hari\n";
					   cout << "Ulangi [Y/T] : "; cin >> ulangi;
					   if (ulangi == 'Y' || ulangi == 'y') goto lanjut;
					   else goto mainmenu;
				   }
				   addressTransaksi transaksiBaru = AlokasiTPeminjaman(InsertTransaksi);
				   InsertLastTPeminjaman(Transaksi, transaksiBaru);

				   addressMobil alamat;
				   alamat = EditMobil(Mobil, noTNKB);
				   if (alamat != NULL)
				   {
					   InsertMobil.IDcarStatus=1;
					   InsertMobil.carStatus = "Disewakan";
					   alamat->InfoMobil.IDcarStatus = InsertMobil.IDcarStatus;
					   alamat->InfoMobil.carStatus = InsertMobil.carStatus;

				   }
				   addressDriver alamat2;
				   alamat2 = EditDriver(Driver, namaDriver);
				   if (alamat2 != NULL)
				   {
					   InsertDriver.IDstatusDriver=1;
					   InsertDriver.statusDriver = "Bertugas";
					   alamat2->InfoDriver.IDstatusDriver = InsertDriver.IDstatusDriver;
					   alamat2->InfoDriver.statusDriver = InsertDriver.statusDriver;
				   }
				   system("pause");
				   goto ulang4;
			   }
			   else if (pil2 == '2')
			   {
				   system("cls");
				   cout << "Data Transaksi Peminjaman" << endl << endl;
				   cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
				   cout << setw(12) << "Nama Konsumen" << setw(24) << "Alamat Konsumen" << setw(18) << "NO TNKB Mobil" << setw(16) << "Nama Driver" << setw(21) << "Tanggal Penyewaan" << setw(26) << "Tanggal Pengembalian" << endl;
				   cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
				   PrintInfoTPeminjaman(Transaksi);
				   cout << "\n-----------------------------------------------------------------------------------------------------------------------" << endl;
				   system("pause");
				   goto ulang4;
			   }
			   else if (pil2 == '3')
			   {
				   system("cls");
				   cout << "Edit Data Transaksi Peminjaman" << endl << endl;
				   cout << "Masukan Nama Penyewa yang ingin diedit : "; getline(cin, find);
				   addressTransaksi alamat;
				   alamat = EditTPeminjaman(Transaksi, find);
				   if (alamat != NULL)
				   {
					   cout << "\nmasukkan nilai baru: " << endl;
					   cout << "Masukan Nama Peminjam        : "; getline(cin, InsertTransaksi.namaKonsumen);
					   cout << "Masukan Alamat Peminjam      : "; getline(cin, InsertTransaksi.alamat);
					   cout << "Masukan NO TNKB Mobil        : "; getline(cin, InsertTransaksi.noTNKB);
					   cout << "Masukan Nama Driver          : "; getline(cin, InsertTransaksi.namaDriver);
					   cout << "Masukan Tanggal Penyewaan    : "; cin >> InsertTransaksi.ATanggalPinjam; getline(cin, InsertTransaksi.HTanggalPinjam);
					   cout << "Masukan Tanggal Pengembalian : "; cin >> InsertTransaksi.AtanggalKembali; getline(cin, InsertTransaksi.HTanggalKembali);
					   alamat->InfoTransaksi = InsertTransaksi;
				   }
				   else
					   cout << "\nnilai " << find << " tidak ditemukan di dalam List";
				   system("pause");
				   goto ulang4;
			   }
			   else if (pil2 == '4')
			   {
				   system("cls");
				   cout << "Hapus Data Transaksi Penyewaan\n";
				   cout << "Masukan Nama Penyewa yang ingin dihapus : "; getline(cin, find);
				   DelTPeminjaman(Transaksi, find);
				   system("pause");
				   goto ulang4;
			   }

			   else if (pil2 == '0')
			   {
				   goto mainmenu;
			   }
			_getch();
			break;

		case '5':
		ulang5 :
			system("cls");
			   cout << "Master Data Transaksi Pengembalian\n";
			   cout << "1. Transaksi Pengembalian\n";
			   cout << "2. Lihat Data Transaksi Pengembalian\n";
			   cout << "3. Edit Data Transaksi Pengembalian\n";
			   cout << "4. Hapus Data Transaksi Pengembalian\n";
			   cout << "0. Kembali\n";
			   cout << "Masukan Pilihan Anda : ";
			   pil2 = _getch();
			   if (pil2 == '1')
			   {
				   addressTransaksi temp = Transaksi;
				   system("cls");
				   cout << "Transaksi Pengembalian" << endl << endl;
			   reinputnames:
				   getline(cin, BUG);
				   cout << "Masukan Nama Peminjam        : "; getline(cin, nama);
				   if (IsFoundTPeminjaman(Transaksi, nama))
				   {
					   addressTransaksi adrToEdit = NULL;
					   if (IsEmptyTPeminjaman(Transaksi))
					   {
						   adrToEdit;
					   }
					   else
					   {
						   while (temp != NULL)
						   {
							   if (temp->InfoTransaksi.namaKonsumen == nama)
							   {
								   adrToEdit = temp;
								   InsertPengembali.nama = temp->InfoTransaksi.namaKonsumen;
								   InsertPengembali.alamat = temp->InfoTransaksi.alamat;
								   InsertPengembali.noTNKB = temp->InfoTransaksi.noTNKB;
								   InsertPengembali.namaDriver = temp->InfoTransaksi.namaDriver;
								   InsertPengembali.tarifMobil = temp->InfoTransaksi.hargaMobil;
								   InsertPengembali.ATanggalPinjam = temp->InfoTransaksi.ATanggalPinjam;
								   InsertPengembali.HTanggalPinjam = temp->InfoTransaksi.HTanggalPinjam;
								   if (temp->InfoTransaksi.AtanggalKembali > temp->InfoTransaksi.ATanggalPinjam)
								   {
									   InsertPengembali.lamaHari = temp->InfoTransaksi.AtanggalKembali - temp->InfoTransaksi.ATanggalPinjam;
								   }
								   else if (temp->InfoTransaksi.AtanggalKembali == temp->InfoTransaksi.ATanggalPinjam)
								   {
									   InsertPengembali.lamaHari = 1;
								   }
								   break;
							   }
							   else
								   temp = temp->NextTransakksi;
						   }
						   adrToEdit;
					   }
				   }
				   else
				   {
					   cout << "Nama Peminjam Belum Terdaftar\n\n";
					   cout << "Ulangi [Y/T] : "; cin >> ulangi;
					   if (ulangi == 'Y' || ulangi == 'y') goto reinputnames;
					   else goto mainmenu;
				   }
				   cout << "Masukan Tanggal Sekarang     : "; cin >> InsertPengembali.ATanggalSekarang; getline(cin, InsertPengembali.HTanggalSekarang);
				   if ((InsertPengembali.ATanggalSekarang-temp->InfoTransaksi.ATanggalPinjam) > InsertPengembali.lamaHari)
				   {
					   InsertPengembali.denda = 200000;
				   }
				   else if ((InsertPengembali.ATanggalSekarang-temp->InfoTransaksi.ATanggalPinjam) ==InsertPengembali.lamaHari)
				   {
					   InsertPengembali.denda = 0;
				   }
				   if (temp->InfoTransaksi.IDdriver == 1)
				   {
					   InsertPengembali.tarifDriver = 200000;
				   }
				   else
				   {
					   InsertPengembali.tarifDriver = 0;
				   }
				   InsertPengembali.total = (InsertPengembali.tarifMobil*InsertPengembali.lamaHari) + InsertPengembali.denda + InsertPengembali.tarifDriver;
				   cout << endl << endl;
				   cout << "Tarif Mobil                  : " << InsertPengembali.tarifMobil << endl;
				   cout << "Denda                        : " << InsertPengembali.denda << endl;
				   cout << "Jumlah Hari                  : " << InsertPengembali.lamaHari << endl;
				   cout << "Tarif Driver                 : " << InsertPengembali.tarifDriver << endl;
				   cout << "Total                        : " << InsertPengembali.total << endl;
				   cout << "Jumlah Bayar                 : "; cin >> InsertPengembali.payment;
				   InsertPengembali.change = InsertPengembali.payment - InsertPengembali.total;
				   cout << "Kembalian                    : " << InsertPengembali.change;
				   addressPengembalian pengembaliBaru = AlokasiPengembalian(InsertPengembali);
				   InsertLastPengembalian(Pengembali, pengembaliBaru);
				   addressMobil alamat;
				   alamat = EditMobil(Mobil, noTNKB);
				   if (alamat != NULL)
				   {
					   InsertMobil.IDcarStatus = 0;
					   InsertMobil.carStatus = "Tersedia";
					   alamat->InfoMobil = InsertMobil;
				   }
				   addressDriver alamat2;
				   alamat2 = EditDriver(Driver, namaDriver);
				   if (alamat2 != NULL)
				   {
					   InsertDriver.IDstatusDriver = 0;
					   InsertDriver.statusDriver = "Tersedia";
					   alamat2->InfoDriver = InsertDriver;
				   }
				   DelTPeminjaman(Transaksi, nama);
				   system("pause");
				   goto ulang5;
			   }
			   
			   else if (pil2 == '2')
			   {
				   system("cls");
				   cout << "Data Transaksi Pengembalian" << endl << endl;
				   cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
				   cout << setw(13) << "Nama Pengembali" << setw(24) << "Alamat" << setw(18) << "No TNKB" << setw(16) << "Nama Driver" << setw(13) << "Tanggal Penyewaan" << setw(18) << "Tanggal Sekarang" << setw(15) << "Denda" << setw(15) << "Total" << endl;
				   cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
				   PrintInfoPengembalian(Pengembali);
				   cout << "\n-----------------------------------------------------------------------------------------------------------------------" << endl;
				   system("pause");
				   goto ulang5;
			   }
			   else if (pil2 == '3')
			   {
				   system("cls");
				   cout << "Edit Data Transaksi Pengembalian" << endl << endl;
				   cout << "Masukan Nama Pengembali yang ingin diedit : "; getline(cin, find);
				   addressPengembalian alamat;
				   alamat = EditPengembalian(Pengembali, find);
				   if (alamat != NULL)
				   {
					   cout << "\nmasukkan nilai baru: " << endl;
					   cout << "Masukan Nama Pengembali      : "; getline(cin, InsertPengembali.nama);
					   cout << "Masukan Alamat Pengembali    : "; getline(cin, InsertPengembali.alamat);
					   cout << "Masukan NO TNKB Mobil        : "; getline(cin, InsertPengembali.noTNKB);
					   cout << "Masukan Nama Driver          : "; getline(cin, InsertPengembali.namaDriver);
					   cout << "Masukan Tanggal Penyewaan    : "; cin >> InsertPengembali.ATanggalPinjam; getline(cin, InsertPengembali.HTanggalPinjam);
					   cout << "Masukan Tanggal Sekarang     : "; cin >> InsertPengembali.ATanggalSekarang; getline(cin, InsertPengembali.HTanggalSekarang);
					   cout << "Masukan Denda                : "; cin >> InsertPengembali.denda;
					   cout << "Masukan Total                : "; cin >> InsertPengembali.total;
					   alamat->InfoPengembalian = InsertPengembali;
				   }
				   else
					   cout << "\nnilai " << find << " tidak ditemukan di dalam List";
				   system("pause");
				   goto ulang5;
			   }
			   else if (pil2 == '4')
			   {
				   system("cls");
				   cout << "Hapus Data Transaksi Pengembalian\n";
				   cout << "Masukan Nama Pengembali yang ingin dihapus : "; getline(cin, find);
				   DelPengembalian(Pengembali, find);
				   system("pause");
				   goto ulang5;
			   }
			   else if (pil2 == '0')
			   {
				   goto mainmenu;
			   }
			   
			_getch();
			break;
		}
	} while (pil != '0');
	return 0;	
}

//-------------------------I M P L E M E N T A S I---------------------------
void CreateEmptyMobil(ListMobil &Mobil)
{
	Mobil = NULL;
}
void CreateEmptyDriver(ListDriver &Driver)
{
	Driver = NULL;
}
void CreateEmptyKonsumen(ListKonsumen &Konsumen)
{
	Konsumen = NULL;
}
void CreateEmptyTPeminjaman(ListTransaksi &Transaksi)
{
	Transaksi = NULL;
}
void CreateEmptyPengembalian(ListPengembali &Pengembali)
{
	Pengembali = NULL;
}
bool IsEmptyMobil(ListMobil Mobil)
{
	return(Mobil == NULL);
}
bool IsEmptyDriver(ListDriver Driver)
{
	return(Driver == NULL);
}
bool IsEmptyKonsumen(ListKonsumen Konsumen)
{
	return(Konsumen == NULL);
}
bool IsEmptyTPeminjaman(ListTransaksi Transaksi)
{
	return(Transaksi == NULL);
}
bool IsEmptyPengembalian(ListPengembali Pengembali)
{
	return(Pengembali == NULL);
}
bool IsOneElementMobil(ListMobil Mobil)
{
	return(IsEmptyMobil(Mobil->NextMobil));
}
bool IsOneElementDriver(ListDriver Driver)
{
	return(IsEmptyDriver(Driver->NextDriver));
}
bool IsOneElementKonsumen(ListKonsumen Konsumen)
{
	return(IsEmptyKonsumen(Konsumen->NextKonsumen));
}
bool IsOneElementTPeminjaman(ListTransaksi Transaksi)
{
	return(IsEmptyTPeminjaman(Transaksi->NextTransakksi));
}
bool IsOneElementPengembalian(ListPengembali Pengembali)
{
	return(IsEmptyPengembalian(Pengembali->NextPengembalian));
}
addressMobil AlokasiMobil(dataMobil Mobil)
{
	addressMobil Car = new(NodeMobil);
	if (Car == NULL)
		return NULL;
	else
	{
		Car->InfoMobil = Mobil;
		Car->NextMobil = NULL;
		return Car;
	}
}
addressDriver AlokasiDriver(dataDriver Driver)
{
	addressDriver Pengemudi = new(NodeDriver);
	if (Pengemudi == NULL)
		return NULL;
	else
	{
		Pengemudi->InfoDriver = Driver;
		Pengemudi->NextDriver = NULL;
		return Pengemudi;
	}
}
addressKonsumen AlokasiKonsumen(dataKonsumen Konsumen)
{
	addressKonsumen Renter = new(NodeKonsumen);
	if (Renter == NULL)
		return NULL;
	else
	{
		Renter->InfoKonsumen = Konsumen;
		Renter->NextKonsumen = NULL;
		return Renter;
	}
}
addressTransaksi AlokasiTPeminjaman(dataTransaksi Transaksi)
{
	addressTransaksi Trans = new(NodeTransaksi);
	if (Trans == NULL)
		return NULL;
	else
	{
		Trans->InfoTransaksi = Transaksi;
		Trans->NextTransakksi = NULL;
		return Trans;
	}
}
addressPengembalian AlokasiPengembalian(dataPengembalian Pengembali)
{
	addressPengembalian Return = new(NodePengembalian);
	if (Return == NULL)
		return NULL;
	else
	{
		Return->InfoPengembalian = Pengembali;
		Return->NextPengembalian = NULL;
		return Return;
	}
}
void InsertFirstMobil(ListMobil &Mobil, addressMobil Car)
{
	Car->NextMobil = Mobil;
	Mobil = Car;
}
void InsertFirstDriver(ListDriver &Driver, addressDriver Pengemudi)
{
	Pengemudi->NextDriver = Driver;
	Driver = Pengemudi;
}
void InsertFirstKonsumen(ListKonsumen &Konsumen, addressKonsumen Renter)
{
	Renter->NextKonsumen = Konsumen;
	Konsumen = Renter;
}
void InsertFirstTPeminjaman(ListTransaksi &Transaksi, addressTransaksi Trans)
{
	Trans->NextTransakksi = Transaksi;
	Transaksi = Trans;
}
void InsertFirstPengembalian(ListPengembali &Pengembali, addressPengembalian Return)
{
	Return->NextPengembalian = Pengembali;
	Pengembali = Return;
}
void InsertAfterMobil(ListMobil &Mobil, addressMobil Prec, addressMobil Car)
{
	Car->NextMobil = Prec->NextMobil;
	Prec->NextMobil = Car;
}
void InsertAfterDriver(ListDriver &Driver, addressDriver Prec, addressDriver Pengemudi)
{
	Pengemudi->NextDriver = Prec->NextDriver;
	Prec->NextDriver = Pengemudi;
}
void InsertAfterKonsumen(ListKonsumen &Konsumen, addressKonsumen Prec, addressKonsumen Renter)
{
	Renter->NextKonsumen = Prec->NextKonsumen;
	Prec->NextKonsumen = Renter;
}
void InsertAfterTPeminjaman(ListTransaksi &Transaksi, addressTransaksi Prec, addressTransaksi Trans)
{
	Trans->NextTransakksi = Prec->NextTransakksi;
	Prec->NextTransakksi = Trans;
}
void InsertAfterPengembalian(ListPengembali &Pengembali, addressPengembalian Prec, addressPengembalian Return)
{
	Return->NextPengembalian = Prec->NextPengembalian;
	Prec->NextPengembalian = Return;
}
void InsertLastMobil(ListMobil &Mobil, addressMobil Car)
{
	if (IsEmptyMobil(Mobil))
		InsertFirstMobil(Mobil, Car);
	else if (IsOneElementMobil(Mobil))
		InsertAfterMobil(Mobil, Mobil, Car);
	else
		InsertLastMobil(Mobil->NextMobil, Car);
}
void InsertLastDriver(ListDriver &Driver, addressDriver Pengemudi)
{
	if (IsEmptyDriver(Driver))
		InsertFirstDriver(Driver, Pengemudi);
	else if (IsOneElementDriver(Driver))
		InsertAfterDriver(Driver, Driver, Pengemudi);
	else
		InsertLastDriver(Driver->NextDriver, Pengemudi);
}
void InsertLastKonsumen(ListKonsumen &Konsumen, addressKonsumen Renter)
{
	if (IsEmptyKonsumen(Konsumen))
		InsertFirstKonsumen(Konsumen, Renter);
	else if (IsOneElementKonsumen(Konsumen))
		InsertAfterKonsumen(Konsumen, Konsumen, Renter);
	else
		InsertLastKonsumen(Konsumen->NextKonsumen, Renter);
}
void InsertLastTPeminjaman(ListTransaksi &Transaksi, addressTransaksi Trans)
{
	if (IsEmptyTPeminjaman(Transaksi))
		InsertFirstTPeminjaman(Transaksi, Trans);
	else if (IsOneElementTPeminjaman(Transaksi))
		InsertAfterTPeminjaman(Transaksi, Transaksi, Trans);
	else
		InsertFirstTPeminjaman(Transaksi->NextTransakksi, Trans);
}
void InsertLastPengembalian(ListPengembali &Pengembali, addressPengembalian Return)
{
	if (IsEmptyPengembalian(Pengembali))
		InsertFirstPengembalian(Pengembali, Return);
	else if (IsOneElementPengembalian(Pengembali))
		InsertAfterPengembalian(Pengembali, Pengembali, Return);
	else
		InsertFirstPengembalian(Pengembali->NextPengembalian, Return);
}
void PrintInfoMobil(ListMobil Mobil)
{
	if (IsEmptyMobil(Mobil))
	{

	}
	else
	{
		cout << setw(2) << AutoNumber() << setw(15) << Mobil->InfoMobil.noTNKB << setw(10) << Mobil->InfoMobil.merek << setw(10) << Mobil->InfoMobil.warna << setw(10) << Mobil->InfoMobil.tahunPembuatan << setw(15) << Mobil->InfoMobil.tarifSewa << setw(14) << Mobil->InfoMobil.carStatus << endl;
		PrintInfoMobil(Mobil->NextMobil);
	}
}
void PrintInfoDriver(ListDriver Driver)
{
	if (IsEmptyDriver(Driver))
	{ }
	else
	{
		cout << setw(16) << Driver->InfoDriver.noKTP << setw(15) << Driver->InfoDriver.namaDriver <<setw(24) << Driver->InfoDriver.alamatDriver << setw(9) << Driver->InfoDriver.usiaDriver << setw(12) << Driver->InfoDriver.statusDriver << endl;
		PrintInfoDriver(Driver->NextDriver);
	}
}
void PrintInfoKonsumen(ListKonsumen Konsumen)
{
	if (IsEmptyKonsumen(Konsumen))
	{ }
	else
	{
		cout << setw(16) << Konsumen->InfoKonsumen.noKtp << setw(18) << Konsumen->InfoKonsumen.nama << setw(24) << Konsumen->InfoKonsumen.alamat << endl;
		PrintInfoKonsumen(Konsumen->NextKonsumen);
	}
}
void PrintInfoTPeminjaman(ListTransaksi Transaksi)
{
	if (IsEmptyTPeminjaman(Transaksi))
	{
	}
	else
	{
		cout << setw(13) << Transaksi->InfoTransaksi.namaKonsumen << setw(24) << Transaksi->InfoTransaksi.alamat << setw(18) << Transaksi->InfoTransaksi.noTNKB << setw(16) << Transaksi->InfoTransaksi.namaDriver << setw(13) << Transaksi->InfoTransaksi.ATanggalPinjam << Transaksi->InfoTransaksi.HTanggalPinjam << setw(18) << Transaksi->InfoTransaksi.AtanggalKembali << Transaksi->InfoTransaksi.HTanggalKembali << endl;
		PrintInfoTPeminjaman(Transaksi->NextTransakksi);
	}
}
void PrintInfoPengembalian(ListPengembali Pengembali)
{
	if (IsEmptyPengembalian(Pengembali))
	{
	}
	else
	{
		cout << setw(13) << Pengembali->InfoPengembalian.nama << setw(24) << Pengembali->InfoPengembalian.alamat << setw(18) << Pengembali->InfoPengembalian.noTNKB << setw(16) << Pengembali->InfoPengembalian.namaDriver << setw(13) << Pengembali->InfoPengembalian.ATanggalPinjam<<Pengembali->InfoPengembalian.HTanggalPinjam << setw(18) << Pengembali->InfoPengembalian.ATanggalSekarang << Pengembali->InfoPengembalian.HTanggalSekarang << setw(15) << Pengembali->InfoPengembalian.denda << setw(15) << Pengembali->InfoPengembalian.total << endl;
		PrintInfoPengembalian(Pengembali->NextPengembalian);
	}
}
bool IsFoundMobil(ListMobil &Mobil, string _nama)
{
	if (IsEmptyMobil(Mobil))
		return false;
	else
		return(Mobil->InfoMobil.noTNKB == _nama || IsFoundMobil(Mobil->NextMobil, _nama));
}
bool IsFoundDriver(ListDriver &Driver, string _nama)
{
	if (IsEmptyDriver(Driver))
		return false;
	else
		return(Driver->InfoDriver.namaDriver ==_nama || IsFoundDriver(Driver->NextDriver, _nama));
}
bool IsFoundKonsumen(ListKonsumen &Konsumen, string _nama)
{
	if (IsEmptyKonsumen(Konsumen))
		return false;
	else
		return(Konsumen->InfoKonsumen.nama == _nama || IsFoundKonsumen(Konsumen->NextKonsumen, _nama));
}
bool IsFoundTPeminjaman(ListTransaksi &Transaksi, string _nama)
{
	if (IsEmptyTPeminjaman(Transaksi))
		return false;
	else
		return(Transaksi->InfoTransaksi.namaKonsumen == _nama || IsFoundTPeminjaman(Transaksi->NextTransakksi, _nama));
}
bool IsFoundPengembalian(ListPengembali &Pengembali, string _nama)
{
	if (IsEmptyPengembalian(Pengembali))
		return false;
	else
		return(Pengembali->InfoPengembalian.nama == _nama || IsFoundPengembalian(Pengembali->NextPengembalian, _nama));
}
void DelMobilFirst(ListMobil &Mobil)
{
	addressMobil temp;
	temp = Mobil;
	Mobil = Mobil->NextMobil;
	delete(temp);
}
void DelDriverFirst(ListDriver &Driver)
{
	addressDriver temp;
	temp = Driver;
	Driver = Driver->NextDriver;
	delete(temp);
}
void DelKonsumenFirst(ListKonsumen &Konsumen)
{
	addressKonsumen temp;
	temp = Konsumen;
	Konsumen = Konsumen->NextKonsumen;
	delete(temp);
}
void DelTPeminjamanFirst(ListTransaksi &Transaksi)
{
	addressTransaksi temp;
	temp = Transaksi;
	Transaksi = Transaksi->NextTransakksi;
	delete(temp);
}
void DelPengembalianFirst(ListPengembali &Pengembali)
{
	addressPengembalian temp;
	temp = Pengembali;
	Pengembali = Pengembali->NextPengembalian;
	delete(temp);
}
void DelMobilLast(ListMobil &Mobil)
{
	addressMobil temp = Mobil;
	while (temp->NextMobil->NextMobil != NULL)
	{
		temp = temp->NextMobil;
	}
	addressMobil del = temp->NextMobil;
	temp->NextMobil = NULL;
	delete(del);
}
void DelDriverLast(ListDriver &Driver)
{
	addressDriver temp = Driver;
	while (temp->NextDriver->NextDriver != NULL)
	{
		temp = temp->NextDriver;
	}
	addressDriver del = temp->NextDriver;
	temp->NextDriver = NULL;
	delete(del);
}
void DelKonsumenLast(ListKonsumen &Konsumen)
{
	addressKonsumen temp = Konsumen;
	while (temp->NextKonsumen->NextKonsumen != NULL)
	{
		temp = temp->NextKonsumen;
	}
	addressKonsumen del = temp->NextKonsumen;
	temp->NextKonsumen = NULL;
	delete(del);
}
void DelTPeminjamanLast(ListTransaksi &Transaksi)
{
	addressTransaksi temp = Transaksi;
	while (temp->NextTransakksi->NextTransakksi != NULL)
	{
		temp = temp->NextTransakksi;
	}
	addressTransaksi del = temp->NextTransakksi;
	temp->NextTransakksi = NULL;
	delete(del);
}
void DelPengembalianLast(ListPengembali &Pengembali)
{
	addressPengembalian temp = Pengembali;
	while (temp->NextPengembalian->NextPengembalian != NULL)
	{
		temp = temp->NextPengembalian;
	}
	addressPengembalian del = temp->NextPengembalian;
	temp->NextPengembalian = NULL;
	delete(del);
}
void DelMobil(ListMobil &Mobil, string noTNKB)
{
	bool found = IsFoundMobil(Mobil, noTNKB);
	if (found)
	{
		addressMobil temp = Mobil;
		if (temp->InfoMobil.noTNKB == noTNKB)
		{
			DelMobilFirst(Mobil);
		}
		else
		{
			while (temp->NextMobil->InfoMobil.noTNKB != noTNKB)
			{
				temp = temp->NextMobil;
			}
			if (temp->NextMobil->NextMobil == NULL)
			{
				DelMobilLast(Mobil);
			}
			else
			{
				addressMobil del = temp->NextMobil;
				temp->NextMobil = del->NextMobil;
				delete(del);
			}
		}

		cout << "\nNilai " << noTNKB << " berhasil dihapus dari di dalam list...." << endl;
	}
	else
	{
		cout << "\nNilai " << noTNKB << " tidak ada di dalam list...." << endl;
	}

}
void DelDriver(ListDriver &Driver, string nama)
{
	bool found = IsFoundDriver(Driver, nama);
	if (found)
	{
		addressDriver temp = Driver;
		if (temp->InfoDriver.namaDriver == nama)
		{
			DelDriverFirst(Driver);
		}
		else
		{
			while (temp->NextDriver->InfoDriver.namaDriver != nama)
			{
				temp = temp->NextDriver;
			}
			if (temp->NextDriver->NextDriver == NULL)
			{
				DelDriverLast(Driver);
			}
			else
			{
				addressDriver del = temp->NextDriver;
				temp->NextDriver = del->NextDriver;
				delete(del);
			}
		}

		cout << "\nNilai " << nama << " berhasil dihapus dari di dalam list...." << endl;
	}
	else
	{
		cout << "\nNilai " << nama << " tidak ada di dalam list...." << endl;
	}
}
void DelKonsumen(ListKonsumen &Konsumen, string nama)
{
	bool found = IsFoundKonsumen(Konsumen, nama);
	if (found)
	{
		addressKonsumen temp = Konsumen;
		if (temp->InfoKonsumen.nama == nama)
		{
			DelKonsumenFirst(Konsumen);
		}
		else
		{
			while (temp->NextKonsumen->InfoKonsumen.nama != nama)
			{
				temp = temp->NextKonsumen;
			}
			if (temp->NextKonsumen->NextKonsumen == NULL)
			{
				DelKonsumenLast(Konsumen);
			}
			else
			{
				addressKonsumen del = temp->NextKonsumen;
				temp->NextKonsumen = del->NextKonsumen;
				delete(del);
			}
		}

		cout << "\nNilai " << nama << " berhasil dihapus dari di dalam list...." << endl;
	}
	else
	{
		cout << "\nNilai " << nama << " tidak ada di dalam list...." << endl;
	}
}
void DelTPeminjaman(ListTransaksi &Transaksi, string nama)
{
	bool found = IsFoundTPeminjaman(Transaksi, nama);
	if (found)
	{
		addressTransaksi temp = Transaksi;
		if (temp->InfoTransaksi.namaKonsumen == nama)
		{
			DelTPeminjamanFirst(Transaksi);
		}
		else
		{
			while (temp->NextTransakksi->InfoTransaksi.namaKonsumen != nama)
			{
				temp = temp->NextTransakksi;
			}
			if (temp->NextTransakksi->NextTransakksi == NULL)
			{
				DelTPeminjamanLast(Transaksi);
			}
			else
			{
				addressTransaksi del = temp->NextTransakksi;
				temp->NextTransakksi = del->NextTransakksi;
				delete(del);
			}
		}

		cout << "\nNilai " << nama << " berhasil dihapus dari di dalam list...." << endl;
	}
	else
	{
		cout << "\nNilai " << nama << " tidak ada di dalam list...." << endl;
	}
}
void DelPengembalian(ListPengembali &Pengembali, string nama)
{
	bool found = IsFoundPengembalian(Pengembali, nama);
	if (found)
	{
		addressPengembalian temp = Pengembali;
		if (temp->InfoPengembalian.nama == nama)
		{
			DelPengembalianFirst(Pengembali);
		}
		else
		{
			while (temp->NextPengembalian->InfoPengembalian.nama != nama)
			{
				temp = temp->NextPengembalian;
			}
			if (temp->NextPengembalian->NextPengembalian == NULL)
			{
				DelPengembalianLast(Pengembali);
			}
			else
			{
				addressPengembalian del = temp->NextPengembalian;
				temp->NextPengembalian = del->NextPengembalian;
				delete(del);
			}
		}

		cout << "\nNilai " << nama << " berhasil dihapus dari di dalam list...." << endl;
	}
	else
	{
		cout << "\nNilai " << nama << " tidak ada di dalam list...." << endl;
	}
}
addressMobil EditMobil(ListMobil Mobil, string cari)
{
	addressMobil adrToEdit = NULL;
	if (IsEmptyMobil(Mobil))
	{
		return adrToEdit;
	}
	else
	{
		addressMobil temp = Mobil;
		while (temp != NULL)
		{
			if (temp->InfoMobil.noTNKB == cari)
			{
				adrToEdit = temp;
				break;
			}
			else
				temp = temp->NextMobil;
		}
		return adrToEdit;
	}
}
addressDriver EditDriver(ListDriver Driver, string cari)
{
	addressDriver adrToEdit = NULL;
	if (IsEmptyDriver(Driver))
	{
		return adrToEdit;
	}
	else
	{
		addressDriver temp = Driver;
		while (temp != NULL)
		{
			if (temp->InfoDriver.namaDriver == cari)
			{
				adrToEdit = temp;
				break;
			}
			else
				temp = temp->NextDriver;
		}
		return adrToEdit;
	}
}
addressKonsumen EditKonsumen(ListKonsumen Konsumen, string cari)
{
	addressKonsumen adrToEdit = NULL;
	if (IsEmptyKonsumen(Konsumen))
	{
		return adrToEdit;
	}
	else
	{
		addressKonsumen temp = Konsumen;
		while (temp != NULL)
		{
			if (temp->InfoKonsumen.nama == cari)
			{
				adrToEdit = temp;
				break;
			}
			else
				temp = temp->NextKonsumen;
		}
		return adrToEdit;
	}
}
addressTransaksi EditTPeminjaman(ListTransaksi Transaksi, string cari)
{
	addressTransaksi adrToEdit = NULL;
	if (IsEmptyTPeminjaman(Transaksi))
	{
		return adrToEdit;
	}
	else
	{
		addressTransaksi temp = Transaksi;
		while (temp != NULL)
		{
			if (temp->InfoTransaksi.namaKonsumen == cari)
			{
				adrToEdit = temp;
				break;
			}
			else
				temp = temp->NextTransakksi;
		}
		return adrToEdit;
	}
}
addressPengembalian EditPengembalian(ListPengembali Pengembali, string cari)
{
	addressPengembalian adrToEdit = NULL;
	if (IsEmptyPengembalian(Pengembali))
	{
		return adrToEdit;
	}
	else
	{
		addressPengembalian temp = Pengembali;
		while (temp != NULL)
		{
			if (temp->InfoPengembalian.nama == cari)
			{
				adrToEdit = temp;
				break;
			}
			else
				temp = temp->NextPengembalian;
		}
		return adrToEdit;
	}
}
unsigned int AutoNumber()
{
	static unsigned int ID = 1;
	return ID++;
}
void menu()
{
	cout << "		Menu Simply Rent a Car  \n";
	cout<<"------------------------------------------------------------"<<endl;
	cout << "1. Mengelola data mobil\n";
	cout << "2. Mengelola data driver\n";
	cout << "3. Mengelola data konsumen yang akan menyewa mobil\n";
	cout << "4. Mengelola data transaksi peminjaman mobil harian\n";
	cout << "5. Mengelola data transaksi pengembalian & pembayaran mobil harian\n";
	cout << "0. Keluar\n";
}

//Simply Rent a Car