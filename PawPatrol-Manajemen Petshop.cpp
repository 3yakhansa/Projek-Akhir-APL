#include <iostream>
#include <cmath>
#include <limits>
#include <iomanip>
using namespace std;

const int limit_user = 50;
const int limit_hewan = 50;

struct Profil
{
    string nama_lengkap;
    string alamat;
    int no_hp;
};

struct User
{
    string username;
    string password;
    Profil data_profil;
};

User daftar_user[limit_user];
int jumlah_user = 0;

struct hewan
{
    string jenis;
    string ras;
    string nama;
    string perawatan;
    string reservasi;
    int id;
    int umur;
};

hewan daftar_hewan[limit_hewan];
int jumlah_hewan = 0;

bool loginUser(string username, string password)
{
    for (int i = 0; i < jumlah_user; i++)
    {
        if (daftar_user[i].username == username && daftar_user[i].password == password)
        {
            return true;
        }
    }
    return false;
}

void welcomeMessage(string nama = "pengguna", string peran = "pengguna")
{
    if (peran == "admin")
    {
        cout << "Login berhasil sebagai ADMIN. Selamat datang, " << nama << "!\n";
    }
    else
    {
        cout << "Login berhasil sebagai pengguna, Selamat datang " << nama << "!\n";
    }
}

void registrasi()
{
    if (jumlah_user < limit_user)
    {
        string username_input;
        bool username_valid = false;

        while (!username_valid)
        {
            cout << "Masukkan Username: ";
            cin >> username_input;

            if (username_input == "")
            {
                cout << "Username tidak boleh kosong.\n";
            }
            else
            {
                bool sudah_ada = false;
                for (int i = 0; i < jumlah_user; i++)
                {
                    if (daftar_user[i].username == username_input)
                    {
                        sudah_ada = true;
                        break;
                    }
                }
                if (sudah_ada)
                {
                    cout << "Username sudah terdaftar. Silahkan pilih username yang lain.\n";
                }
                else
                {
                    username_valid = true;
                }
            }
        }

        daftar_user[jumlah_user].username = username_input;

        string pass_input;
        cout << "Masukkan Password: ";
        cin >> pass_input;
        while (pass_input == "")
        {
            cout << "password tidak boleh kosong.\n";
            cout << "Masukkan Password: ";
            cin >> pass_input;
        }
        daftar_user[jumlah_user].password = pass_input;

        cin.ignore();
        cout << "Masukkan Nama Lengkap: ";
        getline(cin, daftar_user[jumlah_user].data_profil.nama_lengkap);

        cout << "Masukkan Alamat: ";
        getline(cin, daftar_user[jumlah_user].data_profil.alamat);

        int Nomor_hp;
        bool nohp_valid = false;

        while (!nohp_valid)
        {
            cout << "Masukkan No HP : ";
            cin >> Nomor_hp;

            if (cin.fail())
            {
                cout << "Input tidak valid! No HP harus angka.\n";
                cin.clear();
                cin.ignore(1000, '\n');
            }
            else
            {
                daftar_user[jumlah_user].data_profil.no_hp = Nomor_hp;
                nohp_valid = true;
                cin.ignore();
            }
        }

        jumlah_user++;
        cout << "Registrasi berhasil!\n";
    }
    else
    {
        cout << "Kapasitas pengguna penuh.\n";
    }
}

void tambah_hewan_ptr(hewan *daftar, int *jumlah)
{
    if (*jumlah >= limit_hewan)
    {
        cout << "Maaf, kapasitas penuh.\n";
        return;
    }

int id_input;
bool id_unik;

do {
    id_unik = true;
    cout << "Masukkan ID Hewan (angka): ";
    cin >> id_input;

    if (cin.fail()) {
        cout << "Input tidak valid! ID harus berupa angka.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        id_unik = false;
        continue;
    }

    for (int i = 0; i < *jumlah; i++) {
        if (daftar[i].id == id_input) {
            cout << "ID sudah digunakan. Masukkan ID lain.\n";
            id_unik = false;
            break;
        }
    }
} while (!id_unik);

    daftar[*jumlah].id = id_input;
    cout << "Masukkan Nama Hewan: ";
    cin >> daftar[*jumlah].nama;
    cout << "Masukkan jenis hewan: ";
    cin >> daftar[*jumlah].jenis;
    cout << "Masukkan ras hewan: ";
    cin >> daftar[*jumlah].ras;
    cout << "Masukkan Umur Hewan: ";
    while (true) {
        cin >> daftar[*jumlah].umur;
        
        if (cin.fail()) { 
            cout << "Input tidak valid! Harap masukkan angka untuk umur.\n";
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  
            cout << "Masukkan Umur Hewan: ";
            continue; 
        }
        
        if (daftar[*jumlah].umur < 0) {  
            cout << "Umur tidak boleh negatif. Masukkan umur yang valid.\n";
            cout << "Masukkan Umur Hewan: ";
            continue; 
        }
        
        break;  
    }
        cout << "Masukkan Jenis Perawatan Hewan: ";
        cin >> daftar[*jumlah].perawatan;
        cout << "Masukkan Tanggal Reservasi: ";
        cin.ignore();
        getline(cin, daftar[*jumlah].reservasi);

        (*jumlah)++;
        cout << "Data hewan berhasil ditambahkan.\n";
    }

void selectionSort(hewan daftar[], int jumlah) {
    for (int i = 0; i < jumlah - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < jumlah; j++) {
            if (daftar[j].id < daftar[minIdx].id) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            swap(daftar[i], daftar[minIdx]);
        }
    }
}

int jumpSearch(hewan daftar[], int jumlah, int targetID) {
    int step = sqrt(jumlah);
    int prev = 0;

    while (daftar[min(step, jumlah) - 1].id < targetID) {
        prev = step;
        step += sqrt(jumlah);
        if (prev >= jumlah) return -1;
    }

    for (int i = prev; i < min(step, jumlah); i++) {
        if (daftar[i].id == targetID) return i;
    }

    return -1;
}

void tampilkan_hewan(hewan daftar[], int jumlah) {
    if (jumlah == 0) {
        cout << "Tidak ada data hewan.\n";
        return;
    }

    selectionSort(daftar, jumlah);

    cout << "\nIngin menampilkan:\n";
    cout << "1. Semua data hewan\n";
    cout << "2. Cari berdasarkan ID hewan\n";
    cout << "Pilihan (1/2): ";
    int pilihan;
    cin >> pilihan;
    cin.ignore();

    if (pilihan == 1) {
        cout << "\n========= DATA HEWAN =========\n";
        cout << left
            << setw(5)  << "ID"
            << setw(15) << "Nama"
            << setw(10) << "Jenis"
            << setw(15) << "Ras"
            << setw(8)  << "Umur"
            << setw(15) << "Perawatan"
            << setw(20) << "Tanggal Reservasi" << endl;

        cout << string(88, '-') << endl;

        for (int i = 0; i < jumlah; i++) {
            cout << left
                << setw(5)  << daftar[i].id
                << setw(15) << daftar[i].nama
                << setw(10) << daftar[i].jenis
                << setw(15) << daftar[i].ras
                << setw(8)  << (to_string(daftar[i].umur) + " th")
                << setw(15) << daftar[i].perawatan
                << setw(20) << daftar[i].reservasi << endl;
        }

        cout << string(88, '-') << endl;

    } else if (pilihan == 2) {
        int cariID;
        cout << "Masukkan ID hewan yang dicari: ";
        
        while (!(cin >> cariID)) {
            cout << "Input tidak valid! ID harus berupa angka.\n";
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Masukkan ID hewan yang dicari: ";
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int indeks = jumpSearch(daftar, jumlah, cariID);

        if (indeks != -1) {
            cout << "\nData ditemukan:\n";
            cout << "\n========= DATA HEWAN =========\n";
            cout << left
                << setw(5)  << "ID"
                << setw(15) << "Nama"
                << setw(10) << "Jenis"
                << setw(15) << "Ras"
                << setw(8)  << "Umur"
                << setw(15) << "Perawatan"
                << setw(20) << "Tanggal Reservasi" << endl;

            cout << string(88, '-') << endl;

            cout << left
                << setw(5)  << daftar[indeks].id
                << setw(15) << daftar[indeks].nama
                << setw(10) << daftar[indeks].jenis
                << setw(15) << daftar[indeks].ras
                << setw(8)  << (to_string(daftar[indeks].umur) + " th")
                << setw(15) << daftar[indeks].perawatan
                << setw(20) << daftar[indeks].reservasi << endl;

            cout << string(88, '-') << endl;
        } else {
            cout << "Data dengan ID tersebut tidak ditemukan.\n";
        }
    } else {
        cout << "Pilihan tidak valid. Silakan pilih 1 atau 2.\n";
    }
}

void ubah_hewan_ptr(hewan *daftar, int jumlah) // (belum diperbarui)
{
    int id;
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
    int id;
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
    string username, password;
    bool login = false;
    bool ADMIN = false;
    int percobaan_login = 0;

    int pilih;

    while (true)
    {
        cout << "\n=============================\n";
        cout << "|         MENU LOGIN        |\n";
        cout << "=============================\n";
        cout << "| 1. Registrasi             |\n";
        cout << "| 2. Login                  |\n";
        cout << "| 3. Keluar                 |\n";
        cout << "=============================\n";
        cout << "Pilih: ";
        cin >> pilih;

        cin.ignore();

        if (pilih == 1)
        {
            registrasi();
        }
        else if (pilih == 2)
        {
            while (percobaan_login < 3 && !login)
            {
                cout << "Masukkan Username : ";
                getline(cin, username);
                cout << "Masukkan Password : ";
                getline(cin, password);

                if (username == "" || password == "")
                {
                    cout << "Username dan password tidak boleh kosong.\n";
                    percobaan_login++;
                }
                else if (username == "pawpatrol" && password == "bayardulu")
                {
                    login = true;
                    ADMIN = true;
                    welcomeMessage(username, "admin");
                    break;
                }
                else if (loginUser(username, password))
                {
                    login = true;
                    welcomeMessage(username, "pengguna");
                    break;
                }
                else
                {
                    percobaan_login++;
                    cout << "Username atau password salah, silahkan coba lagi.\n\n";
                }
            }
            if (!login)
            {
                cout << "Terlalu banyak percobaan login. Program dihentikan.\n";
                return 0;
            }

            break;
        }
        else if (pilih == 3)
        {
            cout << "Terima kasih telah menggunakan program pet shop ini\n";
            return 0;
        }
        else
        {
            cout << "Input tidak valid.\n";
        }
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
