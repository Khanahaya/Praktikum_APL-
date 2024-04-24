#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
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

// Selection Sort untuk Sorting Huruf Ascending
void selectionSortHuruf() {
    for (int i = 0; i < daftar_produk.size() - 1; i++) {
        for (int j = i + 1; j < daftar_produk.size(); j++) {
            if (daftar_produk[i].nama > daftar_produk[j].nama) {
                swap(daftar_produk[i], daftar_produk[j]);
            }
        }
    }
    cout << "Sorting Huruf Ascending (Selection Sort) berhasil!" << endl;
}

// Bubble Sort untuk Sorting Huruf Ascending
void bubbleSortHuruf() {
    for (int i = 0; i < daftar_produk.size() - 1; i++) {
        for (int j = 0; j < daftar_produk.size() - i - 1; j++) {
            if (daftar_produk[j].nama > daftar_produk[j + 1].nama) {
                swap(daftar_produk[j], daftar_produk[j + 1]);
            }
        }
    }
    cout << "Sorting Huruf Ascending (Bubble Sort) berhasil!" << endl;
}

// Insertion Sort untuk Sorting Huruf Ascending
void insertionSortHuruf() {
    for (int i = 1; i < daftar_produk.size(); i++) {
        Produk key = daftar_produk[i];
        int j = i - 1;


        while (j >= 0 && daftar_produk[j].nama > key.nama) {
            daftar_produk[j + 1] = daftar_produk[j];
            j = j - 1;
        }
        daftar_produk[j + 1] = key;
    }
    cout << "Sorting Huruf Ascending (Insertion Sort) berhasil!" << endl;
}

// Quick Sort untuk Sorting Angka Descending
void quickSortHargaDescending(int low, int high) {
    int partitionHargaDescending(int low, int high);
    if (low < high) {
        int pi = partitionHargaDescending(low, high);

        quickSortHargaDescending(low, pi - 1);
        quickSortHargaDescending(pi + 1, high);
    }
}

int partitionHargaDescending(int low, int high) {
    int pivot = daftar_produk[high].harga;
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (daftar_produk[j].harga > pivot) {
            i++;
            swap(daftar_produk[i], daftar_produk[j]);
        }
    }
    swap(daftar_produk[i + 1], daftar_produk[high]);
    return (i + 1);
}

// Binary Search untuk Searching pada Kumpulan Data yang Terurut Ascending
int binarySearch(const string& nama_produk) {
    int low = 0, high = daftar_produk.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (daftar_produk[mid].nama == nama_produk)
            return mid;
        if (daftar_produk[mid].nama < nama_produk)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

// Linear Search untuk Searching pada Kumpulan Data yang Terurut Ascending
int linearSearch(const string& nama_produk) {
    for (int i = 0; i < daftar_produk.size(); i++) {
        if (daftar_produk[i].nama == nama_produk)
            return i;
    }
    return -1;
}

// Main program
int main() {
    if (!login()) {
        return 0; // Berhenti program jika login gagal
    }

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

    int pilihan;

    do {
        displayBarang();

        cout << "Silahkan pilih opsi : " << endl;
        cout << "1. Tambah Produk" << endl;
        cout << "2. Edit Produk" << endl;
        cout << "3. Hapus Produk" << endl;
        cout << "4. Pesan Produk" << endl;
        cout << "5. Cetak Struk" << endl;
        cout << "6. Selesai" << endl;
        cout << "7. Sorting Huruf Ascending (Selection Sort)" << endl;
        cout << "8. Sorting Huruf Ascending (Bubble Sort)" << endl;
        cout << "9. Sorting Huruf Ascending (Insertion Sort)" << endl;
        cout << "10. Sorting Angka Descending (Quick Sort)" << endl;
        cout << "11. Searching pada Kumpulan Data yang Terurut Ascending (Binary Search)" << endl;
        cout << "12. Searching pada Kumpulan Data yang Terurut Ascending (Linear Search)" << endl;
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
            case 7:
                selectionSortHuruf();
                break;
            case 8:
                bubbleSortHuruf();
                break;
            case 9:
                insertionSortHuruf();
                break;
            case 10:
                quickSortHargaDescending(0, daftar_produk.size() - 1);
                cout << "Sorting Angka Descending (Quick Sort) berhasil!" << endl;
                break;
            case 11:
                {
                    string nama_cari;
                    cout << "Masukkan nama produk yang ingin dicari: ";
                    cin >> nama_cari;
                    int index = binarySearch(nama_cari);
                    if (index != -1) {
                        cout << "Produk ditemukan pada indeks " << index + 1 << endl;
                    } else {
                        cout << "Produk tidak ditemukan." << endl;
                    }
                }
                break;
            case 12:
                {
                    string nama_cari;
                    cout << "Masukkan nama produk yang ingin dicari: ";
                    cin >> nama_cari;
                    int index = linearSearch(nama_cari);
                    if (index != -1) {
                        cout << "Produk ditemukan pada indeks " << index + 1 << endl;
                    } else {
                        cout << "Produk tidak ditemukan." << endl;
                    }
                }
                break;
            default:
                cout << "Opsi tidak valid" << endl;
                break;
        }

    } while (pilihan != 6);

    return 0;
}
