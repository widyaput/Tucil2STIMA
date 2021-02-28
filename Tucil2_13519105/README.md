# _Topological Sort_ dengan pendekatan _decrease and conquer_
Permasalahan yang ingin diselesaikan dalam tugas kecil ini adalah penyusunan rencana kuliah yang diimplementasikan dengan _topological sorting_ melalui pendekatan _decrease and conquer_.
_Topological sort_ adalah pengurutan _node-node_ dalam graf secara linear dengan aturan jika ada _edge_ yang menghubungkan _node_ v ke _node_ w, maka _node_ v akan selalu ditaruh sebelum _node_ w.

Algoritma decrease and conquer yang digunakan pada program ini adalah DFS modifikasi untuk menyelesaikan permasalahan perancangan rencana kuliah. Langkah-langkahnya adalah:
1. Jika sebuah _node_ belum dikunjungi, tandai _node_ tersebut.
2. Lalu untuk setiap tetangga dari _node_ tersebut, cari yang belum dikunjungi dan jika ada lakukan DFS modifikasi ini.
3. Setelah melakukan DFS hingga tetangganya sudah dikunjungi semua (atau jika tetangganya tidak ada), maka masukkan node tersebut ke suatu vector/array, misal namanya order, yang akan menyimpan urutan _node_ secara terbalik.
4. Lakukan proses ini hingga setiap node berhasil dikunjungi
5. _Reverse_ vector/array order yang telah berisi semua _node_ dengan urutan terbalik, sehingga urutannya menjadi sesuai yang kita inginkan.

## Requirement yang dibutuhkan program: 
Minimal c++11 dengan compiler g++4.

Penulisan file uji teks yang benar agar program tidak error.

## Cara mengcompile :
Buka folder src, lalu ketikkan command
```bash
g++ -o [namaoutput] 13519105-main.cpp 13519105-modul.cpp
```
Maka akan terbentuk file _binary_ baru dengan nama [namaoutput]

## Cara menjalankan binary program
Dari hasil _compile_ di atas, ketikkan _command_
```bash
./[namaoutput]
```
Atau bisa menggunakan _binary_ yang sudah di-_compile_ dalam folder bin, dan ketikkan _command_
```bash
./main
```
Cara di atas dilakukan pada OS linux, untuk Windows/Mac tinggal double click file _binary_-nya.

## Input file teks
Ketika program telah dijalankan, program akan meminta nama file input yang akan diuji. Perhatikan bahwa:
1. File teks harus ditaruh dalam folder test
2. Setiap baris dalam file teks yang akan diuji **tidak boleh ada yang kosong** (entah itu di awal, tengah atau akhir). Karena dalam mengambil setiap baris, _author_ mengimplementasikan algoritma getline yang lebih baik daripada ifstream.good(). Hanya saja kekurangan getline adalah fungsi tersebut tidak bisa membaca baris yang kosong. Jika didapati error semacam ini, maka perlu dicek lagi apakah dalam file teks terdapat baris kosong. Biasanya dalam teks editor tertentu baris kosong tidak terlihat, jadi coba edit file teks dalam beberapa editor.
```bash
terminate called after throwing an instance of 'std::out_of_range'
  what():  basic_string::substr: __pos (which is 18446744073709551615) > this->size() (which is 2)
Aborted (core dumped)
```
3. Setiap baris berisi hubungan mata kuliah dan prerequisitenya yang dipisahkan dengan tanda koma (",") dan diakhiri dengan tanda titik (".")

## _Author_
Nama	: Widya Anugrah Putra

NIM	: 13519105

Kelas	: K-02