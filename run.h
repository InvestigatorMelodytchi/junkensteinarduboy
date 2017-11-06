// Definition.
#ifndef RUN_H
#define RUN_H

// Running the game.
void Run() {
	// Global animation clock.
	if (varGameAnimClock > 1) varGameAnimClock--;
	else varGameAnimClock = 60;
	
	// General wait timer.
	if (varWaitTimer > 0) {varWaitTimer--;}
	
	// State switching.
	switch(gameState) {
		// Logo.
		case STATE_LOGO:
			break;
			
		// Title screen.
		case STATE_TITLE:
			if (ardu.justPressed(UP_BUTTON)) {if (varMenuChoice > 0) varMenuChoice--; else varMenuChoice = 3; snd.tones(sndMenuSelect);}
			if (ardu.justPressed(DOWN_BUTTON)) {if (varMenuChoice < 3) varMenuChoice++; else varMenuChoice = 0; snd.tones(sndMenuSelect);}
			if (ardu.justPressed(B_BUTTON)) {
				if (varMenuChoice == 0) {varMenuChoice = 0; gameState = STATE_CHAR;}
				else if (varMenuChoice == 1) {varMenuChoice = 0; gameState = STATE_OPT;}
				else if (varMenuChoice == 2) {gameState = STATE_HELP;}
				else if (varMenuChoice == 3) {gameState = STATE_CRED;}
				snd.tones(sndMenuConfirm);
			}
			break;
			
		// Help screen.
		case STATE_HELP:
			if (ardu.justPressed(A_BUTTON) || ardu.justPressed(B_BUTTON)) {gameState = STATE_TITLE; snd.tones(sndMenuCancel);}
			break;
			
		// Hero select.
		case STATE_CHAR:
			if (ardu.justPressed(LEFT_BUTTON)) {if (varMenuChoice > 0) varMenuChoice--; else varMenuChoice = 3; snd.tones(sndMenuSelect);}
			if (ardu.justPressed(RIGHT_BUTTON)) {if (varMenuChoice < 3) varMenuChoice++; else varMenuChoice = 0; snd.tones(sndMenuSelect);}
			if (ardu.justPressed(B_BUTTON)) {varPlayerChar = varMenuChoice; varMenuChoice = 0; gameState = STATE_LEVEL; snd.tones(sndMenuConfirm);}
			else if (ardu.justPressed(A_BUTTON)) {varMenuChoice = 0; gameState = STATE_TITLE; snd.tones(sndMenuCancel);}
			break;
			
		// Difficulty select.
		case STATE_LEVEL:
			if (ardu.justPressed(UP_BUTTON)) {if (varMenuChoice > 0) varMenuChoice--; else varMenuChoice = 2; snd.tones(sndMenuSelect);}
			if (ardu.justPressed(DOWN_BUTTON)) {if (varMenuChoice < 2) varMenuChoice++; else varMenuChoice = 0; snd.tones(sndMenuSelect);}
			if (ardu.justPressed(A_BUTTON)) {varMenuChoice = varPlayerChar; gameState = STATE_CHAR; snd.tones(sndMenuCancel);}
			break;
			
		// Gameplay.
		case STATE_GAME:
			break;
			
		// End.
		case STATE_END:
			break;
			
		// Credits.
		case STATE_CRED:
			if (ardu.justPressed(A_BUTTON) || ardu.justPressed(B_BUTTON)) {gameState = STATE_TITLE; snd.tones(sndMenuCancel);}
			break;
			
		// Options.
		case STATE_OPT:
			if (ardu.justPressed(UP_BUTTON)) {if (varMenuChoice > 0) varMenuChoice--; else varMenuChoice = 2; snd.tones(sndMenuSelect);}
			if (ardu.justPressed(DOWN_BUTTON)) {if (varMenuChoice < 2) varMenuChoice++; else varMenuChoice = 0; snd.tones(sndMenuSelect);}
			if (ardu.justPressed(B_BUTTON)) {
				if (varMenuChoice == 0) {
					if (varVolumeLevel < 2) varVolumeLevel++;
					else varVolumeLevel = 0;
					if (varVolumeLevel == 0) ardu.audio.off();
					else if (varVolumeLevel == 1) {ardu.audio.on(); snd.volumeMode(VOLUME_ALWAYS_NORMAL);}
					else if (varVolumeLevel == 2) snd.volumeMode(VOLUME_ALWAYS_HIGH);
				}
				else if (varMenuChoice == 2) {varMenuChoice = 1; gameState = STATE_TITLE;}
				snd.tones(sndMenuConfirm);
			}
			else if (ardu.justPressed(A_BUTTON)) {varMenuChoice = 1; gameState = STATE_TITLE; snd.tones(sndMenuCancel);}
			break;
	}
	
	// End.
}

// End.
#endif