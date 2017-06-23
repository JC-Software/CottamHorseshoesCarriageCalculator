// Ukmail Calculator

float fUKMailFuel   = 1.05;     // UK mail fuel surcharge
int nUKMWeightBreak  = 20;
int   nWeightLimit1         = 50;   //over weight surcharges
float fWieghtLimit1Charge   = 2.0;  // wieght limit is weight in kg
int   nWeightLimit2         = 75;   //charge is surchare in £
float fWeighLimit2Charge    = 2.5;  //


float fUKMCost = 0;
float fUKMMainland();

float fUKMail (int nWeight,char cPostcode1,char cPostcode2,char cPostcode3,char cPostcode4)
{
    if (nWeight < nUKMWeightBreak)                // prevent negative weight in later calculations
    {
        nWeight = nUKMWeightBreak;
    }
    if (nWeight>nWeightLimit1)                 //over weight consignment surcharge
        {
            if (nWeight>nWeightLimit2)
            {
                fUKMCost = fWieghtLimit1Charge + fWeighLimit2Charge;   // can go on and on 100/125/150 etc.
            }
            else
            {
                fUKMCost = fWieghtLimit1Charge;
            }
        }

    float fUKMMainland(nWeight);
    {
        fUKMCost += ((nWeight - nUKMWeightBreak)*.21 + 5)*fUKMailFuel;
    }

    /*switch (cPostcode1)
    {
        case ('s'):
        case ('S'):
        fUKMCost = fUKMMainland ();
        break;
    }*/

    return fUKMCost;
        // weight<20,0,weight-20)*0.21+5
}
