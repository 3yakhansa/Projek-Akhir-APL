#include <iostream>
#include <cmath>
#include <limits>
#include <iomanip>
#include <sstream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
using namespace std;

void setColor(int color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void rainbowText(const string &text)
{
    int colors[] = {12, 14, 10, 9, 13, 11}; 
    for (size_t i = 0; i < text.length(); ++i)
    {
        setColor(colors[i % 6]);
        cout << text[i];
    }
    setColor(7); 
}

const int limit_user = 50;
const int limit_hewan = 50;

struct Profil
{
    string nama_lengkap;
    string alamat;
    string no_hp;
};

struct User
{
    string username;
    string password;
    Profil data_profil;
};

User daftar_user[limit_user];
int jumlah_user = 0;

struct Customer
{
    int id;
    string nama;
    string username;
    string no_hp;
    string alamat;
};

struct dataReservasi
{
    int tanggal;
    int bulan;
    int tahun;
};

struct hewan
{
    string jenis;
    double berat;
    string nama;
    string perawatan;
    dataReservasi reservasi;
    int id;
    float umur;
    string username_pengguna;
};

Customer daftar_customer[limit_user];
int jumlah_customer = 0;
hewan daftar_hewan[limit_hewan];
int jumlah_hewan = 0;

void showLoading()
{
    system("cls");
    int colors[] = {12, 14, 10, 9, 13, 11};

    cout << "Memuat data: [          ] 0%";
    for (int i = 0; i <= 10; ++i)
    {
        string bar = "[";
        for (int j = 0; j < 10; ++j)
        {
            if (j < i)
            {
                setColor(colors[j % 6]); 
                bar += "="; 
            }
            else
            {
                bar += " "; 
            }
        }
        bar += "]";
        setColor(7); 

        cout << "\rMemuat data: " << bar << " ";
        setColor(colors[i % 6]);
        cout << i * 10 << "%";

        cout.flush();
        Sleep(200);
    }
    cout << endl;
    setColor(7);
    system("cls");
}

void animasiKucing()
{
    system("cls");
    setColor(14);
    cout << R"(
      \    /\
       )  ( ')
      (  /  )
       \(__)|
)";
    Sleep(1000);
}

void animasiAnjing()
{
    system("cls");
    setColor(10);
    cout << R"(
           __
      (___()'`;
      /,    /`
      \\"--\\
)";
    Sleep(1000);
}

void animasiBebek()
{
    system("cls");
    setColor(11);
    cout << R"(
  _
<(o )
   ( \
   _/_>
)";
    Sleep(1000);
}

void animasiKelinci()
{
    system("cls");
    setColor(13);
    cout << R"(
     \\
      \\_
      ( _\
      / \__
     / _/`"`
    {\  )_
     `"""`
)";
    Sleep(1000);
}

void animasiKodok()
{
    system("cls");
    setColor(9);
    cout << R"(
           (.)_(.)
        _ (   _   ) _
       / \/`-----'\/ \
     __\ ( (     ) ) /__
     )   /\ \._./ /\   (
      )_/ /|\   /|\ \_(
)";
    Sleep(1000);
}

void animasiRandomAnimal()
{
    srand(time(0));
    int r = rand() % 5;
    switch (r)
    {
    case 0:
        animasiKucing();
        break;
    case 1:
        animasiAnjing();
        break;
    case 2:
        animasiBebek();
        break;
    case 3:
        animasiKelinci();
        break;
    case 4:
        animasiKodok();
        break;
    }
}



void validasiString(string *target, const string &prompt)
{
    cout << prompt;
    getline(cin, *target);
    if (target->empty())
    {
        setColor(0);
        cout << "Error: Input tidak boleh kosong, silahkan coba lagi.\n";
        setColor(7);
        validasiString(target, prompt);
    }
}

void validasiDouble(double *target, const string &prompt)
{
    string input;
    cout << prompt;
    getline(cin, input);

    if (input.empty())
    {
        setColor(7);
        cout << "Error: Input tidak boleh kosong!\n";
        validasiDouble(target, prompt);
        return;
    }

    char *end;
    double value = strtod(input.c_str(), &end);

    if (*end == '\0')
    {
        if (value < 0)
        {
            setColor(7);
            cout << "Error: Input tidak boleh negatif!\n";
            validasiDouble(target, prompt);
            return;
        }

        *target = value;
    }
    else
    {
        setColor(7);
        cout << "Error: Input harus berupa angka (bisa desimal)!\n";
        validasiDouble(target, prompt);
    }
}


void validasiFloat(float *target, const string &prompt)
{
    string input;
    cout << prompt;
    getline(cin, input);

    if (input.empty())
    {
        setColor(7);
        cout << "Error: Input tidak boleh kosong!\n";
        validasiFloat(target, prompt);
        return;
    }

    char *end;
    float value = strtof(input.c_str(), &end);

    if (*end == '\0')
    {
        if (value < 0)
        {
            setColor(7);
            cout << "Error: Input tidak boleh negatif!\n";
            validasiFloat(target, prompt);
            return;
        }

        *target = value;
    }
    else
    {
        setColor(7);
        cout << "Error: Input harus berupa angka (bisa desimal)!\n";
        validasiFloat(target, prompt);
    }
}


void validasiInt(int *target, const string &prompt)
{
    string input;
    cout << prompt;
    getline(cin, input);
    if (input.empty())
    {
        setColor(7);
        cout << "Error: Input tidak boleh kosong!\n";
        setColor(7);
        validasiInt(target, prompt);
        return;
    }
    for (char c : input)
    {
        if (!isdigit(c))
        {
            setColor(7);
            cout << "Error: Input harus berupa angka bulat!.\n";
            setColor(7);
            validasiInt(target, prompt);
            return;
        }
    }
    *target = stoi(input);
}

bool loginUser(string username, string password)
{
    if (username == "pawpatrol" && password == "bayardulu")
    {
        return true;
    }
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
    system("cls");
    if (peran == "admin")
    {
        setColor(10);
        cout << R"(
             ,-._
           _.-'  '--.
         .'      _  -`\_
        / .----.`_.'----'
        ;/     `
       /_;

    ._      ._      ._      ._
_.-._)`\_.-._)`\_.-._)`\_.-._)`\_.-._

      Siap Bertugas, Siap Beraksi!
Semangat melayani dengan cepat dan ramah!
)";
        setColor(11);
        cout << "\nLogin berhasil sebagai ADMIN. Selamat datang!\n";
    }
    else
    {
        setColor(14);
        cout << R"(
             ,-._
           _.-'  '--.
         .'      _  -`\_
        / .----.`_.'----'
        ;/     `
       /_;

    ._      ._      ._      ._
_.-._)`\_.-._)`\_.-._)`\_.-._)`\_.-._

          PAWPATROL!
Kami Menerima Semua Jenis Hewan! 
)";
        setColor(12);
        cout << "\nLogin berhasil sebagai pengguna, Selamat datang " << nama << "!\n";
    }
    Sleep(1000);
}

void registrasi()
{
    if (jumlah_user < limit_user)
    {
        string username_input;
        bool username_valid = false;
        while (!username_valid)
        {
            validasiString(&username_input, "Masukkan Username: ");
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
                setColor(12);
                cout << "Username sudah terdaftar. Silakan pilih username yang lain.\n";
                setColor(7);
            }
            else
            {
                username_valid = true;
            }
        }
        daftar_user[jumlah_user].username = username_input;
        string pass_input;
        validasiString(&pass_input, "Masukkan Password: ");
        daftar_user[jumlah_user].password = pass_input;
        validasiString(&daftar_user[jumlah_user].data_profil.nama_lengkap, "Masukkan Nama Lengkap: ");
        validasiString(&daftar_user[jumlah_user].data_profil.alamat, "Masukkan Alamat: ");
        validasiString(&daftar_user[jumlah_user].data_profil.no_hp, "Masukkan No HP: ");
        daftar_customer[jumlah_customer].id = jumlah_customer + 1;
        daftar_customer[jumlah_customer].nama = daftar_user[jumlah_user].data_profil.nama_lengkap;
        daftar_customer[jumlah_customer].username = username_input;
        daftar_customer[jumlah_customer].no_hp = daftar_user[jumlah_user].data_profil.no_hp;
        daftar_customer[jumlah_customer].alamat = daftar_user[jumlah_user].data_profil.alamat;
        jumlah_user++;
        jumlah_customer++;
        setColor(10);
        cout << "\nRegistrasi berhasil!\n";
        setColor(7);
    }
    else
    {
        setColor(12);
        cout << "\nKapasitas pengguna penuh.\n";
        setColor(7);
    }
}

int cariCustomerByUsername(Customer daftar[], int jumlah, string username)
{
    for (int i = 0; i < jumlah; i++)
    {
        if (daftar[i].username == username)
        {
            return i;
        }
    }
    return -1;
}


void tampilkanSemuaCustomer(Customer daftar[], int jumlah)
{
    cout << "\n========= DAFTAR CUSTOMER =========\n";
    cout << left
    << setw(5) << "No."
    << setw(20) << "Nama"
         << setw(15) << "Username"
         << setw(15) << "No HP"
         << setw(30) << "Alamat" << endl;

    cout << string(85, '-') << endl;
    
    for (int i = 0; i < jumlah; i++)
    {
        cout << left
        << setw(5) << daftar[i].id
             << setw(20) << daftar[i].nama
             << setw(15) << daftar[i].username
             << setw(15) << daftar[i].no_hp
             << setw(30) << daftar[i].alamat << endl;
    }

    cout << string(85, '-') << endl;
}

void tampilkanCustomer(Customer daftar[], int jumlah)
{
    if (jumlah == 0)
    {
        cout << "Tidak ada data customer.\n";
        return;
    }
    
    cout << "\nIngin menampilkan:\n";
    cout << "1. Semua data customer\n";
    cout << "2. Cari berdasarkan username customer\n";
    
    int pilihan;
    validasiInt(&pilihan, "Pilihan (1/2): ");
    
    if (pilihan == 1)
    {
        tampilkanSemuaCustomer(daftar, jumlah);
    }
    else if (pilihan == 2)
    {
        string cariUsername;
        validasiString(&cariUsername, "Masukkan Username customer yang dicari: ");
        
        int indeks = cariCustomerByUsername(daftar, jumlah, cariUsername);
        
        if (indeks != -1)
        {
            cout << "\nData ditemukan:\n";
            cout << "\n========= DATA CUSTOMER =========\n";
            cout << left
                 << setw(5) << "ID"
                 << setw(20) << "Nama"
                 << setw(15) << "Username"
                 << setw(15) << "No HP"
                 << setw(30) << "Alamat" << endl;
                 
                 cout << string(85, '-') << endl;
                 
                 cout << left
                 << setw(5) << daftar[indeks].id
                 << setw(20) << daftar[indeks].nama
                 << setw(15) << daftar[indeks].username
                 << setw(15) << daftar[indeks].no_hp
                 << setw(30) << daftar[indeks].alamat << endl;
                 
                 cout << string(85, '-') << endl;
                }
                else
                {
                    cout << "Customer dengan username tersebut tidak ditemukan.\n";
                }
            }
            else
            {
                cout << "Pilihan tidak valid. Silakan pilih 1 atau 2.\n";
            }
        }

void selectionSort(hewan daftar[], int jumlah)
{
    for (int i = 0; i < jumlah - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < jumlah; j++)
        {
            if (daftar[j].id < daftar[minIdx].id)
            {
                minIdx = j;
            }
        }
        if (minIdx != i)
        {
            swap(daftar[i], daftar[minIdx]);
        }
    }
}

int jumpSearch(hewan daftar[], int jumlah, int targetID)
{
    int step = sqrt(jumlah);
    int prev = 0;
    
    while (daftar[min(step, jumlah) - 1].id < targetID)
    {
        prev = step;
        step += sqrt(jumlah);
        if (prev >= jumlah)
        return -1;
    }
    
    for (int i = prev; i < min(step, jumlah); i++)
    {
        if (daftar[i].id == targetID)
        return i;
    }
    
    return -1;
}

string to_string(double value, int precision) {
    stringstream stream;
    stream << fixed << setprecision(precision) << value;
    return stream.str();
}

void tampilkanSemuaHewan(hewan daftar[], int jumlah)
{
    cout << left
        << setw(5) << "ID"
        << setw(15) << "Nama"
        << setw(10) << "Jenis"
        << setw(10) << "Berat"
        << setw(10) << "Umur"
        << setw(15) << "Perawatan"
        << setw(20) << "Tanggal Reservasi" << endl;


    cout << string(88, '-') << endl;

    for (int i = 0; i < jumlah; i++)
    {
    cout << left
        << setw(5) << daftar[i].id
        << setw(15) << daftar[i].nama
        << setw(10) << daftar[i].jenis
        << setw(10) << (to_string(daftar[i].berat, 1) + " kg")
        << setw(10) << (to_string(daftar[i].umur, 1) + " th")
        << setw(15) << daftar[i].perawatan
        << daftar[i].reservasi.tanggal << "/" << daftar[i].reservasi.bulan << "/" << daftar[i].reservasi.tahun << endl;

    }

    cout << string(88, '-') << endl;
}

void tampilkanHewan(hewan daftar[], int jumlah)
{
    if (jumlah == 0)
    {
        cout << "Tidak ada data hewan.\n";
        return;
    }

    selectionSort(daftar, jumlah);

    cout << "\nIngin menampilkan:\n";
    cout << "1. Semua data hewan\n";
    cout << "2. Cari berdasarkan ID hewan\n";

    int pilihan;
    validasiInt(&pilihan, "Pilihan (1/2): ");

    if (pilihan == 1)
    {
        tampilkanSemuaHewan(daftar, jumlah);
    }
    else if (pilihan == 2)
    {
        int cariID;
        validasiInt(&cariID, "Masukkan ID hewan yang dicari: ");

        int indeks = jumpSearch(daftar, jumlah, cariID);

        if (indeks != -1)
        {
            cout << "\nData ditemukan:\n";
            cout << "\n========= DATA HEWAN =========\n";
            cout << left
                << setw(5) << "ID"
                << setw(15) << "Nama"
                << setw(10) << "Jenis"
                << setw(10) << "Berat"
                << setw(10) << "Umur"
                << setw(15) << "Perawatan"
                << setw(20) << "Tanggal Reservasi" << endl;

            cout << string(88, '-') << endl;

            cout << left
                 << setw(5) << daftar[indeks].id
                 << setw(15) << daftar[indeks].nama
                 << setw(10) << daftar[indeks].jenis
                 << setw(10) << (to_string(daftar[indeks].berat, 1) + " kg")
                 << setw(10) << (to_string(daftar[indeks].umur, 1) + " th")
                 << setw(15) << daftar[indeks].perawatan
                 << daftar[indeks].reservasi.tanggal << "/" << daftar[indeks].reservasi.bulan << "/" << daftar[indeks].reservasi.tahun << endl;

            cout << string(88, '-') << endl;
        }
        else
        {
            cout << "Data dengan ID tersebut tidak ditemukan.\n";
        }
    }
    else
    {
        cout << "Pilihan tidak valid. Silakan pilih 1 atau 2.\n";
    }
}

void tampilkanHewanByUser(hewan *daftar, int jumlah, string username_pengguna)
{
    cout << "\n========= DATA HEWANKU =========\n";
    cout << left
        << setw(5) << "ID"
        << setw(15) << "Nama"
        << setw(10) << "Jenis"
        << setw(10) << "Berat"
        << setw(10) << "Umur"
        << setw(15) << "Perawatan"
        << setw(20) << "Tanggal Reservasi" << endl;

    cout << string(90, '-') << endl;

    bool adaData = false;

    for (int i = 0; i < jumlah; i++)
    {
        if (daftar[i].username_pengguna == username_pengguna)
        {
            ostringstream tanggal;
            tanggal << daftar[i].reservasi.tanggal << "/"
                    << daftar[i].reservasi.bulan << "/"
                    << daftar[i].reservasi.tahun;

            cout << left
                 << setw(5) << daftar[i].id
                 << setw(15) << daftar[i].nama
                 << setw(10) << daftar[i].jenis
                 << setw(10) << (to_string(daftar[i].berat, 1) + " kg")
                 << setw(10) << (to_string(daftar[i].umur, 1) + " th")
                 << setw(15) << daftar[i].perawatan
                 << setw(20) << tanggal.str() << endl;
            adaData = true;
        }
    }

    if (!adaData)
    {
        cout << "Tidak ada data hewan yang dimiliki oleh Anda.\n";
    }

    cout << string(90, '-') << endl;
}

void tampilkanData(Customer daftar_customer[], int jumlah_customer, hewan daftar_hewan[], int jumlah_hewan)
{
    int pilihan;

    do
    {
        cout << "\n========= TAMPILKAN DATA =========";
        cout << "\n1. Tampilkan Data Customer";
        cout << "\n2. Tampilkan Data Hewan";
        cout << "\nPilih (1/2): ";

        validasiInt(&pilihan, ">> ");

        if (pilihan != 1 && pilihan != 2)
        {
            cout << "Pilihan hanya 1 atau 2!\n";
        }

    } while (pilihan != 1 && pilihan != 2);

    if (pilihan == 1)
    {
        tampilkanCustomer(daftar_customer, jumlah_customer);
    }
    else if (pilihan == 2)
    {
        tampilkanHewan(daftar_hewan, jumlah_hewan);
    }
}

void tambahHewan_ptr(hewan *daftar, int *jumlah, string username_pengguna)
{
    while (true)
    {
        try
        {
            if (*jumlah >= limit_hewan)
            {
                cout << "Maaf, kapasitas penuh.\n";
                return;
            }

            while (true)
            {
                int id_input;
                validasiInt(&id_input, "Masukkan ID Hewan (angka): ");

                bool id_unik = true;
                for (int i = 0; i < *jumlah; i++)
                {
                    if (daftar[i].id == id_input)
                    {
                        id_unik = false;
                        break;
                    }
                }

                if (!id_unik)
                {
                    cout << "Error: ID sudah digunakan. Masukkan ID lain.\n";
                }
                else
                {
                    daftar[*jumlah].id = id_input;
                    break;
                }
            }

            validasiString(&daftar[*jumlah].nama, "Masukkan Nama Hewan: ");
            validasiString(&daftar[*jumlah].jenis, "Masukkan Jenis Hewan: ");
            validasiDouble(&daftar[*jumlah].berat, "Masukkan Berat Hewan: ");
            validasiFloat(&daftar[*jumlah].umur, "Masukkan Umur Hewan: ");
            validasiString(&daftar[*jumlah].perawatan, "Masukkan Jenis Perawatan Hewan: ");
            validasiInt(&daftar[*jumlah].reservasi.tanggal, "Masukkan Tanggal Reservasi: ");
            validasiInt(&daftar[*jumlah].reservasi.bulan, "Masukkan Bulan Reservasi: ");
            validasiInt(&daftar[*jumlah].reservasi.tahun, "Masukkan Tahun Reservasi: ");

            daftar[*jumlah].username_pengguna = username_pengguna;

            (*jumlah)++;
            cout << "Data hewan berhasil ditambahkan.\n";
            break;
        }
        catch (const exception &e)
        {
            cout << "Terjadi kesalahan saat menambahkan data: " << e.what() << endl;
            cout << "Silakan coba lagi dari awal.\n";
        }
    }
}

void ubahCustomer(Customer daftar[], int jumlah)
{
    if (jumlah == 0)
    {
        cout << "Tidak ada data customer untuk diubah.\n";
        return;
    }

    cout << "\n========= DAFTAR COSTUMER =========\n";
    cout << left
         << setw(5) << "No."
         << setw(20) << "Nama"
         << setw(15) << "Username"
         << setw(15) << "No HP"
         << setw(30) << "Alamat" << endl;
    cout << string(85, '-') << endl;

    for (int i = 0; i < jumlah; i++)
    {
        cout << left
             << setw(5) << daftar[i].id
             << setw(20) << daftar[i].nama
             << setw(15) << daftar[i].username
             << setw(15) << daftar[i].no_hp
             << setw(30) << daftar[i].alamat << endl;
    }
    cout << string(85, '-') << endl;

    string username;
    validasiString(&username, "Masukkan username costumer yang ingin diubah: ");
    int indeks = cariCustomerByUsername(daftar, jumlah, username);
    if (indeks == -1)
    {
        cout << "Customer dengan username \"" << username << "\" tidak ditemukan.\n";
        return;
    }

    cout << "Data customer ditemukan. Silakan masukkan data baru.\n";

    validasiString(&daftar[indeks].nama, "Masukkan nama baru: ");
    validasiString(&daftar[indeks].username, "Masukkan username baru: ");
    validasiString(&daftar[indeks].no_hp, "Masukkan nomor HP baru: ");
    validasiString(&daftar[indeks].alamat, "Masukkan alamat baru: ");

    cout << "Data customer berhasil diperbarui.\n";

    tampilkanSemuaCustomer(daftar, jumlah);
}

void ubahHewan_ptr(hewan *daftar, int jumlah)
{
    int id;
    tampilkanSemuaHewan(daftar, jumlah);
    validasiInt(&id, "Masukkan ID hewan yang ingin diubah: ");

    bool ditemukan = false;

    for (int i = 0; i < jumlah; i++)
    {
        if ((daftar + i)->id == id)
        {
            validasiString(&(daftar + i)->nama, "Masukkan nama baru: ");
            validasiString(&(daftar + i)->jenis, "Masukkan jenis baru: ");
            validasiDouble(&(daftar + i)->berat, "Masukkan berat baru: ");

            validasiFloat(&(daftar + i)->umur, "Masukkan umur baru: ");

            validasiString(&(daftar + i)->perawatan, "Masukkan jenis perawatan baru: ");

            validasiInt(&(daftar + i)->reservasi.tanggal, "Masukkan Tanggal Reservasi: ");
            validasiInt(&(daftar + i)->reservasi.bulan, "Masukkan Bulan Reservasi: ");
            validasiInt(&(daftar + i)->reservasi.tahun, "Masukkan Tahun Reservasi: ");

            ditemukan = true;
            cout << "Data hewan berhasil diperbarui.\n";
            tampilkanSemuaHewan(daftar, jumlah);
            break;
        }
    }

    if (!ditemukan)
    {
        cout << "ID hewan tidak ditemukan.\n";
    }
}

void ubahData(Customer daftar_customer[], int jumlah_customer, hewan daftar_hewan[], int jumlah_hewan)
{
    int pilihan;
    do
    {
        cout << "\n========== UBAH DATA ==========";
        cout << "\n1. Ubah Data Customer";
        cout << "\n2. Ubah Data Hewan";
        cout << "\nPilih (1/2): ";

        validasiInt(&pilihan, ">> ");

        if (pilihan != 1 && pilihan != 2)
        {
            cout << "Pilihan hanya 1 atau 2!\n";
        }
    } while (pilihan != 1 && pilihan != 2);

    if (pilihan == 1)
    {
        ubahCustomer(daftar_customer, jumlah_customer);
    }
    else if (pilihan == 2)
    {
        ubahHewan_ptr(daftar_hewan, jumlah_hewan);
    }
}

void hapusCustomer(Customer daftar[], int &jumlah)
{
    if (jumlah == 0)
    {
        cout << "Tidak ada data customer untuk dihapus.\n";
        return;
    }
    cout << "\n========= DATA CUSTOMER =========\n";
    cout << left
         << setw(5) << "ID"
         << setw(20) << "Nama"
         << setw(15) << "Username"
         << setw(15) << "No HP"
         << setw(30) << "Alamat" << endl;

    cout << string(85, '-') << endl;

    for (int i = 0; i < jumlah; i++)
    {
        cout << left
             << setw(5) << daftar[i].id
             << setw(20) << daftar[i].nama
             << setw(15) << daftar[i].username
             << setw(15) << daftar[i].no_hp
             << setw(30) << daftar[i].alamat << endl;
    }
    cout << string(85, '-') << endl;

    string username;
    validasiString(&username, "Masukkan username customer yang ingin dihapus: ");
    int indeks = cariCustomerByUsername(daftar, jumlah, username);
    if (indeks == -1)
    {
        cout << "Customer dengan username \"" << username << "\" tidak ditemukan.\n";
        return;
    }

    char konfirmasi;
    cout << "Apakah Anda yakin ingin menghapus customer dengan username \"" << username << "\"? (y/n): ";
    cin >> konfirmasi;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (konfirmasi == 'y' || konfirmasi == 'Y')
    {
        for (int i = indeks; i < jumlah - 1; i++)
        {
            daftar[i] = daftar[i + 1];
        }
        jumlah--;
        cout << "Customer dengan username \"" << username << "\" berhasil dihapus.\n";
    }
    else
    {
        cout << "Penghapusan dibatalkan.\n";
    }

    tampilkanSemuaCustomer(daftar, jumlah);
}

void hapusHewan_ptr(hewan *daftar, int *jumlah)
{
    if (*jumlah == 0)
    {
        cout << "Tidak ada data hewan untuk dihapus.\n";
        return;
    }

    tampilkanSemuaHewan(daftar, *jumlah);

    int id;
    validasiInt(&id, "Masukkan ID hewan yang ingin dihapus: ");

    int indeksHewan = -1;
    for (int i = 0; i < *jumlah; i++)
    {
        if ((daftar + i)->id == id)
        {
            indeksHewan = i;
            break;
        }
    }

    if (indeksHewan == -1)
    {
        cout << "Hewan dengan ID " << id << " tidak ditemukan.\n";
        return;
    }

    char konfirmasi;
    cout << "Apakah Anda yakin ingin menghapus hewan dengan ID " << id << "? (y/n): ";
    cin >> konfirmasi;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (konfirmasi == 'y' || konfirmasi == 'Y')
    {
        for (int j = indeksHewan; j < *jumlah - 1; j++)
        {
            *(daftar + j) = *(daftar + j + 1);
        }
        (*jumlah)--;
        cout << "Data hewan dengan ID " << id << " berhasil dihapus.\n";
    }
    else
    {
        cout << "Penghapusan dibatalkan.\n";
    }

    tampilkanSemuaHewan(daftar, *jumlah);
}

void sort_nama_ascending(hewan *daftar, int jumlah)
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

void sort_umur_descending(hewan *daftar, int jumlah)
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

void sort_jenis_ascending(hewan *daftar, int jumlah)
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

void hapusData(Customer daftar_customer[], int &jumlah_customer, hewan daftar_hewan[], int *jumlah_hewan)
{
    int pilihan;

    cout << "\n========== HAPUS DATA ==========";
    cout << "\n1. Hapus Data Customer";
    cout << "\n2. Hapus Data Hewan";

    while (true)
    {
        validasiInt(&pilihan, "\nPilih (1/2): ");
        if (pilihan == 1 || pilihan == 2)
        {
            break;
        }
        else
        {
            cout << "Pilihan hanya boleh 1 atau 2!\n";
        }
    }

    if (pilihan == 1)
    {
        hapusCustomer(daftar_customer, jumlah_customer);
    }
    else if (pilihan == 2)
    {
        hapusHewan_ptr(daftar_hewan, jumlah_hewan);
    }
}

void laporanHewan(hewan *daftar, int jumlah)
{
    cout << "\n--- LAPORAN HEWAN ---\n";

    int tgl, bln, thn;
    validasiInt(&tgl, "Masukkan Tanggal Reservasi: ");
    validasiInt(&bln, "Masukkan Bulan Reservasi: ");
    validasiInt(&thn, "Masukkan Tahun Reservasi: ");

    string jenisList[100];
    int jumlahJenis[100] = {0};
    int jenisCount = 0;

    string perawatanList[100];
    int jumlahPerawatan[100] = {0};
    int perawatanCount = 0;

    cout << "\nLaporan Petshop Pawpatrol (Tanggal " << tgl << "/" << bln << "/" << thn << "):\n";
    cout << left << setw(5) << "ID"
         << setw(15) << "Nama"
         << setw(12) << "Jenis"
         << setw(12) << "Berat"
         << setw(6) << "Umur"
         << setw(15) << "Perawatan"
         << setw(12) << "Tanggal Reservasi" << endl;
    cout << string(77, '-') << endl;

    int total = 0;
    for (int i = 0; i < jumlah; i++)
    {
        if (daftar[i].reservasi.tanggal == tgl &&
            daftar[i].reservasi.bulan == bln &&
            daftar[i].reservasi.tahun == thn)
        {

            cout << left << setw(5) << daftar[i].id
                 << setw(15) << daftar[i].nama
                 << setw(12) << daftar[i].jenis
                 << setw(12) << daftar[i].berat
                 << setw(6) << fixed << setprecision(2) << daftar[i].umur
                 << setw(15) << daftar[i].perawatan
                 << setw(2) << daftar[i].reservasi.tanggal << "/" << daftar[i].reservasi.bulan << "/" << daftar[i].reservasi.tahun << endl;

            bool jenisAda = false;
            for (int j = 0; j < jenisCount; j++)
            {
                if (daftar[i].jenis == jenisList[j])
                {
                    jumlahJenis[j]++;
                    jenisAda = true;
                    break;
                }
            }
            if (!jenisAda)
            {
                jenisList[jenisCount] = daftar[i].jenis;
                jumlahJenis[jenisCount]++;
                jenisCount++;
            }

            bool perawatanAda = false;
            for (int p = 0; p < perawatanCount; p++)
            {
                if (daftar[i].perawatan == perawatanList[p])
                {
                    jumlahPerawatan[p]++;
                    perawatanAda = true;
                    break;
                }
            }
            if (!perawatanAda)
            {
                perawatanList[perawatanCount] = daftar[i].perawatan;
                jumlahPerawatan[perawatanCount]++;
                perawatanCount++;
            }

            total++;
        }
    }

    cout << "\nTotal hewan ditemukan: " << total << endl;

    if (jenisCount > 0)
    {
        cout << "\n>> Jumlah Berdasarkan Jenis Hewan:\n";
        for (int i = 0; i < jenisCount; i++)
        {
            cout << "- " << jenisList[i] << ": " << jumlahJenis[i] << endl;
        }
    }

    if (perawatanCount > 0)
    {
        cout << "\n>> Jumlah Berdasarkan Jenis Perawatan:\n";
        for (int i = 0; i < perawatanCount; i++)
        {
            cout << "- " << perawatanList[i] << ": " << jumlahPerawatan[i] << endl;
        }
    }

    if (total == 0)
    {
        cout << "\nTidak ada data yang sesuai dengan tanggal tersebut.\n";
    }
}

int main()
{
    while (true)
    {
        string username, password;
        bool login = false;
        int percobaan_login = 0;
        int pilih;

        animasiRandomAnimal();

        system("cls");
        rainbowText("=========================================\n");
        rainbowText("|      SELAMAT DATANG DI PAWPATROL      |\n");
        rainbowText("=========================================\n\n");

        while (true)
        {
            cout << "\n=============================";
            setColor(14);
            cout << "\n|         MENU LOGIN        |";
            setColor(7);
            cout << "\n=============================";
            cout << "\n| 1. Registrasi             |";
            cout << "\n| 2. Login                  |";
            cout << "\n| 3. Keluar                 |";
            cout << "\n=============================";
            validasiInt(&pilih, "\nPilih: ");
            system("cls");
            showLoading();

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

                    if (username.empty() || password.empty())
                    {
                        cout << "\nUsername dan password tidak boleh kosong.\n";
                        percobaan_login++;
                    }
                    else if (loginUser(username, password))
                    {
                        login = true;

                        if (username == "pawpatrol" && password == "bayardulu")
                        {
                            animasiRandomAnimal();

                            welcomeMessage(username, "admin");

                            while (true)
                            {
                                cout << "\n=============================\n";
                                cout << "|         MENU ADMIN         |\n";
                                cout << "=============================\n";
                                cout << "| 1. Tampilkan Data          |\n";
                                cout << "| 2. Menambahkan Data Hewan  |\n";
                                cout << "| 3. Mengubah Data           |\n";
                                cout << "| 4. Menghapus Data          |\n";
                                cout << "| 5. Tampilkan Laporan       |\n";
                                cout << "| 6. Kembali                 |\n";
                                cout << "=============================\n";

                                int pilihanAdmin;
                                validasiInt(&pilihanAdmin, "Pilih (1-6): ");
                                system("cls");
                                showLoading();

                                switch (pilihanAdmin)
                                {
                                case 1:
                                    tampilkanData(daftar_customer, jumlah_customer, daftar_hewan, jumlah_hewan);
                                    break;
                                case 2:
                                    tambahHewan_ptr(daftar_hewan, &jumlah_hewan, username);
                                    break;
                                case 3:
                                    ubahData(daftar_customer, jumlah_customer, daftar_hewan, jumlah_hewan);
                                    break;
                                case 4:
                                    hapusData(daftar_customer, jumlah_customer, daftar_hewan, &jumlah_hewan);
                                    break;
                                case 5:
                                    laporanHewan(daftar_hewan, jumlah_hewan);
                                    break;
                                case 6:
                                    cout << "\nKembali ke menu login\n";
                                    break;
                                default:
                                    cout << "\nPilihan tidak valid. Masukkan angka 1 - 6.\n";
                                }
                                if (pilihanAdmin == 6)
                                    break;
                            }
                        }
                        else
                        {
                            animasiRandomAnimal();

                            welcomeMessage(username, "pengguna");

                            while (true)
                            {
                                cout << "\n==============================\n";
                                cout << "|         MENU PENGGUNA      |\n";
                                cout << "==============================\n";
                                cout << "| 1. Tampilkan Data Hewan    |\n";
                                cout << "| 2. Menambah Data Hewan     |\n";
                                cout << "| 3. Kembali                 |\n";
                                cout << "===============================\n";
                                cout << "Pilih (1-3): ";

                                int pilihanPengguna;
                                cin >> pilihanPengguna;
                                cin.ignore();
                                system("cls");
                                showLoading();

                                switch (pilihanPengguna)
                                {
                                case 1:
                                    tampilkanHewanByUser(daftar_hewan, jumlah_hewan, username);
                                    break;
                                case 2:
                                    tambahHewan_ptr(daftar_hewan, &jumlah_hewan, username);
                                    break;
                                case 3:
                                    cout << "\nKembali ke menu login\n";
                                    break;
                                default:
                                    cout << "\nPilihan tidak valid. Masukkan angka 1 - 6.\n";
                                    break;
                                }
                                if (pilihanPengguna == 3)
                                    break;
                            }
                        }
                        break;
                    }
                    else
                    {
                        percobaan_login++;
                        cout << "\nUsername atau password salah.\n";
                    }
                }
                if (!login)
                {
                    cout << "\nTerlalu banyak percobaan login. Program dihentikan.\n";
                    return 0;
                }
                break;
            }
            else if (pilih == 3)
            {
                cout << "\nTerima kasih telah menggunakan program pet shop ini.\n";
                return 0;
            }
            else
            {
                cout << "\nInput tidak valid.\n";
            }
        }
    }
    return 0;
}