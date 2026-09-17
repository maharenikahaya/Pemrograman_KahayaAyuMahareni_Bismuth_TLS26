#include <iostream>
using namespace std;

int main() {
    int N, K;

    cout << "Masukkan jumlah astronot (N): ";
    cin >> N;

    cout << "Masukkan nilai awal K: ";
    cin >> K;

    int astronaut[1000];
    int alive = N;

    for (int i = 0; i < N; i++) {
        astronaut[i] = i + 1;
    }

    int current = 0;

    cout << "\nUrutan eliminasi: ";

    while (alive > 1) {
        int eliminateIndex = (current + K - 1) % alive;
        int eliminated = astronaut[eliminateIndex];

        cout << eliminated;

        if (alive > 2)
            cout << " -> ";

        // Update K sesuai aturan
        if (eliminated % 2 == 0) {
            K += 2;
        } else {
            K -= 1;
            if (K < 2)
                K = 2;
        }

        // Hapus astronot yang tereliminasi
        for (int i = eliminateIndex; i < alive - 1; i++) {
            astronaut[i] = astronaut[i + 1];
        }

        alive--;

        // Posisi awal hitungan berikutnya
        if (alive > 0)
            current = eliminateIndex % alive;
    }

    cout << "\n\nAstronot terakhir yang bertahan: "
         << astronaut[0] << endl;

    return 0;
}