#ifndef _GH_NIRCEK_LABIRYNT_COLOR_H_
#define _GH_NIRCEK_LABIRYNT_COLOR_H_
enum color_mode {ANSI, WIN, NO}; //g_color_mode
enum color {BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE, BBLACK, BRED, BGREEN, BYELLOW, BBLUE, BMAGENTA, BCYAN, BWHITE};
enum surface {FG, BG};
bool isModeAvailable(color_mode);
void setColor(color, surface);
#endif
