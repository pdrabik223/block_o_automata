cmake_minimum_required(VERSION 3.19)
project(block_o_automata)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
set(CELL
        cells_dir/barrier_cell.h cells_dir/barrier_cell.cpp
        cells_dir/cell.h cells_dir/cell.cpp
        cells_dir/cell_tools.h cells_dir/cell_tools.cpp
        cells_dir/empty_cell.h cells_dir/empty_cell.cpp
        cells_dir/goal_cell.h cells_dir/goal_cell.cpp
        cells_dir/kill_cell.h cells_dir/kill_cell.cpp
        cells_dir/move_cell.h cells_dir/move_cell.cpp
        cells_dir/spawn_cell.h cells_dir/spawn_cell.cpp
        cells_dir/turn_cell.h cells_dir/turn_cell.cpp)

set(LEVEL
        level_dir/level_pick.h level_dir/level_pick.cpp
        level_dir/level_edit.h level_dir/level_edit.cpp
        level_dir/level_play.h level_dir/level_play.cpp
        level_dir/level_info.h level_dir/level_info.cpp
        )
set(WIN_COL_TOOLS
        windows_console_tools/win_colors.h
        windows_console_tools/win_colors.cpp
        )
set(ENGINE
        board.h
        board.cpp
        )
add_executable(basic_main executables/main.cpp
        ${CELL}
        ${LEVEL}
        ${WIN_COL_TOOLS}
        ${ENGINE})

add_executable(admin executables/admin.cpp
        ${CELL}
        ${LEVEL}
        ${WIN_COL_TOOLS}
        ${ENGINE})

add_executable(level_edit executables/level_editor.cpp
        ${CELL}
        ${LEVEL}
        ${WIN_COL_TOOLS}
        ${ENGINE})

add_executable(level_pick executables/level_picker.cpp
        ${CELL}
        ${LEVEL}
        ${WIN_COL_TOOLS}
        ${ENGINE}
        )
add_executable(level_play executables/level_player.cpp
        ${CELL}
        ${LEVEL}
        ${WIN_COL_TOOLS}
        ${ENGINE}
        )


add_executable(block_o_automata executables/win_console_ui.cpp
        ${CELL}
        ${LEVEL}
        ${WIN_COL_TOOLS}
        ${ENGINE}
        )