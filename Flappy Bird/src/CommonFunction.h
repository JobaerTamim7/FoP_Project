#pragma once

#include<iostream>
#include<fstream>
#include<stdio.h>
#include<map>
#include<string.h>
#include<sstream>
#include<SDL.h>
#include<SDL_image.h>
#include<SDL_ttf.h>
#include"config.h"


namespace common {
	SDL_Window* set_window(const char*, const char*);
	SDL_Texture* load_texture(const char*, SDL_Renderer*);
	SDL_Texture* load_font_texture(const char*, std::string, SDL_Renderer*, SDL_Color, int);
	void display_setter(SDL_Renderer*, SDL_Texture*);
	bool mouse_collision_rect(SDL_Rect);
	class Transition {
	public:
		Transition();
		bool active;
		int alpha_channel;
	};
	void transition(SDL_Renderer*, Transition& );
	std::string int_to_str(int);

};
