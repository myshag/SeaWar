/*
//  Copyright (c) 2021, Alex Zapevalin
//  All rights reserved.
*/


#include "vector"
#include "Observer.h"
#include "QDebug"


void Observable::addObserver(Observer *observer)
{
    _observers.push_back(observer);
    qDebug()<<" Observable::addObserver()"<<observer;
}

void Observable::notifyUpdate()
{
    int size = _observers.size();
    for (int i=0;i<size;i++)
    {
        _observers[i]->updateObserver();
    };
      qDebug()<<" Observable::notifyUpdate()";

}
