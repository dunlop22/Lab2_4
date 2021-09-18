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

avto new_avto(motor* motor1, koleso* koleso1, korobka_peredach* korobka_peredach1, obchee* obchee);
void vod_avto(avto* avtomobil, voditel vod);
void prosmotr_avto(avto avtomobil);
void avto_otv(avto* avtomobil);