#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

int main() {

    // Sanal þehrin internet kullanýmý verilerini yükleyin
    ifstream infile("internet_usage_data.csv");
    string line;
    vector<string> data;
    while (getline(infile, line)) {
        data.push_back(line);
    }

    // Þu andaki saati kontrol edin
    time_t now = time(nullptr);
    struct tm* tm = localtime(&now);
    int hour = tm->tm_hour;

    // Sanal þehri bölgelere ayýrýn
    // Örneðin, þehri 10 bölgeye ayýrabilirsiniz.
    vector<vector<int>> regions = { {0, 1, 2, 3, 4}, {5, 6, 7, 8, 9}, {10, 11, 12, 13, 14}, {15, 16, 17, 18, 19}, {20, 21, 22, 23, 24} };

    // Bölgelerdeki internet kullanýmýný hesaplayýn
    for (int i = 0; i < regions.size(); i++) {
        int region_usage = 0;
        for (int j = 0; j < regions[i].size(); j++) {
            region_usage += stoi(data[regions[i][j]]);
        }
        regions[i].push_back(region_usage);
    }

    // Bölgelerdeki hava durumunu kontrol edin
    // Örneðin, hava durumunu internetten veya bir hava durumu API'sinden alabilirsiniz.
    vector<vector<int>> regions_weather = { {1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}, {16, 17, 18, 19, 20}, {21, 22, 23, 24, 25} };

    // Bölgelerdeki internet kullanýmýný ve hava durumunu kullanarak kullanýcýlarý yönlendirin
    for (int i = 0; i < regions.size(); i++) {
        if (hour == regions[i][0]) {
            // Kullanýcýlara uyarý mesajý gönderin
            cout << "Ýnternet kullanýmý þu anda yoðunlaþmaya baþladý. Daha yavaþ internet baðlantýsý yaþayabilirsiniz." << endl;

            // Kullanýcýlarýn internet kullanýmýný azaltmalarý için bir öneri yapýn
            cout << "Ýnternet kullanýmýnýzý azaltmak için aþaðýdakileri yapabilirsiniz:" << endl;

            // Bölgedeki internet kullanýmýný ve hava durumunu göz önünde bulundurarak özelleþtirilmiþ öneriler
            if (regions[i][1] < regions[i][2]) {
                // Ýnternet kullanýmý daha az olan bölgeye yönlendirin
                if (i == 2) {
                    cout << "* Bölge 3'e gidin. Bölgedeki internet hýzý 100 Mbps, hava durumu ise güneþli." << endl;
                    cout << "* Bölge 3'te bulunan oyun merkezleri ve kafeler þunlardýr:" << endl;
                    cout << "* Oyun Merkezi 1" << endl;
                    cout << "* Oyun Merkezi 2" << endl;
                    cout << "* Kafe 1" << endl;
                    cout << "* Kafe 2" << endl;
                    cout << "* Oyun Merkezi 1'in adresi: Naaldwijk, Hollanda, 2671 NW" << endl;
                    cout << "* Oyun Merkezi 1'in iletiþim bilgileri: +31 (0)70 345 6789" << endl;
                    cout << "* Oyun Merkezi 1'in fiyatlarý:" << endl;
                    cout << "* Yetiþkin giriþ ücreti: €5" << endl;
                    cout << "* Çocuk giriþ ücreti: €2.5" << endl;
                    cout << "* Oyun saati ücreti: €2" << endl;
                    cout << "* Oyun Merkezi 1'in sunduðu oyunlar veya hizmetler:" << endl;
                    cout << "* Konsol oyunlarý" << endl;
                    cout << "* Bilgisayar oyunlarý" << endl;
                    cout << "* Masa oyunlarý" << endl;
                    cout << "* Bilardo" << endl;
                    cout << "* ÖNEMLÝ" << endl;
                    cout << "* Bölge 3'e giden kullanýcýlardan rastgele seçilecek 100 kiþiye hediye internet paketi verilecektir." << endl;
                    cout << "* Hediyenizi almak için lütfen þu adýmlarý izleyin:." << endl;
                    cout << "* 1. Bölge 3'e gidin ve önerdiðimiz oyun merkezlerinden veya kafelerden birinde en az 2 saat geçirin." << endl;
                    cout << "* 2. Oyun merkezine veya kafeye gidince, hediyenizi almak istediðinizi belirtin." << endl;
                    cout << "* 3. Kimliðinizi veya telefon numaranýzý verin." << endl;
                    cout << "* 4. Hediyenizi alýn ve keyfini çýkarýn!" << endl;
                }
            }
        }
    }
}



