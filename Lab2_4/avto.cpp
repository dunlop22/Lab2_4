#include "avto.h"


avto new_avto(motor* motor1, koleso* koleso1, korobka_peredach* korobka_peredach1, obchee* obchee)
{
    if (motor1->koni >= 0 && koleso1->visota >= 0 && korobka_peredach1->kolvo_peredach >= 0 && obchee->obem_benzobaka >= 0)
    {
        avto avto_create;
        avto_create.har2 = *motor1;
        avto_create.har3 = *koleso1;
        avto_create.har4 = *korobka_peredach1;
        avto_create.har5 = *obchee;
        avto_create.vod = NULL;
        
        return avto_create;
    }
    else
    {
        cout << "Автомобиль невозможно собрать из-за отсутствия информации о компонентах";
    }
}

void vod_avto(avto* avtomobil, voditel vod)
{
    avtomobil->vod = &vod;
}

void prosmotr_avto(avto avtomobil)
{
    if (avtomobil.har2.koni >= 0)
    {
        prosmotr_obchee(avtomobil.har5);
        prosmotr_motor(avtomobil.har2);
        prosmotr_koleso(avtomobil.har3);
        prosmotr_korobka_peredach(avtomobil.har4);
        if (avtomobil.vod != NULL)
        {
            prosmotr_voditel(*avtomobil.vod);
        }
    }
    else
    {
        cout << "Информация об автомобиле не найдена.";
    }
}


void avto_otv(avto* avtomobil)
{
    if (avtomobil->har2.koni >= 0)
    {
        avtomobil->vod = NULL;
    }
    else
    {
        cout << "Информация об автомобиле не найдена.";
    }
}

