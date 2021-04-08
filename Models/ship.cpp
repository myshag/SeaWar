#include "ship.h"
#include <QDebug>


Ship::Ship(int id, Point start, Point end,int len,Direction direction):
  m_id(id),m_start(start),m_end(end),m_lenght(len),m_direction(direction),m_demage(len)
{

}

void Ship::setDemage()
{
  if ((m_demage-1)<=0)
    {
      m_demage = 0;
      m_isdead = true;
      qDebug()<<"Ship::kill: m_demage"<<m_demage;

    }

  m_demage-=1;

  qDebug()<<"Ship::setDemage: m_demage"<<m_demage;
}

