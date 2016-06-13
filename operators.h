#pragma once

#include"vec.h"
#include"mat.h"

Adina::vec &operator*(const Adina::mat& a, const Adina::vec& b);
Adina::mat &operator*(const Adina::vec& a, const Adina::vec& b);