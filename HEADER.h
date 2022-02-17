#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <iostream>
using namespace std;


#define first(L)  L.first
#define firstch(P) (P)->firstch
#define lastch(P) (P)->lastch
#define info(P) (P)->info
#define next(P) (P)->next
#define prev(P) (P)->prev



struct document{
    int nmrdoc;
    string namadoc;
    int tahundoc;
};
typedef document infotype_p;
typedef string infotype_c;
typedef struct elmList_p *adr_p;
typedef struct elmList_c *adr_c;

struct elmList_p{
    infotype_p info;
    adr_p next;
    adr_p prev;
    adr_c firstch;
    adr_c lastch;
};
struct elmList_c{
    infotype_c info;
    adr_c next;
    adr_c prev;
};
struct List{
    adr_p first;
};
void menu();
void creatList(List &L);
adr_p alokasidoc(int nmr, string judul, int tahun);
void insertFirst(List &L , adr_p P);
void insertAfter(List &L , adr_p prec , adr_p P);
void insertLast(List &L , adr_p P);
void insertUrutDoc(List &L , adr_p P );
void deleteFirst(List &L , adr_p &P);
void deleteAfter(List &L , adr_p prec , adr_p &P);
void deleteLast(List &L , adr_p &P);
void hapus_doc(List &L ,string nama, adr_p &P);
void showdoc(List L);
adr_p findDoc(List L, string data);

//function procedur anak

adr_c creatkategori(infotype_c data);
void insertKategori(adr_p P , adr_c C);
void deleteFirstkategori(adr_p P , adr_c &C);
void deleteafterkategory(adr_c prec , adr_c &C);
void deleteLastkategory(adr_p P , adr_c &C);
adr_c findkategory(string judul , adr_p P);
void deletekategory(List &L , adr_p P, adr_c &C , string nama);
void showkategory(adr_p P);
void printList(List L);

void kategoriterbanyak(List L);
void kategorisedikit(List L);
void docdarikategori(List L, string judul);
#endif // HEADER_H_INCLUDED
