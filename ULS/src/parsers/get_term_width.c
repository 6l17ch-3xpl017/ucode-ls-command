#include "uls.h"

int get_term_width(void)
{
    struct winsize ws;

    ioctl(STDIN_FILENO, TIOCGWINSZ, &ws);
    if (isatty(1) != 0)
        return ws.ws_col;

    return 79;
}