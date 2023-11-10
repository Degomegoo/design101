#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

int main() {

    // Sanal �ehrin internet kullan�m� verilerini y�kleyin
    ifstream infile("internet_usage_data.csv");
    string line;
    vector<string> data;
    while (getline(infile, line)) {
        data.push_back(line);
    }

    // �u andaki saati kontrol edin
    time_t now = time(nullptr);
    struct tm* tm = localtime(&now);
    int hour = tm->tm_hour;

    // Sanal �ehri b�lgelere ay�r�n
    // �rne�in, �ehri 10 b�lgeye ay�rabilirsiniz.
    vector<vector<int>> regions = { {0, 1, 2, 3, 4}, {5, 6, 7, 8, 9}, {10, 11, 12, 13, 14}, {15, 16, 17, 18, 19}, {20, 21, 22, 23, 24} };

    // B�lgelerdeki internet kullan�m�n� hesaplay�n
    for (int i = 0; i < regions.size(); i++) {
        int region_usage = 0;
        for (int j = 0; j < regions[i].size(); j++) {
            region_usage += stoi(data[regions[i][j]]);
        }
        regions[i].push_back(region_usage);
    }

    // B�lgelerdeki hava durumunu kontrol edin
    // �rne�in, hava durumunu internetten veya bir hava durumu API'sinden alabilirsiniz.
    vector<vector<int>> regions_weather = { {1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}, {16, 17, 18, 19, 20}, {21, 22, 23, 24, 25} };

    // B�lgelerdeki internet kullan�m�n� ve hava durumunu kullanarak kullan�c�lar� y�nlendirin
    for (int i = 0; i < regions.size(); i++) {
        if (hour == regions[i][0]) {
            // Kullan�c�lara uyar� mesaj� g�nderin
            cout << "�nternet kullan�m� �u anda yo�unla�maya ba�lad�. Daha yava� internet ba�lant�s� ya�ayabilirsiniz." << endl;

            // Kullan�c�lar�n internet kullan�m�n� azaltmalar� i�in bir �neri yap�n
            cout << "�nternet kullan�m�n�z� azaltmak i�in a�a��dakileri yapabilirsiniz:" << endl;

            // B�lgedeki internet kullan�m�n� ve hava durumunu g�z �n�nde bulundurarak �zelle�tirilmi� �neriler
            if (regions[i][1] < regions[i][2]) {
                // �nternet kullan�m� daha az olan b�lgeye y�nlendirin
                if (i == 2) {
                    cout << "* B�lge 3'e gidin. B�lgedeki internet h�z� 100 Mbps, hava durumu ise g�ne�li." << endl;
                    cout << "* B�lge 3'te bulunan oyun merkezleri ve kafeler �unlard�r:" << endl;
                    cout << "* Oyun Merkezi 1" << endl;
                    cout << "* Oyun Merkezi 2" << endl;
                    cout << "* Kafe 1" << endl;
                    cout << "* Kafe 2" << endl;
                    cout << "* Oyun Merkezi 1'in adresi: Naaldwijk, Hollanda, 2671 NW" << endl;
                    cout << "* Oyun Merkezi 1'in ileti�im bilgileri: +31 (0)70 345 6789" << endl;
                    cout << "* Oyun Merkezi 1'in fiyatlar�:" << endl;
                    cout << "* Yeti�kin giri� �creti: �5" << endl;
                    cout << "* �ocuk giri� �creti: �2.5" << endl;
                    cout << "* Oyun saati �creti: �2" << endl;
                    cout << "* Oyun Merkezi 1'in sundu�u oyunlar veya hizmetler:" << endl;
                    cout << "* Konsol oyunlar�" << endl;
                    cout << "* Bilgisayar oyunlar�" << endl;
                    cout << "* Masa oyunlar�" << endl;
                    cout << "* Bilardo" << endl;
                    cout << "* �NEML�" << endl;
                    cout << "* B�lge 3'e giden kullan�c�lardan rastgele se�ilecek 100 ki�iye hediye internet paketi verilecektir." << endl;
                    cout << "* Hediyenizi almak i�in l�tfen �u ad�mlar� izleyin:." << endl;
                    cout << "* 1. B�lge 3'e gidin ve �nerdi�imiz oyun merkezlerinden veya kafelerden birinde en az 2 saat ge�irin." << endl;
                    cout << "* 2. Oyun merkezine veya kafeye gidince, hediyenizi almak istedi�inizi belirtin." << endl;
                    cout << "* 3. Kimli�inizi veya telefon numaran�z� verin." << endl;
                    cout << "* 4. Hediyenizi al�n ve keyfini ��kar�n!" << endl;
                }
            }
        }
    }
}



