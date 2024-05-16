#include "MLL.h"

void createlistRelation(listRelation &L){
    first(L) = NULL;
}

void createlistToko(listToko &L){
    first(L) = NULL;
}

void createlistProduk(listProduk &L){
    first(L) = NULL;
}

void createlistRelationS(listRelationS &L){
    first(L) = NULL;
}
void createlistSuplier(listSuplier &L){
    first(L) = NULL;
}

void createlistPabrik(listPabrik &L){
    first(L) = NULL;
}

adrToko createElm_toko(infotype_toko x){
    adrToko p;
    p = new elm_toko;
    info(p) = x;
    next(p) = NULL;
    first(relation(p))= NULL;
    return p;
}

adrProduk createElm_produk(infotype_produk x){
    adrProduk p;
    p = new elm_produk;
    info(p) = x;
    next(p) = NULL;
    return p;
}

adrSuplier createElm_suplier(infotype_suplier x){
    adrSuplier p;
    p = new elm_suplier;
    info(p) = x;
    next(p) = NULL;
    first(relationS(p))=NULL;
    return p;
}

adrPabrik createElm_pabrik(infotype_pabrik x){
    adrPabrik p;
    p = new elm_pabrik;
    info(p) = x;
    next(p) = NULL;
    return p;
}
adrRelation createElm_relation(adrProduk produk, adrSuplier suplier){
    adrRelation p;
    p = new elm_relation;
    produk(p) = produk;
    suplier(p) = suplier;
    next(p) = NULL;
    return p;
}

adrRelationS createElm_relationS(adrPabrik pabrik){
    adrRelationS p;
    p = new elm_relationS;
    pabrik(p) = pabrik;
    next(p) = NULL;
    return p;
}

void InsertLastToko(listToko &L, adrToko P){
    if(first(L) == NULL){
        first(L) = P;
    } else {
        adrToko Q = first(L);
        while(next(Q) != NULL){
            Q = next(Q);
        }
        next(Q) = P;
    }
}

void InsertLastProduk(listProduk &L, adrProduk P){
    if(first(L) == NULL){
        first(L) = P;
    } else {
        adrProduk Q = first(L);
        while(next(Q) != NULL){
            Q = next(Q);
        }
        next(Q) = P;
    }
}

void InsertLastSuplier(listSuplier &L, adrSuplier P){
    if(first(L) == NULL){
        first(L) = P;
    } else {
        adrSuplier Q = first(L);
        while(next(Q) != NULL){
            Q = next(Q);
        }
        next(Q) = P;
    }
}

void InsertLastPabrik(listPabrik &L, adrPabrik P){
    if(first(L) == NULL){
        first(L) = P;
    } else {
        adrPabrik Q = first(L);
        while(next(Q) != NULL){
            Q = next(Q);
        }
        next(Q) = P;
    }
}

void InsertLastRelation(listRelation &L, adrRelation P){
    if(first(L) == NULL){
        first(L) = P;
    } else {
        adrRelation Q = first(L);
        while(next(Q) != NULL){
            Q = next(Q);
        }
        next(Q) = P;
    }
}

void InsertLastRelationS(listRelationS &L, adrRelationS P){
    if(first(L) == NULL){
        first(L) = P;
    } else {
        adrRelationS Q = first(L);
        while(next(Q) != NULL){
            Q = next(Q);
        }
        next(Q) = P;
    }
}

void InsertFirstToko(listToko &L, adrToko P){
    if(first(L)== NULL){
        first(L) = P;
    } else {
        next(P) = first(L);
        first(L) = P;
    }
}

void InsertFirstSuplier(listSuplier &L, adrSuplier P){
    if(first(L)== NULL){
        first(L) = P;
    } else {
        next(P) = first(L);
        first(L) = P;
    }
}

void InsertRelation(listToko &Ltoko, listProduk &Lproduk, listSuplier &Lsuplier, string toko, string produk, string suplier,bool &berhasil){
    adrToko pToko = search_toko(Ltoko, toko);
    if (pToko != NULL){
    adrRelation check = first(relation(pToko));
        if (check == NULL){
            adrProduk pProduk = search_produk(Lproduk, produk);
            adrSuplier pSuplier = search_suplier(Lsuplier, suplier);
            if (pProduk != NULL && pSuplier != NULL){
                adrRelation p = createElm_relation(pProduk, pSuplier);
                InsertLastRelation(relation(pToko), p);
            }
        } else {
            while (check != NULL && info(produk(check)).nama_produk != produk){
                check = next(check);
            }
            if (check != NULL && info(produk(check)).nama_produk == produk && info(suplier(check)).nama_suplier != suplier){
                cout << "tidak boleh mengambil produk yang sama dengan suplier yang berbeda"<< endl;
            } else if (check != NULL && info(produk(check)).nama_produk == produk && info(suplier(check)).nama_suplier == suplier){
                cout << "produk dengan suplier tersebut sudah ada" << endl;
            }else{
                adrProduk pProduk = search_produk(Lproduk, produk);
                adrSuplier pSuplier = search_suplier(Lsuplier, suplier);
                if (pProduk != NULL && pSuplier != NULL){
                    adrRelation p = createElm_relation(pProduk, pSuplier);
                    InsertLastRelation(relation(pToko), p);
                    berhasil = true;
                }else{
                    cout << "PRODUK ATAU SUPLIER TIDAK TERDAPAT PADA DATA "<<endl<<endl;
                }
            }
        }
    } else{
        cout << "TOKO TIDAK TERDAPAT PADA DATA"<<endl<<endl;
    }

}

void InsertRelationS(listSuplier &Lsuplier, listPabrik &Lpabrik, string suplier, string pabrik,bool &berhasil){
    int i = 1;
    adrSuplier pSuplier = search_suplier(Lsuplier, suplier);
    if (pSuplier != NULL){
    adrRelationS pRelationS = first(relationS(pSuplier));
        while (pRelationS != NULL){
            pRelationS = next(pRelationS);
            i++;
        }
        if ( i <= 2){
            adrPabrik pPabrik= search_pabrik(Lpabrik, pabrik);
            if (pPabrik != NULL){
                adrRelationS p = createElm_relationS(pPabrik);
                InsertLastRelationS(relationS(pSuplier), p);
                berhasil = true;
            }else{
                cout << "PABRIK TIDAK TERDAPAT PADA DATA "<<endl<<endl;
            }
        } else {
            cout << "pabrik dari suplier ini sudah ada 2" <<endl;
        }
    }
}

adrToko search_toko(listToko L, string nama_toko){
    adrToko p = first(L);
    while (p != NULL && info(p).nama_toko != nama_toko){
        p = next(p);
    }
    return p;
}

adrProduk search_produk(listProduk L,string nama_produk){
    adrProduk p = first(L);
    while (p != NULL && info(p).nama_produk != nama_produk){
        p = next(p);
    }
    return p;
}

adrSuplier search_suplier(listSuplier L,string nama_suplier){
    adrSuplier p = first(L);
    while (p != NULL && info(p).nama_suplier != nama_suplier){
        p = next(p);
    }
    return p;
}

adrPabrik search_pabrik(listPabrik L,string nama_pabrik){
    adrPabrik p = first(L);
    while (p != NULL && info(p).nama_pabrik != nama_pabrik){
        p = next(p);
    }
    return p;
}

void showToko(listToko L){
    adrToko p = first(L);
    int i=1;
    while (p!= NULL){
        cout << endl << i << "." << endl << "nama toko: " << info(p).nama_toko << endl << "alamat: " << info(p).alamat << endl << "no.hp: "<< info(p).no_telfon <<endl;
        p = next(p);
        i++;
    }
}

void showProduk(listProduk L){
    adrProduk p = first(L);
    int i=1;
    while (p!= NULL){
        cout << endl << i << "." << endl << "nama produk: " << info(p).nama_produk << endl << "jenis: " << info(p).jenis << endl;
        p = next(p);
        i++;
    }
}

void showSuplier(listSuplier L){
    adrSuplier p = first(L);
    int i=1;
    while (p!= NULL){
        cout << endl << i << "." << endl << "nama suplier: " << info(p).nama_suplier << endl << "no.hp: " << info(p).no_telfon << endl;
        p = next(p);
        i++;
    }
}

void showPabrik(listPabrik L){
    adrPabrik p = first(L);
    int i=1;
    while (p!= NULL){
        cout << endl << i << "." << endl << "nama pabrik: " << info(p).nama_pabrik << endl << "alamat: " << info(p).alamat << endl;
        p = next(p);
        i++;
    }
}

void showTokoRelasi(listToko L, string toko){
    int i = 1;
    adrToko pToko = search_toko(L, toko);
    if (pToko != NULL){
        adrRelation pRelation = first(relation(pToko));
        while (pRelation != NULL){
            cout << endl << i << "." << endl << "nama produk: " << info(produk(pRelation)).nama_produk << endl << "nama suplier: " << info(suplier(pRelation)).nama_suplier << endl;
            i++;
            pRelation = next(pRelation);
        }
    }
    cout << endl;
}

void showSuplierRelasiS(listSuplier L, string suplier){
    int i = 1;
    adrSuplier pSuplier = search_suplier(L, suplier);
    adrRelationS pRelationS = first(relationS(pSuplier));
    while (pRelationS != NULL){
        cout << endl << i << "." << endl << "nama pabrik: " << info(pabrik(pRelationS)).nama_pabrik << endl << "alamat: " << info(pabrik(pRelationS)).alamat << endl;
        i++;
        pRelationS = next(pRelationS);
    }
    cout << endl;
}

void showTokoAll(listToko L){
    adrToko p = first(L);
    int i=1;
    while (p!= NULL){
        cout << endl << "Toko " << i << ":" << endl << "nama toko: " << info(p).nama_toko << endl << "alamat: " << info(p).alamat << endl << "no.hp: "<< info(p).no_telfon <<endl;
        cout << endl <<"Data toko " << info(p).nama_toko << ":" << endl;
        showTokoRelasi(L, info(p).nama_toko);
        p = next(p);
        i++;
    }
}

void showSuplierAll(listSuplier L){
    adrSuplier p = first(L);
    int i=1;
    while (p!= NULL){
        cout << endl << "Suplier " << i << ":" << endl << "nama suplier: " << info(p).nama_suplier << endl << "no.hp: " << info(p).no_telfon << endl;
        cout << endl << "Distributor dari pabrik: " << endl;
        showSuplierRelasiS(L, info(p).nama_suplier);
        p = next(p);
        i++;
    }
}

void showTokoByProduk(listToko Ltoko, listProduk Lproduk, string namaToko, string produk){
    adrToko pToko = search_toko(Ltoko,namaToko);
    if (pToko != NULL){
        adrProduk pProduk = search_produk(Lproduk, produk);
        adrRelation pRelation, p;
        pRelation = first(relation(pToko));
        bool ketemu = false;
        while (pRelation != NULL && ketemu == false){
            if (produk(pRelation) == pProduk){
                cout << "produk " << produk << " " << "ADA pada toko " << namaToko<< endl<<endl;
                showTokoRelasi(Ltoko,namaToko);
                ketemu = true;
            } else {
                pRelation = next(pRelation);
            }
        }
        if (ketemu == false){
            cout << "produk " << produk << " " << "TIDAK ADA pada toko " << namaToko<< endl<<endl;
        }
    } else {
        cout << "TOKO TIDAK ADA PADA DATA"<< endl;
    }
}

void showTokoBySuplier(listToko Ltoko, listSuplier Lsuplier, string namaToko,string suplier){
    adrToko pToko = search_toko(Ltoko,namaToko);
    if (pToko != NULL){
        adrSuplier pSuplier= search_suplier(Lsuplier, suplier);
        adrRelation pRelation, p;
        pRelation = first(relation(pToko));
        bool ketemu = false;
        while (pRelation != NULL && ketemu == false){
             if (suplier(pRelation) == pSuplier){
                cout << "suplier " << suplier << " " << "menyuplai produk ke toko " << namaToko<< endl<<endl;
                showTokoRelasi(Ltoko,namaToko);
                ketemu = true;
            } else {
                pRelation = next(pRelation);
            }
        }
        if (ketemu == false){
            cout << "suplier " << suplier << " " << "TIDAK menyuplai produk ke toko " << namaToko<< endl<<endl;
        }
    } else {
        cout << "TOKO TIDAK ADA PADA DATA"<< endl;
    }
}

void showSuplierByPabrik(listSuplier Lsuplier, listPabrik Lpabrik, string namaSuplier, string pabrik){
    adrSuplier pSuplier = search_suplier(Lsuplier,namaSuplier);
    if (pSuplier != NULL){
        adrPabrik pPabrik= search_pabrik(Lpabrik, pabrik);
        adrRelationS pRelationS, p;
        bool ketemu = false;
        pRelationS = first(relationS(pSuplier));
        while (pRelationS != NULL&&ketemu == false){
            if (pabrik(
                       pRelationS) == pPabrik){
                cout << "suplier " << namaSuplier << " " << "mendapatkan barang dari pabrik " << pabrik << endl<<endl;
                showSuplierRelasiS(Lsuplier,namaSuplier);
                ketemu = true;
            } else {
                pRelationS = next(pRelationS);
            }
        }
        if (ketemu == false){
            cout << "suplier " << namaSuplier << " " << "TIDAK mendapatkan barang dari pabrik " << pabrik<< endl<<endl;
        }
    } else {
        cout << "SUPLIER TIDAK ADA PADA DATA"<< endl;
    }
}

void dataDummy(listToko &Ltoko, listProduk &Lproduk, listSuplier &Lsuplier, listPabrik &Lpabrik){
    bool berhasil = false;
    adrToko pToko;
    infotype_toko xToko;
    createlistToko(Ltoko);
    xToko.nama_toko = "prima";
    xToko.alamat = "bojongsoang";
    xToko.no_telfon = "081261659883";
    pToko = createElm_toko(xToko);
    InsertLastToko(Ltoko, pToko);
    xToko.nama_toko = "jasa_tegar";
    xToko.alamat = "cibaduyut";
    xToko.no_telfon = "081485739284";
    pToko = createElm_toko(xToko);
    InsertLastToko(Ltoko, pToko);
    xToko.nama_toko = "makmur_jaya";
    xToko.alamat = "dipatiukur";
    xToko.no_telfon = "087591837571";
    pToko = createElm_toko(xToko);
    InsertLastToko(Ltoko, pToko);
    xToko.nama_toko = "sukses_abadi";
    xToko.alamat = "antapani";
    xToko.no_telfon = "084743758174";
    pToko = createElm_toko(xToko);
    InsertLastToko(Ltoko, pToko);

    adrProduk pProduk;
    infotype_produk xProduk;
    createlistProduk(Lproduk);
    xProduk.nama_produk = "oreo";
    xProduk.jenis = "makanan";
    pProduk = createElm_produk(xProduk);
    InsertLastProduk(Lproduk, pProduk);
    xProduk.nama_produk = "sapu";
    xProduk.jenis = "peralatan";
    pProduk = createElm_produk(xProduk);
    InsertLastProduk(Lproduk, pProduk);
    xProduk.nama_produk = "kopi_instan";
    xProduk.jenis = "minuman";
    pProduk = createElm_produk(xProduk);
    InsertLastProduk(Lproduk, pProduk);
    xProduk.nama_produk = "air_mineral";
    xProduk.jenis = "minuman";
    pProduk = createElm_produk(xProduk);
    InsertLastProduk(Lproduk, pProduk);

    adrSuplier pSuplier;
    infotype_suplier xSuplier;
    createlistSuplier(Lsuplier);
    xSuplier.nama_suplier = "yoim_store";
    xSuplier.no_telfon = "081265730184";
    pSuplier = createElm_suplier(xSuplier);
    InsertLastSuplier(Lsuplier, pSuplier);
    xSuplier.nama_suplier = "blanja_grosir";
    xSuplier.no_telfon = "085613246213";
    pSuplier = createElm_suplier(xSuplier);
    InsertLastSuplier(Lsuplier, pSuplier);
    xSuplier.nama_suplier = "mitra_unit";
    xSuplier.no_telfon = "086574843321";
    pSuplier = createElm_suplier(xSuplier);
    InsertLastSuplier(Lsuplier, pSuplier);
    xSuplier.nama_suplier = "jaya_utama";
    xSuplier.no_telfon = "088897564790";
    pSuplier = createElm_suplier(xSuplier);
    InsertLastSuplier(Lsuplier, pSuplier);

    adrPabrik pPabrik;
    infotype_pabrik xPabrik;
    createlistPabrik(Lpabrik);
    xPabrik.nama_pabrik = "Lestari_Maha_Putra";
    xPabrik.alamat = "padalarang";
    pPabrik = createElm_pabrik(xPabrik);
    InsertLastPabrik(Lpabrik, pPabrik);
    xPabrik.nama_pabrik = "Royal_Abadi_Sejahtera";
    xPabrik.alamat = "ngamprah";
    pPabrik = createElm_pabrik(xPabrik);
    InsertLastPabrik(Lpabrik, pPabrik);
    xPabrik.nama_pabrik = "Ateja_Multi";
    xPabrik.alamat = "gadobangkong";
    pPabrik = createElm_pabrik(xPabrik);
    InsertLastPabrik(Lpabrik, pPabrik);
    xPabrik.nama_pabrik = "Daya_Pratama_Lestari";
    xPabrik.alamat = "laksana_mekar";
    pPabrik = createElm_pabrik(xPabrik);
    InsertLastPabrik(Lpabrik, pPabrik);

    InsertRelation(Ltoko, Lproduk, Lsuplier, "prima", "oreo", "blanja_grosir",berhasil);
    InsertRelation(Ltoko, Lproduk, Lsuplier, "prima", "kopi_instan", "blanja_grosir",berhasil);
    InsertRelation(Ltoko, Lproduk, Lsuplier, "prima", "air_mineral", "yoim_store",berhasil);
    InsertRelation(Ltoko, Lproduk, Lsuplier, "jasa_tegar", "sapu", "jaya_utama",berhasil);
    InsertRelation(Ltoko, Lproduk, Lsuplier, "jasa_tegar", "kopi_instan", "mitra_unit",berhasil);
    InsertRelation(Ltoko, Lproduk, Lsuplier, "makmur_jaya", "oreo", "mitra_unit",berhasil);
    InsertRelation(Ltoko, Lproduk, Lsuplier, "makmur_jaya", "sapu", "yoim_store",berhasil);
    InsertRelation(Ltoko, Lproduk, Lsuplier, "makmur_jaya", "air_mineral", "jaya_utama",berhasil);
    InsertRelation(Ltoko, Lproduk, Lsuplier, "sukses_abadi", "oreo", "yoim_store",berhasil);
    InsertRelation(Ltoko, Lproduk, Lsuplier, "sukses_abadi", "sapu", "yoim_store",berhasil);
    InsertRelation(Ltoko, Lproduk, Lsuplier, "sukses_abadi", "air_mineral", "jaya_utama",berhasil);

    InsertRelationS(Lsuplier, Lpabrik, "yoim_store", "Lestari_Maha_Putra",berhasil);
    InsertRelationS(Lsuplier, Lpabrik, "yoim_store", "Ateja_Multi",berhasil);
    InsertRelationS(Lsuplier, Lpabrik, "blanja_grosir", "Ateja_Multi",berhasil);
    InsertRelationS(Lsuplier, Lpabrik, "blanja_grosir", "Daya_Pratama_Lestari",berhasil);
    InsertRelationS(Lsuplier, Lpabrik, "mitra_unit", "Lestari_Maha_Putra",berhasil);
    InsertRelationS(Lsuplier, Lpabrik, "jaya_utama", "Royal_Abadi_Sejahtera",berhasil);
    InsertRelationS(Lsuplier, Lpabrik, "jaya_utama", "Daya_Pratama_Lestari",berhasil);
}

void deleteElmToko(listToko &L, adrToko &p){
    if (p == first(L)){
        first(L) = next(p);
        next(p) = NULL;
     } else {
        adrToko prec = first(L);
        while (next(prec) != p){
            prec = next(prec);
        }
        next(prec) = next(p);
        next(p) = NULL;
     }
}

void deleteElmProduk(listProduk &L, adrProduk &p){
    if (p == first(L)){
        first(L) = next(p);
        next(p) = NULL;
     } else {
        adrProduk prec = first(L);
        while (next(prec) != p){
            prec = next(prec);
        }
        next(prec) = next(p);
        next(p) = NULL;
     }
}

void deleteElmSuplier(listSuplier &L, adrSuplier &p){
    if (p == first(L)){
        first(L) = next(p);
        next(p) = NULL;
     } else {
        adrSuplier prec = first(L);
        while (next(prec) != p){
            prec = next(prec);
        }
        next(prec) = next(p);
        next(p) = NULL;
     }
}

void deleteElmPabrik(listPabrik &L, adrPabrik &p){
    if (p == first(L)){
        first(L) = next(p);
        next(p) = NULL;
     } else {
        adrPabrik prec = first(L);
        while (next(prec) != p){
            prec = next(prec);
        }
        next(prec) = next(p);
        next(p) = NULL;
     }
}

void deleteElmRelation(listRelation &L, adrRelation &p){
     if (p == first(L)){
        first(L) = next(p);
        next(p) = NULL;
        produk(p) = NULL;
        suplier(p) = NULL;
     } else {
        adrRelation prec = first(L);
        while (next(prec) != p){
            prec = next(prec);
        }
        next(prec) = next(p);
        next(p) = NULL;
        produk(p) = NULL;
        suplier(p) = NULL;
     }
}

void deleteElmRelationS(listRelationS &L, adrRelationS &p){
     if (p == first(L)){
        first(L) = next(p);
        next(p) = NULL;
        pabrik(p) = NULL;
     } else {
        adrRelationS prec = first(L);
        while (next(prec) != p){
            prec = next(prec);
        }
        next(prec) = next(p);
        next(p) = NULL;
        pabrik(p) = NULL;
     }
}

void deleteToko(listToko &L, string toko){
    adrToko pToko = search_toko(L, toko);
    if (pToko != NULL){
        adrRelation pRelation, p;
        pRelation = first(relation(pToko));
        while (pRelation != NULL){
            p = pRelation;
            pRelation = next(pRelation);
            deleteElmRelation(relation(pToko), p);
        }
        deleteElmToko(L, pToko);
        cout << "BERHASIL DIHAPUS"<<endl<<endl;
    }else {
        cout << "TOKO TERSEBUT TIDAK ADA"<<endl<<endl;
    }
}

void deleteProduk(listProduk &Lproduk, listToko &Ltoko, string produk){
    deleteRelationByProduk(Ltoko, Lproduk, produk);
    adrProduk p = search_produk(Lproduk, produk);
    if (p != NULL){
        deleteElmProduk(Lproduk, p);
        cout << "BERHASIL DIHAPUS"<<endl<<endl;
    }else{
        cout << "PRODUK TERSEBUT TIDAK ADA"<<endl<<endl;
    }
}

void deleteSuplier(listSuplier &Lsuplier, listToko &Ltoko, string suplier){
    adrSuplier pSuplier = search_suplier(Lsuplier, suplier);
    if (pSuplier != NULL){
        adrRelationS pRelationS, p;
        pRelationS = first(relationS(pSuplier));
        while (pRelationS != NULL){
            p = pRelationS;
            pRelationS = next(pRelationS);
            deleteElmRelationS(relationS(pSuplier), p);
        }

        deleteRelationBySuplier(Ltoko, Lsuplier, suplier);

        deleteElmSuplier(Lsuplier, pSuplier);
        cout << "BERHASIL DIHAPUS"<<endl<<endl;
    }else {
        cout << "SUPLIER TERSEBUT TIDAK ADA"<<endl<<endl;
    }
}

void deletePabrik(listPabrik &Lpabrik, listSuplier &Lsuplier, string pabrik){
    deleteRelationS(Lsuplier, Lpabrik, pabrik);
    adrPabrik p = search_pabrik(Lpabrik, pabrik);
    if (p != NULL){
        deleteElmPabrik(Lpabrik, p);
        cout << "BERHASIL DIHAPUS"<<endl<<endl;
    }else{
        cout << "PABRIK TERSEBUT TIDAK ADA"<<endl<< endl;
    }
}
void deleteChildProdukDiToko(listToko &Ltoko, listProduk Lproduk, string produk,string toko){
    bool ketemu = false;
    adrToko pToko = search_toko(Ltoko,toko);
    if (pToko != NULL){
        adrProduk pProduk = search_produk(Lproduk, produk);
        if (pProduk != NULL){
            adrRelation pRelation, p;
            pRelation = first(relation(pToko));
            while (pRelation != NULL){
                if (produk(pRelation) == pProduk){
                    p = pRelation;
                    pRelation = next(pRelation);
                    deleteElmRelation(relation(pToko), p);
                    ketemu = true;
                } else {
                    pRelation = next(pRelation);
                }
            }
            if (ketemu == true){
                cout << "BERHASIL TERHAPUS "<<endl<<endl;
            }else{
                cout << "DALAM TOKO TERSEBUT TIDAK ADA PRODUK YANG DICARI "<<endl<<endl;
            }
        }else{
            cout << "PRODUK TERSEBUT TIDAK ADA"<<endl<<endl;
        }
    }else{
        cout << "TOKO TERSEBUT TIDAK ADA"<<endl<<endl;
    }
}
void deleteChildSuplierDiToko(listToko &Ltoko, listSuplier Lsuplier, string suplier,string toko){
    bool ketemu = false;
    adrToko pToko = search_toko(Ltoko,toko);
    if (pToko != NULL){
        adrSuplier pSuplier= search_suplier(Lsuplier, suplier);
        if (pSuplier != NULL){
            adrRelation pRelation, p;
            pRelation = first(relation(pToko));
            while (pRelation != NULL){
                if (suplier(pRelation) == pSuplier){
                    p = pRelation;
                    pRelation = next(pRelation);
                    deleteElmRelation(relation(pToko), p);
                    ketemu = true;
                } else {
                    pRelation = next(pRelation);
                }
            }
            if (ketemu == true){
                cout << "BERHASIL TERHAPUS "<<endl<<endl;
            }else{
                cout << "DALAM TOKO TERSEBUT TIDAK ADA SUPLIER YANG DICARI "<<endl<<endl;
            }
        }else{
            cout << "SUPLIER TERSEBUT TIDAK ADA"<<endl<<endl;
        }
    }else{
        cout << "TOKO TERSEBUT TIDAK ADA"<<endl<<endl;
    }
}

void deleteChildPabrikDiSuplier(listSuplier &Lsuplier, listPabrik Lpabrik, string pabrik,string suplier){
    bool ketemu = false;
    adrSuplier pSuplier = search_suplier(Lsuplier,suplier);
    if (pSuplier != NULL){
        adrPabrik pPabrik= search_pabrik(Lpabrik, pabrik);
        if (pPabrik != NULL){
            adrRelationS pRelationS, p;

            pRelationS = first(relationS(pSuplier));
            while (pRelationS != NULL){
                if (pabrik(pRelationS) == pPabrik){
                    p = pRelationS;
                    pRelationS = next(pRelationS);
                    deleteElmRelationS(relationS(pSuplier), p);
                    ketemu = true;
                } else {
                    pRelationS = next(pRelationS);
                }
            }
            if (ketemu == true){
                cout << "BERHASIL TERHAPUS "<<endl<<endl;
            }else{
                cout << "DALAM SUPLIER TERSEBUT TIDAK ADA PABRIK YANG DICARI "<<endl<<endl;
            }
        }else{
            cout << "PABRIK TERSEBUT TIDAK ADA"<<endl<<endl;
        }
    }else{
        cout << "SUPLIER TERSEBUT TIDAK ADA"<<endl<<endl;
    }
}

void deleteRelationByProduk(listToko &Ltoko, listProduk Lproduk, string produk){
    adrToko pToko = first(Ltoko);
    adrProduk pProduk = search_produk(Lproduk, produk);
    if (pProduk != NULL){
        adrRelation pRelation, p;

        while (pToko != NULL){
            pRelation = first(relation(pToko));
            while (pRelation != NULL){
                if (produk(pRelation) == pProduk){
                    p = pRelation;
                    pRelation = next(pRelation);
                    deleteElmRelation(relation(pToko), p);
                } else {
                    pRelation = next(pRelation);
                }
            }
            pToko = next(pToko);
        }
    }
}

void deleteRelationBySuplier(listToko &Ltoko, listSuplier Lsuplier, string suplier){
    adrToko pToko = first(Ltoko);
    adrSuplier pSuplier= search_suplier(Lsuplier, suplier);
    if (pSuplier != NULL){
        adrRelation pRelation, p;

        while (pToko != NULL){
            pRelation = first(relation(pToko));
            while (pRelation != NULL){
                if (suplier(pRelation) == pSuplier){
                    p = pRelation;
                    pRelation = next(pRelation);
                    deleteElmRelation(relation(pToko), p);
                } else {
                    pRelation = next(pRelation);
                }
            }
            pToko = next(pToko);
        }
    }
}

void deleteRelationS(listSuplier &Lsuplier, listPabrik Lpabrik, string pabrik){
    adrSuplier pSuplier = first(Lsuplier);
    adrPabrik pPabrik= search_pabrik(Lpabrik, pabrik);
    if (pPabrik != NULL){
        adrRelationS pRelationS, p;
        while (pSuplier != NULL){
            pRelationS = first(relationS(pSuplier));
            while (pRelationS != NULL){
                if (pabrik(pRelationS) == pPabrik){
                    p = pRelationS;
                    pRelationS = next(pRelationS);
                    deleteElmRelationS(relationS(pSuplier), p);
                } else {
                    pRelationS = next(pRelationS);
                }
            }
            pSuplier = next(pSuplier);
        }
    }
}

void jumlahChildPadaToko(listToko L, string toko){
    int i = 0;
    adrToko pToko = search_toko(L, toko);
    if (pToko != NULL){
        adrRelation pRelation = first(relation(pToko));
        while (pRelation != NULL){
            i++;
            pRelation = next(pRelation);
        }
        cout << "jumlah produk beserta suplier pada toko tersebut ada " << i << endl<< endl;
    }else{
        cout << "toko tersebut tidak ada"<<endl<<endl;
    }
}
void jumlahChildPadaSuplier(listSuplier L, string suplier){
    int i = 0;
    adrSuplier pSuplier = search_suplier(L, suplier);
    if (pSuplier != NULL){
        adrRelationS pRelationS = first(relationS(pSuplier));
        while (pRelationS != NULL){
            i++;
            pRelationS = next(pRelationS);
        }
        cout << "jumlah pabrik yang memberi produk pada suplier tersebut ada " << i<< endl<< endl;
    }else{
        cout << "suplier tersebut tidak ada"<<endl<<endl;
    }
}
//void deleteElm(list &L,adr &p){
//    adr prec = first(L);
//    if (p == first(L)){
//        first(L) = next(p);
//        next(p) = NULL;
//    } else{
//        while (next(prec) != p){
//            prec = next(prec);
//        }
//        if (next(p) == NULL){
//            next(prec) = NULL;
//        } else {
//            next(prec) = next(p);
//            next(p) = NULL;
//        }
//    }
//}
//void deleteParentToko(list &LT,adr &p,string nama_toko){
//    adr r;
//    p = search_toko(LT,nama_toko);
//    if (p != NULL){
//        while (first(relation(p)) != NULL){
//            r = first(relation(p);
//            first(relation(p)) = next(r);
//            next(r) = NULL;
//        }
//        void delete(LT,p);
//    } else{
//        cout << "toko tidak ada dalam list"<<endl;
//    }
//}
//void deleteParentSuplier(list &listToko, list &ListSuplier,adr &p,string nama_suplier){
//    adr r,relasiToko;
//    adr toko = first(listToko);
//    p = search_suplier(ListSuplier,nama_suplier);
//    if (p != NULL){
//        while (toko != NULL){
//            relasiToko = first(relation(toko));
//            while (relasiToko != NULL){
//                if (next_suplier(relasiToko)) == p ){
//                    deleteElm(relation(toko),p);
//                }
//                relasiToko = next(relasiToko)
//            }
//            toko = next(toko);
//        }
//        while (first(relationS(p)) != NULL){
//            r = first(relationS(p);
//            first(relationS(p)) = next(r);
//            next(r) = NULL;
//        }
//    } else {
//        cout << "suplier tidak ada dalam list"<<endl;
//    }
//}
