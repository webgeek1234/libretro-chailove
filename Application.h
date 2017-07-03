#ifndef APPLICATION_H
#define APPLICATION_H

#include <SDL.h>
#include <libretro.h>
#include "chaigame/chaigame.h"

class Application {
public:
    static Application* getInstance();
    static bool isRunning();
	static Application* m_instance;
	static void destroy();

	static retro_input_state_t input_state_cb;
	static retro_input_poll_t input_poll_cb;

	chaigame::keyboard keyboard;
	chaigame::script* script;
	chaigame::filesystem filesystem;
	chaigame::graphics graphics;
	chaigame::image image;
	chaigame::system system;
	chaigame::sound sound;
	chaigame::audio audio;
	chaigame::joystick joystick;

	void quit(void);
	bool load(const std::string& file);
	bool update();
	void draw();

	uint32_t *videoBuffer;
	Uint32 tick;
	SDL_Surface* screen;
	SDL_Event event;
};

#endif
