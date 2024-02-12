#include <locale.h>
#include <ncurses.h>

#include "sv.h"

#define INITIAL_CAP 16

typedef struct Todo_
{
    char *text;
    bool checked;
} Todo;

typedef struct Todos_
{
    Todo *items;
    size_t count;
    size_t capacity;
} Todos;

int main()
{
    setlocale(LC_ALL, "");
    initscr();
    curs_set(0);
    noecho();

    Todos todos = {0};
    da_append(todos, ((Todo){.text = "lol", .checked = true}));
    da_append(todos, ((Todo){.text = "xd", .checked = false}));
    da_append(todos, ((Todo){.text = "1337", .checked = true}));
    da_append(todos, ((Todo){.text = "wow", .checked = true}));

    int current = 0;

    int c = 0;
    while (1)
    {
        clear();
        refresh();
        for (size_t i = 0; i < todos.count; i++)
        {
            move(i, 0);
            Todo item = todos.items[i];
            const char *spacing = current == i ? " " : "";
            printw("%s[%c] %s", spacing, item.checked ? 'x' : ' ', item.text);
        }
        keypad(stdscr, true);
        c = wgetch(stdscr);
        switch (c)
        {
        case 'q':
            goto end;
        case KEY_UP:
            if (current > 0)
                current--;
            break;
        case KEY_DOWN:
            if (current < todos.count - 1)
                current++;
            break;
        case 's':
            todos.items[current].checked = !todos.items[current].checked;
            break;
        }
    }
end:

    endwin();
    return 0;
}
