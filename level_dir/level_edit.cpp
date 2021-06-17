//
// Created by pc on 13.05.2021.
//

#include "level_edit.h"

using namespace le;

//todo make logs appear at the bottom of screen
// when cursor is over functional icons display what they do
//
PlayerAction LevelEdit::AnalyzeMovement(char key) {
    switch (key) {
        case 'a':
          cursor_position_.y_--;
            break;
        case 'w':
          cursor_position_.x_--;
            break;
        case 's':
          cursor_position_.x_++;
            break;
        case 'd':
          cursor_position_.y_++;
            break;
        case 32:
            return RUN_SIMULATION;
        case 'q':
            return QUIT_EDIT;
        case 'x':
            if (cursor_position_.x_ < GetHeight() &&
              cursor_position_.y_ < GetWidth())
              level_[cursor_position_.ToUint(GetWidth())] = new EmptyCell();
        break;
        case 13:
            // set pawn in place
            if (cursor_position_.x_ < GetHeight() &&
                cursor_position_.y_ < GetWidth())
              CopyCell(cursor_position_, all_blocks_[current_block_]);
            else {


                /// if cursor is on " plus on the right"
                if (cursor_position_ == Coord(GetHeight() - 1, GetWidth())) {
                  Resize(GetHeight(), GetWidth() + 1);
                  cursor_position_.y_++;
                    /// i'm so sorry but I wanted to use it so much
                    /// and i know it's confusing so I couldn't
                    /// but here is quite Clear
                    goto skip;
                }
                /// if cursor is on " minus on the right"
                if (cursor_position_ == Coord(GetHeight() - 2, GetWidth())) {
                  Resize(GetHeight(), GetWidth() - 1);
                  cursor_position_.y_--;
                    goto skip;
                }

                /// if cursor is on " plus on the bottom"
                if (cursor_position_ == Coord(GetHeight(), GetWidth() - 1)) {
                  Resize(GetHeight() + 1, GetWidth());
                  cursor_position_.x_++;
                    goto skip;
                }
                /// if cursor is on " minus on the bottom"
                if (cursor_position_ == Coord(GetHeight(), GetWidth() - 2)) {
                  Resize(GetHeight() - 1, GetWidth());
                  cursor_position_.x_--;
                    goto skip;
                }

                /// if cursor is on "blue  i icon"
                if (cursor_position_ == Coord(GetHeight(), GetWidth())) {
                  SetAdditionalInfo();
                    goto skip;
                }

                /// if cursor is on "red < icon"
                if (cursor_position_ == Coord(0, GetWidth())) {
                    return QUIT_EDIT;
                }
                /// if cursor is on "blue \/ icon"
                if (cursor_position_ == Coord(2, GetWidth())) {
                    if (level_name_ != "noname")
                      Save();
                }
                /// if cursor is on "yellow >icon"
                if (cursor_position_ == Coord(1, GetWidth())) {
                    return RUN_SIMULATION;
                }


            }
        skip:
            break;
        case 'r':
          level_[cursor_position_.ToUint(GetWidth())]->RotateRight();
            break;
        case '1':
          current_block_ = 0;
            break;
        case '2':
          current_block_ = 1;
            break;
        case '3':
          current_block_ = 2;
            break;
        case '4':
          current_block_ = 3;
            break;
        case '5':
          current_block_ = 4;
            break;
        case '6':
          current_block_ = 5;
            break;
        case '7':
          current_block_ = 6;
            break;
        case '8':
          current_block_ = 7;
            break;

        default:
            return NOTHING;

    }


    if (cursor_position_.y_ > GetWidth())
      cursor_position_.y_ = GetWidth();
    if (cursor_position_.x_ > GetHeight())
      cursor_position_.x_ = GetHeight();

    if (cursor_position_.y_ < 0)
      cursor_position_.y_ = 0;
    if (cursor_position_.x_ < 0)
      cursor_position_.x_ = 0;

    /// if cursor is on "red < icon"
    if (cursor_position_ == Coord(0, GetWidth())) {
      current_message_ = EXIT;
    }

        /// if cursor is on "yellow >icon"
    else if (cursor_position_ == Coord(1, GetWidth())) {
      current_message_ = START_SIMULATION;
    }
    /// if cursor is on "blue \/ icon"
    if (cursor_position_ == Coord(2, GetWidth())) {
        if (level_name_ != "noname")
          current_message_ = SAVE_CHANGES_TO_FILE;
        else
          current_message_ = ADDITIONAL_INFO_REQUEST;
    }

    /// if cursor is on "blue  i icon"
    if (cursor_position_ == Coord(GetHeight(), GetWidth())) {

      current_message_ = ADDITIONAL_INFO;
    }
    /// if cursor is on " plus on the right"
    if (cursor_position_ == Coord(GetHeight() - 1, GetWidth())) {

      current_message_ = INCREASE_WIDTH;
    }
    /// if cursor is on " minus on the right"
    if (cursor_position_ == Coord(GetHeight() - 2, GetWidth())) {

      current_message_ = DECREASE_WIDTH;
    }
    /// if cursor is on " plus on the bottom"
    if (cursor_position_ == Coord(GetHeight(), GetWidth() - 1)) {

      current_message_ = INCREASE_HEIGHT;
    }
    /// if cursor is on " minus on the bottom"
    if (cursor_position_ == Coord(GetHeight(), GetWidth() - 2)) {

      current_message_ = DECREASE_HEIGHT;
    }
    /// todo these abowe + Resize window
    return NOTHING;
}


void LevelEdit::MainLoop() {

    char key_pressed = 0;
    PlayerAction operation;

    while (2 > 1) {
      ControlledView();

        key_pressed = GetKey();

        operation = AnalyzeMovement(key_pressed);

        if (operation == QUIT_EDIT) break;
        if (operation == RUN_SIMULATION)
          RunSim();

    }

}



