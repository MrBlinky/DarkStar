#pragma once
#include "gfx/blinkyicon.h"
#include "gfx/blinkyinfo.h"
#include "gfx/darkstarSprite.h"
#include "gfx/darkSprite.h"
#include "gfx/starSprite.h"
#include "gfx/tiles.h"
#include "gfx/hudNumbers.h"
#include "gfx/ballSprite.h"
#include "gfx/joystickSprite.h"
#include "gfx/blockerSprite.h"
#include "levels.h"
#include "print.h"

constexpr uint8_t frameRate     = 60;

constexpr uint8_t gsTitle            = 0;
constexpr uint8_t gsTitleEnd         = 1;
constexpr uint8_t gsPlayLevel        = 2;
constexpr uint8_t gsLevelCompleted   = 3;
constexpr uint8_t gsNextLevel        = 4;
constexpr uint8_t gsMissionCompleted = 5;
constexpr uint8_t gsGameOver         = 6;
constexpr uint8_t gsShowMenu         = 7;

constexpr uint8_t introTitleDelay     = 80;
constexpr uint8_t introButtonOnDelay  = introTitleDelay + 40;
constexpr uint8_t introButtonOffDelay = introButtonOnDelay + 24;
constexpr uint8_t introLoopDelay      = introButtonOnDelay - 24;

constexpr uint8_t levelWidth  = 16;
constexpr uint8_t levelHeight = 9;

constexpr uint8_t lsIdle          = 0;
constexpr uint8_t lsMoving        = 1;
constexpr uint8_t lsSwitchControl = 2;
constexpr uint8_t lsCompleted     = 3;

constexpr uint8_t ttSpace       = 0;
constexpr uint8_t ttWall        = 1;
constexpr uint8_t ttCollectible = 2;

constexpr uint16_t maxMoves         = 1024;
constexpr uint16_t maxRetries       = 5;
constexpr uint16_t nextLevelPenalty = 100;

struct Camera
{
  int8_t x;
  int8_t y;
};

struct  PlayerSprite
{
  uint8_t pos;
  uint8_t row;
  uint8_t col;
  int8_t  x;
  int8_t  y;
  int8_t  h;
  int8_t  v;
  uint8_t count;
  uint8_t frame;
};

struct  ControlSprite 
{
  int16_t  x;
  int16_t  y;
  int16_t  h;
  int16_t  v;
  uint8_t count;
  uint8_t frame;
};

Arduboy2Base arduboy;

uint8_t levelMap [levelWidth * levelHeight];

Camera camera = {0,-4};

uint8_t gameState;
uint16_t gameMoves;
uint16_t gameOption;

uint8_t levelRetries;
uint8_t levelNumber;
uint8_t levelMoves;
uint8_t levelCollectibles;
uint8_t levelState;
uint8_t levelRetry;

bool gameNextState;

ControlSprite control;
PlayerSprite  ball;
PlayerSprite  blocker;
PlayerSprite* player;


constexpr uint8_t sp = 8 + 5;

const uint8_t PROGMEM anyButtonText[] = 
{
  AT_X((WIDTH - 9 * fontWidth - 5) / 2), AT_Y(HEIGHT - fontHeight + 1),
  'A','N','Y',CHR_SPACE,'B','U','T','T','O','N',
  0
};
const uint8_t PROGMEM levelCompletedText[] = 
{
  AT_X(32), AT_Y(6),
  'L','E','V','E','L',
  AT_X(26), AT_Y(17),
  'C','O','M','P','L','E','T','E','D',
  AT_X(16), AT_Y(28),
  'I','N',
  AT_X(67), AT_Y(28),
  'M','O','V','E','S',
  AT_X(43), AT_Y(39),
  'M','O','V','E','S',CHR_SPACE,'L','E','F','T',
  AT_X(WIDTH - 5 * fontWidth - 1), AT_Y(HEIGHT - fontHeight - 3),
  CHR_BTN_B,'N','E','X','T',
  0
};

const uint8_t PROGMEM retryLevelText[] = 
{
  AT_X(2), AT_Y(HEIGHT - fontHeight - 3),
  CHR_BTN_A,'R','E','T','R','Y',
  0
};

const uint8_t PROGMEM missionCompletedText[] = 
{
  AT_X(1), AT_Y(6),
  'C','O','N','G','R','A','T','U','L','A','T','I','O','N','S',
  AT_X(30), AT_Y(17),
  'Y','O','U',CHR_SPACE,'H','A','V','E',
  AT_X(25), AT_Y(28),
  'C','O','M','P','L','E','T','E','D',
  AT_X(16), AT_Y(39),
  'Y','O','U','R',CHR_SPACE,'M','I','S','S','I','O','N',
  AT_X(13), AT_Y(50),
  'I','N',
  AT_X(71), AT_Y(50),
  'M','O','V','E','S',
  0
};

const uint8_t PROGMEM menuPos[4][2] =
{
  {21, 10},
  {32, 21},
  {36, 32},
  {38, 43},
};

const uint8_t PROGMEM menuText[] = 
{
  AT_X(31), AT_Y(11),
  'C','O','N','T','I','N','U','E',
  AT_X(42), AT_Y(22),
  'R','E','T','R','Y',
  AT_X(46), AT_Y(33),
  'N','E','X','T',
  AT_X(48), AT_Y(44),
  'E','X','I','T',
  0
};

const uint8_t PROGMEM shortMenuPos[2][2] =
{
  {21, 21},
  {38, 33},
};

const uint8_t PROGMEM shortMenuText[] = 
{
  AT_X(31), AT_Y(22),
  'C','O','N','T','I','N','U','E',
  AT_X(48), AT_Y(33),
  'E','X','I','T',
  0
};

const uint8_t PROGMEM gameOverText[] = 
{
  AT_X(5), AT_Y(6),
  'O','O','P','S',CHR_EX,CHR_SPACE,'Y','O','U',CHR_SPACE,'H','A','V','E',
  AT_X(5), AT_Y(17),
  'N','O',CHR_SPACE,'M','O','V','E','S',CHR_SPACE,'L','E','F','T',CHR_EX,
  AT_X(25), AT_Y(39),
  'G','A','M','E',CHR_SPACE,'O','V','E','R',
  0
};
