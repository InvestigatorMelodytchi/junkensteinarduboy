// Definition.
#ifndef DRAW_H
#define DRAW_H

// Drawing.
void Draw() {
	// Clearing.
	ardu.clear();
	
	// State switching.
	switch(gameState) {
		// Logo.
		case STATE_LOGO:
			break;
			
		// Title screen.
		case STATE_TITLE:
			spr.drawSelfMasked(4, 1, sprTitleLogo, 0);
			for(uint8_t i = 0; i < 4; i++) {
				if ((uint8_t)varMenuChoice != i || (varGameAnimClock%4 > 1)) DrawTextCenter(64, 32 + (i * 8), i);
			}
			break;
			
		// Help screen.
		case STATE_HELP:
			DrawTextCenter(64, 4, STR_HELP);
			spr.drawSelfMasked(51, 19, sprHelpQr, 0);
			DrawTextCenter(64, 52, STR_HELP + 1);
			break;
			
		// Hero select.
		case STATE_CHAR:
			// Icon and name.
			spr.drawSelfMasked(0, 0, sprCharIcon, (uint8_t)varMenuChoice);
			DrawTextCenter(64, 25, STR_NAME + (uint8_t)varMenuChoice);
			
			// Difficulty.
			DrawText(80, 0, STR_DIFF);
			spr.drawSelfMasked(80, 8, sprCharStar, 0);
			if (varMenuChoice > 0) spr.drawSelfMasked(88, 8, sprCharStar, 0);
			if (varMenuChoice == 2) spr.drawSelfMasked(96, 8, sprCharStar, 0);
			
			// Arrows.
			spr.drawSelfMasked(0, 25, sprMenuArrow, 0);
			spr.drawSelfMasked(120, 25, sprMenuArrow, 1);
			
			// Ability info.
			for(uint8_t i = 0; i < 4; i++) {
				spr.drawSelfMasked(8 + (8 * i), 32 + (8 * i), sprAbilityIcon, ((uint8_t)varMenuChoice * 4) + i);
				DrawText(28 + (8 * i), 33 + (8 * i), STR_ABILITY + ((uint8_t)varMenuChoice * 4) + i);
			}
			break;
			
		// Difficulty select.
		case STATE_LEVEL:
			// Selected hero.
			DrawTextCenter(64, 0, STR_INQUOTE + (uint8_t)varPlayerChar);
			spr.drawSelfMasked(32, 8, sprCharIcon, (uint8_t)varPlayerChar);
			
			// Menu.
			for(uint8_t i = 0; i < 3; i++) {
				if ((uint8_t)varMenuChoice != i || (varGameAnimClock%4 > 1)) DrawTextCenter(64, 36 + (i * 8), STR_LEVEL + i);
			}
			break;
			
		// Gameplay.
		case STATE_GAME:
			break;
			
		// End.
		case STATE_END:
			break;
			
		// Credits.
		case STATE_CRED:
			spr.drawSelfMasked(4, 1, sprTitleLogo, 0);
			for(uint8_t i = 0; i < 4; i++) {
				DrawText(0, 32 + (i * 8), STR_CREDITS + i);
			}
			break;
			
		// Options.
		case STATE_OPT:
			spr.drawSelfMasked(4, 1, sprTitleLogo, 0);
			if ((uint8_t)varMenuChoice != 0 || (varGameAnimClock%4 > 1)) DrawTextCenter(64, 32, STR_OPTIONS + (uint8_t)varVolumeLevel);
			for(uint8_t i = 1; i < 3; i++) {
				if ((uint8_t)varMenuChoice != i || (varGameAnimClock%4 > 1)) DrawTextCenter(64, 32 + (i * 8), STR_OPTIONS + 2 + i);
			}
			break;
	}
	
	// Finalizing.
	ardu.display();
}

// End.
#endif