#pragma once
#include "motor.h";
#include "obchee.h";
#include "korobka.h";
#include "koleso.h";
#include "voditel.h";

struct avto
{
    motor har2;
    koleso har3;
    korobka_peredach har4;
    obchee har5;
    voditel* vod = NULL;
};