// Code to be inserted in Graphics.h
static const unsigned char Sprite_Explosion[][10] = {
	{0x08, 0x08, 0x00, 0x00, 0x24, 0x18, 0x18, 0x24, 0x00, 0x00},
	{0x08, 0x08, 0x00, 0x42, 0x18, 0x24, 0x24, 0x18, 0x42, 0x00},
	{0x08, 0x08, 0x42, 0x99, 0x00, 0x42, 0x42, 0x00, 0x99, 0x42},
	{0x08, 0x08, 0x3c, 0x00, 0x81, 0x81, 0x81, 0x81, 0x00, 0x3c},
	{0x08, 0x08, 0x24, 0x00, 0x99, 0x24, 0x24, 0x99, 0x00, 0x24},
	{0x08, 0x08, 0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00}
};

static const float Times_Explosion[] = {1, 1, 1, 1, 1, 1};


// Code to be inserted in Objects.h
static Object_t Explosion = {
	0, 0, 1, 1,
	{
		// Idle animation
		(unsigned char *) Sprite_Explosion,
		(float *) Times_Explosion, 10, 6, 0, 0
	},
	{
		// Default death animation
		(unsigned char *) Sprite_Explosion,
		(float *) Times_Explosion, 10, 6, 0, 0
	}
};