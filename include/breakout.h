#ifndef BREAKOUT_H
#define BREAKOUT_H
#include <QWidget>
#include <QKeyEvent>
#include "ball.h"
#include "brick.h"
#include "paddle.h"

class Breakout : public QWidget {

public:
    Breakout(QWidget *parent = 0);
    ~Breakout();

public:
    bool isGameStarted();
    bool isGamePaused();
    bool isGameStopped();
    bool isGameWon();

protected:
    void paintEvent(QPaintEvent *);
    void timerEvent(QTimerEvent *);
    void keyPressEvent(QKeyEvent *);
    void keyReleaseEvent(QKeyEvent *);
    void drawObjects(QPainter *);
    void finishGame(QPainter *, QString);
    void moveObjects();

    void startGame();
    void pauseGame();
    void stopGame();
    void victory();
    void checkCollision();

private:
    int x;
    int timerId;
    static const int N_OF_BRICKS = 30;
    static const int DELAY = 10;
    static const int BOTTOM_EDGE = 400;
    Ball *ball;
    Paddle *paddle;
    Brick *bricks[N_OF_BRICKS];
    bool gameOver;
    bool gameWon;
    bool gameStarted;
    bool paused;

    friend class TestBreakout;
};

#endif // BREAKOUT_H