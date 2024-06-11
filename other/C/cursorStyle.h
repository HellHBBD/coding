#define SETPOS(x, y) printf("\e[%d;%dH", x, y)
/*  y--> */
/* x     */
/* |     */
/* v     */

#define FONT(n) printf("\e[%dm", (n))
#define BG(n) printf("\e[%dm", (n + 10))

#define BOLD 1
#define FINE 2
#define ITALIC 3
#define UNDERLINE 4
#define BLINK 5
// #define BLINK 6
#define REVERSE 7
#define VOID 8
#define DELETE_LINE 9
#define DOUBLE_UNDERLINE 21

#define BLACK 30
#define RED 31
#define GREEN 32
#define YELLOW 33
#define BLUE 34
#define VIOLET 35
#define CYAN 36
#define WHITE 37

#define L_BLACK 90
#define L_RED 91
#define L_GREEN 92
#define L_YELLOW 93
#define L_BLUE 94
#define L_VIOLET 95
#define L_CYAN 96
#define L_WHITE 97

#define CURSOR_STYLE(n) printf("\e[%d q", n)

#define DEFAULT 0
// #define BAR_BLINK 1
#define BLOCK_BLINK 2
#define BLOCK_STEADY 3
#define UNDERLINE_BLINK 4
#define UNDERLINE_STEADY 5
#define BAR_BLINK 6
#define BAR_STEADY 7
