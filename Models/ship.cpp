#include "ship.h"
#include <QDebug>


Ship::Ship(int id, Point start, Point end,int len,Direction direction):
  m_id(id),m_start(start),m_end(end),m_lenght(len),m_direction(direction)
{
  for (int i=len-1;i<=3;i++)
    {
      m_demage[i] = true;
    }

}

void Ship::setDemage(int x)
{
  if (x<m_lenght)
    {
      m_demage[x]=true;
    }
  bool dead = true;
  for(bool c:m_demage)
    {
      if (!c) {
          dead = false;
        }
    }
  if (dead)
  {
     m_isdead=true;
    }
}

