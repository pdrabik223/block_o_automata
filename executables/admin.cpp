

#include <windows_console/edit.h>


int main() {

    win_console::edit editor;
//    editor.controlled_view();
//    int h = editor.getHeight(), w = editor.getWidth();
//    for (int i = 0; i < 10; i++) {
//        if (i % 2 == 0) editor.resize(++h, w);
//        else editor.resize(h, ++w);
//        editor.controlled_view();
//        // std::this_thread::sleep_for(std::chrono::seconds(1));
//    }
//
//    for (int i = 0; i < 10; i++) {
//        if (i % 2 == 0) editor.resize(--h, w);
//        else editor.resize(h, --w);
//        editor.controlled_view();
//        //   std::this_thread::sleep_for(std::chrono::seconds(1));
//    }
//
//    std::cout << cc(green, black) << "resize [ ok ]\n";

    editor[{0, 0}] = new barrier_cell(true);
    editor[{0, 1}] = new move_cell(left);
    editor[{0, 2}] = new spawn_cell(left);
    editor[{0, 3}] = new kill_cell();
    editor.save();

    scml con;
    //_setmode(_fileno(stdout), _O_U8TEXT);
    std::cout<<"outcome:"<< (int) con.await_key_press(std::chrono::milliseconds(1000));

    return 0;
}

