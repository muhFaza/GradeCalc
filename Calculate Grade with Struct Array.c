//2502141990
//Muhammad Faza
//Compiler - Dev C++
//Algoprog TP-2
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

void menu();
char select;
int idx = 0;

struct Nilai{
  float hadir;
  float tugas;
  float quiz;
  float forum;
  float uas;
};

struct Data{
  int nim;
  char nama[150];
  char matkul[50];
  struct Nilai skor;
}dat[99];

void inputdata(){ //no1

  int nim, i;

  printf("#%d\n", idx+1);

  printf("Nomor Induk Mahasiswa (NIM): ");
  scanf("%d", &nim); getchar();

  for(i = 0; i < idx; i++){
    if(dat[i].nim == nim){
      printf("NIM sudah terdaftar!"); getchar();
      system("cls");
      return;
    }
  }

  dat[idx].nim = nim;

  printf("Nama Mahasiswa: ");
  scanf("%[^\n]", dat[idx].nama); getchar();

  printf("Mata Kuliah: ");
  scanf("%[^\n]", dat[idx].matkul); getchar();

  //validation();

  idx++;
  printf("\n\nData berhasil ditambah!\n"); getchar();
  system("cls");
}

void inputnilai(){ //no2
  char nama[150];
  int validasi = 0;
  int i = 0;
  printf("Nama Mahasiswa: ");
  scanf("%[^\n]", nama); getchar();

  for(i; i < idx; i++){
    if(strcmpi(nama, dat[i].nama) == 0){
      validasi = 1;
      break;
    }
  }
  if(validasi == 0){
    printf("\nData tidak ditemukan..");
    getchar();
    system("cls");
    return;
  }

  printf("#%d\n", i+1);
  printf("1. Nilai Hadir: ");
  scanf("%f", &dat[i].skor.hadir); getchar();

  printf("\n2. Nilai Tugas: ");
  scanf("%f", &dat[i].skor.tugas); getchar();

  printf("\n3. Nilai Quiz: ");
  scanf("%f", &dat[i].skor.quiz); getchar();

  printf("\n4. Nilai Keaktifan Forum: ");
  scanf("%f", &dat[i].skor.forum); getchar();

  printf("\n5. Nilai UAS: ");
  scanf("%f", &dat[i].skor.uas); getchar();

  printf("\n\nData berhasil ditambah!\n"); getchar();
  system("cls");
}

char *calculation(float h, float t, float q, float f, float u){
  int nilai = (h*0.1) + (t*0.2) + (q*0.1) + (f*0.1) + (u*0.5);
  if(nilai <= 100 && nilai >= 90){
    return "A (LULUS)\n\n";
  }
  else if(nilai <= 89 && nilai >= 80){
    return "B (LULUS)\n\n";
  }
  else if(nilai <= 79 && nilai >= 70){
    return "C (LULUS)\n\n";
  }
  else if(nilai <= 69 && nilai >= 60){
    return "D (LULUS)\n\n";
  }
  else if(nilai <= 59 && nilai >= 50){
    return "E (TIDAK LULUS)\n\n";
  }
  else if(nilai < 50){
    return"F (TIDAK LULUS / BELUM ADA NILAI)\n\n";
  }
}

void outputnilai(){ //no3
  int i;

  if(idx == 0){
    printf("Data belum ada.."); getchar();
    system("cls");
    return;
  }

  for(i = 0; i < idx; i++){
    printf("#%d", i+1);
    printf("\nNIM: %d", dat[i].nim);
    printf("\nNama Mahasiswa: %s", dat[i].nama);
    printf("\nNilai: %s", calculation(dat[i].skor.hadir,
    dat[i].skor.tugas,dat[i].skor.quiz,dat[i].skor.forum,dat[i].skor.uas));
  }
  printf("Tekan enter untuk melanjutkan..");
  getchar();
  system("cls");
}

void menu(){
  while(1){

  printf("Program Hitung Nilai Mahasiswa\n");
  printf("==============================");

  printf("\n1. Input data mahasiswa (NIM, Nama & Matkul)");
  printf("\n2. Input Nilai");
  printf("\n3. Output Nilai dan status");
  printf("\n4. Exit");


  printf("\n\nMasukkan Input: ");
  scanf("%c", &select); getchar();

    if (select == '1') {
      system("cls");inputdata();
    }
    else if(select == '2') {
        system("cls");inputnilai();
    }
    else if(select == '3'){
        system("cls");outputnilai();
    }
    else if(select == '4')break;
    else {
    printf("Input tidak dikenal."); getchar();
    system("cls");
  }
}
}

int main(){
  menu();

  return 0;
}
