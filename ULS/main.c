#include "uls.h"

int main(int argc, char **argv)
{
    t_main *main = init_main(argc, argv);
    run(main);
    return 0;
}