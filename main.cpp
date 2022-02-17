#include "HEADER.h"
#include <iostream>
using namespace std;

List  L;
string pilihsatu,pilihsa;
string judul, nama,caridoc;
string jnskategori , doc;
string kategori,data;
int nomorpilih;
int nmr,tahun,pilih;
adr_c C;
adr_p P;

int main()
{
    creatList(L);
    pilihsatu = "y";
    while(pilihsatu == "y" || pilihsatu == "Y"){
        cout<<endl;
        menu();
        cin>>nomorpilih;
        cout<<endl;
        if(nomorpilih == 1){
            cout<< "====TAMBAHKAN DOCUMENT BARU===="<<endl;
            cout<< "======isi tanpa spasi======"<<endl;
           cout<<"masukan nomer document(int) : ";
           cin >> nmr;
           cout<< "masukan judul document(string) : ";
           cin >>judul;
           cout<<"masukan tahun document(int) : ";
           cin>>tahun;
           P = alokasidoc(nmr,judul,tahun);
           insertUrutDoc(L , P);
            cout<<endl;

        }else if(nomorpilih == 2){
            cout<<" ====TAMBAHKAN KATEGORI DOCUMENT==== "<<endl;
            cout<< "======isi tanpa spasi======"<<endl;
            cout<<"masukan jenis kategori(string): ";
            cin>>jnskategori;
            cout<<"masukan document untuk kategori(string) : ";
            cin>>doc;
            C = creatkategori(jnskategori);
            P = findDoc(L,doc);
            insertKategori(P,C);
            cout<<endl;
        }else if (nomorpilih == 3){
            cout<<"====HAPUS KATEGORI DOCUMENT===="<<endl;
            cout<< "======isi tanpa spasi======"<<endl;
            cout<<"masukan nama document(string) : ";
            cin>>data;
            cout<<"masukan kategori yang ingin dihapus(string): ";
            cin>>jnskategori;
            P = findDoc(L,data);
            deletekategory(L , P ,C ,jnskategori);
            cout<<endl;
        }else if(nomorpilih == 4){
            cout<<"====HAPUS DATA DOCUMENT===="<<endl;
            cout<< "======isi tanpa spasi======"<<endl;
            cout<<"masukan nama document yang akan dihapus(string) : ";
            cin>>nama;
            hapus_doc(L,nama,P);
            cout<<endl;
        }else if(nomorpilih == 5){
            cout<<"====MELIHAT DOCUMENT DARI KATEGORI TERTENTU===="<<endl;
            cout<< "======isi tanpa spasi======"<<endl;
            cout<<"masukan kategori(string) : ";
            cin>>kategori;
            docdarikategori(L, kategori);
            cout<<endl;
            cout<<endl;
        }else if(nomorpilih == 6){
            cout<<"====MELIHAT KATEGORI DARI DOCUMENT TERTENTU===="<<endl;
            cout<< "======isi tanpa spasi======"<<endl;
            cout<<"masukan judul document(string) : ";
            cin>> caridoc;
            P = findDoc(L,caridoc);
            cout<<"kategory nya adalah : ";
            showkategory(P);
            cout<<endl;
            cout<<endl;
        }else if(nomorpilih == 7){
            kategoriterbanyak(L);
             cout<<endl;
            cout<<endl;
        }else if(nomorpilih == 8){
            kategorisedikit(L);
             cout<<endl;
            cout<<endl;
        }else if(nomorpilih == 9){
            cout<<"1.Lihat data Document saja"<<endl;
            cout<<"2.Lihat Isi List Keseluruhan"<<endl;
            cout<<"pilihan : ";
            cin>>pilih ;
            if(pilih == 1){
                showdoc(L);
                cout<<endl;
                cout<<endl;
            }else if(pilih == 2){
                printList(L);
                cout<<endl;
                cout<<endl;
            }else{
                cout<<"pilihan tidak tersedia ";
                cout<<endl;
                cout<<endl;
            }
        }else{
            cout<<"pilihan tidak tesedia " ;
             cout<<endl;
            cout<<endl;
        }
        cout<<"KEMBALI KE MENU AWAL ?(Y/T) : ";
        cin>>pilihsa;
        pilihsatu = pilihsa;
    }
     cout<<endl;
    cout<<"TERIMAKASIH"<<endl;
    cout<<"KELOMPOK 4 : "<<endl;
    cout<<"1. Artisa Bunga Syahputri (1301194007)"<<endl;
    cout<<"2. Bagus Wicaksono Nurjayanto (1301194280)"<<endl;


    creatList(L);
    pilihsatu = "y";
    while(pilihsatu == "y" || pilihsatu == "Y"){
        cout<<endl;
        menu();
        cin>>nomorpilih;
        cout<<endl;
        if(nomorpilih == 1){
            cout<< "====TAMBAHKAN DOCUMENT BARU===="<<endl;
           cout<<"masukan nomer document(int) : ";
           cin >> nmr;
           cout<< "masukan judul document(string) : ";
           cin.ignore();
           getline(cin, judul);
           cout<<"masukan tahun document(int) : ";
           cin>>tahun;
           P = alokasidoc(nmr,judul,tahun);
           insertUrutDoc(L , P);
            cout<<endl;

        }else if(nomorpilih == 2){
            cout<<" ====TAMBAHKAN KATEGORI DOCUMENT==== "<<endl;
            cout<<"masukan jenis kategori(string): ";
            cin.ignore();
            getline(cin, jnskategori);
            cout<<"masukan document untuk kategori(string) : ";
            cin.ignore();
            getline(cin,doc);
            C = creatkategori(jnskategori);
            P = findDoc(L,doc);
            insertKategori(P,C);
            cout<<endl;
        }else if (nomorpilih == 3){
            cout<<"====HAPUS KATEGORI DOCUMENT===="<<endl;
            cout<<"masukan nama document(string) : ";
            cin.ignore();
            getline(cin, data);
            cout<<"masukan kategori yang ingin dihapus(string): ";
            cin.ignore();
            getline(cin,jnskategori);
            P = findDoc(L,data);
            deletekategory(L , P ,C ,jnskategori);
            cout<<endl;
        }else if(nomorpilih == 4){
            cout<<"====HAPUS DATA DOCUMENT===="<<endl;
            cout<<"masukan nama document yang akan dihapus(string) : ";
            cin.ignore();
            getline(cin, nama);
            hapus_doc(L,nama,P);
            cout<<endl;
        }else if(nomorpilih == 5){
            cout<<"====MELIHAT DOCUMENT DARI KATEGORI TERTENTU===="<<endl;
            cout<<"masukan kategori(string) : ";
            cin.ignore();
            getline(cin, kategori);
            docdarikategori(L, kategori);
            cout<<endl;
            cout<<endl;
        }else if(nomorpilih == 6){
            cout<<"====MELIHAT KATEGORI DARI DOCUMENT TERTENTU===="<<endl;
            cout<<"masukan judul document(string) : ";
            cin.ignore();
            getline(cin, caridoc);
            P = findDoc(L,caridoc);
            cout<<"kategory nya adalah : ";
            showkategory(P);
            cout<<endl;
            cout<<endl;
        }else if(nomorpilih == 7){
            kategoriterbanyak(L);
             cout<<endl;
            cout<<endl;
        }else if(nomorpilih == 8){
            kategorisedikit(L);
             cout<<endl;
            cout<<endl;
        }else if(nomorpilih == 9){
            cout<<"1.Lihat data Document saja"<<endl;
            cout<<"2.Lihat Isi List Keseluruhan"<<endl;
            cout<<"pilihan : ";
            cin>>pilih ;
            if(pilih == 1){
                showdoc(L);
                cout<<endl;
                cout<<endl;
            }else if(pilih == 2){
                printList(L);
                cout<<endl;
                cout<<endl;
            }else{
                cout<<"pilihan tidak tersedia ";
                cout<<endl;
                cout<<endl;
            }
        }else{
            cout<<"pilihan tidak tesedia " ;
             cout<<endl;
            cout<<endl;
        }
        cout<<"KEMBALI KE MENU AWAL ?(Y/T) : ";
        cin>>pilihsa;
        pilihsatu = pilihsa;
    }
     cout<<endl;
    cout<<"TERIMAKASIH"<<endl;
    cout<<"KELOMPOK 4 : "<<endl;
    cout<<"1. Artisa Bunga Syahputri (1301194007)"<<endl;
    cout<<"2. Bagus Wicaksono Nurjayanto (1301194280)"<<endl;
}
