

#include <windows_console/edit.h>

int main() {

    win_console::Edit editor;
    Scml con;
    std::wcout << L"3\t";
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::wcout << L"2\t";
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::wcout << L"1\t";
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::wcout << L"go!\n";


    int futore = (int)con.AwaitKeyPress(std::chrono::milliseconds(1000));

    std::wcout << L"outcome";
    std::wcout << futore + 10;

    system("pause");
    return 0;
}

