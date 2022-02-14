#pragma once

#include <vector>

#include "bomb.h"
#include "ground.h"
#include "level_gui.h"
#include "plane.h"
#include "tank.h"

class SBomber {
 public:
  SBomber();
  ~SBomber();

  inline bool GetExitFlag() const { return exitFlag; }

  void ProcessKBHit();
  void TimeStart();
  void TimeFinish();

  void DrawFrame();
  void MoveObjects();
  void CheckObjects();

 private:
  void CheckPlaneAndLevelGUI();
  void CheckBombsAndGround();
  void CheckDestoyableObjects(DynamicObject* pBomb);

  void DeleteDynamicObj(DynamicObject* pBomb);
  void DeleteStaticObj(GameObject* pObj);

  Ground* FindGround() const;
  Plane* FindPlane() const;
  LevelGUI* FindLevelGUI() const;
  std::vector<DestroyableGroundObject*> FindDestoyableGroundObjects() const;
  std::vector<DynamicObject*> FindAllBombs() const;

  void DropBomb();

  std::vector<DynamicObject*> vecDynamicObj;
  std::vector<GameObject*> vecStaticObj;

  bool exitFlag;

  uint64_t startTime, finishTime, passedTime;
  uint16_t bombsNumber, deltaTime, fps;
  int16_t score;
};
