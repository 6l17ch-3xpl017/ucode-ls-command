#include "uls.h"
#include "prototypes.h"

// ToDo: Terminal defaults to -Cq, non-terminal defaults to -1. Make logic for terminal output and non-terminal
// ToDo: /* The -d option turns off the -R option. */
// ToDo: /* The -c and -u options override each other. */
// ToDo: /*
//		 * The -1, -C, -x and -l options all override each other so
//		 * shell aliasing works right.
//		 */
// ToDo: Add last sort option to main struct

int main(int argc, char **argv) {
    //ToDo:!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! ********** !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //ToDo:!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! Close pDir !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //ToDo:!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! ********** !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    /* DEBUG ONLY Check print terminal windows size DEBUG ONLY */
//    struct winsize w;
//    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
//
//    printf ("lines %d\n", w.ws_row);
//    printf ("columns %d\n\n", w.ws_col);

    print_l(argv[1]);

//    if (argc == 1)
//    {                           //ToDo: Create Struct
//                                //ToDo: Check Errors
//                                //ToDo: Change working dir
//        print_base(".");
//    } //ToDo: check flag or path // Make line parser
//    else if (argc == 2 && argv[1][0] != '-')
//    {
//        print_base(argv[1]);
//    }
//    else
//    {
//        argv[0] = cutter(argv[0], '/', 2);                   //ToDo: Change 2 to 1
//        run(argc, argv);
//    }

//    struct stat buf;

//    stat("../test_dir/c_file.cpp", &buf);

}
