enum color_mode {ANSI, WIN, NO} color_mode=NO;
enum color {BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE, BBLACK, BRED, BGREEN, BYELLOW, BBLUE, BMAGENTA, BCYAN, BWHITE};
enum surface {FG, BG};
bool isModeAvailable(color_mode);
void setColor(color, surface);

