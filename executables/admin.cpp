

#include <windows_console/edit.h>


int main() {

    win_console::edit editor;
    editor.controlled_view();
    int h = editor.getHeight(), w = editor.getWidth();
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) editor.resize(++h, w);
        else editor.resize(h, ++w);
        editor.controlled_view();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) editor.resize(--h, w);
        else editor.resize(h, --w);
        editor.controlled_view();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}

