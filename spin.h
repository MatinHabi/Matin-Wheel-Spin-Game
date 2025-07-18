#ifndef SPIN_H
#define SPIN_H
#include <iostream>
#include <ctime>
#include <random>
#include <thread>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

void List(vector<string>& games);

void Remove(vector<string>& games);

void Add(vector<string>& games);

void Spin(vector<string>& games);

void Load(vector<string> &games);

void Save(vector<string> &games);
#endif