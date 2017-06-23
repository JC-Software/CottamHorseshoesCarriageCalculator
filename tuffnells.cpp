//tuffnells cost calculator

float   fTuffsFuel      = 1.075;    // tuffnells fuel surcharge
int     nWeightBreak    = 50;       // weight break point in kg
float   fTuffsPerKg     = 0.17      // price per kg
float   fTuffsBase      = 8.9       // base price

float fTuffCost = 0;

float fTuffs (int nWeight,char cPostcode1,char cPostcode2,char cPostcode3,char cPostcode4)
{
    if (nWeight<nWeightBreak)             // prevents breakpoint weight being less than 0 for small orders
    {
        nWeight = nWeightBreak;
    }

    float fTMainland();          // Mainland cost
    {
        fTuffCost = ((nWeight - nWeightBreak)*fTuffsPerKg + fTuffsBase)*fTuffsFuel;
    }

    switch (cPostcode1)         // choose which postcode zone has been entered
    {
        case ('s'):
        case ('S'):
            fTMainland;
            break;
        default:
            fTuffCost = 0;
    }

    return fTuffCost;
}

