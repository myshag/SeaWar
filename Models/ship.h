#ifndef SHIP_H
#define SHIP_H


struct Point
{
    int x;
    int y;

};

enum class Direction
{

   Horizontal,
  Vertical

};


class Ship
{
public:
  Ship()=delete;
  Ship(int id, Point start, Point end, int len, Direction direction);
  void setdemage(int x);

  Point start() const
  {
    return m_start;
  }
  Point end() const
  {
    return m_end;
  }

  int lenght() const
  {
    return m_lenght;
  }

  bool isdead() const
  {
    return m_isdead;
  }

  int id() const
  {
    return m_id;
  }

  Direction direction() const
  {
    return m_direction;
  }


  void setDemage(int x);



private:

    const Point m_start;
    const Point m_end;
    const int m_lenght;
         bool m_isdead=false;
    const Direction m_direction;
   const int m_id;
    bool m_demage[3]={false};


};



#endif // SHIP_H
