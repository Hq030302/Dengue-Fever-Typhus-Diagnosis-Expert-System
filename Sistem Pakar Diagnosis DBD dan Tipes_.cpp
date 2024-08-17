/*
(C) 2022 - Adhimas Wahyu_082011233011_Maliky Syailendra H.S._082011233053 - Sistem Pakar
    untuk Mendiagnosis Penyakit DBD dan Tipes
*/
#include <iostream.h>
#include <stdlib.h>
#include <fstream.h>
#include <iomanip.h>
#include <conio.h>

#define bobot_P1 0.8
#define bobot_P2 0.8


struct gejala{
	char jenis[100];
	float bobotP[2];
};
struct gejala G[12];
void input_JenisGejala();
void input_BobotGejala();
char nama[32];
int usia;
void diagnosis();
float min(float arr[], int n);
float sum(float arr[], int n);

int main(){
	start:
   system("cls");

   input_JenisGejala();
	input_BobotGejala();

   int pil;
   cout << "Aplikasi Diagnosis Penyakit Demam Berdarah dan Tipes" << endl;
	cout << "===== Menu =====" << endl;
   cout << " 1. Diagnosis sekarang!" << endl;
   cout << " 2. Keluar" << endl;
   cout << "Pilihan: "; cin >> pil;
   cout << endl << endl;
   switch (pil){
   	case 1:{
         registrasi:
         int pil1;
      	cout << "Diagnosis Penyakit Demam Berdarah dan Tipes" << endl;
         cout << " 1. Registrasi" << endl;
         cout << " 2. Kembali" << endl;
         cout << "Pilihan: "; cin >> pil1;
      	cout << endl << endl;
         switch (pil1){
         	case 1:{
            	cin.ignore();
               system("cls");
            	cout << "===== Registrasi =====" << endl;
               cout << "Data Pasien:" << endl;
               cout << "Nama: "; cin.getline(nama,sizeof(nama));
               cout << "Usia: "; cin >> usia;
               cout << endl << endl;

               system("cls");
               diagnosis();

         		getch();
            }

            case 2:{
            	goto start;
            }

            default:{
            	cout << "Pilihan tidak tersedia";
               cout << endl << endl;
         		goto registrasi;
            }
         }
      }

      case 2:{
      	cout << setw(70) << "Copyright (C) 2022 - Adhimas Wahyu_082011233011_Maliky Syailendra H.S._082011233053 - Sistem Pakar Diagnosis Demam Berdarah dan Tipes";
      	cout << endl << endl;
         cout << "Press any button to exit ...";
         getch();
         exit(1);
      }

      default:{
      	cout << "Pilihan tidak tersedia";
         getch();
         goto start;
      }
   }
   getch();
   return 0;
}

void input_JenisGejala(){
	ifstream inputfile("Jenis Gejala.txt");
   for(int i = 0; i < 12; i++){
   	inputfile.getline(G[i].jenis, sizeof(G[i].jenis));
   }

   /*for(int i = 0; i < 12; i++){
   	cout << "G" << (i+1) << " :: " << G[i].jenis << endl;
   }
   cout << endl;*/
}

void input_BobotGejala(){
	ifstream inputfile("Bobot Gejala.txt");
   for(int i = 0; i < 12; i++){
   	for(int j = 0; j < 2; j++){
      	inputfile >> G[i].bobotP[j];
		}
   }

   /*cout << "Gejala" << setw(15) << "Bobot P1" << setw(15) << "Bobot P2" << endl;
   for(int i = 0; i < 12; i++){
   	cout << setw(5) << "G" << (i+1) << setw(15) << G[i].bobotP[0] << setw(15) << G[i].bobotP[1] << endl;
   }
   cout << endl;*/
}

void diagnosis(){
   char j[10];
   float YP1[6], NP1[6];
   float YP2[7], NP2[7];
   float bobotP1 = bobot_P1, bobotP2 = bobot_P2;
   float CYP1, CNP1, CYP2, CNP2;
   float MBP1, MDP1, MBP2, MDP2;
   float CF;

   pertanyaan:
	cout << "Diagnosis Penyakit Demam Berdarah dan Tipes" << endl;
   cout << "Jawablah pertanyaan berikut ini! (Mohon Capslock dimatikan)" << endl << endl;
   cout << "1. Apakah Anda demam? Y/T" << endl;
   cout << "Jawaban: "; cin >> j[0];
   cout << endl;
   if(j[0] == 'Y' || j[0] == 'y'){
      cout << "2. Anda demam secara" << endl;
      cout << "   a. tiba-tiba selama 2-7 hari       b. bertahap selama +-2 minggu" << endl;
      cout << "Jawaban: "; cin >> j[1];
      cout << endl;
      cout << "3. Berapa suhunya?" << endl;
      cout << "   a. >40 derajat                     b. 39-40 derajat" << endl;
      cout << "Jawaban: "; cin >> j[2];
      cout << endl;

      //terindikasi P1 (DBD)
      if(j[1] == 'a' && j[2] == 'a'){
      	cout << "4. Apakah pada kulit Anda terdapat ruam merah? Y/T" << endl;
         cout << "Jawaban: "; cin >> j[3];
         cout << endl;
         cout << "5. Apakah Anda mengalami sakit kepala? Y/T" << endl;
         cout << "Jawaban: "; cin >> j[4];
         cout << endl;
         cout << "6. Apakah Anda mengalami nyeri otot? Y/T" << endl;
         cout << "Jawaban: "; cin >> j[5];
         cout << endl;

         //perhitungan tingkat kepercayaan
         if(j[3] == 'y' && j[4] == 'y' && j[5] == 'y'){
         	YP1[0] = G[0].bobotP[0];	NP1[0] = 0;
            YP1[1] = G[1].bobotP[0];   NP1[1] = 0;
            YP1[2] = G[3].bobotP[0];   NP1[2] = 0;
            YP1[3] = G[5].bobotP[0];   NP1[3] = 0;
            YP1[4] = G[7].bobotP[0];   NP1[4] = 0;
            YP1[5] = G[8].bobotP[0];   NP1[5] = 0;
         }
         else if(j[3] == 'y' && j[4] == 'y' && j[5] == 't'){
         	YP1[0] = G[0].bobotP[0];	NP1[0] = 0;
            YP1[1] = G[1].bobotP[0];   NP1[1] = 0;
            YP1[2] = G[3].bobotP[0];   NP1[2] = 0;
            YP1[3] = G[5].bobotP[0];   NP1[3] = 0;
            YP1[4] = G[7].bobotP[0];   NP1[4] = 0;
            YP1[5] = 0;   NP1[5] = G[8].bobotP[0];
         }
         else if(j[3] == 'y' && j[4] == 't' && j[5] == 'y'){
         	YP1[0] = G[0].bobotP[0];	NP1[0] = 0;
            YP1[1] = G[1].bobotP[0];   NP1[1] = 0;
            YP1[2] = G[3].bobotP[0];   NP1[2] = 0;
            YP1[3] = G[5].bobotP[0];   NP1[3] = 0;
            YP1[4] = 0;   NP1[4] = G[7].bobotP[0];
            YP1[5] = G[8].bobotP[0];   NP1[5] = 0;
         }
         else if(j[3] == 'y' && j[4] == 't' && j[5] == 't'){
         	YP1[0] = G[0].bobotP[0];	NP1[0] = 0;
            YP1[1] = G[1].bobotP[0];   NP1[1] = 0;
            YP1[2] = G[3].bobotP[0];   NP1[2] = 0;
            YP1[3] = G[5].bobotP[0];   NP1[3] = 0;
            YP1[4] = 0;   NP1[4] = G[7].bobotP[0];
            YP1[5] = 0;   NP1[5] = G[8].bobotP[0];
         }
         else if(j[3] == 't' && j[4] == 'y' && j[5] == 'y'){
         	YP1[0] = G[0].bobotP[0];	NP1[0] = 0;
            YP1[1] = G[1].bobotP[0];   NP1[1] = 0;
            YP1[2] = G[3].bobotP[0];   NP1[2] = 0;
            YP1[3] = 0;   NP1[3] = G[5].bobotP[0];
            YP1[4] = G[7].bobotP[0];   NP1[4] = 0;
            YP1[5] = G[8].bobotP[0];   NP1[5] = 0;
         }
         else if(j[3] == 't' && j[4] == 't' && j[5] == 'y'){
         	YP1[0] = G[0].bobotP[0];	NP1[0] = 0;
            YP1[1] = G[1].bobotP[0];   NP1[1] = 0;
            YP1[2] = G[3].bobotP[0];   NP1[2] = 0;
            YP1[3] = 0;   NP1[3] = G[5].bobotP[0];
            YP1[4] = 0;   NP1[4] = G[7].bobotP[0];
            YP1[5] = G[8].bobotP[0];   NP1[5] = 0;
         }
         else if(j[3] == 't' && j[4] == 'y' && j[5] == 't'){
         	YP1[0] = G[0].bobotP[0];	NP1[0] = 0;
            YP1[1] = G[1].bobotP[0];   NP1[1] = 0;
            YP1[2] = G[3].bobotP[0];   NP1[2] = 0;
            YP1[3] = 0;   NP1[3] = G[5].bobotP[0];
            YP1[4] = G[7].bobotP[0];   NP1[4] = 0;
            YP1[5] = 0;   NP1[5] = G[8].bobotP[0];
         }
         else if(j[3] == 't' && j[4] == 't' && j[5] == 't'){
         	YP1[0] = G[0].bobotP[0];	NP1[0] = 0;
            YP1[1] = G[1].bobotP[0];   NP1[1] = 0;
            YP1[2] = G[3].bobotP[0];   NP1[2] = 0;
            NP1[3] = G[5].bobotP[0];   YP1[3] = 0;
            NP1[4] = G[7].bobotP[0];   YP1[4] = 0;
            NP1[5] = G[8].bobotP[0];   YP1[5] = 0;
         }

         CYP1 = min(YP1, sizeof(YP1)/sizeof(int))*bobotP1;
         CNP1 = min(NP1, sizeof(NP1)/sizeof(int))*bobotP1;
         MBP1 = sum(YP1, sizeof(YP1)/sizeof(int))*(1-CYP1);
         MDP1 = sum(NP1, sizeof(NP1)/sizeof(int))*(1-CNP1);
         CF = MBP1 - MDP1;

         cout << CYP1 << " " << CNP1 << " " << MBP1 << " " << MDP1 << endl;
         cout << "Hasil diagnosis pasien " << nama << " (" << usia << " tahun):" << endl;
         cout << "----------------------------------------------------------------" << endl;
         cout << "Anda terindikasi menderita Demam Berdarah dengan tingkat kepercayaan " << CF*100 << "%" << endl;
         cout << "Saran:" << endl
              << "Silakan Anda cek darah lengkap, tes NS1, tes IgM ELISA," << endl
              << "serta tes HAI ke laboratorium dan segeralah ke rumah sakit";
      }
      else if(j[1] == 'a' && j[2] == 'b'){
      	cout << "4. Apakah pada kulit Anda terdapat ruam merah? Y/T" << endl;
         cout << "Jawaban: "; cin >> j[3];
         cout << endl;
         cout << "5. Apakah Anda mengalami sakit kepala? Y/T" << endl;
         cout << "Jawaban: "; cin >> j[4];
         cout << endl;
         cout << "6. Apakah Anda mengalami nyeri otot? Y/T" << endl;
         cout << "Jawaban: "; cin >> j[5];
         cout << endl;

         if(j[3] == 'y' && j[4] == 'y' && j[5] == 'y'){
         	YP1[0] = G[0].bobotP[0];	NP1[0] = 0;
            YP1[1] = G[1].bobotP[0];   NP1[1] = 0;
            YP1[2] = G[4].bobotP[0];   NP1[2] = 0;
            YP1[3] = G[5].bobotP[0];   NP1[3] = 0;
            YP1[4] = G[7].bobotP[0];   NP1[4] = 0;
            YP1[5] = G[8].bobotP[0];   NP1[5] = 0;
         }
         else if(j[3] == 'y' && j[4] == 'y' && j[5] == 't'){
         	YP1[0] = G[0].bobotP[0];	NP1[0] = 0;
            YP1[1] = G[1].bobotP[0];   NP1[1] = 0;
            YP1[2] = G[4].bobotP[0];   NP1[2] = 0;
            YP1[3] = G[5].bobotP[0];   NP1[3] = 0;
            YP1[4] = G[7].bobotP[0];   NP1[4] = 0;
            YP1[5] = 0;   NP1[5] = G[8].bobotP[0];
         }
         else if(j[3] == 'y' && j[4] == 't' && j[5] == 'y'){
         	YP1[0] = G[0].bobotP[0];	NP1[0] = 0;
            YP1[1] = G[1].bobotP[0];   NP1[1] = 0;
            YP1[2] = G[4].bobotP[0];   NP1[2] = 0;
            YP1[3] = G[5].bobotP[0];   NP1[3] = 0;
            YP1[4] = 0;   NP1[4] = G[7].bobotP[0];
            YP1[5] = G[8].bobotP[0];   NP1[5] = 0;
         }
         else if(j[3] == 'y' && j[4] == 't' && j[5] == 't'){
         	YP1[0] = G[0].bobotP[0];	NP1[0] = 0;
            YP1[1] = G[1].bobotP[0];   NP1[1] = 0;
            YP1[2] = G[4].bobotP[0];   NP1[2] = 0;
            YP1[3] = G[5].bobotP[0];   NP1[3] = 0;
            YP1[4] = 0;   NP1[4] = G[7].bobotP[0];
            YP1[5] = 0;   NP1[5] = G[8].bobotP[0];
         }
         else if(j[3] == 't' && j[4] == 'y' && j[5] == 'y'){
         	YP1[0] = G[0].bobotP[0];	NP1[0] = 0;
            YP1[1] = G[1].bobotP[0];   NP1[1] = 0;
            YP1[2] = G[4].bobotP[0];   NP1[2] = 0;
            YP1[3] = 0;   NP1[3] = G[5].bobotP[0];
            YP1[4] = G[7].bobotP[0];   NP1[4] = 0;
            YP1[5] = G[8].bobotP[0];   NP1[5] = 0;
         }
         else if(j[3] == 't' && j[4] == 't' && j[5] == 'y'){
         	YP1[0] = G[0].bobotP[0];	NP1[0] = 0;
            YP1[1] = G[1].bobotP[0];   NP1[1] = 0;
            YP1[2] = G[4].bobotP[0];   NP1[2] = 0;
            YP1[3] = 0;   NP1[3] = G[5].bobotP[0];
            YP1[4] = 0;   NP1[4] = G[7].bobotP[0];
            YP1[5] = G[8].bobotP[0];   NP1[5] = 0;
         }
         else if(j[3] == 't' && j[4] == 'y' && j[5] == 't'){
         	YP1[0] = G[0].bobotP[0];	NP1[0] = 0;
            YP1[1] = G[1].bobotP[0];   NP1[1] = 0;
            YP1[2] = G[4].bobotP[0];   NP1[2] = 0;
            YP1[3] = 0;   NP1[3] = G[5].bobotP[0];
            YP1[4] = G[7].bobotP[0];   NP1[4] = 0;
            YP1[5] = 0;   NP1[5] = G[8].bobotP[0];
         }
         else if(j[3] == 't' && j[4] == 't' && j[5] == 't'){
         	YP1[0] = G[0].bobotP[0];	NP1[0] = 0;
            YP1[1] = G[1].bobotP[0];   NP1[1] = 0;
            YP1[2] = G[4].bobotP[0];   NP1[2] = 0;
            NP1[3] = G[5].bobotP[0];   YP1[3] = 0;
            NP1[4] = G[7].bobotP[0];   YP1[4] = 0;
            NP1[5] = G[8].bobotP[0];   YP1[5] = 0;
         }

         CYP1 = min(YP1, sizeof(YP1)/sizeof(int))*bobotP1;
         CNP1 = min(NP1, sizeof(NP1)/sizeof(int))*bobotP1;
         MBP1 = sum(YP1, sizeof(YP1)/sizeof(int))*(1-CYP1);
         MDP1 = sum(NP1, sizeof(NP1)/sizeof(int))*(1-CNP1);
         CF = MBP1 - MDP1;

         cout << "Hasil diagnosis pasien " << nama << " (" << usia << " tahun):" << endl;
         cout << "----------------------------------------------------------------" << endl;
         cout << "Anda terindikasi menderita Demam Berdarah dengan tingkat kepercayaan " << CF*100 << "%" << endl;
         cout << "Saran:" << endl
              << "Silakan Anda cek darah lengkap, tes NS1, tes IgM ELISA," << endl
              << "serta tes HAI ke laboratorium dan segeralah ke rumah sakit";
      }




      //terindikasi P2 (tipes)
      else if(j[1] == 'b' && j[2] == 'a'){
      	cout << "4. Apakah Anda lelah dan lemas? Y/T" << endl;
         cout << "Jawaban: "; cin >> j[3];
         cout << endl;
         cout << "5. Apakah Anda mengalami mual dan muntah? Y/T" << endl;
         cout << "Jawaban: "; cin >> j[4];
         cout << endl;
         cout << "6. Apakah Anda mengalami nyeri perut? Y/T" << endl;
         cout << "Jawaban: "; cin >> j[5];
         cout << endl;
         cout << "7. Apakah Anda mengalami diare? Y/T" << endl;
         cout << "Jawaban: "; cin >> j[6];
      	cout << endl;

         if(j[3] == 'y' && j[4] == 'y' && j[5] == 'y' && j[6] == 'y'){
         	YP2[0] = G[0].bobotP[1];	NP2[0] = 0;
            YP2[1] = G[2].bobotP[1];   NP2[1] = 0;
            YP2[2] = G[4].bobotP[1];   NP2[2] = 0;
            YP2[3] = G[6].bobotP[1];   NP2[3] = 0;
            YP2[4] = G[9].bobotP[1];   NP2[4] = 0;
            YP2[5] = G[10].bobotP[1];   NP2[5] = 0;
         	YP2[6] = G[11].bobotP[1];   NP2[6] = 0;
         }
         else if(j[3] == 'y' && j[4] == 'y' && j[5] == 'y' && j[6] == 't'){
         	YP2[0] = G[0].bobotP[1];	NP2[0] = 0;
            YP2[1] = G[2].bobotP[1];   NP2[1] = 0;
            YP2[2] = G[4].bobotP[1];   NP2[2] = 0;
            YP2[3] = G[6].bobotP[1];   NP2[3] = 0;
            YP2[4] = G[9].bobotP[1];   NP2[4] = 0;
            YP2[5] = G[10].bobotP[1];   NP2[5] = 0;
         	NP2[6] = G[11].bobotP[1];   YP2[6] = 0;
         }
         else if(j[3] == 'y' && j[4] == 'y' && j[5] == 't' && j[6] == 'y'){
         	YP2[0] = G[0].bobotP[1];	NP2[0] = 0;
            YP2[1] = G[2].bobotP[1];   NP2[1] = 0;
            YP2[2] = G[4].bobotP[1];   NP2[2] = 0;
            YP2[3] = G[6].bobotP[1];   NP2[3] = 0;
            YP2[4] = G[9].bobotP[1];   NP2[4] = 0;
            NP2[5] = G[10].bobotP[1];   YP2[5] = 0;
         	YP2[6] = G[11].bobotP[1];   NP2[6] = 0;
         }
         else if(j[3] == 'y' && j[4] == 'y' && j[5] == 't' && j[6] == 't'){
         	YP2[0] = G[0].bobotP[1];	NP2[0] = 0;
            YP2[1] = G[2].bobotP[1];   NP2[1] = 0;
            YP2[2] = G[4].bobotP[1];   NP2[2] = 0;
            YP2[3] = G[6].bobotP[1];   NP2[3] = 0;
            YP2[4] = G[9].bobotP[1];   NP2[4] = 0;
            NP2[5] = G[10].bobotP[1];   YP2[5] = 0;
         	NP2[6] = G[11].bobotP[1];   YP2[6] = 0;
         }
         else if(j[3] == 'y' && j[4] == 't' && j[5] == 'y' && j[6] == 'y'){
         	YP2[0] = G[0].bobotP[1];	NP2[0] = 0;
            YP2[1] = G[2].bobotP[1];   NP2[1] = 0;
            YP2[2] = G[4].bobotP[1];   NP2[2] = 0;
            YP2[3] = G[6].bobotP[1];   NP2[3] = 0;
            NP2[4] = G[9].bobotP[1];   YP2[4] = 0;
            YP2[5] = G[10].bobotP[1];   NP2[5] = 0;
         	YP2[6] = G[11].bobotP[1];   NP2[6] = 0;
         }
         else if(j[3] == 'y' && j[4] == 't' && j[5] == 'y' && j[6] == 't'){
         	YP2[0] = G[0].bobotP[1];	NP2[0] = 0;
            YP2[1] = G[2].bobotP[1];   NP2[1] = 0;
            YP2[2] = G[4].bobotP[1];   NP2[2] = 0;
            YP2[3] = G[6].bobotP[1];   NP2[3] = 0;
            NP2[4] = G[9].bobotP[1];   YP2[4] = 0;
            YP2[5] = G[10].bobotP[1];   NP2[5] = 0;
         	NP2[6] = G[11].bobotP[1];   YP2[6] = 0;
         }
         else if(j[3] == 'y' && j[4] == 't' && j[5] == 't' && j[6] == 'y'){
         	YP2[0] = G[0].bobotP[1];	NP2[0] = 0;
            YP2[1] = G[2].bobotP[1];   NP2[1] = 0;
            YP2[2] = G[4].bobotP[1];   NP2[2] = 0;
            YP2[3] = G[6].bobotP[1];   NP2[3] = 0;
            NP2[4] = G[9].bobotP[1];   YP2[4] = 0;
            NP2[5] = G[10].bobotP[1];   YP2[5] = 0;
         	YP2[6] = G[11].bobotP[1];   NP2[6] = 0;
         }
         else if(j[3] == 'y' && j[4] == 't' && j[5] == 't' && j[6] == 't'){
         	YP2[0] = G[0].bobotP[1];	NP2[0] = 0;
            YP2[1] = G[2].bobotP[1];   NP2[1] = 0;
            YP2[2] = G[4].bobotP[1];   NP2[2] = 0;
            YP2[3] = G[6].bobotP[1];   NP2[3] = 0;
            NP2[4] = G[9].bobotP[1];   YP2[4] = 0;
            NP2[5] = G[10].bobotP[1];   YP2[5] = 0;
         	NP2[6] = G[11].bobotP[1];   YP2[6] = 0;
         }
         else if(j[3] == 't' && j[4] == 'y' && j[5] == 'y' && j[6] == 'y'){
         	YP2[0] = G[0].bobotP[1];	NP2[0] = 0;
            YP2[1] = G[2].bobotP[1];   NP2[1] = 0;
            YP2[2] = G[4].bobotP[1];   NP2[2] = 0;
            NP2[3] = G[6].bobotP[1];   YP2[3] = 0;
            YP2[4] = G[9].bobotP[1];   NP2[4] = 0;
            YP2[5] = G[10].bobotP[1];   NP2[5] = 0;
         	YP2[6] = G[11].bobotP[1];   NP2[6] = 0;
         }
         else if(j[3] == 't' && j[4] == 'y' && j[5] == 'y' && j[6] == 't'){
         	YP2[0] = G[0].bobotP[1];	NP2[0] = 0;
            YP2[1] = G[2].bobotP[1];   NP2[1] = 0;
            YP2[2] = G[4].bobotP[1];   NP2[2] = 0;
            NP2[3] = G[6].bobotP[1];   YP2[3] = 0;
            YP2[4] = G[9].bobotP[1];   NP2[4] = 0;
            YP2[5] = G[10].bobotP[1];   NP2[5] = 0;
         	NP2[6] = G[11].bobotP[1];   YP2[6] = 0;
         }
         else if(j[3] == 't' && j[4] == 'y' && j[5] == 't' && j[6] == 'y'){
         	YP2[0] = G[0].bobotP[1];	NP2[0] = 0;
            YP2[1] = G[2].bobotP[1];   NP2[1] = 0;
            YP2[2] = G[4].bobotP[1];   NP2[2] = 0;
            NP2[3] = G[6].bobotP[1];   YP2[3] = 0;
            YP2[4] = G[9].bobotP[1];   NP2[4] = 0;
            NP2[5] = G[10].bobotP[1];   YP2[5] = 0;
         	YP2[6] = G[11].bobotP[1];   NP2[6] = 0;
         }
         else if(j[3] == 't' && j[4] == 'y' && j[5] == 't' && j[6] == 't'){
         	YP2[0] = G[0].bobotP[1];	NP2[0] = 0;
            YP2[1] = G[2].bobotP[1];   NP2[1] = 0;
            YP2[2] = G[4].bobotP[1];   NP2[2] = 0;
            NP2[3] = G[6].bobotP[1];   YP2[3] = 0;
            YP2[4] = G[9].bobotP[1];   NP2[4] = 0;
            NP2[5] = G[10].bobotP[1];   YP2[5] = 0;
         	NP2[6] = G[11].bobotP[1];   YP2[6] = 0;
         }
         else if(j[3] == 't' && j[4] == 't' && j[5] == 'y' && j[6] == 'y'){
         	YP2[0] = G[0].bobotP[1];	NP2[0] = 0;
            YP2[1] = G[2].bobotP[1];   NP2[1] = 0;
            YP2[2] = G[4].bobotP[1];   NP2[2] = 0;
            NP2[3] = G[6].bobotP[1];   YP2[3] = 0;
            NP2[4] = G[9].bobotP[1];   YP2[4] = 0;
            YP2[5] = G[10].bobotP[1];   NP2[5] = 0;
         	YP2[6] = G[11].bobotP[1];   NP2[6] = 0;
         }
         else if(j[3] == 't' && j[4] == 't' && j[5] == 'y' && j[6] == 't'){
         	YP2[0] = G[0].bobotP[1];	NP2[0] = 0;
            YP2[1] = G[2].bobotP[1];   NP2[1] = 0;
            YP2[2] = G[4].bobotP[1];   NP2[2] = 0;
            NP2[3] = G[6].bobotP[1];   YP2[3] = 0;
            NP2[4] = G[9].bobotP[1];   YP2[4] = 0;
            YP2[5] = G[10].bobotP[1];   NP2[5] = 0;
         	NP2[6] = G[11].bobotP[1];   YP2[6] = 0;
         }
         else if(j[3] == 't' && j[4] == 't' && j[5] == 't' && j[6] == 'y'){
         	YP2[0] = G[0].bobotP[1];	NP2[0] = 0;
            YP2[1] = G[2].bobotP[1];   NP2[1] = 0;
            YP2[2] = G[4].bobotP[1];   NP2[2] = 0;
            NP2[3] = G[6].bobotP[1];   YP2[3] = 0;
            NP2[4] = G[9].bobotP[1];   YP2[4] = 0;
            NP2[5] = G[10].bobotP[1];   YP2[5] = 0;
         	YP2[6] = G[11].bobotP[1];   NP2[6] = 0;
         }
         else if(j[3] == 't' && j[4] == 't' && j[5] == 't' && j[6] == 't'){
         	YP2[0] = G[0].bobotP[1];	NP2[0] = 0;
            YP2[1] = G[2].bobotP[1];   NP2[1] = 0;
            YP2[2] = G[4].bobotP[1];   NP2[2] = 0;
            NP2[3] = G[6].bobotP[1];   YP2[3] = 0;
            NP2[4] = G[9].bobotP[1];   YP2[4] = 0;
            NP2[5] = G[10].bobotP[1];   YP2[5] = 0;
         	NP2[6] = G[11].bobotP[1];   YP2[6] = 0;
         }

         CYP2 = min(YP2, sizeof(YP2)/sizeof(int))*bobotP2;
         CNP2 = min(NP2, sizeof(NP2)/sizeof(int))*bobotP2;
         MBP2 = sum(YP2, sizeof(YP2)/sizeof(int))*(1-CYP2);
         MDP2 = sum(NP2, sizeof(NP2)/sizeof(int))*(1-CNP2);
         CF = MBP2 - MDP2;

         cout << "Hasil diagnosis pasien " << nama << " (" << usia << " tahun):" << endl;
         cout << "----------------------------------------------------------------" << endl;
         cout << "Anda terindikasi menderita tipes dengan tingkat kepercayaan " << CF*100 << "%" << endl;
         cout << "Saran:" << endl
              << "Silakan Anda melakukan tes widal untuk memastikan bahwa benar menderita tipes" << endl
              << "dan tes darah lengkap, tes NS1, tes IgM ELISA, serta tes HAI ke laboratorium" << endl
              << "karena suhu tubuh anda >40 derajat untuk memastikan anda tidak menderita DBD";
      }
      else if(j[1] == 'b' && j[2] == 'b'){
      	cout << "4. Apakah Anda lelah dan lemas? Y/T" << endl;
         cout << "Jawaban: "; cin >> j[3];
         cout << endl;
         cout << "5. Apakah Anda mengalami mual dan muntah? Y/T" << endl;
         cout << "Jawaban: "; cin >> j[4];
         cout << endl;
         cout << "6. Apakah Anda mengalami nyeri perut? Y/T" << endl;
         cout << "Jawaban: "; cin >> j[5];
         cout << endl;
         cout << "7. Apakah Anda mengalami diare? Y/T" << endl;
         cout << "Jawaban: "; cin >> j[6];
      	cout << endl;

         if(j[3] == 'y' && j[4] == 'y' && j[5] == 'y' && j[6] == 'y'){
         	YP2[0] = G[0].bobotP[1];	NP2[0] = 0;
            YP2[1] = G[2].bobotP[1];   NP2[1] = 0;
            YP2[2] = G[3].bobotP[1];   NP2[2] = 0;
            YP2[3] = G[6].bobotP[1];   NP2[3] = 0;
            YP2[4] = G[9].bobotP[1];   NP2[4] = 0;
            YP2[5] = G[10].bobotP[1];   NP2[5] = 0;
         	YP2[6] = G[11].bobotP[1];   NP2[6] = 0;
         }
         else if(j[3] == 'y' && j[4] == 'y' && j[5] == 'y' && j[6] == 't'){
         	YP2[0] = G[0].bobotP[1];	NP2[0] = 0;
            YP2[1] = G[2].bobotP[1];   NP2[1] = 0;
            YP2[2] = G[3].bobotP[1];   NP2[2] = 0;
            YP2[3] = G[6].bobotP[1];   NP2[3] = 0;
            YP2[4] = G[9].bobotP[1];   NP2[4] = 0;
            YP2[5] = G[10].bobotP[1];   NP2[5] = 0;
         	NP2[6] = G[11].bobotP[1];   YP2[6] = 0;
         }
         else if(j[3] == 'y' && j[4] == 'y' && j[5] == 't' && j[6] == 'y'){
         	YP2[0] = G[0].bobotP[1];	NP2[0] = 0;
            YP2[1] = G[2].bobotP[1];   NP2[1] = 0;
            YP2[2] = G[3].bobotP[1];   NP2[2] = 0;
            YP2[3] = G[6].bobotP[1];   NP2[3] = 0;
            YP2[4] = G[9].bobotP[1];   NP2[4] = 0;
            NP2[5] = G[10].bobotP[1];   YP2[5] = 0;
         	YP2[6] = G[11].bobotP[1];   NP2[6] = 0;
         }
         else if(j[3] == 'y' && j[4] == 'y' && j[5] == 't' && j[6] == 't'){
         	YP2[0] = G[0].bobotP[1];	NP2[0] = 0;
            YP2[1] = G[2].bobotP[1];   NP2[1] = 0;
            YP2[2] = G[3].bobotP[1];   NP2[2] = 0;
            YP2[3] = G[6].bobotP[1];   NP2[3] = 0;
            YP2[4] = G[9].bobotP[1];   NP2[4] = 0;
            NP2[5] = G[10].bobotP[1];   YP2[5] = 0;
         	NP2[6] = G[11].bobotP[1];   YP2[6] = 0;
         }
         else if(j[3] == 'y' && j[4] == 't' && j[5] == 'y' && j[6] == 'y'){
         	YP2[0] = G[0].bobotP[1];	NP2[0] = 0;
            YP2[1] = G[2].bobotP[1];   NP2[1] = 0;
            YP2[2] = G[3].bobotP[1];   NP2[2] = 0;
            YP2[3] = G[6].bobotP[1];   NP2[3] = 0;
            NP2[4] = G[9].bobotP[1];   YP2[4] = 0;
            YP2[5] = G[10].bobotP[1];   NP2[5] = 0;
         	YP2[6] = G[11].bobotP[1];   NP2[6] = 0;
         }
         else if(j[3] == 'y' && j[4] == 't' && j[5] == 'y' && j[6] == 't'){
         	YP2[0] = G[0].bobotP[1];	NP2[0] = 0;
            YP2[1] = G[2].bobotP[1];   NP2[1] = 0;
            YP2[2] = G[3].bobotP[1];   NP2[2] = 0;
            YP2[3] = G[6].bobotP[1];   NP2[3] = 0;
            NP2[4] = G[9].bobotP[1];   YP2[4] = 0;
            YP2[5] = G[10].bobotP[1];   NP2[5] = 0;
         	NP2[6] = G[11].bobotP[1];   YP2[6] = 0;
         }
         else if(j[3] == 'y' && j[4] == 't' && j[5] == 't' && j[6] == 'y'){
         	YP2[0] = G[0].bobotP[1];	NP2[0] = 0;
            YP2[1] = G[2].bobotP[1];   NP2[1] = 0;
            YP2[2] = G[3].bobotP[1];   NP2[2] = 0;
            YP2[3] = G[6].bobotP[1];   NP2[3] = 0;
            NP2[4] = G[9].bobotP[1];   YP2[4] = 0;
            NP2[5] = G[10].bobotP[1];   YP2[5] = 0;
         	YP2[6] = G[11].bobotP[1];   NP2[6] = 0;
         }
         else if(j[3] == 'y' && j[4] == 't' && j[5] == 't' && j[6] == 't'){
         	YP2[0] = G[0].bobotP[1];	NP2[0] = 0;
            YP2[1] = G[2].bobotP[1];   NP2[1] = 0;
            YP2[2] = G[3].bobotP[1];   NP2[2] = 0;
            YP2[3] = G[6].bobotP[1];   NP2[3] = 0;
            NP2[4] = G[9].bobotP[1];   YP2[4] = 0;
            NP2[5] = G[10].bobotP[1];   YP2[5] = 0;
         	NP2[6] = G[11].bobotP[1];   YP2[6] = 0;
         }
         else if(j[3] == 't' && j[4] == 'y' && j[5] == 'y' && j[6] == 'y'){
         	YP2[0] = G[0].bobotP[1];	NP2[0] = 0;
            YP2[1] = G[2].bobotP[1];   NP2[1] = 0;
            YP2[2] = G[3].bobotP[1];   NP2[2] = 0;
            NP2[3] = G[6].bobotP[1];   YP2[3] = 0;
            YP2[4] = G[9].bobotP[1];   NP2[4] = 0;
            YP2[5] = G[10].bobotP[1];   NP2[5] = 0;
         	YP2[6] = G[11].bobotP[1];   NP2[6] = 0;
         }
         else if(j[3] == 't' && j[4] == 'y' && j[5] == 'y' && j[6] == 't'){
         	YP2[0] = G[0].bobotP[1];	NP2[0] = 0;
            YP2[1] = G[2].bobotP[1];   NP2[1] = 0;
            YP2[2] = G[3].bobotP[1];   NP2[2] = 0;
            NP2[3] = G[6].bobotP[1];   YP2[3] = 0;
            YP2[4] = G[9].bobotP[1];   NP2[4] = 0;
            YP2[5] = G[10].bobotP[1];   NP2[5] = 0;
         	NP2[6] = G[11].bobotP[1];   YP2[6] = 0;
         }
         else if(j[3] == 't' && j[4] == 'y' && j[5] == 't' && j[6] == 'y'){
         	YP2[0] = G[0].bobotP[1];	NP2[0] = 0;
            YP2[1] = G[2].bobotP[1];   NP2[1] = 0;
            YP2[2] = G[3].bobotP[1];   NP2[2] = 0;
            NP2[3] = G[6].bobotP[1];   YP2[3] = 0;
            YP2[4] = G[9].bobotP[1];   NP2[4] = 0;
            NP2[5] = G[10].bobotP[1];   YP2[5] = 0;
         	YP2[6] = G[11].bobotP[1];   NP2[6] = 0;
         }
         else if(j[3] == 't' && j[4] == 'y' && j[5] == 't' && j[6] == 't'){
         	YP2[0] = G[0].bobotP[1];	NP2[0] = 0;
            YP2[1] = G[2].bobotP[1];   NP2[1] = 0;
            YP2[2] = G[3].bobotP[1];   NP2[2] = 0;
            NP2[3] = G[6].bobotP[1];   YP2[3] = 0;
            YP2[4] = G[9].bobotP[1];   NP2[4] = 0;
            NP2[5] = G[10].bobotP[1];   YP2[5] = 0;
         	NP2[6] = G[11].bobotP[1];   YP2[6] = 0;
         }
         else if(j[3] == 't' && j[4] == 't' && j[5] == 'y' && j[6] == 'y'){
         	YP2[0] = G[0].bobotP[1];	NP2[0] = 0;
            YP2[1] = G[2].bobotP[1];   NP2[1] = 0;
            YP2[2] = G[3].bobotP[1];   NP2[2] = 0;
            NP2[3] = G[6].bobotP[1];   YP2[3] = 0;
            NP2[4] = G[9].bobotP[1];   YP2[4] = 0;
            YP2[5] = G[10].bobotP[1];   NP2[5] = 0;
         	YP2[6] = G[11].bobotP[1];   NP2[6] = 0;
         }
         else if(j[3] == 't' && j[4] == 't' && j[5] == 'y' && j[6] == 't'){
         	YP2[0] = G[0].bobotP[1];	NP2[0] = 0;
            YP2[1] = G[2].bobotP[1];   NP2[1] = 0;
            YP2[2] = G[3].bobotP[1];   NP2[2] = 0;
            NP2[3] = G[6].bobotP[1];   YP2[3] = 0;
            NP2[4] = G[9].bobotP[1];   YP2[4] = 0;
            YP2[5] = G[10].bobotP[1];   NP2[5] = 0;
         	NP2[6] = G[11].bobotP[1];   YP2[6] = 0;
         }
         else if(j[3] == 't' && j[4] == 't' && j[5] == 't' && j[6] == 'y'){
         	YP2[0] = G[0].bobotP[1];	NP2[0] = 0;
            YP2[1] = G[2].bobotP[1];   NP2[1] = 0;
            YP2[2] = G[3].bobotP[1];   NP2[2] = 0;
            NP2[3] = G[6].bobotP[1];   YP2[3] = 0;
            NP2[4] = G[9].bobotP[1];   YP2[4] = 0;
            NP2[5] = G[10].bobotP[1];   YP2[5] = 0;
         	YP2[6] = G[11].bobotP[1];   NP2[6] = 0;
         }
         else if(j[3] == 't' && j[4] == 't' && j[5] == 't' && j[6] == 't'){
         	YP2[0] = G[0].bobotP[1];	NP2[0] = 0;
            YP2[1] = G[2].bobotP[1];   NP2[1] = 0;
            YP2[2] = G[3].bobotP[1];   NP2[2] = 0;
            NP2[3] = G[6].bobotP[1];   YP2[3] = 0;
            NP2[4] = G[9].bobotP[1];   YP2[4] = 0;
            NP2[5] = G[10].bobotP[1];   YP2[5] = 0;
         	NP2[6] = G[11].bobotP[1];   YP2[6] = 0;
         }

         CYP2 = min(YP2, sizeof(YP2)/sizeof(int))*bobotP2;
         CNP2 = min(NP2, sizeof(NP2)/sizeof(int))*bobotP2;
         MBP2 = sum(YP2, sizeof(YP2)/sizeof(int))*(1-CYP2);
         MDP2 = sum(NP2, sizeof(NP2)/sizeof(int))*(1-CNP2);
         CF = MBP2 - MDP2;

         cout << "Hasil diagnosis pasien " << nama << " (" << usia << " tahun):" << endl;
         cout << "----------------------------------------------------------------" << endl;
         cout << "Anda terindikasi menderita tipes dengan tingkat kepercayaan " << CF*100 << "%" << endl;
         cout << "Saran:" << endl
              << "Silakan Anda melakukan tes widal untuk memastikan bahwa benar menderita tipes";
      }
   }
   else if(j[0] == 'T' || j[0] == 't'){
      cout << "Hasil diagnosis pasien " << nama << " (" << usia << " tahun):" << endl;
   	cout << "Selamat Anda tidak menderita demam berdarah maupun tipes" << endl;
   }
   else{
   	cout << "Pilihan jawaban tidak tersedia" << endl;
      goto pertanyaan;
   }
}

float min(float arr[], int n){
   float temp = arr[0];
	for(int i = 1; i < n; i++){
   	if(arr[i] < temp){
         temp = arr[i];
   	}
   }
   return temp;
}

float sum(float arr[], int n){
   float tot = 0;
	for(int i = 0; i < n; i++){
   	tot = tot + arr[i];
  	}
   return tot;
}
