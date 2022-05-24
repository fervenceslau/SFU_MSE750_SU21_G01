/*! \file  Graphics.h
 *  \brief Contains definitions used to create and display animations
	and other drawable content such as title screen and scoreboard.
 */

#ifndef __GRAPHICS__
#define __GRAPHICS__

#ifdef SIMULATION
#define	GRAPHICS_SIMULATION_SPEED	5
#else
#define	GRAPHICS_SIMULATION_SPEED	1
#endif

#define	SCOREBOARDH					8
#define FPS_SCREEN	10

#include <stdint.h>


/************************************************************
 *  Animation Type
 ************************************************************/

typedef struct Anim {
	const uint8_t 	*sprite;
	const float 	*seq_times;
	const uint8_t 	size_sprite;
	const uint8_t 	num_frames;
	uint8_t			count_seq;
	float 			time_ref;
} Animation_t;


/************************************************************
 *  Bitmap and Sprite Initialization
 ************************************************************/

static const uint8_t BMP_Title[] = {
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x7f, 0x7f, 0x7f, 0x3f, 0x1f, 0x0f, 0x0f, 0x1f, 0x3f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x3f, 0x0f, 0x87, 0xc7, 0xe3, 0xf1, 0xf9, 0xfc, 0xfc, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xf8, 0xf8, 
	0xf8, 0xf8, 0xfc, 0xfe, 0xfe, 0xfc, 0xf8, 0xf1, 0xc3, 0x83, 0x07, 0x0f, 0x1f, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x1f, 0x0f, 0x0f, 0x0f, 0x1f, 
	0x3f, 0x3f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x9f, 0x03, 0x01, 0xf1, 0xf9, 0xf1, 0x61, 0x63, 0xff, 0xff, 0xff, 0x0f, 0x07, 
	0x03, 0xe3, 0x63, 0x06, 0x04, 0xfe, 0xff, 0xff, 0x3f, 0x03, 0x03, 0xe3, 0xe3, 0xe3, 0xf7, 0xff, 0xff, 0x1f, 0x07, 0x03, 0xe3, 0xe3, 0x03, 0x07, 0x9f, 0xff, 0xff, 0xf7, 0x03, 0x07, 0x06, 0xe2, 
	0xe2, 0x06, 0x0e, 0xff, 0xff, 0xff, 0x1f, 0x07, 0x07, 0xe3, 0x03, 0x03, 0x03, 0xff, 0xff, 0xfc, 0xf8, 0xf8, 0xf8, 0xf8, 0xf0, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0xf8, 0xf1, 0xf1, 0xf8, 0xf8, 0x7e, 0x7f, 0x3f, 0x3f, 0xfe, 0xfc, 0xfc, 0xec, 0xcc, 0x04, 0x06, 0xc7, 0xe7, 0xf7, 0xf6, 0xec, 0xcc, 0x3f, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfc, 0xfc, 0x3f, 0x07, 0x84, 0xec, 0xff, 0xff, 0xff, 0xfe, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 
	0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x1f, 0x0f, 0x0f, 0x0f, 0x03, 0x03, 0x07, 0x07, 0x07, 0x03, 0x83, 0xc3, 0xc1, 0xc0, 0xe0, 0xe0, 
	0xf0, 0xf8, 0xf8, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xf8, 0xf9, 0xf3, 0xf7, 0xe7, 0xc3, 0xc9, 0x8c, 0x9f, 0x9f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x9f, 
	0x9f, 0x8f, 0xcf, 0xe7, 0xe3, 0xf1, 0xf8, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xf8, 0xf8, 0xf8, 0xf0, 0xf0, 0xe0, 0xe2, 0xc7, 0xcf, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff 
};

static const uint8_t BMP_Lives[] = {
	0x05, 0x04, 0x02, 0x07, 0x0e, 0x07, 0x02
};

static const uint8_t Sprite_Player[][18] = {
	{0x10, 0x08, 0x00, 0x10, 0x28, 0x01, 0x3b, 0x3f, 0x3e, 0x7e, 0xfc, 0xfc, 0xf8, 0x78, 0x78, 0x30, 0x30, 0x30},
	{0x10, 0x08, 0x10, 0x00, 0x28, 0x01, 0x3b, 0x3f, 0x3e, 0x7e, 0xfc, 0xfc, 0xf8, 0x78, 0x78, 0x30, 0x30, 0x30},
	{0x10, 0x08, 0x10, 0x28, 0x10, 0x01, 0x3b, 0x3f, 0x3e, 0x7e, 0xfc, 0xfc, 0xf8, 0x78, 0x78, 0x30, 0x30, 0x30},
	{0x10, 0x08, 0x10, 0x00, 0x28, 0x11, 0x3b, 0x3f, 0x3e, 0x7e, 0xfc, 0xfc, 0xf8, 0x78, 0x78, 0x30, 0x30, 0x30}
};

static const uint8_t Sprite_Enemy[][10] = {
	{0x08, 0x08, 0x7e, 0xff, 0xff, 0x18, 0x18, 0xff, 0xff, 0x7e},
	{0x08, 0x08, 0x3c, 0x7e, 0xff, 0x3c, 0x3c, 0xff, 0x7e, 0x3c},
	{0x08, 0x08, 0x00, 0x3c, 0x7e, 0xff, 0xff, 0x7e, 0x3c, 0x00},
	{0x08, 0x08, 0x3c, 0x7e, 0xff, 0x3c, 0x3c, 0xff, 0x7e, 0x3c}
};

static const uint8_t Sprite_Explosion[][10] = {
	{0x08, 0x08, 0x00, 0x00, 0x24, 0x18, 0x18, 0x24, 0x00, 0x00},
	{0x08, 0x08, 0x00, 0x42, 0x18, 0x24, 0x24, 0x18, 0x42, 0x00},
	{0x08, 0x08, 0x42, 0x99, 0x00, 0x42, 0x42, 0x00, 0x99, 0x42},
	{0x08, 0x08, 0x3c, 0x00, 0x81, 0x81, 0x81, 0x81, 0x00, 0x3c},
	{0x08, 0x08, 0x24, 0x00, 0x99, 0x24, 0x24, 0x99, 0x00, 0x24},
	{0x08, 0x08, 0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00}
};

static const unsigned char Sprite_Laser[][10] = {
	{0x08, 0x02, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03}
};

static const unsigned char Sprite_Bullet[][6] = {
	{0x04, 0x04, 0x06, 0x0f, 0x0f, 0x06}
};


/************************************************************
 *  Sprites' Timing
 ************************************************************/

static const float Times_Player[] = {.5, .5, .5, .5};
static const float Times_Enemy[]  = {.5, .5, .5, .5};
static const float Times_Explosion[] = {.5, .5, .5, .5, .5, .5};
static const float Times_Laser[] = {1};
static const float Times_Bullet[] = {1};


/************************************************************
 *  External Variables
 ************************************************************/

extern uint8_t lock_graphics;


/************************************************************
 *  Functions
 ************************************************************/

/** 
 *  Initializes Timer 1 counter used to consistently refresh the screen with FPS_SCREEN frames per second
 */
void Graphics_Init(void);

/** 
 *  Callback function to refresh screen updates
 */
void Graphics_Callback(void);

/** 
 *  Draws the current game scoreboard, with time, player lives and score
 */
void drawScoreBoard(uint8_t lives, uint16_t time, uint16_t score);

/** 
 *  Draws the title screen
 */
void drawTitle(void);

/** 
 *  Draws game over text
 */
void drawGameOver(uint16_t score);

/** 
 *  Draws a sigle animation step at given position.
 */
uint8_t playAnimationStep(int8_t pos_x, int8_t pos_y, Animation_t *anim, uint8_t is_loop);

#endif