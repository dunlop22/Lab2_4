#pragma once
struct korobka_peredach
{
    char tip_korobki[20];
    double kolvo_peredach;
};

korobka_peredach new_korobka_info();
korobka_peredach new_korobka_peredach(double kolvo_peredach, char tip_korobki[20]);
void prosmotr_korobka_peredach(korobka_peredach korobka_peredach1);
void korobka_peredach_peredacha_plus(korobka_peredach* korobka_peredach1);