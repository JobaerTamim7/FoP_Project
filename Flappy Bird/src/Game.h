#pragma once
#include"CommonFunction.h"
#include<vector>
#include"Pipe.h"
#include"Bird.h"
#include"Restart.h"

class Pipe;
class Bird;

class Game {
public:
	Game(SDL_Window*);
	void render();
	void handle_event();
	void free_memory();
	void update();
	void pipe_generate(SDL_Window*);
	void score_render();
	void pause_render();
	void start_count();

	bool get_quit_state() { return quit_state; }
	bool get_main_menu_state() { return main_menu_state; }
	bool get_game_over() { return game_over; }
	bool is_collide();

	int get_score() { return score; }

	int t;

private:
	SDL_Renderer* renderer;
	SDL_Window* win;

	Bird* bird;
	Restart* re;

	std::vector<Pipe> pipes;
	std::map<std::string, SDL_Texture*> texture_map;

	int score;
	Uint32 pause_interval;
	
	const SDL_Rect bg_rect = { 0,0,WINDOW_WIDTH,WINDOW_HEIGHT };
	const SDL_Rect test = { 100,100,100,100 };
	SDL_Rect base_rect = { 0,615,WINDOW_WIDTH,162 };
	SDL_Rect base_rect2 = { WINDOW_WIDTH,615,WINDOW_WIDTH,162 };
	SDL_Rect score_rect = { WINDOW_WIDTH / 2,10,70,90 };
	SDL_Rect t_rect = { WINDOW_WIDTH / 2-75,WINDOW_HEIGHT/2, 100, 200 };
	const SDL_Rect pause_bg_rect = { 83,0,436,648 };
	const SDL_Rect main_menu_button_rect = { 191,174,240,90 };
	const SDL_Rect resume_button_rect = { 191, 351,240,90 };
	const SDL_Rect main_menu_rect = { 218,169,193,84 };
	const SDL_Rect resume_rect = { 221,334,173,105 };
 
	bool game_over;
	bool main_menu_state;
	bool quit_state;
	bool re_state;
	bool pause;
	bool pause_done;
};


