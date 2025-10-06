/**
 * @file crypto.h
 * @brief Header file for cryptography functions (Caesar and Vigenere ciphers).
 */

#ifndef CRYPTO_H
#define CRYPTO_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>

/**
 * @brief Encrypts ved brug af Caesar cipher.
 * @param text input ren text 
 * @param shift skif værdig
 * @param result Output efter værdig skift.
 */
void caesar_encrypt(const char *text, int shift, char *result);

/**
 * @brief Decrypts ved brug af Caesar cipher.
 * @param text Input ciphertext.
 * @param shift skift værdig (integer).
 * @param result Output buffer for decrypted tekst.
 */
void caesar_decrypt(const char *text, int shift, char *result);

/**
 * @brief Encrypts teskt ved brug af Vigenere cipher.
 * @param text Input
 * @param key Key string (letters only).
 * @param result Output buffer for ciphertekst.
 */
void vigenere_encrypt(const char *text, const char *key, char *result);

/**
 * @brief Decrypts Vigenere cipher.
 * @param text Input ciphertekst
 * @param key Key streng (bogstaver ).
 * @param result Output buffer for decrypted tekst.
 */
void vigenere_decrypt(const char *text, const char *key, char *result);

#endif 
