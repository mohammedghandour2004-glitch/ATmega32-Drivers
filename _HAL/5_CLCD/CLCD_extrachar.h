/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< CLCD_extrachar.h >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 * Created on: September 5, 2026
 * Author: MOHAMMED GHANDOUR
 * Layer : _HAL
 * SWC   : CLCD
 */

#ifndef _HAL_5_CLCD_CLCD_EXTRACHAR_H_
#define _HAL_5_CLCD_CLCD_EXTRACHAR_H_

/*

 We draw each char on web site ===>> https://maxpromer.github.io/LCD-Character-Creator/

 Hint : *this web site already neglect the first 3 bits in each byte = 0 (on the left side)
        *take the hex value or ad 000 on the left

 * Character Sets:
 * 1. Last Name Set  -> "غنضور"
 * 2. Name Set       -> "محمد"
 * 3. Symbol Set      -> Symbols
*/



/*
 * This Character Set is used to display the last name:
 *
 *                  غنضور
 *
 * Only the required Arabic letters are stored.
 *
 * Char0 -> غ
 * Char1 -> ن
 * Char2 -> ض
 * Char3 -> و
 * Char4 -> ر
 *
 * Char5, Char6 and Char7 are reserved for future use.
 */

u8 CLCD_u8LastNameSet[] =
{
    /*====================== Last Name : "غنضور" ======================*/

    0x04, 0x00, 0x0E, 0x11, 0x11, 0x0E, 0x00, 0x04, // حرف "غ" <- Char1
    0x00, 0x00, 0x12, 0x12, 0x12, 0x1E, 0x00, 0x04, // حرف "ن" <- Char2
    0x00, 0x0E, 0x12, 0x12, 0x1E, 0x10, 0x04, 0x00, // حرف "ض" <- Char3
    0x00, 0x00, 0x0C, 0x12, 0x12, 0x0C, 0x00, 0x00, // حرف "و" <- Char4
    0x00, 0x00, 0x04, 0x02, 0x02, 0x1C, 0x00, 0x00  // حرف "ر" <- Char5
};



/*
 * This Character Set is used to display the first name:
 *
 *                   محمد
 *
 * Char0 -> م
 * Char1 -> ح
 * Char2 -> م
 * Char3 -> د
 *
 * The same "م" character can be displayed more than once.
 */

u8 CLCD_u8NameSet[] =
{
    /*======================== Name : "محمد" ==========================*/

    0x00, 0x1C, 0x12, 0x12, 0x1E, 0x10, 0x10, 0x00, // حرف "م" <- Char1
    0x00, 0x00, 0x12, 0x12, 0x12, 0x0C, 0x00, 0x00, // حرف "ح" <- Char2
    0x00, 0x1C, 0x12, 0x12, 0x1E, 0x10, 0x10, 0x00, // حرف "م" <- Char3
    0x00, 0x00, 0x10, 0x10, 0x10, 0x1E, 0x00, 0x00  // حرف "د" <- Char4
};



/*
 * This Character Set contains useful symbols.
 *
 * Char0 -> Heart
 * Char1 -> Star
 * Char2 -> Smile
 * Char3 -> Arrow Up
 * Char4 -> Arrow Down
 * Char5 -> Arrow Left
 * Char6 -> Arrow Right
 * Char7 -> Check
 */

u8 CLCD_u8SymbolSet[] =
{
    /*========================== Symbols ==============================*/

    0x00, 0x0A, 0x1F, 0x1F, 0x0E, 0x04, 0x00, 0x00, // Heart <- Char1
    0x04, 0x0E, 0x15, 0x1F, 0x0E, 0x15, 0x04, 0x00, // Star  <- Char2
    0x00, 0x0A, 0x00, 0x00, 0x11, 0x0E, 0x00, 0x00, // Smile <- Char3
    0x04, 0x0E, 0x15, 0x04, 0x04, 0x04, 0x04, 0x00, // Up    <- Char4
    0x04, 0x04, 0x04, 0x04, 0x15, 0x0E, 0x04, 0x00, // Down  <- Char5
    0x04, 0x08, 0x1F, 0x08, 0x04, 0x00, 0x00, 0x00, // Left  <- Char6
    0x04, 0x02, 0x1F, 0x02, 0x04, 0x00, 0x00, 0x00, // Right <- Char7
    0x00, 0x01, 0x03, 0x16, 0x0C, 0x08, 0x00, 0x00  // Check <- Char8
};


#endif /* _HAL_5_CLCD_CLCD_EXTRACHAR_H_ */
