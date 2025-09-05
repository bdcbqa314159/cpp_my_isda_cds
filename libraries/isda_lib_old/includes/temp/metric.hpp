#pragma once
#ifndef METRIC_HPP
#define METRIC_HPP

#include <stdio.h>
#include <stdlib.h>

#include "cdate.hpp"  // IWYU pragma: keep

EXPORT_C { typedef double (*TMetricDoubleFunc)(double pt1, double pt2); }

#endif  // METRIC_HPP