#include "MLL.h"
#include <iostream>
using namespace std;

int main()
{
    listToko Ltoko;
    listProduk Lproduk;
    listSuplier Lsuplier;
    listPabrik Lpabrik;
    infotype_toko dataToko;
    infotype_produk dataProduk;
    infotype_suplier dataSuplier;
    infotype_pabrik dataPabrik;
    adrToko T, toko;
    adrSuplier S, suplier;
    adrProduk P,produk;
    adrPabrik PB,pabrik;
    int pilih;
    bool selesai = false;
    bool berhasil = false;
    string bagian = "menu awal";
    string a,b,c;

    dataDummy(Ltoko, Lproduk, Lsuplier, Lpabrik);
    cout << "===DATA TOKO BESERTA PRODUK DAN SUPLIER==="<<endl<<endl;
    showTokoAll(Ltoko);
    cout << "===DATA SUPLIER BESERTA PABRIK==="<<endl<<endl;
    showSuplierAll(Lsuplier);
    while (selesai == false ){
        if (bagian == "menu awal"){
        cout << "==================MENU==================="<<endl<<endl;
        cout << "==  1. MENAMBAHKAN DATA                =="<<endl<<endl;
        cout << "==  2. MENGHAPUS DATA                  =="<<endl<<endl;
        cout << "==  3. MENCARI DATA                    =="<<endl<<endl;
        cout << "==  4. MENAMPILKAN DATA                =="<<endl<<endl;
        cout << "==  5. MENAMPILKAN JUMLAH CHILD DATA   =="<<endl<<endl;
        cout << "==  0. KELUAR                          =="<<endl<<endl;
        cout << "========================================="<<endl<<endl;
        cout << "PILIH : ";
        cin >> pilih;;cout <<endl<<endl;
        while(pilih < 0  || pilih  >5){
                cout << "pilihan nomor " << pilih<< " tidak ada dalam menu, mohon pilih kembali"<<endl;
                cout << "PILIH : ";
                cin >> pilih;cout <<endl<<endl;
        }
        }
        if (pilih == 1 || bagian == "menu tambah data"){
            cout << "============MENAMBAHKAN DATA============"<<endl<<endl;
            cout << "==  1. DATA TOKO                      =="<<endl<<endl;
            cout << "==  2. DATA PRODUK                    =="<<endl<<endl;
            cout << "==  3. DATA SUPLIER                   =="<<endl<<endl;
            cout << "==  4. DATA PABRIK                    =="<<endl<<endl;
            cout << "==  5. PRODUK DAN SUPLIER UNTUK TOKO  =="<<endl<<endl;
            cout << "==  6. PABRIK YANG MENYUPLAI SUPLIER  =="<<endl<<endl;
            cout << "==  7. KEMBALI KE MENU SEBELUMNYA     =="<<endl<<endl;
            cout << "==  0. KELUAR                         =="<<endl<<endl;
            cout << "========================================"<<endl<<endl;
            cout << "PILIH : ";
            cin >> pilih;;cout <<endl<<endl;
            while(pilih < 0  || pilih > 7){
                    cout << "pilihan nomor " << pilih<< " tidak ada dalam menu, mohon pilih kembali"<<endl;
                    cout << "PILIH : ";
                    cin >> pilih;cout <<endl<<endl;
            }
            if (pilih == 1){
                cout << "=========DATA TOKO===================="<<endl<<endl;
                cout << "==  1. MASUKAN DATA DIBAGIAN AWAL   =="<<endl<<endl;
                cout << "==  2. MASUKAN DATA DIBAGIAN AKHIR  =="<<endl<<endl;
                cout << "==  3. KEMBALI KE MENU SEBELUMNYA   =="<<endl<<endl;
                cout << "==  0. KELUAR                       =="<<endl<<endl;
                cout << "======================================"<<endl<<endl;
                cout << "PILIH : ";
                cin >> pilih;;cout <<endl<<endl;
                while(pilih < 0 || pilih > 3){
                    cout << "pilihan nomor " << pilih<< " tidak ada dalam menu, mohon pilih kembali"<<endl;
                    cout << "PILIH : ";
                    cin >> pilih;cout <<endl<<endl;
                }
                if (pilih ==3){
                    bagian = "menu tambah data";
                } else if (pilih == 2 || pilih == 1){
                    cout << "MASUKAN NAMA, ALAMAT, DAN NOMOR TELFON TOKO SESUAI URUTAN: "<<endl;
                    cin >> dataToko.nama_toko >> dataToko.alamat>> dataToko.no_telfon;
                    toko = createElm_toko(dataToko);
                    bagian = "akhir";
                    if (pilih == 1){
                       InsertFirstToko(Ltoko,toko);
                        cout << "BERHASIL DITAMBAHKAN"<<endl<<endl;
                    } else {
                        InsertLastToko(Ltoko,toko);
                        cout << "BERHASIL DITAMBAHKAN"<<endl<<endl;
                    }
                }
            }else if (pilih == 2){
                cout << "MASUKAN NAMA, DAN JENIS PRODUK SESUAI URUTAN: "<<endl;
                cin >> dataProduk.nama_produk>>dataProduk.jenis;
                produk = createElm_produk(dataProduk);
                InsertLastProduk(Lproduk,produk);
                cout << "BERHASIL DITAMBAHKAN"<<endl<<endl;
                bagian = "akhir";
            }else if (pilih == 3){
                cout << "=========DATA SUPLIER================="<<endl<<endl;
                cout << "==  1. MASUKAN DATA DIBAGIAN AWAL   =="<<endl<<endl;
                cout << "==  2. MASUKAN DATA DIBAGIAN AKHIR  =="<<endl<<endl;
                cout << "==  3. KEMBALI KE MENU SEBELUMNYA   =="<<endl<<endl;
                cout << "==  0. KELUAR                       =="<<endl<<endl;
                cout << "======================================"<<endl<<endl;
                cout << "PILIH : ";
                cin >> pilih;;cout <<endl<<endl;
                while(pilih < 0 || pilih > 3){
                    cout << "pilihan nomor " << pilih<< " tidak ada dalam menu, mohon pilih kembali"<<endl;
                    cout << "PILIH : ";
                    cin >> pilih;cout <<endl<<endl;
                }
                if (pilih ==3){
                    bagian = "menu tambah data";
                } else if (pilih == 2 || pilih == 1){
                    cout << "MASUKAN NAMA, DAN NOMOR TELFON SUPLIER SESUAI URUTAN: "<<endl;
                    cin >> dataSuplier.nama_suplier >>dataSuplier.no_telfon;
                    suplier = createElm_suplier(dataSuplier);
                    bagian = "akhir";
                    if (pilih == 1){
                       InsertFirstSuplier(Lsuplier,suplier);
                       cout << "BERHASIL DITAMBAHKAN"<<endl<<endl;
                    } else {
                       InsertLastSuplier(Lsuplier,suplier);
                       cout << "BERHASIL DITAMBAHKAN"<<endl<<endl;
                    }

                }
            } else if (pilih == 4){
                cout << "MASUKAN NAMA, ALAMAT PABRIK SESUAI URUTAN: "<<endl;
                cin >> dataPabrik.nama_pabrik>> dataPabrik.alamat;
                pabrik = createElm_pabrik(dataPabrik);
                InsertLastPabrik(Lpabrik,pabrik);
                cout << "BERHASIL DITAMBAHKAN"<<endl<<endl;
                bagian = "akhir";
            } else if(pilih == 5){
                cout << "MASUKAN NAMA TOKO, PRODUK, DAN SUPLIER YANG INGIN DI BUAT RELASINYA SESUAI DENGAN URUTAN: "<<endl;
                cin >> a >> b>> c;
                InsertRelation(Ltoko,Lproduk,Lsuplier,a,b,c,berhasil);
                if (berhasil == true){
                    cout << "BERHASIL DITAMBAHKAN"<<endl<<endl;
                }
                bagian = "akhir";
            }else if (pilih == 6) {
                cout <<"MASUKAN NAMA SUPLIER DAN PABRIK YANG INGIN DIBUAT RELASINYA SESUAI DENGAN URUTAN: "<< endl;
                cin >> a >> b;
                InsertRelationS(Lsuplier,Lpabrik, a, b,berhasil);
                if (berhasil == true){
                    cout << "BERHASIL DITAMBAHKAN"<<endl<<endl;
                }
                bagian = "akhir";
            }else if (pilih == 7){
                bagian = "menu awal";
            }
        } else if (pilih == 2 || bagian == "menu hapus data"){
            cout << "============MENGHAPUS DATA=============="<<endl<<endl;
            cout << "==  1. DATA TOKO                      =="<<endl<<endl;
            cout << "==  2. DATA PRODUK                    =="<<endl<<endl;
            cout << "==  3. DATA SUPLIER                   =="<<endl<<endl;
            cout << "==  4. DATA PABRIK                    =="<<endl<<endl;
            cout << "==  5. DATA PRODUK PADA TOKO          =="<<endl<<endl;
            cout << "==  6. DATA SUPLIER PADA TOKO         =="<<endl<<endl;
            cout << "==  7. DATA PABRIK PADA SUPLIER       =="<<endl<<endl;
            cout << "==  8. KEMBALI KE MENU SEBELUMNYA     =="<<endl<<endl;
            cout << "==  0. KELUAR                         =="<<endl<<endl;
            cout << "========================================"<<endl<<endl;
            cout << "PILIH : ";
            cin >> pilih;;cout <<endl<<endl;
            while(pilih < 0  || pilih > 8){
                    cout << "pilihan nomor " << pilih<< " tidak ada dalam menu, mohon pilih kembali"<<endl;
                    cout << "PILIH : ";
                    cin >> pilih;cout <<endl<<endl;
            }
            if (pilih == 1){
                cout << "MASUKAN NAMA TOKO YANG INGIN DIHAPUS "<<endl;
                cin >> a;cout<<endl;
                deleteToko(Ltoko,a);
                bagian = "akhir";
            } else if (pilih == 2){
                cout << "MASUKAN NAMA PRODUK YANG INGIN DIHAPUS "<<endl;
                cin >> a;cout<<endl;
                deleteProduk(Lproduk,Ltoko,a);
                bagian = "akhir";
            } else if (pilih == 3){
                cout << "MASUKAN NAMA SUPLIER YANG INGIN DIHAPUS "<<endl;
                cin >> a;cout<<endl;
                deleteSuplier(Lsuplier,Ltoko,a);
                bagian = "akhir";
            }else if (pilih ==4){
                cout << "MASUKAN NAMA PABRIK YANG INGIN DIHAPUS "<<endl;
                cin >> a;cout<<endl;
                deletePabrik(Lpabrik,Lsuplier,a);
                bagian = "akhir";
            }else if(pilih == 5){
                cout << "MASUKAN NAMA PRODUK DAN JUGA TOKONYA "<<endl;
                cin >> a>>b;cout<<endl;
                deleteChildProdukDiToko(Ltoko,Lproduk,a,b);
                bagian = "akhir";
            }else if(pilih ==6){
                cout << "MASUKAN NAMA SUPLIER DAN JUGA TOKONYA "<<endl;
                cin >> a>>b;cout<<endl;
                deleteChildSuplierDiToko(Ltoko,Lsuplier,a,b);
                bagian = "akhir";
            }else if(pilih ==7){
                cout << "MASUKAN NAMA PABRIK DAN JUGA SUPLIERNYA "<<endl;
                cin >> a>>b;cout<<endl;
                deleteChildPabrikDiSuplier(Lsuplier,Lpabrik,a,b);
                bagian = "akhir";
            }else if (pilih == 8){
                bagian = "menu awal";
            }
        }else if(pilih ==3){
            cout << "============MENCARI DATA================"<<endl<<endl;
            cout << "==  1. DATA TOKO                      =="<<endl<<endl;
            cout << "==  2. DATA PRODUK                    =="<<endl<<endl;
            cout << "==  3. DATA SUPLIER                   =="<<endl<<endl;
            cout << "==  4. DATA PABRIK                    =="<<endl<<endl;
            cout << "==  5. PRODUK PADA SUATU TOKO         =="<<endl<<endl;
            cout << "==  6. SUPLIER PADA SUATU TOKO        =="<<endl<<endl;
            cout << "==  7. PABRIK YANG MENYUPLAI SUPLIER  =="<<endl<<endl;
            cout << "==  8. KEMBALI KE MENU SEBELUMNYA     =="<<endl<<endl;
            cout << "==  0. KELUAR                         =="<<endl<<endl;
            cout << "========================================"<<endl<<endl;
            cout << "PILIH : ";
            cin >> pilih;;cout <<endl<<endl;
            while(pilih < 0  || pilih > 8){
                    cout << "pilihan nomor " << pilih<< " tidak ada dalam menu, mohon pilih kembali"<<endl;
                    cout << "PILIH : ";
                    cin >> pilih;cout <<endl<<endl;
            }
            if (pilih == 1){
                cout << "MASUKAN NAMA TOKO YANG INGIN DICARI "<< endl;
                cin >> a;cout << endl<<endl;
                toko = search_toko(Ltoko,a);
                if (toko != NULL){
                    cout << "TOKO TERDAPAT PADA DATA"<<endl;
                    cout << info(toko).nama_toko<<endl<<info(toko).alamat << endl<<info(toko).no_telfon<<endl;
                    showTokoRelasi(Ltoko,a);
                } else{
                    cout << "TOKO TIDAK TERDAPAT PADA DATA"<< endl;
                }
                bagian = "akhir";
            } else if (pilih == 2){
                cout << "MASUKAN NAMA PRODUK YANG INGIN DICARI "<< endl;
                cin >> a;cout << endl<<endl;
                produk = search_produk(Lproduk,a);
                if (produk != NULL){
                    cout << "PRODUK TERDAPAT PADA DATA"<<endl;
                    cout << info(produk).nama_produk << endl<< info(produk).jenis<<endl;
                } else{
                    cout << "PRODUK TIDAK TERDAPAT PADA DATA"<< endl;
                }
                bagian = "akhir";
            } else if (pilih == 3){
                cout << "MASUKAN NAMA SUPLIER YANG INGIN DICARI "<< endl;
                cin >> a;cout << endl<<endl;
                suplier = search_suplier(Lsuplier,a);
                if (suplier != NULL){
                    cout << "SUPLIER TERDAPAT PADA DATA"<<endl;
                    cout << info(suplier).nama_suplier << endl<< info(suplier).no_telfon<<endl;
                } else{
                    cout << "SUPLIER TIDAK TERDAPAT PADA DATA"<< endl;
                }
                bagian = "akhir";
            } else if (pilih == 4){
                cout << "MASUKAN NAMA PABRIK YANG INGIN DICARI "<< endl;
                cin >> a;cout << endl<<endl;
                pabrik = search_pabrik(Lpabrik,a);
                if (pabrik != NULL){
                    cout << "PABRIK TERDAPAT PADA DATA"<<endl;
                    cout << info(pabrik).nama_pabrik << endl<< info(pabrik).alamat<<endl;
                } else{
                    cout << "PABRIK TIDAK TERDAPAT PADA DATA"<< endl;
                }
                bagian = "akhir";
            } else if (pilih == 5){
                cout << "MASUKAN NAMA TOKO DAN PRODUK PADA TOKO TERSEBUT YANG INGIN DICARI "<<endl;
                cin >> b >> c;
                cout <<endl<<endl;
                showTokoByProduk(Ltoko,Lproduk,b,c);
                bagian = "akhir";
            }else if (pilih == 6){
                cout << "MASUKAN NAMA TOKO DAN SUPLIER PADA TOKO TERSEBUT YANG INGIN DICARI "<<endl;
                cin >> b >> c;
                cout <<endl<<endl;
                showTokoBySuplier(Ltoko,Lsuplier,b,c);
                bagian = "akhir";
            }else if (pilih == 7){
                cout << "MASUKAN NAMA SUPLIER DAN PABRIK DARI SUPLIER TERSEBUT YANG INGIN DICARI"<<endl;
                cin >> b >> c;
                cout <<endl<<endl;
                showSuplierByPabrik(Lsuplier,Lpabrik,b,c);
                bagian = "akhir";
            }else if (pilih == 8){
                bagian = "menu awal";
            }
        }else if(pilih == 4){
            cout << "===========MENAMPILKAN DATA=================="<<endl<<endl;
            cout << "==  1. DATA TOKO                           =="<<endl<<endl;
            cout << "==  2. DATA PRODUK                         =="<<endl<<endl;
            cout << "==  3. DATA SUPLIER                        =="<<endl<<endl;
            cout << "==  4. DATA PABRIK                         =="<<endl<<endl;
            cout << "==  5. TOKO BESERTA PRODUK DAN SUPLIERNYA  =="<<endl<<endl;
            cout << "==  6. SUPLIER BESERTA PABRIKNYA           =="<<endl<<endl;
            cout << "==  7. KEMBALI KE MENU SEBELUMNYA          =="<<endl<<endl;
            cout << "==  0. KELUAR                              =="<<endl<<endl;
            cout << "============================================="<<endl<<endl;
            cout << "PILIH : ";
            cin >> pilih;;cout <<endl<<endl;
            while(pilih < 0  || pilih > 7){
                cout << "pilihan nomor " << pilih<< " tidak ada dalam menu, mohon pilih kembali"<<endl;
                cout << "PILIH : ";
                cin >> pilih;cout <<endl<<endl;
            }
            if (pilih == 1){
                cout << "BERIKUT TOKO-TOKO YANG BERADA PADA DATA"<<endl<<endl;
                showToko(Ltoko);
                bagian = "akhir";
            }else if (pilih == 2){
                cout << "BERIKUT PRODUK-PRODUK YANG BERADA PADA DATA"<<endl<<endl;
                showProduk(Lproduk);
                bagian = "akhir";
            }else if (pilih == 3){
                cout << "BERIKUT SUPLIER-SUPLIER YANG BERADA PADA DATA"<<endl<<endl;
                showSuplier(Lsuplier);
                bagian = "akhir";
            }else if (pilih == 4){
                cout << "BERIKUT PABRIK-PABRIK YANG BERADA PADA DATA"<<endl<<endl;
                showPabrik(Lpabrik);
                bagian = "akhir";
            }else if (pilih == 5){
                cout << "BERIKUT TOKO-TOKO BESERTA PRODUK-PRODUK DAN SUPLIER-SUPLIERNYA"<<endl<<endl;
                showTokoAll(Ltoko);
                bagian = "akhir";
            }else if (pilih == 6){
                cout << "BERIKUT SUPLIER-SUPLIER BERESTA PABRIK-PABRIKNYA"<<endl<<endl;
                showSuplierAll(Lsuplier);
                bagian = "akhir";
            }else if(pilih == 7){
                bagian = "menu awal";
            }
        }else if (pilih == 5){
            cout << "===============DATA SUPLIER==================="<<endl<<endl;
            cout << "==  1. JUMLAH PRODUK DAN SUPLIER PADA TOKO  =="<<endl<<endl;
            cout << "==  2. JUMLAH PABRIK PADA SUPLIER           =="<<endl<<endl;
            cout << "==  3. KEMBALI KE MENU SEBELUMNYA           =="<<endl<<endl;
            cout << "==  0. KELUAR                               =="<<endl<<endl;
            cout << "=============================================="<<endl<<endl;
            cout << "PILIH : ";
            cin >> pilih;;cout <<endl<<endl;
            while(pilih < 0 || pilih > 3){
                cout << "pilihan nomor " << pilih<< " tidak ada dalam menu, mohon pilih kembali"<<endl;
                cout << "PILIH : ";
                cin >> pilih;cout <<endl<<endl;
            }
            if (pilih == 1){
                cout << "MASUKAN NAMA TOKO YANG INGIN DILIHAT JUMLAH PRODUK DAN SUPLIERNYA"<<endl<<endl;
                cin >> a;cout<<endl<<endl;
                jumlahChildPadaToko(Ltoko,a);
                bagian == "akhir";
            }else if(pilih == 2){
                cout << "MASUKAN NAMA SUPLIER YANG INGIN DILIHAT JUMLAH PABRIKNYA"<<endl<<endl;
                cin >> a;cout <<endl<<endl;
                jumlahChildPadaSuplier(Lsuplier,a);
                bagian == "akhir";
            }else if (pilih == 3){
                bagian = "menu awal";
            }
        }
        if (bagian == "akhir" && pilih != 0){
            cout<<endl;
            cout << "INGIN BALIK KE MENU AWAL? "<<endl;
            cout << "1.IYA"<<endl;
            cout << "2.TIDAK"<<endl;
            cout << "PILIHLAH DENGAN ANGKA: ";
            cin >> pilih;cout <<endl<<endl;
            while(pilih != 1 && pilih != 2){
                    cout << "pilihan nomor " << pilih<< " tidak ada dalam menu, mohon pilih kembali"<<endl;
                    cout << "PILIHLAH DENGAN ANGKA : ";
                    cin >> pilih;cout <<endl<<endl;
            }
            if (pilih == 1){
                bagian = "menu awal";
            } else if (pilih == 2){
                selesai = true;
            }
        } else if(pilih == 0){
            selesai = true;
        }
    }
    return 0;
}
