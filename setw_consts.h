#ifndef SETW_CONSTS_H
#define SETW_CONSTS_H

const int WINDOW_OUTER = 80;
const int WINDOW_INNER = WINDOW_OUTER - 2;

const int MENU_HEAD_PADDING = (WINDOW_INNER / 2) - 9;
const int MENU_SUBHEAD_PADDING = MENU_HEAD_PADDING - 3;
const int MENU_BODY_PADDING = MENU_SUBHEAD_PADDING - 1;

const int BOOK_INFO_TITLE_PADDING = (WINDOW_INNER / 2) - 4;
const int BOOK_INFO_SUBTITLE_PADDING = WINDOW_OUTER - 45;
const int BOOK_INFO_BODY_PADDING = BOOK_INFO_SUBTITLE_PADDING + 3;

const int BOOK_EDITOR_TITLE_PADDING = WINDOW_OUTER - BOOK_INFO_TITLE_PADDING;
const int BOOK_EDITOR_SUBTITLE_PADDING = WINDOW_OUTER - BOOK_INFO_SUBTITLE_PADDING;
const int BOOK_EDITOR_BODY_PADDING = BOOK_INFO_BODY_PADDING;

const int DB_SIZE_PADDING = MENU_HEAD_PADDING - MENU_BODY_PADDING;
const int PENDING_VALUES_PADDING = WINDOW_OUTER - 10;

const int BOOK_COUNT_PADDING = WINDOW_OUTER - PENDING_VALUES_PADDING + 10;
const int PENDING_VALUES_WIDTH = WINDOW_INNER - PENDING_VALUES_PADDING;
const int MENU_EXIT_PADDING = PENDING_VALUES_PADDING - 9;

const int BOOK_INFO_TITLE_WIDTH = WINDOW_INNER - BOOK_INFO_TITLE_PADDING;
const int BOOK_INFO_SUBTITLE_WIDTH = WINDOW_INNER - BOOK_INFO_SUBTITLE_PADDING;
const int BOOK_INFO_BODY_WIDTH = WINDOW_INNER - BOOK_INFO_BODY_PADDING;

const int MENU_HEAD_WIDTH = WINDOW_INNER - MENU_HEAD_PADDING;
const int MENU_SUBHEAD_WIDTH = WINDOW_INNER - MENU_SUBHEAD_PADDING;
const int MENU_BODY_WIDTH = WINDOW_INNER - MENU_BODY_PADDING;

const int BOOK_EDITOR_TITLE_WIDTH = WINDOW_INNER - BOOK_EDITOR_TITLE_PADDING;
const int BOOK_EDITOR_SUBTITLE_WIDTH = WINDOW_INNER - BOOK_EDITOR_SUBTITLE_PADDING;
const int BOOK_EDITOR_BODY_WIDTH = WINDOW_INNER - BOOK_EDITOR_BODY_PADDING - 6;


#endif // SETW_CONSTS_H