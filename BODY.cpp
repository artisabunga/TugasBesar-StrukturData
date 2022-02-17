#include "HEADER.h"
#include <iostream>
using namespace std;

void menu(){
    cout<<"=========================================="<<endl;
    cout<<"DOCUMENT PERUSAHAAN"<<endl;
    cout<<"1.Tambah Data Document"<< endl;
    cout<<"2.Tambah Kategori Document"<<endl;
    cout<<"3.Hapus Kategori Document"<<endl;
    cout<<"4.Hapus Data Document"<<endl;
    cout<<"5.Lihat Documen Dari Kategori"<<endl;
    cout<<"6.Lihat Kategori Dari Documen"<<endl;
    cout<<"7.Lihat Documen Dari Kategori Terbanyak Saat Ini "<<endl;
    cout<<"8.Lihat Documen Dari Kategori Paling Sedikit Saat Ini "<<endl;
    cout<<"9.Tampilkan Semua Documen dan Kategorinya"<<endl;
    cout<<"=========================================="<<endl;
    cout<<"Apa Pilihan Anda ? : ";
}
void creatList(List &L){
    first(L) = NULL;
}
adr_p alokasidoc(int nmr, string judul, int tahun){
    adr_p P ;
    P = new elmList_p;
    info(P).nmrdoc = nmr;
    info(P).namadoc = judul;
    info(P).tahundoc = tahun;
    next(P) = NULL;
    prev(P) = NULL;
    firstch(P) = NULL;
    lastch(P) = NULL;
    return P;
}
void insertFirst(List &L , adr_p P){
     if(first(L)== NULL){
        first(L) = P;
        next(P) = first(L);
        prev(first(L)) = P;
    }else {
        next(P) = first(L);
        next(prev(first(L))) = P;
        prev(P) = prev(first(L));
        prev(first(L)) = P;
        first(L) = P;
    }
}
void insertAfter(List &L , adr_p prec , adr_p P){
    next(P) = next(prec);
    prev(P) = prec;
    prev(next(P)) = P;
    next(prec) = P;
}
void insertLast(List &L , adr_p P){
    if(first(L)== NULL){
        first(L) = P;
        next(P) = first(L);
        prev(first(L)) = P;
    }else {
        next(prev(first(L))) = P;
        next(P) =first(L);
        prev(P) = prev(first(L));
        prev(first(L)) = P;
    }
}
void insertUrutDoc(List &L , adr_p P ){
    adr_p prec;
    if (first(L)== NULL){
        insertFirst(L , P);
    }else if(next(first(L))== first(L)){
        if(info(first(L)).nmrdoc > info(P).nmrdoc ){
            insertFirst(L,P);
        }else{
            insertLast(L,P);
        }
    }else {
        if(info(first(L)).nmrdoc > info(P).nmrdoc ){
            insertFirst(L,P);
        }else{
            prec = first(L);
            while (info(next(prec)).nmrdoc < info(P).nmrdoc && next(prec)!= first(L)){
                prec = next(prec);
            }
            if (info(next(prec)).nmrdoc > info(P).nmrdoc){
                insertAfter(L,prec , P);

            }else if(info(next(prec)).nmrdoc == info(P).nmrdoc){
                cout<<"document dengan nomor "<<info(P).nmrdoc<<" sudah terdaftar"<<endl;
            }else{
                insertLast(L,P);
            }
        }
    }
}
void deleteFirst(List &L , adr_p &P){
     if(first(L) == NULL){
        cout<< " Data Document Kosong ";
    }else if(next(first(L))== first(L)){
        P = first(L);
        first(L) = NULL;
    }else {
        P = first(L);
        first(L) = next(first(L));
        next(prev(P)) = first(L);
        prev(first(L)) = prev(P);
        next(P) =NULL;
        prev(P) = NULL;
    }
}
void deleteAfter(List &L , adr_p prec , adr_p &P){
    P = next(prec);
    next(prec) = next(P);
    prev(next(P)) = prec;
    next(P) = NULL;
    prev(P) = NULL;

}
void deleteLast(List &L , adr_p &P){
    if(first(L) == NULL){
        cout<< " Data document Kosong ";
    }else if(next(first(L))== first(L)){
        P = first(L);
        first(L) = NULL;
    }else {
        P = prev(first(L));
        prev(first(L))= prev(P);
        next(prev(P)) = first(L);
        next(P) = NULL;
        prev(P) = NULL;
    }
}
void hapus_doc(List &L ,string nama, adr_p &P){
    adr_p prec;

    if(first(L)== NULL){
        cout<<" Data Document Kosong "<<endl;

    }else {
        prec = first(L);
        while(info(prec).namadoc != nama && next(prec)!= first(L)){
            prec =next(prec);
        }
        if(first(L)== prec){
            deleteFirst(L , P);
        }else if(info(prec).namadoc == nama && next(prec)== first(L)){
            deleteLast(L,P);
        }else if(info(prec).namadoc != nama && next(prec)== first(L)){
            cout<<" documen yang ingin di hapus tidak ditemukan "<<endl;
        }else{
            prec = prev(prec);
            deleteAfter(L,prec,P);
        }
    }

}
void showdoc(List L){
    adr_p P;
    if(first(L)== NULL){
        cout<<" Data Document kosong "<< endl;
    }
    else{
        P = first(L);
        cout<<" Daftar Data Document :"<<endl;
        cout<<endl;
        while (next(P)!= first(L)){
            cout<<" nomor document: "<< info(P).nmrdoc<<endl;
            cout<<" judul document:  "<<info(P).namadoc<<endl;
            cout<<" tahun document: "<<info(P).tahundoc<<endl;
            cout<<endl;
            P =next(P);
        }
        cout<<" nomor document: "<< info(P).nmrdoc<<endl;
        cout<<" judul document:  "<<info(P).namadoc<<endl;
        cout<<" tahun document: "<<info(P).tahundoc<<endl;
    }
    cout<<endl;
    cout<<endl;
}
adr_p findDoc(List L, string data){
     adr_p P;
    if(first(L) == NULL){
        return NULL;
    }else {
         P = first(L);
         while (info(P).namadoc != data && next(P)!= first(L)){
            P = next(P);

         }
         if (info(P).namadoc == data ){
           return P;
         }else {
           return NULL;
         }
    }
}
void docdarikategori(List L, string judul){
    adr_c Q;
    adr_p P;
    int i;

    i=0;
    P = first(L);
    cout<<" Document dari Kategori "<<judul<<" adalah : ";
    while(next(P)!= first(L)){
        Q = findkategory(judul , P);
        if(Q!= NULL){
            cout<<info(P).namadoc<<", ";
            i = i + 1;
        }
        P = next(P);
    }
     Q = findkategory(judul , P);
        if(Q!= NULL){
            cout<<info(P).namadoc<<". ";
            i = i + 1;
        }

    if(i == 0){
            cout<<" Document dengan kategori "<<judul<<" tidak tersedia "<<endl;
    }
}

