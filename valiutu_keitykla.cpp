#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Kiek valiutos gaunama uz 1 EUR
const double GBP_Bendras  = 0.8729;
const double GBP_Pirkti   = 0.8600;
const double GBP_Parduoti = 0.9220;

const double USD_Bendras  = 1.1793;
const double USD_Pirkti   = 1.1460;
const double USD_Parduoti = 1.2340;

const double INR_Bendras  = 104.6918;
const double INR_Pirkti   = 101.3862;
const double INR_Parduoti = 107.8546;

int main() {
    cout << fixed << setprecision(2);
    int veiksmas = 0;

    while (veiksmas != 4) {
        cout << "\n===== VALIUTOS KEITYKLA =====\n";
        cout << "1. Valiutos kurso palyginimas su euru\n";
        cout << "2. Valiutos pirkimas (EUR -> valiuta)\n";
        cout << "3. Valiutos pardavimas (valiuta -> EUR)\n";
        cout << "4. Iseiti\n";
        cout << "Pasirinkite veiksma: ";
        cin >> veiksmas;

        if (veiksmas == 4) {
            cout << "Viso gero!\n";
        } else if (veiksmas < 1 || veiksmas > 4) {
            cout << "Klaida: neteisingas meniu pasirinkimas!\n";
        } else {
            cout << "\n1 - GBP\n2 - USD\n3 - INR\n";
            cout << "Pasirinkite valiuta: ";
            int valiuta;
            cin >> valiuta;

            string vardas;
            double bendras, pirkti, parduoti;

            if (valiuta == 1) {
                vardas = "GBP";
                bendras = GBP_Bendras;
                pirkti = GBP_Pirkti;
                parduoti = GBP_Parduoti;
            } else if (valiuta == 2) {
                vardas = "USD";
                bendras = USD_Bendras;
                pirkti = USD_Pirkti;
                parduoti = USD_Parduoti;
            } else if (valiuta == 3) {
                vardas = "INR";
                bendras = INR_Bendras;
                pirkti = INR_Pirkti;
                parduoti = INR_Parduoti;
            } else {
                cout << "Klaida: neteisingas valiutos pasirinkimas!\n";
                continue;
            }

            if (veiksmas == 1) {
                cout << "\n1 EUR = " << bendras << " " << vardas << " (bendras)\n";
                cout << "1 EUR = " << pirkti << " " << vardas << " (pirkimas)\n";
                cout << "1 EUR = " << parduoti << " " << vardas << " (pardavimas)\n";
            } else {
                double suma;
                cout << "Iveskite suma: ";
                cin >> suma;

                if (suma <= 0) {
                    cout << "Klaida: suma turi buti teigiama!\n";
                } else if (veiksmas == 2) {
                    cout << suma << " EUR = " << suma * pirkti << " " << vardas << "\n";
                } else {
                    cout << suma << " " << vardas << " = " << suma / parduoti << " EUR\n";
                }
            }
        }
    }
    return 0;
}