# Topological Sort
Permasalahan yang ingin diselesaikan dalam tugas kecil ini adalah perancangan rencana kuliah yang diimplementasikan melalui pendekatan topological sorting.
Topological sort ada pengurutan node-node dalam graf secara linear dengan aturan jika ada edge yang menghubungkan node v ke node w, maka node v akan selalu ditaruh sebelum node w.

Algoritma decrease and conquer yang digunakan pada program ini adalah DFS modifikasi untuk menyelesaikan permasalahan perancangan rencana kuliah. Langkah-langkahnya adalah:
1. Jika sebuah node belum dikunjungi, tandai node tersebut.
2. Lalu untuk setiap tetangga dari node tersebut, cari yang belum dikunjungi dan jika ada lakukan DFS modifikasi ini.
3. Setelah melakukan DFS hingga tetangganya sudah dikunjungi semua (atau jika tetangganya tidak ada), maka masukkan node tersebut ke suatu vector/array, misal namanya order, yang akan menyimpan urutan node secara terbalik.
4. Lakukan proses ini hingga setiap node berhasil dikunjungi
5. Reverse vector/array order yang telah berisi semua node dengan urutan terbalik, sehingga urutannya menjadi sesuai yang kita inginkan.

## Requirement program yang dibutuhkan untuk mengcompile: 
Minimal c++11 dengan compiler g++4.9

## Cara mengcompile :
Buka folder src, lalu ketikkan command
```bash
g++ -o [namaoutput] 13519105-main.cpp 13519105-modul.cpp
```
Maka akan terbentuk file binary baru dengan nama [namaoutput]

## Cara menjalankan binary program
Dari hasil compile di atas, ketikkan command
```bash
./[namaoutput]
```
Atau bisa menggunakan binary yang sudah dicompile dalam folder bin, dan ketikkan command
```bash
./main
```
Cara di atas dilakukan dalam OS linux, untuk windows tinggal double click file binarynya.

## Author
Nama	: Widya Anugrah Putra

NIM	: 13519105

Kelas	: K-02