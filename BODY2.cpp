#include "HEADER.h"
#include <iostream>
using namespace std;

adr_c creatkategori(infotype_c data){
    adr_c P;

    P = new elmList_c;
    info(P) = data;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}
void insertKategori(adr_p P , adr_c C){
    if(firstch(P)== NULL){
        firstch(P) = C;
        lastch(P) = C;
    }else{
        next(lastch(P)) = C;
        prev(C) = lastch(P);
        lastch(P) = C;
    }

}
void deleteFirstkategori(adr_p P , adr_c &C){
    if(firstch(P)==NULL){
        cout<<" kategory document kosong "<<endl;
    }else{
        C = firstch(P);
        firstch(P) = next(C);
        next(C)=NULL;
        prev(firstch(P)) = NULL;
    }
}
void deleteafterkategory(adr_c prec , adr_c &C){
    next(prec) = C;
    next(prec) = next(C);
    prev(next(C)) = prec;
    next(C) = NULL;
    prev(C)=NULL;

}
void deleteLastkategory(adr_p P , adr_c &C){
    adr_c Q;
    if(firstch(P)== NULL){
        cout<<" kategory document kosong "<<endl;
    }else{
        Q = firstch(P);
        while(next(Q)!=lastch(P) ){
            Q = next(Q);
        }
        C = lastch(P);
        lastch(P) = Q;
        next(Q) = NULL;
        prev(C)=NULL;

    }

}
adr_c findkategory(string judul , adr_p P){
    adr_c C;

    C = firstch(P);
    if(C == NULL){
        return NULL;
    }else{
        while(info(C)!= judul && next(C)!= NULL){
            C = next(C);
        }
        if(info(C)==judul){
            return C;
        }else {
            return NULL;
        }
    }

}
void deletekategory(List &L , adr_p P, adr_c &C , string nama){
    adr_c prec;

    if (firstch(P) == NULL){
        cout<<" Kategory pada document ini kosong ";
    }
    C = findkategory(nama , P);
    if(C == NULL){
        cout<<" kategori tidak terdaftar "<<endl;
    }else if (C == firstch(P)){
        deleteFirstkategori(P , C);
    }else if (C == lastch(P)){
        deleteLastkategory(P,C);

    }else{
        prec = firstch(P);
        while(next(prec) != C){
            prec = next(prec);
        }
        deleteafterkategory(prec , C);
    }

}
void showkategory(adr_p P){
    adr_c C;
    C = firstch(P);
    if(firstch(P)== NULL){
        cout<<" kategori kosong ";
    }else{
        while (C!= NULL){
            cout<<info(C)<<",";
            C = next(C);
        }
    }
}
void printList(List L){
    adr_p P;

    if(first(L)==NULL){
        cout<<"List document kosong"<<endl;
    }else{
        P = first(L);
        while (next(P)!= first(L)){
            cout<<"nomor document: "<< info(P).nmrdoc<<endl;
            cout<<"judul document:  "<<info(P).namadoc<<endl;
            cout<<"tahun document: "<<info(P).tahundoc<<endl;
            cout<<"kategory : ";
            showkategory(P);
            cout<<endl;
            P = next(P);
        }
        cout<<"nomor document: "<< info(P).nmrdoc<<endl;
        cout<<"judul document:  "<<info(P).namadoc<<endl;
        cout<<"tahun document: "<<info(P).tahundoc<<endl;
        cout<<"kategory : ";
        showkategory(P);
        cout<<endl;
    }
}
void kategoriterbanyak(List L){
    int i;
    int j;
    adr_p maxi;
    adr_p P;
    adr_c Q;
    P = first(L);
    j = 0;
    maxi = first(L);
    while(next(P)!= first(L)){
        Q = firstch(P);
        i = 0;
        while(Q!= NULL){
            i = i + 1;
            Q = next(Q);
        }
        if(j < i){
          maxi = P;
           j = i;
        }
        P = next(P);
    }
    Q = firstch(P);
    i = 0;
    while(Q!= NULL){
        i = i + 1;
        Q = next(Q);
    }
    if(j < i){
        maxi = P;
        j = i;
    }
    cout<<" documen dengan kategori terbanyak adalah : ";
    cout<<info(maxi).namadoc;
    cout<<endl;
    cout<<" dengan kategori : ";
    showkategory(maxi);
    cout<<endl;
    cout<<endl;
}
void kategorisedikit(List L){
    int i;
    int j;
    adr_p mini;
    adr_p P;
    adr_c Q;

    P = first(L);
    j = 100;
    mini = first(L);
    while(next(P)!= first(L)){
        Q = firstch(P);
        i = 0;
        while(Q!= NULL){
            i = i + 1;
            Q = next(Q);
        }
        if(j >= i){
           mini = P;
           j = i;
        }
        P = next(P);
    }
    Q = firstch(P);
    i = 0;
    while(Q!= NULL){
        i = i + 1;
        Q = next(Q);
    }
    if(j >= i){
        mini = P;
        j = i;
    }
    cout<<"documen dengan kategori paling sedikit adalah : ";
    cout<< info(mini).namadoc;
    cout<<endl;
    cout<<"dengan kategori : ";
    showkategory(mini);
    cout<<endl;
    cout<<endl;
}
