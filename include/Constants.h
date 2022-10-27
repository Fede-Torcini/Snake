#pragma once

namespace snakegame
{
namespace constants
{
	const float SPRITES_HEIGHT = 32.0f;
	const float SPRITES_WIDTH = 32.0f;

	const int HEAD_SPRITE_POSITION = 2;
	const int BODY_SPRITE_POSITION = 1;

	const int WINDOW_HEIGHT = 600;
	const int WINDOW_WIDTH = 800;
	const std::string WINDOW_NAME = "SNAKE";

	const float SNAKE_SPEED = 5.0f;
	const std::string SNAKE_TEXTURE_DIRECTORY = "src/resources/snake_skin.png";

	const std::string RAT_TEXTURE_DIRECTORY = "src/resources/rat.png";

	const int SCORE_TEXT_SIZE = 300;
	const std::string TEXT_FONT_DIR = "src/resources/sansation.ttf";
}
}