#include "Principal.h"

using namespace std;

void init();
void deinit();

int main()
{
    init();
    Principal ObjPrincipal;

	return 0;
}
END_OF_MAIN()


void init()
{
    allegro_init();
    install_timer();
    install_keyboard();
    install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL);
    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0);
    set_window_title("SUPER MARIO - by Marcio Victor");

	/* add other initializations here */
}

void deinit()
{
	clear_keybuf();
	/* add other deinitializations here */
}
