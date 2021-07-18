#ifndef UTILS_H
#define UTILS_H
#include "infrastructure.h"
#include "service.h"
#pragma once

MasiniRepo* sort(MasiniRepo* masini_repo, int(compara)(Masina* masina_1, Masina* masina_2, int type),int type,int order);

#endif