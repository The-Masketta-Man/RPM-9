/**
  * @file sort.cpp
  * @brief bubble sort
  * @author Roman Safin
  */
#include "sort.h"
Sort::Sort(int count, QObject *parent) : QObject(parent)
{
    f = count;
    array = new int[f];
    for(int i=0; i<f; i++)
        array[i] = (qrand() % ((1000000 + 1) - 1) + 1);
}

Sort::~Sort()
{
    delete array;
}

bool Sort::running() const
{
    return m_running;
}

void Sort::setRunning(bool running)
{
    if (m_running == running)
            return;
    m_running = running;
    emit runningChanged(running);
}

void Sort::run()
{
    while (m_running){
        int buf;
        for (int i=0; i<f-1; i++){
            for (int j=0; j<f;j++){
                if (array[j]>array[j+1]){
                    buf=array[j];
                    array[j]=array[j+1];
                    array[j+1]=buf;
                }
                if(m_running == false)
                    return;
            }
        }
        setRunning(false);
    }
    emit finished();
}

int *Sort::getArray() const
{
    return array;
}

int Sort::getF() const
{
    return f;
}
