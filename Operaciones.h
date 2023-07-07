#pragma once

#ifndef OPERACIONES_H
#define OPERACIONES_H

#include <iostream>

template <typename T>
class ListNode
{
public:
    T data;
    ListNode<T>* next;

    ListNode(T value) : data(value), next(nullptr) {}
};

template <typename T>
class List
{
private:
    ListNode<T>* head;

public:
    List() : head(nullptr) {}

    List(T* in_data, int in_size) : head(nullptr)
    {
        for (int i = 0; i < in_size; i++)
        {
            PushBack(in_data[i]);
        }
    }

    void PushBack(T value)
    {
        ListNode<T>* newNode = new ListNode<T>(value);

        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            ListNode<T>* current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void Print()
    {
        ListNode<T>* current = head;
        while (current != nullptr)
        {
            std::cout << current->data;
            if (current->next != nullptr)
            {
                std::cout << ", ";
            }
            current = current->next;
        }
        std::cout << std::endl;
    }

    void Reverse()
    {
        ListNode<T>* prev = nullptr;
        ListNode<T>* current = head;
        ListNode<T>* next = nullptr;

        while (current != nullptr)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
    }

    void Unique()
    {
        if (head == nullptr)
            return;

        ListNode<T>* current = head;
        while (current != nullptr && current->next != nullptr)
        {
            ListNode<T>* runner = current;
            while (runner->next != nullptr)
            {
                if (runner->next->data == current->data)
                {
                    ListNode<T>* duplicate = runner->next;
                    runner->next = runner->next->next;
                    delete duplicate;
                }
                else
                {
                    runner = runner->next;
                }
            }
            current = current->next;
        }
    }


    ~List()
    {
        ListNode<T>* current = head;
        while (current != nullptr)
        {
            ListNode<T>* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

#endif // OPERACIONES_H