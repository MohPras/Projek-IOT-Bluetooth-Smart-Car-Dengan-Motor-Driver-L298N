# Projek-IOT-Bluetooth-Smart-Car-Dengan-Motor-Driver-L298N

Mengenai Projek
Robot ini adalah robot smart car yang dapat dikendalikan dengan menggunakan aplikasi android. Kita dapat menggerakan, mengarahkan, dan menghentikan dengan perantara tombol pada aplikasi android. Komunikasi antara Smartphone dan Robot menggunakan modul Bluetooth HC-06.

ALAT DAN BAHAN
1.	Arduino uno 
2.	Modul Driver Motor L298N
3.	Modul Bluetooth HC-06
4.	Baterai 9V 2 buah
5.	Chassis robot.
6.	Motor DC 5V 2 buah.
7.	Konektor jack to terminal 
8.	Resistor 6K8
9.	Resistor 3K3
10.	Halft breadboard
11.	Kabel Jumper
12.	4 buah roda kecil.

DESIGN RANGKAIAN
![image](https://user-images.githubusercontent.com/108654517/209518589-0e9db159-5b27-46fd-9316-1efd7c553969.png)

CARA MERANGKAI KOMPONEN
1.	Pasang semua komponen pada Chassis
2.	Hubungkan pin VCC Modul HC-06 ke pin VCC 5V Arduino uno.
3.	Hubungkan pin GND Modul HC-06 ke pin GND Arduino uno.
4.	Hubungkan pin TXD Modul HC-06 ke pin 3 digital Arduino uno.
5.	Hubungkan satu kaki resistor 6K8 pada pin GND Modul HC-06.
6.	Hubungkan satu kaki resistor 6K8 pada pin RXD Modul HC-06.
7.	Hubungkan satu kaki resistor 3K3 pada pin RXD Modul HC-06.
8.	Hubungkan satu kaki resistor 3K3 pada pin 4 digital Arduino uno.
9.	Hubungkan kancing baterai 9V dengan baeterai 9V.
10.	Hubungkan pin GND Arduino uno dengan pin GND modul driver motor L298N.
11.	Hubungkan Motor DC dengan pin output motor kiri modul driver motor L298N.
12.	Hubungkan Motor DC lainya dengan pin output motor kiri modul driver motor L298N.
13.	Hubungkan pin 11 arduino uno pada pin input control motor IN1.
14.	Hubungkan pin 10 arduino uno pada pin input control motor IN2.
15.	Hubungkan pin 9 arduino uno pada pin input control motor IN3.
16.	Hubungkan pin 6 arduino uno pada pin input control motor IN2
17.	Hubungkan Arduino dengan pc.
18.	Buat program codingnya.
19.	Compile coding.
20.	Upload program ke arduno uno.
21.	Copot kabel Usb.
22.	Lalu hubungkan jack DC terminal yang sudah terhubung dengan baterai 9V ke Arduino uno.
23.	Hubungkan pin positif kancing baterai 9V dengan pin power 12V driver motor L28N.

PENJELASAN KODE PROGRAM
1.	Input library software serial. Library ini digunakan karena kita akan menggunakan pin digital 3 sebagai pin RX dan pin digital 4 sebagai pin TX Arduino uno. 
2.	Inisialisasi varibel arah yang bertipe string.
3.	Definisikan nama untuk setiap pin dari motor DC. 
4.	Pin digital 11 diberi nama motorKIri_1, pin digital 10 diberi nama motorKiri_2, pin digital 9 diberi nama motorKanan_1 dan pin digital 6 diberi nama  motorKanan _2.
5.	Pada void setup atur baud rate untuk komunikasi serial antara pc dan Arduino juga antara Arduino dengan Bluethoth. Baud keduanya sebesar 9600.
6.	Atur arah I/O untuk pin yang akan digunakan. sensorKiri, sensorKanan, motorKiri_1, motorKiri_2, motorKanan_1 dan motorKanan_2. Semua didefinisikan sebagai pin OUTPUT
7.	Di awal void loop buat kondisi perulangan while dimana statement didalam perulangan ini akan terus dieksekusi selama ada bytes di buffer serial. Jika ada bytes di buffer serial, maka data akan dibaca per byte dan disimpan ke variable masukan, kemuadia Setelah itu karater dari variable masukan akan disimpan pada variabel arah yang bertipe string. Jika tidak ada bytes didalam buffer serial yang dapat dibaca maka secara otomatis keluar dari perulangan.
8.	Pada selanjutnya buat pengkndisian if, diamana kondisi yang diperiksa adalah panjang dari variable arah, jika variable arah ada isinya dengan kata lain panjangnya lebih dari 0, maka selanjutnya varibael arah akan diseleksi Kembali isinya untuk menentukan apakah isi variable arah sama dengan maju, kiri, kanan, mundur dan berhenti.
9.	Jika arah sama dengan isinya maju maka nilai analog 100 (untuk kecepatan motor PMW) akan dituliskan ke motorKiri_1 dan motorKanan_1 sedangkan motorkiri_2 dan motorkanan_2 diberi nilai analog 0. Kondisi ini akan membuat mobil bergerak maju.
10.	Jika arah sama dengan isinya kiri maka nilai analog 100 (untuk kecepatan motor PMW) akan dituliskan ke motorKanan_1 sedangkan motorKiri_1, motorkiri_2 dan motorkanan_2 diberi nilai analog 0. Kondisi ini akan membuat mobil bergerak ke arah kiri.
11.	Jika arah sama dengan isinya kanan maka nilai analog 100 (untuk kecepatan motor PMW) akan dituliskan ke motorKiri_1 sedangkan motorKiri_2, motorkanan_1 dan motorkanan_2 diberi nilai analog 0. Kondisi ini akan membuat mobil bergerak ke arah kanan.
12.	Jika arah sama dengan isinya mundur maka nilai analog 100 (untuk kecepatan motor PMW) akan dituliskan ke motorKiri_2 dan motorKanan_2 sedangkan motorkiri_1 dan motorkanan_1 diberi nilai analog 0. Kondisi ini akan membuat mobil bergerak mundur.
13.	Jika arah sama dengan isinya berhenti maka nilai analog 100 (untuk kecepatan motor PMW) tidak akan dituliskan. Sebagai gantinya untuk motorKiri_1, motorKiri_2 dan motorKanan_1, motorKanan_2 akan diberikan nialai 0.
14.	Di akhir void loop isi varibael arah kosongkan Kembali.
