#ifndef MLL_H_INCLUDED
#define MLL_H_INCLUDED
#include <iostream>
using namespace std;
#define info(P) P->info
#define next(P) P->next
#define first(P) P.first
#define produk(P) P->produk
#define suplier(P) P->suplier
#define pabrik(P) P->pabrik
#define relation(P) P->relation
#define relationS(P) P->relationS
#define banyak_produk(P) P->banyak_produk

typedef struct elm_relation *adrRelation;
typedef struct elm_toko *adrToko;
typedef struct elm_produk *adrProduk;
typedef struct elm_relationS *adrRelationS;
typedef struct elm_suplier *adrSuplier;
typedef struct elm_pabrik *adrPabrik;

struct elm_relation {
    adrProduk produk;
    adrSuplier suplier;
    adrRelation next;
};

struct listRelation {
    adrRelation first;
};

struct infotype_toko {
    string nama_toko, alamat, no_telfon;
};

struct elm_toko{
    infotype_toko info;
    adrToko next;
    listRelation relation;
};

struct listToko{
    adrToko first;
};

struct infotype_produk {
    string nama_produk, jenis;
};

struct elm_produk{
    infotype_produk info;
    adrProduk next;
};

struct listProduk {
    adrProduk first;
};

struct elm_relationS {
    adrPabrik pabrik;
    adrRelationS next;
};

struct listRelationS {
    adrRelationS first;
};

struct infotype_suplier {
    string nama_suplier, no_telfon;
};

struct elm_suplier {
    infotype_suplier info;
    adrSuplier next;
    listRelationS relationS;
};

struct listSuplier {
    adrSuplier first;
};

struct infotype_pabrik {
    string nama_pabrik, alamat;
};

struct elm_pabrik {
    infotype_pabrik info;
    adrPabrik next;
};

struct listPabrik {
    adrPabrik first;
};

void createlistRelation(listRelation &L);
void createlistToko(listToko &L);
void createlistProduk(listProduk &L);
void createlistRelationS(listRelationS &L);
void createlistSuplier(listSuplier &L);
void createlistPabrik(listPabrik &L);
adrToko createElm_toko(infotype_toko x);
adrProduk createElm_produk(infotype_produk x);
adrSuplier createElm_suplier(infotype_suplier x);
adrPabrik createElm_pabrik(infotype_pabrik x);
adrRelation createElm_relation(adrProduk produk, adrSuplier suplier);
adrRelationS createElm_relationS(adrPabrik pabrik);
void InsertLastToko(listToko &L, adrToko P);
void InsertLastProduk(listProduk &L, adrProduk P);
void InsertLastSuplier(listSuplier &L, adrSuplier P);
void InsertLastPabrik(listPabrik &L, adrPabrik P);
void InsertLastRelation(listRelation &L, adrRelation P);
void InsertLastRelationS(listRelationS &L, adrRelationS P);
void InsertFirstToko(listToko &L, adrToko P);
void InsertFirstSuplier(listSuplier &L, adrSuplier P);
void InsertRelation(listToko &Ltoko, listProduk &Lproduk, listSuplier &Lsuplier, string toko, string produk, string suplier,bool &berhasil);
void InsertRelationS(listSuplier &Lsuplier, listPabrik &Lpabrik, string suplier, string pabrik,bool &berhasil);
adrToko search_toko(listToko L, string nama_toko);
adrProduk search_produk(listProduk L,string nama_produk);
adrSuplier search_suplier(listSuplier L,string nama_suplier);
adrPabrik search_pabrik(listPabrik L,string nama_pabrik);
void showToko(listToko L);
void showProduk(listProduk L);
void showSuplier(listSuplier L);
void showPabrik(listPabrik L);
void showTokoRelasi(listToko L, string toko);
void showSuplierRelasiS(listSuplier L, string suplier);
void showTokoAll(listToko L);
void showSuplierAll(listSuplier L);
void showTokoByProduk(listToko Ltoko, listProduk Lproduk,string namaToko, string produk);
void showTokoBySuplier(listToko Ltoko, listSuplier Lsuplier, string namaToko, string suplier);
void showSuplierByPabrik(listSuplier Lsuplier, listPabrik Lpabrik, string namaSuplier, string pabrik);
void dataDummy(listToko &Ltoko, listProduk &Lproduk, listSuplier &Lsuplier, listPabrik &Lpabrik);
void deleteElmToko(listToko &L, adrToko &p);
void deleteElmProduk(listProduk &L, adrProduk &p);
void deleteElmSuplier(listSuplier &L, adrSuplier &p);
void deleteElmPabrik(listPabrik &L, adrPabrik &p);
void deleteElmRelation(listRelation &L, adrRelation &p);
void deleteElmRelationS(listRelationS &L, adrRelationS &p);
void deleteToko(listToko &L, string toko);
void deleteProduk(listProduk &Lproduk, listToko &Ltoko, string produk);
void deleteSuplier(listSuplier &Lsuplier, listToko &Ltoko, string suplier);
void deletePabrik(listPabrik &Lpabrik, listSuplier &Lsuplier, string pabrik);
void deleteChildProdukDiToko(listToko &Ltoko, listProduk Lproduk, string produk,string toko);
void deleteChildSuplierDiToko(listToko &Ltoko, listSuplier Lsuplier, string suplier,string toko);
void deleteChildPabrikDiSuplier(listSuplier &Lsuplier, listPabrik Lpabrik, string pabrik,string suplier);
void deleteRelationByProduk(listToko &Ltoko, listProduk Lproduk, string produk);
void deleteRelationBySuplier(listToko &Ltoko, listSuplier Lsuplier, string suplier);
void deleteRelationS(listSuplier &Lsuplier, listPabrik Lpabrik, string pabrik);
void jumlahChildPadaToko(listToko L, string toko);
void jumlahChildPadaSuplier(listSuplier L, string suplier);
//void delete(list &L,adr &p);
//void deleteParentToko(list &LT,adr &p,string nama_toko);
//void deleteParentSuplier(list &listToko, list &ListSuplier,adr &p,string nama_suplier);
//void deleteChild(list &L,adr &p);
//void deleteRelation(list &LT);
//void deleteRelationS(list &LS);
#endif // MLL_H_INCLUDED
