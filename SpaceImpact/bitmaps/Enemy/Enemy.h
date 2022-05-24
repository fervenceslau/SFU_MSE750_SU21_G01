// Code to be inserted in Graphics.h
static const unsigned char Sprite_Enemy[][10] = {
	{0x08, 0x08, 0x7e, 0xff, 0xff, 0x18, 0x18, 0xff, 0xff, 0x7e},
	{0x08, 0x08, 0x3c, 0x7e, 0xff, 0x3c, 0x3c, 0xff, 0x7e, 0x3c},
	{0x08, 0x08, 0x00, 0x3c, 0x7e, 0xff, 0xff, 0x7e, 0x3c, 0x00},
	{0x08, 0x08, 0x3c, 0x7e, 0xff, 0x3c, 0x3c, 0xff, 0x7e, 0x3c}
};

static const float Times_Enemy[] = {1, 1, 1, 1};


// Code to be inserted in Objects.h
static Object_t Enemy = {
	0, 0, 1, 1,
	{
		// Idle animation
		(unsigned char *) Sprite_Enemy,
		(float *) Times_Enemy, 10, 4, 0, 0
	},
	{
		// Default death animation
		(unsigned char *) Sprite_Explosion,
		(float *) Times_Explosion, 10, 6, 0, 0
	}
};