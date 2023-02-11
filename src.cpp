#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct menu_item {
  int ID;
  string nama;
  string kategori;
  int harga;
};

vector<menu_item> menu = {
  {1, "Keripik Pedas", "Camilan", 2000},
  {2, "Pilus Keju", "Camilan", 5000},
  {3, "Malkist Abon", "Camilan", 6000},
  {4, "Wafer Stroberi", "Camilan", 10000},
  {5, "Kol 100 gram", "Bahan", 3000},
  {6, "Bakso Udang", "Bahan", 5000},
  {7, "Ayam 1 ekor", "Bahan", 30000},
  {8, "Nasi Padang", "Makanan", 12000},
  {9, "Mie Kocok", "Makanan", 15000},
  {10, "Es Teh Manis", "Minuman", 3000},
  {11, "Lemon Tea", "Minuman", 4000}
};

struct transaksi {
  string nama_pelanggan;
  string nama_menu;
  int jumlah;
  int total_harga;
};

vector<transaksi> riwayat_penjualan;

int main() {
  string pilihan_pemilik;
  cout << "Pemilik Toko: (Ketik 1 untuk buka dan 2 untuk tutup) ";
  cin >> pilihan_pemilik;
  
  if (pilihan_pemilik == "2") {
    cout << "Tidak Ada Penjualan" << endl;
  } else {
      while (pilihan_pemilik != "2") {
        if (pilihan_pemilik == "1") {
          string nama_pelanggan;
          cout << "Masukkan nama pelanggan: ";
          cin >> nama_pelanggan;
    
          string pilihan_pelanggan;
          cout << "Pelanggan: (lihat menu(ketik 1) / beli(ketik 2) / keluar(ketik 3)) ";
          cin >> pilihan_pelanggan;
    
          while (pilihan_pelanggan != "3") {
            if (pilihan_pelanggan == "1") {
              cout << "ID\tNama\tKategori\tHarga" << endl;
              for (menu_item item : menu) {
                cout << item.ID << "\t" << item.nama << "\t" << item.kategori << "\t" << item.harga << endl;
              }
            } else if (pilihan_pelanggan == "2") {
              string nama_menu_atau_ID;
              cout << "Masukkan nama atau ID menu: ";
              cin >> nama_menu_atau_ID;
    
              map<string, int> nama_ke_ID;
              for (menu_item item : menu) {
                nama_ke_ID[item.nama] = item.ID;
              }
    
              int ID;
              if (nama_ke_ID.count(nama_menu_atau_ID) > 0) {
                ID = nama_ke_ID[nama_menu_atau_ID];
              } else {
                ID = stoi(nama_menu_atau_ID);
              }
    
              int jumlah;
              cout << "Masukkan jumlah: ";
              cin >> jumlah;
    
              menu_item item_dipilih;
              for (menu_item item : menu)
      {
        if (item.ID == ID) {
          item_dipilih = item;
        break;
      }
    }
          int total_harga = 0 + jumlah * item_dipilih.harga;
    
          transaksi t = {nama_pelanggan, item_dipilih.nama, jumlah, total_harga};
          riwayat_penjualan.push_back(t);
    
          cout << "Total harga: " << total_harga << endl;
        }
    
        cout << "Pelanggan: (lihat menu(ketik 1) / beli(ketik 2) / keluar(ketik 3)) ";
        cin >> pilihan_pelanggan;
      }
    }
    
    cout << "Pemilik Toko: (Ketik 1 untuk buka dan 2 untuk tutup) ";
    cin >> pilihan_pemilik;
    }
    cout << "Riwayat Penjualan:" << endl;
    cout << "Nama Pelanggan\tNama Menu\t\tJumlah\t\tTotal Harga" << endl;
    for (transaksi t : riwayat_penjualan) {
    cout << t.nama_pelanggan << "\t\t" << t.nama_menu << "\t\t" << t.jumlah << "\t\t" << t.total_harga << endl;
    }
  }
return 0;
}
