#include <iostream>
using namespace std;

// tambahkan limit user 
const int limit_hewan = 100;

struct hewan
{
    string id;
    string jenis;
    string ras;
    string nama;
    string perawatan;
    int umur;
    int reservasi;

};

// buat nested struct pengguna 

hewan daftar_hewan[limit_hewan];
int jumlah_hewan = 0;

// buat jadi multiuser -> lila
// buat login admin dengan username "pawpatrol" dan password "bayardulu" 
// buat sapaan dengan default value pada saat user berhasil login 
// buat menu login beserta opsinya 

bool login_program(string Nama, string NIM)
{
    return (Nama == "bila" && NIM == "041");
}

void tambah_hewan_ptr(hewan *daftar, int *jumlah) //panggil fungsi ke dalam fungsi tambah data (belum diperbarui)
{
    if (*jumlah < limit_hewan)
    {
        cout << "Masukkan ID Hewan: ";
        cin >> (daftar[*jumlah]).id;
        cout << "Masukkan jenis hewan: ";
        cin >> (daftar[*jumlah]).jenis;
        cout << "Masukkan Nama Hewan: ";
        cin >> (daftar[*jumlah]).nama;
        cout << "Masukkan Umur Hewan: ";
        cin >> (daftar[*jumlah]).umur;

        (*jumlah)++;
        cout << "Data hewan telah berhasil ditambahkan.\n";
    }
    else
    {
        cout << "Maaf, tidak dapat menambahkan hewan lagi.\n";
    }
}

void tampilkan_hewan(const hewan daftar[], int jumlah) // tampilkan data baru (belum diperbarui) + masukkan sorting ke dalam sini
{
    if (jumlah == 0)
    {
        cout << "Tidak ada data hewan.\n";
    }
    else
    {
        cout << "\n========= DATA HEWAN =========\n";
        cout << "ID\tJenis\tNama\tUmur\n";
        cout << "------------------------------------\n";
        for (int i = 0; i < jumlah; i++)
        {
            cout << daftar[i].id << "\t"
                 << daftar[i].jenis << "\t"
                 << daftar[i].nama << "\t"
                 << daftar[i].umur << " tahun\n";
        }
        cout << "------------------------------------\n";
    }
}

void ubah_hewan_ptr(hewan *daftar, int jumlah) // (belum diperbarui)
{
    string id;
    cout << "Masukkan ID hewan yang ingin diubah: ";
    cin >> id;
    bool ditemukan = false;

    for (int i = 0; i < jumlah; i++)
    {
        if ((daftar + i)->id == id)
        {
            cout << "Masukkan jenis baru: ";
            cin >> (daftar + i)->jenis;
            cout << "Masukkan nama baru: ";
            cin >> (daftar + i)->nama;
            cout << "Masukkan umur baru hewan: ";
            cin >> (daftar + i)->umur;
            ditemukan = true;
            cout << "Data hewan berhasil diperbarui.\n";
            break;
        }
    }

    if (!ditemukan)
        cout << "Hewan tidak ditemukan!\n";
}

void hapus_hewan_ptr(hewan *daftar, int *jumlah) // (belum diperbarui)
{
    string id;
    cout << "Masukkan ID hewan yang ingin dihapus: ";
    cin >> id;
    bool ditemukan = false;

    for (int i = 0; i < *jumlah; i++)
    {
        if ((daftar + i)->id == id)
        {
            for (int j = i; j < *jumlah - 1; j++)
            {
                *(daftar + j) = *(daftar + j + 1);
            }
            (*jumlah)--;
            ditemukan = true;
            cout << "Data hewan berhasil dihapus.\n";
            break;
        }
    }

    if (!ditemukan)
        cout << "Hewan tidak ditemukan\n";
}

void sort_nama_ascending(hewan *daftar, int jumlah) // masukkan ke dalam tampilkanHewan() & tampilkanCustomer()
{
    for (int i = 0; i < jumlah - 1; i++)
    {
        for (int j = i + 1; j < jumlah; j++)
        {
            if ((daftar + i)->nama > (daftar + j)->nama)
            {
                swap(*(daftar + i), *(daftar + j));
            }
        }
    }
    cout << "Data berhasil diurutkan berdasarkan Nama (A-Z).\n";
}

void sort_umur_descending(hewan *daftar, int jumlah) // ubah sorting berdasarkan tanggal reservasi sortReservasiTerjauh
{
    for (int i = 0; i < jumlah - 1; i++)
    {
        for (int j = i + 1; j < jumlah; j++)
        {
            if ((daftar + i)->umur < (daftar + j)->umur)
            {
                swap(*(daftar + i), *(daftar + j));
            }
        }
    }
    cout << "Data berhasil diurutkan berdasarkan Umur ( dari yang terbesar ke yang terkecil).\n";
}

void sort_jenis_ascending(hewan *daftar, int jumlah) // ubah sorting beradasarkan tanggal reservasi terdekat
{
    for (int i = 0; i < jumlah - 1; i++)
    {
        for (int j = i + 1; j < jumlah; j++)
        {
            if ((daftar + i)->jenis > (daftar + j)->jenis)
            {
                swap(*(daftar + i), *(daftar + j));
            }
        }
    }
    cout << "Data berhasil diurutkan berdasarkan Jenis Hewan (A-Z).\n";

}

// buat fungsi tambah data 
// buat fungsi tambah data customer 
// buat fungsi tampilkan data 
// buat fungsi tampilkan data customer 
// buat fungsi hapus data 
// buat fungsi hapus data customer 
// buat fungsi ubah data 
// buat fungsi ubah data customer 
// buat fungsi sorting descending untuk laporan berdasarkan perawatan ->
// buat fungsi tampilkan laporan dengan searching filter data berapa banyak hewan dengan perawatan tersebut, berikan jumlahnya, dan tampilkan hanya data tersebut
// buat fungsi tampilkan laporan dengan searching filter data berapa banyak reservasi pada tanggal tersebut tersebut, berikan jumlahnya, dan tampilkan hanya data tersebut
// buat tampilan menu admin
// buat tampilan menu pengguna
// pastikan tiap tahap disertai error handling !!


int main()
{
    string Nama, NIM;
    bool login = false;
    int percobaan_login = 0;

    while (percobaan_login < 3 && !login)
    {
        cout << "Masukkan Nama : ";
        cin >> Nama;
        cout << "Masukkan NIM : ";
        cin >> NIM;

        if (login_program(Nama, NIM))
        {
            login = true;
            cout << "Login berhasil, Welcome " << Nama << "!\n";
        }
        else
        {
            percobaan_login++;
            cout << "Nama atau NIM salah, Silahkan coba lagi!\n";
        }
    }

    if (!login)
    {
        cout << "Terlalu banyak percobaan login, program dihentikan!\n";
        return 0;
    }

    while (true) // belum diperbarui
    {
        cout << "\n======================";
        cout << "\n|    MENU PET SHOP   |";
        cout << "\n=======================";
        cout << "\n| 1. TAMBAH HEWAN     |";
        cout << "\n| 2. TAMPILKAN HEWAN  |";
        cout << "\n| 3. UBAH HEWAN       |";
        cout << "\n| 4. HAPUS HEWAN      |";
        cout << "\n| 5. SORTING DATA     |";
        cout << "\n| 6. KELUAR PROGRAM   |";
        cout << "\n=======================";
        cout << "\nPilih (1/2/3/4/5/6): ";
        int pilihan;
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            tambah_hewan_ptr(daftar_hewan, &jumlah_hewan);
            break;
        case 2:
            tampilkan_hewan(daftar_hewan, jumlah_hewan);
            break;
        case 3:
            ubah_hewan_ptr(daftar_hewan, jumlah_hewan);
            break;
        case 4:
            hapus_hewan_ptr(daftar_hewan, &jumlah_hewan);
            break;
        case 5: // masukkan sorting ke tampilkan data 
            int pilihan_sort;
            cout << "\n== PILIHAN SORTING ==";
            cout << "\n1. Berdasarkan Nama (A-Z)";
            cout << "\n2. Berdasarkan Umur (Tua ke Muda)";
            cout << "\n3. Berdasarkan Jenis (A-Z)";
            cout << "\nPilih metode sorting (1/2/3): ";
            cin >> pilihan_sort;

            if (pilihan_sort == 1)
                sort_nama_ascending(daftar_hewan, jumlah_hewan);
            else if (pilihan_sort == 2)
                sort_umur_descending(daftar_hewan, jumlah_hewan);
            else if (pilihan_sort == 3)
                sort_jenis_ascending(daftar_hewan, jumlah_hewan);
            else
                cout << "Pilihan sorting tidak valid.\n";
            break;
        case 6:
            cout << "Terima kasih telah menggunakan program petshop ini.\n";
            return 0;
        default:
            cout << "Pilihan tidak valid.\n";
        }
    }

    return 0;
}
