#pragma once

#ifndef OPERACIONES_H
#define OPERACIONES_H

#include <iostream>
#include <list>

template<class T>
class List {
private:
    std::list<T> data;

public:
    List() {}

    List(T* in_data, int in_size) {
        for (int i = 0; i < in_size; i++) {
            data.push_back(in_data[i]);
        }
    }

    void Print() {
        typename std::list<T>::iterator it;
        for (it = data.begin(); it != data.end(); ++it) {
            std::cout << *it;
            if (std::next(it) != data.end()) {
                std::cout << ", ";
            }
        }
        std::cout << std::endl;
    }

    void PushBack(T value) {
        data.push_back(value);
    }

    void Reverse() {
        data.reverse();
    }

    void Unique() {
        std::list<T> uniqueList;
        typename std::list<T>::iterator it;
        for (it = data.begin(); it != data.end(); ++it) {
            if (std::find(uniqueList.begin(), uniqueList.end(), *it) == uniqueList.end()) {
                uniqueList.push_back(*it);
            }
        }
        data = uniqueList;
    }
};

#endif // OPERACIONES_H


