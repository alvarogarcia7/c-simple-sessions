#include <stdio.h>
#include <stdbool.h>

#define mymacro(a)            \
printf("");                   \
a##();                        \
printf("a##");


void quit_command(){ printf("quit\n"); }
void help_command(){ printf("help\n"); }

struct command
{
    char *name;
    void (*function) (void);
};

struct command commands[] =
        {
                { "quit", quit_command },
                { "help", help_command },
        };

#define COMMAND(NAME)  { #NAME, NAME ## _command }

#define execute(NAME)  do{ NAME(); printf("%s\n", #NAME); } while (0);

struct command commands_2[] =
        {
                COMMAND (quit),
                COMMAND (help),
        };

int main(int argc, char **argv){
    /*
     * Links:
     *   - https://stackoverflow.com/questions/46356185/pasting-formed-an-invalid-processing-token
     *   - https://gcc.gnu.org/onlinedocs/cpp/Concatenation.html
     *   - https://gcc.gnu.org/onlinedocs/cpp/Stringizing.html
     *   - http://darmawan-salihun.blogspot.com/2016/02/c-macro-101-stringizing-operator-and.html
     */
    execute(quit_command);
    /**
     * Prints:
     * quit // Result from executing `quit_command`
     * quit_command // The macro prints the function name
     */
}
