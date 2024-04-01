#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Struktur data untuk produk
struct Produk {
    string nama;
    int harga;
    int stok;
};

// Menyimpan daftar produk
vector<Produk> daftar_produk;

// Fungsi login
bool login() {
    string nama;
    int nim;
    int attempts = 0;
    const int max_attempts = 3;
    const string correct_nama = "fadil";
    const int correct_nim = 111;

    do {
        cout << "                      KASIR INDOMARET                  " << endl;
        cout << "==========================================================" << endl;
        cout << "Silahkan Login sebagai Kasir Indomaret " << endl;
        cout << "Nama: ";
        cin >> nama;
        cout << "NIM: ";
        cin >> nim;

        if (nama == correct_nama && nim == correct_nim) {
            cout << "Login berhasil!" << endl;
            return true;
        } else {
            cout << "Login gagal. Silakan coba lagi." << endl;
            attempts++;
        }
    } while (attempts < max_attempts);

    cout << "Anda telah mencoba login sebanyak 3 kali. Program akan berhenti." << endl;
    return false;
}

// Menampilkan daftar produk
void displayBarang() {
    cout << "==========================================================" << endl;
    cout << "                        DAFTAR PRODUK                      " << endl << endl;
    for (int i = 0; i < daftar_produk.size(); i++) {
        cout << i + 1 << ". " << daftar_produk[i].nama << " : Rp. " << daftar_produk[i].harga << " (Stok: " << daftar_produk[i].stok << ")" << endl;
    }
    cout << daftar_produk.size() + 1 << ". Selesai" << endl;
    cout << "==========================================================" << endl << endl;
}

// Menambah produk baru
void tambahProduk() {
    Produk produk;
    cout << "Masukkan nama produk : ";
    cin >> produk.nama;
    cout << "Masukkan harga produk : ";
    cin >> produk.harga;
    cout << "Masukkan stok produk : ";
    cin >> produk.stok;
    daftar_produk.push_back(produk);
    cout << "Produk berhasil ditambahkan!" << endl;
}


// Mengedit produk berdasarkan nomor pilihan
void editProduk(int nomor_pilihan) {
    if (nomor_pilihan < 1 || nomor_pilihan > daftar_produk.size()) {
        cout << "Nomor pilihan tidak valid!" << endl;
        return;
    }
    Produk* produk = &daftar_produk[nomor_pilihan - 1]; // Menggunakan pointer untuk mengakses produk yang akan diubah
    cout << "Masukkan nama produk baru : ";
    cin >> produk->nama;
    cout << "Masukkan harga produk baru : ";
    cin >> produk->harga;
    cout << "Masukkan stok produk baru : ";
    cin >> produk->stok;
    cout << "Produk berhasil diubah!" << endl;
}

// Menghapus produk berdasarkan nomor pilihan
void hapusProduk(int nomor_pilihan) {
    if (nomor_pilihan < 1 || nomor_pilihan > daftar_produk.size()) {
        cout << "Nomor pilihan tidak valid!" << endl;
        return;
    }
    Produk* produk = &daftar_produk[nomor_pilihan - 1]; // Menggunakan pointer untuk mengakses produk yang akan dihapus
    daftar_produk.erase(daftar_produk.begin() + nomor_pilihan - 1);
    cout << "Produk berhasil dihapus!" << endl;
}

// Fungsi rekursif untuk mencari produk berdasarkan nama
int cariProduk(const string& nama_produk, int index = 0) {
    if (index >= daftar_produk.size())
        return -1; // Produk tidak ditemukan
    if (daftar_produk[index].nama == nama_produk)
        return index; // Produk ditemukan
    return cariProduk(nama_produk, index + 1); // Pencarian rekursif
}

// Proses pemesanan produk
void pesanProduk() {
    string nama_produk;
    cout << "Masukkan nama produk yang ingin dipesan: ";
    cin >> nama_produk;
    int index = cariProduk(nama_produk);
    if (index != -1) {
        cout << "Produk ditemukan pada indeks " << index + 1 << endl;
        // Lakukan proses pemesanan di sini
    } else {
        cout << "Produk tidak ditemukan." << endl;
    }
}

// Proses cetak struk
void cetakStruk() {
    // Proses cetak struk
}

// Main program
int main() {
    if (!login()) {
        return 0; // Berhenti program jika login gagal
    }

    int pilihan;

    // Menambahkan produk default
    Produk p1 = {"Nescafe", 7000, 10};
    Produk p2 = {"Chiki", 5000, 20};
    Produk p3 = {"Taro", 7000, 15};
    Produk p4 = {"Ichi Ocha", 4000, 25};
    Produk p5 = {"Le Mineral", 4000, 30};
    daftar_produk.push_back(p1);
    daftar_produk.push_back(p2);
    daftar_produk.push_back(p3);
    daftar_produk.push_back(p4);
    daftar_produk.push_back(p5);

    do {
        displayBarang();

        cout << "Silahkan pilih opsi : " << endl;
        cout << "1. Tambah Produk" << endl;
        cout << "2. Edit Produk" << endl;
        cout << "3. Hapus Produk" << endl;
        cout << "4. Pesan Produk" << endl;
        cout << "5. Cetak Struk" << endl;
        cout << "6. Selesai" << endl;
        cout << "Pilih opsi : ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            tambahProduk();
            break;
        case 2:
            int nomor_edit;
            cout << "Masukkan nomor produk yang ingin diubah : ";
            cin >> nomor_edit;
            editProduk(nomor_edit);
            break;
        case 3:
            int nomor_hapus;
            cout << "Masukkan nomor produk yang ingin dihapus : ";
            cin >> nomor_hapus;
            hapusProduk(nomor_hapus);
            break;
        case 4:
            pesanProduk();
            break;
        case 5:
            cetakStruk();
            break;
        case 6:
            cout << "Terima Kasih! :)" << endl;
            break;
        default:
            cout << "Opsi tidak valid" << endl;
            break;
        }

    } while (pilihan != 6);

    return 0;
}

