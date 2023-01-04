//
// Created by dangkhacdat on 14/12/2021.
//
#ifndef NETWORKPROGRAMMING_PROTOCOL_H
#define NETWORKPROGRAMMING_PROTOCOL_H

typedef enum {
    LOGIN,
    REGISTER,
    LOGOUT,
    JOIN_GAME,
    QUESTION_REQUEST,
    DASHBOARD,
    ANSWER,
    HELP,
    STOP,
    BREAK,
    EXIT
} REQUEST_CODE;


typedef enum {
    QUERY_FAIL,
    USERNAME_NOTFOUND,
    USERNAME_BLOCKED,
    USERNAME_IS_SIGNIN,
    LOGIN_SUCCESS,

    PASSWORD_CORRECT,
    PASSWORD_INCORRECT,
    STOPGAME_SUCCESS,

    LOGOUT_SUCCESS,
    LOGOUT_FAIL,
    JOIN_GAME_FAIL,
    JOIN_GAME_SUCCESS,

    QUESTION,
    ANSWER_CORRECT,
    HELP_SUCCESS,
    SCORE_INFO,

    DASHBOARD_INFO,

    REGISTER_SUCCESS,
    REGISTER_USERNAME_EXISTED,
    END_GAME,
} RESPONSE_CODE;

#endif //NETWORKPROGRAMMING_PROTOCOL_H
