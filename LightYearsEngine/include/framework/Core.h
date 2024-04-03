#pragma once

#include <stdio.h>
#include <memory>
#include <vector>
#include <map>
#include <unordered_map>

namespace ly
{
template<typename T>
using unique = std::unique_ptr<T>;

template<typename T>
using shared = std::shared_ptr<T>;

template<typename T>
using weak = std::weak_ptr<T>;

template<typename T>
using List = std::vector<T>;

template<typename key, typename val, typename pr = std::less<key>>
using Map = std::map<key, val, pr>;

template<typename key, typename val, typename hasher = std::hash<key>>
using Dict = std::unordered_map<key, val, hasher>;

// MACRO
#define LOG(M, ...) printf(M "\n", ##__VA_ARGS__)
}