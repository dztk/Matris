
// Ödev no : 2 
// Ödev konu : Matris oluşturma, matris işlemleri ve şifreleme

#include <iostream>
#include <iomanip>
#include<locale.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Turkish");
    int matris_a[5][5];
    int matris_b[5][5];
    int matris_c[5][5];
    int matris_b2[5][5];
    int satır, sutun;
    char ch;
    do
    {
        srand(time(0));
        // rastgele değer atama
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                matris_a[i][j] = rand() % 11;
            }
        }
        // ekrana yazdırma
        cout << "A matrisi" << endl;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                cout << setw(5) << matris_a[i][j];

            }
            cout << endl;
        }

        // b için değer atama
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                matris_b[i][j] = rand() % 11;
            }
            cout << endl;
        }
        // b yi ekrana yazdırma
        cout << "B matrisi:" << endl;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                matris_b2[i][j] = matris_b[i][j];
                cout << setw(5) << matris_b[i][j];
            }
            cout << endl;
        }
        cout << endl;
        // değiştirme 
        do {
            cout << "Değiştirilecek satır ve sütun numarasını giriniz(1-5 arası):" << endl;
            cin >> satır >> sutun;
        } while (!(satır <= 5 && satır >= 1 && sutun <= 5 && sutun >= 1));

        for (int i = 0; i < 5; i++) {
            int temp = matris_a[i][sutun - 1];
            matris_a[i][sutun - 1] = matris_b[i][sutun - 1];
            matris_b[i][sutun - 1] = temp;
        }

        for (int j = 0; j < 5; j++) {
            int temp = matris_a[satır - 1][j];
            matris_a[satır - 1][j] = matris_b[satır - 1][j];
            matris_b[satır - 1][j] = temp;
        }
        


        cout << "Değişim sonrası:" << endl;
        cout << "A matrisi:" << endl;

        for (int i = 0; i < 5; i++) {

            for (int j = 0; j < 5; j++) {
                int temp = matris_a[satır - 1][sutun - 1];  // satır sütunun kesiştiği yerlerde sorun çıkıyordu onları gidermeye çalıştım
                matris_a[satır - 1][sutun - 1] = matris_b[satır - 1][sutun - 1];
                matris_b[satır - 1][sutun - 1] = temp;
                int temp_1 = matris_a[satır - 1][sutun - 1];
                matris_a[satır - 1][sutun - 1] = matris_b2[satır - 1][sutun - 1];
                matris_b2[satır - 1][sutun - 1] = temp_1;
                cout << setw(5) << matris_a[i][j];
            }
            cout << endl;
        }
        cout << endl;

        cout << "B matrisi:" << endl;


        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                cout << setw(5) << matris_b[i][j];

            }
            cout << endl;
        }

        // çarpımları
        int toplam;

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                toplam = 0;
                for (int k = 0; k < 5; k++)
                    toplam += matris_a[i][k] * matris_b[k][j];
                matris_c[i][j] = toplam;
            }
        }

        cout << "AxB matrisi:" << endl;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                cout << setw(5) << matris_c[i][j];
            }
            cout << endl;
        }

        //kullanıcıya devam etmek isteyip istemediği sorulacak seçimine göre program tekrar çalışacak ya da hoşçakalın diyecek
        do {
            cout << "Devam etmek istiyor musunuz? (E/H):" << endl;
            cin >> ch;
        } while (!(ch == 'E' || ch == 'H' || ch == 'h' || ch == 'e'));
    } while (ch != 'H' && ch != 'h');
    cout << "Hoşçakalın";

    return 0;
}