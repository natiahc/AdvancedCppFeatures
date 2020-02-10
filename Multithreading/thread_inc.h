#pragma once

#include <iostream>
#include <thread>
#include <memory>
#include <future>
#include <functional>
#include <utility>
#include <exception>
#include <sstream>

extern int sum(int st, int ed);
extern void sum_prm(std::promise<int>& prm, int st, int ed);