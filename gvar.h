// Definition.
#ifndef GVAR_H
#define GVAR_H

// Imports.
#include <Arduino.h>
#include <Arduboy2.h>
#include <ArduboyTones.h>

// Control objects.
Arduboy2Base ardu;
Sprites spr;
ArduboyTones snd(ardu.audio.enabled);

// Game state.
#define STATE_LOGO	0
#define STATE_TITLE	1
#define STATE_HELP	2
#define STATE_CHAR	3
#define STATE_LEVEL	4
#define STATE_GAME	5
#define STATE_END	6
#define STATE_CRED	7
#define STATE_OPT	8
#define STATE_SURE	9
byte gameState = STATE_TITLE;

// Characters.
#define CHAR_SOLDIER	0
#define CHAR_MCCREE		1
#define CHAR_GENJI		2
#define CHAR_TORBJORN	3

// Misc. variables.
byte varGameAnimClock = 0;
byte varWaitTimer = 0;
byte varVolumeLevel = 1;

// Menu variables.
byte varMenuChoice = 0;

// Game variables.
byte varPlayerChar = 0;
byte varGameLevel = 0;

// End.
#endif