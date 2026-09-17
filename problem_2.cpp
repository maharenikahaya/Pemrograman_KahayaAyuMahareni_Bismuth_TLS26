#include <iostream>

// Fungsi manual untuk mengukur panjang string (tanpa library string/cstring)
int hitungPanjang(const char str[]) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

// Fungsi manual untuk mengubah karakter menjadi huruf kapital
char keKapital(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a' + 'A';
    }
    return c;
}

int main() {
    char pesan[100];
    
    std::cout << "Masukkan pesan (huruf A-Z): ";
    std::cin >> pesan;

    int panjang = hitungPanjang(pesan);

    if (panjang == 0) {
        return 0;
    }

    std::cout << "Pesan Terenkripsi: ";

    // Huruf pertama tidak mengalami perubahan
    char hurufSebelumnyaVal = 0;

    for (int i = 0; i < panjang; i++) {
        char currentChar = keKapital(pesan[i]);

        if (currentChar >= 'A' && currentChar <= 'Z') {
            // Ubah huruf A-Z ke angka 1-26
            int valSekarang = currentChar - 'A' + 1;

            // Geser nilai sebesar huruf sebelumnya
            int valBaru = valSekarang + hurufSebelumnyaVal;

            // Jika melebihi 26 (Z), kembali mutar ke A (1)
            if (valBaru > 26) {
                valBaru = valBaru - 26;
            }

            // Kembalikan ke karakter ASCII ('A' + valBaru - 1)
            char hurufBaru = 'A' + (valBaru - 1);
            std::cout << hurufBaru;

            // Simpan nilai dari HURUF ASLI sebelumnya untuk iterasi berikutnya
            hurufSebelumnyaVal = valSekarang;
        } else {
            // Jika ada karakter selain huruf, cetak langsung tanpa diubah
            std::cout << currentChar;
        }
    }

    std::cout << std::endl;

    return 0;
}