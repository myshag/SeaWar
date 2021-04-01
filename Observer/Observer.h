/*
//  Copyright (c) 2021, Alex Zapevalin
//  All rights reserved.
*/


#include "vector"

#ifndef OBSERVER_H
#define OBSERVER_H


class Observer
{
    public:
    virtual void update() = 0;
};

class Observable
{
    public:

    void addObserver(Observer *observer);


    void notifyUpdate();

    private:
    std::vector<Observer*> _observers;
};

#endif
