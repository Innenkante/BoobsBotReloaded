#include "stdafx.h"

Draw::ScreenLocation Draw::WorldToScreen(WorldLocation world_location)
{
	float screen_location[2];
	float world_location_f[] = { world_location.X,world_location.Y,world_location.Z };
	internal::WorldToScreen(0, internal::GetScreenMatrix(), world_location_f, screen_location);

	return ScreenLocation(screen_location);
}

void Draw::DrawString(char * string, ScreenLocation screen_location, Font font, Color color)
{
	float color_f[] = { color.R,color.G,color.B,color.Alpha };
	internal::DrawString(string, 0x7FFFFFFF, internal::Fonts[font], screen_location.X, screen_location.Y, 1.f, 1.f, 0.f, color_f, 0);
}

void Draw::DrawShader(Shader shader, ScreenLocation screen_location, ScreenSize screen_size, float angle, Color color)
{
	float color_f[] = { color.R,color.G,color.B,color.Alpha };
	internal::DrawRotatedPicture(internal::GetScreenMatrix(), screen_location.X, screen_location.Y, screen_size.Width, screen_size.Height, angle, color_f, internal::Shaders[shader]);
}



void Draw::internal::InitializeFonts()
{
	Fonts[0] = RegisterFont("fonts/smallDevFont");
	Fonts[1] = RegisterFont("fonts/bigDevFont");
	Fonts[2] = RegisterFont("fonts/consoleFont");
	Fonts[3] = RegisterFont("fonts/bigFont");
	Fonts[4] = RegisterFont("fonts/smallFont");
	Fonts[5] = RegisterFont("fonts/boldFont");
	Fonts[6] = RegisterFont("fonts/normalFont");
	Fonts[7] = RegisterFont("fonts/extraBigFont");
	Fonts[8] = RegisterFont("fonts/objectiveFont");
}

void Draw::internal::InitializeShaders()
{
	Shaders[0] = RegisterShader("white");
}

void Draw::Initialize()
{
	internal::InitializeFonts();
	internal::InitializeShaders();
}

