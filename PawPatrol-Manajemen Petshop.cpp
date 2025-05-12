#include <iostream>
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
    string id;
    string jenis;
    string ras;
    string nama;
    string perawatan;
    int umur;
    int reservasi;
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

void tambah_hewan_ptr(hewan *daftar, int *jumlah) // panggil fungsi ke dalam fungsi tambah data (belum diperbarui)
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
