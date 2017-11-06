// Getting character ID.
byte GetChar(char fC) {
	if (fC >= 65 && fC <= 90) return(fC - 65);
	else if (fC >= 97 && fC <= 122) return(fC - 97);
	else if (fC >= 48 && fC <= 57) return(fC - 22);
	else if (fC == 46) return(36);
	else if (fC == 44) return(37);
	else if (fC == 39) return(38);
	else if (fC == 33) return(39);
	else if (fC == 63) return(40);
	else if (fC == 32 || fC == 95) return(41);
	else if (fC == 96) return(42);
	else if (fC == 132) return(43);
	else return(255);
}

// Getting string length.
/*byte GetLength(String fStr) {
	for(byte fi = 0; fi < 32; fi++) {
		if (fStr[(uint8_t)fi] == "\0") return(fi);
	}
	return(32);
}*/

// Drawing text.
void DrawText(byte fX, byte fY, byte fStr) {
	for(byte fi = 0; fi < strlen(strcpy_P(strBuf, (char*)pgm_read_word(&strDb[fStr]))); fi++) {
		spr.drawSelfMasked(fX + (fi * 4), fY, sprFont, (byte)GetChar(strcpy_P(strBuf, (char*)pgm_read_word(&strDb[fStr]))[(uint8_t)fi]));
	}
}

// Drawing centered text.
void DrawTextCenter(byte fX, byte fY, byte fStr) {
	DrawText(fX - (strlen(strcpy_P(strBuf, (char*)pgm_read_word(&strDb[fStr]))) * 2), fY, fStr);
}

// Getting whether something is even or not.
bool Even(byte fX) {
	return(fX % 2 == 0);
}