#include "../include/crypto.h"  // Inkluderer headerfilen med funktionsdeklarationer

/**
 * Caesar-kryptering
 * Flytter hvert bogstav i teksten et bestemt antal pladser i alfabetet.
 * Eksempel: "HELLO" med shift=3 bliver "KHOOR"
 */
void caesar_encrypt(const char *text, int shift, char *result) {
    // Gennemløber hvert tegn i teksten
    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) { // Tjekker om tegnet er et bogstav (A-Z / a-z)
            // Bestemmer om bogstavet er stort eller småt
            char base = isupper(text[i]) ? 'A' : 'a';

            // Beregner nyt bogstav: (tegn - startbogstav + forskydning) mod 26
            // Dette sikrer, at Z går tilbage til A
            result[i] = (text[i] - base + shift) % 26 + base;
        } else {
            // Hvis tegnet ikke er et bogstav (fx mellemrum), kopieres det som det er
            result[i] = text[i];
        }
    }
}

/**
 * Caesar-dekryptering
 * Gør det modsatte af kryptering ved at bruge (26 - shift)
 * I praksis "skruer" vi bare forskydningen tilbage
 */
void caesar_decrypt(const char *text, int shift, char *result) {
    // Kalder bare encrypt-funktionen med modsat forskydning
    caesar_encrypt(text, 26 - (shift % 26), result);
}

/**
 * Vigenere-kryptering
 * Hvert bogstav flyttes ud fra et bogstav i en nøgle.
 * Eksempel: tekst="HELLO", nøgle="KEY" → krypteret="RIJVS"
 */
void vigenere_encrypt(const char *text, const char *key, char *result) {
    int key_len = strlen(key); // Finder længden af nøglen

    // i = position i tekst, j = position i nøgle
    for (int i = 0, j = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) { // Kun bogstaver krypteres
            char base = isupper(text[i]) ? 'A' : 'a'; // Tjekker om stort/småt bogstav

            // Beregner forskydning ud fra nøglebogstav (0–25)
            int k = tolower(key[j % key_len]) - 'a';

            // Krypterer ved at lægge nøglens værdi til
            result[i] = (text[i] - base + k) % 26 + base;

            j++; // Går videre til næste bogstav i nøglen
        } else {
            // Ikke-bogstaver kopieres
            result[i] = text[i];
        }
    }
}

/**
 * Vigenere-dekryptering
 * Gør det modsatte af encrypt: trækker nøglens bogstavværdi fra.
 */
void vigenere_decrypt(const char *text, const char *key, char *result) {
    int key_len = strlen(key); // Længden af nøgle

    for (int i = 0, j = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            char base = isupper(text[i]) ? 'A' : 'a';
            int k = tolower(key[j % key_len]) - 'a';

            // Dekryptering: træk nøgleværdien fra (og +26 for at undgå negative tal)
            result[i] = (text[i] - base - k + 26) % 26 + base;
            j++;
        } else {
            result[i] = text[i];
        }
    }
}
