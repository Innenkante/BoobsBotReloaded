#include "stdafx.h"
#include "Draw.h"

Draw::ScreenLocation Draw::WorldToScreen(WorldLocation world_location)
{
	float screen_location[2];

	internal::WorldToScreen(0, internal::GetScreenMatrix(), world_location.ToFloatArray(), screen_location);

	return ScreenLocation(screen_location);
}

void Draw::DrawString(char * string, ScreenLocation screen_location, char * font, Color color)
{
	internal::DrawString(string, strlen(string), Fonts[font], screen_location.X, screen_location.Y, 1.f, 1.f, 0.f, color.ToFloatArray(), 0);
}

void Draw::DrawShader(char * shader, ScreenLocation screen_location, ScreenSize screen_size, float angle, Color color)
{
	internal::DrawRotatedPicture(internal::GetScreenMatrix(), screen_location.X, screen_location.Y, screen_size.Width, screen_size.Height, angle, color.ToFloatArray(), Shaders[shader]);
}
