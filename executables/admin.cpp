

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

//    editor[{0, 0}] = new barrier_cell(true);
//    editor[{0, 1}] = new move_cell(left);
//    editor[{0, 2}] = new spawn_cell(left);
//    editor[{0, 3}] = new kill_cell();
//    editor.save();

    scml con;

    int futore = (int) con.await_key_press(std::chrono::milliseconds(500));

    std::wcout << L"outcome";
    std::wcout << futore + 10;


    return 0;
}

KEY_EVENT_RECORD read_event() {
// chcemy czytac tylko po 1 inpucie at the time

    const DWORD size_input_records = 1;
    INPUT_RECORD input_records[size_input_records];

    DWORD inputs_read;

    const HANDLE std_input = GetStdHandle(STD_INPUT_HANDLE);

    ReadConsoleInput(std_input, input_records, size_input_records, &inputs_read);


// zwracamy otrzymany input
    return input_records[0].Event.KeyEvent;
}
